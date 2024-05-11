// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.


// Take the name prefix into account.
#define yylex   VerilogParserlex

// First part of user prologue.
#line 4 "VerilogParser.yy"
 /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>


#line 51 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"


#include "VerilogParser.h"

// Second part of user prologue.
#line 117 "VerilogParser.yy"


#include "VerilogDriver.h"
#include "VerilogScanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


#line 70 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"



#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if VERILOGPARSERDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !VERILOGPARSERDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !VERILOGPARSERDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace VerilogParser {
#line 163 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"

  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
#if VERILOGPARSERDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}


  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    switch (yysym.kind ())
    {
      case symbol_kind::S_NAME: // NAME
#line 110 "VerilogParser.yy"
                    {delete (yysym.value.stringVal);}
#line 375 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
        break;

      case symbol_kind::S_range: // range
#line 111 "VerilogParser.yy"
                    {delete (yysym.value.rangeVal);}
#line 381 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
        break;

      case symbol_kind::S_general_name_array: // general_name_array
#line 113 "VerilogParser.yy"
                    {delete (yysym.value.generalNameArrayVal);}
#line 387 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
        break;

      default:
        break;
    }
  }

#if VERILOGPARSERDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if VERILOGPARSERDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // VERILOGPARSERDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
#line 39 "VerilogParser.yy"
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
}

#line 530 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // range: '[' NUM ':' NUM ']'
#line 134 "VerilogParser.yy"
                           {(yylhs.value.rangeVal) = new Range ((yystack_[3].value.integerVal), (yystack_[1].value.integerVal));}
#line 668 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 3: // range: '[' NUM ']'
#line 135 "VerilogParser.yy"
                   {(yylhs.value.rangeVal) = new Range (std::numeric_limits<int>::min(), (yystack_[1].value.integerVal));}
#line 674 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 4: // general_name_array: NAME
#line 152 "VerilogParser.yy"
                         {
          (yylhs.value.generalNameArrayVal) = new GeneralNameArray(1, GeneralName(*(yystack_[0].value.stringVal)));
          delete (yystack_[0].value.stringVal);
        }
#line 683 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 5: // general_name_array: NAME range
#line 156 "VerilogParser.yy"
                     {
          (yylhs.value.generalNameArrayVal) = new GeneralNameArray(1, GeneralName(*(yystack_[1].value.stringVal), (yystack_[0].value.rangeVal)->low, (yystack_[0].value.rangeVal)->high));
          delete (yystack_[1].value.stringVal);
          delete (yystack_[0].value.rangeVal); 
        }
#line 693 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 6: // general_name_array: general_name_array ',' NAME
#line 161 "VerilogParser.yy"
                                      {
            (yystack_[2].value.generalNameArrayVal)->push_back(GeneralName(*(yystack_[0].value.stringVal)));
            delete (yystack_[0].value.stringVal);
            (yylhs.value.generalNameArrayVal) = (yystack_[2].value.generalNameArrayVal);
        }
#line 703 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 7: // general_name_array: general_name_array ',' NAME range
#line 166 "VerilogParser.yy"
                                            {
            (yystack_[3].value.generalNameArrayVal)->push_back(GeneralName(*(yystack_[1].value.stringVal), (yystack_[0].value.rangeVal)->low, (yystack_[0].value.rangeVal)->high));
            delete (yystack_[1].value.stringVal);
            delete (yystack_[0].value.rangeVal); 
            (yylhs.value.generalNameArrayVal) = (yystack_[3].value.generalNameArrayVal);
        }
#line 714 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 8: // param2: '.' NAME '(' NAME ')'
#line 180 "VerilogParser.yy"
                              {driver.wire_pin_cbk(*(yystack_[1].value.stringVal), *(yystack_[3].value.stringVal)); delete (yystack_[3].value.stringVal); delete (yystack_[1].value.stringVal);}
#line 720 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 9: // param2: '.' NAME '(' NAME range ')'
#line 181 "VerilogParser.yy"
                                    {driver.wire_pin_cbk(*(yystack_[2].value.stringVal), *(yystack_[4].value.stringVal), *(yystack_[1].value.rangeVal)); delete (yystack_[4].value.stringVal); delete (yystack_[2].value.stringVal); delete (yystack_[1].value.rangeVal);}
#line 726 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 10: // param2: '.' NAME '(' ')'
#line 182 "VerilogParser.yy"
                         {delete (yystack_[2].value.stringVal);}
