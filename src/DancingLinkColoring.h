/**
 * @file   DancingLinkColoring.h
 * @author Yibo Lin
 * @date   Oct 2019
 */
#ifndef SIMPLEMPL_DANCINGLINKCOLORING_H
#define SIMPLEMPL_DANCINGLINKCOLORING_H

#include <limbo/algorithms/coloring/Coloring.h>
#include "DL_MPL.h"

SIMPLEMPL_BEGIN_NAMESPACE

template <typename GraphType>
class DancingLinkColoring : public limbo::algorithms::coloring::Coloring<GraphType>
{
	public:
        /// @nowarn 
		typedef limbo::algorithms::coloring::Coloring<GraphType> base_type;
		using typename base_type::graph_type;
		using typename base_type::graph_vertex_type;
		using typename base_type::graph_edge_type;
		using typename base_type::vertex_iterator_type;
		using typename base_type::edge_iterator_type;
        using typename base_type::edge_weight_type;
		using typename base_type::ColorNumType;

		/// constructor
        /// @param g graph 
		DancingLinkColoring(graph_type const& g) 
			: base_type(g)
		{}
		/// destructor
		virtual ~DancingLinkColoring() {}

	protected:
        /// kernel coloring algorithm 
		/// @return objective value 
		virtual double coloring()
        {
            double cost1 = solve_by_dancing_link_with_one_stitch();
            return cost1;
        }
        void dfs_search(uint32_t& source,std::vector<uint32_t> & node_comp,uint32_t& comp_id,std::set<Edge*> & stitch_set){
            std::stack<uint32_t> vStack; 
            uint32_t component_count = 0;
            // std::cout<<source<<"Vstack push: "<<source<< std::endl;
            vStack.push(source);
            while (!vStack.empty())
            {
                uint32_t current = vStack.top();
                // std::cout<<source<<"Vstack pop: "<<current<< std::endl;
                vStack.pop();
                if (node_comp[current] == std::numeric_limits<uint32_t>::max()) // not visited 
                {
                    node_comp[current] = comp_id;// set visited 
                    component_count += 1;
                    typename boost::graph_traits<graph_type>::adjacency_iterator vi2, vie2,next2;
                    boost::tie(vi2, vie2) = boost::adjacent_vertices(current, this->m_graph);
                    for (next2 = vi2; vi2 != vie2; vi2 = next2)
                    {
                        ++next2; 
                        graph_vertex_type v2 = *vi2;
                        std::pair<graph_edge_type, bool> e12 = boost::edge(current, v2, this->m_graph);
                        bool in_stitch_set = false;
                        for(auto stitch = stitch_set.begin(); stitch != stitch_set.end();++stitch){
                            if(((*stitch)->source == current && (*stitch)->target == (int)v2) || ((*stitch)->source == (int)v2 && (*stitch)->target == current)){
                                in_stitch_set = true;
                                break;
                            }
                        }
                        //if the stitch adj node is not connected by stitch in stitch_set, then we assign the same component
                        if(boost::get(boost::edge_weight, this->m_graph, e12.first) < 0 && in_stitch_set == false){
                            mplAssert(current != v2);
                            vStack.push(v2);
                            // std::cout<<source<<"Vstack push: "<<v2<< std::endl;
                        }
                    }
                }
            }
        }
        void connected_components_k_stitches(std::vector<uint32_t> & node_comp, uint32_t& comp_id, std::vector<Vertex*> & node_set, std::set<Edge*> & stitch_set){
            for(std::vector<Vertex*>::iterator it = node_set.begin(); it != node_set.end(); ++it){
                // if not visited
                uint32_t No = (uint32_t)((*it)->Stitch_No);
                if(node_comp[No] ==std::numeric_limits<uint32_t>::max()){
                    dfs_search(No, node_comp,comp_id,stitch_set);
                    comp_id ++;
                }
            }
        }

        double solve_by_dancing_link_with_one_stitch()
        {
            // Due to graph does not contain a parent&child node system
            // we simply redesign a node struct to achieve this kind of system
            //boost::timer::cpu_timer dancing_link_timer;
            //dancing_link_timer.start();
            DancingLink dl; 
            std::vector<Vertex*> node_list;
            node_list.resize(num_vertices(this->m_graph));
            uint32_t vertex_numbers = 0;
            uint32_t edge_numbers = 0;
            vertex_iterator_type vi1, vie1;
            for (boost::tie(vi1, vie1) = boost::vertices(this->m_graph); vi1 != vie1; ++vi1)
            {	
                graph_vertex_type v1 = *vi1;
                typename boost::graph_traits<graph_type>::adjacency_iterator vi2, vie2,next2;
                boost::tie(vi2, vie2) = boost::adjacent_vertices(v1, this->m_graph);
                for (next2 = vi2; vi2 != vie2; vi2 = next2)
                {
                    ++next2; 
                    graph_vertex_type v2 = *vi2;
                    if (v1 >= v2) continue;
                    std::pair<graph_edge_type, bool> e12 = boost::edge(v1, v2, this->m_graph);
                    mplAssert(e12.second);
                    //std::cout<<v1<<" "<<v2<<" "<<boost::get(boost::edge_weight, this->m_graph, e12.first)<<std::endl;

                    //if node source and node target is not created. New one/
                    if(!node_list[v1])
                    {
                        Vertex* source_vertex = new Vertex;
                        mplAssert(source_vertex->Conflicts.empty());
                        node_list[v1] = source_vertex;
                        source_vertex->Stitch_No = v1;
                        vertex_numbers ++;
                    }
                    if(!node_list[v2])
                    {
                        Vertex* target_vertex = new Vertex;
                        target_vertex->Stitch_No = v2;
                        node_list[v2] = target_vertex;
                        vertex_numbers ++;
                    }

                    //if two nodes are stitch relationships and both of them are parent
                    if(boost::get(boost::edge_weight, this->m_graph, e12.first) < 0)
                    {
                        //std::cout<<"Stitch:"<<v1<<" "<<v2<<std::endl;
                        if(node_list[v1]->parent != NULL && node_list[v1]->parent== node_list[v2]->parent) continue;
                        Vertex* parent_vertex = new Vertex;
                        mplAssert(parent_vertex->Childs.empty());
                        parent_vertex->parentOf(node_list[v1]);
                        parent_vertex->parentOf(node_list[v2]);
                        vertex_numbers -= 1;
                        continue;
                    }
                    node_list[v1]->Conflicts.insert(node_list[v2]);
                }
            }
            //need to store node list, which does not contain child node
            std::set<Vertex*> node_wo_stitch_list;
            int index = 1;
            for(std::vector<Vertex*>::iterator it = node_list.begin(); it != node_list.end(); ++it) 
            {
                //if the node in parent node, means it has no stitch relations
                (*it)->updateConflicts();
                if((*it)->Is_Parent)
                {
                    node_wo_stitch_list.insert((*it));
                    (*it)->No = index;
                    index ++;
                }
                //else, add its parent node if it has not been added into node_wo_stitch_list
                else
                {
                    mplAssertMsg((*it)->parent->Is_Parent, "%u\n%u\n", (uint32_t)(*it)->Stitch_No, (uint32_t)(*it)->parent->Stitch_No);
                    if(node_wo_stitch_list.find((*it)->parent) == node_wo_stitch_list.end())
                    {
                        node_wo_stitch_list.insert((*it)->parent);
                        (*it)->parent->updateConflicts();
                        (*it)->parent->No = index;
                        index ++;
                    }

                }
            }
            mplAssert(node_wo_stitch_list.size() == vertex_numbers);
            std::vector<std::list<Edge_Simple> >   edge_list;
            edge_list.resize(vertex_numbers + 1);
            for(std::set<Vertex*>::iterator it = node_wo_stitch_list.begin(); it != node_wo_stitch_list.end(); ++it) 
            {
                mplAssert((*it)->No != 0);
                for(std::set<Vertex*>::iterator itconflict = (*it)->Conflicts_in_LG.begin(); itconflict != (*it)->Conflicts_in_LG.end(); ++itconflict) 
                {
                    if((*itconflict)->Is_Parent)
                    {
                        mplAssert((*itconflict)->No != 0);
                        edge_numbers++;
                        edge_list[(*it)->No].push_back(Edge_Simple{ (*itconflict)->No, (int)edge_numbers });
                        edge_list[(*itconflict)->No].push_back(Edge_Simple{ (*it)->No, (int)edge_numbers });	
                    }
                    else
                    {
                        mplAssert((*itconflict)->parent->Is_Parent);
                        //avoid repeat (conflicts of stitch realation nodes may represent same conflict)
                        edge_numbers++;	
                        edge_list[(*it)->No].push_back(Edge_Simple{ (*itconflict)->parent->No, (int)edge_numbers });
                        edge_list[(*itconflict)->parent->No].push_back(Edge_Simple{ (*it)->No, (int)edge_numbers });
                    }
                }
            }
            //std::cout<<"EDGE list generated with size: "<<edge_numbers<<std::endl;
            std::vector<uint32_t> starting_indexes;
            uint32_t starting_index = 0;

            //Stitch Generation: recording strating index of each parent node block
            for(std::set<Vertex*>::iterator it = node_wo_stitch_list.begin(); it != node_wo_stitch_list.end(); ++it)
            {
                uint32_t childs_num = ((*it)->Childs).size();
                mplAssert(childs_num > 1 || childs_num == 0);
                starting_indexes.push_back(starting_index);
                if(childs_num > 1)
                {
                    starting_index += 9*(childs_num-1);
                }
            }
            //std::cout<< "Graph build" << dancing_link_timer.format(6)<<std::endl;
            //dancing_link_timer.start();
            //BUILD DL MATRIX WITHOUT STITCH
            //Node structure done,  then build DL system
            int row_numbers = vertex_numbers * (int32_t)this->color_num() + 1;
            int col_numbers = edge_numbers * (int32_t)this->color_num() + vertex_numbers;
            //std::cout<<"DL1: row/col is"<<row_numbers<< " "<<col_numbers<<std::endl;
            //std::cout<<"DL1: vertex/edge number is"<<vertex_numbers<< " "<<edge_numbers<<std::endl;
            DL_Init(dl, row_numbers, col_numbers);
            //std::cout<< "FIRST DL initl" << dancing_link_timer.format(6)<<std::endl;
            //dancing_link_timer.start();
            // Insert DL cells

            for (uint32_t it = 1; it < edge_list.size(); ++it)
            {
                for (int32_t i = 1; i <= (int32_t)this->color_num(); ++i)
                {
                    //Insert elements representing nodes color ( first edge_num cols)
                    Cell_Insert(dl,(it - 1)*(int32_t)this->color_num() + i,it);
                    for (auto j = edge_list[it].begin(); j != edge_list[it].end(); ++j)
                    {
                        //Insert elements representing edge conflict
                        Cell_Insert(dl,(it - 1)*(int32_t)this->color_num() + i,vertex_numbers + (j->No - 1)*(int32_t)this->color_num() + i);
                    }
                }
            }
            for (uint32_t i = 0; i < edge_numbers; ++i)
            {
                for (int32_t j = 1; j <= (int32_t)this->color_num(); ++j)
                    //Insert singelon row
                    Cell_Insert(dl,vertex_numbers * (int32_t)this->color_num() + 1,vertex_numbers + i * (int32_t)this->color_num() + j);
            }


            for(std::vector<Vertex*>::iterator it = node_list.begin(); it != node_list.end(); ++it) 
            {
                //if the node in parent node, means it has no stitch relations
                (*it)->updateDuplicateLGConflicts();
                if(!(*it)->Is_Parent)
                    //else, add its parent node if it has not been added into node_wo_stitch_list
                {
                    mplAssert((*it)->parent->Is_Parent);
                    if(node_wo_stitch_list.find((*it)->parent) == node_wo_stitch_list.end())
                    {
                        node_wo_stitch_list.insert((*it)->parent);
                        (*it)->parent->updateDuplicateLGConflicts();
                    }

                }
            }
            //std::cout<< "FIRST DL insert" << dancing_link_timer.format(6)<<std::endl;
            //dancing_link_timer.start();
            //Firstly solve dl without stitches
            std::vector<int> selected_rows_by_dl1;
            selected_rows_by_dl1 = core_solve_dl(dl,edge_list,row_numbers, col_numbers,(int)vertex_numbers,(int32_t)this->color_num());
            //decode_mat for transforming the selected row to represented color. First: node id, Second: color;
            std::vector<std::vector<std::pair<uint32_t,uint32_t>>> decode_mat;
            //cost 1 is the cost of non-stitch solver
            //std::cout<< "FIRST DL SOLVE" << dancing_link_timer.format(6)<<std::endl;
            //dancing_link_timer.start();
            decode_row_results(selected_rows_by_dl1, this->m_vColor,(int)vertex_numbers, (int32_t)this->color_num(), decode_mat,node_list);
            double cost1 = new_calc_cost(this->m_vColor);
            //std::cout<< "FIRST DL GET RESULT" << dancing_link_timer.format(6)<<std::endl;
            //dancing_link_timer.start();
            if(cost1 > 0)
            {
                std::vector<int8_t> color_vector_dl2;
                color_vector_dl2.assign(this->m_vColor.size(),-1);
                //Step 1, encode matrix generation
                //if cost1 is larger than 1, which means that there is one more conflicts, than we insert stitch in the node
                //1 st dim: num_parent node + 1
                //2 nd dim: num_stitch of this parent node
                //3 rd pair: deivided child node set by this stitch / conflict parent nodes set of the child nodes set
                std::vector<std::vector<std::pair<std::set<uint32_t>,std::set<uint32_t>>>> encode_mat;
                for(uint32_t i = 0; i<=vertex_numbers; i++)
                {
                    std::vector<std::pair<std::set<uint32_t>,std::set<uint32_t>>> small_encode_mat;
                    encode_mat.push_back(small_encode_mat);
                }
                uint32_t stitch_count = 0;
                //I traverse all of the stitch edges for getting the encode matrix
                vertex_iterator_type vi1, vie1;
                for (boost::tie(vi1, vie1) = boost::vertices(this->m_graph); vi1 != vie1; ++vi1)
                {	
                    graph_vertex_type v1 = *vi1;
                    typename boost::graph_traits<graph_type>::adjacency_iterator vi2, vie2,next2;
                    boost::tie(vi2, vie2) = boost::adjacent_vertices(v1, this->m_graph);
                    for (next2 = vi2; vi2 != vie2; vi2 = next2)
                    {
                        ++next2; 
                        graph_vertex_type v2 = *vi2;
                        if (v1 >= v2) continue;
                        std::pair<graph_edge_type, bool> e12 = boost::edge(v1, v2, this->m_graph);
                        mplAssert(e12.second);
                        //if two nodes are stitch relationships
                        if(boost::get(boost::edge_weight, this->m_graph, e12.first) < 0)
                        {
                            stitch_count ++ ;
                            std::set<uint32_t> set1;
                            set1.insert(v1);
                            std::set<uint32_t> set2;
                            set2.insert(v2);
                            push_adj_into_set(v1,this->m_graph,set1,set2);
                            push_adj_into_set(v2,this->m_graph,set2,set1);
                            //std::cout << node_list[v1]->parent->No <<std::endl;
                            std::pair<std::set<uint32_t>,std::set<uint32_t>> encode_mat_per_stitch = std::make_pair(set1,set2);
                            encode_mat[node_list[v1]->parent->No].push_back(encode_mat_per_stitch);
                        }
                    }
                }
                //std::cout<< "SECOND encode matrix" << dancing_link_timer.format(6)<<std::endl;
                //dancing_link_timer.start();
                //Step 1.1 BUILD DL MATRIX WITH STITCH
                //Node structure done,  then build DL system
                DancingLink dl2; 
                row_numbers = vertex_numbers * (int32_t)this->color_num() + 1 + stitch_count * pow((int32_t)this->color_num(),2);
                col_numbers = edge_numbers * (int32_t)this->color_num() + vertex_numbers;
                // std::cout<<"DL2: row/col is"<<row_numbers<< " "<<col_numbers<<std::endl;
                // std::cout<<"DL2: vertex/edge number is"<<vertex_numbers<< " "<<edge_numbers<<std::endl;
                DL_Init(dl2, row_numbers, col_numbers);

                // Insert Non-stitch DL cells
                //std::cout<< "SECOND dl init" << dancing_link_timer.format(6)<<std::endl;
                //dancing_link_timer.start();
                for (uint32_t it = 1; it < edge_list.size(); ++it)
                {
                    for (int32_t i = 1; i <= (int32_t)this->color_num(); ++i)
                    {
                        //Insert elements representing nodes color ( first edge_num cols)
                        Cell_Insert(dl2,(it - 1)*(int32_t)this->color_num() + i,it);
                        for (auto j = edge_list[it].begin(); j != edge_list[it].end(); ++j)
                        {
                            //Insert elements representing edge conflict
                            Cell_Insert(dl2,(it - 1)*(int32_t)this->color_num() + i,vertex_numbers + (j->No - 1)*(int32_t)this->color_num() + i);
                        }
                    }
                }
                for (uint32_t i = 0; i < edge_numbers; ++i)
                {
                    for (int32_t j = 1; j <= (int32_t)this->color_num(); ++j)
                        //Insert singelon row
                        Cell_Insert(dl2,vertex_numbers * (int32_t)this->color_num() + 1,vertex_numbers + i * (int32_t)this->color_num() + j);
                }
                // Step 2 Decode matrix generation and Stitch Rows Cell Insertion
                int count = -1;
                std::vector<uint32_t> starting_indexes;
                uint32_t starting_index = 0;
                for(auto parent_node = node_wo_stitch_list.begin(); parent_node != node_wo_stitch_list.end(); ++parent_node)
                {
                    uint32_t childs_num = ((*parent_node)->Childs).size();
                    int parent_no = (*parent_node)->No;
                    count++;
                    if(childs_num == 0){continue;}
                    mplAssert(childs_num > 1);
                    starting_indexes.push_back(starting_index);
                    for(uint32_t stitch_no = 0; stitch_no < childs_num - 1; stitch_no++)
                    {
                        std::set<uint32_t>  first_set = encode_mat[parent_no][stitch_no].first;
                        std::set<uint32_t>  second_set = encode_mat[parent_no][stitch_no].second;
                        for(auto first_color = 0 ; first_color < (int32_t)this->color_num(); first_color ++)
                        {
                            for(auto second_color = 0 ; second_color < (int32_t)this->color_num(); second_color ++)
                            {
                                //row_decoder indicates the represented color of this row
                                std::vector<std::pair<uint32_t,uint32_t>> row_decoder;
                                //Cell insertion: Node indicator of stitch row
                                Cell_Insert(dl2,vertex_numbers * (uint32_t)this->color_num() + 2+ starting_index + (stitch_no*pow((uint32_t)this->color_num(),2)) + 
                                        first_color *(uint32_t)this->color_num() + second_color, parent_no);
                                for( auto first_set_element = first_set.begin(); first_set_element != first_set.end();first_set_element++)
                                {
                                    row_decoder.push_back(std::make_pair(*first_set_element,first_color));
                                }
                                for(auto second_set_element = second_set.begin(); second_set_element !=second_set.end();second_set_element++)
                                {
                                    row_decoder.push_back(std::make_pair(*second_set_element, second_color));
                                }
                                mplAssertMsg(row_decoder.size() == childs_num, "BUG FOUND! row_decoder.size() %lu, childs_num %u\n", row_decoder.size(), childs_num);
                                decode_mat.push_back(row_decoder);
                                //Cell insertion: conflict indicator of stitch row
                                //std::cout<<"FIRST SET "<<std::endl;
                                for( auto first_set_element = first_set.begin(); first_set_element != first_set.end();first_set_element++)
                                {
                                    for(auto child_conflict =  (node_list[*first_set_element]->Conflicts_in_LG).begin(); child_conflict != 
                                            (node_list[*first_set_element]->Conflicts_in_LG).end(); ++child_conflict)
                                    {
                                        int col_edge = -1;
                                        for(std::list<Edge_Simple>::iterator conflict_edge = edge_list[node_list[*first_set_element]->parent->No].begin();conflict_edge != edge_list[node_list[*first_set_element]->parent->No].end();++conflict_edge)
                                        {
                                            if((*conflict_edge).target == (*child_conflict)->No)
                                            {
                                                col_edge = (*conflict_edge).No;
                                                break;
                                            }
                                        }
                                        // 			mplAssert(col_edge!=-1);
                                        // 			mplAssert(node_list[*first_set_element]->Stitch_No == *first_set_element);
                                        // 			std::cout<<"COL EDGE is "<<col_edge<<std::endl;
                                        //  			std::cout<<vertex_numbers * (uint32_t)this->color_num() + 2+ starting_index + (stitch_no*pow((uint32_t)this->color_num(),2)) + 
                                        //  first_color *(uint32_t)this->color_num() + second_color<<" "<< vertex_numbers + 1+(col_edge -1)*(uint32_t)this->color_num() + first_color<<std::endl;
                                        Cell_Insert(dl2,vertex_numbers * (uint32_t)this->color_num() + 2+ starting_index + (stitch_no*pow((uint32_t)this->color_num(),2)) + 
                                                first_color *(uint32_t)this->color_num() + second_color, vertex_numbers + 1+(col_edge -1)*(uint32_t)this->color_num() + first_color);
                                    }
                                }
                                //std::cout<<"SECOND SET "<<std::endl;
                                for(auto second_set_element = second_set.begin(); second_set_element !=second_set.end();second_set_element++)
                                {
                                    for(auto child_conflict =  (node_list[*second_set_element]->Conflicts_in_LG).begin(); child_conflict != 
                                            (node_list[*second_set_element]->Conflicts_in_LG).end(); ++child_conflict)
                                    {
                                        int col_edge = -1;
                                        for(std::list<Edge_Simple>::iterator conflict_edge = edge_list[node_list[*second_set_element]->parent->No].begin();conflict_edge != edge_list[node_list[*second_set_element]->parent->No].end();++conflict_edge)
                                        {
                                            if((*conflict_edge).target == (*child_conflict)->No)
                                            {
                                                col_edge = (*conflict_edge).No;
                                                break;
                                            }
                                        }
                                        //mplAssert(col_edge!=-1);
                                        // 			std::cout<<"COL EDGE is "<<col_edge<<std::endl;
                                        //  			std::cout<<vertex_numbers * (uint32_t)this->color_num() + 2+ starting_index + (stitch_no*pow((uint32_t)this->color_num(),2)) + 
                                        //  first_color *(uint32_t)this->color_num() + second_color<<" "<< vertex_numbers + 1+(col_edge -1)*(uint32_t)this->color_num() + second_color<<std::endl;
                                        Cell_Insert(dl2,vertex_numbers * (uint32_t)this->color_num() +2+ starting_index + (stitch_no*pow((uint32_t)this->color_num(),2)) + 
                                                first_color *(uint32_t)this->color_num() + second_color, vertex_numbers + 1+(col_edge -1)*(uint32_t)this->color_num() + second_color);

                                    }
                                }
                            }
                        }
                    }
                    //for each parent node, there are 9 * stitch_No stitch rows totally
                    starting_index += pow((int32_t)this->color_num(),2) * (childs_num -1);
                }
                //std::cout<< "SECOND dl insert" << dancing_link_timer.format(6)<<std::endl;
                //dancing_link_timer.start();
                // if(starting_index != pow((int32_t)this->color_num(),2)* stitch_count)
                // {
                // 	std::cout<<"BUG FOUND!"<<starting_index<<pow((int32_t)this->color_num(),2)* stitch_count<<std::endl;
                // }
                //mplAssert(starting_index == pow((int32_t)this->color_num(),2)* stitch_count);
                //solve dl with stitches
                std::vector<int> selected_rows_by_dl2;
                selected_rows_by_dl2 = core_solve_dl(dl2,edge_list,row_numbers, col_numbers,(int)vertex_numbers,(int32_t)this->color_num());
                //cost 1 is the cost of non-stitch solver
                //std::cout<< "SECOND dl slver" << dancing_link_timer.format(6)<<std::endl;
                //dancing_link_timer.start();
                decode_row_results(selected_rows_by_dl2, color_vector_dl2,(int)vertex_numbers, (int32_t)this->color_num(), decode_mat,node_list);
                double cost2 = new_calc_cost(color_vector_dl2);

                //std::cout<< "SECOND dl get result" << dancing_link_timer.format(6)<<std::endl;
                //dancing_link_timer.start();
                if(cost1 > cost2)
                {
                    cost1 = cost2;
                    this->m_vColor.swap(color_vector_dl2);
                }
            }
            return cost1;
        }