#line 732 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 11: // param2: '.' NAME '(' BIT_MASK ')'
#line 183 "VerilogParser.yy"
                                  {driver.wire_pin_cbk((yystack_[1].value.mask).bits, (yystack_[1].value.mask).value, *(yystack_[3].value.stringVal)); delete (yystack_[3].value.stringVal);}
#line 738 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 12: // param2: '.' NAME '(' OCT_MASK ')'
#line 184 "VerilogParser.yy"
                                  {driver.wire_pin_cbk((yystack_[1].value.mask).bits, (yystack_[1].value.mask).value, *(yystack_[3].value.stringVal)); delete (yystack_[3].value.stringVal);}
#line 744 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 13: // param2: '.' NAME '(' DEC_MASK ')'
#line 185 "VerilogParser.yy"
                                  {driver.wire_pin_cbk((yystack_[1].value.mask).bits, (yystack_[1].value.mask).value, *(yystack_[3].value.stringVal)); delete (yystack_[3].value.stringVal);}
#line 750 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 14: // param2: '.' NAME '(' HEX_MASK ')'
#line 186 "VerilogParser.yy"
                                  {driver.wire_pin_cbk((yystack_[1].value.mask).bits, (yystack_[1].value.mask).value, *(yystack_[3].value.stringVal)); delete (yystack_[3].value.stringVal);}
#line 756 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 15: // param2: '.' NAME '(' '{' general_name_array '}' ')'
#line 187 "VerilogParser.yy"
                                                    {driver.wire_pin_cbk(*(yystack_[2].value.generalNameArrayVal), *(yystack_[5].value.stringVal)); delete (yystack_[5].value.stringVal); delete (yystack_[2].value.generalNameArrayVal);}
#line 762 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 16: // param3: INPUT general_name_array
#line 190 "VerilogParser.yy"
                                 {driver.pin_declare_cbk(*(yystack_[0].value.generalNameArrayVal), kINPUT); delete (yystack_[0].value.generalNameArrayVal);}
#line 768 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 17: // param3: INPUT range general_name_array
#line 191 "VerilogParser.yy"
                                       {driver.pin_declare_cbk(*(yystack_[0].value.generalNameArrayVal), kINPUT, *(yystack_[1].value.rangeVal)); delete (yystack_[1].value.rangeVal); delete (yystack_[0].value.generalNameArrayVal);}
#line 774 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 18: // param3: INPUT REG range general_name_array
#line 192 "VerilogParser.yy"
                                           {driver.pin_declare_cbk(*(yystack_[0].value.generalNameArrayVal), kINPUT|kREG, *(yystack_[1].value.rangeVal)); delete (yystack_[1].value.rangeVal); delete (yystack_[0].value.generalNameArrayVal);}
#line 780 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 19: // param3: INPUT REG general_name_array
#line 193 "VerilogParser.yy"
                                     {driver.pin_declare_cbk(*(yystack_[0].value.generalNameArrayVal), kINPUT|kREG); delete (yystack_[0].value.generalNameArrayVal);}
#line 786 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 20: // param3: OUTPUT general_name_array
#line 194 "VerilogParser.yy"
                                  {driver.pin_declare_cbk(*(yystack_[0].value.generalNameArrayVal), kOUTPUT); delete (yystack_[0].value.generalNameArrayVal);}
#line 792 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 21: // param3: OUTPUT range general_name_array
#line 195 "VerilogParser.yy"
                                        {driver.pin_declare_cbk(*(yystack_[0].value.generalNameArrayVal), kOUTPUT, *(yystack_[1].value.rangeVal)); delete (yystack_[1].value.rangeVal); delete (yystack_[0].value.generalNameArrayVal);}
#line 798 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 22: // param3: OUTPUT REG range general_name_array
#line 196 "VerilogParser.yy"
                                            {driver.pin_declare_cbk(*(yystack_[0].value.generalNameArrayVal), kOUTPUT|kREG, *(yystack_[1].value.rangeVal)); delete (yystack_[1].value.rangeVal); delete (yystack_[0].value.generalNameArrayVal);}
#line 804 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 23: // param3: OUTPUT REG general_name_array
#line 197 "VerilogParser.yy"
                                      {driver.pin_declare_cbk(*(yystack_[0].value.generalNameArrayVal), kOUTPUT|kREG); delete (yystack_[0].value.generalNameArrayVal);}