        double solve_by_dancing_link_with_at_most_two_stitches(double current_best_cost){
            // Due to graph does not contain a parent&child node system
            // we simply redesign a node struct to achieve this kind of system
            //boost::timer::cpu_timer dancing_link_timer;
            //dancing_link_timer.start();
            DancingLink dl; 
            std::vector<Vertex*> node_list;
            node_list.resize(num_vertices(this->m_graph));
            uint32_t vertex_numbers = 0;
            uint32_t edge_numbers = 0;
            vertex_iterator_type vi1, vie1;
            for (boost::tie(vi1, vie1) = boost::vertices(this->m_graph); vi1 != vie1; ++vi1)
            {	
                graph_vertex_type v1 = *vi1;
                typename boost::graph_traits<graph_type>::adjacency_iterator vi2, vie2,next2;
                boost::tie(vi2, vie2) = boost::adjacent_vertices(v1, this->m_graph);
                for (next2 = vi2; vi2 != vie2; vi2 = next2)
                {
                    ++next2; 
                    graph_vertex_type v2 = *vi2;
                    if (v1 >= v2) continue;
                    std::pair<graph_edge_type, bool> e12 = boost::edge(v1, v2, this->m_graph);
                    mplAssert(e12.second);
                    //std::cout<<v1<<" "<<v2<<" "<<boost::get(boost::edge_weight, this->m_graph, e12.first)<<std::endl;

                    //if node source and node target is not created. New one/
                    if(!node_list[v1])
                    {
                        Vertex* source_vertex = new Vertex;
                        mplAssert(source_vertex->Conflicts.empty());
                        node_list[v1] = source_vertex;
                        source_vertex->Stitch_No = v1;
                        vertex_numbers ++;
                    }
                    if(!node_list[v2])
                    {
                        Vertex* target_vertex = new Vertex;
                        target_vertex->Stitch_No = v2;
                        node_list[v2] = target_vertex;
                        vertex_numbers ++;
                    }

                    //if two nodes are stitch relationships and both of them are parent
                    if(boost::get(boost::edge_weight, this->m_graph, e12.first) < 0)
                    {
                        // std::cout<<"Stitch:"<<v1<<" "<<v2<<std::endl;
                        if(node_list[v1]->parent != NULL && node_list[v1]->parent== node_list[v2]->parent) continue;
                        Vertex* parent_vertex = new Vertex;
                        mplAssert(parent_vertex->Childs.empty());
                        parent_vertex->parentOf(node_list[v1]);
                        parent_vertex->parentOf(node_list[v2]);
                        vertex_numbers -= 1;
                        continue;
                    }
                    node_list[v1]->Conflicts.insert(node_list[v2]);
                }
            }
            //need to store node list, which does not contain child node
            std::set<Vertex*> node_wo_stitch_list;
            int index = 1;
            for(std::vector<Vertex*>::iterator it = node_list.begin(); it != node_list.end(); ++it) 
            {
                //if the node in parent node, means it has no stitch relations
                (*it)->updateConflicts();
                if((*it)->Is_Parent)
                {
                    node_wo_stitch_list.insert((*it));
                    (*it)->No = index;
                    index ++;
                }
                //else, add its parent node if it has not been added into node_wo_stitch_list
                else
                {
                    mplAssertMsg((*it)->parent->Is_Parent, "%u\n%u\n", (uint32_t)(*it)->Stitch_No, (uint32_t)(*it)->parent->Stitch_No);
                    if(node_wo_stitch_list.find((*it)->parent) == node_wo_stitch_list.end())
                    {
                        node_wo_stitch_list.insert((*it)->parent);
                        (*it)->parent->updateConflicts();
                        (*it)->parent->No = index;
                        index ++;
                    }

                }
            }
            mplAssert(node_wo_stitch_list.size() == vertex_numbers);
            std::vector<std::list<Edge_Simple> >   edge_list;
            edge_list.resize(vertex_numbers + 1);
            for(std::set<Vertex*>::iterator it = node_wo_stitch_list.begin(); it != node_wo_stitch_list.end(); ++it) 
            {
                mplAssert((*it)->No != 0);
                for(std::set<Vertex*>::iterator itconflict = (*it)->Conflicts_in_LG.begin(); itconflict != (*it)->Conflicts_in_LG.end(); ++itconflict) 
                {
                    if((*itconflict)->Is_Parent)
                    {
                        mplAssert((*itconflict)->No != 0);
                        edge_numbers++;
                        edge_list[(*it)->No].push_back(Edge_Simple{ (*itconflict)->No, (int)edge_numbers });
                        edge_list[(*itconflict)->No].push_back(Edge_Simple{ (*it)->No, (int)edge_numbers });	
                    }
                    else
                    {
                        mplAssert((*itconflict)->parent->Is_Parent);
                        //avoid repeat (conflicts of stitch realation nodes may represent same conflict)
                        edge_numbers++;	
                        edge_list[(*it)->No].push_back(Edge_Simple{ (*itconflict)->parent->No, (int)edge_numbers });
                        edge_list[(*itconflict)->parent->No].push_back(Edge_Simple{ (*it)->No, (int)edge_numbers });
                    }
                }
            }
            //std::cout<<"EDGE list generated with size: "<<edge_numbers<<std::endl;
            std::vector<uint32_t> starting_indexes;
            uint32_t starting_index = 0;

            //Stitch Generation: recording strating index of each parent node block
            for(std::set<Vertex*>::iterator it = node_wo_stitch_list.begin(); it != node_wo_stitch_list.end(); ++it)
            {
                uint32_t childs_num = ((*it)->Childs).size();
                mplAssert(childs_num > 1 || childs_num == 0);
                starting_indexes.push_back(starting_index);
                if(childs_num > 1)
                {
                    starting_index += 9*(childs_num-1);
                }
            }

            //This step is to update Stitches set
            int stitch_count = 0;
            for (boost::tie(vi1, vie1) = boost::vertices(this->m_graph); vi1 != vie1; ++vi1)
            {	
                graph_vertex_type v1 = *vi1;
                typename boost::graph_traits<graph_type>::adjacency_iterator vi2, vie2,next2;
                boost::tie(vi2, vie2) = boost::adjacent_vertices(v1, this->m_graph);
                for (next2 = vi2; vi2 != vie2; vi2 = next2)
                {
                    ++next2; 
                    graph_vertex_type v2 = *vi2;
                    if (v1 >= v2) continue;
                    std::pair<graph_edge_type, bool> e12 = boost::edge(v1, v2, this->m_graph);
                    mplAssert(e12.second);
                    //if two nodes are stitch relationships and both of them are parent
                    if(boost::get(boost::edge_weight, this->m_graph, e12.first) < 0)
                    {
                        // std::cout<<"Stitch:"<<int(v1)<<" "<<int(v2)<<std::endl;
                        mplAssert(node_list[v1]->parent == node_list[v2]->parent);
                        Edge* edge = new Edge{int(v1),int(v2),stitch_count};
                        node_list[v1]->parent->Stitches.insert(edge);
                        // std::cout<<"Edge address is: "<<&edge<<std::endl;
                        // std::cout <<"parent->No: "<<node_list[v1]->parent->No<<std::endl;
                        // std::cout<<edge->source<<std::endl;
                        // std::cout<<edge->target<<std::endl;
                        // std::cout<<edge->No<<std::endl;
                        // for(auto stitch = (node_list[v1]->parent->Stitches).begin(); stitch != (node_list[v1]->parent->Stitches).end(); ++stitch){
                        //     std::cout<<"stitch set source: "<< (*stitch)->source<<std::endl;
                        //     std::cout<<"stitch set target: "<<(*stitch)->target<<std::endl;
                        //     std::cout<<"stitch set No: "<<(*stitch)->No<<std::endl;
                        // }   
                        stitch_count ++;
                    }
                }
            }
            //std::cout<< "Graph build" << dancing_link_timer.format(6)<<std::endl;
            //dancing_link_timer.start();
            //BUILD DL MATRIX WITHOUT STITCH
            //Node structure done,  then build DL system
            int row_numbers = vertex_numbers * (int32_t)this->color_num() + 1;
            int col_numbers = edge_numbers * (int32_t)this->color_num() + vertex_numbers;
            //std::cout<<"DL1: row/col is"<<row_numbers<< " "<<col_numbers<<std::endl;
            //std::cout<<"DL1: vertex/edge number is"<<vertex_numbers<< " "<<edge_numbers<<std::endl;
            DL_Init(dl, row_numbers, col_numbers);
            //std::cout<< "FIRST DL initl" << dancing_link_timer.format(6)<<std::endl;
            //dancing_link_timer.start();
            // Insert DL cells

            for (uint32_t it = 1; it < edge_list.size(); ++it)
            {
                for (int32_t i = 1; i <= (int32_t)this->color_num(); ++i)
                {
                    //Insert elements representing nodes color ( first edge_num cols)
                    Cell_Insert(dl,(it - 1)*(int32_t)this->color_num() + i,it);
                    for (auto j = edge_list[it].begin(); j != edge_list[it].end(); ++j)
                    {
                        //Insert elements representing edge conflict
                        Cell_Insert(dl,(it - 1)*(int32_t)this->color_num() + i,vertex_numbers + (j->No - 1)*(int32_t)this->color_num() + i);
                    }
                }
            }
            for (uint32_t i = 0; i < edge_numbers; ++i)
            {
                for (int32_t j = 1; j <= (int32_t)this->color_num(); ++j)
                    //Insert singelon row
                    Cell_Insert(dl,vertex_numbers * (int32_t)this->color_num() + 1,vertex_numbers + i * (int32_t)this->color_num() + j);
            }


            for(std::vector<Vertex*>::iterator it = node_list.begin(); it != node_list.end(); ++it) 
            {
                //if the node in parent node, means it has no stitch relations
                (*it)->updateDuplicateLGConflicts();
                if(!(*it)->Is_Parent)
                    //else, add its parent node if it has not been added into node_wo_stitch_list
                {
                    mplAssert((*it)->parent->Is_Parent);
                    if(node_wo_stitch_list.find((*it)->parent) == node_wo_stitch_list.end())
                    {
                        node_wo_stitch_list.insert((*it)->parent);
                        (*it)->parent->updateDuplicateLGConflicts();
                    }

                }
            }
            //std::cout<< "FIRST DL insert" << dancing_link_timer.format(6)<<std::endl;
            //dancing_link_timer.start();
            //Firstly solve dl without stitches
            std::vector<int> selected_rows_by_dl1;
            selected_rows_by_dl1 = core_solve_dl(dl,edge_list,row_numbers, col_numbers,(int)vertex_numbers,(int32_t)this->color_num());
            //decode_mat for transforming the selected row to represented color. First: node id, Second: color;
            std::vector<std::vector<std::pair<uint32_t,uint32_t>>> decode_mat;
            //cost 1 is the cost of non-stitch solver
            //std::cout<< "FIRST DL SOLVE" << dancing_link_timer.format(6)<<std::endl;
            //dancing_link_timer.start();
            std::vector<int8_t> color_vector_dl1;
            color_vector_dl1.assign(this->m_vColor.size(),-1);
            decode_row_results(selected_rows_by_dl1, color_vector_dl1,(int)vertex_numbers, (int32_t)this->color_num(), decode_mat,node_list);
            double cost1 = new_calc_cost(color_vector_dl1);
            //std::cout<< "FIRST DL GET RESULT" << dancing_link_timer.format(6)<<std::endl;
            //dancing_link_timer.start();
            if(cost1 < current_best_cost){
                this->m_vColor.swap(color_vector_dl1);
            }
            if(cost1 > 0)
            {
                std::vector<int8_t> color_vector_dl2;
                color_vector_dl2.assign(this->m_vColor.size(),-1);
                //Step 1, encode matrix generation
                //if cost1 is larger than 1, which means that there is one more conflicts, than we insert stitch in the node
                //1 st dim: num_parent node + 1
                //2 nd dim: num_stitch of this parent node
                //3 rd pair: deivided child node set by this stitch / conflict parent nodes set of the child nodes set
                std::vector<std::vector<std::pair<std::set<uint32_t>,std::set<uint32_t>>>> encode_mat;
                for(uint32_t i = 0; i<=vertex_numbers; i++)
                {
                    std::vector<std::pair<std::set<uint32_t>,std::set<uint32_t>>> small_encode_mat;
                    encode_mat.push_back(small_encode_mat);
                }
                uint32_t stitch_count = 0;
                //I traverse all of the stitch edges for getting the encode matrix
                vertex_iterator_type vi1, vie1;
                row_numbers = vertex_numbers * (int32_t)this->color_num() + 1;
                for (boost::tie(vi1, vie1) = boost::vertices(this->m_graph); vi1 != vie1; ++vi1)
                {	
                    graph_vertex_type v1 = *vi1;
                    typename boost::graph_traits<graph_type>::adjacency_iterator vi2, vie2,next2;
                    boost::tie(vi2, vie2) = boost::adjacent_vertices(v1, this->m_graph);
                    for (next2 = vi2; vi2 != vie2; vi2 = next2)
                    {
                        ++next2; 
                        graph_vertex_type v2 = *vi2;
                        if (v1 >= v2) continue;
                        std::pair<graph_edge_type, bool> e12 = boost::edge(v1, v2, this->m_graph);
                        mplAssert(e12.second);
                        //if two nodes are stitch relationships
                        if(boost::get(boost::edge_weight, this->m_graph, e12.first) < 0)
                        {
                            stitch_count ++ ;
                            std::set<uint32_t> set1;
                            set1.insert(v1);
                            std::set<uint32_t> set2;
                            set2.insert(v2);
                            push_adj_into_set(v1,this->m_graph,set1,set2);
                            push_adj_into_set(v2,this->m_graph,set2,set1);
                            //std::cout << node_list[v1]->parent->No <<std::endl;
                            std::pair<std::set<uint32_t>,std::set<uint32_t>> encode_mat_per_stitch = std::make_pair(set1,set2);
                            encode_mat[node_list[v1]->parent->No].push_back(encode_mat_per_stitch);
                        }
                    }
                }

                for(std::set<Vertex*>::iterator it = node_wo_stitch_list.begin(); it != node_wo_stitch_list.end(); ++it) {
                    uint32_t childs_num = ((*it)->Childs).size();
                    uint32_t stitch_num = ((*it)->Stitches).size();
                    if(childs_num > 1){
                        // std::cout<<"node id: "<<(*it)->No<<", stitch_num: "<<stitch_num<<", childs_num: "<<childs_num<<std::endl;
                        // for(auto child = ((*it)->Childs).begin(); child != ((*it)->Childs).end(); ++child){
                        //     std::cout<<"child count "<< (*child)->Stitch_No<<std::endl;
                        // }                  
                        mplAssert(childs_num == stitch_num + 1); 
                        // # of rows which select exactly one working stitch, here non-stitch case is included... for implementation convenience
                        row_numbers += stitch_num *(this->color_num()) * (this->color_num());
                        if(childs_num > 2){
                            // # of rows which select exactly two working stitches
                            // this part is done by hard-coding, actually the valid number of rows should be determined by recording the conflict relationship between sub-polygons divided by working stitches.
                            row_numbers += stitch_num *(stitch_num -1)/2* (this->color_num() * (this->color_num() -1 )*(this->color_num() -1));
                        }
                    }
                    
                    }
                //std::cout<< "SECOND encode matrix" << dancing_link_timer.format(6)<<std::endl;
                //dancing_link_timer.start();
                //Step 1.1 BUILD DL MATRIX WITH STITCH
                //Node structure done,  then build DL system
                DancingLink dl2; 
                // row_numbers = vertex_numbers * (int32_t)this->color_num() + 1 + stitch_count * pow((int32_t)this->color_num(),2);
                col_numbers = edge_numbers * (int32_t)this->color_num() + vertex_numbers;
                // std::cout<<"DL2: row/col is"<<row_numbers<< " "<<col_numbers<<std::endl;
                // std::cout<<"DL2: vertex/edge number is"<<vertex_numbers<< " "<<edge_numbers<<std::endl;
                DL_Init(dl2, row_numbers, col_numbers);

                // Insert Non-stitch DL cells
                //std::cout<< "SECOND dl init" << dancing_link_timer.format(6)<<std::endl;
                //dancing_link_timer.start();
                for (uint32_t it = 1; it < edge_list.size(); ++it)
                {
                    for (int32_t i = 1; i <= (int32_t)this->color_num(); ++i)
                    {
                        //Insert elements representing nodes color ( first edge_num cols)
                        Cell_Insert(dl2,(it - 1)*(int32_t)this->color_num() + i,it);
                        for (auto j = edge_list[it].begin(); j != edge_list[it].end(); ++j)
                        {
                            //Insert elements representing edge conflict
                            Cell_Insert(dl2,(it - 1)*(int32_t)this->color_num() + i,vertex_numbers + (j->No - 1)*(int32_t)this->color_num() + i);
                        }
                    }
                }
                for (uint32_t i = 0; i < edge_numbers; ++i)
                {
                    for (int32_t j = 1; j <= (int32_t)this->color_num(); ++j)
                        //Insert singelon row
                        Cell_Insert(dl2,vertex_numbers * (int32_t)this->color_num() + 1,vertex_numbers + i * (int32_t)this->color_num() + j);
                }
                // Step 2 Decode matrix generation and Stitch Rows Cell Insertion
                int count = -1;
                std::vector<uint32_t> starting_indexes;
                uint32_t starting_index = 0;
                for(auto parent_node = node_wo_stitch_list.begin(); parent_node != node_wo_stitch_list.end(); ++parent_node)
                {
                    uint32_t childs_num = ((*parent_node)->Childs).size();
                    int parent_no = (*parent_node)->No;
                    count++;
                    if(childs_num == 0){continue;}
                    mplAssert(childs_num > 1);
                    starting_indexes.push_back(starting_index);
                    for(uint32_t stitch_no = 0; stitch_no < childs_num - 1; stitch_no++)
                    {
                        std::set<uint32_t>  first_set = encode_mat[parent_no][stitch_no].first;
                        std::set<uint32_t>  second_set = encode_mat[parent_no][stitch_no].second;
                        for(auto first_color = 0 ; first_color < (int32_t)this->color_num(); first_color ++)
                        {
                            for(auto second_color = 0 ; second_color < (int32_t)this->color_num(); second_color ++)
                            {
                                //row_decoder indicates the represented color of this row
                                std::vector<std::pair<uint32_t,uint32_t>> row_decoder;
                                //Cell insertion: Node indicator of stitch row
                                Cell_Insert(dl2,vertex_numbers * (uint32_t)this->color_num() + 2+ starting_index + (stitch_no*pow((uint32_t)this->color_num(),2)) + 
                                        first_color *(uint32_t)this->color_num() + second_color, parent_no);
                                for( auto first_set_element = first_set.begin(); first_set_element != first_set.end();first_set_element++)
                                {
                                    row_decoder.push_back(std::make_pair(*first_set_element,first_color));
                                }
                                for(auto second_set_element = second_set.begin(); second_set_element !=second_set.end();second_set_element++)
                                {
                                    row_decoder.push_back(std::make_pair(*second_set_element, second_color));
                                }
                                mplAssertMsg(row_decoder.size() == childs_num, "BUG FOUND! row_decoder.size() %lu, childs_num %u\n", row_decoder.size(), childs_num);
                                decode_mat.push_back(row_decoder);
                                //Cell insertion: conflict indicator of stitch row
                                //std::cout<<"FIRST SET "<<std::endl;
                                for( auto first_set_element = first_set.begin(); first_set_element != first_set.end();first_set_element++)
                                {
                                    for(auto child_conflict =  (node_list[*first_set_element]->Conflicts_in_LG).begin(); child_conflict != 
                                            (node_list[*first_set_element]->Conflicts_in_LG).end(); ++child_conflict)
                                    {
                                        int col_edge = -1;
                                        for(std::list<Edge_Simple>::iterator conflict_edge = edge_list[node_list[*first_set_element]->parent->No].begin();conflict_edge != edge_list[node_list[*first_set_element]->parent->No].end();++conflict_edge)
                                        {
                                            if((*conflict_edge).target == (*child_conflict)->No)
                                            {
                                                col_edge = (*conflict_edge).No;
                                                break;
                                            }
                                        }
                                        // 			mplAssert(col_edge!=-1);
                                        // 			mplAssert(node_list[*first_set_element]->Stitch_No == *first_set_element);
                                        // 			std::cout<<"COL EDGE is "<<col_edge<<std::endl;
                                        //  			std::cout<<vertex_numbers * (uint32_t)this->color_num() + 2+ starting_index + (stitch_no*pow((uint32_t)this->color_num(),2)) + 
                                        //  first_color *(uint32_t)this->color_num() + second_color<<" "<< vertex_numbers + 1+(col_edge -1)*(uint32_t)this->color_num() + first_color<<std::endl;
                                        Cell_Insert(dl2,vertex_numbers * (uint32_t)this->color_num() + 2+ starting_index + (stitch_no*pow((uint32_t)this->color_num(),2)) + 
                                                first_color *(uint32_t)this->color_num() + second_color, vertex_numbers + 1+(col_edge -1)*(uint32_t)this->color_num() + first_color);
                                    }
                                }
                                //std::cout<<"SECOND SET "<<std::endl;
                                for(auto second_set_element = second_set.begin(); second_set_element !=second_set.end();second_set_element++)
                                {
                                    for(auto child_conflict =  (node_list[*second_set_element]->Conflicts_in_LG).begin(); child_conflict != 
                                            (node_list[*second_set_element]->Conflicts_in_LG).end(); ++child_conflict)
                                    {
                                        int col_edge = -1;
                                        for(std::list<Edge_Simple>::iterator conflict_edge = edge_list[node_list[*second_set_element]->parent->No].begin();conflict_edge != edge_list[node_list[*second_set_element]->parent->No].end();++conflict_edge)
                                        {
                                            if((*conflict_edge).target == (*child_conflict)->No)
                                            {
                                                col_edge = (*conflict_edge).No;
                                                break;
                                            }
                                        }
                                        //mplAssert(col_edge!=-1);
                                        // 			std::cout<<"COL EDGE is "<<col_edge<<std::endl;
                                        //  			std::cout<<vertex_numbers * (uint32_t)this->color_num() + 2+ starting_index + (stitch_no*pow((uint32_t)this->color_num(),2)) + 
                                        //  first_color *(uint32_t)this->color_num() + second_color<<" "<< vertex_numbers + 1+(col_edge -1)*(uint32_t)this->color_num() + second_color<<std::endl;
                                        Cell_Insert(dl2,vertex_numbers * (uint32_t)this->color_num() +2+ starting_index + (stitch_no*pow((uint32_t)this->color_num(),2)) + 
                                                first_color *(uint32_t)this->color_num() + second_color, vertex_numbers + 1+(col_edge -1)*(uint32_t)this->color_num() + second_color);

                                    }
                                }
                            }
                        }
                    }
                    //for each parent node, there are 9 * stitch_No stitch rows totally
                    starting_index += pow((int32_t)this->color_num(),2) * (childs_num -1);
                }


                //Now, we insert exactly two stitches 
                std::vector<uint32_t> node_comp(node_list.size(), std::numeric_limits<uint32_t>::max());
                for(auto parent_node = node_wo_stitch_list.begin(); parent_node != node_wo_stitch_list.end(); ++parent_node)
                {
                    uint32_t childs_num = ((*parent_node)->Childs).size();
                    int parent_no = (*parent_node)->No;
                    count++;
                    if(childs_num == 0){continue;}
                    mplAssert(childs_num > 1);
                    starting_indexes.push_back(starting_index);
                    //DYNAMIC TODO: Here we hard-code select two stitches as working stitches. If we need a dynamic k stitches, a recursive func is needed
                    for(auto stitch1 = (*parent_node)->Stitches.begin(); stitch1 != (*parent_node)->Stitches.end(); ++stitch1){
                        for(auto stitch2 = (*parent_node)->Stitches.begin(); stitch2 != (*parent_node)->Stitches.end(); ++stitch2){
                            //if two stitches are the same, it equals to the one stitch situation
                            if((*stitch1)->No < (*stitch2)->No){
                                std::set<Edge*> stitch_set;
                                stitch_set.insert(*stitch1);
                                stitch_set.insert(*stitch2);
                                uint32_t comp_id = 0;
                                std::fill(node_comp.begin(), node_comp.end(), std::numeric_limits<uint32_t>::max());
                                connected_components_k_stitches(node_comp,comp_id,(*parent_node)->Childs,stitch_set);
                                // std::cout<<comp_id<<std::endl;
                                // for(auto stitch:stitch_set){
                                //     std::cout<<"selected stitch->source"<<stitch->source<<std::endl;
                                //     std::cout<<"selected stitch->target"<<stitch->target<<std::endl;
                                // }
                                // for(auto stitch:(*parent_node)->Stitches){
                                //     std::cout<<"all stitch->source"<<stitch->source<<std::endl;
                                //     std::cout<<"all stitch->target"<<stitch->target<<std::endl;                                    
                                // }
                                // for(auto node_comp_item:node_comp){
                                //     std::cout<<node_comp_item<<std::endl;
                                // }
                                mplAssert(comp_id == 3);
                                //DYNAMIC TODO: color should also be a dynamic vector(not color1,color2,color3)
                                std::vector<uint32_t> colors(comp_id, std::numeric_limits<uint32_t>::max());
                                for(uint32_t color0 = 0; color0 < this->color_num(); color0++){
                                    for(uint32_t color1 = 0; color1 < this->color_num();color1++){
                                        for(uint32_t color2 = 0; color2 < this->color_num();color2++){
                                            colors[0] = color0;
                                            colors[1] = color1;
                                            colors[2] = color2;
                                            bool is_invalid = false;
                                            for(auto stitch = stitch_set.begin(); stitch != stitch_set.end(); ++stitch){
                                                mplAssert(node_comp[(*stitch)->source] != node_comp[(*stitch)->target]);
                                                //if two components seperated by one working stitch share same color: then this is invalid! (the stitch is not working!)
                                                if(colors[node_comp[(*stitch)->source]] == colors[node_comp[(*stitch)->target]]){
                                                    is_invalid = true;
                                                    break;
                                                }
                                            }
                                            if(is_invalid)  continue;
                                            //otherwise, we insert the color combination as one row.
                                            
                                            std::vector<std::pair<uint32_t,uint32_t>> row_decoder;
                                            //Insert node indicator
                                            // std::cout<<"Cell_Insert "<<vertex_numbers * (uint32_t)this->color_num() + 2+ starting_index <<" " <<parent_no<<std::endl;
                                            Cell_Insert(dl2,vertex_numbers * (uint32_t)this->color_num() + 2+ starting_index, parent_no);
                                            // for(auto node_comp_item:node_comp){
                                            //     std::cout<<(node_comp_item)<<std::endl;
                                            // }
                                            for(auto child_node = (*parent_node)->Childs.begin(); child_node != (*parent_node)->Childs.end(); ++child_node){
                                                int No = (*child_node)->Stitch_No;
                                                // std::cout<<"No is "<<No<<std::endl;
                                                for(auto child_conflict =  ((*child_node)->Conflicts_in_LG).begin(); child_conflict != 
                                                        ((*child_node)->Conflicts_in_LG).end(); ++child_conflict)
                                                {
                                                    int col_edge = -1;
                                                    // This step is to find col_edge to locate the col number.
                                                    for(std::list<Edge_Simple>::iterator conflict_edge = edge_list[(*child_node)->parent->No].begin();conflict_edge != edge_list[(*child_node)->parent->No].end();++conflict_edge)
                                                    {
                                                        if((*conflict_edge).target == (*child_conflict)->No)
                                                        {
                                                            col_edge = (*conflict_edge).No;
                                                            break;
                                                        }
                                                    }
                                                    // 			mplAssert(col_edge!=-1);
                                                    // 			mplAssert(node_list[*first_set_element]->Stitch_No == *first_set_element);
                                                    // 			std::cout<<"COL EDGE is "<<col_edge<<std::endl;
                                                    //  			std::cout<<vertex_numbers * (uint32_t)this->color_num() + 2+ starting_index + (stitch_no*pow((uint32_t)this->color_num(),2)) + 
                                                    //  first_color *(uint32_t)this->color_num() + second_color<<" "<< vertex_numbers + 1+(col_edge -1)*(uint32_t)this->color_num() + first_color<<std::endl;
                                                    // Insert corresponding edge indicators
                                                    // std::cout<<"Cell_Insert "<<vertex_numbers * (uint32_t)this->color_num() + 2+ starting_index <<" " <<vertex_numbers + 1+(col_edge -1)*(uint32_t)this->color_num() + colors[node_comp[No]]<<std::endl;
                                                    Cell_Insert(dl2,vertex_numbers * (uint32_t)this->color_num() + 2+ starting_index, vertex_numbers + 1+(col_edge -1)*(uint32_t)this->color_num() + colors[node_comp[No]]);
                                                }  
                                                row_decoder.push_back(std::make_pair((uint32_t)No,colors[node_comp[No]]));
                                            }
                                            decode_mat.push_back(row_decoder);
                                            starting_index += 1;
                                        }
                                    }
                                }
                            }
                        }                        
                    }
                }
                //std::cout<< "SECOND dl insert" << dancing_link_timer.format(6)<<std::endl;
                //dancing_link_timer.start();
                // if(starting_index != pow((int32_t)this->color_num(),2)* stitch_count)
                // {
                // 	std::cout<<"BUG FOUND!"<<starting_index<<pow((int32_t)this->color_num(),2)* stitch_count<<std::endl;
                // }
                //mplAssert(starting_index == pow((int32_t)this->color_num(),2)* stitch_count);
                //solve dl with stitches
                std::vector<int> selected_rows_by_dl2;
                selected_rows_by_dl2 = core_solve_dl(dl2,edge_list,row_numbers, col_numbers,(int)vertex_numbers,(int32_t)this->color_num());
                //cost 1 is the cost of non-stitch solver
                //std::cout<< "SECOND dl slver" << dancing_link_timer.format(6)<<std::endl;
                //dancing_link_timer.start();
                decode_row_results(selected_rows_by_dl2, color_vector_dl2,(int)vertex_numbers, (int32_t)this->color_num(), decode_mat,node_list);
                double cost2 = new_calc_cost(color_vector_dl2);

                //std::cout<< "SECOND dl get result" << dancing_link_timer.format(6)<<std::endl;
                //dancing_link_timer.start();
                if(cost1 > cost2 && current_best_cost > cost2)
                {
                    cost1 = cost2;
                    this->m_vColor.swap(color_vector_dl2);
                }
            }
            return cost1;
        }
		//find the node with maximal degree,
		//return: the node id with maximal degree
		//iteratively mark the nodes which locate in some polygon (for new_calc_cost function)
		void iterative_mark(graph_type const& g, std::vector<uint32_t>& parent_node_ids, graph_vertex_type& v1) const
        {
            typename boost::graph_traits<graph_type>::adjacency_iterator vi2, vie2,next2;
            boost::tie(vi2, vie2) = boost::adjacent_vertices(v1, g);
            for (next2 = vi2; vi2 != vie2; vi2 = next2)
            {	
                ++next2; 
                graph_vertex_type v2 = *vi2;
                std::pair<graph_edge_type, bool> e12 = boost::edge(v1, v2, g);
                mplAssert(e12.second);
                //if two nodes are stitch relationships 
                if(boost::get(boost::edge_weight, g, e12.first) < 0)
                {
                    if(parent_node_ids[(uint32_t)v2] == (uint32_t)-1)
                    {
                        parent_node_ids[(uint32_t)v2] = parent_node_ids[(uint32_t)v1];
                        iterative_mark(g, parent_node_ids,v2);
                    }
                    else
                    {
                        mplAssert(parent_node_ids[(uint32_t)v2] == parent_node_ids[(uint32_t)v1]);
                    }
                }
            }
        }

		//calculate cost, used in dancing link
        virtual double new_calc_cost(std::vector<int8_t> const& vColor) const
        {
            double cost = 0;
            std::vector<uint32_t> parent_node_ids;
            parent_node_ids.assign(boost::num_vertices(this->m_graph),-1);
            uint32_t parent_node_id = 0;
            vertex_iterator_type vi1, vie1;
            for (boost::tie(vi1, vie1) = boost::vertices(this->m_graph); vi1 != vie1; ++vi1)
            {	
                graph_vertex_type v1 = *vi1;
                mplAssert(vColor[v1]!=-1);
                if(parent_node_ids[(uint32_t)v1] == (uint32_t)-1)
                {
                    parent_node_ids[(uint32_t)v1] = parent_node_id;
                    iterative_mark(this->m_graph,parent_node_ids,v1);
                    parent_node_id++;
                }
            }


            //calculate conflict by parent node
            std::vector<std::vector<bool>> conflict_mat;
            for(uint32_t i = 0; i < parent_node_id; i++)
            {
                std::vector<bool> row_mat;
                row_mat.assign(parent_node_id,false);
                conflict_mat.push_back(row_mat);
            }

            for (boost::tie(vi1, vie1) = boost::vertices(this->m_graph); vi1 != vie1; ++vi1)
            {	
                graph_vertex_type v1 = *vi1;
                typename boost::graph_traits<graph_type>::adjacency_iterator vi2, vie2,next2;
                boost::tie(vi2, vie2) = boost::adjacent_vertices(v1, this->m_graph);
                for (next2 = vi2; vi2 != vie2; vi2 = next2)
                {
                    ++next2; 
                    graph_vertex_type v2 = *vi2;
                    if (v1 >= v2) continue;
                    std::pair<graph_edge_type, bool> e12 = boost::edge(v1, v2, this->m_graph);
                    mplAssert(e12.second);
                    //if two nodes are stitch relationships and both of them are parent
                    if(boost::get(boost::edge_weight, this->m_graph, e12.first) < 0)
                    {
                        //std::cout<<"Stitch:"<<v1<<" "<<v2<<std::endl;
                        cost += (vColor[v1] != vColor[v2])*this->stitch_weight();
                    }
                    else
                    {
                        if(vColor[v1] == vColor[v2])
                        {
                            if(conflict_mat[parent_node_ids[(uint32_t)v1]][parent_node_ids[(uint32_t)v2]] == false)
                            {
                                cost += 1;
                                conflict_mat[parent_node_ids[(uint32_t)v1]][parent_node_ids[(uint32_t)v2]] = true;
                                conflict_mat[parent_node_ids[(uint32_t)v2]][parent_node_ids[(uint32_t)v1]] = true;
                            }
                        }
                    }
                }
            }

            return cost;
        }
        