#line 810 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 24: // param3: INOUT general_name_array
#line 198 "VerilogParser.yy"
                                 {driver.pin_declare_cbk(*(yystack_[0].value.generalNameArrayVal), kINPUT|kOUTPUT); delete (yystack_[0].value.generalNameArrayVal);}
#line 816 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 25: // param3: INOUT range general_name_array
#line 199 "VerilogParser.yy"
                                       {driver.pin_declare_cbk(*(yystack_[0].value.generalNameArrayVal), kINPUT|kOUTPUT, *(yystack_[1].value.rangeVal)); delete (yystack_[1].value.rangeVal); delete (yystack_[0].value.generalNameArrayVal);}
#line 822 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 26: // param3: INOUT REG range general_name_array
#line 200 "VerilogParser.yy"
                                           {driver.pin_declare_cbk(*(yystack_[0].value.generalNameArrayVal), kINPUT|kOUTPUT|kREG, *(yystack_[1].value.rangeVal)); delete (yystack_[1].value.rangeVal); delete (yystack_[0].value.generalNameArrayVal);}
#line 828 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 27: // param3: INOUT REG general_name_array
#line 201 "VerilogParser.yy"
                                     {driver.pin_declare_cbk(*(yystack_[0].value.generalNameArrayVal), kINPUT|kOUTPUT|kREG); delete (yystack_[0].value.generalNameArrayVal);}
#line 834 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 28: // param4: REG general_name_array
#line 204 "VerilogParser.yy"
                               {delete (yystack_[0].value.generalNameArrayVal);}
#line 840 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 29: // param4: REG range general_name_array
#line 205 "VerilogParser.yy"
                                     {delete (yystack_[1].value.rangeVal); delete (yystack_[0].value.generalNameArrayVal);}
#line 846 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 30: // param5: WIRE general_name_array
#line 208 "VerilogParser.yy"
                                {driver.wire_declare_cbk(*(yystack_[0].value.generalNameArrayVal)); delete (yystack_[0].value.generalNameArrayVal);}
#line 852 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 31: // param5: WIRE range general_name_array
#line 209 "VerilogParser.yy"
                                      {driver.wire_declare_cbk(*(yystack_[0].value.generalNameArrayVal), *(yystack_[1].value.rangeVal)); delete (yystack_[1].value.rangeVal); delete (yystack_[0].value.generalNameArrayVal);}
#line 858 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 32: // module_declare: MODULE NAME '(' ')' ';'
#line 225 "VerilogParser.yy"
                                                    {driver.module_name_cbk(*(yystack_[3].value.stringVal), GeneralNameArray()); delete (yystack_[3].value.stringVal);}
#line 864 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 33: // module_declare: MODULE NAME '(' general_name_array ')' ';'
#line 226 "VerilogParser.yy"
                                                           {driver.module_name_cbk(*(yystack_[4].value.stringVal), *(yystack_[2].value.generalNameArrayVal)); delete (yystack_[4].value.stringVal); delete (yystack_[2].value.generalNameArrayVal);}
#line 870 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 40: // module_instance: NAME NAME '(' instance_params ')' ';'
#line 240 "VerilogParser.yy"
                                                       {driver.module_instance_cbk(*(yystack_[5].value.stringVal), *(yystack_[4].value.stringVal)); delete (yystack_[5].value.stringVal); delete (yystack_[4].value.stringVal);}
#line 876 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 41: // module_instance: NAME NAME '[' NUM ']' '(' instance_params ')' ';'
#line 241 "VerilogParser.yy"
                                                                   {
               /* append NUM to instance name */
               char buf[256];
               sprintf(buf, "[%d]", (yystack_[5].value.integerVal));
               (yystack_[7].value.stringVal)->append(buf);
               driver.module_instance_cbk(*(yystack_[8].value.stringVal), *(yystack_[7].value.stringVal)); 
               delete (yystack_[8].value.stringVal); 
               delete (yystack_[7].value.stringVal);
               }
#line 890 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 42: // assignment: ASSIGN NAME '=' NAME ';'
#line 252 "VerilogParser.yy"
                                     {driver.assignment_cbk(*(yystack_[3].value.stringVal), Range(), *(yystack_[1].value.stringVal), Range()); delete (yystack_[3].value.stringVal); delete (yystack_[1].value.stringVal);}
#line 896 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 43: // assignment: ASSIGN NAME range '=' NAME ';'
#line 253 "VerilogParser.yy"
                                           {driver.assignment_cbk(*(yystack_[4].value.stringVal), *(yystack_[3].value.rangeVal), *(yystack_[1].value.stringVal), Range()); delete (yystack_[4].value.stringVal); delete (yystack_[3].value.rangeVal); delete (yystack_[1].value.stringVal);}
#line 902 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 44: // assignment: ASSIGN NAME '=' NAME range ';'
#line 254 "VerilogParser.yy"
                                           {driver.assignment_cbk(*(yystack_[4].value.stringVal), Range(), *(yystack_[2].value.stringVal), *(yystack_[1].value.rangeVal)); delete (yystack_[4].value.stringVal); delete (yystack_[2].value.stringVal); delete (yystack_[1].value.rangeVal);}
#line 908 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;

  case 45: // assignment: ASSIGN NAME range '=' NAME range ';'
#line 255 "VerilogParser.yy"
                                                 {driver.assignment_cbk(*(yystack_[5].value.stringVal), *(yystack_[4].value.rangeVal), *(yystack_[2].value.stringVal), *(yystack_[1].value.rangeVal)); delete (yystack_[5].value.stringVal); delete (yystack_[4].value.rangeVal); delete (yystack_[2].value.stringVal); delete (yystack_[1].value.rangeVal);}
#line 914 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"
    break;


#line 918 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -24;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
     -24,     9,   -24,    -3,   -24,   -24,     2,    52,    -9,    -2,
     -24,    -8,    32,    37,     5,     5,    34,    11,    40,    43,
     -24,   -24,   -24,    51,    45,     3,   -20,     5,    70,    72,
      54,     5,    72,    54,     5,    72,    54,    72,    54,    72,
      54,   -23,   -24,   -24,   -24,   -24,   -24,    74,    50,    75,
      58,    72,    54,    29,    54,    72,    54,    54,    72,    54,
      54,    54,    54,    79,    55,    51,   -24,    64,    83,   -24,
      42,    54,    84,   -24,    54,    54,    -1,    86,   -24,    63,
      66,    58,    67,    71,   -24,    68,     4,    58,    28,   -24,
     -24,   -24,   -24,   -24,    69,    44,   -22,    73,    76,    77,
      80,   -24,    72,   -24,    78,   -24,    82,   -24,   -24,   -24,
     -24,    30,   -24,   -24,    85,   -24
  };

  const signed char
  Parser::yydefact_[] =
  {
      51,     0,     1,     0,    46,    52,     0,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,    48,    49,     4,     0,     0,     0,     0,     0,     0,
      16,     0,     0,    20,     0,     0,    24,     0,    28,     0,
      30,     0,    34,    35,    36,     5,    32,     0,     0,     0,
      37,     0,    19,     0,    17,     0,    23,    21,     0,    27,
      25,    29,    31,     0,     0,     6,    33,     0,     0,    38,
       0,    18,     0,     3,    22,    26,     0,     0,     7,     0,
       0,     0,     0,     0,    42,     0,     0,    37,     0,    39,
      40,     2,    44,    43,     0,     0,     0,     0,     0,     0,
       0,    10,     0,    45,     0,     8,     0,    11,    12,    13,
      14,     0,    41,     9,     0,    15
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -24,    18,   -11,    21,   -24,   -24,   -24,   -24,   -24,    23,
     -24,   -24,   -24,   -24,   -24
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,    29,    25,    69,    17,    18,    19,     4,    20,    70,
      21,    22,     7,     5,     1
  };

  const signed char
  Parser::yytable_[] =
  {
      30,    33,    36,    38,    40,    23,    23,    28,    28,     2,
      49,     6,    26,    27,   105,    50,    52,    63,    54,    23,
      56,    57,    28,    59,    60,     3,    61,    24,    62,    28,
      32,    35,    37,    39,    28,    28,    47,     8,    84,    48,
      71,    45,    96,    93,    74,    51,    23,    75,    41,    55,
      42,    23,    58,    31,    97,    98,    99,   100,    34,    64,
      72,    73,    28,    47,   101,   102,     9,    28,   114,    10,
      11,    12,    13,    14,    15,    81,    16,    81,    82,    43,
     104,    28,    44,    78,    46,    53,    23,    47,    65,    66,
      67,   111,    68,    76,    85,    77,    79,    80,    87,    83,
      86,    88,    89,    91,    94,     0,    90,    92,   103,   107,
      95,     0,   108,   109,   106,     0,   110,   112,   113,     0,
       0,   115
  };

  const signed char
  Parser::yycheck_[] =
  {
      11,    12,    13,    14,    15,    14,    14,    30,    30,     0,
      30,    14,    14,    21,    36,    35,    27,    40,    29,    14,
      31,    32,    30,    34,    35,    16,    37,    36,    39,    30,
      12,    13,    14,    15,    30,    30,    33,    35,    39,    36,
      51,    23,    14,    39,    55,    27,    14,    58,    14,    31,
      39,    14,    34,    21,    26,    27,    28,    29,    21,    41,
      31,    32,    30,    33,    36,    37,    14,    30,    38,    17,
      18,    19,    20,    21,    22,    33,    24,    33,    36,    39,
      36,    30,    39,    65,    39,    15,    14,    33,    14,    39,
      15,   102,    34,    14,    76,    40,    32,    14,    35,    15,
      14,    35,    81,    32,    86,    -1,    39,    39,    39,    36,
      87,    -1,    36,    36,    96,    -1,    36,    39,    36,    -1,
      -1,    36
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    55,     0,    16,    48,    54,    14,    53,    35,    14,
      17,    18,    19,    20,    21,    22,    24,    45,    46,    47,
      49,    51,    52,    14,    36,    43,    14,    21,    30,    42,
      43,    21,    42,    43,    21,    42,    43,    42,    43,    42,
      43,    14,    39,    39,    39,    42,    39,    33,    36,    30,
      35,    42,    43,    15,    43,    42,    43,    43,    42,    43,
      43,    43,    43,    40,    42,    14,    39,    15,    34,    44,
      50,    43,    31,    32,    43,    43,    14,    40,    42,    32,
      14,    33,    36,    15,    39,    42,    14,    35,    35,    44,
      39,    32,    39,    39,    42,    50,    14,    26,    27,    28,
      29,    36,    37,    39,    36,    36,    42,    36,    36,    36,
      36,    43,    39,    36,    38,    36
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    41,    42,    42,    43,    43,    43,    43,    44,    44,
      44,    44,    44,    44,    44,    44,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    46,    46,
      47,    47,    48,    48,    49,    49,    49,    50,    50,    50,
      51,    51,    52,    52,    52,    52,    53,    53,    53,    53,
      54,    55,    55
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     5,     3,     1,     2,     3,     4,     5,     6,
       4,     5,     5,     5,     5,     7,     2,     3,     4,     3,
       2,     3,     4,     3,     2,     3,     4,     3,     2,     3,
       2,     3,     5,     6,     2,     2,     2,     0,     1,     3,
       6,     9,     5,     6,     6,     7,     0,     2,     2,     2,
       3,     0,     2
  };