		//push stitch adjacents nodes into same des_set used in solve_by_dancing_link_with_one_stitch.
        void push_adj_into_set(graph_vertex_type const& v1, graph_type const& g, std::set<uint32_t> & des_set, std::set<uint32_t> const& oppo_set)
        {
            typename boost::graph_traits<graph_type>::adjacency_iterator vi2, vie2,next2;
            boost::tie(vi2, vie2) = boost::adjacent_vertices(v1, g);
            for (next2 = vi2; vi2 != vie2; vi2 = next2)
            {
                ++next2; 
                graph_vertex_type v2 = *vi2;
                std::pair<graph_edge_type, bool> e12 = boost::edge(v1, v2, g);
                mplAssert(e12.second);
                //if two nodes are stitch relationships
                if(boost::get(boost::edge_weight, g, e12.first) < 0)
                {
                    //if the node has not been seted into the set
                    //std::cout<<"v1 "<<v1<<" , v2 "<<v2<<std::endl;
                    if(des_set.find(v2) == des_set.end() &&oppo_set.find(v2) == oppo_set.end() )
                    {
                        des_set.insert(v2);
                        push_adj_into_set(v2,g,des_set,oppo_set);
                    }
                }
            }
        }


};

SIMPLEMPL_END_NAMESPACE

#endif