#if VERILOGPARSERDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "ALWAYS", "EQUAL",
  "POSEDGE", "NEGEDGE", "OR", "BEG", "AND", "IF", "ELSE", "INIT", "AT",
  "NAME", "NUM", "MODULE", "ENDMODULE", "INPUT", "OUTPUT", "INOUT", "REG",
  "WIRE", "INTEGER", "ASSIGN", "TIME", "BIT_MASK", "OCT_MASK", "DEC_MASK",
  "HEX_MASK", "'['", "':'", "']'", "','", "'.'", "'('", "')'", "'{'",
  "'}'", "';'", "'='", "$accept", "range", "general_name_array", "param2",
  "param3", "param4", "param5", "module_declare", "variable_declare",
  "instance_params", "module_instance", "assignment", "module_content",
  "single_module", "start", YY_NULLPTR
  };
#endif


#if VERILOGPARSERDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   134,   134,   135,   152,   156,   161,   166,   180,   181,
     182,   183,   184,   185,   186,   187,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   204,   205,
     208,   209,   225,   226,   229,   230,   231,   235,   236,   237,
     240,   241,   252,   253,   254,   255,   257,   258,   259,   260,
     264,   267,   268
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // VERILOGPARSERDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      35,    36,     2,     2,    33,     2,    34,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    31,    39,
       2,    40,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
    };
    // Last valid token kind.
    const int code_max = 284;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // VerilogParser
#line 1507 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/parsers/verilog/bison/VerilogParser.cc"

#line 273 "VerilogParser.yy"
 /*** Additional Code ***/

void VerilogParser::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}
