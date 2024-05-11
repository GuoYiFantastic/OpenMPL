/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         defyyparse
#define yylex           defyylex
#define yyerror         defyyerror
#define yydebug         defyydebug
#define yynerrs         defyynerrs

/* First part of user prologue.  */
#line 58 "def/def.y"

#include <stdlib.h>
#include <string.h>
#include "defrReader.hpp"
#include "defiUser.hpp"
#include "defrCallBacks.hpp"
#include "lex.h"

#define DEF_MAX_INT 2147483647
#define YYDEBUG 1     // this is temp fix for pcr 755132 
// TX_DIR:TRANSLATION ON


#include "defrData.hpp"
#include "defrSettings.hpp"
#include "defrCallBacks.hpp"

BEGIN_LEFDEF_PARSER_NAMESPACE

// Macro to describe how we handle a callback.
// If the function was set then call it.
// If the function returns non zero then there was an error
// so call the error routine and exit.
//
#define CALLBACK(func, typ, data) \
    if (!defData->errors) {\
      if (func) { \
        if ((defData->defRetVal = (*func)(typ, data, defData->session->UserData)) == PARSE_OK) { \
        } else if (defData->defRetVal == STOP_PARSE) { \
          return defData->defRetVal; \
        } else { \
          defData->defError(6010, "An error has been reported in callback."); \
          return defData->defRetVal; \
        } \
      } \
    }

#define CHKERR() \
    if (defData->checkErrors()) { \
      return 1; \
    }

#define CHKPROPTYPE(propType, propName, name) \
    if (propType == 'N') { \
       defData->warningMsg = (char*)malloc(strlen(propName)+strlen(name)+40); \
       sprintf(defData->warningMsg, "The PropName %s is not defined for %s.", \
               propName, name); \
       defData->defWarning(7010, defData->warningMsg); \
       free(defData->warningMsg); \
    }

int yylex(YYSTYPE *pYylval, defrData *defData)
{
    return defData->defyylex(pYylval);
}


void yyerror(defrData *defData, const char *s)
{
    return defData->defyyerror(s);
}




#define FIXED 1
#define COVER 2
#define PLACED 3
#define UNPLACED 4

#line 147 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "def.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_QSTRING = 3,                    /* QSTRING  */
  YYSYMBOL_T_STRING = 4,                   /* T_STRING  */
  YYSYMBOL_SITE_PATTERN = 5,               /* SITE_PATTERN  */
  YYSYMBOL_NUMBER = 6,                     /* NUMBER  */
  YYSYMBOL_K_HISTORY = 7,                  /* K_HISTORY  */
  YYSYMBOL_K_NAMESCASESENSITIVE = 8,       /* K_NAMESCASESENSITIVE  */
  YYSYMBOL_K_DESIGN = 9,                   /* K_DESIGN  */
  YYSYMBOL_K_VIAS = 10,                    /* K_VIAS  */
  YYSYMBOL_K_TECH = 11,                    /* K_TECH  */
  YYSYMBOL_K_UNITS = 12,                   /* K_UNITS  */
  YYSYMBOL_K_ARRAY = 13,                   /* K_ARRAY  */
  YYSYMBOL_K_FLOORPLAN = 14,               /* K_FLOORPLAN  */
  YYSYMBOL_K_SITE = 15,                    /* K_SITE  */
  YYSYMBOL_K_CANPLACE = 16,                /* K_CANPLACE  */
  YYSYMBOL_K_CANNOTOCCUPY = 17,            /* K_CANNOTOCCUPY  */
  YYSYMBOL_K_DIEAREA = 18,                 /* K_DIEAREA  */
  YYSYMBOL_K_PINS = 19,                    /* K_PINS  */
  YYSYMBOL_K_DEFAULTCAP = 20,              /* K_DEFAULTCAP  */
  YYSYMBOL_K_MINPINS = 21,                 /* K_MINPINS  */
  YYSYMBOL_K_WIRECAP = 22,                 /* K_WIRECAP  */
  YYSYMBOL_K_TRACKS = 23,                  /* K_TRACKS  */
  YYSYMBOL_K_GCELLGRID = 24,               /* K_GCELLGRID  */
  YYSYMBOL_K_DO = 25,                      /* K_DO  */
  YYSYMBOL_K_BY = 26,                      /* K_BY  */
  YYSYMBOL_K_STEP = 27,                    /* K_STEP  */
  YYSYMBOL_K_LAYER = 28,                   /* K_LAYER  */
  YYSYMBOL_K_ROW = 29,                     /* K_ROW  */
  YYSYMBOL_K_RECT = 30,                    /* K_RECT  */
  YYSYMBOL_K_COMPS = 31,                   /* K_COMPS  */
  YYSYMBOL_K_COMP_GEN = 32,                /* K_COMP_GEN  */
  YYSYMBOL_K_SOURCE = 33,                  /* K_SOURCE  */
  YYSYMBOL_K_WEIGHT = 34,                  /* K_WEIGHT  */
  YYSYMBOL_K_EEQMASTER = 35,               /* K_EEQMASTER  */
  YYSYMBOL_K_FIXED = 36,                   /* K_FIXED  */
  YYSYMBOL_K_COVER = 37,                   /* K_COVER  */
  YYSYMBOL_K_UNPLACED = 38,                /* K_UNPLACED  */
  YYSYMBOL_K_PLACED = 39,                  /* K_PLACED  */
  YYSYMBOL_K_FOREIGN = 40,                 /* K_FOREIGN  */
  YYSYMBOL_K_REGION = 41,                  /* K_REGION  */
  YYSYMBOL_K_REGIONS = 42,                 /* K_REGIONS  */
  YYSYMBOL_K_NETS = 43,                    /* K_NETS  */
  YYSYMBOL_K_START_NET = 44,               /* K_START_NET  */
  YYSYMBOL_K_MUSTJOIN = 45,                /* K_MUSTJOIN  */
  YYSYMBOL_K_ORIGINAL = 46,                /* K_ORIGINAL  */
  YYSYMBOL_K_USE = 47,                     /* K_USE  */
  YYSYMBOL_K_STYLE = 48,                   /* K_STYLE  */
  YYSYMBOL_K_PATTERN = 49,                 /* K_PATTERN  */
  YYSYMBOL_K_PATTERNNAME = 50,             /* K_PATTERNNAME  */
  YYSYMBOL_K_ESTCAP = 51,                  /* K_ESTCAP  */
  YYSYMBOL_K_ROUTED = 52,                  /* K_ROUTED  */
  YYSYMBOL_K_NEW = 53,                     /* K_NEW  */
  YYSYMBOL_K_SNETS = 54,                   /* K_SNETS  */
  YYSYMBOL_K_SHAPE = 55,                   /* K_SHAPE  */
  YYSYMBOL_K_WIDTH = 56,                   /* K_WIDTH  */
  YYSYMBOL_K_VOLTAGE = 57,                 /* K_VOLTAGE  */
  YYSYMBOL_K_SPACING = 58,                 /* K_SPACING  */
  YYSYMBOL_K_NONDEFAULTRULE = 59,          /* K_NONDEFAULTRULE  */
  YYSYMBOL_K_NONDEFAULTRULES = 60,         /* K_NONDEFAULTRULES  */
  YYSYMBOL_K_N = 61,                       /* K_N  */
  YYSYMBOL_K_S = 62,                       /* K_S  */
  YYSYMBOL_K_E = 63,                       /* K_E  */
  YYSYMBOL_K_W = 64,                       /* K_W  */
  YYSYMBOL_K_FN = 65,                      /* K_FN  */
  YYSYMBOL_K_FE = 66,                      /* K_FE  */
  YYSYMBOL_K_FS = 67,                      /* K_FS  */
  YYSYMBOL_K_FW = 68,                      /* K_FW  */
  YYSYMBOL_K_GROUPS = 69,                  /* K_GROUPS  */
  YYSYMBOL_K_GROUP = 70,                   /* K_GROUP  */
  YYSYMBOL_K_SOFT = 71,                    /* K_SOFT  */
  YYSYMBOL_K_MAXX = 72,                    /* K_MAXX  */
  YYSYMBOL_K_MAXY = 73,                    /* K_MAXY  */
  YYSYMBOL_K_MAXHALFPERIMETER = 74,        /* K_MAXHALFPERIMETER  */
  YYSYMBOL_K_CONSTRAINTS = 75,             /* K_CONSTRAINTS  */
  YYSYMBOL_K_NET = 76,                     /* K_NET  */
  YYSYMBOL_K_PATH = 77,                    /* K_PATH  */
  YYSYMBOL_K_SUM = 78,                     /* K_SUM  */
  YYSYMBOL_K_DIFF = 79,                    /* K_DIFF  */
  YYSYMBOL_K_SCANCHAINS = 80,              /* K_SCANCHAINS  */
  YYSYMBOL_K_START = 81,                   /* K_START  */
  YYSYMBOL_K_FLOATING = 82,                /* K_FLOATING  */
  YYSYMBOL_K_ORDERED = 83,                 /* K_ORDERED  */
  YYSYMBOL_K_STOP = 84,                    /* K_STOP  */
  YYSYMBOL_K_IN = 85,                      /* K_IN  */
  YYSYMBOL_K_OUT = 86,                     /* K_OUT  */
  YYSYMBOL_K_RISEMIN = 87,                 /* K_RISEMIN  */
  YYSYMBOL_K_RISEMAX = 88,                 /* K_RISEMAX  */
  YYSYMBOL_K_FALLMIN = 89,                 /* K_FALLMIN  */
  YYSYMBOL_K_FALLMAX = 90,                 /* K_FALLMAX  */
  YYSYMBOL_K_WIREDLOGIC = 91,              /* K_WIREDLOGIC  */
  YYSYMBOL_K_MAXDIST = 92,                 /* K_MAXDIST  */
  YYSYMBOL_K_ASSERTIONS = 93,              /* K_ASSERTIONS  */
  YYSYMBOL_K_DISTANCE = 94,                /* K_DISTANCE  */
  YYSYMBOL_K_MICRONS = 95,                 /* K_MICRONS  */
  YYSYMBOL_K_END = 96,                     /* K_END  */
  YYSYMBOL_K_IOTIMINGS = 97,               /* K_IOTIMINGS  */
  YYSYMBOL_K_RISE = 98,                    /* K_RISE  */
  YYSYMBOL_K_FALL = 99,                    /* K_FALL  */
  YYSYMBOL_K_VARIABLE = 100,               /* K_VARIABLE  */
  YYSYMBOL_K_SLEWRATE = 101,               /* K_SLEWRATE  */
  YYSYMBOL_K_CAPACITANCE = 102,            /* K_CAPACITANCE  */
  YYSYMBOL_K_DRIVECELL = 103,              /* K_DRIVECELL  */
  YYSYMBOL_K_FROMPIN = 104,                /* K_FROMPIN  */
  YYSYMBOL_K_TOPIN = 105,                  /* K_TOPIN  */
  YYSYMBOL_K_PARALLEL = 106,               /* K_PARALLEL  */
  YYSYMBOL_K_TIMINGDISABLES = 107,         /* K_TIMINGDISABLES  */
  YYSYMBOL_K_THRUPIN = 108,                /* K_THRUPIN  */
  YYSYMBOL_K_MACRO = 109,                  /* K_MACRO  */
  YYSYMBOL_K_PARTITIONS = 110,             /* K_PARTITIONS  */
  YYSYMBOL_K_TURNOFF = 111,                /* K_TURNOFF  */
  YYSYMBOL_K_FROMCLOCKPIN = 112,           /* K_FROMCLOCKPIN  */
  YYSYMBOL_K_FROMCOMPPIN = 113,            /* K_FROMCOMPPIN  */
  YYSYMBOL_K_FROMIOPIN = 114,              /* K_FROMIOPIN  */
  YYSYMBOL_K_TOCLOCKPIN = 115,             /* K_TOCLOCKPIN  */
  YYSYMBOL_K_TOCOMPPIN = 116,              /* K_TOCOMPPIN  */
  YYSYMBOL_K_TOIOPIN = 117,                /* K_TOIOPIN  */
  YYSYMBOL_K_SETUPRISE = 118,              /* K_SETUPRISE  */
  YYSYMBOL_K_SETUPFALL = 119,              /* K_SETUPFALL  */
  YYSYMBOL_K_HOLDRISE = 120,               /* K_HOLDRISE  */
  YYSYMBOL_K_HOLDFALL = 121,               /* K_HOLDFALL  */
  YYSYMBOL_K_VPIN = 122,                   /* K_VPIN  */
  YYSYMBOL_K_SUBNET = 123,                 /* K_SUBNET  */
  YYSYMBOL_K_XTALK = 124,                  /* K_XTALK  */
  YYSYMBOL_K_PIN = 125,                    /* K_PIN  */
  YYSYMBOL_K_SYNTHESIZED = 126,            /* K_SYNTHESIZED  */
  YYSYMBOL_K_DEFINE = 127,                 /* K_DEFINE  */
  YYSYMBOL_K_DEFINES = 128,                /* K_DEFINES  */
  YYSYMBOL_K_DEFINEB = 129,                /* K_DEFINEB  */
  YYSYMBOL_K_IF = 130,                     /* K_IF  */
  YYSYMBOL_K_THEN = 131,                   /* K_THEN  */
  YYSYMBOL_K_ELSE = 132,                   /* K_ELSE  */
  YYSYMBOL_K_FALSE = 133,                  /* K_FALSE  */
  YYSYMBOL_K_TRUE = 134,                   /* K_TRUE  */
  YYSYMBOL_K_EQ = 135,                     /* K_EQ  */
  YYSYMBOL_K_NE = 136,                     /* K_NE  */
  YYSYMBOL_K_LE = 137,                     /* K_LE  */
  YYSYMBOL_K_LT = 138,                     /* K_LT  */
  YYSYMBOL_K_GE = 139,                     /* K_GE  */
  YYSYMBOL_K_GT = 140,                     /* K_GT  */
  YYSYMBOL_K_OR = 141,                     /* K_OR  */
  YYSYMBOL_K_AND = 142,                    /* K_AND  */
  YYSYMBOL_K_NOT = 143,                    /* K_NOT  */
  YYSYMBOL_K_SPECIAL = 144,                /* K_SPECIAL  */
  YYSYMBOL_K_DIRECTION = 145,              /* K_DIRECTION  */
  YYSYMBOL_K_RANGE = 146,                  /* K_RANGE  */
  YYSYMBOL_K_FPC = 147,                    /* K_FPC  */
  YYSYMBOL_K_HORIZONTAL = 148,             /* K_HORIZONTAL  */
  YYSYMBOL_K_VERTICAL = 149,               /* K_VERTICAL  */
  YYSYMBOL_K_ALIGN = 150,                  /* K_ALIGN  */
  YYSYMBOL_K_MIN = 151,                    /* K_MIN  */
  YYSYMBOL_K_MAX = 152,                    /* K_MAX  */
  YYSYMBOL_K_EQUAL = 153,                  /* K_EQUAL  */
  YYSYMBOL_K_BOTTOMLEFT = 154,             /* K_BOTTOMLEFT  */
  YYSYMBOL_K_TOPRIGHT = 155,               /* K_TOPRIGHT  */
  YYSYMBOL_K_ROWS = 156,                   /* K_ROWS  */
  YYSYMBOL_K_TAPER = 157,                  /* K_TAPER  */
  YYSYMBOL_K_TAPERRULE = 158,              /* K_TAPERRULE  */
  YYSYMBOL_K_VERSION = 159,                /* K_VERSION  */
  YYSYMBOL_K_DIVIDERCHAR = 160,            /* K_DIVIDERCHAR  */
  YYSYMBOL_K_BUSBITCHARS = 161,            /* K_BUSBITCHARS  */
  YYSYMBOL_K_PROPERTYDEFINITIONS = 162,    /* K_PROPERTYDEFINITIONS  */
  YYSYMBOL_K_STRING = 163,                 /* K_STRING  */
  YYSYMBOL_K_REAL = 164,                   /* K_REAL  */
  YYSYMBOL_K_INTEGER = 165,                /* K_INTEGER  */
  YYSYMBOL_K_PROPERTY = 166,               /* K_PROPERTY  */
  YYSYMBOL_K_BEGINEXT = 167,               /* K_BEGINEXT  */
  YYSYMBOL_K_ENDEXT = 168,                 /* K_ENDEXT  */
  YYSYMBOL_K_NAMEMAPSTRING = 169,          /* K_NAMEMAPSTRING  */
  YYSYMBOL_K_ON = 170,                     /* K_ON  */
  YYSYMBOL_K_OFF = 171,                    /* K_OFF  */
  YYSYMBOL_K_X = 172,                      /* K_X  */
  YYSYMBOL_K_Y = 173,                      /* K_Y  */
  YYSYMBOL_K_COMPONENT = 174,              /* K_COMPONENT  */
  YYSYMBOL_K_MASK = 175,                   /* K_MASK  */
  YYSYMBOL_K_MASKSHIFT = 176,              /* K_MASKSHIFT  */
  YYSYMBOL_K_COMPSMASKSHIFT = 177,         /* K_COMPSMASKSHIFT  */
  YYSYMBOL_K_SAMEMASK = 178,               /* K_SAMEMASK  */
  YYSYMBOL_K_PINPROPERTIES = 179,          /* K_PINPROPERTIES  */
  YYSYMBOL_K_TEST = 180,                   /* K_TEST  */
  YYSYMBOL_K_COMMONSCANPINS = 181,         /* K_COMMONSCANPINS  */
  YYSYMBOL_K_SNET = 182,                   /* K_SNET  */
  YYSYMBOL_K_COMPONENTPIN = 183,           /* K_COMPONENTPIN  */
  YYSYMBOL_K_REENTRANTPATHS = 184,         /* K_REENTRANTPATHS  */
  YYSYMBOL_K_SHIELD = 185,                 /* K_SHIELD  */
  YYSYMBOL_K_SHIELDNET = 186,              /* K_SHIELDNET  */
  YYSYMBOL_K_NOSHIELD = 187,               /* K_NOSHIELD  */
  YYSYMBOL_K_VIRTUAL = 188,                /* K_VIRTUAL  */
  YYSYMBOL_K_ANTENNAPINPARTIALMETALAREA = 189, /* K_ANTENNAPINPARTIALMETALAREA  */
  YYSYMBOL_K_ANTENNAPINPARTIALMETALSIDEAREA = 190, /* K_ANTENNAPINPARTIALMETALSIDEAREA  */
  YYSYMBOL_K_ANTENNAPINGATEAREA = 191,     /* K_ANTENNAPINGATEAREA  */
  YYSYMBOL_K_ANTENNAPINDIFFAREA = 192,     /* K_ANTENNAPINDIFFAREA  */
  YYSYMBOL_K_ANTENNAPINMAXAREACAR = 193,   /* K_ANTENNAPINMAXAREACAR  */
  YYSYMBOL_K_ANTENNAPINMAXSIDEAREACAR = 194, /* K_ANTENNAPINMAXSIDEAREACAR  */
  YYSYMBOL_K_ANTENNAPINPARTIALCUTAREA = 195, /* K_ANTENNAPINPARTIALCUTAREA  */
  YYSYMBOL_K_ANTENNAPINMAXCUTCAR = 196,    /* K_ANTENNAPINMAXCUTCAR  */
  YYSYMBOL_K_SIGNAL = 197,                 /* K_SIGNAL  */
  YYSYMBOL_K_POWER = 198,                  /* K_POWER  */
  YYSYMBOL_K_GROUND = 199,                 /* K_GROUND  */
  YYSYMBOL_K_CLOCK = 200,                  /* K_CLOCK  */
  YYSYMBOL_K_TIEOFF = 201,                 /* K_TIEOFF  */
  YYSYMBOL_K_ANALOG = 202,                 /* K_ANALOG  */
  YYSYMBOL_K_SCAN = 203,                   /* K_SCAN  */
  YYSYMBOL_K_RESET = 204,                  /* K_RESET  */
  YYSYMBOL_K_RING = 205,                   /* K_RING  */
  YYSYMBOL_K_STRIPE = 206,                 /* K_STRIPE  */
  YYSYMBOL_K_FOLLOWPIN = 207,              /* K_FOLLOWPIN  */
  YYSYMBOL_K_IOWIRE = 208,                 /* K_IOWIRE  */
  YYSYMBOL_K_COREWIRE = 209,               /* K_COREWIRE  */
  YYSYMBOL_K_BLOCKWIRE = 210,              /* K_BLOCKWIRE  */
  YYSYMBOL_K_FILLWIRE = 211,               /* K_FILLWIRE  */
  YYSYMBOL_K_BLOCKAGEWIRE = 212,           /* K_BLOCKAGEWIRE  */
  YYSYMBOL_K_PADRING = 213,                /* K_PADRING  */
  YYSYMBOL_K_BLOCKRING = 214,              /* K_BLOCKRING  */
  YYSYMBOL_K_BLOCKAGES = 215,              /* K_BLOCKAGES  */
  YYSYMBOL_K_PLACEMENT = 216,              /* K_PLACEMENT  */
  YYSYMBOL_K_SLOTS = 217,                  /* K_SLOTS  */
  YYSYMBOL_K_FILLS = 218,                  /* K_FILLS  */
  YYSYMBOL_K_PUSHDOWN = 219,               /* K_PUSHDOWN  */
  YYSYMBOL_K_NETLIST = 220,                /* K_NETLIST  */
  YYSYMBOL_K_DIST = 221,                   /* K_DIST  */
  YYSYMBOL_K_USER = 222,                   /* K_USER  */
  YYSYMBOL_K_TIMING = 223,                 /* K_TIMING  */
  YYSYMBOL_K_BALANCED = 224,               /* K_BALANCED  */
  YYSYMBOL_K_STEINER = 225,                /* K_STEINER  */
  YYSYMBOL_K_TRUNK = 226,                  /* K_TRUNK  */
  YYSYMBOL_K_FIXEDBUMP = 227,              /* K_FIXEDBUMP  */
  YYSYMBOL_K_FENCE = 228,                  /* K_FENCE  */
  YYSYMBOL_K_FREQUENCY = 229,              /* K_FREQUENCY  */
  YYSYMBOL_K_GUIDE = 230,                  /* K_GUIDE  */
  YYSYMBOL_K_MAXBITS = 231,                /* K_MAXBITS  */
  YYSYMBOL_K_PARTITION = 232,              /* K_PARTITION  */
  YYSYMBOL_K_TYPE = 233,                   /* K_TYPE  */
  YYSYMBOL_K_ANTENNAMODEL = 234,           /* K_ANTENNAMODEL  */
  YYSYMBOL_K_DRCFILL = 235,                /* K_DRCFILL  */
  YYSYMBOL_K_OXIDE1 = 236,                 /* K_OXIDE1  */
  YYSYMBOL_K_OXIDE2 = 237,                 /* K_OXIDE2  */
  YYSYMBOL_K_OXIDE3 = 238,                 /* K_OXIDE3  */
  YYSYMBOL_K_OXIDE4 = 239,                 /* K_OXIDE4  */
  YYSYMBOL_K_CUTSIZE = 240,                /* K_CUTSIZE  */
  YYSYMBOL_K_CUTSPACING = 241,             /* K_CUTSPACING  */
  YYSYMBOL_K_DESIGNRULEWIDTH = 242,        /* K_DESIGNRULEWIDTH  */
  YYSYMBOL_K_DIAGWIDTH = 243,              /* K_DIAGWIDTH  */
  YYSYMBOL_K_ENCLOSURE = 244,              /* K_ENCLOSURE  */
  YYSYMBOL_K_HALO = 245,                   /* K_HALO  */
  YYSYMBOL_K_GROUNDSENSITIVITY = 246,      /* K_GROUNDSENSITIVITY  */
  YYSYMBOL_K_HARDSPACING = 247,            /* K_HARDSPACING  */
  YYSYMBOL_K_LAYERS = 248,                 /* K_LAYERS  */
  YYSYMBOL_K_MINCUTS = 249,                /* K_MINCUTS  */
  YYSYMBOL_K_NETEXPR = 250,                /* K_NETEXPR  */
  YYSYMBOL_K_OFFSET = 251,                 /* K_OFFSET  */
  YYSYMBOL_K_ORIGIN = 252,                 /* K_ORIGIN  */
  YYSYMBOL_K_ROWCOL = 253,                 /* K_ROWCOL  */
  YYSYMBOL_K_STYLES = 254,                 /* K_STYLES  */
  YYSYMBOL_K_POLYGON = 255,                /* K_POLYGON  */
  YYSYMBOL_K_PORT = 256,                   /* K_PORT  */
  YYSYMBOL_K_SUPPLYSENSITIVITY = 257,      /* K_SUPPLYSENSITIVITY  */
  YYSYMBOL_K_VIA = 258,                    /* K_VIA  */
  YYSYMBOL_K_VIARULE = 259,                /* K_VIARULE  */
  YYSYMBOL_K_WIREEXT = 260,                /* K_WIREEXT  */
  YYSYMBOL_K_EXCEPTPGNET = 261,            /* K_EXCEPTPGNET  */
  YYSYMBOL_K_FILLWIREOPC = 262,            /* K_FILLWIREOPC  */
  YYSYMBOL_K_OPC = 263,                    /* K_OPC  */
  YYSYMBOL_K_PARTIAL = 264,                /* K_PARTIAL  */
  YYSYMBOL_K_ROUTEHALO = 265,              /* K_ROUTEHALO  */
  YYSYMBOL_266_ = 266,                     /* ';'  */
  YYSYMBOL_267_ = 267,                     /* '-'  */
  YYSYMBOL_268_ = 268,                     /* '+'  */
  YYSYMBOL_269_ = 269,                     /* '('  */
  YYSYMBOL_270_ = 270,                     /* ')'  */
  YYSYMBOL_271_ = 271,                     /* '*'  */
  YYSYMBOL_272_ = 272,                     /* ','  */
  YYSYMBOL_YYACCEPT = 273,                 /* $accept  */
  YYSYMBOL_def_file = 274,                 /* def_file  */
  YYSYMBOL_version_stmt = 275,             /* version_stmt  */
  YYSYMBOL_276_1 = 276,                    /* $@1  */
  YYSYMBOL_case_sens_stmt = 277,           /* case_sens_stmt  */
  YYSYMBOL_rules = 278,                    /* rules  */
  YYSYMBOL_rule = 279,                     /* rule  */
  YYSYMBOL_design_section = 280,           /* design_section  */
  YYSYMBOL_design_name = 281,              /* design_name  */
  YYSYMBOL_282_2 = 282,                    /* $@2  */
  YYSYMBOL_end_design = 283,               /* end_design  */
  YYSYMBOL_tech_name = 284,                /* tech_name  */
  YYSYMBOL_285_3 = 285,                    /* $@3  */
  YYSYMBOL_array_name = 286,               /* array_name  */
  YYSYMBOL_287_4 = 287,                    /* $@4  */
  YYSYMBOL_floorplan_name = 288,           /* floorplan_name  */
  YYSYMBOL_289_5 = 289,                    /* $@5  */
  YYSYMBOL_history = 290,                  /* history  */
  YYSYMBOL_prop_def_section = 291,         /* prop_def_section  */
  YYSYMBOL_292_6 = 292,                    /* $@6  */
  YYSYMBOL_property_defs = 293,            /* property_defs  */
  YYSYMBOL_property_def = 294,             /* property_def  */
  YYSYMBOL_295_7 = 295,                    /* $@7  */
  YYSYMBOL_296_8 = 296,                    /* $@8  */
  YYSYMBOL_297_9 = 297,                    /* $@9  */
  YYSYMBOL_298_10 = 298,                   /* $@10  */
  YYSYMBOL_299_11 = 299,                   /* $@11  */
  YYSYMBOL_300_12 = 300,                   /* $@12  */
  YYSYMBOL_301_13 = 301,                   /* $@13  */
  YYSYMBOL_302_14 = 302,                   /* $@14  */
  YYSYMBOL_303_15 = 303,                   /* $@15  */
  YYSYMBOL_property_type_and_val = 304,    /* property_type_and_val  */
  YYSYMBOL_305_16 = 305,                   /* $@16  */
  YYSYMBOL_306_17 = 306,                   /* $@17  */
  YYSYMBOL_opt_num_val = 307,              /* opt_num_val  */
  YYSYMBOL_units = 308,                    /* units  */
  YYSYMBOL_divider_char = 309,             /* divider_char  */
  YYSYMBOL_bus_bit_chars = 310,            /* bus_bit_chars  */
  YYSYMBOL_canplace = 311,                 /* canplace  */
  YYSYMBOL_312_18 = 312,                   /* $@18  */
  YYSYMBOL_cannotoccupy = 313,             /* cannotoccupy  */
  YYSYMBOL_314_19 = 314,                   /* $@19  */
  YYSYMBOL_orient = 315,                   /* orient  */
  YYSYMBOL_die_area = 316,                 /* die_area  */
  YYSYMBOL_317_20 = 317,                   /* $@20  */
  YYSYMBOL_pin_cap_rule = 318,             /* pin_cap_rule  */
  YYSYMBOL_start_def_cap = 319,            /* start_def_cap  */
  YYSYMBOL_pin_caps = 320,                 /* pin_caps  */
  YYSYMBOL_pin_cap = 321,                  /* pin_cap  */
  YYSYMBOL_end_def_cap = 322,              /* end_def_cap  */
  YYSYMBOL_pin_rule = 323,                 /* pin_rule  */
  YYSYMBOL_start_pins = 324,               /* start_pins  */
  YYSYMBOL_pins = 325,                     /* pins  */
  YYSYMBOL_pin = 326,                      /* pin  */
  YYSYMBOL_327_21 = 327,                   /* $@21  */
  YYSYMBOL_328_22 = 328,                   /* $@22  */
  YYSYMBOL_329_23 = 329,                   /* $@23  */
  YYSYMBOL_pin_options = 330,              /* pin_options  */
  YYSYMBOL_pin_option = 331,               /* pin_option  */
  YYSYMBOL_332_24 = 332,                   /* $@24  */
  YYSYMBOL_333_25 = 333,                   /* $@25  */
  YYSYMBOL_334_26 = 334,                   /* $@26  */
  YYSYMBOL_335_27 = 335,                   /* $@27  */
  YYSYMBOL_336_28 = 336,                   /* $@28  */
  YYSYMBOL_337_29 = 337,                   /* $@29  */
  YYSYMBOL_338_30 = 338,                   /* $@30  */
  YYSYMBOL_339_31 = 339,                   /* $@31  */
  YYSYMBOL_340_32 = 340,                   /* $@32  */
  YYSYMBOL_341_33 = 341,                   /* $@33  */
  YYSYMBOL_pin_layer_mask_opt = 342,       /* pin_layer_mask_opt  */
  YYSYMBOL_pin_via_mask_opt = 343,         /* pin_via_mask_opt  */
  YYSYMBOL_pin_poly_mask_opt = 344,        /* pin_poly_mask_opt  */
  YYSYMBOL_pin_layer_spacing_opt = 345,    /* pin_layer_spacing_opt  */
  YYSYMBOL_pin_poly_spacing_opt = 346,     /* pin_poly_spacing_opt  */
  YYSYMBOL_pin_oxide = 347,                /* pin_oxide  */
  YYSYMBOL_use_type = 348,                 /* use_type  */
  YYSYMBOL_pin_layer_opt = 349,            /* pin_layer_opt  */
  YYSYMBOL_350_34 = 350,                   /* $@34  */
  YYSYMBOL_end_pins = 351,                 /* end_pins  */
  YYSYMBOL_row_rule = 352,                 /* row_rule  */
  YYSYMBOL_353_35 = 353,                   /* $@35  */
  YYSYMBOL_354_36 = 354,                   /* $@36  */
  YYSYMBOL_row_do_option = 355,            /* row_do_option  */
  YYSYMBOL_row_step_option = 356,          /* row_step_option  */
  YYSYMBOL_row_options = 357,              /* row_options  */
  YYSYMBOL_row_option = 358,               /* row_option  */
  YYSYMBOL_359_37 = 359,                   /* $@37  */
  YYSYMBOL_row_prop_list = 360,            /* row_prop_list  */
  YYSYMBOL_row_prop = 361,                 /* row_prop  */
  YYSYMBOL_tracks_rule = 362,              /* tracks_rule  */
  YYSYMBOL_363_38 = 363,                   /* $@38  */
  YYSYMBOL_track_start = 364,              /* track_start  */
  YYSYMBOL_track_type = 365,               /* track_type  */
  YYSYMBOL_track_opts = 366,               /* track_opts  */
  YYSYMBOL_track_mask_statement = 367,     /* track_mask_statement  */
  YYSYMBOL_same_mask = 368,                /* same_mask  */
  YYSYMBOL_track_layer_statement = 369,    /* track_layer_statement  */
  YYSYMBOL_370_39 = 370,                   /* $@39  */
  YYSYMBOL_track_layers = 371,             /* track_layers  */
  YYSYMBOL_track_layer = 372,              /* track_layer  */
  YYSYMBOL_gcellgrid = 373,                /* gcellgrid  */
  YYSYMBOL_extension_section = 374,        /* extension_section  */
  YYSYMBOL_extension_stmt = 375,           /* extension_stmt  */
  YYSYMBOL_via_section = 376,              /* via_section  */
  YYSYMBOL_via = 377,                      /* via  */
  YYSYMBOL_via_declarations = 378,         /* via_declarations  */
  YYSYMBOL_via_declaration = 379,          /* via_declaration  */
  YYSYMBOL_380_40 = 380,                   /* $@40  */
  YYSYMBOL_381_41 = 381,                   /* $@41  */
  YYSYMBOL_layer_stmts = 382,              /* layer_stmts  */
  YYSYMBOL_layer_stmt = 383,               /* layer_stmt  */
  YYSYMBOL_384_42 = 384,                   /* $@42  */
  YYSYMBOL_385_43 = 385,                   /* $@43  */
  YYSYMBOL_386_44 = 386,                   /* $@44  */
  YYSYMBOL_387_45 = 387,                   /* $@45  */
  YYSYMBOL_388_46 = 388,                   /* $@46  */
  YYSYMBOL_389_47 = 389,                   /* $@47  */
  YYSYMBOL_layer_viarule_opts = 390,       /* layer_viarule_opts  */
  YYSYMBOL_391_48 = 391,                   /* $@48  */
  YYSYMBOL_firstPt = 392,                  /* firstPt  */
  YYSYMBOL_nextPt = 393,                   /* nextPt  */
  YYSYMBOL_otherPts = 394,                 /* otherPts  */
  YYSYMBOL_pt = 395,                       /* pt  */
  YYSYMBOL_mask = 396,                     /* mask  */
  YYSYMBOL_via_end = 397,                  /* via_end  */
  YYSYMBOL_regions_section = 398,          /* regions_section  */
  YYSYMBOL_regions_start = 399,            /* regions_start  */
  YYSYMBOL_regions_stmts = 400,            /* regions_stmts  */
  YYSYMBOL_regions_stmt = 401,             /* regions_stmt  */
  YYSYMBOL_402_49 = 402,                   /* $@49  */
  YYSYMBOL_403_50 = 403,                   /* $@50  */
  YYSYMBOL_rect_list = 404,                /* rect_list  */
  YYSYMBOL_region_options = 405,           /* region_options  */
  YYSYMBOL_region_option = 406,            /* region_option  */
  YYSYMBOL_407_51 = 407,                   /* $@51  */
  YYSYMBOL_region_prop_list = 408,         /* region_prop_list  */
  YYSYMBOL_region_prop = 409,              /* region_prop  */
  YYSYMBOL_region_type = 410,              /* region_type  */
  YYSYMBOL_comps_maskShift_section = 411,  /* comps_maskShift_section  */
  YYSYMBOL_comps_section = 412,            /* comps_section  */
  YYSYMBOL_start_comps = 413,              /* start_comps  */
  YYSYMBOL_layer_statement = 414,          /* layer_statement  */
  YYSYMBOL_maskLayer = 415,                /* maskLayer  */
  YYSYMBOL_comps_rule = 416,               /* comps_rule  */
  YYSYMBOL_comp = 417,                     /* comp  */
  YYSYMBOL_comp_start = 418,               /* comp_start  */
  YYSYMBOL_comp_id_and_name = 419,         /* comp_id_and_name  */
  YYSYMBOL_420_52 = 420,                   /* $@52  */
  YYSYMBOL_comp_net_list = 421,            /* comp_net_list  */
  YYSYMBOL_comp_options = 422,             /* comp_options  */
  YYSYMBOL_comp_option = 423,              /* comp_option  */
  YYSYMBOL_comp_extension_stmt = 424,      /* comp_extension_stmt  */
  YYSYMBOL_comp_eeq = 425,                 /* comp_eeq  */
  YYSYMBOL_426_53 = 426,                   /* $@53  */
  YYSYMBOL_comp_generate = 427,            /* comp_generate  */
  YYSYMBOL_428_54 = 428,                   /* $@54  */
  YYSYMBOL_opt_pattern = 429,              /* opt_pattern  */
  YYSYMBOL_comp_source = 430,              /* comp_source  */
  YYSYMBOL_source_type = 431,              /* source_type  */
  YYSYMBOL_comp_region = 432,              /* comp_region  */
  YYSYMBOL_comp_pnt_list = 433,            /* comp_pnt_list  */
  YYSYMBOL_comp_halo = 434,                /* comp_halo  */
  YYSYMBOL_435_55 = 435,                   /* $@55  */
  YYSYMBOL_halo_soft = 436,                /* halo_soft  */
  YYSYMBOL_comp_routehalo = 437,           /* comp_routehalo  */
  YYSYMBOL_438_56 = 438,                   /* $@56  */
  YYSYMBOL_comp_property = 439,            /* comp_property  */
  YYSYMBOL_440_57 = 440,                   /* $@57  */
  YYSYMBOL_comp_prop_list = 441,           /* comp_prop_list  */
  YYSYMBOL_comp_prop = 442,                /* comp_prop  */
  YYSYMBOL_comp_region_start = 443,        /* comp_region_start  */
  YYSYMBOL_comp_foreign = 444,             /* comp_foreign  */
  YYSYMBOL_445_58 = 445,                   /* $@58  */
  YYSYMBOL_opt_paren = 446,                /* opt_paren  */
  YYSYMBOL_comp_type = 447,                /* comp_type  */
  YYSYMBOL_maskShift = 448,                /* maskShift  */
  YYSYMBOL_449_59 = 449,                   /* $@59  */
  YYSYMBOL_placement_status = 450,         /* placement_status  */
  YYSYMBOL_weight = 451,                   /* weight  */
  YYSYMBOL_end_comps = 452,                /* end_comps  */
  YYSYMBOL_nets_section = 453,             /* nets_section  */
  YYSYMBOL_start_nets = 454,               /* start_nets  */
  YYSYMBOL_net_rules = 455,                /* net_rules  */
  YYSYMBOL_one_net = 456,                  /* one_net  */
  YYSYMBOL_net_and_connections = 457,      /* net_and_connections  */
  YYSYMBOL_net_start = 458,                /* net_start  */
  YYSYMBOL_459_60 = 459,                   /* $@60  */
  YYSYMBOL_net_name = 460,                 /* net_name  */
  YYSYMBOL_461_61 = 461,                   /* $@61  */
  YYSYMBOL_462_62 = 462,                   /* $@62  */
  YYSYMBOL_net_connections = 463,          /* net_connections  */
  YYSYMBOL_net_connection = 464,           /* net_connection  */
  YYSYMBOL_465_63 = 465,                   /* $@63  */
  YYSYMBOL_466_64 = 466,                   /* $@64  */
  YYSYMBOL_467_65 = 467,                   /* $@65  */
  YYSYMBOL_conn_opt = 468,                 /* conn_opt  */
  YYSYMBOL_net_options = 469,              /* net_options  */
  YYSYMBOL_net_option = 470,               /* net_option  */
  YYSYMBOL_471_66 = 471,                   /* $@66  */
  YYSYMBOL_472_67 = 472,                   /* $@67  */
  YYSYMBOL_473_68 = 473,                   /* $@68  */
  YYSYMBOL_474_69 = 474,                   /* $@69  */
  YYSYMBOL_475_70 = 475,                   /* $@70  */
  YYSYMBOL_476_71 = 476,                   /* $@71  */
  YYSYMBOL_477_72 = 477,                   /* $@72  */
  YYSYMBOL_478_73 = 478,                   /* $@73  */
  YYSYMBOL_479_74 = 479,                   /* $@74  */
  YYSYMBOL_480_75 = 480,                   /* $@75  */
  YYSYMBOL_481_76 = 481,                   /* $@76  */
  YYSYMBOL_net_prop_list = 482,            /* net_prop_list  */
  YYSYMBOL_net_prop = 483,                 /* net_prop  */
  YYSYMBOL_netsource_type = 484,           /* netsource_type  */
  YYSYMBOL_vpin_stmt = 485,                /* vpin_stmt  */
  YYSYMBOL_486_77 = 486,                   /* $@77  */
  YYSYMBOL_vpin_begin = 487,               /* vpin_begin  */
  YYSYMBOL_488_78 = 488,                   /* $@78  */
  YYSYMBOL_vpin_layer_opt = 489,           /* vpin_layer_opt  */
  YYSYMBOL_490_79 = 490,                   /* $@79  */
  YYSYMBOL_vpin_options = 491,             /* vpin_options  */
  YYSYMBOL_vpin_status = 492,              /* vpin_status  */
  YYSYMBOL_net_type = 493,                 /* net_type  */
  YYSYMBOL_paths = 494,                    /* paths  */
  YYSYMBOL_new_path = 495,                 /* new_path  */
  YYSYMBOL_496_80 = 496,                   /* $@80  */
  YYSYMBOL_path = 497,                     /* path  */
  YYSYMBOL_498_81 = 498,                   /* $@81  */
  YYSYMBOL_499_82 = 499,                   /* $@82  */
  YYSYMBOL_virtual_statement = 500,        /* virtual_statement  */
  YYSYMBOL_rect_statement = 501,           /* rect_statement  */
  YYSYMBOL_path_item_list = 502,           /* path_item_list  */
  YYSYMBOL_path_item = 503,                /* path_item  */
  YYSYMBOL_504_83 = 504,                   /* $@83  */
  YYSYMBOL_505_84 = 505,                   /* $@84  */
  YYSYMBOL_path_pt = 506,                  /* path_pt  */
  YYSYMBOL_virtual_pt = 507,               /* virtual_pt  */
  YYSYMBOL_rect_pts = 508,                 /* rect_pts  */
  YYSYMBOL_opt_taper_style_s = 509,        /* opt_taper_style_s  */
  YYSYMBOL_opt_taper_style = 510,          /* opt_taper_style  */
  YYSYMBOL_opt_taper = 511,                /* opt_taper  */
  YYSYMBOL_512_85 = 512,                   /* $@85  */
  YYSYMBOL_opt_style = 513,                /* opt_style  */
  YYSYMBOL_opt_spaths = 514,               /* opt_spaths  */
  YYSYMBOL_opt_shape_style = 515,          /* opt_shape_style  */
  YYSYMBOL_end_nets = 516,                 /* end_nets  */
  YYSYMBOL_shape_type = 517,               /* shape_type  */
  YYSYMBOL_snets_section = 518,            /* snets_section  */
  YYSYMBOL_snet_rules = 519,               /* snet_rules  */
  YYSYMBOL_snet_rule = 520,                /* snet_rule  */
  YYSYMBOL_snet_options = 521,             /* snet_options  */
  YYSYMBOL_snet_option = 522,              /* snet_option  */
  YYSYMBOL_snet_other_option = 523,        /* snet_other_option  */
  YYSYMBOL_524_86 = 524,                   /* $@86  */
  YYSYMBOL_525_87 = 525,                   /* $@87  */
  YYSYMBOL_526_88 = 526,                   /* $@88  */
  YYSYMBOL_527_89 = 527,                   /* $@89  */
  YYSYMBOL_528_90 = 528,                   /* $@90  */
  YYSYMBOL_529_91 = 529,                   /* $@91  */
  YYSYMBOL_530_92 = 530,                   /* $@92  */
  YYSYMBOL_531_93 = 531,                   /* $@93  */
  YYSYMBOL_532_94 = 532,                   /* $@94  */
  YYSYMBOL_533_95 = 533,                   /* $@95  */
  YYSYMBOL_orient_pt = 534,                /* orient_pt  */
  YYSYMBOL_shield_layer = 535,             /* shield_layer  */
  YYSYMBOL_536_96 = 536,                   /* $@96  */
  YYSYMBOL_snet_width = 537,               /* snet_width  */
  YYSYMBOL_538_97 = 538,                   /* $@97  */
  YYSYMBOL_snet_voltage = 539,             /* snet_voltage  */
  YYSYMBOL_540_98 = 540,                   /* $@98  */
  YYSYMBOL_snet_spacing = 541,             /* snet_spacing  */
  YYSYMBOL_542_99 = 542,                   /* $@99  */
  YYSYMBOL_543_100 = 543,                  /* $@100  */
  YYSYMBOL_snet_prop_list = 544,           /* snet_prop_list  */
  YYSYMBOL_snet_prop = 545,                /* snet_prop  */
  YYSYMBOL_opt_snet_range = 546,           /* opt_snet_range  */
  YYSYMBOL_opt_range = 547,                /* opt_range  */
  YYSYMBOL_pattern_type = 548,             /* pattern_type  */
  YYSYMBOL_spaths = 549,                   /* spaths  */
  YYSYMBOL_snew_path = 550,                /* snew_path  */
  YYSYMBOL_551_101 = 551,                  /* $@101  */
  YYSYMBOL_spath = 552,                    /* spath  */
  YYSYMBOL_553_102 = 553,                  /* $@102  */
  YYSYMBOL_554_103 = 554,                  /* $@103  */
  YYSYMBOL_width = 555,                    /* width  */
  YYSYMBOL_start_snets = 556,              /* start_snets  */
  YYSYMBOL_end_snets = 557,                /* end_snets  */
  YYSYMBOL_groups_section = 558,           /* groups_section  */
  YYSYMBOL_groups_start = 559,             /* groups_start  */
  YYSYMBOL_group_rules = 560,              /* group_rules  */
  YYSYMBOL_group_rule = 561,               /* group_rule  */
  YYSYMBOL_start_group = 562,              /* start_group  */
  YYSYMBOL_563_104 = 563,                  /* $@104  */
  YYSYMBOL_group_members = 564,            /* group_members  */
  YYSYMBOL_group_member = 565,             /* group_member  */
  YYSYMBOL_group_options = 566,            /* group_options  */
  YYSYMBOL_group_option = 567,             /* group_option  */
  YYSYMBOL_568_105 = 568,                  /* $@105  */
  YYSYMBOL_569_106 = 569,                  /* $@106  */
  YYSYMBOL_group_region = 570,             /* group_region  */
  YYSYMBOL_group_prop_list = 571,          /* group_prop_list  */
  YYSYMBOL_group_prop = 572,               /* group_prop  */
  YYSYMBOL_group_soft_options = 573,       /* group_soft_options  */
  YYSYMBOL_group_soft_option = 574,        /* group_soft_option  */
  YYSYMBOL_groups_end = 575,               /* groups_end  */
  YYSYMBOL_assertions_section = 576,       /* assertions_section  */
  YYSYMBOL_constraint_section = 577,       /* constraint_section  */
  YYSYMBOL_assertions_start = 578,         /* assertions_start  */
  YYSYMBOL_constraints_start = 579,        /* constraints_start  */
  YYSYMBOL_constraint_rules = 580,         /* constraint_rules  */
  YYSYMBOL_constraint_rule = 581,          /* constraint_rule  */
  YYSYMBOL_operand_rule = 582,             /* operand_rule  */
  YYSYMBOL_operand = 583,                  /* operand  */
  YYSYMBOL_584_107 = 584,                  /* $@107  */
  YYSYMBOL_585_108 = 585,                  /* $@108  */
  YYSYMBOL_operand_list = 586,             /* operand_list  */
  YYSYMBOL_wiredlogic_rule = 587,          /* wiredlogic_rule  */
  YYSYMBOL_588_109 = 588,                  /* $@109  */
  YYSYMBOL_opt_plus = 589,                 /* opt_plus  */
  YYSYMBOL_delay_specs = 590,              /* delay_specs  */
  YYSYMBOL_delay_spec = 591,               /* delay_spec  */
  YYSYMBOL_constraints_end = 592,          /* constraints_end  */
  YYSYMBOL_assertions_end = 593,           /* assertions_end  */
  YYSYMBOL_scanchains_section = 594,       /* scanchains_section  */
  YYSYMBOL_scanchain_start = 595,          /* scanchain_start  */
  YYSYMBOL_scanchain_rules = 596,          /* scanchain_rules  */
  YYSYMBOL_scan_rule = 597,                /* scan_rule  */
  YYSYMBOL_start_scan = 598,               /* start_scan  */
  YYSYMBOL_599_110 = 599,                  /* $@110  */
  YYSYMBOL_scan_members = 600,             /* scan_members  */
  YYSYMBOL_opt_pin = 601,                  /* opt_pin  */
  YYSYMBOL_scan_member = 602,              /* scan_member  */
  YYSYMBOL_603_111 = 603,                  /* $@111  */
  YYSYMBOL_604_112 = 604,                  /* $@112  */
  YYSYMBOL_605_113 = 605,                  /* $@113  */
  YYSYMBOL_606_114 = 606,                  /* $@114  */
  YYSYMBOL_607_115 = 607,                  /* $@115  */
  YYSYMBOL_608_116 = 608,                  /* $@116  */
  YYSYMBOL_opt_common_pins = 609,          /* opt_common_pins  */
  YYSYMBOL_floating_inst_list = 610,       /* floating_inst_list  */
  YYSYMBOL_one_floating_inst = 611,        /* one_floating_inst  */
  YYSYMBOL_612_117 = 612,                  /* $@117  */
  YYSYMBOL_floating_pins = 613,            /* floating_pins  */
  YYSYMBOL_ordered_inst_list = 614,        /* ordered_inst_list  */
  YYSYMBOL_one_ordered_inst = 615,         /* one_ordered_inst  */
  YYSYMBOL_616_118 = 616,                  /* $@118  */
  YYSYMBOL_ordered_pins = 617,             /* ordered_pins  */
  YYSYMBOL_partition_maxbits = 618,        /* partition_maxbits  */
  YYSYMBOL_scanchain_end = 619,            /* scanchain_end  */
  YYSYMBOL_iotiming_section = 620,         /* iotiming_section  */
  YYSYMBOL_iotiming_start = 621,           /* iotiming_start  */
  YYSYMBOL_iotiming_rules = 622,           /* iotiming_rules  */
  YYSYMBOL_iotiming_rule = 623,            /* iotiming_rule  */
  YYSYMBOL_start_iotiming = 624,           /* start_iotiming  */
  YYSYMBOL_625_119 = 625,                  /* $@119  */
  YYSYMBOL_iotiming_members = 626,         /* iotiming_members  */
  YYSYMBOL_iotiming_member = 627,          /* iotiming_member  */
  YYSYMBOL_628_120 = 628,                  /* $@120  */
  YYSYMBOL_629_121 = 629,                  /* $@121  */
  YYSYMBOL_iotiming_drivecell_opt = 630,   /* iotiming_drivecell_opt  */
  YYSYMBOL_631_122 = 631,                  /* $@122  */
  YYSYMBOL_632_123 = 632,                  /* $@123  */
  YYSYMBOL_iotiming_frompin = 633,         /* iotiming_frompin  */
  YYSYMBOL_634_124 = 634,                  /* $@124  */
  YYSYMBOL_iotiming_parallel = 635,        /* iotiming_parallel  */
  YYSYMBOL_risefall = 636,                 /* risefall  */
  YYSYMBOL_iotiming_end = 637,             /* iotiming_end  */
  YYSYMBOL_floorplan_contraints_section = 638, /* floorplan_contraints_section  */
  YYSYMBOL_fp_start = 639,                 /* fp_start  */
  YYSYMBOL_fp_stmts = 640,                 /* fp_stmts  */
  YYSYMBOL_fp_stmt = 641,                  /* fp_stmt  */
  YYSYMBOL_642_125 = 642,                  /* $@125  */
  YYSYMBOL_643_126 = 643,                  /* $@126  */
  YYSYMBOL_h_or_v = 644,                   /* h_or_v  */
  YYSYMBOL_constraint_type = 645,          /* constraint_type  */
  YYSYMBOL_constrain_what_list = 646,      /* constrain_what_list  */
  YYSYMBOL_constrain_what = 647,           /* constrain_what  */
  YYSYMBOL_648_127 = 648,                  /* $@127  */
  YYSYMBOL_649_128 = 649,                  /* $@128  */
  YYSYMBOL_row_or_comp_list = 650,         /* row_or_comp_list  */
  YYSYMBOL_row_or_comp = 651,              /* row_or_comp  */
  YYSYMBOL_652_129 = 652,                  /* $@129  */
  YYSYMBOL_653_130 = 653,                  /* $@130  */
  YYSYMBOL_timingdisables_section = 654,   /* timingdisables_section  */
  YYSYMBOL_timingdisables_start = 655,     /* timingdisables_start  */
  YYSYMBOL_timingdisables_rules = 656,     /* timingdisables_rules  */
  YYSYMBOL_timingdisables_rule = 657,      /* timingdisables_rule  */
  YYSYMBOL_658_131 = 658,                  /* $@131  */
  YYSYMBOL_659_132 = 659,                  /* $@132  */
  YYSYMBOL_660_133 = 660,                  /* $@133  */
  YYSYMBOL_661_134 = 661,                  /* $@134  */
  YYSYMBOL_td_macro_option = 662,          /* td_macro_option  */
  YYSYMBOL_663_135 = 663,                  /* $@135  */
  YYSYMBOL_664_136 = 664,                  /* $@136  */
  YYSYMBOL_665_137 = 665,                  /* $@137  */
  YYSYMBOL_timingdisables_end = 666,       /* timingdisables_end  */
  YYSYMBOL_partitions_section = 667,       /* partitions_section  */
  YYSYMBOL_partitions_start = 668,         /* partitions_start  */
  YYSYMBOL_partition_rules = 669,          /* partition_rules  */
  YYSYMBOL_partition_rule = 670,           /* partition_rule  */
  YYSYMBOL_start_partition = 671,          /* start_partition  */
  YYSYMBOL_672_138 = 672,                  /* $@138  */
  YYSYMBOL_turnoff = 673,                  /* turnoff  */
  YYSYMBOL_turnoff_setup = 674,            /* turnoff_setup  */
  YYSYMBOL_turnoff_hold = 675,             /* turnoff_hold  */
  YYSYMBOL_partition_members = 676,        /* partition_members  */
  YYSYMBOL_partition_member = 677,         /* partition_member  */
  YYSYMBOL_678_139 = 678,                  /* $@139  */
  YYSYMBOL_679_140 = 679,                  /* $@140  */
  YYSYMBOL_680_141 = 680,                  /* $@141  */
  YYSYMBOL_681_142 = 681,                  /* $@142  */
  YYSYMBOL_682_143 = 682,                  /* $@143  */
  YYSYMBOL_683_144 = 683,                  /* $@144  */
  YYSYMBOL_minmaxpins = 684,               /* minmaxpins  */
  YYSYMBOL_685_145 = 685,                  /* $@145  */
  YYSYMBOL_min_or_max_list = 686,          /* min_or_max_list  */
  YYSYMBOL_min_or_max_member = 687,        /* min_or_max_member  */
  YYSYMBOL_pin_list = 688,                 /* pin_list  */
  YYSYMBOL_risefallminmax1_list = 689,     /* risefallminmax1_list  */
  YYSYMBOL_risefallminmax1 = 690,          /* risefallminmax1  */
  YYSYMBOL_risefallminmax2_list = 691,     /* risefallminmax2_list  */
  YYSYMBOL_risefallminmax2 = 692,          /* risefallminmax2  */
  YYSYMBOL_partitions_end = 693,           /* partitions_end  */
  YYSYMBOL_comp_names = 694,               /* comp_names  */
  YYSYMBOL_comp_name = 695,                /* comp_name  */
  YYSYMBOL_696_146 = 696,                  /* $@146  */
  YYSYMBOL_subnet_opt_syn = 697,           /* subnet_opt_syn  */
  YYSYMBOL_subnet_options = 698,           /* subnet_options  */
  YYSYMBOL_subnet_option = 699,            /* subnet_option  */
  YYSYMBOL_700_147 = 700,                  /* $@147  */
  YYSYMBOL_701_148 = 701,                  /* $@148  */
  YYSYMBOL_subnet_type = 702,              /* subnet_type  */
  YYSYMBOL_pin_props_section = 703,        /* pin_props_section  */
  YYSYMBOL_begin_pin_props = 704,          /* begin_pin_props  */
  YYSYMBOL_opt_semi = 705,                 /* opt_semi  */
  YYSYMBOL_end_pin_props = 706,            /* end_pin_props  */
  YYSYMBOL_pin_prop_list = 707,            /* pin_prop_list  */
  YYSYMBOL_pin_prop_terminal = 708,        /* pin_prop_terminal  */
  YYSYMBOL_709_149 = 709,                  /* $@149  */
  YYSYMBOL_710_150 = 710,                  /* $@150  */
  YYSYMBOL_pin_prop_options = 711,         /* pin_prop_options  */
  YYSYMBOL_pin_prop = 712,                 /* pin_prop  */
  YYSYMBOL_713_151 = 713,                  /* $@151  */
  YYSYMBOL_pin_prop_name_value_list = 714, /* pin_prop_name_value_list  */
  YYSYMBOL_pin_prop_name_value = 715,      /* pin_prop_name_value  */
  YYSYMBOL_blockage_section = 716,         /* blockage_section  */
  YYSYMBOL_blockage_start = 717,           /* blockage_start  */
  YYSYMBOL_blockage_end = 718,             /* blockage_end  */
  YYSYMBOL_blockage_defs = 719,            /* blockage_defs  */
  YYSYMBOL_blockage_def = 720,             /* blockage_def  */
  YYSYMBOL_blockage_rule = 721,            /* blockage_rule  */
  YYSYMBOL_722_152 = 722,                  /* $@152  */
  YYSYMBOL_723_153 = 723,                  /* $@153  */
  YYSYMBOL_724_154 = 724,                  /* $@154  */
  YYSYMBOL_layer_blockage_rules = 725,     /* layer_blockage_rules  */
  YYSYMBOL_layer_blockage_rule = 726,      /* layer_blockage_rule  */
  YYSYMBOL_mask_blockage_rule = 727,       /* mask_blockage_rule  */
  YYSYMBOL_comp_blockage_rule = 728,       /* comp_blockage_rule  */
  YYSYMBOL_729_155 = 729,                  /* $@155  */
  YYSYMBOL_placement_comp_rules = 730,     /* placement_comp_rules  */
  YYSYMBOL_placement_comp_rule = 731,      /* placement_comp_rule  */
  YYSYMBOL_732_156 = 732,                  /* $@156  */
  YYSYMBOL_rectPoly_blockage_rules = 733,  /* rectPoly_blockage_rules  */
  YYSYMBOL_rectPoly_blockage = 734,        /* rectPoly_blockage  */
  YYSYMBOL_735_157 = 735,                  /* $@157  */
  YYSYMBOL_slot_section = 736,             /* slot_section  */
  YYSYMBOL_slot_start = 737,               /* slot_start  */
  YYSYMBOL_slot_end = 738,                 /* slot_end  */
  YYSYMBOL_slot_defs = 739,                /* slot_defs  */
  YYSYMBOL_slot_def = 740,                 /* slot_def  */
  YYSYMBOL_slot_rule = 741,                /* slot_rule  */
  YYSYMBOL_742_158 = 742,                  /* $@158  */
  YYSYMBOL_743_159 = 743,                  /* $@159  */
  YYSYMBOL_geom_slot_rules = 744,          /* geom_slot_rules  */
  YYSYMBOL_geom_slot = 745,                /* geom_slot  */
  YYSYMBOL_746_160 = 746,                  /* $@160  */
  YYSYMBOL_fill_section = 747,             /* fill_section  */
  YYSYMBOL_fill_start = 748,               /* fill_start  */
  YYSYMBOL_fill_end = 749,                 /* fill_end  */
  YYSYMBOL_fill_defs = 750,                /* fill_defs  */
  YYSYMBOL_fill_def = 751,                 /* fill_def  */
  YYSYMBOL_752_161 = 752,                  /* $@161  */
  YYSYMBOL_753_162 = 753,                  /* $@162  */
  YYSYMBOL_fill_rule = 754,                /* fill_rule  */
  YYSYMBOL_755_163 = 755,                  /* $@163  */
  YYSYMBOL_756_164 = 756,                  /* $@164  */
  YYSYMBOL_geom_fill_rules = 757,          /* geom_fill_rules  */
  YYSYMBOL_geom_fill = 758,                /* geom_fill  */
  YYSYMBOL_759_165 = 759,                  /* $@165  */
  YYSYMBOL_fill_layer_mask_opc_opt = 760,  /* fill_layer_mask_opc_opt  */
  YYSYMBOL_opt_mask_opc_l = 761,           /* opt_mask_opc_l  */
  YYSYMBOL_fill_layer_opc = 762,           /* fill_layer_opc  */
  YYSYMBOL_fill_via_pt = 763,              /* fill_via_pt  */
  YYSYMBOL_fill_via_mask_opc_opt = 764,    /* fill_via_mask_opc_opt  */
  YYSYMBOL_opt_mask_opc = 765,             /* opt_mask_opc  */
  YYSYMBOL_fill_via_opc = 766,             /* fill_via_opc  */
  YYSYMBOL_fill_mask = 767,                /* fill_mask  */
  YYSYMBOL_fill_viaMask = 768,             /* fill_viaMask  */
  YYSYMBOL_nondefaultrule_section = 769,   /* nondefaultrule_section  */
  YYSYMBOL_nondefault_start = 770,         /* nondefault_start  */
  YYSYMBOL_nondefault_end = 771,           /* nondefault_end  */
  YYSYMBOL_nondefault_defs = 772,          /* nondefault_defs  */
  YYSYMBOL_nondefault_def = 773,           /* nondefault_def  */
  YYSYMBOL_774_166 = 774,                  /* $@166  */
  YYSYMBOL_775_167 = 775,                  /* $@167  */
  YYSYMBOL_nondefault_options = 776,       /* nondefault_options  */
  YYSYMBOL_nondefault_option = 777,        /* nondefault_option  */
  YYSYMBOL_778_168 = 778,                  /* $@168  */
  YYSYMBOL_779_169 = 779,                  /* $@169  */
  YYSYMBOL_780_170 = 780,                  /* $@170  */
  YYSYMBOL_781_171 = 781,                  /* $@171  */
  YYSYMBOL_782_172 = 782,                  /* $@172  */
  YYSYMBOL_nondefault_layer_options = 783, /* nondefault_layer_options  */
  YYSYMBOL_nondefault_layer_option = 784,  /* nondefault_layer_option  */
  YYSYMBOL_nondefault_prop_opt = 785,      /* nondefault_prop_opt  */
  YYSYMBOL_786_173 = 786,                  /* $@173  */
  YYSYMBOL_nondefault_prop_list = 787,     /* nondefault_prop_list  */
  YYSYMBOL_nondefault_prop = 788,          /* nondefault_prop  */
  YYSYMBOL_styles_section = 789,           /* styles_section  */
  YYSYMBOL_styles_start = 790,             /* styles_start  */
  YYSYMBOL_styles_end = 791,               /* styles_end  */
  YYSYMBOL_styles_rules = 792,             /* styles_rules  */
  YYSYMBOL_styles_rule = 793,              /* styles_rule  */
  YYSYMBOL_794_174 = 794                   /* $@174  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1486

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  273
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  522
/* YYNRULES -- Number of rules.  */
#define YYNRULES  957
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1668

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   520


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     269,   270,   271,   268,   272,   267,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   266,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   216,   216,   219,   220,   220,   246,   247,   260,   278,
     279,   280,   283,   283,   283,   283,   284,   284,   284,   284,
     285,   285,   285,   286,   286,   286,   287,   287,   287,   288,
     288,   288,   288,   289,   292,   292,   292,   292,   293,   293,
     293,   294,   294,   294,   295,   295,   295,   296,   296,   296,
     296,   301,   301,   308,   333,   333,   339,   339,   345,   345,
     351,   358,   357,   369,   370,   373,   373,   382,   382,   391,
     391,   400,   400,   409,   409,   418,   418,   427,   427,   438,
     437,   448,   447,   468,   470,   470,   475,   475,   481,   486,
     491,   497,   498,   501,   509,   516,   523,   523,   535,   535,
     548,   549,   550,   551,   552,   553,   554,   555,   558,   557,
     570,   573,   585,   586,   589,   600,   603,   606,   612,   613,
     616,   617,   618,   616,   630,   631,   633,   639,   645,   651,
     672,   672,   692,   692,   712,   716,   737,   738,   737,   756,
     757,   756,   792,   792,   818,   829,   847,   865,   883,   901,
     901,   919,   919,   938,   956,   956,   974,   991,   992,  1006,
    1007,  1014,  1015,  1028,  1029,  1052,  1076,  1077,  1100,  1124,
    1129,  1134,  1139,  1145,  1147,  1149,  1151,  1153,  1155,  1157,
    1159,  1164,  1165,  1165,  1168,  1174,  1176,  1174,  1190,  1200,
    1238,  1241,  1249,  1250,  1253,  1253,  1257,  1258,  1261,  1273,
    1282,  1293,  1292,  1326,  1331,  1333,  1336,  1338,  1339,  1350,
    1351,  1354,  1355,  1355,  1358,  1359,  1362,  1368,  1397,  1403,
    1406,  1409,  1415,  1416,  1419,  1420,  1419,  1431,  1432,  1435,
    1435,  1442,  1443,  1442,  1469,  1469,  1479,  1481,  1479,  1504,
    1505,  1511,  1523,  1535,  1547,  1547,  1560,  1563,  1566,  1567,
    1570,  1577,  1583,  1589,  1596,  1597,  1600,  1606,  1612,  1618,
    1619,  1622,  1623,  1622,  1632,  1635,  1640,  1641,  1644,  1644,
    1647,  1662,  1663,  1666,  1681,  1690,  1700,  1702,  1705,  1722,
    1725,  1732,  1733,  1736,  1743,  1744,  1747,  1753,  1759,  1759,
    1767,  1768,  1773,  1779,  1780,  1783,  1783,  1783,  1783,  1783,
    1784,  1784,  1784,  1784,  1785,  1785,  1785,  1788,  1795,  1795,
    1801,  1801,  1809,  1810,  1813,  1819,  1821,  1823,  1825,  1830,
    1832,  1838,  1849,  1862,  1861,  1883,  1884,  1904,  1904,  1924,
    1924,  1928,  1929,  1932,  1943,  1952,  1962,  1965,  1965,  1980,
    1982,  1985,  1992,  1999,  2014,  2014,  2023,  2025,  2027,  2030,
    2036,  2042,  2045,  2052,  2053,  2056,  2067,  2071,  2071,  2074,
    2073,  2082,  2082,  2090,  2091,  2094,  2094,  2108,  2108,  2115,
    2115,  2124,  2125,  2132,  2137,  2138,  2142,  2141,  2160,  2163,
    2180,  2180,  2198,  2198,  2201,  2204,  2207,  2210,  2213,  2216,
    2219,  2219,  2230,  2232,  2232,  2235,  2236,  2235,  2282,  2287,
    2297,  2281,  2311,  2311,  2315,  2321,  2322,  2325,  2336,  2345,
    2355,  2357,  2359,  2361,  2363,  2367,  2366,  2377,  2377,  2380,
    2381,  2381,  2384,  2385,  2388,  2390,  2392,  2395,  2397,  2399,
    2403,  2407,  2410,  2410,  2416,  2435,  2415,  2449,  2466,  2483,
    2484,  2489,  2500,  2514,  2521,  2532,  2556,  2590,  2624,  2649,
    2650,  2651,  2651,  2662,  2661,  2671,  2682,  2690,  2697,  2704,
    2710,  2718,  2726,  2734,  2743,  2751,  2758,  2765,  2773,  2782,
    2783,  2785,  2786,  2789,  2793,  2793,  2798,  2818,  2819,  2823,
    2827,  2847,  2853,  2855,  2857,  2859,  2861,  2863,  2865,  2867,
    2883,  2885,  2887,  2889,  2892,  2895,  2896,  2899,  2902,  2903,
    2906,  2906,  2907,  2907,  2910,  2924,  2923,  2945,  2946,  2945,
    2952,  2956,  2962,  2963,  2962,  3003,  3003,  3036,  3037,  3036,
    3069,  3072,  3075,  3078,  3078,  3081,  3084,  3087,  3098,  3101,
    3104,  3104,  3108,  3112,  3113,  3114,  3115,  3116,  3117,  3118,
    3119,  3120,  3123,  3137,  3137,  3192,  3192,  3203,  3203,  3221,
    3222,  3221,  3229,  3230,  3233,  3245,  3254,  3264,  3265,  3270,
    3271,  3274,  3276,  3278,  3280,  3284,  3301,  3304,  3304,  3323,
    3331,  3322,  3339,  3344,  3351,  3358,  3361,  3367,  3368,  3371,
    3377,  3377,  3388,  3389,  3392,  3399,  3400,  3403,  3405,  3405,
    3408,  3408,  3410,  3416,  3426,  3431,  3432,  3435,  3446,  3455,
    3465,  3466,  3469,  3479,  3489,  3500,  3507,  3511,  3514,  3528,
    3542,  3543,  3546,  3547,  3557,  3570,  3570,  3575,  3575,  3580,
    3585,  3591,  3592,  3594,  3596,  3596,  3605,  3606,  3609,  3610,
    3613,  3618,  3623,  3628,  3634,  3645,  3656,  3659,  3665,  3666,
    3669,  3675,  3675,  3682,  3683,  3688,  3689,  3692,  3692,  3696,
    3696,  3699,  3698,  3707,  3707,  3711,  3711,  3713,  3713,  3731,
    3738,  3739,  3748,  3762,  3763,  3767,  3766,  3777,  3778,  3791,
    3812,  3843,  3844,  3848,  3847,  3856,  3857,  3870,  3891,  3923,
    3924,  3927,  3936,  3939,  3950,  3951,  3954,  3960,  3960,  3966,
    3967,  3971,  3976,  3981,  3986,  3987,  3986,  3995,  4002,  4003,
    4001,  4009,  4010,  4010,  4016,  4017,  4023,  4023,  4025,  4031,
    4037,  4043,  4044,  4047,  4048,  4047,  4052,  4054,  4057,  4059,
    4061,  4063,  4066,  4067,  4071,  4070,  4074,  4073,  4078,  4079,
    4081,  4081,  4083,  4083,  4086,  4090,  4097,  4098,  4101,  4102,
    4101,  4110,  4110,  4118,  4118,  4126,  4132,  4133,  4132,  4138,
    4138,  4144,  4151,  4154,  4161,  4162,  4165,  4171,  4171,  4177,
    4178,  4185,  4186,  4188,  4192,  4193,  4195,  4198,  4199,  4202,
    4202,  4208,  4208,  4214,  4214,  4220,  4220,  4226,  4226,  4232,
    4232,  4237,  4245,  4244,  4248,  4249,  4252,  4257,  4263,  4264,
    4267,  4268,  4270,  4272,  4274,  4276,  4280,  4281,  4284,  4287,
    4290,  4293,  4297,  4301,  4302,  4305,  4305,  4314,  4315,  4318,
    4319,  4322,  4321,  4334,  4334,  4337,  4339,  4341,  4343,  4346,
    4348,  4354,  4355,  4358,  4362,  4363,  4366,  4367,  4366,  4376,
    4377,  4379,  4379,  4383,  4384,  4387,  4398,  4407,  4417,  4419,
    4423,  4427,  4428,  4431,  4440,  4441,  4440,  4460,  4459,  4476,
    4477,  4480,  4506,  4528,  4529,  4532,  4541,  4541,  4560,  4581,
    4602,  4620,  4652,  4653,  4658,  4658,  4676,  4694,  4728,  4764,
    4765,  4768,  4774,  4773,  4799,  4801,  4805,  4809,  4810,  4813,
    4821,  4822,  4821,  4829,  4830,  4833,  4839,  4838,  4851,  4853,
    4857,  4861,  4862,  4865,  4872,  4873,  4872,  4882,  4883,  4882,
    4891,  4892,  4895,  4901,  4900,  4919,  4920,  4922,  4923,  4928,
    4947,  4957,  4958,  4960,  4961,  4966,  4986,  4996,  5006,  5009,
    5027,  5031,  5032,  5035,  5036,  5035,  5046,  5047,  5050,  5055,
    5057,  5055,  5064,  5064,  5070,  5070,  5076,  5076,  5082,  5085,
    5086,  5089,  5095,  5101,  5109,  5109,  5113,  5114,  5117,  5128,
    5137,  5148,  5150,  5167,  5171,  5172,  5176,  5175
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "QSTRING", "T_STRING",
  "SITE_PATTERN", "NUMBER", "K_HISTORY", "K_NAMESCASESENSITIVE",
  "K_DESIGN", "K_VIAS", "K_TECH", "K_UNITS", "K_ARRAY", "K_FLOORPLAN",
  "K_SITE", "K_CANPLACE", "K_CANNOTOCCUPY", "K_DIEAREA", "K_PINS",
  "K_DEFAULTCAP", "K_MINPINS", "K_WIRECAP", "K_TRACKS", "K_GCELLGRID",
  "K_DO", "K_BY", "K_STEP", "K_LAYER", "K_ROW", "K_RECT", "K_COMPS",
  "K_COMP_GEN", "K_SOURCE", "K_WEIGHT", "K_EEQMASTER", "K_FIXED",
  "K_COVER", "K_UNPLACED", "K_PLACED", "K_FOREIGN", "K_REGION",
  "K_REGIONS", "K_NETS", "K_START_NET", "K_MUSTJOIN", "K_ORIGINAL",
  "K_USE", "K_STYLE", "K_PATTERN", "K_PATTERNNAME", "K_ESTCAP", "K_ROUTED",
  "K_NEW", "K_SNETS", "K_SHAPE", "K_WIDTH", "K_VOLTAGE", "K_SPACING",
  "K_NONDEFAULTRULE", "K_NONDEFAULTRULES", "K_N", "K_S", "K_E", "K_W",
  "K_FN", "K_FE", "K_FS", "K_FW", "K_GROUPS", "K_GROUP", "K_SOFT",
  "K_MAXX", "K_MAXY", "K_MAXHALFPERIMETER", "K_CONSTRAINTS", "K_NET",
  "K_PATH", "K_SUM", "K_DIFF", "K_SCANCHAINS", "K_START", "K_FLOATING",
  "K_ORDERED", "K_STOP", "K_IN", "K_OUT", "K_RISEMIN", "K_RISEMAX",
  "K_FALLMIN", "K_FALLMAX", "K_WIREDLOGIC", "K_MAXDIST", "K_ASSERTIONS",
  "K_DISTANCE", "K_MICRONS", "K_END", "K_IOTIMINGS", "K_RISE", "K_FALL",
  "K_VARIABLE", "K_SLEWRATE", "K_CAPACITANCE", "K_DRIVECELL", "K_FROMPIN",
  "K_TOPIN", "K_PARALLEL", "K_TIMINGDISABLES", "K_THRUPIN", "K_MACRO",
  "K_PARTITIONS", "K_TURNOFF", "K_FROMCLOCKPIN", "K_FROMCOMPPIN",
  "K_FROMIOPIN", "K_TOCLOCKPIN", "K_TOCOMPPIN", "K_TOIOPIN", "K_SETUPRISE",
  "K_SETUPFALL", "K_HOLDRISE", "K_HOLDFALL", "K_VPIN", "K_SUBNET",
  "K_XTALK", "K_PIN", "K_SYNTHESIZED", "K_DEFINE", "K_DEFINES",
  "K_DEFINEB", "K_IF", "K_THEN", "K_ELSE", "K_FALSE", "K_TRUE", "K_EQ",
  "K_NE", "K_LE", "K_LT", "K_GE", "K_GT", "K_OR", "K_AND", "K_NOT",
  "K_SPECIAL", "K_DIRECTION", "K_RANGE", "K_FPC", "K_HORIZONTAL",
  "K_VERTICAL", "K_ALIGN", "K_MIN", "K_MAX", "K_EQUAL", "K_BOTTOMLEFT",
  "K_TOPRIGHT", "K_ROWS", "K_TAPER", "K_TAPERRULE", "K_VERSION",
  "K_DIVIDERCHAR", "K_BUSBITCHARS", "K_PROPERTYDEFINITIONS", "K_STRING",
  "K_REAL", "K_INTEGER", "K_PROPERTY", "K_BEGINEXT", "K_ENDEXT",
  "K_NAMEMAPSTRING", "K_ON", "K_OFF", "K_X", "K_Y", "K_COMPONENT",
  "K_MASK", "K_MASKSHIFT", "K_COMPSMASKSHIFT", "K_SAMEMASK",
  "K_PINPROPERTIES", "K_TEST", "K_COMMONSCANPINS", "K_SNET",
  "K_COMPONENTPIN", "K_REENTRANTPATHS", "K_SHIELD", "K_SHIELDNET",
  "K_NOSHIELD", "K_VIRTUAL", "K_ANTENNAPINPARTIALMETALAREA",
  "K_ANTENNAPINPARTIALMETALSIDEAREA", "K_ANTENNAPINGATEAREA",
  "K_ANTENNAPINDIFFAREA", "K_ANTENNAPINMAXAREACAR",
  "K_ANTENNAPINMAXSIDEAREACAR", "K_ANTENNAPINPARTIALCUTAREA",
  "K_ANTENNAPINMAXCUTCAR", "K_SIGNAL", "K_POWER", "K_GROUND", "K_CLOCK",
  "K_TIEOFF", "K_ANALOG", "K_SCAN", "K_RESET", "K_RING", "K_STRIPE",
  "K_FOLLOWPIN", "K_IOWIRE", "K_COREWIRE", "K_BLOCKWIRE", "K_FILLWIRE",
  "K_BLOCKAGEWIRE", "K_PADRING", "K_BLOCKRING", "K_BLOCKAGES",
  "K_PLACEMENT", "K_SLOTS", "K_FILLS", "K_PUSHDOWN", "K_NETLIST", "K_DIST",
  "K_USER", "K_TIMING", "K_BALANCED", "K_STEINER", "K_TRUNK",
  "K_FIXEDBUMP", "K_FENCE", "K_FREQUENCY", "K_GUIDE", "K_MAXBITS",
  "K_PARTITION", "K_TYPE", "K_ANTENNAMODEL", "K_DRCFILL", "K_OXIDE1",
  "K_OXIDE2", "K_OXIDE3", "K_OXIDE4", "K_CUTSIZE", "K_CUTSPACING",
  "K_DESIGNRULEWIDTH", "K_DIAGWIDTH", "K_ENCLOSURE", "K_HALO",
  "K_GROUNDSENSITIVITY", "K_HARDSPACING", "K_LAYERS", "K_MINCUTS",
  "K_NETEXPR", "K_OFFSET", "K_ORIGIN", "K_ROWCOL", "K_STYLES", "K_POLYGON",
  "K_PORT", "K_SUPPLYSENSITIVITY", "K_VIA", "K_VIARULE", "K_WIREEXT",
  "K_EXCEPTPGNET", "K_FILLWIREOPC", "K_OPC", "K_PARTIAL", "K_ROUTEHALO",
  "';'", "'-'", "'+'", "'('", "')'", "'*'", "','", "$accept", "def_file",
  "version_stmt", "$@1", "case_sens_stmt", "rules", "rule",
  "design_section", "design_name", "$@2", "end_design", "tech_name", "$@3",
  "array_name", "$@4", "floorplan_name", "$@5", "history",
  "prop_def_section", "$@6", "property_defs", "property_def", "$@7", "$@8",
  "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15",
  "property_type_and_val", "$@16", "$@17", "opt_num_val", "units",
  "divider_char", "bus_bit_chars", "canplace", "$@18", "cannotoccupy",
  "$@19", "orient", "die_area", "$@20", "pin_cap_rule", "start_def_cap",
  "pin_caps", "pin_cap", "end_def_cap", "pin_rule", "start_pins", "pins",
  "pin", "$@21", "$@22", "$@23", "pin_options", "pin_option", "$@24",
  "$@25", "$@26", "$@27", "$@28", "$@29", "$@30", "$@31", "$@32", "$@33",
  "pin_layer_mask_opt", "pin_via_mask_opt", "pin_poly_mask_opt",
  "pin_layer_spacing_opt", "pin_poly_spacing_opt", "pin_oxide", "use_type",
  "pin_layer_opt", "$@34", "end_pins", "row_rule", "$@35", "$@36",
  "row_do_option", "row_step_option", "row_options", "row_option", "$@37",
  "row_prop_list", "row_prop", "tracks_rule", "$@38", "track_start",
  "track_type", "track_opts", "track_mask_statement", "same_mask",
  "track_layer_statement", "$@39", "track_layers", "track_layer",
  "gcellgrid", "extension_section", "extension_stmt", "via_section", "via",
  "via_declarations", "via_declaration", "$@40", "$@41", "layer_stmts",
  "layer_stmt", "$@42", "$@43", "$@44", "$@45", "$@46", "$@47",
  "layer_viarule_opts", "$@48", "firstPt", "nextPt", "otherPts", "pt",
  "mask", "via_end", "regions_section", "regions_start", "regions_stmts",
  "regions_stmt", "$@49", "$@50", "rect_list", "region_options",
  "region_option", "$@51", "region_prop_list", "region_prop",
  "region_type", "comps_maskShift_section", "comps_section", "start_comps",
  "layer_statement", "maskLayer", "comps_rule", "comp", "comp_start",
  "comp_id_and_name", "$@52", "comp_net_list", "comp_options",
  "comp_option", "comp_extension_stmt", "comp_eeq", "$@53",
  "comp_generate", "$@54", "opt_pattern", "comp_source", "source_type",
  "comp_region", "comp_pnt_list", "comp_halo", "$@55", "halo_soft",
  "comp_routehalo", "$@56", "comp_property", "$@57", "comp_prop_list",
  "comp_prop", "comp_region_start", "comp_foreign", "$@58", "opt_paren",
  "comp_type", "maskShift", "$@59", "placement_status", "weight",
  "end_comps", "nets_section", "start_nets", "net_rules", "one_net",
  "net_and_connections", "net_start", "$@60", "net_name", "$@61", "$@62",
  "net_connections", "net_connection", "$@63", "$@64", "$@65", "conn_opt",
  "net_options", "net_option", "$@66", "$@67", "$@68", "$@69", "$@70",
  "$@71", "$@72", "$@73", "$@74", "$@75", "$@76", "net_prop_list",
  "net_prop", "netsource_type", "vpin_stmt", "$@77", "vpin_begin", "$@78",
  "vpin_layer_opt", "$@79", "vpin_options", "vpin_status", "net_type",
  "paths", "new_path", "$@80", "path", "$@81", "$@82", "virtual_statement",
  "rect_statement", "path_item_list", "path_item", "$@83", "$@84",
  "path_pt", "virtual_pt", "rect_pts", "opt_taper_style_s",
  "opt_taper_style", "opt_taper", "$@85", "opt_style", "opt_spaths",
  "opt_shape_style", "end_nets", "shape_type", "snets_section",
  "snet_rules", "snet_rule", "snet_options", "snet_option",
  "snet_other_option", "$@86", "$@87", "$@88", "$@89", "$@90", "$@91",
  "$@92", "$@93", "$@94", "$@95", "orient_pt", "shield_layer", "$@96",
  "snet_width", "$@97", "snet_voltage", "$@98", "snet_spacing", "$@99",
  "$@100", "snet_prop_list", "snet_prop", "opt_snet_range", "opt_range",
  "pattern_type", "spaths", "snew_path", "$@101", "spath", "$@102",
  "$@103", "width", "start_snets", "end_snets", "groups_section",
  "groups_start", "group_rules", "group_rule", "start_group", "$@104",
  "group_members", "group_member", "group_options", "group_option",
  "$@105", "$@106", "group_region", "group_prop_list", "group_prop",
  "group_soft_options", "group_soft_option", "groups_end",
  "assertions_section", "constraint_section", "assertions_start",
  "constraints_start", "constraint_rules", "constraint_rule",
  "operand_rule", "operand", "$@107", "$@108", "operand_list",
  "wiredlogic_rule", "$@109", "opt_plus", "delay_specs", "delay_spec",
  "constraints_end", "assertions_end", "scanchains_section",
  "scanchain_start", "scanchain_rules", "scan_rule", "start_scan", "$@110",
  "scan_members", "opt_pin", "scan_member", "$@111", "$@112", "$@113",
  "$@114", "$@115", "$@116", "opt_common_pins", "floating_inst_list",
  "one_floating_inst", "$@117", "floating_pins", "ordered_inst_list",
  "one_ordered_inst", "$@118", "ordered_pins", "partition_maxbits",
  "scanchain_end", "iotiming_section", "iotiming_start", "iotiming_rules",
  "iotiming_rule", "start_iotiming", "$@119", "iotiming_members",
  "iotiming_member", "$@120", "$@121", "iotiming_drivecell_opt", "$@122",
  "$@123", "iotiming_frompin", "$@124", "iotiming_parallel", "risefall",
  "iotiming_end", "floorplan_contraints_section", "fp_start", "fp_stmts",
  "fp_stmt", "$@125", "$@126", "h_or_v", "constraint_type",
  "constrain_what_list", "constrain_what", "$@127", "$@128",
  "row_or_comp_list", "row_or_comp", "$@129", "$@130",
  "timingdisables_section", "timingdisables_start", "timingdisables_rules",
  "timingdisables_rule", "$@131", "$@132", "$@133", "$@134",
  "td_macro_option", "$@135", "$@136", "$@137", "timingdisables_end",
  "partitions_section", "partitions_start", "partition_rules",
  "partition_rule", "start_partition", "$@138", "turnoff", "turnoff_setup",
  "turnoff_hold", "partition_members", "partition_member", "$@139",
  "$@140", "$@141", "$@142", "$@143", "$@144", "minmaxpins", "$@145",
  "min_or_max_list", "min_or_max_member", "pin_list",
  "risefallminmax1_list", "risefallminmax1", "risefallminmax2_list",
  "risefallminmax2", "partitions_end", "comp_names", "comp_name", "$@146",
  "subnet_opt_syn", "subnet_options", "subnet_option", "$@147", "$@148",
  "subnet_type", "pin_props_section", "begin_pin_props", "opt_semi",
  "end_pin_props", "pin_prop_list", "pin_prop_terminal", "$@149", "$@150",
  "pin_prop_options", "pin_prop", "$@151", "pin_prop_name_value_list",
  "pin_prop_name_value", "blockage_section", "blockage_start",
  "blockage_end", "blockage_defs", "blockage_def", "blockage_rule",
  "$@152", "$@153", "$@154", "layer_blockage_rules", "layer_blockage_rule",
  "mask_blockage_rule", "comp_blockage_rule", "$@155",
  "placement_comp_rules", "placement_comp_rule", "$@156",
  "rectPoly_blockage_rules", "rectPoly_blockage", "$@157", "slot_section",
  "slot_start", "slot_end", "slot_defs", "slot_def", "slot_rule", "$@158",
  "$@159", "geom_slot_rules", "geom_slot", "$@160", "fill_section",
  "fill_start", "fill_end", "fill_defs", "fill_def", "$@161", "$@162",
  "fill_rule", "$@163", "$@164", "geom_fill_rules", "geom_fill", "$@165",
  "fill_layer_mask_opc_opt", "opt_mask_opc_l", "fill_layer_opc",
  "fill_via_pt", "fill_via_mask_opc_opt", "opt_mask_opc", "fill_via_opc",
  "fill_mask", "fill_viaMask", "nondefaultrule_section",
  "nondefault_start", "nondefault_end", "nondefault_defs",
  "nondefault_def", "$@166", "$@167", "nondefault_options",
  "nondefault_option", "$@168", "$@169", "$@170", "$@171", "$@172",
  "nondefault_layer_options", "nondefault_layer_option",
  "nondefault_prop_opt", "$@173", "nondefault_prop_list",
  "nondefault_prop", "styles_section", "styles_start", "styles_end",
  "styles_rules", "styles_rule", "$@174", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-1119)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-544)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -94, -1119,   102,   119,   207, -1119,    77,   489,  -104,   -49,
     -37, -1119,   666, -1119, -1119, -1119, -1119, -1119,   227, -1119,
     161, -1119, -1119, -1119, -1119, -1119,   256,   310,   148,   148,
   -1119,   327,   337,   359,   379,   401,   451,   461,   498,   510,
     366,   529,   530,   545,   547,   551,   552, -1119, -1119, -1119,
     550,   554,   555,   559,   560, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119,   564, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119,   290, -1119, -1119,   568,   307,
     570,   480,   572,   573,   574,   576,   312,   317, -1119, -1119,
   -1119, -1119,   578,   583,   322,   324,   325,   326,   328,   329,
     332,   344,   345, -1119,   346,   347,   348,   349,   350,   360,
   -1119,    26,   361,   362,   363,   365,   367,    74,   -29, -1119,
     -13,    -9,    -8,    -2,     4,    41,    43,    47,    50,    51,
      55,    58,    59,    60,    61,    62,    63, -1119, -1119,    64,
     368, -1119,   371,   587,   372,   374,   635,   636,    11,   312,
   -1119, -1119,   618,   642, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,   385,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,   641,
     628, -1119, -1119,   633, -1119, -1119, -1119,   629,   643, -1119,
   -1119, -1119,   613, -1119, -1119,   638, -1119, -1119, -1119, -1119,
   -1119,   624, -1119, -1119, -1119, -1119, -1119,   616, -1119, -1119,
   -1119,   602, -1119, -1119, -1119, -1119,   579,    57, -1119, -1119,
   -1119, -1119,   599, -1119,   601, -1119, -1119, -1119, -1119,   590,
     419, -1119, -1119, -1119,   544, -1119, -1119,   585,   -18, -1119,
   -1119,   584, -1119, -1119, -1119, -1119,   514, -1119, -1119, -1119,
     485,    35, -1119, -1119,    34,   486,   677, -1119, -1119, -1119,
     492,    44, -1119, -1119, -1119,   711,    65,   464,   671, -1119,
   -1119, -1119, -1119,   455, -1119, -1119,   716,   717,    12,    13,
   -1119, -1119,   719,   721,   462, -1119, -1119, -1119, -1119, -1119,
   -1119,   567, -1119, -1119, -1119, -1119,   708, -1119, -1119,   727,
     726, -1119,   730, -1119,   732, -1119,   733,  -186,     9, -1119,
      97,   -95, -1119,   -76, -1119,   735,   736, -1119, -1119, -1119,
     473,   475, -1119, -1119, -1119, -1119,   741,   -58, -1119, -1119,
     -44, -1119,   743, -1119, -1119, -1119, -1119,   482, -1119,   745,
     -23, -1119,   746, -1119, -1119, -1119,   312, -1119, -1119, -1119,
   -1119,   -14, -1119, -1119, -1119,     2, -1119,   691, -1119, -1119,
   -1119,   747, -1119,   274,   274,   484,   487,   488,   490,  -141,
     725,   749, -1119,   752,   760,   763,   764,   766,   767, -1119,
     768,   770,   771,   772,   509,   753, -1119, -1119,   777, -1119,
      21, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119,    16, -1119, -1119, -1119,   312, -1119, -1119, -1119, -1119,
     513, -1119, -1119,   665, -1119, -1119, -1119,   755, -1119,   179,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,   116,
     780,   781,   198,   198,   782,   229, -1119, -1119,    24, -1119,
   -1119,   786, -1119,    79, -1119, -1119,   223,   787,   788,   789,
   -1119,   683, -1119,     1, -1119, -1119,   791,   792, -1119,   312,
     312,    15,   793,   312, -1119, -1119, -1119,   794,   795,   312,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119,   775,   776, -1119, -1119, -1119, -1119,
   -1119, -1119,   796,   274,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   537,   728,   799, -1119,   312, -1119, -1119,
     158,   800, -1119, -1119, -1119,   312, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119,   801, -1119,   312,   312,   274, -1119,   804,
    -101,   803, -1119, -1119, -1119,   285,   805,   -50,   806, -1119,
   -1119, -1119, -1119,   808, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119,   312, -1119,   158,   809, -1119,   285,   810,   -50,   811,
     395, -1119, -1119, -1119, -1119,   812, -1119, -1119,   813, -1119,
   -1119,   816, -1119,    52, -1119, -1119, -1119,   817, -1119,   -28,
      -3,   542, -1119,   300, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119,   818, -1119, -1119,   819, -1119,    83, -1119, -1119, -1119,
     820,   826,    85,   281, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119,   566, -1119,   312, -1119, -1119, -1119,   312,
     312, -1119, -1119,   312,   312,   253,   312,   829,   830,   571,
   -1119,   836, -1119, -1119,   837,   580,   581,   582,   588,   589,
     591,   592,   593,   594, -1119, -1119,   648,   260,   312,   312,
     838, -1119, -1119, -1119, -1119, -1119, -1119,   840,   274,   845,
     846,   849,   769, -1119, -1119,   312, -1119,   595, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119,   852, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119,   857,   858,   859, -1119,   861,   862, -1119,
     863,   864,   866,   312,   867, -1119, -1119,   868, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119,   869,   870,   871,   872, -1119,
     873, -1119,   875,   876,   878, -1119, -1119, -1119,   881, -1119,
     198, -1119, -1119, -1119,   797,   880,   882,   884,   885,   889,
   -1119, -1119,   892,   630,   893,   631, -1119,   894,   896,   897,
     245,   802,   634, -1119, -1119,   639, -1119, -1119,   272,   900,
     902,   904,   906,   907,   908, -1119, -1119,   -25, -1119,   312,
      48, -1119,   312, -1119, -1119, -1119,   312, -1119,    14, -1119,
   -1119,   312,   887,   888, -1119,   890, -1119,   773,   773, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,   912,
     911,   652,   895, -1119,    54, -1119, -1119, -1119, -1119,   312,
     261,   917, -1119, -1119,    32,    93,   846, -1119, -1119, -1119,
     916,   920, -1119,     7, -1119,   921, -1119, -1119, -1119, -1119,
     106,   861, -1119, -1119,   864, -1119, -1119,   874, -1119, -1119,
   -1119,   312, -1119,   922, -1119,   923,   412,   872, -1119, -1119,
   -1119,   557, -1119,   877, -1119,    18,   369, -1119,   927, -1119,
     926, -1119, -1119, -1119, -1119,   929,   930,   931,   929,   932,
   -1119,   695, -1119, -1119,   933,   934, -1119,   935,   936,   937,
   -1119, -1119, -1119,   940,   941, -1119, -1119, -1119, -1119,   942,
     943, -1119,   944,   945, -1119,   273,   669, -1119, -1119, -1119,
     946, -1119, -1119,   312,   -15,   143,   312, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119,   947,   949,   950, -1119,   951,   952,
     952, -1119,   783, -1119, -1119, -1119, -1119, -1119, -1119,   953,
     954,   956, -1119, -1119, -1119, -1119,  -122, -1119, -1119, -1119,
     957, -1119,   274, -1119, -1119, -1119, -1119,   958,   961, -1119,
   -1119, -1119,   668, -1119, -1119, -1119, -1119, -1119,   874, -1119,
   -1119, -1119,   399,   312, -1119, -1119, -1119, -1119, -1119, -1119,
     962,   312, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119,   963, -1119, -1119, -1119,   312, -1119,   964,   965,   966,
   -1119,   969, -1119,   684, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119,   970,   971, -1119,   847, -1119, -1119, -1119, -1119, -1119,
     276,   972,   879, -1119,   321,   315,   390,   321,   315,   390,
   -1119,   814, -1119,   149, -1119, -1119, -1119,   974, -1119,   312,
   -1119,  -123, -1119, -1119, -1119, -1119,   -98, -1119,   702, -1119,
   -1119, -1119, -1119,   975, -1119,   977,   978,   979,  -125,   948,
     959,   967,   279,   981, -1119, -1119, -1119, -1119, -1119, -1119,
     984,   985,   986,   987,   988,   989,   990,   993,   994, -1119,
     318, -1119, -1119,   995, -1119,   996,   998,   999, -1119,   723,
      -5,   864, -1119, -1119, -1119, -1119,   312, -1119,   839, -1119,
     878,   312,   312, -1119, -1119,   878, -1119, -1119, -1119, -1119,
     450, -1119, -1119,   737,   738,   729, -1119, -1119, -1119,   899,
   -1119,   277, -1119,  1001, -1119, -1119,  1002,  1003,  1005,  1006,
     315, -1119,  1007,  1008,  1009,  1011, -1119, -1119,   315, -1119,
    1012, -1119,  1013, -1119, -1119, -1119,  1014, -1119, -1119,   312,
    1015, -1119,  1016, -1119,   312, -1119,   312,   968,  1019,  1020,
   -1119, -1119, -1119,  1021,  1022,  1023, -1119,   865, -1119, -1119,
     284, -1119,   984,   757, -1119, -1119,  1024, -1119, -1119,   757,
     765, -1119, -1119, -1119, -1119,  1026,   774,   774,   774, -1119,
   -1119, -1119,  1028, -1119, -1119,    17, -1119, -1119, -1119, -1119,
   -1119,   274,  1029, -1119,   877,   312, -1119,   159, -1119, -1119,
   -1119, -1119,  1032, -1119,  1033, -1119,   778,  1034, -1119, -1119,
   -1119,   779,  1035, -1119,    49,  1037,  1038,  1040,  1042, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119,  1036, -1119, -1119,
   -1119, -1119,  1043,   456, -1119, -1119,  1044,  1045,  1025, -1119,
   -1119,   167, -1119, -1119,   312, -1119,   984,   886,   312,  1047,
   -1119,   822,  1050, -1119,     5, -1119,   790,   798,   807,  1052,
      33, -1119,  1053,    19,    20, -1119, -1119,  1057, -1119,   312,
     131, -1119, -1119,  1055,  1060,  1061, -1119,  1062, -1119, -1119,
   -1119, -1119, -1119,  1063,  1064, -1119, -1119, -1119, -1119, -1119,
    1067, -1119, -1119, -1119, -1119, -1119,   815,   821,  1066, -1119,
   -1119, -1119,   285, -1119,  1069,  1068,  1070,  1072,  1073,  1074,
    1076,  1077,  1078,   255, -1119,  1082, -1119, -1119, -1119, -1119,
     274, -1119,  1080,   312, -1119,   312,  1083,   460, -1119, -1119,
   -1119, -1119, -1119,  1071, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119,    27,    28,    29,    30,    10, -1119,   312,  1084,
     395, -1119,   823,   824,  1087, -1119,   828,   828, -1119,  1086,
    1089,   511, -1119, -1119, -1119, -1119,  1092,  1095,  1096, -1119,
   -1119,  1039,  1039,  1039,  1039,  1075,  1079,  1039,  1081, -1119,
   -1119, -1119, -1119, -1119,  1097, -1119,  1098,  1100,  1101, -1119,
   -1119, -1119,   312,  1102, -1119, -1119, -1119,   842,  1107,   864,
     843, -1119,   844, -1119,   848, -1119,   850, -1119,   384,   853,
    1106,   854, -1119, -1119, -1119, -1119, -1119, -1119,    10,   855,
     856,   851,   982,    40, -1119,  1111, -1119, -1119, -1119, -1119,
   -1119,   -11, -1119,   519, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,   955,   312,
     860,   915,   883, -1119,   874, -1119, -1119, -1119, -1119,  1110,
    1094,  1120, -1119,    94,    22, -1119,  1113,  1123, -1119,  1125,
   -1119, -1119, -1119, -1119,  1126,  1127,  1128, -1119, -1119, -1119,
   -1119,   960,  1132,  1133,  1134,  1135,   973,  1136,   891, -1119,
     898, -1119, -1119,  1103,  1138,  1139,   408, -1119,   901,    23,
      25,  1137,  1143, -1119,  1145,  1146, -1119, -1119, -1119,  1148,
     -19, -1119, -1119, -1119, -1119,  1149,     8, -1119,  1150,   312,
   -1119,  1151,  1114,  1152,  1153,  1140,   905, -1119,   903,   909,
     910,   913,   914,   918,   919,   924, -1119,  1155,  1156,   312,
   -1119,  1157,  1158,   312,  1160,  1147,  1142,  1161,  1165,  1159,
    1169,  1170, -1119, -1119, -1119, -1119,   928,   938, -1119, -1119,
   -1119, -1119,   312, -1119, -1119,   312,   925,  1173,  1172,  1154,
     939,  1176,  1164,  1180,  1183,  1187, -1119,   312, -1119,  1188,
    1190,  1192, -1119,  1166,  1193,  1194,  1197,  1198, -1119,   976,
   -1119,  1199,  1200,  1177,  1202,   980,   983,   312,   991, -1119,
    1204,  1205,   992, -1119, -1119,  1206, -1119,  1207, -1119,  1208,
   -1119,   997,  1004,  1209,  1210,  1211,  1212, -1119
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       3,     4,     0,     6,     0,     1,     0,     0,     0,     0,
       0,    11,     0,     5,     7,     8,    60,    51,     0,    54,
       0,    56,    58,    96,    98,   108,     0,     0,     0,     0,
     185,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,   218,   281,
       0,     0,     0,     0,     0,    10,    12,    38,     2,    48,
      34,    41,    43,    46,    50,    40,    35,    36,    37,    39,
      44,   112,    45,   118,    47,    49,     0,    42,    17,    33,
     222,    27,   259,    19,    15,   284,    23,   353,    30,   495,
      21,   577,    13,    16,   610,   610,    28,   638,    22,   684,
      20,   711,    32,   736,    25,   754,    26,   824,    14,   841,
      29,   877,    18,   891,    24,     0,    31,   954,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,   204,
     205,   203,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
      63,     0,   821,     0,     0,     0,     0,     0,     0,   201,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   923,   921,     0,
       0,   221,     0,     0,     0,     0,     0,     0,     0,     0,
     246,   117,     0,     0,   280,   258,   352,   573,   919,   576,
     609,   637,   608,   683,   735,   753,   710,    94,    95,     0,
     283,   278,   282,   822,   820,   839,   875,   889,   952,     0,
       0,   113,   110,     0,   120,   119,   116,     0,     0,   224,
     223,   220,     0,   261,   260,     0,   288,   285,   293,   290,
     279,     0,   357,   354,   374,   356,   351,     0,   498,   496,
     494,     0,   580,   578,   582,   575,     0,     0,   611,   612,
     613,   606,     0,   607,     0,   641,   639,   643,   636,     0,
       0,   685,   689,   682,     0,   713,   712,     0,     0,   737,
     734,     0,   757,   755,   767,   752,     0,   826,   819,   825,
       0,     0,   838,   842,     0,     0,     0,   874,   878,   883,
       0,     0,   888,   892,   900,     0,     0,     0,     0,   951,
     955,    52,    55,     0,    57,    59,     0,     0,     0,     0,
     248,   247,     0,     0,     0,    65,    77,    71,    81,    73,
      67,     0,    75,    69,    79,    64,     0,   115,   184,     0,
       0,   256,     0,   257,     0,   350,     0,     0,   287,   481,
       0,     0,   574,     0,   605,     0,   585,   635,   615,   617,
       0,     0,   624,   628,   634,   681,     0,     0,   708,   687,
       0,   709,     0,   751,   738,   741,   743,     0,   802,     0,
       0,   823,     0,   840,   844,   847,     0,   872,   869,   876,
     880,     0,   890,   897,   894,     0,   924,     0,   918,   922,
     953,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,    62,
       0,     0,     0,     0,     0,     0,   225,   262,     0,   286,
       0,   307,   294,   306,   302,   295,   296,   301,   303,   304,
     305,     0,   300,   297,   299,     0,   298,   292,   291,   359,
       0,   358,   355,     0,   404,   375,   392,   419,   497,     0,
     532,   499,   503,   500,   501,   502,   581,   584,   583,     0,
       0,     0,     0,     0,     0,     0,   642,   640,     0,   659,
     644,     0,   686,     0,   697,   690,     0,     0,     0,     0,
     745,   759,   756,     0,   781,   768,     0,     0,   862,     0,
       0,     0,     0,     0,   886,   879,   884,     0,     0,     0,
     903,   893,   901,   926,   920,   956,   100,   102,   103,   101,
     104,   107,   106,   105,     0,     0,   250,   252,   251,   253,
     109,   249,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,     0,   289,   310,
       0,     0,   308,   346,   347,   342,   348,   337,   336,   329,
     219,   344,   323,     0,   320,     0,   319,     0,   363,     0,
       0,     0,   427,   428,   382,     0,     0,     0,     0,   429,
     390,   417,   398,     0,   402,   393,   395,   379,   380,   376,
     420,     0,   515,     0,     0,   523,     0,     0,     0,     0,
       0,   545,   547,   549,   530,     0,   507,   521,     0,   512,
     517,   504,   579,     0,   592,   586,   616,     0,   621,     0,
       0,   626,   614,     0,   629,   647,   649,   651,   653,   655,
     657,     0,   706,   707,     0,   694,     0,   716,   717,   714,
       0,     0,     0,   761,   758,   769,   771,   773,   775,   777,
     779,   827,   845,   848,   871,     0,   843,   870,   881,     0,
       0,   898,   895,     0,     0,     0,     0,     0,     0,     0,
     186,    88,    86,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   121,   207,     0,     0,   266,
       0,   315,   316,   317,   318,   314,   349,     0,     0,     0,
       0,     0,   325,   327,   321,     0,   341,   360,   361,   414,
     410,   411,   412,   413,   378,   385,     0,   173,   174,   175,
     176,   177,   178,   179,   180,   388,   389,   564,   561,   562,
     563,   384,   387,     0,     0,     0,   386,     0,     0,   396,
       0,     0,     0,     0,     0,   520,   526,     0,   528,   529,
     525,   527,   482,   483,   484,   485,   486,   487,   488,   491,
     492,   493,   490,   489,   510,     0,     0,     0,     0,   511,
       0,   522,     0,     0,     0,   590,   600,   588,     0,   619,
       0,   622,   620,   627,     0,     0,     0,     0,     0,     0,
     663,   671,     0,   660,     0,     0,   693,     0,     0,     0,
       0,     0,     0,   746,   749,     0,   762,   763,   764,     0,
       0,     0,     0,     0,     0,   829,   849,     0,   863,     0,
       0,   885,     0,   905,   911,   902,     0,   925,     0,   927,
     938,     0,     0,     0,   217,   188,    89,   559,   559,    90,
      66,    78,    72,    82,    74,    68,    76,    70,    80,     0,
       0,     0,   211,   226,     0,   240,   228,   239,   264,     0,
       0,   312,   309,   343,     0,     0,   330,   331,   345,   326,
       0,     0,   322,     0,   364,     0,   383,   391,   418,   399,
       0,   403,   405,   394,     0,   381,   434,   377,   430,   421,
     415,     0,   524,     0,   548,     0,     0,   531,   552,   508,
     513,   533,   569,   506,   565,     0,   587,   595,     0,   623,
       0,   630,   631,   632,   633,   645,   650,   652,   645,     0,
     656,   679,   688,   695,     0,     0,   718,     0,     0,     0,
     722,   739,   742,     0,     0,   744,   765,   766,   760,     0,
       0,   790,     0,     0,   790,     0,   846,   867,   864,   866,
       0,   248,   882,     0,     0,     0,     0,   929,   944,   928,
     936,   932,   934,   248,     0,     0,     0,   192,     0,    91,
      91,   122,   209,   202,   212,   206,   229,   244,   234,     0,
       0,     0,   231,   236,   265,   263,     0,   267,   313,   311,
       0,   339,     0,   334,   335,   333,   332,     0,     0,   365,
     369,   367,     0,   803,   408,   409,   407,   406,   397,   469,
     432,   431,   422,     0,   546,   550,   555,   556,   554,   553,
     542,     0,   534,   536,   537,   535,   538,   541,   540,   539,
     518,     0,   567,   566,   594,     0,   591,     0,     0,     0,
     601,   589,   618,     0,   646,   648,   665,   664,   673,   672,
     654,     0,     0,   658,   701,   691,   692,   720,   719,   721,
       0,     0,     0,   750,     0,     0,   774,     0,     0,   780,
     828,     0,   830,     0,   850,   853,   854,     0,   868,   873,
     248,     0,   899,   906,   907,   908,     0,   248,     0,   912,
     913,   914,   248,     0,   946,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,    87,    85,   124,   210,   208,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
       0,   340,   338,     0,   328,     0,     0,     0,   362,   400,
       0,     0,   425,   426,   424,   416,     0,   516,   557,   509,
       0,     0,     0,   572,   477,     0,   593,   602,   603,   604,
       0,   596,   625,   667,   675,     0,   680,   702,   696,     0,
     715,     0,   723,     0,   747,   784,     0,     0,     0,     0,
     772,   796,     0,     0,     0,     0,   791,   784,   778,   831,
       0,   856,     0,   858,   859,   860,     0,   861,   865,   887,
       0,   909,     0,   915,   910,   896,   904,     0,   945,     0,
     933,   935,   957,     0,     0,     0,   187,     0,   193,   560,
       0,   216,   214,   254,   245,   235,     0,   242,   241,   254,
       0,   271,   276,   277,   270,     0,   371,   371,   371,   805,
     809,   804,     0,   473,   474,     0,   435,   470,   472,   471,
     433,     0,     0,   551,   544,     0,   248,     0,   568,   598,
     599,   597,     0,   666,     0,   674,   661,     0,   698,   724,
     726,     0,     0,   770,     0,     0,     0,     0,     0,   797,
     792,   794,   793,   795,   776,   833,   851,     0,   855,   852,
     916,   917,     0,     0,   947,   937,     0,     0,   190,   194,
     123,     0,   125,   127,     0,   213,   214,     0,     0,     0,
     232,     0,   269,   324,     0,   372,     0,     0,     0,     0,
     401,   476,     0,     0,     0,   439,   423,     0,   248,   519,
       0,   570,   478,     0,     0,     0,   703,     0,   728,   728,
     740,   748,   782,     0,     0,   785,   798,   800,   799,   801,
     832,   857,   930,   949,   950,   948,     0,     0,     0,   189,
     196,   136,     0,   126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,     0,   139,   135,   130,   142,
       0,   215,     0,     0,   243,     0,     0,     0,   272,   373,
     366,   370,   368,     0,   815,   816,   817,   813,   818,   810,
     811,   475,     0,     0,     0,     0,   436,   558,   514,     0,
       0,   439,     0,     0,     0,   699,   725,   727,   788,     0,
       0,     0,   834,   939,    97,    99,     0,   195,     0,   134,
     128,   181,   181,   181,   181,     0,     0,   181,     0,   169,
     170,   171,   172,   156,     0,   129,     0,     0,     0,   144,
     255,   230,     0,     0,   274,   275,   273,   807,     0,     0,
       0,   456,     0,   458,     0,   457,     0,   459,   441,     0,
       0,     0,   449,   450,   440,   455,   480,   479,   571,   668,
     676,     0,   704,     0,   729,   783,   786,   787,   836,   837,
     835,   931,   191,     0,   197,   137,   182,   145,   146,   147,
     148,   149,   151,   153,   154,   133,   140,   131,   159,     0,
       0,     0,     0,   814,   812,   460,   462,   461,   463,     0,
     443,     0,   438,   453,     0,   437,     0,     0,   662,     0,
     700,   732,   730,   789,     0,     0,     0,   940,   199,   200,
     198,   157,     0,     0,     0,     0,   161,     0,     0,   248,
       0,   808,   806,     0,     0,     0,   442,   451,     0,     0,
       0,     0,     0,   705,     0,     0,   942,   941,   943,     0,
     163,   183,   150,   152,   155,     0,   166,   160,     0,   233,
     237,     0,     0,     0,     0,   444,     0,   454,     0,     0,
       0,     0,     0,     0,     0,     0,   158,     0,     0,     0,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   464,   466,   465,   467,   669,   677,   733,   731,
     164,   165,     0,   167,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   138,     0,   143,     0,
       0,     0,   468,     0,     0,     0,     0,     0,   248,     0,
     446,     0,     0,     0,     0,     0,     0,   141,     0,   447,
       0,     0,     0,   670,   678,     0,   445,     0,   452,     0,
     448,     0,     0,     0,     0,     0,     0,   238
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119,   123, -1119, -1119,   136, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119,  -403, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119,  -591, -1072, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119,  1174, -1119, -1119, -1119, -1119, -1119,  -144,   109,
   -1119, -1119,  -343, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,  -497,
    -187,  -942,  -126,     3, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,   627, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,   355,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119,    31, -1119, -1119,
   -1119, -1119, -1119, -1119,  1059, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119,  -717, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
     343, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
     784,  -878, -1119, -1119,    95, -1119, -1119, -1119, -1119,  -176,
   -1119, -1119, -1119, -1118, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119,  -173, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119,   331, -1119,   391,   632,    91, -1119, -1119,    88,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119,  1141, -1119, -1119,
    -250, -1119, -1119,   761, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,   319, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119,  -865, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119,   -91, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119,    68, -1119, -1119, -1119, -1119,   291, -1119,   171, -1089,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119,   739, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119,   422, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119,   292, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
    1000, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119, -1119,
   -1119, -1119
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     4,     7,    12,    55,    56,    57,   118,
      58,    59,   120,    60,   122,    61,   123,    62,    63,   150,
     209,   335,   413,   418,   421,   415,   417,   420,   414,   422,
     416,   675,   838,   837,  1105,    64,    65,    66,    67,   124,
      68,   125,   524,    69,   126,    70,    71,   157,   221,   222,
      72,    73,   158,   225,   339,   849,  1107,  1210,  1292,  1437,
    1434,  1418,  1531,  1436,  1536,  1438,  1533,  1534,  1535,  1560,
    1538,  1566,  1589,  1593,  1433,   725,  1487,  1532,   226,    74,
     133,   835,   967,  1349,  1102,  1208,  1350,  1417,  1484,    75,
     227,    76,   131,   851,   852,  1109,   975,  1110,  1295,  1296,
      77,    78,  1305,    79,    80,   160,   230,   342,   546,   687,
     856,  1111,  1117,  1375,  1113,  1118,  1595,   857,  1112,   189,
     531,   409,   321,  1298,   231,    81,    82,   161,   234,   344,
     547,   689,   860,   987,  1221,  1302,  1378,  1224,    83,    84,
      85,   151,   212,   162,   237,   238,   239,   346,   348,   347,
     432,   433,   434,   697,   435,   690,   989,   436,   695,   437,
     566,   438,   702,   870,   439,   871,   440,   700,   866,   867,
     441,   442,   699,   992,   443,   444,   701,   445,   446,   240,
      86,    87,   163,   243,   244,   245,   350,   451,   568,   875,
     707,   874,  1125,  1127,  1126,  1306,   351,   455,   741,   740,
     716,   733,   738,   739,   884,   735,  1003,  1230,   737,   881,
     882,   714,   456,  1012,   457,   734,   591,   742,  1135,  1136,
     589,   887,  1011,  1131,   888,  1009,  1315,  1462,  1463,  1396,
    1464,  1576,  1548,  1465,  1515,  1512,  1130,  1237,  1238,  1312,
    1239,  1247,  1322,   246,   764,    88,   164,   249,   353,   461,
     462,   774,   770,  1020,   772,  1021,   744,   773,  1142,   747,
     768,  1030,  1139,  1140,   463,   765,   464,   766,   465,   767,
    1138,   897,   898,  1243,   969,   731,   903,  1033,  1145,   904,
    1031,  1401,  1144,    89,   250,    90,    91,   165,   253,   254,
     355,   356,   468,   469,   615,   907,   905,  1036,  1041,  1151,
     906,  1040,   255,    92,    93,    94,    95,   166,   258,   259,
     618,   470,   471,   619,   260,   474,   784,   475,   624,   263,
     261,    96,    97,   168,   266,   267,   366,   367,  1045,   480,
     789,   790,   791,   792,   793,   794,   920,   916,  1047,  1153,
    1253,   917,  1049,  1154,  1255,  1053,   268,    98,    99,   169,
     271,   272,   481,   370,   485,   797,  1054,  1158,  1327,  1472,
    1159,  1257,  1520,   636,   273,   100,   101,   170,   276,   372,
     800,   639,   930,  1060,  1162,  1328,  1329,  1406,  1474,  1555,
    1554,   102,   103,   171,   279,   487,  1061,   488,   489,   805,
     933,  1262,   934,   280,   104,   105,   172,   283,   284,   379,
     644,   808,   938,   380,   495,   809,   810,   811,   812,   813,
     814,  1263,  1408,  1264,  1335,  1475,  1066,  1176,  1170,  1171,
     285,  1129,  1231,  1309,  1502,  1310,  1389,  1449,  1448,  1390,
     106,   107,   214,   288,   173,   289,   382,   815,   945,  1072,
    1275,  1340,  1412,   108,   109,   292,   174,   293,   294,   497,
     816,   498,   946,  1074,  1075,  1076,  1277,   653,   818,  1077,
     501,   388,   500,   110,   111,   297,   175,   298,   299,   502,
     820,   391,   506,   660,   112,   113,   302,   176,   303,   508,
     824,   304,   507,   823,   395,   512,   664,   954,  1083,  1084,
    1088,   955,  1089,  1090,  1085,  1091,   114,   115,   398,   306,
     178,   305,   513,   665,   829,  1093,  1413,  1096,  1097,  1095,
    1481,  1527,   830,  1094,  1198,  1284,   116,   117,   309,   179,
     310,   666
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     190,   525,   320,   655,   431,   748,  1008,   363,   454,  1079,
     460,   999,  1236,   447,  1458,   509,   503,   318,   405,   407,
     564,  1098,  1034,  1313,   479,  1392,  1394,   484,  1549,  1578,
     210,  1580,   509,  1450,  1452,  1454,  1456,   494,   990,  1587,
    1459,   727,   957,  1232,  1119,   386,   947,  1524,   358,   359,
     360,   361,  1190,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   384,   386,     1,  1591,   223,  1332,  1384,
    1385,  1521,   393,   358,   359,   360,   361,  1192,   503,   709,
     429,  1269,   430,   228,   976,  1386,   374,   232,   235,  1269,
     375,   376,  1387,   775,   241,   219,   993,   994,  1546,   995,
     247,   449,     5,   977,   978,   625,   626,   627,   628,  1004,
    1005,  1120,  1006,   645,   646,   647,   648,   649,   650,   710,
     711,   712,   713,   776,  1547,   530,   614,     6,   188,  1321,
     670,  1379,  1000,   358,   359,   360,   361,   251,  1189,   256,
    1191,  1202,   450,   262,   188,  1194,   264,   269,   362,   948,
    1196,   274,  1233,  1234,   277,   281,   286,   290,   295,   300,
     307,   397,    13,   822,   706,  1193,   377,   826,   560,   831,
     220,   452,   560,   453,   728,   729,   730,   632,   633,  1399,
     958,   634,   635,   798,   799,  1460,  1400,   559,   560,   803,
     458,   560,   459,   804,   949,  1351,  1522,   561,  1461,  1165,
    1333,  1334,  1177,   553,   554,   629,   556,  1180,   477,   592,
     478,     8,   593,   594,  1352,   572,   573,    14,   777,   560,
    1388,   560,   482,  1588,   483,   595,   596,   597,   598,    15,
     599,   579,  1525,   119,   600,   601,   602,   603,   224,   950,
     510,   504,   779,   492,   780,   493,   560,     9,    10,  1526,
    1592,   385,   505,  1081,   229,   121,   630,   510,   233,   236,
     499,   959,   127,   960,  1235,   242,   562,   782,   511,   780,
     387,   242,   961,   962,   358,   359,   360,   361,  1001,  1235,
     448,   656,   319,   406,   408,   188,   563,   188,  1314,   387,
    1393,  1395,   211,  1550,  1579,   863,  1581,  1451,  1453,  1455,
    1457,   188,   394,   504,  1319,   979,   980,   981,   252,   982,
     257,  1353,  1354,   983,   257,   565,   128,   265,   270,   567,
     129,   130,   275,  1181,  1182,   278,   282,   287,   291,   296,
     301,   308,   177,   134,   560,   516,   517,   518,   519,   520,
     521,   522,   523,   135,   855,   604,   560,   671,   672,   673,
    1488,  1489,  1490,   674,   605,  1493,  1355,  1356,  1357,  1358,
    1359,  1360,  1361,  1362,   606,   136,  1183,  1184,  1185,   781,
     781,   637,   638,   654,   190,   143,  1398,   659,   691,   692,
     693,   694,   612,   663,   613,   137,   324,   785,   786,   787,
     788,  1186,   936,   937,   325,   926,   927,   928,   929,   806,
     807,  1363,  1166,  1167,  1168,  1169,   607,   138,   608,  1509,
    1187,  1086,   188,  1364,   326,  1016,  1017,  1365,  1018,   632,
     633,   688,  1366,  1367,  1368,  1369,   327,  1320,  1235,   698,
    1577,  1259,  1260,  1574,   609,  1132,  1133,   610,  1134,   704,
     705,  1037,  1038,  1039,   328,   516,   517,   518,   519,   520,
     521,   522,   523,  1249,  1250,   329,  1251,   139,  1087,  1343,
    1344,   330,  1345,  1444,  1445,   743,  1446,   140,   819,   516,
     517,   518,   519,   520,   521,   522,   523,  1172,  1173,  1174,
    1175,   331,   717,   718,   719,   720,   721,   722,   723,   724,
      11,  1429,  1430,  1431,  1432,   622,    -9,   623,    -9,    -9,
      -9,    -9,    -9,    -9,   141,    -9,    -9,    -9,    -9,    -9,
    1307,  1308,    -9,    -9,  1478,  1479,   142,  1480,    -9,   827,
      -9,   828,  1528,  1529,  1141,  1530,   853,   985,   854,   986,
     909,    -9,    -9,   821,   190,   144,   145,   825,   190,  1070,
     190,  1071,  1160,    -9,  1161,  1206,  1222,  1207,  1223,    -9,
    1290,   146,  1291,   147,   148,   149,   152,   177,    -9,   332,
     153,   154,   858,   859,    -9,   155,   156,   333,   334,    -9,
     159,  1504,   180,   181,   182,   183,   184,   185,   186,   872,
     187,   188,    -9,   191,   192,    -9,    -9,   193,   194,  1122,
     195,   196,   197,   313,   198,   199,    -9,  1569,   200,    -9,
     752,   753,   754,   755,   756,   757,   758,   759,   760,   761,
     201,   202,   203,   204,   205,   206,   207,   890,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,   208,   213,   215,   216,
     762,   217,   951,   218,   311,   953,    -9,   312,   314,   956,
     315,   316,   317,   322,   963,  1246,   323,   336,   337,    -9,
      -9,    -9,   338,   341,   340,   343,    -9,   763,   676,   677,
     678,   679,   680,   681,   682,   683,    -9,   349,    -9,   345,
     352,   354,   357,    16,   364,    17,    18,    19,    20,    21,
      22,   365,    23,    24,    25,    26,    27,   368,   369,    28,
      29,   371,   373,   381,   378,    30,  1647,    31,   570,   571,
     383,   572,   573,   389,    -9,   390,    -9,    -9,    32,    33,
     392,   574,   575,   576,   577,   396,   578,   579,   400,   401,
      34,   402,   403,   404,   580,   410,    35,   411,   412,   419,
     423,   424,   425,   984,   426,    36,   427,   428,   991,   466,
     467,    37,   472,    -9,   473,   476,    38,   486,   490,   491,
     496,   514,   532,   515,   526,   533,   534,   527,   528,    39,
     529,  1419,    40,    41,   535,  1013,  1080,   536,   537,  1092,
     538,   539,   540,    42,   541,   542,    43,   544,   543,  1035,
     545,   548,   569,   590,   616,   617,   621,   581,   582,   583,
     631,   640,   641,   642,   643,   651,   652,   658,   661,   662,
     667,   668,   669,   684,   685,   686,   696,   703,   708,   715,
     783,   726,   732,    44,   736,   746,   749,   751,   769,   771,
    -505,   778,   795,   850,   801,   796,    45,    46,    47,   190,
     802,   584,   560,    48,   817,   832,   833,   834,  1316,   836,
     869,   839,   861,    49,   862,    50,   840,   841,   842,   864,
     865,   585,   586,   868,   843,   844,   876,   845,   846,   847,
     848,   877,   878,   879,   873,   880,   883,  1293,   886,   885,
     889,   891,   892,   893,   894,   895,   896,   899,  1442,   900,
     901,    51,   902,    52,    53,   908,   911,  1137,   912,   910,
     913,   914,   587,   915,   588,   190,   918,   921,   923,   919,
     932,   922,   924,   925,   939,   935,   940,   931,   941,  1146,
     942,   943,   944,   964,   965,   966,   971,   972,   973,   968,
      54,   988,   997,   974,   998,  1002,  1052,  1010,  1014,  1015,
    1032,  1042,  1043,  1044,  1046,  1048,  1051,  1073,  1128,  1055,
    1056,  1057,  1058,  1059,  1062,  1063,  1064,  1065,  1067,  1068,
    1152,  1157,  1078,  1099,  1245,  1100,  1101,  1103,  1104,  1114,
    1115,  1108,  1116,  1121,  1123,  1124,  -543,  1439,  1195,  1143,
    1147,  1148,  1149,  1150,  1155,  1203,  1163,  1156,  1188,  1197,
    1179,  1199,  1200,  1201,  1164,  1242,  1204,  1209,  1211,  1213,
    1214,  1215,  1229,  1205,  1216,  1217,  1218,  1219,  1220,  1256,
    1226,  1225,  1227,  1228,  1258,  1261,  1252,  1254,  1265,  1266,
    1241,  1267,  1268,  1270,  1271,  1272,   190,  1273,  1276,  1278,
    1279,  1280,  1281,  1283,  1282,  1297,  1285,  1286,  1287,  1288,
    1299,  1289,  1303,  1301,  1311,  1317,  1323,  1324,  1326,  1331,
    1341,  1541,  1304,  1336,  1337,  1330,  1338,  1325,  1339,  1342,
    1346,  1347,  1348,  1374,  1377,  1510,  1383,  1391,  1318,  1402,
    1380,  1372,  1376,  1397,  1403,  1404,  1405,  1486,  1381,  1409,
    1410,  1411,  1416,  1420,  1421,  1447,  1422,  1382,  1423,  1424,
    1425,  1414,  1426,  1427,  1428,  1435,  1440,  1415,  1519,  1443,
    1466,  1471,  1476,  1469,  1470,  1477,  1615,  1473,  1482,  1483,
    1485,  1495,  1496,  1491,  1497,  1498,  1106,  1492,  1500,  1494,
    1501,  1503,  1513,  1505,  1506,  1523,  1543,  1551,  1507,  1544,
    1508,  1518,  1511,  1514,  1516,  1517,  1545,  1552,  1540,  1571,
    1537,  1553,  1556,  1557,  1558,  1559,  1561,  1562,  1563,  1564,
    1597,  1582,  1567,  1575,  1572,  1573,  1570,  1583,  1565,  1584,
    1585,  1617,  1371,  1542,  1586,  1590,  1594,  1596,  1598,  1599,
    1568,  1610,  1611,  1613,  1614,  1600,  1616,  1619,  1370,  1618,
    1235,  1620,  1373,  1602,  1601,  1622,  1623,  1629,  1630,  1603,
    1604,  1631,  1633,  1605,  1606,  1621,  1635,  1636,  1607,  1608,
    1634,  1637,  1639,  1642,  1609,  1628,  1640,  1624,  1641,  1643,
    1644,  1645,  1646,   132,  1651,  1649,  1650,  1625,  1652,  1632,
    1656,  1657,  1659,  1660,  1661,  1664,  1665,  1666,  1667,  1212,
     745,   996,  1300,   248,  1007,  1468,  1240,  1467,  1019,   970,
     750,  1244,  1655,  1248,   620,  1069,   167,  1050,  1407,  1178,
     657,  1294,   952,   611,  1648,  1274,  1082,  1441,  1663,   190,
    1653,     0,     0,  1654,     0,  1499,     0,     0,     0,     0,
       0,     0,  1658,     0,     0,  1662,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   399,     0,     0,     0,
       0,     0,  1539,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1627,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1638,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1612,     0,     0,     0,   190,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1626
};

static const yytype_int16 yycheck[] =
{
     126,   404,   189,   500,   347,   596,   884,   257,   351,   951,
     353,     4,  1130,     4,     4,    30,    30,     6,     6,     6,
       4,   963,     4,     6,   367,     6,     6,   370,     6,     6,
       4,     6,    30,     6,     6,     6,     6,   380,     6,    58,
      30,    91,    28,    48,   166,    30,    71,    58,    76,    77,
      78,    79,   175,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    28,    30,   159,    58,    96,    19,    36,
      37,    31,    28,    76,    77,    78,    79,   175,    30,   180,
     266,  1170,   268,    96,    30,    52,   104,    96,    96,  1178,
     108,   109,    59,    41,    96,    21,     3,     4,     4,     6,
      96,     4,     0,    49,    50,    81,    82,    83,    84,     3,
       4,   233,     6,   112,   113,   114,   115,   116,   117,   220,
     221,   222,   223,    71,    30,   266,   469,     8,   269,  1247,
     533,   126,   125,    76,    77,    78,    79,    96,  1080,    96,
     263,   266,    45,    96,   269,  1087,    96,    96,    91,   174,
    1092,    96,   157,   158,    96,    96,    96,    96,    96,    96,
      96,    96,   266,   660,   567,   263,   184,   664,   167,   666,
      96,   266,   167,   268,   224,   225,   226,    98,    99,    48,
     166,   102,   103,   100,   101,   175,    55,   166,   167,   104,
     266,   167,   268,   108,   219,    28,   156,   176,   188,  1064,
     151,   152,  1067,    36,    37,   181,    39,    58,   266,    30,
     268,     4,    33,    34,    47,    36,    37,   266,   166,   167,
     187,   167,   266,   242,   268,    46,    47,    48,    49,   266,
      51,    52,   243,     6,    55,    56,    57,    58,   267,   264,
     255,   255,   270,   266,   272,   268,   167,   170,   171,   260,
     242,   216,   266,   268,   267,    94,   232,   255,   267,   267,
     386,   247,     6,   249,   269,   267,   245,   270,   266,   272,
     255,   267,   258,   259,    76,    77,    78,    79,   271,   269,
     271,   266,   271,   271,   271,   269,   265,   269,   271,   255,
     271,   271,   266,   271,   271,   698,   271,   270,   270,   270,
     270,   269,   258,   255,  1246,   251,   252,   253,   267,   255,
     267,   144,   145,   259,   267,   441,     6,   267,   267,   445,
     172,   173,   267,   174,   175,   267,   267,   267,   267,   267,
     267,   267,   267,     6,   167,    61,    62,    63,    64,    65,
      66,    67,    68,     6,   687,   166,   167,   163,   164,   165,
    1422,  1423,  1424,   169,   175,  1427,   189,   190,   191,   192,
     193,   194,   195,   196,   185,     6,   217,   218,   219,   619,
     620,   148,   149,   499,   500,     9,  1318,   503,   220,   221,
     222,   223,   266,   509,   268,     6,     1,    87,    88,    89,
      90,   242,   120,   121,     9,   150,   151,   152,   153,   118,
     119,   234,    87,    88,    89,    90,   227,     6,   229,    25,
     261,   268,   269,   246,    29,     3,     4,   250,     6,    98,
      99,   547,   255,   256,   257,   258,    41,   268,   269,   555,
    1548,   154,   155,    25,   255,    36,    37,   258,    39,   565,
     566,    72,    73,    74,    59,    61,    62,    63,    64,    65,
      66,    67,    68,     3,     4,    70,     6,     6,   955,     3,
       4,    76,     6,     3,     4,   591,     6,     6,   655,    61,
      62,    63,    64,    65,    66,    67,    68,    87,    88,    89,
      90,    96,   197,   198,   199,   200,   201,   202,   203,   204,
       1,   236,   237,   238,   239,   266,     7,   268,     9,    10,
      11,    12,    13,    14,     6,    16,    17,    18,    19,    20,
    1227,  1228,    23,    24,     3,     4,     6,     6,    29,   266,
      31,   268,     3,     4,  1021,     6,   266,   266,   268,   268,
     780,    42,    43,   659,   660,     6,     6,   663,   664,   266,
     666,   268,   266,    54,   268,   266,   228,   268,   230,    60,
     266,     6,   268,     6,     3,     3,     6,   267,    69,   174,
       6,     6,   688,   689,    75,     6,     6,   182,   183,    80,
       6,  1449,     4,   266,     4,    95,     4,     4,     4,   705,
       4,   269,    93,   266,     6,    96,    97,     4,   266,   992,
     266,   266,   266,     6,   266,   266,   107,  1539,   266,   110,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     266,   266,   266,   266,   266,   266,   266,   743,    61,    62,
      63,    64,    65,    66,    67,    68,   266,   266,   266,   266,
     235,   266,   819,   266,   266,   822,   147,   266,   266,   826,
     266,     6,     6,    25,   831,  1142,     4,     6,    20,   160,
     161,   162,    19,    10,    25,    42,   167,   262,   535,   536,
     537,   538,   539,   540,   541,   542,   177,    43,   179,    31,
      54,    69,    93,     7,    75,     9,    10,    11,    12,    13,
      14,    80,    16,    17,    18,    19,    20,    97,   269,    23,
      24,   147,   107,   179,   110,    29,  1638,    31,    33,    34,
     215,    36,    37,   217,   215,    28,   217,   218,    42,    43,
     218,    46,    47,    48,    49,     4,    51,    52,   254,    48,
      54,   266,     6,     6,    59,     6,    60,     6,   266,   162,
      22,     4,     6,   859,     4,    69,     4,     4,   864,     4,
       4,    75,   269,   254,   269,     4,    80,     4,   266,     4,
       4,    60,    27,     6,   270,     6,     4,   270,   270,    93,
     270,  1352,    96,    97,     4,   891,   953,     4,     4,   956,
       4,     4,     4,   107,     4,     4,   110,   268,     6,   905,
      27,     4,   269,    28,     4,     4,     4,   122,   123,   124,
       4,     4,     4,     4,   111,     4,     4,     4,     4,     4,
      25,    25,     6,   266,    76,     6,     6,     6,     4,     6,
     268,     6,     6,   147,     6,     6,     6,     6,     6,     6,
       4,     4,     4,   175,     4,     6,   160,   161,   162,   955,
       4,   166,   167,   167,   268,     6,     6,   266,  1241,     3,
      71,     4,     4,   177,     4,   179,   266,   266,   266,     4,
       4,   186,   187,     4,   266,   266,     4,   266,   266,   266,
     266,     4,     4,     4,   269,     4,     4,  1210,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     4,  1375,     4,
       4,   215,     4,   217,   218,     4,     6,  1013,     6,    92,
       6,     6,   227,     4,   229,  1021,     4,     4,     4,   269,
     266,   270,     6,     6,     4,   266,     4,   105,     4,  1035,
       4,     4,     4,    26,    26,    25,     4,     6,   266,   146,
     254,     4,     6,    28,     4,     4,   231,    53,     6,     6,
      53,     4,     6,     4,     4,     4,     4,   268,   270,     6,
       6,     6,     6,     6,     4,     4,     4,     4,     4,     4,
     266,   104,     6,     6,  1141,     6,     6,     6,     6,     6,
       6,   178,     6,     6,     6,     4,     4,  1370,   266,     6,
       6,     6,     6,     4,     4,    27,     4,     6,     4,     4,
     166,     4,     4,     4,   105,   146,    27,     6,     4,     4,
       4,     4,   269,    26,     6,     6,     6,     4,     4,   270,
       4,     6,     4,     4,   105,     4,   269,   269,     6,     6,
    1136,     6,     6,     6,     6,     6,  1142,     6,     6,     6,
       6,     6,     6,     4,    56,   268,     6,     6,     6,     6,
       6,   166,     6,   268,     6,     6,     4,     4,     4,     4,
       4,   126,   268,     6,     6,   266,     6,   269,     6,     6,
       6,     6,    27,     6,     4,  1458,     4,     4,  1245,     4,
     270,   175,   240,     6,     4,     4,     4,    28,   270,     6,
       6,     4,     6,     4,     6,     4,     6,   270,     6,     6,
       6,   266,     6,     6,     6,     3,     6,   266,   106,     6,
       6,     4,     6,   270,   270,     6,  1593,   269,     6,     4,
       4,     4,     4,    28,     4,     4,   970,    28,     6,    28,
     268,     4,     6,   270,   270,     4,     6,     4,   270,    25,
     270,   270,   269,   269,   269,   269,     6,     4,   268,    26,
     175,     6,     6,     6,     6,   175,     4,     4,     4,     4,
      26,     4,     6,  1546,     6,     6,   248,     4,   175,     4,
       4,     4,  1296,   270,     6,     6,     6,     6,     6,     6,
     269,     6,     6,     6,     6,    25,     6,     6,  1294,    27,
     269,     6,  1298,   270,   269,     6,     6,     4,     6,   270,
     270,    27,     6,   270,   270,    26,     6,     4,   270,   270,
      26,     4,     4,    27,   270,   270,     6,   269,     6,     6,
       6,     4,     4,    29,    27,     6,     6,   269,     6,   270,
       6,     6,     6,     6,     6,     6,     6,     6,     6,  1110,
     593,   866,  1219,   164,   881,  1401,  1131,  1400,   897,   838,
     598,  1140,   241,  1145,   473,   944,    95,   918,  1329,  1068,
     501,  1210,   820,   459,   268,  1177,   954,  1373,   244,  1375,
     270,    -1,    -1,   270,    -1,  1442,    -1,    -1,    -1,    -1,
      -1,    -1,   270,    -1,    -1,   268,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   306,    -1,    -1,    -1,
      -1,    -1,  1499,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1615,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1589,    -1,    -1,    -1,  1593,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1612
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   159,   274,   275,   276,     0,     8,   277,     4,   170,
     171,     1,   278,   266,   266,   266,     7,     9,    10,    11,
      12,    13,    14,    16,    17,    18,    19,    20,    23,    24,
      29,    31,    42,    43,    54,    60,    69,    75,    80,    93,
      96,    97,   107,   110,   147,   160,   161,   162,   167,   177,
     179,   215,   217,   218,   254,   279,   280,   281,   283,   284,
     286,   288,   290,   291,   308,   309,   310,   311,   313,   316,
     318,   319,   323,   324,   352,   362,   364,   373,   374,   376,
     377,   398,   399,   411,   412,   413,   453,   454,   518,   556,
     558,   559,   576,   577,   578,   579,   594,   595,   620,   621,
     638,   639,   654,   655,   667,   668,   703,   704,   716,   717,
     736,   737,   747,   748,   769,   770,   789,   790,   282,     6,
     285,    94,   287,   289,   312,   314,   317,     6,     6,   172,
     173,   365,   365,   353,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     9,     6,     6,     6,     6,     3,     3,
     292,   414,     6,     6,     6,     6,     6,   320,   325,     6,
     378,   400,   416,   455,   519,   560,   580,   580,   596,   622,
     640,   656,   669,   707,   719,   739,   750,   267,   773,   792,
       4,   266,     4,    95,     4,     4,     4,     4,   269,   392,
     395,   266,     6,     4,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   293,
       4,   266,   415,   266,   705,   266,   266,   266,   266,    21,
      96,   321,   322,    96,   267,   326,   351,   363,    96,   267,
     379,   397,    96,   267,   401,    96,   267,   417,   418,   419,
     452,    96,   267,   456,   457,   458,   516,    96,   457,   520,
     557,    96,   267,   561,   562,   575,    96,   267,   581,   582,
     587,   593,    96,   592,    96,   267,   597,   598,   619,    96,
     267,   623,   624,   637,    96,   267,   641,    96,   267,   657,
     666,    96,   267,   670,   671,   693,    96,   267,   706,   708,
      96,   267,   718,   720,   721,    96,   267,   738,   740,   741,
      96,   267,   749,   751,   754,   774,   772,    96,   267,   791,
     793,   266,   266,     6,   266,   266,     6,     6,     6,   271,
     393,   395,    25,     4,     1,     9,    29,    41,    59,    70,
      76,    96,   174,   182,   183,   294,     6,    20,    19,   327,
      25,    10,   380,    42,   402,    31,   420,   422,   421,    43,
     459,   469,    54,   521,    69,   563,   564,    93,    76,    77,
      78,    79,    91,   583,    75,    80,   599,   600,    97,   269,
     626,   147,   642,   107,   104,   108,   109,   184,   110,   672,
     676,   179,   709,   215,    28,   216,    30,   255,   734,   217,
      28,   744,   218,    28,   258,   757,     4,    96,   771,   773,
     254,    48,   266,     6,     6,     6,   271,     6,   271,   394,
       6,     6,   266,   295,   301,   298,   303,   299,   296,   162,
     300,   297,   302,    22,     4,     6,     4,     4,     4,   266,
     268,   375,   423,   424,   425,   427,   430,   432,   434,   437,
     439,   443,   444,   447,   448,   450,   451,     4,   271,     4,
      45,   460,   266,   268,   375,   470,   485,   487,   266,   268,
     375,   522,   523,   537,   539,   541,     4,     4,   565,   566,
     584,   585,   269,   269,   588,   590,     4,   266,   268,   375,
     602,   625,   266,   268,   375,   627,     4,   658,   660,   661,
     266,     4,   266,   268,   375,   677,     4,   722,   724,   395,
     735,   733,   742,    30,   255,   266,   745,   755,   752,    30,
     255,   266,   758,   775,    60,     6,    61,    62,    63,    64,
      65,    66,    67,    68,   315,   315,   270,   270,   270,   270,
     266,   393,    27,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,   268,    27,   381,   403,     4,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,   166,
     167,   176,   245,   265,     4,   395,   433,   395,   461,   269,
      33,    34,    36,    37,    46,    47,    48,    49,    51,    52,
      59,   122,   123,   124,   166,   186,   187,   227,   229,   493,
      28,   489,    30,    33,    34,    46,    47,    48,    49,    51,
      55,    56,    57,    58,   166,   175,   185,   227,   229,   255,
     258,   493,   266,   268,   375,   567,     4,     4,   583,   586,
     586,     4,   266,   268,   591,    81,    82,    83,    84,   181,
     232,     4,    98,    99,   102,   103,   636,   148,   149,   644,
       4,     4,     4,   111,   673,   112,   113,   114,   115,   116,
     117,     4,     4,   730,   395,   392,   266,   734,     4,   395,
     746,     4,     4,   395,   759,   776,   794,    25,    25,     6,
     315,   163,   164,   165,   169,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   266,    76,     6,   382,   395,   404,
     428,   220,   221,   222,   223,   431,     6,   426,   395,   445,
     440,   449,   435,     6,   395,   395,   315,   463,     4,   180,
     220,   221,   222,   223,   484,     6,   473,   197,   198,   199,
     200,   201,   202,   203,   204,   348,     6,    91,   224,   225,
     226,   548,     6,   474,   488,   478,     6,   481,   475,   476,
     472,   471,   490,   395,   529,   431,     6,   532,   348,     6,
     548,     6,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   235,   262,   517,   538,   540,   542,   533,     6,
     525,     6,   527,   530,   524,    41,    71,   166,     4,   270,
     272,   583,   270,   268,   589,    87,    88,    89,    90,   603,
     604,   605,   606,   607,   608,     4,     6,   628,   100,   101,
     643,     4,     4,   104,   108,   662,   118,   119,   674,   678,
     679,   680,   681,   682,   683,   710,   723,   268,   731,   393,
     743,   395,   392,   756,   753,   395,   392,   266,   268,   777,
     785,   392,     6,     6,   266,   354,     3,   306,   305,     4,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   328,
     175,   366,   367,   266,   268,   375,   383,   390,   395,   395,
     405,     4,     4,   315,     4,     4,   441,   442,     4,    71,
     436,   438,   395,   269,   464,   462,     4,     4,     4,     4,
       4,   482,   483,     4,   477,     6,     4,   494,   497,     4,
     395,     4,     4,     4,     4,     4,     4,   544,   545,     4,
       4,     4,     4,   549,   552,   569,   573,   568,     4,   583,
      92,     6,     6,     6,     6,     4,   610,   614,     4,   269,
     609,     4,   270,     4,     6,     6,   150,   151,   152,   153,
     645,   105,   266,   663,   665,   266,   120,   121,   675,     4,
       4,     4,     4,     4,     4,   711,   725,    71,   174,   219,
     264,   393,   745,   393,   760,   764,   393,    28,   166,   247,
     249,   258,   259,   393,    26,    26,    25,   355,   146,   547,
     547,     4,     6,   266,    28,   369,    30,    49,    50,   251,
     252,   253,   255,   259,   395,   266,   268,   406,     4,   429,
       6,   395,   446,     3,     4,     6,   442,     6,     4,     4,
     125,   271,     4,   479,     3,     4,     6,   483,   494,   498,
      53,   495,   486,   395,     6,     6,     3,     4,     6,   545,
     526,   528,    61,    62,    63,    64,    65,    66,    67,    68,
     534,   553,    53,   550,     4,   395,   570,    72,    73,    74,
     574,   571,     4,     6,     4,   601,     4,   611,     4,   615,
     601,     4,   231,   618,   629,     6,     6,     6,     6,     6,
     646,   659,     4,     4,     4,     4,   689,     4,     4,   689,
     266,   268,   712,   268,   726,   727,   728,   732,     6,   394,
     393,   268,   758,   761,   762,   767,   268,   392,   763,   765,
     766,   768,   393,   778,   786,   782,   780,   781,   394,     6,
       6,     6,   357,     6,     6,   307,   307,   329,   178,   368,
     370,   384,   391,   387,     6,     6,     6,   385,   388,   166,
     233,     6,   315,     6,     4,   465,   467,   466,   270,   694,
     509,   496,    36,    37,    39,   491,   492,   395,   543,   535,
     536,   392,   531,     6,   555,   551,   395,     6,     6,     6,
       4,   572,   266,   612,   616,     4,     6,   104,   630,   633,
     266,   268,   647,     4,   105,   636,    87,    88,    89,    90,
     691,   692,    87,    88,    89,    90,   690,   636,   691,   166,
      58,   174,   175,   217,   218,   219,   242,   261,     4,   394,
     175,   263,   175,   263,   394,   266,   394,     4,   787,     4,
       4,     4,   266,    27,    27,    26,   266,   268,   358,     6,
     330,     4,   372,     4,     4,     4,     6,     6,     6,     4,
       4,   407,   228,   230,   410,     6,     4,     4,     4,   269,
     480,   695,    48,   157,   158,   269,   506,   510,   511,   513,
     497,   395,   146,   546,   549,   393,   392,   514,   552,     3,
       4,     6,   269,   613,   269,   617,   270,   634,   105,   154,
     155,     4,   664,   684,   686,     6,     6,     6,     6,   692,
       6,     6,     6,     6,   684,   713,     6,   729,     6,     6,
       6,     6,    56,     4,   788,     6,     6,     6,     6,   166,
     266,   268,   331,   375,   450,   371,   372,   268,   396,     6,
     396,   268,   408,     6,   268,   375,   468,   468,   468,   696,
     698,     6,   512,     6,   271,   499,   315,     6,   393,   394,
     268,   506,   515,     4,     4,   269,     4,   631,   648,   649,
     266,     4,    19,   151,   152,   687,     6,     6,     6,     6,
     714,     4,     6,     3,     4,     6,     6,     6,    27,   356,
     359,    28,    47,   144,   145,   189,   190,   191,   192,   193,
     194,   195,   196,   234,   246,   250,   255,   256,   257,   258,
     395,   371,   175,   395,     6,   386,   240,     4,   409,   126,
     270,   270,   270,     4,    36,    37,    52,    59,   187,   699,
     702,     4,     6,   271,     6,   271,   502,     6,   394,    48,
      55,   554,     4,     4,     4,     4,   650,   650,   685,     6,
       6,     4,   715,   779,   266,   266,     6,   360,   334,   348,
       4,     6,     6,     6,     6,     6,     6,     6,     6,   236,
     237,   238,   239,   347,   333,     3,   336,   332,   338,   315,
       6,   395,   392,     6,     3,     4,     6,     4,   701,   700,
       6,   270,     6,   270,     6,   270,     6,   270,     4,    30,
     175,   188,   500,   501,   503,   506,     6,   517,   502,   270,
     270,     4,   632,   269,   651,   688,     6,     6,     3,     4,
       6,   783,     6,     4,   361,     4,    28,   349,   349,   349,
     349,    28,    28,   349,    28,     4,     4,     4,     4,   393,
       6,   268,   697,     4,   494,   270,   270,   270,   270,    25,
     315,   269,   508,     6,   269,   507,   269,   269,   270,   106,
     635,    31,   156,     4,    58,   243,   260,   784,     3,     4,
       6,   335,   350,   339,   340,   341,   337,   175,   343,   393,
     268,   126,   270,     6,    25,     6,     4,    30,   505,     6,
     271,     4,     4,     6,   653,   652,     6,     6,     6,   175,
     342,     4,     4,     4,     4,   175,   344,     6,   269,   394,
     248,    26,     6,     6,    25,   315,   504,   506,     6,   271,
       6,   271,     4,     4,     4,     4,     6,    58,   242,   345,
       6,    58,   242,   346,     6,   389,     6,    26,     6,     6,
      25,   269,   270,   270,   270,   270,   270,   270,   270,   270,
       6,     6,   395,     6,     6,   392,     6,     4,    27,     6,
       6,    26,     6,     6,   269,   269,   395,   393,   270,     4,
       6,    27,   270,     6,    26,     6,     4,     4,   393,     4,
       6,     6,    27,     6,     6,     4,     4,   394,   268,     6,
       6,    27,     6,   270,   270,   241,     6,     6,   270,     6,
       6,     6,   268,   244,     6,     6,     6,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   273,   274,   275,   276,   275,   277,   277,   277,   278,
     278,   278,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   282,   281,   283,   285,   284,   287,   286,   289,   288,
     290,   292,   291,   293,   293,   295,   294,   296,   294,   297,
     294,   298,   294,   299,   294,   300,   294,   301,   294,   302,
     294,   303,   294,   294,   305,   304,   306,   304,   304,   304,
     304,   307,   307,   308,   309,   310,   312,   311,   314,   313,
     315,   315,   315,   315,   315,   315,   315,   315,   317,   316,
     318,   319,   320,   320,   321,   322,   323,   324,   325,   325,
     327,   328,   329,   326,   330,   330,   331,   331,   331,   331,
     332,   331,   333,   331,   331,   331,   334,   335,   331,   336,
     337,   331,   338,   331,   331,   331,   331,   331,   331,   339,
     331,   340,   331,   331,   341,   331,   331,   342,   342,   343,
     343,   344,   344,   345,   345,   345,   346,   346,   346,   347,
     347,   347,   347,   348,   348,   348,   348,   348,   348,   348,
     348,   349,   350,   349,   351,   353,   354,   352,   355,   355,
     356,   356,   357,   357,   359,   358,   360,   360,   361,   361,
     361,   363,   362,   364,   365,   365,   366,   367,   367,   368,
     368,   369,   370,   369,   371,   371,   372,   373,   374,   375,
     376,   377,   378,   378,   380,   381,   379,   382,   382,   384,
     383,   385,   386,   383,   387,   383,   388,   389,   383,   383,
     383,   390,   390,   390,   391,   390,   392,   393,   394,   394,
     395,   395,   395,   395,   396,   396,   397,   398,   399,   400,
     400,   402,   403,   401,   404,   404,   405,   405,   407,   406,
     406,   408,   408,   409,   409,   409,   410,   410,   411,   412,
     413,   414,   414,   415,   416,   416,   417,   418,   420,   419,
     421,   421,   421,   422,   422,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   423,   423,   423,   424,   426,   425,
     428,   427,   429,   429,   430,   431,   431,   431,   431,   432,
     432,   433,   433,   435,   434,   436,   436,   438,   437,   440,
     439,   441,   441,   442,   442,   442,   443,   445,   444,   446,
     446,   447,   447,   447,   449,   448,   450,   450,   450,   451,
     452,   453,   454,   455,   455,   456,   457,   459,   458,   461,
     460,   462,   460,   463,   463,   465,   464,   466,   464,   467,
     464,   468,   468,   468,   469,   469,   471,   470,   470,   470,
     472,   470,   473,   470,   470,   470,   470,   470,   470,   470,
     474,   470,   470,   475,   470,   476,   477,   470,   478,   479,
     480,   470,   481,   470,   470,   482,   482,   483,   483,   483,
     484,   484,   484,   484,   484,   486,   485,   488,   487,   489,
     490,   489,   491,   491,   492,   492,   492,   493,   493,   493,
     494,   494,   496,   495,   498,   499,   497,   500,   501,   502,
     502,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   504,   503,   505,   503,   503,   506,   506,   506,   506,
     506,   506,   506,   506,   507,   507,   507,   507,   508,   509,
     509,   510,   510,   511,   512,   511,   513,   514,   514,   515,
     515,   516,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   518,   519,   519,   520,   521,   521,
     522,   522,   522,   522,   523,   524,   523,   525,   526,   523,
     523,   523,   527,   528,   523,   529,   523,   530,   531,   523,
     523,   523,   523,   532,   523,   523,   523,   523,   523,   523,
     533,   523,   523,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   535,   536,   535,   538,   537,   540,   539,   542,
     543,   541,   544,   544,   545,   545,   545,   546,   546,   547,
     547,   548,   548,   548,   548,   549,   549,   551,   550,   553,
     554,   552,   555,   556,   557,   558,   559,   560,   560,   561,
     563,   562,   564,   564,   565,   566,   566,   567,   568,   567,
     569,   567,   567,   570,   570,   571,   571,   572,   572,   572,
     573,   573,   574,   574,   574,   575,   576,   577,   578,   579,
     580,   580,   581,   581,   582,   584,   583,   585,   583,   583,
     583,   586,   586,   586,   588,   587,   589,   589,   590,   590,
     591,   591,   591,   591,   592,   593,   594,   595,   596,   596,
     597,   599,   598,   600,   600,   601,   601,   603,   602,   604,
     602,   605,   602,   606,   602,   607,   602,   608,   602,   602,
     609,   609,   609,   610,   610,   612,   611,   613,   613,   613,
     613,   614,   614,   616,   615,   617,   617,   617,   617,   618,
     618,   619,   620,   621,   622,   622,   623,   625,   624,   626,
     626,   627,   627,   627,   628,   629,   627,   627,   631,   632,
     630,   633,   634,   633,   635,   635,   636,   636,   637,   638,
     639,   640,   640,   642,   643,   641,   644,   644,   645,   645,
     645,   645,   646,   646,   648,   647,   649,   647,   650,   650,
     652,   651,   653,   651,   654,   655,   656,   656,   658,   659,
     657,   660,   657,   661,   657,   657,   663,   664,   662,   665,
     662,   666,   667,   668,   669,   669,   670,   672,   671,   673,
     673,   674,   674,   674,   675,   675,   675,   676,   676,   678,
     677,   679,   677,   680,   677,   681,   677,   682,   677,   683,
     677,   677,   685,   684,   686,   686,   687,   687,   688,   688,
     689,   689,   690,   690,   690,   690,   691,   691,   692,   692,
     692,   692,   693,   694,   694,   696,   695,   697,   697,   698,
     698,   700,   699,   701,   699,   702,   702,   702,   702,   703,
     704,   705,   705,   706,   707,   707,   709,   710,   708,   711,
     711,   713,   712,   714,   714,   715,   715,   715,   716,   717,
     718,   719,   719,   720,   722,   723,   721,   724,   721,   725,
     725,   726,   726,   726,   726,   727,   729,   728,   728,   728,
     728,   728,   730,   730,   732,   731,   731,   731,   731,   733,
     733,   734,   735,   734,   736,   737,   738,   739,   739,   740,
     742,   743,   741,   744,   744,   745,   746,   745,   747,   748,
     749,   750,   750,   751,   752,   753,   751,   755,   756,   754,
     757,   757,   758,   759,   758,   760,   760,   761,   761,   762,
     763,   764,   764,   765,   765,   766,   767,   768,   769,   770,
     771,   772,   772,   774,   775,   773,   776,   776,   777,   778,
     779,   777,   780,   777,   781,   777,   782,   777,   777,   783,
     783,   784,   784,   784,   786,   785,   787,   787,   788,   788,
     788,   789,   790,   791,   792,   792,   794,   793
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     0,     4,     0,     3,     3,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     2,     0,     4,     0,     4,     0,     4,
       1,     0,     5,     0,     2,     0,     5,     0,     5,     0,
       5,     0,     5,     0,     5,     0,     5,     0,     5,     0,
       5,     0,     5,     2,     0,     4,     0,     4,     1,     2,
       2,     0,     1,     5,     3,     3,     0,    14,     0,    14,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       3,     2,     0,     2,     5,     2,     3,     3,     0,     2,
       0,     0,     0,    10,     0,     2,     2,     1,     3,     3,
       0,     4,     0,     4,     3,     2,     0,     0,     9,     0,
       0,    11,     0,     9,     3,     4,     4,     4,     4,     0,
       6,     0,     6,     4,     0,     6,     3,     0,     2,     0,
       2,     0,     2,     0,     2,     2,     0,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     0,     3,     2,     0,     0,    11,     0,     5,
       0,     3,     0,     2,     0,     4,     0,     2,     2,     2,
       2,     0,     9,     2,     1,     1,     2,     0,     3,     0,
       1,     0,     0,     4,     0,     2,     1,     8,     1,     2,
       3,     3,     0,     2,     0,     0,     6,     0,     2,     0,
       7,     0,     0,    10,     0,     4,     0,     0,    24,     1,
       1,     4,     4,     6,     0,     4,     1,     1,     0,     2,
       4,     4,     4,     4,     0,     3,     2,     4,     3,     0,
       2,     0,     0,     7,     2,     3,     0,     2,     0,     4,
       3,     0,     2,     2,     2,     2,     1,     1,     3,     3,
       3,     0,     2,     1,     0,     2,     3,     2,     0,     4,
       0,     2,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       0,     5,     0,     1,     3,     1,     1,     1,     1,     2,
       2,     2,     3,     0,     8,     0,     1,     0,     6,     0,
       4,     1,     2,     2,     2,     2,     2,     0,     6,     1,
       2,     3,     2,     4,     0,     4,     2,     2,     2,     3,
       2,     3,     3,     0,     2,     3,     1,     0,     3,     0,
       3,     0,     6,     0,     2,     0,     6,     0,     6,     0,
       6,     0,     1,     2,     0,     2,     0,     4,     3,     2,
       0,     4,     0,     4,     3,     3,     3,     3,     3,     3,
       0,     4,     1,     0,     4,     0,     0,     5,     0,     0,
       0,     8,     0,     4,     1,     1,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     0,     6,     0,     4,     0,
       0,     3,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     3,     0,     0,     6,     2,     2,     0,
       2,     1,     3,     2,     4,    10,     8,     9,    11,     1,
       1,     0,    10,     0,     4,     1,     4,     4,     4,     4,
       5,     5,     5,     5,     4,     4,     4,     4,     6,     0,
       2,     1,     1,     1,     0,     3,     2,     0,     2,     3,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     2,     3,     0,     2,
       1,     1,     1,     1,     2,     0,     4,     0,     0,     6,
       3,     3,     0,     0,     9,     0,     6,     0,     0,     8,
       3,     2,     3,     0,     4,     3,     3,     3,     3,     3,
       0,     4,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     0,     2,     0,     5,     0,     4,     0,
       0,     7,     1,     2,     2,     2,     2,     0,     3,     0,
       3,     1,     1,     1,     1,     1,     2,     0,     3,     0,
       0,     7,     1,     3,     2,     3,     3,     0,     2,     4,
       0,     3,     0,     2,     1,     0,     2,     3,     0,     4,
       0,     4,     1,     2,     1,     0,     2,     2,     2,     2,
       0,     2,     2,     2,     2,     2,     3,     3,     3,     3,
       0,     2,     1,     1,     4,     0,     3,     0,     6,     4,
       4,     1,     2,     3,     0,     8,     0,     1,     0,     2,
       3,     3,     3,     3,     2,     2,     3,     3,     0,     2,
       3,     0,     3,     0,     2,     0,     1,     0,     5,     0,
       4,     0,     4,     0,     5,     0,     4,     0,     5,     1,
       0,     4,     8,     0,     2,     0,     3,     0,     4,     8,
      12,     0,     2,     0,     3,     0,     4,     8,    12,     0,
       2,     2,     3,     3,     0,     2,     3,     0,     6,     0,
       2,     5,     5,     3,     0,     0,     6,     1,     0,     0,
       6,     0,     0,     3,     0,     2,     1,     1,     2,     4,
       3,     0,     2,     0,     0,     8,     1,     1,     1,     2,
       2,     2,     0,     2,     0,     4,     0,     4,     0,     2,
       0,     5,     0,     5,     3,     3,     0,     2,     0,     0,
      10,     0,     6,     0,     6,     3,     0,     0,     6,     0,
       3,     2,     3,     3,     0,     2,     3,     0,     4,     0,
       3,     0,     1,     1,     0,     1,     1,     0,     2,     0,
       7,     0,     6,     0,     5,     0,     7,     0,     6,     0,
       5,     1,     0,     4,     0,     2,     3,     3,     0,     2,
       0,     2,     2,     2,     2,     2,     1,     2,     3,     3,
       3,     3,     2,     0,     2,     0,     6,     0,     2,     0,
       2,     0,     3,     0,     3,     1,     1,     1,     1,     3,
       3,     0,     1,     2,     0,     2,     0,     0,     7,     0,
       2,     0,     4,     0,     2,     2,     2,     2,     3,     3,
       2,     0,     2,     4,     0,     0,     6,     0,     4,     0,
       2,     3,     3,     1,     1,     3,     0,     4,     2,     2,
       2,     2,     0,     2,     0,     4,     2,     2,     3,     0,
       2,     3,     0,     6,     3,     3,     2,     0,     2,     3,
       0,     0,     6,     0,     2,     3,     0,     6,     3,     3,
       2,     0,     2,     3,     0,     0,     8,     0,     0,     7,
       0,     2,     3,     0,     6,     0,     2,     1,     1,     2,
       2,     0,     2,     1,     1,     2,     3,     3,     4,     3,
       2,     0,     2,     0,     0,     6,     0,     2,     2,     0,
       0,     8,     0,     4,     0,     4,     0,     5,     1,     0,
       2,     2,     2,     2,     0,     4,     0,     2,     2,     2,
       2,     3,     3,     2,     0,     2,     0,     8
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (defData, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, defData); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, defrData *defData)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (defData);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, defrData *defData)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, defData);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, defrData *defData)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], defData);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, defData); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, defrData *defData)
{
  YY_USE (yyvaluep);
  YY_USE (defData);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (defrData *defData)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, defData);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* $@1: %empty  */
#line 220 "def/def.y"
                { defData->dumb_mode = 1; defData->no_num = 1; }
#line 3293 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 5: /* version_stmt: K_VERSION $@1 T_STRING ';'  */
#line 221 "def/def.y"
      {
        defData->VersionNum = defrData::convert_defname2num((yyvsp[-1].string));
        if (defData->VersionNum > CURRENT_VERSION) {
          char temp[300];
          sprintf(temp,
          "The execution has been stopped because the DEF parser %.1f does not support DEF file with version %s.\nUpdate your DEF file to version 5.8 or earlier.",
                  CURRENT_VERSION, (yyvsp[-1].string));
          defData->defError(6503, temp);
          return 1;
        }
        if (defData->callbacks->VersionStrCbk) {
          CALLBACK(defData->callbacks->VersionStrCbk, defrVersionStrCbkType, (yyvsp[-1].string));
        } else if (defData->callbacks->VersionCbk) {
            CALLBACK(defData->callbacks->VersionCbk, defrVersionCbkType, defData->VersionNum);
        }
        if (defData->VersionNum > 5.3 && defData->VersionNum < 5.4)
          defData->defIgnoreVersion = 1;
        if (defData->VersionNum < 5.6)     // default to false before 5.6
          defData->names_case_sensitive = defData->session->reader_case_sensitive;
        else
          defData->names_case_sensitive = 1;
        defData->hasVer = 1;
        defData->doneDesign = 0;
    }
#line 3322 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 7: /* case_sens_stmt: K_NAMESCASESENSITIVE K_ON ';'  */
#line 248 "def/def.y"
      {
        if (defData->VersionNum < 5.6) {
          defData->names_case_sensitive = 1;
          if (defData->callbacks->CaseSensitiveCbk)
            CALLBACK(defData->callbacks->CaseSensitiveCbk, defrCaseSensitiveCbkType,
                     defData->names_case_sensitive); 
          defData->hasNameCase = 1;
        } else
          if (defData->callbacks->CaseSensitiveCbk) // write error only if cbk is set 
             if (defData->caseSensitiveWarnings++ < defData->settings->CaseSensitiveWarnings)
               defData->defWarning(7011, "The NAMESCASESENSITIVE statement is obsolete in version 5.6 and later.\nThe DEF parser will ignore this statement.");
      }
#line 3339 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 8: /* case_sens_stmt: K_NAMESCASESENSITIVE K_OFF ';'  */
#line 261 "def/def.y"
      {
        if (defData->VersionNum < 5.6) {
          defData->names_case_sensitive = 0;
          if (defData->callbacks->CaseSensitiveCbk)
            CALLBACK(defData->callbacks->CaseSensitiveCbk, defrCaseSensitiveCbkType,
                     defData->names_case_sensitive);
          defData->hasNameCase = 1;
        } else {
          if (defData->callbacks->CaseSensitiveCbk) { // write error only if cbk is set 
            if (defData->caseSensitiveWarnings++ < defData->settings->CaseSensitiveWarnings) {
              defData->defError(6504, "Def parser version 5.7 and later does not support NAMESCASESENSITIVE OFF.\nEither remove this optional construct or set it to ON.");
              CHKERR();
            }
          }
        }
      }
#line 3360 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 51: /* $@2: %empty  */
#line 301 "def/def.y"
                      {defData->dumb_mode = 1; defData->no_num = 1; }
#line 3366 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 52: /* design_name: K_DESIGN $@2 T_STRING ';'  */
#line 302 "def/def.y"
      {
            if (defData->callbacks->DesignCbk)
              CALLBACK(defData->callbacks->DesignCbk, defrDesignStartCbkType, (yyvsp[-1].string));
            defData->hasDes = 1;
          }
#line 3376 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 53: /* end_design: K_END K_DESIGN  */
#line 309 "def/def.y"
          {
            defData->doneDesign = 1;
            if (defData->callbacks->DesignEndCbk)
              CALLBACK(defData->callbacks->DesignEndCbk, defrDesignEndCbkType, 0);
            // 11/16/2001 - pcr 408334
            // Return 1 if there is any defData->errors during parsing
            if (defData->errors)
                return 1;

            if (!defData->hasVer) {
              char temp[300];
              sprintf(temp, "No VERSION statement found, using the default value %2g.", defData->VersionNum);
              defData->defWarning(7012, temp);            
            }
            if (!defData->hasNameCase && defData->VersionNum < 5.6)
              defData->defWarning(7013, "The DEF file is invalid if NAMESCASESENSITIVE is undefined.\nNAMESCASESENSITIVE is a mandatory statement in the DEF file with version 5.6 and earlier.\nTo define the NAMESCASESENSITIVE statement, refer to the LEF/DEF 5.5 and earlier Language Reference manual.");
            if (!defData->hasBusBit && defData->VersionNum < 5.6)
              defData->defWarning(7014, "The DEF file is invalid if BUSBITCHARS is undefined.\nBUSBITCHARS is a mandatory statement in the DEF file with version 5.6 and earlier.\nTo define the BUSBITCHARS statement, refer to the LEF/DEF 5.5 and earlier Language Reference manual.");
            if (!defData->hasDivChar && defData->VersionNum < 5.6)
              defData->defWarning(7015, "The DEF file is invalid if DIVIDERCHAR is undefined.\nDIVIDERCHAR is a mandatory statement in the DEF file with version 5.6 and earlier.\nTo define the DIVIDERCHAR statement, refer to the LEF/DEF 5.5 and earlier Language Reference manual.");
            if (!defData->hasDes)
              defData->defWarning(7016, "DESIGN is a mandatory statement in the DEF file. Ensure that it exists in the file.");
          }
#line 3404 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 54: /* $@3: %empty  */
#line 333 "def/def.y"
                  { defData->dumb_mode = 1; defData->no_num = 1; }
#line 3410 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 55: /* tech_name: K_TECH $@3 T_STRING ';'  */
#line 334 "def/def.y"
          { 
            if (defData->callbacks->TechnologyCbk)
              CALLBACK(defData->callbacks->TechnologyCbk, defrTechNameCbkType, (yyvsp[-1].string));
          }
#line 3419 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 56: /* $@4: %empty  */
#line 339 "def/def.y"
                    {defData->dumb_mode = 1; defData->no_num = 1;}
#line 3425 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 57: /* array_name: K_ARRAY $@4 T_STRING ';'  */
#line 340 "def/def.y"
          { 
            if (defData->callbacks->ArrayNameCbk)
              CALLBACK(defData->callbacks->ArrayNameCbk, defrArrayNameCbkType, (yyvsp[-1].string));
          }
#line 3434 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 58: /* $@5: %empty  */
#line 345 "def/def.y"
                            { defData->dumb_mode = 1; defData->no_num = 1; }
#line 3440 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 59: /* floorplan_name: K_FLOORPLAN $@5 T_STRING ';'  */
#line 346 "def/def.y"
          { 
            if (defData->callbacks->FloorPlanNameCbk)
              CALLBACK(defData->callbacks->FloorPlanNameCbk, defrFloorPlanNameCbkType, (yyvsp[-1].string));
          }
#line 3449 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 60: /* history: K_HISTORY  */
#line 352 "def/def.y"
          { 
            if (defData->callbacks->HistoryCbk)
              CALLBACK(defData->callbacks->HistoryCbk, defrHistoryCbkType, &defData->History_text[0]);
          }
#line 3458 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 61: /* $@6: %empty  */
#line 358 "def/def.y"
          {
            if (defData->callbacks->PropDefStartCbk)
              CALLBACK(defData->callbacks->PropDefStartCbk, defrPropDefStartCbkType, 0);
          }
#line 3467 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 62: /* prop_def_section: K_PROPERTYDEFINITIONS $@6 property_defs K_END K_PROPERTYDEFINITIONS  */
#line 363 "def/def.y"
          { 
            if (defData->callbacks->PropDefEndCbk)
              CALLBACK(defData->callbacks->PropDefEndCbk, defrPropDefEndCbkType, 0);
            defData->real_num = 0;     // just want to make sure it is reset 
          }
#line 3477 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 64: /* property_defs: property_defs property_def  */
#line 371 "def/def.y"
            { }
#line 3483 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 65: /* $@7: %empty  */
#line 373 "def/def.y"
                       {defData->dumb_mode = 1; defData->no_num = 1; defData->Prop.clear(); }
#line 3489 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 66: /* property_def: K_DESIGN $@7 T_STRING property_type_and_val ';'  */
#line 375 "def/def.y"
            {
              if (defData->callbacks->PropCbk) {
                defData->Prop.setPropType("design", (yyvsp[-2].string));
                CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
              }
              defData->session->DesignProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
            }
#line 3501 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 67: /* $@8: %empty  */
#line 382 "def/def.y"
                { defData->dumb_mode = 1 ; defData->no_num = 1; defData->Prop.clear(); }
#line 3507 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 68: /* property_def: K_NET $@8 T_STRING property_type_and_val ';'  */
#line 384 "def/def.y"
            {
              if (defData->callbacks->PropCbk) {
                defData->Prop.setPropType("net", (yyvsp[-2].string));
                CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
              }
              defData->session->NetProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
            }
#line 3519 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 69: /* $@9: %empty  */
#line 391 "def/def.y"
                 { defData->dumb_mode = 1 ; defData->no_num = 1; defData->Prop.clear(); }
#line 3525 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 70: /* property_def: K_SNET $@9 T_STRING property_type_and_val ';'  */
#line 393 "def/def.y"
            {
              if (defData->callbacks->PropCbk) {
                defData->Prop.setPropType("specialnet", (yyvsp[-2].string));
                CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
              }
              defData->session->SNetProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
            }
#line 3537 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 71: /* $@10: %empty  */
#line 400 "def/def.y"
                   { defData->dumb_mode = 1 ; defData->no_num = 1; defData->Prop.clear(); }
#line 3543 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 72: /* property_def: K_REGION $@10 T_STRING property_type_and_val ';'  */
#line 402 "def/def.y"
            {
              if (defData->callbacks->PropCbk) {
                defData->Prop.setPropType("region", (yyvsp[-2].string));
                CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
              }
              defData->session->RegionProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
            }
#line 3555 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 73: /* $@11: %empty  */
#line 409 "def/def.y"
                  { defData->dumb_mode = 1 ; defData->no_num = 1; defData->Prop.clear(); }
#line 3561 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 74: /* property_def: K_GROUP $@11 T_STRING property_type_and_val ';'  */
#line 411 "def/def.y"
            {
              if (defData->callbacks->PropCbk) {
                defData->Prop.setPropType("group", (yyvsp[-2].string));
                CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
              }
              defData->session->GroupProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
            }
#line 3573 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 75: /* $@12: %empty  */
#line 418 "def/def.y"
                      { defData->dumb_mode = 1 ; defData->no_num = 1; defData->Prop.clear(); }
#line 3579 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 76: /* property_def: K_COMPONENT $@12 T_STRING property_type_and_val ';'  */
#line 420 "def/def.y"
            {
              if (defData->callbacks->PropCbk) {
                defData->Prop.setPropType("component", (yyvsp[-2].string));
                CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
              }
              defData->session->CompProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
            }
#line 3591 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 77: /* $@13: %empty  */
#line 427 "def/def.y"
                { defData->dumb_mode = 1 ; defData->no_num = 1; defData->Prop.clear(); }
#line 3597 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 78: /* property_def: K_ROW $@13 T_STRING property_type_and_val ';'  */
#line 429 "def/def.y"
            {
              if (defData->callbacks->PropCbk) {
                defData->Prop.setPropType("row", (yyvsp[-2].string));
                CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
              }
              defData->session->RowProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
            }
#line 3609 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 79: /* $@14: %empty  */
#line 438 "def/def.y"
          { defData->dumb_mode = 1 ; defData->no_num = 1; defData->Prop.clear(); }
#line 3615 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 80: /* property_def: K_COMPONENTPIN $@14 T_STRING property_type_and_val ';'  */
#line 440 "def/def.y"
            {
              if (defData->callbacks->PropCbk) {
                defData->Prop.setPropType("componentpin", (yyvsp[-2].string));
                CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
              }
              defData->session->CompPinProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
            }
#line 3627 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 81: /* $@15: %empty  */
#line 448 "def/def.y"
          { defData->dumb_mode = 1 ; defData->no_num = 1; defData->Prop.clear(); }
#line 3633 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 82: /* property_def: K_NONDEFAULTRULE $@15 T_STRING property_type_and_val ';'  */
#line 450 "def/def.y"
            {
              if (defData->VersionNum < 5.6) {
                if (defData->nonDefaultWarnings++ < defData->settings->NonDefaultWarnings) {
                  defData->defMsg = (char*)malloc(1000); 
                  sprintf (defData->defMsg,
                     "The NONDEFAULTRULE statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6505, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              } else {
                if (defData->callbacks->PropCbk) {
                  defData->Prop.setPropType("nondefaultrule", (yyvsp[-2].string));
                  CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
                }
                defData->session->NDefProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
              }
            }
#line 3656 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 83: /* property_def: error ';'  */
#line 468 "def/def.y"
                    { yyerrok; yyclearin;}
#line 3662 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 84: /* $@16: %empty  */
#line 470 "def/def.y"
                                 { defData->real_num = 0; }
#line 3668 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 85: /* property_type_and_val: K_INTEGER $@16 opt_range opt_num_val  */
#line 471 "def/def.y"
            {
              if (defData->callbacks->PropCbk) defData->Prop.setPropInteger();
              defData->defPropDefType = 'I';
            }
#line 3677 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 86: /* $@17: %empty  */
#line 475 "def/def.y"
                 { defData->real_num = 1; }
#line 3683 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 87: /* property_type_and_val: K_REAL $@17 opt_range opt_num_val  */
#line 476 "def/def.y"
            {
              if (defData->callbacks->PropCbk) defData->Prop.setPropReal();
              defData->defPropDefType = 'R';
              defData->real_num = 0;
            }
#line 3693 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 88: /* property_type_and_val: K_STRING  */
#line 482 "def/def.y"
            {
              if (defData->callbacks->PropCbk) defData->Prop.setPropString();
              defData->defPropDefType = 'S';
            }
#line 3702 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 89: /* property_type_and_val: K_STRING QSTRING  */
#line 487 "def/def.y"
            {
              if (defData->callbacks->PropCbk) defData->Prop.setPropQString((yyvsp[0].string));
              defData->defPropDefType = 'Q';
            }
#line 3711 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 90: /* property_type_and_val: K_NAMEMAPSTRING T_STRING  */
#line 492 "def/def.y"
            {
              if (defData->callbacks->PropCbk) defData->Prop.setPropNameMapString((yyvsp[0].string));
              defData->defPropDefType = 'S';
            }
#line 3720 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 92: /* opt_num_val: NUMBER  */
#line 499 "def/def.y"
            { if (defData->callbacks->PropCbk) defData->Prop.setNumber((yyvsp[0].dval)); }
#line 3726 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 93: /* units: K_UNITS K_DISTANCE K_MICRONS NUMBER ';'  */
#line 502 "def/def.y"
          {
            if (defData->callbacks->UnitsCbk) {
              if (defData->defValidNum((int)(yyvsp[-1].dval)))
                CALLBACK(defData->callbacks->UnitsCbk,  defrUnitsCbkType, (yyvsp[-1].dval));
            }
          }
#line 3737 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 94: /* divider_char: K_DIVIDERCHAR QSTRING ';'  */
#line 510 "def/def.y"
          {
            if (defData->callbacks->DividerCbk)
              CALLBACK(defData->callbacks->DividerCbk, defrDividerCbkType, (yyvsp[-1].string));
            defData->hasDivChar = 1;
          }
#line 3747 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 95: /* bus_bit_chars: K_BUSBITCHARS QSTRING ';'  */
#line 517 "def/def.y"
          { 
            if (defData->callbacks->BusBitCbk)
              CALLBACK(defData->callbacks->BusBitCbk, defrBusBitCbkType, (yyvsp[-1].string));
            defData->hasBusBit = 1;
          }
#line 3757 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 96: /* $@18: %empty  */
#line 523 "def/def.y"
                     {defData->dumb_mode = 1;defData->no_num = 1; }
#line 3763 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 97: /* canplace: K_CANPLACE $@18 T_STRING NUMBER NUMBER orient K_DO NUMBER K_BY NUMBER K_STEP NUMBER NUMBER ';'  */
#line 525 "def/def.y"
            {
              if (defData->callbacks->CanplaceCbk) {
                defData->Canplace.setName((yyvsp[-11].string));
                defData->Canplace.setLocation((yyvsp[-10].dval),(yyvsp[-9].dval));
                defData->Canplace.setOrient((yyvsp[-8].integer));
                defData->Canplace.setDo((yyvsp[-6].dval),(yyvsp[-4].dval),(yyvsp[-2].dval),(yyvsp[-1].dval));
                CALLBACK(defData->callbacks->CanplaceCbk, defrCanplaceCbkType,
                &(defData->Canplace));
              }
            }
#line 3778 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 98: /* $@19: %empty  */
#line 535 "def/def.y"
                             {defData->dumb_mode = 1;defData->no_num = 1; }
#line 3784 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 99: /* cannotoccupy: K_CANNOTOCCUPY $@19 T_STRING NUMBER NUMBER orient K_DO NUMBER K_BY NUMBER K_STEP NUMBER NUMBER ';'  */
#line 537 "def/def.y"
            {
              if (defData->callbacks->CannotOccupyCbk) {
                defData->CannotOccupy.setName((yyvsp[-11].string));
                defData->CannotOccupy.setLocation((yyvsp[-10].dval),(yyvsp[-9].dval));
                defData->CannotOccupy.setOrient((yyvsp[-8].integer));
                defData->CannotOccupy.setDo((yyvsp[-6].dval),(yyvsp[-4].dval),(yyvsp[-2].dval),(yyvsp[-1].dval));
                CALLBACK(defData->callbacks->CannotOccupyCbk, defrCannotOccupyCbkType,
                        &(defData->CannotOccupy));
              }
            }
#line 3799 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 100: /* orient: K_N  */
#line 548 "def/def.y"
               {(yyval.integer) = 0;}
#line 3805 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 101: /* orient: K_W  */
#line 549 "def/def.y"
               {(yyval.integer) = 1;}
#line 3811 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 102: /* orient: K_S  */
#line 550 "def/def.y"
               {(yyval.integer) = 2;}
#line 3817 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 103: /* orient: K_E  */
#line 551 "def/def.y"
               {(yyval.integer) = 3;}
#line 3823 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 104: /* orient: K_FN  */
#line 552 "def/def.y"
               {(yyval.integer) = 4;}
#line 3829 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 105: /* orient: K_FW  */
#line 553 "def/def.y"
               {(yyval.integer) = 5;}
#line 3835 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 106: /* orient: K_FS  */
#line 554 "def/def.y"
               {(yyval.integer) = 6;}
#line 3841 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 107: /* orient: K_FE  */
#line 555 "def/def.y"
               {(yyval.integer) = 7;}
#line 3847 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 108: /* $@20: %empty  */
#line 558 "def/def.y"
          {
            defData->Geometries.Reset();
          }
#line 3855 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 109: /* die_area: K_DIEAREA $@20 firstPt nextPt otherPts ';'  */
#line 562 "def/def.y"
          {
            if (defData->callbacks->DieAreaCbk) {
               defData->DieArea.addPoint(&defData->Geometries);
               CALLBACK(defData->callbacks->DieAreaCbk, defrDieAreaCbkType, &(defData->DieArea));
            }
          }
#line 3866 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 110: /* pin_cap_rule: start_def_cap pin_caps end_def_cap  */
#line 571 "def/def.y"
            { }
#line 3872 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 111: /* start_def_cap: K_DEFAULTCAP NUMBER  */
#line 574 "def/def.y"
        {
          if (defData->VersionNum < 5.4) {
             if (defData->callbacks->DefaultCapCbk)
                CALLBACK(defData->callbacks->DefaultCapCbk, defrDefaultCapCbkType, ROUND((yyvsp[0].dval)));
          } else {
             if (defData->callbacks->DefaultCapCbk) // write error only if cbk is set 
                if (defData->defaultCapWarnings++ < defData->settings->DefaultCapWarnings)
                   defData->defWarning(7017, "The DEFAULTCAP statement is obsolete in version 5.4 and later.\nThe DEF parser will ignore this statement.");
          }
        }
#line 3887 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 114: /* pin_cap: K_MINPINS NUMBER K_WIRECAP NUMBER ';'  */
#line 590 "def/def.y"
          {
            if (defData->VersionNum < 5.4) {
              if (defData->callbacks->PinCapCbk) {
                defData->PinCap.setPin(ROUND((yyvsp[-3].dval)));
                defData->PinCap.setCap((yyvsp[-1].dval));
                CALLBACK(defData->callbacks->PinCapCbk, defrPinCapCbkType, &(defData->PinCap));
              }
            }
          }
#line 3901 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 115: /* end_def_cap: K_END K_DEFAULTCAP  */
#line 601 "def/def.y"
            { }
#line 3907 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 116: /* pin_rule: start_pins pins end_pins  */
#line 604 "def/def.y"
            { }
#line 3913 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 117: /* start_pins: K_PINS NUMBER ';'  */
#line 607 "def/def.y"
          { 
            if (defData->callbacks->StartPinsCbk)
              CALLBACK(defData->callbacks->StartPinsCbk, defrStartPinsCbkType, ROUND((yyvsp[-1].dval)));
          }
#line 3922 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 120: /* $@21: %empty  */
#line 616 "def/def.y"
         {defData->dumb_mode = 1; defData->no_num = 1; }
#line 3928 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 121: /* $@22: %empty  */
#line 617 "def/def.y"
         {defData->dumb_mode = 1; defData->no_num = 1; }
#line 3934 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 122: /* $@23: %empty  */
#line 618 "def/def.y"
          {
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
              defData->Pin.Setup((yyvsp[-4].string), (yyvsp[0].string));
            }
            defData->hasPort = 0;
          }
#line 3945 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 123: /* pin: '-' $@21 T_STRING '+' K_NET $@22 T_STRING $@23 pin_options ';'  */
#line 625 "def/def.y"
          { 
            if (defData->callbacks->PinCbk)
              CALLBACK(defData->callbacks->PinCbk, defrPinCbkType, &defData->Pin);
          }
#line 3954 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 126: /* pin_option: '+' K_SPECIAL  */
#line 634 "def/def.y"
          {
            if (defData->callbacks->PinCbk)
              defData->Pin.setSpecial();
          }
#line 3963 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 127: /* pin_option: extension_stmt  */
#line 640 "def/def.y"
          { 
            if (defData->callbacks->PinExtCbk)
              CALLBACK(defData->callbacks->PinExtCbk, defrPinExtCbkType, &defData->History_text[0]);
          }
#line 3972 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 128: /* pin_option: '+' K_DIRECTION T_STRING  */
#line 646 "def/def.y"
          {
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.setDirection((yyvsp[0].string));
          }
#line 3981 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 129: /* pin_option: '+' K_NETEXPR QSTRING  */
#line 652 "def/def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The NETEXPR statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6506, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
                defData->Pin.setNetExpr((yyvsp[0].string));

            }
          }
#line 4005 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 130: /* $@24: %empty  */
#line 672 "def/def.y"
                                  { defData->dumb_mode = 1; }
#line 4011 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 131: /* pin_option: '+' K_SUPPLYSENSITIVITY $@24 T_STRING  */
#line 673 "def/def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The SUPPLYSENSITIVITY statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6507, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
                defData->Pin.setSupplySens((yyvsp[0].string));
            }
          }
#line 4034 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 132: /* $@25: %empty  */
#line 692 "def/def.y"
                                  { defData->dumb_mode = 1; }
#line 4040 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 133: /* pin_option: '+' K_GROUNDSENSITIVITY $@25 T_STRING  */
#line 693 "def/def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The GROUNDSENSITIVITY statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6508, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
                defData->Pin.setGroundSens((yyvsp[0].string));
            }
          }
#line 4063 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 134: /* pin_option: '+' K_USE use_type  */
#line 713 "def/def.y"
          {
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) defData->Pin.setUse((yyvsp[0].string));
          }
#line 4071 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 135: /* pin_option: '+' K_PORT  */
#line 717 "def/def.y"
          {
            if (defData->VersionNum < 5.7) {
               if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                 if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                     (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                   defData->defMsg = (char*)malloc(10000);
                   sprintf (defData->defMsg,
                     "The PORT in PINS is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                   defData->defError(6555, defData->defMsg);
                   free(defData->defMsg);
                   CHKERR();
                 }
               }
            } else {
               if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
                 defData->Pin.addPort();
               defData->hasPort = 1;
            }
          }
#line 4095 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 136: /* $@26: %empty  */
#line 737 "def/def.y"
                      { defData->dumb_mode = 1; }
#line 4101 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 137: /* $@27: %empty  */
#line 738 "def/def.y"
          {
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
              if (defData->hasPort)
                 defData->Pin.addPortLayer((yyvsp[0].string));
              else
                 defData->Pin.addLayer((yyvsp[0].string));
            }
          }
#line 4114 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 138: /* pin_option: '+' K_LAYER $@26 T_STRING $@27 pin_layer_mask_opt pin_layer_spacing_opt pt pt  */
#line 747 "def/def.y"
          {
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
              if (defData->hasPort)
                 defData->Pin.addPortLayerPts((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y);
              else
                 defData->Pin.addLayerPts((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y);
            }
          }
#line 4127 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 139: /* $@28: %empty  */
#line 756 "def/def.y"
                        { defData->dumb_mode = 1; }
#line 4133 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 140: /* $@29: %empty  */
#line 757 "def/def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The POLYGON statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6509, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort)
                   defData->Pin.addPortPolygon((yyvsp[0].string));
                else
                   defData->Pin.addPolygon((yyvsp[0].string));
              }
            }
            
            defData->Geometries.Reset();            
          }
#line 4162 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 141: /* pin_option: '+' K_POLYGON $@28 T_STRING $@29 pin_poly_mask_opt pin_poly_spacing_opt firstPt nextPt nextPt otherPts  */
#line 782 "def/def.y"
          {
            if (defData->VersionNum >= 5.6) {  // only add if 5.6 or beyond
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort)
                   defData->Pin.addPortPolygonPts(&defData->Geometries);
                else
                   defData->Pin.addPolygonPts(&defData->Geometries);
              }
            }
          }
#line 4177 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 142: /* $@30: %empty  */
#line 792 "def/def.y"
                    { defData->dumb_mode = 1; }
#line 4183 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 143: /* pin_option: '+' K_VIA $@30 T_STRING pin_via_mask_opt '(' NUMBER NUMBER ')'  */
#line 793 "def/def.y"
          {
            if (defData->VersionNum < 5.7) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The PIN VIA statement is available in version 5.7 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6556, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort)
                   defData->Pin.addPortVia((yyvsp[-5].string), (int)(yyvsp[-2].dval),
                                               (int)(yyvsp[-1].dval), (yyvsp[-4].integer));
                else
                   defData->Pin.addVia((yyvsp[-5].string), (int)(yyvsp[-2].dval),
                                               (int)(yyvsp[-1].dval), (yyvsp[-4].integer));
              }
            }
          }
#line 4212 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 144: /* pin_option: placement_status pt orient  */
#line 819 "def/def.y"
          {
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
              if (defData->hasPort)
                 defData->Pin.setPortPlacement((yyvsp[-2].integer), (yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].integer));
              else
                 defData->Pin.setPlacement((yyvsp[-2].integer), (yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].integer));
            }
          }
#line 4225 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 145: /* pin_option: '+' K_ANTENNAPINPARTIALMETALAREA NUMBER pin_layer_opt  */
#line 830 "def/def.y"
          {
            if (defData->VersionNum <= 5.3) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAPINPARTIALMETALAREA statement is available in version 5.4 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6510, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAPinPartialMetalArea((int)(yyvsp[-1].dval), (yyvsp[0].string)); 
          }
#line 4247 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 146: /* pin_option: '+' K_ANTENNAPINPARTIALMETALSIDEAREA NUMBER pin_layer_opt  */
#line 848 "def/def.y"
          {
            if (defData->VersionNum <= 5.3) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAPINPARTIALMETALSIDEAREA statement is available in version 5.4 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6511, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAPinPartialMetalSideArea((int)(yyvsp[-1].dval), (yyvsp[0].string)); 
          }
#line 4269 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 147: /* pin_option: '+' K_ANTENNAPINGATEAREA NUMBER pin_layer_opt  */
#line 866 "def/def.y"
          {
            if (defData->VersionNum <= 5.3) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAPINGATEAREA statement is available in version 5.4 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6512, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
                defData->Pin.addAPinGateArea((int)(yyvsp[-1].dval), (yyvsp[0].string)); 
            }
#line 4291 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 148: /* pin_option: '+' K_ANTENNAPINDIFFAREA NUMBER pin_layer_opt  */
#line 884 "def/def.y"
          {
            if (defData->VersionNum <= 5.3) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAPINDIFFAREA statement is available in version 5.4 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6513, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAPinDiffArea((int)(yyvsp[-1].dval), (yyvsp[0].string)); 
          }
#line 4313 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 149: /* $@31: %empty  */
#line 901 "def/def.y"
                                                    {defData->dumb_mode=1;}
#line 4319 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 150: /* pin_option: '+' K_ANTENNAPINMAXAREACAR NUMBER K_LAYER $@31 T_STRING  */
#line 902 "def/def.y"
          {
            if (defData->VersionNum <= 5.3) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAPINMAXAREACAR statement is available in version 5.4 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6514, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAPinMaxAreaCar((int)(yyvsp[-3].dval), (yyvsp[0].string)); 
          }
#line 4341 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 151: /* $@32: %empty  */
#line 919 "def/def.y"
                                                        {defData->dumb_mode=1;}
#line 4347 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 152: /* pin_option: '+' K_ANTENNAPINMAXSIDEAREACAR NUMBER K_LAYER $@32 T_STRING  */
#line 921 "def/def.y"
          {
            if (defData->VersionNum <= 5.3) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAPINMAXSIDEAREACAR statement is available in version 5.4 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6515, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAPinMaxSideAreaCar((int)(yyvsp[-3].dval), (yyvsp[0].string)); 
          }
#line 4369 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 153: /* pin_option: '+' K_ANTENNAPINPARTIALCUTAREA NUMBER pin_layer_opt  */
#line 939 "def/def.y"
          {
            if (defData->VersionNum <= 5.3) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAPINPARTIALCUTAREA statement is available in version 5.4 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6516, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAPinPartialCutArea((int)(yyvsp[-1].dval), (yyvsp[0].string)); 
          }
#line 4391 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 154: /* $@33: %empty  */
#line 956 "def/def.y"
                                                   {defData->dumb_mode=1;}
#line 4397 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 155: /* pin_option: '+' K_ANTENNAPINMAXCUTCAR NUMBER K_LAYER $@33 T_STRING  */
#line 957 "def/def.y"
          {
            if (defData->VersionNum <= 5.3) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAPINMAXCUTCAR statement is available in version 5.4 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6517, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAPinMaxCutCar((int)(yyvsp[-3].dval), (yyvsp[0].string)); 
          }
#line 4419 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 156: /* pin_option: '+' K_ANTENNAMODEL pin_oxide  */
#line 975 "def/def.y"
          {  // 5.5 syntax 
            if (defData->VersionNum < 5.5) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAMODEL statement is available in version 5.5 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6518, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
          }
#line 4439 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 158: /* pin_layer_mask_opt: K_MASK NUMBER  */
#line 993 "def/def.y"
         { 
           if (defData->validateMaskInput((int)(yyvsp[0].dval), defData->pinWarnings, defData->settings->PinWarnings)) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort)
                   defData->Pin.addPortLayerMask((int)(yyvsp[0].dval));
                else
                   defData->Pin.addLayerMask((int)(yyvsp[0].dval));
              }
           }
         }
#line 4454 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 159: /* pin_via_mask_opt: %empty  */
#line 1006 "def/def.y"
        { (yyval.integer) = 0; }
#line 4460 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 160: /* pin_via_mask_opt: K_MASK NUMBER  */
#line 1008 "def/def.y"
         { 
           if (defData->validateMaskInput((int)(yyvsp[0].dval), defData->pinWarnings, defData->settings->PinWarnings)) {
             (yyval.integer) = (yyvsp[0].dval);
           }
         }
#line 4470 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 162: /* pin_poly_mask_opt: K_MASK NUMBER  */
#line 1016 "def/def.y"
         { 
           if (defData->validateMaskInput((int)(yyvsp[0].dval), defData->pinWarnings, defData->settings->PinWarnings)) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort)
                   defData->Pin.addPortPolyMask((int)(yyvsp[0].dval));
                else
                   defData->Pin.addPolyMask((int)(yyvsp[0].dval));
              }
           }
         }
#line 4485 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 164: /* pin_layer_spacing_opt: K_SPACING NUMBER  */
#line 1030 "def/def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The SPACING statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6519, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort)
                   defData->Pin.addPortLayerSpacing((int)(yyvsp[0].dval));
                else
                   defData->Pin.addLayerSpacing((int)(yyvsp[0].dval));
              }
            }
          }
#line 4512 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 165: /* pin_layer_spacing_opt: K_DESIGNRULEWIDTH NUMBER  */
#line 1053 "def/def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "DESIGNRULEWIDTH statement is a version 5.6 and later syntax.\nYour def file is defined with version %g", defData->VersionNum);
                  defData->defError(6520, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort)
                   defData->Pin.addPortLayerDesignRuleWidth((int)(yyvsp[0].dval));
                else
                   defData->Pin.addLayerDesignRuleWidth((int)(yyvsp[0].dval));
              }
            }
          }
#line 4539 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 167: /* pin_poly_spacing_opt: K_SPACING NUMBER  */
#line 1078 "def/def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "SPACING statement is a version 5.6 and later syntax.\nYour def file is defined with version %g", defData->VersionNum);
                  defData->defError(6521, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort)
                   defData->Pin.addPortPolySpacing((int)(yyvsp[0].dval));
                else
                   defData->Pin.addPolySpacing((int)(yyvsp[0].dval));
              }
            }
          }
#line 4566 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 168: /* pin_poly_spacing_opt: K_DESIGNRULEWIDTH NUMBER  */
#line 1101 "def/def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The DESIGNRULEWIDTH statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6520, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort)
                   defData->Pin.addPortPolyDesignRuleWidth((int)(yyvsp[0].dval));
                else
                   defData->Pin.addPolyDesignRuleWidth((int)(yyvsp[0].dval));
              }
            }
          }
#line 4593 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 169: /* pin_oxide: K_OXIDE1  */
#line 1125 "def/def.y"
          { defData->aOxide = 1;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4602 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 170: /* pin_oxide: K_OXIDE2  */
#line 1130 "def/def.y"
          { defData->aOxide = 2;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4611 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 171: /* pin_oxide: K_OXIDE3  */
#line 1135 "def/def.y"
          { defData->aOxide = 3;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4620 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 172: /* pin_oxide: K_OXIDE4  */
#line 1140 "def/def.y"
          { defData->aOxide = 4;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4629 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 173: /* use_type: K_SIGNAL  */
#line 1146 "def/def.y"
          { (yyval.string) = (char*)"SIGNAL"; }
#line 4635 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 174: /* use_type: K_POWER  */
#line 1148 "def/def.y"
          { (yyval.string) = (char*)"POWER"; }
#line 4641 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 175: /* use_type: K_GROUND  */
#line 1150 "def/def.y"
          { (yyval.string) = (char*)"GROUND"; }
#line 4647 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 176: /* use_type: K_CLOCK  */
#line 1152 "def/def.y"
          { (yyval.string) = (char*)"CLOCK"; }
#line 4653 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 177: /* use_type: K_TIEOFF  */
#line 1154 "def/def.y"
          { (yyval.string) = (char*)"TIEOFF"; }
#line 4659 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 178: /* use_type: K_ANALOG  */
#line 1156 "def/def.y"
          { (yyval.string) = (char*)"ANALOG"; }
#line 4665 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 179: /* use_type: K_SCAN  */
#line 1158 "def/def.y"
          { (yyval.string) = (char*)"SCAN"; }
#line 4671 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 180: /* use_type: K_RESET  */
#line 1160 "def/def.y"
          { (yyval.string) = (char*)"RESET"; }
#line 4677 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 181: /* pin_layer_opt: %empty  */
#line 1164 "def/def.y"
          { (yyval.string) = (char*)""; }
#line 4683 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 182: /* $@34: %empty  */
#line 1165 "def/def.y"
                  {defData->dumb_mode=1;}
#line 4689 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 183: /* pin_layer_opt: K_LAYER $@34 T_STRING  */
#line 1166 "def/def.y"
          { (yyval.string) = (yyvsp[0].string); }
#line 4695 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 184: /* end_pins: K_END K_PINS  */
#line 1169 "def/def.y"
        { 
          if (defData->callbacks->PinEndCbk)
            CALLBACK(defData->callbacks->PinEndCbk, defrPinEndCbkType, 0);
        }
#line 4704 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 185: /* $@35: %empty  */
#line 1174 "def/def.y"
                {defData->dumb_mode = 2; defData->no_num = 2; }
#line 4710 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 186: /* $@36: %empty  */
#line 1176 "def/def.y"
        {
          if (defData->callbacks->RowCbk) {
            defData->rowName = (yyvsp[-4].string);
            defData->Row.setup((yyvsp[-4].string), (yyvsp[-3].string), (yyvsp[-2].dval), (yyvsp[-1].dval), (yyvsp[0].integer));
          }
        }
#line 4721 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 187: /* row_rule: K_ROW $@35 T_STRING T_STRING NUMBER NUMBER orient $@36 row_do_option row_options ';'  */
#line 1184 "def/def.y"
        {
          if (defData->callbacks->RowCbk) 
            CALLBACK(defData->callbacks->RowCbk, defrRowCbkType, &defData->Row);
        }
#line 4730 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 188: /* row_do_option: %empty  */
#line 1190 "def/def.y"
        {
          if (defData->VersionNum < 5.6) {
            if (defData->callbacks->RowCbk) {
              if (defData->rowWarnings++ < defData->settings->RowWarnings) {
                defData->defError(6523, "Invalid ROW statement defined in the DEF file. The DO statement which is required in the ROW statement is not defined.\nUpdate your DEF file with a DO statement.");
                CHKERR();
              }
            }
          }
        }
#line 4745 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 189: /* row_do_option: K_DO NUMBER K_BY NUMBER row_step_option  */
#line 1201 "def/def.y"
        {
          // 06/05/2002 - pcr 448455 
          // Check for 1 and 0 in the correct position 
          // 07/26/2002 - Commented out due to pcr 459218 
          if (defData->hasDoStep) {
            // 04/29/2004 - pcr 695535 
            // changed the testing 
            if ((((yyvsp[-1].dval) == 1) && (defData->yStep == 0)) ||
                (((yyvsp[-3].dval) == 1) && (defData->xStep == 0))) {
              // do nothing 
            } else 
              if (defData->VersionNum < 5.6) {
                if (defData->callbacks->RowCbk) {
                  if (defData->rowWarnings++ < defData->settings->RowWarnings) {
                    defData->defMsg = (char*)malloc(1000);
                    sprintf(defData->defMsg,
                            "The DO statement in the ROW statement with the name %s has invalid syntax.\nThe valid syntax is \"DO numX BY 1 STEP spaceX 0 | DO 1 BY numY STEP 0 spaceY\".\nSpecify the valid syntax and try again.", defData->rowName);
                    defData->defWarning(7018, defData->defMsg);
                    free(defData->defMsg);
                    }
                  }
              }
          }
          // pcr 459218 - Error if at least numX or numY does not equal 1 
          if (((yyvsp[-3].dval) != 1) && ((yyvsp[-1].dval) != 1)) {
            if (defData->callbacks->RowCbk) {
              if (defData->rowWarnings++ < defData->settings->RowWarnings) {
                defData->defError(6524, "Invalid syntax specified. The valid syntax is either \"DO 1 BY num or DO num BY 1\". Specify the valid syntax and try again.");
                CHKERR();
              }
            }
          }
          if (defData->callbacks->RowCbk)
            defData->Row.setDo(ROUND((yyvsp[-3].dval)), ROUND((yyvsp[-1].dval)), defData->xStep, defData->yStep);
        }
#line 4785 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 190: /* row_step_option: %empty  */
#line 1238 "def/def.y"
        {
          defData->hasDoStep = 0;
        }
#line 4793 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 191: /* row_step_option: K_STEP NUMBER NUMBER  */
#line 1242 "def/def.y"
        {
          defData->hasDoStep = 1;
          defData->Row.setHasDoStep();
          defData->xStep = (yyvsp[-1].dval);
          defData->yStep = (yyvsp[0].dval);
        }
#line 4804 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 194: /* $@37: %empty  */
#line 1253 "def/def.y"
                            {defData->dumb_mode = DEF_MAX_INT; }
#line 4810 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 195: /* row_option: '+' K_PROPERTY $@37 row_prop_list  */
#line 1255 "def/def.y"
         { defData->dumb_mode = 0; }
#line 4816 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 198: /* row_prop: T_STRING NUMBER  */
#line 1262 "def/def.y"
        {
          if (defData->callbacks->RowCbk) {
             char propTp;
             char* str = defData->ringCopy("                       ");
             propTp =  defData->session->RowProp.propType((yyvsp[-1].string));
             CHKPROPTYPE(propTp, (yyvsp[-1].string), "ROW");
             // For backword compatibility, also set the string value 
             sprintf(str, "%g", (yyvsp[0].dval));
             defData->Row.addNumProperty((yyvsp[-1].string), (yyvsp[0].dval), str, propTp);
          }
        }
#line 4832 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 199: /* row_prop: T_STRING QSTRING  */
#line 1274 "def/def.y"
        {
          if (defData->callbacks->RowCbk) {
             char propTp;
             propTp =  defData->session->RowProp.propType((yyvsp[-1].string));
             CHKPROPTYPE(propTp, (yyvsp[-1].string), "ROW");
             defData->Row.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
          }
        }
#line 4845 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 200: /* row_prop: T_STRING T_STRING  */
#line 1283 "def/def.y"
        {
          if (defData->callbacks->RowCbk) {
             char propTp;
             propTp =  defData->session->RowProp.propType((yyvsp[-1].string));
             CHKPROPTYPE(propTp, (yyvsp[-1].string), "ROW");
             defData->Row.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
          }
        }
#line 4858 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 201: /* $@38: %empty  */
#line 1293 "def/def.y"
        {
          if (defData->callbacks->TrackCbk) {
            defData->Track.setup((yyvsp[-1].string));
          }
        }
#line 4868 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 202: /* tracks_rule: track_start NUMBER $@38 K_DO NUMBER K_STEP NUMBER track_opts ';'  */
#line 1299 "def/def.y"
        {
          if (((yyvsp[-4].dval) <= 0) && (defData->VersionNum >= 5.4)) {
            if (defData->callbacks->TrackCbk)
              if (defData->trackWarnings++ < defData->settings->TrackWarnings) {
                defData->defMsg = (char*)malloc(1000);
                sprintf (defData->defMsg,
                   "The DO number %g in TRACK is invalid.\nThe number value has to be greater than 0. Specify the valid syntax and try again.", (yyvsp[-4].dval));
                defData->defError(6525, defData->defMsg);
                free(defData->defMsg);
              }
          }
          if ((yyvsp[-2].dval) < 0) {
            if (defData->callbacks->TrackCbk)
              if (defData->trackWarnings++ < defData->settings->TrackWarnings) {
                defData->defMsg = (char*)malloc(1000);
                sprintf (defData->defMsg,
                   "The STEP number %g in TRACK is invalid.\nThe number value has to be greater than 0. Specify the valid syntax and try again.", (yyvsp[-2].dval));
                defData->defError(6526, defData->defMsg);
                free(defData->defMsg);
              }
          }
          if (defData->callbacks->TrackCbk) {
            defData->Track.setDo(ROUND((yyvsp[-7].dval)), ROUND((yyvsp[-4].dval)), (yyvsp[-2].dval));
            CALLBACK(defData->callbacks->TrackCbk, defrTrackCbkType, &defData->Track);
          }
        }
#line 4899 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 203: /* track_start: K_TRACKS track_type  */
#line 1327 "def/def.y"
        {
          (yyval.string) = (yyvsp[0].string);
        }
#line 4907 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 204: /* track_type: K_X  */
#line 1332 "def/def.y"
            { (yyval.string) = (char*)"X";}
#line 4913 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 205: /* track_type: K_Y  */
#line 1334 "def/def.y"
            { (yyval.string) = (char*)"Y";}
#line 4919 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 208: /* track_mask_statement: K_MASK NUMBER same_mask  */
#line 1340 "def/def.y"
           { 
              if (defData->validateMaskInput((int)(yyvsp[-1].dval), defData->trackWarnings, defData->settings->TrackWarnings)) {
                  if (defData->callbacks->TrackCbk) {
                    defData->Track.addMask((yyvsp[-1].dval), (yyvsp[0].integer));
                  }
               }
            }
#line 4931 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 209: /* same_mask: %empty  */
#line 1350 "def/def.y"
        { (yyval.integer) = 0; }
#line 4937 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 210: /* same_mask: K_SAMEMASK  */
#line 1352 "def/def.y"
        { (yyval.integer) = 1; }
#line 4943 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 212: /* $@39: %empty  */
#line 1355 "def/def.y"
                  { defData->dumb_mode = 1000; }
#line 4949 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 213: /* track_layer_statement: K_LAYER $@39 track_layer track_layers  */
#line 1356 "def/def.y"
            { defData->dumb_mode = 0; }
#line 4955 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 216: /* track_layer: T_STRING  */
#line 1363 "def/def.y"
        {
          if (defData->callbacks->TrackCbk)
            defData->Track.addLayer((yyvsp[0].string));
        }
#line 4964 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 217: /* gcellgrid: K_GCELLGRID track_type NUMBER K_DO NUMBER K_STEP NUMBER ';'  */
#line 1370 "def/def.y"
        {
          if ((yyvsp[-3].dval) <= 0) {
            if (defData->callbacks->GcellGridCbk)
              if (defData->gcellGridWarnings++ < defData->settings->GcellGridWarnings) {
                defData->defMsg = (char*)malloc(1000);
                sprintf (defData->defMsg,
                   "The DO number %g in GCELLGRID is invalid.\nThe number value has to be greater than 0. Specify the valid syntax and try again.", (yyvsp[-3].dval));
                defData->defError(6527, defData->defMsg);
                free(defData->defMsg);
              }
          }
          if ((yyvsp[-1].dval) < 0) {
            if (defData->callbacks->GcellGridCbk)
              if (defData->gcellGridWarnings++ < defData->settings->GcellGridWarnings) {
                defData->defMsg = (char*)malloc(1000);
                sprintf (defData->defMsg,
                   "The STEP number %g in GCELLGRID is invalid.\nThe number value has to be greater than 0. Specify the valid syntax and try again.", (yyvsp[-1].dval));
                defData->defError(6528, defData->defMsg);
                free(defData->defMsg);
              }
          }
          if (defData->callbacks->GcellGridCbk) {
            defData->GcellGrid.setup((yyvsp[-6].string), ROUND((yyvsp[-5].dval)), ROUND((yyvsp[-3].dval)), (yyvsp[-1].dval));
            CALLBACK(defData->callbacks->GcellGridCbk, defrGcellGridCbkType, &defData->GcellGrid);
          }
        }
#line 4995 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 218: /* extension_section: K_BEGINEXT  */
#line 1398 "def/def.y"
        {
          if (defData->callbacks->ExtensionCbk)
             CALLBACK(defData->callbacks->ExtensionCbk, defrExtensionCbkType, &defData->History_text[0]);
        }
#line 5004 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 219: /* extension_stmt: '+' K_BEGINEXT  */
#line 1404 "def/def.y"
        { }
#line 5010 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 221: /* via: K_VIAS NUMBER ';'  */
#line 1410 "def/def.y"
        {
          if (defData->callbacks->ViaStartCbk)
            CALLBACK(defData->callbacks->ViaStartCbk, defrViaStartCbkType, ROUND((yyvsp[-1].dval)));
        }
#line 5019 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 224: /* $@40: %empty  */
#line 1419 "def/def.y"
                     {defData->dumb_mode = 1;defData->no_num = 1; }
#line 5025 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 225: /* $@41: %empty  */
#line 1420 "def/def.y"
            {
              if (defData->callbacks->ViaCbk) defData->Via.setup((yyvsp[0].string));
              defData->viaRule = 0;
            }
#line 5034 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 226: /* via_declaration: '-' $@40 T_STRING $@41 layer_stmts ';'  */
#line 1425 "def/def.y"
            {
              if (defData->callbacks->ViaCbk)
                CALLBACK(defData->callbacks->ViaCbk, defrViaCbkType, &defData->Via);
              defData->Via.clear();
            }
#line 5044 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 229: /* $@42: %empty  */
#line 1435 "def/def.y"
                       {defData->dumb_mode = 1;defData->no_num = 1; }
#line 5050 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 230: /* layer_stmt: '+' K_RECT $@42 T_STRING mask pt pt  */
#line 1436 "def/def.y"
            { 
              if (defData->callbacks->ViaCbk)
                if (defData->validateMaskInput((yyvsp[-2].integer), defData->viaWarnings, defData->settings->ViaWarnings)) {
                    defData->Via.addLayer((yyvsp[-3].string), (yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y, (yyvsp[-2].integer));
                }
            }
#line 5061 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 231: /* $@43: %empty  */
#line 1442 "def/def.y"
                        { defData->dumb_mode = 1; }
#line 5067 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 232: /* $@44: %empty  */
#line 1443 "def/def.y"
            {
              if (defData->VersionNum < 5.6) {
                if (defData->callbacks->ViaCbk) {
                  if (defData->viaWarnings++ < defData->settings->ViaWarnings) {
                    defData->defMsg = (char*)malloc(1000);
                    sprintf (defData->defMsg,
                       "The POLYGON statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                    defData->defError(6509, defData->defMsg);
                    free(defData->defMsg);
                    CHKERR();
                  }
                }
              }
              
              defData->Geometries.Reset();
              
            }
#line 5089 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 233: /* layer_stmt: '+' K_POLYGON $@43 T_STRING mask $@44 firstPt nextPt nextPt otherPts  */
#line 1461 "def/def.y"
            {
              if (defData->VersionNum >= 5.6) {  // only add if 5.6 or beyond
                if (defData->callbacks->ViaCbk)
                  if (defData->validateMaskInput((yyvsp[-5].integer), defData->viaWarnings, defData->settings->ViaWarnings)) {
                    defData->Via.addPolygon((yyvsp[-6].string), &defData->Geometries, (yyvsp[-5].integer));
                  }
              }
            }
#line 5102 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 234: /* $@45: %empty  */
#line 1469 "def/def.y"
                            {defData->dumb_mode = 1;defData->no_num = 1; }
#line 5108 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 235: /* layer_stmt: '+' K_PATTERNNAME $@45 T_STRING  */
#line 1470 "def/def.y"
            {
              if (defData->VersionNum < 5.6) {
                if (defData->callbacks->ViaCbk)
                  defData->Via.addPattern((yyvsp[0].string));
              } else
                if (defData->callbacks->ViaCbk)
                  if (defData->viaWarnings++ < defData->settings->ViaWarnings)
                    defData->defWarning(7019, "The PATTERNNAME statement is obsolete in version 5.6 and later.\nThe DEF parser will ignore this statement."); 
            }
#line 5122 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 236: /* $@46: %empty  */
#line 1479 "def/def.y"
                        {defData->dumb_mode = 1;defData->no_num = 1; }
#line 5128 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 237: /* $@47: %empty  */
#line 1481 "def/def.y"
                       {defData->dumb_mode = 3;defData->no_num = 1; }
#line 5134 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 238: /* layer_stmt: '+' K_VIARULE $@46 T_STRING '+' K_CUTSIZE NUMBER NUMBER '+' K_LAYERS $@47 T_STRING T_STRING T_STRING '+' K_CUTSPACING NUMBER NUMBER '+' K_ENCLOSURE NUMBER NUMBER NUMBER NUMBER  */
#line 1484 "def/def.y"
            {
               defData->viaRule = 1;
               if (defData->VersionNum < 5.6) {
                if (defData->callbacks->ViaCbk) {
                  if (defData->viaWarnings++ < defData->settings->ViaWarnings) {
                    defData->defMsg = (char*)malloc(1000);
                    sprintf (defData->defMsg,
                       "The VIARULE statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                    defData->defError(6557, defData->defMsg);
                    free(defData->defMsg);
                    CHKERR();
                  }
                }
              } else {
                if (defData->callbacks->ViaCbk)
                   defData->Via.addViaRule((yyvsp[-20].string), (int)(yyvsp[-17].dval), (int)(yyvsp[-16].dval), (yyvsp[-12].string), (yyvsp[-11].string),
                                             (yyvsp[-10].string), (int)(yyvsp[-7].dval), (int)(yyvsp[-6].dval), (int)(yyvsp[-3].dval),
                                             (int)(yyvsp[-2].dval), (int)(yyvsp[-1].dval), (int)(yyvsp[0].dval)); 
              }
            }
#line 5159 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 240: /* layer_stmt: extension_stmt  */
#line 1506 "def/def.y"
          { 
            if (defData->callbacks->ViaExtCbk)
              CALLBACK(defData->callbacks->ViaExtCbk, defrViaExtCbkType, &defData->History_text[0]);
          }
#line 5168 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 241: /* layer_viarule_opts: '+' K_ROWCOL NUMBER NUMBER  */
#line 1512 "def/def.y"
            {
              if (!defData->viaRule) {
                if (defData->callbacks->ViaCbk) {
                  if (defData->viaWarnings++ < defData->settings->ViaWarnings) {
                    defData->defError(6559, "The ROWCOL statement is missing from the VIARULE statement. Ensure that it exists in the VIARULE statement.");
                    CHKERR();
                  }
                }
              } else if (defData->callbacks->ViaCbk)
                 defData->Via.addRowCol((int)(yyvsp[-1].dval), (int)(yyvsp[0].dval));
            }
#line 5184 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 242: /* layer_viarule_opts: '+' K_ORIGIN NUMBER NUMBER  */
#line 1524 "def/def.y"
            {
              if (!defData->viaRule) {
                if (defData->callbacks->ViaCbk) {
                  if (defData->viaWarnings++ < defData->settings->ViaWarnings) {
                    defData->defError(6560, "The ORIGIN statement is missing from the VIARULE statement. Ensure that it exists in the VIARULE statement.");
                    CHKERR();
                  }
                }
              } else if (defData->callbacks->ViaCbk)
                 defData->Via.addOrigin((int)(yyvsp[-1].dval), (int)(yyvsp[0].dval));
            }
#line 5200 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 243: /* layer_viarule_opts: '+' K_OFFSET NUMBER NUMBER NUMBER NUMBER  */
#line 1536 "def/def.y"
            {
              if (!defData->viaRule) {
                if (defData->callbacks->ViaCbk) {
                  if (defData->viaWarnings++ < defData->settings->ViaWarnings) {
                    defData->defError(6561, "The OFFSET statement is missing from the VIARULE statement. Ensure that it exists in the VIARULE statement.");
                    CHKERR();
                  }
                }
              } else if (defData->callbacks->ViaCbk)
                 defData->Via.addOffset((int)(yyvsp[-3].dval), (int)(yyvsp[-2].dval), (int)(yyvsp[-1].dval), (int)(yyvsp[0].dval));
            }
#line 5216 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 244: /* $@48: %empty  */
#line 1547 "def/def.y"
                        {defData->dumb_mode = 1;defData->no_num = 1; }
#line 5222 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 245: /* layer_viarule_opts: '+' K_PATTERN $@48 T_STRING  */
#line 1548 "def/def.y"
            {
              if (!defData->viaRule) {
                if (defData->callbacks->ViaCbk) {
                  if (defData->viaWarnings++ < defData->settings->ViaWarnings) {
                    defData->defError(6562, "The PATTERN statement is missing from the VIARULE statement. Ensure that it exists in the VIARULE statement.");
                    CHKERR();
                  }
                }
              } else if (defData->callbacks->ViaCbk)
                 defData->Via.addCutPattern((yyvsp[0].string));
            }
#line 5238 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 246: /* firstPt: pt  */
#line 1561 "def/def.y"
          { defData->Geometries.startList((yyvsp[0].pt).x, (yyvsp[0].pt).y); }
#line 5244 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 247: /* nextPt: pt  */
#line 1564 "def/def.y"
          { defData->Geometries.addToList((yyvsp[0].pt).x, (yyvsp[0].pt).y); }
#line 5250 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 250: /* pt: '(' NUMBER NUMBER ')'  */
#line 1571 "def/def.y"
          {
            defData->save_x = (yyvsp[-2].dval);
            defData->save_y = (yyvsp[-1].dval);
            (yyval.pt).x = ROUND((yyvsp[-2].dval));
            (yyval.pt).y = ROUND((yyvsp[-1].dval));
          }
#line 5261 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 251: /* pt: '(' '*' NUMBER ')'  */
#line 1578 "def/def.y"
          {
            defData->save_y = (yyvsp[-1].dval);
            (yyval.pt).x = ROUND(defData->save_x);
            (yyval.pt).y = ROUND((yyvsp[-1].dval));
          }
#line 5271 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 252: /* pt: '(' NUMBER '*' ')'  */
#line 1584 "def/def.y"
          {
            defData->save_x = (yyvsp[-2].dval);
            (yyval.pt).x = ROUND((yyvsp[-2].dval));
            (yyval.pt).y = ROUND(defData->save_y);
          }
#line 5281 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 253: /* pt: '(' '*' '*' ')'  */
#line 1590 "def/def.y"
          {
            (yyval.pt).x = ROUND(defData->save_x);
            (yyval.pt).y = ROUND(defData->save_y);
          }
#line 5290 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 254: /* mask: %empty  */
#line 1596 "def/def.y"
      { (yyval.integer) = 0; }
#line 5296 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 255: /* mask: '+' K_MASK NUMBER  */
#line 1598 "def/def.y"
      { (yyval.integer) = (yyvsp[0].dval); }
#line 5302 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 256: /* via_end: K_END K_VIAS  */
#line 1601 "def/def.y"
        { 
          if (defData->callbacks->ViaEndCbk)
            CALLBACK(defData->callbacks->ViaEndCbk, defrViaEndCbkType, 0);
        }
#line 5311 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 257: /* regions_section: regions_start regions_stmts K_END K_REGIONS  */
#line 1607 "def/def.y"
        {
          if (defData->callbacks->RegionEndCbk)
            CALLBACK(defData->callbacks->RegionEndCbk, defrRegionEndCbkType, 0);
        }
#line 5320 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 258: /* regions_start: K_REGIONS NUMBER ';'  */
#line 1613 "def/def.y"
        {
          if (defData->callbacks->RegionStartCbk)
            CALLBACK(defData->callbacks->RegionStartCbk, defrRegionStartCbkType, ROUND((yyvsp[-1].dval)));
        }
#line 5329 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 260: /* regions_stmts: regions_stmts regions_stmt  */
#line 1620 "def/def.y"
            {}
#line 5335 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 261: /* $@49: %empty  */
#line 1622 "def/def.y"
                  { defData->dumb_mode = 1; defData->no_num = 1; }
#line 5341 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 262: /* $@50: %empty  */
#line 1623 "def/def.y"
        {
          if (defData->callbacks->RegionCbk)
             defData->Region.setup((yyvsp[0].string));
          defData->regTypeDef = 0;
        }
#line 5351 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 263: /* regions_stmt: '-' $@49 T_STRING $@50 rect_list region_options ';'  */
#line 1629 "def/def.y"
        { CALLBACK(defData->callbacks->RegionCbk, defrRegionCbkType, &defData->Region); }
#line 5357 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 264: /* rect_list: pt pt  */
#line 1633 "def/def.y"
        { if (defData->callbacks->RegionCbk)
          defData->Region.addRect((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y); }
#line 5364 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 265: /* rect_list: rect_list pt pt  */
#line 1636 "def/def.y"
        { if (defData->callbacks->RegionCbk)
          defData->Region.addRect((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y); }
#line 5371 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 268: /* $@51: %empty  */
#line 1644 "def/def.y"
                               {defData->dumb_mode = DEF_MAX_INT; }
#line 5377 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 269: /* region_option: '+' K_PROPERTY $@51 region_prop_list  */
#line 1646 "def/def.y"
         { defData->dumb_mode = 0; }
#line 5383 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 270: /* region_option: '+' K_TYPE region_type  */
#line 1648 "def/def.y"
         {
           if (defData->regTypeDef) {
              if (defData->callbacks->RegionCbk) {
                if (defData->regionWarnings++ < defData->settings->RegionWarnings) {
                  defData->defError(6563, "The TYPE statement already exists. It has been defined in the REGION statement.");
                  CHKERR();
                }
              }
           }
           if (defData->callbacks->RegionCbk) defData->Region.setType((yyvsp[0].string));
           defData->regTypeDef = 1;
         }
#line 5400 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 273: /* region_prop: T_STRING NUMBER  */
#line 1667 "def/def.y"
        {
          if (defData->callbacks->RegionCbk) {
             char propTp;
             char* str = defData->ringCopy("                       ");
             propTp = defData->session->RegionProp.propType((yyvsp[-1].string));
             CHKPROPTYPE(propTp, (yyvsp[-1].string), "REGION");
             // For backword compatibility, also set the string value 
             // We will use a temporary string to store the number.
             // The string space is borrowed from the ring buffer
             // in the lexer.
             sprintf(str, "%g", (yyvsp[0].dval));
             defData->Region.addNumProperty((yyvsp[-1].string), (yyvsp[0].dval), str, propTp);
          }
        }
#line 5419 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 274: /* region_prop: T_STRING QSTRING  */
#line 1682 "def/def.y"
        {
          if (defData->callbacks->RegionCbk) {
             char propTp;
             propTp = defData->session->RegionProp.propType((yyvsp[-1].string));
             CHKPROPTYPE(propTp, (yyvsp[-1].string), "REGION");
             defData->Region.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
          }
        }
#line 5432 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 275: /* region_prop: T_STRING T_STRING  */
#line 1691 "def/def.y"
        {
          if (defData->callbacks->RegionCbk) {
             char propTp;
             propTp = defData->session->RegionProp.propType((yyvsp[-1].string));
             CHKPROPTYPE(propTp, (yyvsp[-1].string), "REGION");
             defData->Region.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
          }
        }
#line 5445 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 276: /* region_type: K_FENCE  */
#line 1701 "def/def.y"
            { (yyval.string) = (char*)"FENCE"; }
#line 5451 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 277: /* region_type: K_GUIDE  */
#line 1703 "def/def.y"
            { (yyval.string) = (char*)"GUIDE"; }
#line 5457 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 278: /* comps_maskShift_section: K_COMPSMASKSHIFT layer_statement ';'  */
#line 1706 "def/def.y"
         {
           if (defData->VersionNum < 5.8) {
                if (defData->componentWarnings++ < defData->settings->ComponentWarnings) {
                   defData->defMsg = (char*)malloc(10000);
                   sprintf (defData->defMsg,
                     "The MASKSHIFT statement is available in version 5.8 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
                   defData->defError(7415, defData->defMsg);
                   free(defData->defMsg);
                   CHKERR();
                }
            }
            if (defData->callbacks->ComponentMaskShiftLayerCbk) {
                CALLBACK(defData->callbacks->ComponentMaskShiftLayerCbk, defrComponentMaskShiftLayerCbkType, &defData->ComponentMaskShiftLayer);
            }
         }
#line 5477 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 280: /* start_comps: K_COMPS NUMBER ';'  */
#line 1726 "def/def.y"
         { 
            if (defData->callbacks->ComponentStartCbk)
              CALLBACK(defData->callbacks->ComponentStartCbk, defrComponentStartCbkType,
                       ROUND((yyvsp[-1].dval)));
         }
#line 5487 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 283: /* maskLayer: T_STRING  */
#line 1737 "def/def.y"
        {
            if (defData->callbacks->ComponentMaskShiftLayerCbk) {
              defData->ComponentMaskShiftLayer.addMaskShiftLayer((yyvsp[0].string));
            }
        }
#line 5497 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 286: /* comp: comp_start comp_options ';'  */
#line 1748 "def/def.y"
         {
            if (defData->callbacks->ComponentCbk)
              CALLBACK(defData->callbacks->ComponentCbk, defrComponentCbkType, &defData->Component);
         }
#line 5506 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 287: /* comp_start: comp_id_and_name comp_net_list  */
#line 1754 "def/def.y"
         {
            defData->dumb_mode = 0;
            defData->no_num = 0;
         }
#line 5515 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 288: /* $@52: %empty  */
#line 1759 "def/def.y"
                      {defData->dumb_mode = DEF_MAX_INT; defData->no_num = DEF_MAX_INT; }
#line 5521 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 289: /* comp_id_and_name: '-' $@52 T_STRING T_STRING  */
#line 1761 "def/def.y"
         {
            if (defData->callbacks->ComponentCbk)
              defData->Component.IdAndName((yyvsp[-1].string), (yyvsp[0].string));
         }
#line 5530 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 290: /* comp_net_list: %empty  */
#line 1767 "def/def.y"
        { }
#line 5536 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 291: /* comp_net_list: comp_net_list '*'  */
#line 1769 "def/def.y"
            {
              if (defData->callbacks->ComponentCbk)
                defData->Component.addNet("*");
            }
#line 5545 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 292: /* comp_net_list: comp_net_list T_STRING  */
#line 1774 "def/def.y"
            {
              if (defData->callbacks->ComponentCbk)
                defData->Component.addNet((yyvsp[0].string));
            }
#line 5554 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 307: /* comp_extension_stmt: extension_stmt  */
#line 1789 "def/def.y"
        {
          if (defData->callbacks->ComponentCbk)
            CALLBACK(defData->callbacks->ComponentExtCbk, defrComponentExtCbkType,
                     &defData->History_text[0]);
        }
#line 5564 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 308: /* $@53: %empty  */
#line 1795 "def/def.y"
                          {defData->dumb_mode=1; defData->no_num = 1; }
#line 5570 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 309: /* comp_eeq: '+' K_EEQMASTER $@53 T_STRING  */
#line 1796 "def/def.y"
        {
          if (defData->callbacks->ComponentCbk)
            defData->Component.setEEQ((yyvsp[0].string));
        }
#line 5579 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 310: /* $@54: %empty  */
#line 1801 "def/def.y"
                              { defData->dumb_mode = 2;  defData->no_num = 2; }
#line 5585 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 311: /* comp_generate: '+' K_COMP_GEN $@54 T_STRING opt_pattern  */
#line 1803 "def/def.y"
        {
          if (defData->callbacks->ComponentCbk)
             defData->Component.setGenerate((yyvsp[-1].string), (yyvsp[0].string));
        }
#line 5594 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 312: /* opt_pattern: %empty  */
#line 1809 "def/def.y"
      { (yyval.string) = (char*)""; }
#line 5600 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 313: /* opt_pattern: T_STRING  */
#line 1811 "def/def.y"
      { (yyval.string) = (yyvsp[0].string); }
#line 5606 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 314: /* comp_source: '+' K_SOURCE source_type  */
#line 1814 "def/def.y"
        {
          if (defData->callbacks->ComponentCbk)
            defData->Component.setSource((yyvsp[0].string));
        }
#line 5615 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 315: /* source_type: K_NETLIST  */
#line 1820 "def/def.y"
            { (yyval.string) = (char*)"NETLIST"; }
#line 5621 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 316: /* source_type: K_DIST  */
#line 1822 "def/def.y"
            { (yyval.string) = (char*)"DIST"; }
#line 5627 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 317: /* source_type: K_USER  */
#line 1824 "def/def.y"
            { (yyval.string) = (char*)"USER"; }
#line 5633 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 318: /* source_type: K_TIMING  */
#line 1826 "def/def.y"
            { (yyval.string) = (char*)"TIMING"; }
#line 5639 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 319: /* comp_region: comp_region_start comp_pnt_list  */
#line 1831 "def/def.y"
        { }
#line 5645 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 320: /* comp_region: comp_region_start T_STRING  */
#line 1833 "def/def.y"
        {
          if (defData->callbacks->ComponentCbk)
            defData->Component.setRegionName((yyvsp[0].string));
        }
#line 5654 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 321: /* comp_pnt_list: pt pt  */
#line 1839 "def/def.y"
        { 
          // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
          if (defData->VersionNum < 5.5) {
            if (defData->callbacks->ComponentCbk)
               defData->Component.setRegionBounds((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, 
                                                            (yyvsp[0].pt).x, (yyvsp[0].pt).y);
          }
          else
            defData->defWarning(7020, "The REGION pt pt statement is obsolete in version 5.5 and later.\nThe DEF parser will ignore this statement.");
        }
#line 5669 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 322: /* comp_pnt_list: comp_pnt_list pt pt  */
#line 1850 "def/def.y"
        { 
          // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
          if (defData->VersionNum < 5.5) {
            if (defData->callbacks->ComponentCbk)
               defData->Component.setRegionBounds((yyvsp[-1].pt).x, (yyvsp[-1].pt).y,
                                                            (yyvsp[0].pt).x, (yyvsp[0].pt).y);
          }
          else
            defData->defWarning(7020, "The REGION pt pt statement is obsolete in version 5.5 and later.\nThe DEF parser will ignore this statement.");
        }
#line 5684 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 323: /* $@55: %empty  */
#line 1862 "def/def.y"
        {
          if (defData->VersionNum < 5.6) {
             if (defData->callbacks->ComponentCbk) {
               if (defData->componentWarnings++ < defData->settings->ComponentWarnings) {
                 defData->defMsg = (char*)malloc(1000);
                 sprintf (defData->defMsg,
                    "The HALO statement is a version 5.6 and later syntax.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                 defData->defError(6529, defData->defMsg);
                 free(defData->defMsg);
                 CHKERR();
               }
             }
          }
        }
#line 5703 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 324: /* comp_halo: '+' K_HALO $@55 halo_soft NUMBER NUMBER NUMBER NUMBER  */
#line 1877 "def/def.y"
        {
          if (defData->callbacks->ComponentCbk)
            defData->Component.setHalo((int)(yyvsp[-3].dval), (int)(yyvsp[-2].dval),
                                                 (int)(yyvsp[-1].dval), (int)(yyvsp[0].dval));
        }
#line 5713 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 326: /* halo_soft: K_SOFT  */
#line 1885 "def/def.y"
      {
        if (defData->VersionNum < 5.7) {
           if (defData->callbacks->ComponentCbk) {
             if (defData->componentWarnings++ < defData->settings->ComponentWarnings) {
                defData->defMsg = (char*)malloc(10000);
                sprintf (defData->defMsg,
                  "The HALO SOFT is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                defData->defError(6550, defData->defMsg);
                free(defData->defMsg);
                CHKERR();
             }
           }
        } else {
           if (defData->callbacks->ComponentCbk)
             defData->Component.setHaloSoft();
        }
      }
#line 5735 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 327: /* $@56: %empty  */
#line 1904 "def/def.y"
                                       { defData->dumb_mode = 2; defData->no_num = 2; }
#line 5741 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 328: /* comp_routehalo: '+' K_ROUTEHALO NUMBER $@56 T_STRING T_STRING  */
#line 1905 "def/def.y"
      {
        if (defData->VersionNum < 5.7) {
           if (defData->callbacks->ComponentCbk) {
             if (defData->componentWarnings++ < defData->settings->ComponentWarnings) {
                defData->defMsg = (char*)malloc(10000);
                sprintf (defData->defMsg,
                  "The ROUTEHALO is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                defData->defError(6551, defData->defMsg);
                free(defData->defMsg);
                CHKERR();
             }
           }
        } else {
           if (defData->callbacks->ComponentCbk)
             defData->Component.setRouteHalo(
                            (int)(yyvsp[-3].dval), (yyvsp[-1].string), (yyvsp[0].string));
        }
      }
#line 5764 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 329: /* $@57: %empty  */
#line 1924 "def/def.y"
                              { defData->dumb_mode = DEF_MAX_INT; }
#line 5770 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 330: /* comp_property: '+' K_PROPERTY $@57 comp_prop_list  */
#line 1926 "def/def.y"
      { defData->dumb_mode = 0; }
#line 5776 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 333: /* comp_prop: T_STRING NUMBER  */
#line 1933 "def/def.y"
        {
          if (defData->callbacks->ComponentCbk) {
            char propTp;
            char* str = defData->ringCopy("                       ");
            propTp = defData->session->CompProp.propType((yyvsp[-1].string));
            CHKPROPTYPE(propTp, (yyvsp[-1].string), "COMPONENT");
            sprintf(str, "%g", (yyvsp[0].dval));
            defData->Component.addNumProperty((yyvsp[-1].string), (yyvsp[0].dval), str, propTp);
          }
        }
#line 5791 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 334: /* comp_prop: T_STRING QSTRING  */
#line 1944 "def/def.y"
        {
          if (defData->callbacks->ComponentCbk) {
            char propTp;
            propTp = defData->session->CompProp.propType((yyvsp[-1].string));
            CHKPROPTYPE(propTp, (yyvsp[-1].string), "COMPONENT");
            defData->Component.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
          }
        }
#line 5804 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 335: /* comp_prop: T_STRING T_STRING  */
#line 1953 "def/def.y"
        {
          if (defData->callbacks->ComponentCbk) {
            char propTp;
            propTp = defData->session->CompProp.propType((yyvsp[-1].string));
            CHKPROPTYPE(propTp, (yyvsp[-1].string), "COMPONENT");
            defData->Component.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
          }
        }
#line 5817 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 336: /* comp_region_start: '+' K_REGION  */
#line 1963 "def/def.y"
        { defData->dumb_mode = 1; defData->no_num = 1; }
#line 5823 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 337: /* $@58: %empty  */
#line 1965 "def/def.y"
                            { defData->dumb_mode = 1; defData->no_num = 1; }
#line 5829 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 338: /* comp_foreign: '+' K_FOREIGN $@58 T_STRING opt_paren orient  */
#line 1967 "def/def.y"
        { 
          if (defData->VersionNum < 5.6) {
            if (defData->callbacks->ComponentCbk) {
              defData->Component.setForeignName((yyvsp[-2].string));
              defData->Component.setForeignLocation((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].integer));
            }
         } else
            if (defData->callbacks->ComponentCbk)
              if (defData->componentWarnings++ < defData->settings->ComponentWarnings)
                defData->defWarning(7021, "The FOREIGN statement is obsolete in version 5.6 and later.\nThe DEF parser will ignore this statement.");
         }
#line 5845 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 339: /* opt_paren: pt  */
#line 1981 "def/def.y"
         { (yyval.pt) = (yyvsp[0].pt); }
#line 5851 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 340: /* opt_paren: NUMBER NUMBER  */
#line 1983 "def/def.y"
         { (yyval.pt).x = ROUND((yyvsp[-1].dval)); (yyval.pt).y = ROUND((yyvsp[0].dval)); }
#line 5857 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 341: /* comp_type: placement_status pt orient  */
#line 1986 "def/def.y"
        {
          if (defData->callbacks->ComponentCbk) {
            defData->Component.setPlacementStatus((yyvsp[-2].integer));
            defData->Component.setPlacementLocation((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].integer));
          }
        }
#line 5868 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 342: /* comp_type: '+' K_UNPLACED  */
#line 1993 "def/def.y"
        {
          if (defData->callbacks->ComponentCbk)
            defData->Component.setPlacementStatus(
                                         DEFI_COMPONENT_UNPLACED);
            defData->Component.setPlacementLocation(-1, -1, -1);
        }
#line 5879 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 343: /* comp_type: '+' K_UNPLACED pt orient  */
#line 2000 "def/def.y"
        {
          if (defData->VersionNum < 5.4) {   // PCR 495463 
            if (defData->callbacks->ComponentCbk) {
              defData->Component.setPlacementStatus(
                                          DEFI_COMPONENT_UNPLACED);
              defData->Component.setPlacementLocation((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].integer));
            }
          } else {
            if (defData->componentWarnings++ < defData->settings->ComponentWarnings)
               defData->defWarning(7022, "In the COMPONENT UNPLACED statement, point and orient are invalid in version 5.4 and later.\nThe DEF parser will ignore this statement.");
          }
        }
#line 5896 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 344: /* $@59: %empty  */
#line 2014 "def/def.y"
                           { defData->dumb_mode = 1; defData->no_num = 1; }
#line 5902 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 345: /* maskShift: '+' K_MASKSHIFT $@59 T_STRING  */
#line 2015 "def/def.y"
        {  
          if (defData->callbacks->ComponentCbk) {
            if (defData->validateMaskShiftInput((yyvsp[0].string), defData->componentWarnings, defData->settings->ComponentWarnings)) {
                defData->Component.setMaskShift((yyvsp[0].string));
            }
          }
        }
#line 5914 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 346: /* placement_status: '+' K_FIXED  */
#line 2024 "def/def.y"
        { (yyval.integer) = DEFI_COMPONENT_FIXED; }
#line 5920 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 347: /* placement_status: '+' K_COVER  */
#line 2026 "def/def.y"
        { (yyval.integer) = DEFI_COMPONENT_COVER; }
#line 5926 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 348: /* placement_status: '+' K_PLACED  */
#line 2028 "def/def.y"
        { (yyval.integer) = DEFI_COMPONENT_PLACED; }
#line 5932 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 349: /* weight: '+' K_WEIGHT NUMBER  */
#line 2031 "def/def.y"
        {
          if (defData->callbacks->ComponentCbk)
            defData->Component.setWeight(ROUND((yyvsp[0].dval)));
        }
#line 5941 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 350: /* end_comps: K_END K_COMPS  */
#line 2037 "def/def.y"
        { 
          if (defData->callbacks->ComponentCbk)
            CALLBACK(defData->callbacks->ComponentEndCbk, defrComponentEndCbkType, 0);
        }
#line 5950 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 352: /* start_nets: K_NETS NUMBER ';'  */
#line 2046 "def/def.y"
        { 
          if (defData->callbacks->NetStartCbk)
            CALLBACK(defData->callbacks->NetStartCbk, defrNetStartCbkType, ROUND((yyvsp[-1].dval)));
          defData->netOsnet = 1;
        }
#line 5960 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 355: /* one_net: net_and_connections net_options ';'  */
#line 2057 "def/def.y"
        { 
          if (defData->callbacks->NetCbk)
            CALLBACK(defData->callbacks->NetCbk, defrNetCbkType, &defData->Net);
        }
#line 5969 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 356: /* net_and_connections: net_start  */
#line 2068 "def/def.y"
        {defData->dumb_mode = 0; defData->no_num = 0; }
#line 5975 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 357: /* $@60: %empty  */
#line 2071 "def/def.y"
               {defData->dumb_mode = DEF_MAX_INT; defData->no_num = DEF_MAX_INT; defData->nondef_is_keyword = TRUE; defData->mustjoin_is_keyword = TRUE;}
#line 5981 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 359: /* $@61: %empty  */
#line 2074 "def/def.y"
        {
          // 9/22/1999 
          // this is shared by both net and special net 
          if ((defData->callbacks->NetCbk && (defData->netOsnet==1)) || (defData->callbacks->SNetCbk && (defData->netOsnet==2)))
            defData->Net.setName((yyvsp[0].string));
          if (defData->callbacks->NetNameCbk)
            CALLBACK(defData->callbacks->NetNameCbk, defrNetNameCbkType, (yyvsp[0].string));
        }
#line 5994 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 361: /* $@62: %empty  */
#line 2082 "def/def.y"
                                  {defData->dumb_mode = 1; defData->no_num = 1;}
#line 6000 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 362: /* net_name: K_MUSTJOIN '(' T_STRING $@62 T_STRING ')'  */
#line 2083 "def/def.y"
        {
          if ((defData->callbacks->NetCbk && (defData->netOsnet==1)) || (defData->callbacks->SNetCbk && (defData->netOsnet==2)))
            defData->Net.addMustPin((yyvsp[-3].string), (yyvsp[-1].string), 0);
          defData->dumb_mode = 3;
          defData->no_num = 3;
        }
#line 6011 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 365: /* $@63: %empty  */
#line 2094 "def/def.y"
                             {defData->dumb_mode = DEF_MAX_INT; defData->no_num = DEF_MAX_INT;}
#line 6017 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 366: /* net_connection: '(' T_STRING $@63 T_STRING conn_opt ')'  */
#line 2096 "def/def.y"
        {
          // 9/22/1999 
          // since the code is shared by both net & special net, 
          // need to check on both flags 
          if ((defData->callbacks->NetCbk && (defData->netOsnet==1)) || (defData->callbacks->SNetCbk && (defData->netOsnet==2)))
            defData->Net.addPin((yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[-1].integer));
          // 1/14/2000 - pcr 289156 
          // reset defData->dumb_mode & defData->no_num to 3 , just in case 
          // the next statement is another net_connection 
          defData->dumb_mode = 3;
          defData->no_num = 3;
        }
#line 6034 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 367: /* $@64: %empty  */
#line 2108 "def/def.y"
                  {defData->dumb_mode = 1; defData->no_num = 1;}
#line 6040 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 368: /* net_connection: '(' '*' $@64 T_STRING conn_opt ')'  */
#line 2109 "def/def.y"
        {
          if ((defData->callbacks->NetCbk && (defData->netOsnet==1)) || (defData->callbacks->SNetCbk && (defData->netOsnet==2)))
            defData->Net.addPin("*", (yyvsp[-2].string), (yyvsp[-1].integer));
          defData->dumb_mode = 3;
          defData->no_num = 3;
        }
#line 6051 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 369: /* $@65: %empty  */
#line 2115 "def/def.y"
                    {defData->dumb_mode = 1; defData->no_num = 1;}
#line 6057 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 370: /* net_connection: '(' K_PIN $@65 T_STRING conn_opt ')'  */
#line 2116 "def/def.y"
        {
          if ((defData->callbacks->NetCbk && (defData->netOsnet==1)) || (defData->callbacks->SNetCbk && (defData->netOsnet==2)))
            defData->Net.addPin("PIN", (yyvsp[-2].string), (yyvsp[-1].integer));
          defData->dumb_mode = 3;
          defData->no_num = 3;
        }
#line 6068 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 371: /* conn_opt: %empty  */
#line 2124 "def/def.y"
          { (yyval.integer) = 0; }
#line 6074 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 372: /* conn_opt: extension_stmt  */
#line 2126 "def/def.y"
        {
          if (defData->callbacks->NetConnectionExtCbk)
            CALLBACK(defData->callbacks->NetConnectionExtCbk, defrNetConnectionExtCbkType,
              &defData->History_text[0]);
          (yyval.integer) = 0;
        }
#line 6085 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 373: /* conn_opt: '+' K_SYNTHESIZED  */
#line 2133 "def/def.y"
        { (yyval.integer) = 1; }
#line 6091 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 376: /* $@66: %empty  */
#line 2142 "def/def.y"
        {  
          if (defData->callbacks->NetCbk) defData->Net.addWire((yyvsp[0].string), NULL);
        }
#line 6099 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 377: /* net_option: '+' net_type $@66 paths  */
#line 2146 "def/def.y"
        {
          defData->by_is_keyword = FALSE;
          defData->do_is_keyword = FALSE;
          defData->new_is_keyword = FALSE;
          defData->nondef_is_keyword = FALSE;
          defData->mustjoin_is_keyword = FALSE;
          defData->step_is_keyword = FALSE;
          defData->orient_is_keyword = FALSE;
          defData->virtual_is_keyword = FALSE;
          defData->rect_is_keyword = FALSE;
          defData->mask_is_keyword = FALSE;
          defData->needNPCbk = 0;
        }
#line 6117 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 378: /* net_option: '+' K_SOURCE netsource_type  */
#line 2161 "def/def.y"
        { if (defData->callbacks->NetCbk) defData->Net.setSource((yyvsp[0].string)); }
#line 6123 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 379: /* net_option: '+' K_FIXEDBUMP  */
#line 2164 "def/def.y"
        {
          if (defData->VersionNum < 5.5) {
            if (defData->callbacks->NetCbk) {
              if (defData->netWarnings++ < defData->settings->NetWarnings) {
                 defData->defMsg = (char*)malloc(1000);
                 sprintf (defData->defMsg,
                    "The FIXEDBUMP statement is available in version 5.5 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                 defData->defError(6530, defData->defMsg);
                 free(defData->defMsg);
                 CHKERR();
              }
            }
          }
          if (defData->callbacks->NetCbk) defData->Net.setFixedbump();
        }
#line 6143 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 380: /* $@67: %empty  */
#line 2180 "def/def.y"
                          { defData->real_num = 1; }
#line 6149 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 381: /* net_option: '+' K_FREQUENCY $@67 NUMBER  */
#line 2181 "def/def.y"
        {
          if (defData->VersionNum < 5.5) {
            if (defData->callbacks->NetCbk) {
              if (defData->netWarnings++ < defData->settings->NetWarnings) {
                 defData->defMsg = (char*)malloc(1000);
                 sprintf (defData->defMsg,
                    "The FREQUENCY statement is a version 5.5 and later syntax.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
                 defData->defError(6558, defData->defMsg);
                 free(defData->defMsg);
                 CHKERR();
              }
            }
          }
          if (defData->callbacks->NetCbk) defData->Net.setFrequency((yyvsp[0].dval));
          defData->real_num = 0;
        }
#line 6170 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 382: /* $@68: %empty  */
#line 2198 "def/def.y"
                         {defData->dumb_mode = 1; defData->no_num = 1;}
#line 6176 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 383: /* net_option: '+' K_ORIGINAL $@68 T_STRING  */
#line 2199 "def/def.y"
        { if (defData->callbacks->NetCbk) defData->Net.setOriginal((yyvsp[0].string)); }
#line 6182 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 384: /* net_option: '+' K_PATTERN pattern_type  */
#line 2202 "def/def.y"
        { if (defData->callbacks->NetCbk) defData->Net.setPattern((yyvsp[0].string)); }
#line 6188 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 385: /* net_option: '+' K_WEIGHT NUMBER  */
#line 2205 "def/def.y"
        { if (defData->callbacks->NetCbk) defData->Net.setWeight(ROUND((yyvsp[0].dval))); }
#line 6194 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 386: /* net_option: '+' K_XTALK NUMBER  */
#line 2208 "def/def.y"
        { if (defData->callbacks->NetCbk) defData->Net.setXTalk(ROUND((yyvsp[0].dval))); }
#line 6200 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 387: /* net_option: '+' K_ESTCAP NUMBER  */
#line 2211 "def/def.y"
        { if (defData->callbacks->NetCbk) defData->Net.setCap((yyvsp[0].dval)); }
#line 6206 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 388: /* net_option: '+' K_USE use_type  */
#line 2214 "def/def.y"
        { if (defData->callbacks->NetCbk) defData->Net.setUse((yyvsp[0].string)); }
#line 6212 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 389: /* net_option: '+' K_STYLE NUMBER  */
#line 2217 "def/def.y"
        { if (defData->callbacks->NetCbk) defData->Net.setStyle((int)(yyvsp[0].dval)); }
#line 6218 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 390: /* $@69: %empty  */
#line 2219 "def/def.y"
                               { defData->dumb_mode = 1; defData->no_num = 1; }
#line 6224 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 391: /* net_option: '+' K_NONDEFAULTRULE $@69 T_STRING  */
#line 2220 "def/def.y"
        { 
          if (defData->callbacks->NetCbk && defData->callbacks->NetNonDefaultRuleCbk) {
             // User wants a callback on nondefaultrule 
             CALLBACK(defData->callbacks->NetNonDefaultRuleCbk,
                      defrNetNonDefaultRuleCbkType, (yyvsp[0].string));
          }
          // Still save data in the class 
          if (defData->callbacks->NetCbk) defData->Net.setNonDefaultRule((yyvsp[0].string));
        }
#line 6238 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 393: /* $@70: %empty  */
#line 2232 "def/def.y"
                          { defData->dumb_mode = 1; defData->no_num = 1; }
#line 6244 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 394: /* net_option: '+' K_SHIELDNET $@70 T_STRING  */
#line 2233 "def/def.y"
        { if (defData->callbacks->NetCbk) defData->Net.addShieldNet((yyvsp[0].string)); }
#line 6250 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 395: /* $@71: %empty  */
#line 2235 "def/def.y"
                         { defData->dumb_mode = 1; defData->no_num = 1; }
#line 6256 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 396: /* $@72: %empty  */
#line 2236 "def/def.y"
        { // since the parser still support 5.3 and earlier, can't 
          // move NOSHIELD in net_type 
          if (defData->VersionNum < 5.4) {   // PCR 445209 
            if (defData->callbacks->NetCbk) defData->Net.addNoShield("");
            defData->by_is_keyword = FALSE;
            defData->do_is_keyword = FALSE;
            defData->new_is_keyword = FALSE;
            defData->step_is_keyword = FALSE;
            defData->orient_is_keyword = FALSE;
            defData->virtual_is_keyword = FALSE;
            defData->mask_is_keyword = FALSE;
            defData->rect_is_keyword = FALSE;
            defData->shield = TRUE;    // save the path info in the defData->shield paths 
          } else
            if (defData->callbacks->NetCbk) defData->Net.addWire("NOSHIELD", NULL);
        }
#line 6277 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 397: /* net_option: '+' K_NOSHIELD $@71 $@72 paths  */
#line 2253 "def/def.y"
        {
          if (defData->VersionNum < 5.4) {   // PCR 445209 
            defData->shield = FALSE;
            defData->by_is_keyword = FALSE;
            defData->do_is_keyword = FALSE;
            defData->new_is_keyword = FALSE;
            defData->step_is_keyword = FALSE;
            defData->nondef_is_keyword = FALSE;
            defData->mustjoin_is_keyword = FALSE;
            defData->orient_is_keyword = FALSE;
            defData->virtual_is_keyword = FALSE;
            defData->rect_is_keyword = FALSE;
            defData->mask_is_keyword = FALSE;
          } else {
            defData->by_is_keyword = FALSE;
            defData->do_is_keyword = FALSE;
            defData->new_is_keyword = FALSE;
            defData->step_is_keyword = FALSE;
            defData->nondef_is_keyword = FALSE;
            defData->mustjoin_is_keyword = FALSE;
            defData->orient_is_keyword = FALSE;
            defData->virtual_is_keyword = FALSE;
            defData->rect_is_keyword = FALSE;
            defData->mask_is_keyword = FALSE;
          }
          defData->needNPCbk = 0;
        }
#line 6309 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 398: /* $@73: %empty  */
#line 2282 "def/def.y"
        { defData->dumb_mode = 1; defData->no_num = 1;
          if (defData->callbacks->NetCbk) {
            defData->Subnet = new defiSubnet(defData);
          }
        }
#line 6319 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 399: /* $@74: %empty  */
#line 2287 "def/def.y"
                 {
          if (defData->callbacks->NetCbk && defData->callbacks->NetSubnetNameCbk) {
            // User wants a callback on Net subnetName 
            CALLBACK(defData->callbacks->NetSubnetNameCbk, defrNetSubnetNameCbkType, (yyvsp[0].string));
          }
          // Still save the subnet name in the class 
          if (defData->callbacks->NetCbk) {
            defData->Subnet->setName((yyvsp[0].string));
          }
        }
#line 6334 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 400: /* $@75: %empty  */
#line 2297 "def/def.y"
                   {
          defData->routed_is_keyword = TRUE;
          defData->fixed_is_keyword = TRUE;
          defData->cover_is_keyword = TRUE;
        }
#line 6344 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 401: /* net_option: '+' K_SUBNET $@73 T_STRING $@74 comp_names $@75 subnet_options  */
#line 2301 "def/def.y"
                         {
          if (defData->callbacks->NetCbk) {
            defData->Net.addSubnet(defData->Subnet);
            defData->Subnet = NULL;
            defData->routed_is_keyword = FALSE;
            defData->fixed_is_keyword = FALSE;
            defData->cover_is_keyword = FALSE;
          }
        }
#line 6358 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 402: /* $@76: %empty  */
#line 2311 "def/def.y"
                         {defData->dumb_mode = DEF_MAX_INT; }
#line 6364 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 403: /* net_option: '+' K_PROPERTY $@76 net_prop_list  */
#line 2313 "def/def.y"
        { defData->dumb_mode = 0; }
#line 6370 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 404: /* net_option: extension_stmt  */
#line 2316 "def/def.y"
        { 
          if (defData->callbacks->NetExtCbk)
            CALLBACK(defData->callbacks->NetExtCbk, defrNetExtCbkType, &defData->History_text[0]);
        }
#line 6379 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 407: /* net_prop: T_STRING NUMBER  */
#line 2326 "def/def.y"
        {
          if (defData->callbacks->NetCbk) {
            char propTp;
            char* str = defData->ringCopy("                       ");
            propTp = defData->session->NetProp.propType((yyvsp[-1].string));
            CHKPROPTYPE(propTp, (yyvsp[-1].string), "NET");
            sprintf(str, "%g", (yyvsp[0].dval));
            defData->Net.addNumProp((yyvsp[-1].string), (yyvsp[0].dval), str, propTp);
          }
        }
#line 6394 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 408: /* net_prop: T_STRING QSTRING  */
#line 2337 "def/def.y"
        {
          if (defData->callbacks->NetCbk) {
            char propTp;
            propTp = defData->session->NetProp.propType((yyvsp[-1].string));
            CHKPROPTYPE(propTp, (yyvsp[-1].string), "NET");
            defData->Net.addProp((yyvsp[-1].string), (yyvsp[0].string), propTp);
          }
        }
#line 6407 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 409: /* net_prop: T_STRING T_STRING  */
#line 2346 "def/def.y"
        {
          if (defData->callbacks->NetCbk) {
            char propTp;
            propTp = defData->session->NetProp.propType((yyvsp[-1].string));
            CHKPROPTYPE(propTp, (yyvsp[-1].string), "NET");
            defData->Net.addProp((yyvsp[-1].string), (yyvsp[0].string), propTp);
          }
        }
#line 6420 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 410: /* netsource_type: K_NETLIST  */
#line 2356 "def/def.y"
        { (yyval.string) = (char*)"NETLIST"; }
#line 6426 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 411: /* netsource_type: K_DIST  */
#line 2358 "def/def.y"
        { (yyval.string) = (char*)"DIST"; }
#line 6432 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 412: /* netsource_type: K_USER  */
#line 2360 "def/def.y"
        { (yyval.string) = (char*)"USER"; }
#line 6438 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 413: /* netsource_type: K_TIMING  */
#line 2362 "def/def.y"
        { (yyval.string) = (char*)"TIMING"; }
#line 6444 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 414: /* netsource_type: K_TEST  */
#line 2364 "def/def.y"
        { (yyval.string) = (char*)"TEST"; }
#line 6450 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 415: /* $@77: %empty  */
#line 2367 "def/def.y"
        {
          // vpin_options may have to deal with orient 
          defData->orient_is_keyword = TRUE;
        }
#line 6459 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 416: /* vpin_stmt: vpin_begin vpin_layer_opt pt pt $@77 vpin_options  */
#line 2372 "def/def.y"
        { if (defData->callbacks->NetCbk)
            defData->Net.addVpinBounds((yyvsp[-3].pt).x, (yyvsp[-3].pt).y, (yyvsp[-2].pt).x, (yyvsp[-2].pt).y);
          defData->orient_is_keyword = FALSE;
        }
#line 6468 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 417: /* $@78: %empty  */
#line 2377 "def/def.y"
                       {defData->dumb_mode = 1; defData->no_num = 1;}
#line 6474 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 418: /* vpin_begin: '+' K_VPIN $@78 T_STRING  */
#line 2378 "def/def.y"
        { if (defData->callbacks->NetCbk) defData->Net.addVpin((yyvsp[0].string)); }
#line 6480 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 420: /* $@79: %empty  */
#line 2381 "def/def.y"
                  {defData->dumb_mode=1;}
#line 6486 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 421: /* vpin_layer_opt: K_LAYER $@79 T_STRING  */
#line 2382 "def/def.y"
        { if (defData->callbacks->NetCbk) defData->Net.addVpinLayer((yyvsp[0].string)); }
#line 6492 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 423: /* vpin_options: vpin_status pt orient  */
#line 2386 "def/def.y"
        { if (defData->callbacks->NetCbk) defData->Net.addVpinLoc((yyvsp[-2].string), (yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].integer)); }
#line 6498 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 424: /* vpin_status: K_PLACED  */
#line 2389 "def/def.y"
        { (yyval.string) = (char*)"PLACED"; }
#line 6504 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 425: /* vpin_status: K_FIXED  */
#line 2391 "def/def.y"
        { (yyval.string) = (char*)"FIXED"; }
#line 6510 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 426: /* vpin_status: K_COVER  */
#line 2393 "def/def.y"
        { (yyval.string) = (char*)"COVER"; }
#line 6516 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 427: /* net_type: K_FIXED  */
#line 2396 "def/def.y"
        { (yyval.string) = (char*)"FIXED"; defData->dumb_mode = 1; }
#line 6522 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 428: /* net_type: K_COVER  */
#line 2398 "def/def.y"
        { (yyval.string) = (char*)"COVER"; defData->dumb_mode = 1; }
#line 6528 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 429: /* net_type: K_ROUTED  */
#line 2400 "def/def.y"
        { (yyval.string) = (char*)"ROUTED"; defData->dumb_mode = 1; }
#line 6534 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 430: /* paths: path  */
#line 2404 "def/def.y"
      { if (defData->NeedPathData && defData->callbacks->NetCbk)
          defData->pathIsDone(defData->shield, 0, defData->netOsnet, &defData->needNPCbk);
      }
#line 6542 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 431: /* paths: paths new_path  */
#line 2408 "def/def.y"
      { }
#line 6548 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 432: /* $@80: %empty  */
#line 2410 "def/def.y"
                { defData->dumb_mode = 1; }
#line 6554 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 433: /* new_path: K_NEW $@80 path  */
#line 2411 "def/def.y"
      { if (defData->NeedPathData && defData->callbacks->NetCbk)
          defData->pathIsDone(defData->shield, 0, defData->netOsnet, &defData->needNPCbk);
      }
#line 6562 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 434: /* $@81: %empty  */
#line 2416 "def/def.y"
      {
        if ((strcmp((yyvsp[0].string), "TAPER") == 0) || (strcmp((yyvsp[0].string), "TAPERRULE") == 0)) {
          if (defData->NeedPathData && defData->callbacks->NetCbk) {
            if (defData->netWarnings++ < defData->settings->NetWarnings) {
              defData->defError(6531, "The layerName which is required in path is missing. Include the layerName in the path and then try again.");
              CHKERR();
            }
          }
          // Since there is already error, the next token is insignificant 
          defData->dumb_mode = 1; defData->no_num = 1;
        } else {
          // CCR 766289 - Do not accummulate the layer information if there 
          // is not a callback set 
          if (defData->NeedPathData && defData->callbacks->NetCbk)
              defData->PathObj.addLayer((yyvsp[0].string));
          defData->dumb_mode = 0; defData->no_num = 0;
        }
      }
#line 6585 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 435: /* $@82: %empty  */
#line 2435 "def/def.y"
      { defData->dumb_mode = DEF_MAX_INT; defData->by_is_keyword = TRUE; defData->do_is_keyword = TRUE;
/*
       dumb_mode = 1; by_is_keyword = TRUE; do_is_keyword = TRUE;
*/
        defData->new_is_keyword = TRUE; defData->step_is_keyword = TRUE; 
        defData->orient_is_keyword = TRUE; defData->virtual_is_keyword = TRUE;
        defData->mask_is_keyword = TRUE, defData->rect_is_keyword = TRUE;  }
#line 6597 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 436: /* path: T_STRING $@81 opt_taper_style_s path_pt $@82 path_item_list  */
#line 2445 "def/def.y"
      { defData->dumb_mode = 0;   defData->virtual_is_keyword = FALSE; defData->mask_is_keyword = FALSE,
       defData->rect_is_keyword = FALSE; }
#line 6604 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 437: /* virtual_statement: K_VIRTUAL virtual_pt  */
#line 2450 "def/def.y"
    {
      if (defData->VersionNum < 5.8) {
              if (defData->callbacks->SNetCbk) {
                if (defData->sNetWarnings++ < defData->settings->SNetWarnings) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The VIRTUAL statement is available in version 5.8 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
                  defData->defError(6536, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
          }
    }
#line 6623 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 438: /* rect_statement: K_RECT rect_pts  */
#line 2467 "def/def.y"
    {
      if (defData->VersionNum < 5.8) {
              if (defData->callbacks->SNetCbk) {
                if (defData->sNetWarnings++ < defData->settings->SNetWarnings) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The RECT statement is available in version 5.8 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
                  defData->defError(6536, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
      }
    }
#line 6642 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 441: /* path_item: T_STRING  */
#line 2490 "def/def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
            (defData->callbacks->SNetCbk && (defData->netOsnet==2)))) {
          if (strcmp((yyvsp[0].string), "TAPER") == 0)
            defData->PathObj.setTaper();
          else {
            defData->PathObj.addVia((yyvsp[0].string));
            }
        }
      }
#line 6657 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 442: /* path_item: K_MASK NUMBER T_STRING  */
#line 2501 "def/def.y"
      {
        if (defData->validateMaskInput((int)(yyvsp[-1].dval), defData->sNetWarnings, defData->settings->SNetWarnings)) {
            if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
                (defData->callbacks->SNetCbk && (defData->netOsnet==2)))) {
              if (strcmp((yyvsp[0].string), "TAPER") == 0)
                defData->PathObj.setTaper();
              else {
                defData->PathObj.addViaMask((yyvsp[-1].dval));
                defData->PathObj.addVia((yyvsp[0].string));
                }
            }
        }
      }
#line 6675 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 443: /* path_item: T_STRING orient  */
#line 2515 "def/def.y"
      { if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
            (defData->callbacks->SNetCbk && (defData->netOsnet==2)))) {
            defData->PathObj.addVia((yyvsp[-1].string));
            defData->PathObj.addViaRotation((yyvsp[0].integer));
        }
      }
#line 6686 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 444: /* path_item: K_MASK NUMBER T_STRING orient  */
#line 2522 "def/def.y"
      { 
        if (defData->validateMaskInput((int)(yyvsp[-2].dval), defData->sNetWarnings, defData->settings->SNetWarnings)) {
            if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
                (defData->callbacks->SNetCbk && (defData->netOsnet==2)))) {
                defData->PathObj.addViaMask((yyvsp[-2].dval));
                defData->PathObj.addVia((yyvsp[-1].string));
                defData->PathObj.addViaRotation((yyvsp[0].integer));
            }
        }
      }
#line 6701 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 445: /* path_item: K_MASK NUMBER T_STRING K_DO NUMBER K_BY NUMBER K_STEP NUMBER NUMBER  */
#line 2533 "def/def.y"
      {
        if (defData->validateMaskInput((int)(yyvsp[-8].dval), defData->sNetWarnings, defData->settings->SNetWarnings)) {      
            if (((yyvsp[-5].dval) == 0) || ((yyvsp[-3].dval) == 0)) {
              if (defData->NeedPathData &&
                  defData->callbacks->SNetCbk) {
                if (defData->netWarnings++ < defData->settings->NetWarnings) {
                  defData->defError(6533, "Either the numX or numY in the VIA DO statement has the value. The value specified is 0.\nUpdate your DEF file with the correct value and then try again.\n");
                  CHKERR();
                }
              }
            }
            if (defData->NeedPathData && (defData->callbacks->SNetCbk && (defData->netOsnet==2))) {
                defData->PathObj.addViaMask((yyvsp[-8].dval));
                defData->PathObj.addVia((yyvsp[-7].string));
                defData->PathObj.addViaData((int)(yyvsp[-5].dval), (int)(yyvsp[-3].dval), (int)(yyvsp[-1].dval), (int)(yyvsp[0].dval));
            }  else if (defData->NeedPathData && (defData->callbacks->NetCbk && (defData->netOsnet==1))) {
              if (defData->netWarnings++ < defData->settings->NetWarnings) {
                defData->defError(6567, "The VIA DO statement is defined in the NET statement and is invalid.\nRemove this statement from your DEF file and try again.");
                CHKERR();
              }
            }
        }
      }
#line 6729 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 446: /* path_item: T_STRING K_DO NUMBER K_BY NUMBER K_STEP NUMBER NUMBER  */
#line 2557 "def/def.y"
      {
        if (defData->VersionNum < 5.5) {
          if (defData->NeedPathData && 
              defData->callbacks->SNetCbk) {
            if (defData->netWarnings++ < defData->settings->NetWarnings) {
              defData->defMsg = (char*)malloc(1000);
              sprintf (defData->defMsg,
                 "The VIA DO statement is available in version 5.5 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
              defData->defError(6532, defData->defMsg);
              free(defData->defMsg);
              CHKERR();
            }
          }
        }
        if (((yyvsp[-5].dval) == 0) || ((yyvsp[-3].dval) == 0)) {
          if (defData->NeedPathData &&
              defData->callbacks->SNetCbk) {
            if (defData->netWarnings++ < defData->settings->NetWarnings) {
              defData->defError(6533, "Either the numX or numY in the VIA DO statement has the value. The value specified is 0.\nUpdate your DEF file with the correct value and then try again.\n");
              CHKERR();
            }
          }
        }
        if (defData->NeedPathData && (defData->callbacks->SNetCbk && (defData->netOsnet==2))) {
            defData->PathObj.addVia((yyvsp[-7].string));
            defData->PathObj.addViaData((int)(yyvsp[-5].dval), (int)(yyvsp[-3].dval), (int)(yyvsp[-1].dval), (int)(yyvsp[0].dval));
        }  else if (defData->NeedPathData && (defData->callbacks->NetCbk && (defData->netOsnet==1))) {
          if (defData->netWarnings++ < defData->settings->NetWarnings) {
            defData->defError(6567, "The VIA DO statement is defined in the NET statement and is invalid.\nRemove this statement from your DEF file and try again.");
            CHKERR();
          }
        }
      }
#line 6767 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 447: /* path_item: T_STRING orient K_DO NUMBER K_BY NUMBER K_STEP NUMBER NUMBER  */
#line 2591 "def/def.y"
      {
        if (defData->VersionNum < 5.5) {
          if (defData->NeedPathData &&
              defData->callbacks->SNetCbk) {
            if (defData->netWarnings++ < defData->settings->NetWarnings) {
              defData->defMsg = (char*)malloc(1000);
              sprintf (defData->defMsg,
                 "The VIA DO statement is available in version 5.5 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
              defData->defError(6532, defData->defMsg);
              CHKERR();
            }
          }
        }
        if (((yyvsp[-5].dval) == 0) || ((yyvsp[-3].dval) == 0)) {
          if (defData->NeedPathData &&
              defData->callbacks->SNetCbk) {
            if (defData->netWarnings++ < defData->settings->NetWarnings) {
              defData->defError(6533, "Either the numX or numY in the VIA DO statement has the value. The value specified is 0.\nUpdate your DEF file with the correct value and then try again.\n");
              CHKERR();
            }
          }
        }
        if (defData->NeedPathData && (defData->callbacks->SNetCbk && (defData->netOsnet==2))) {
            defData->PathObj.addVia((yyvsp[-8].string));
            defData->PathObj.addViaRotation((yyvsp[-7].integer));
            defData->PathObj.addViaData((int)(yyvsp[-5].dval), (int)(yyvsp[-3].dval), (int)(yyvsp[-1].dval), (int)(yyvsp[0].dval));
        } else if (defData->NeedPathData && (defData->callbacks->NetCbk && (defData->netOsnet==1))) {
          if (defData->netWarnings++ < defData->settings->NetWarnings) {
            defData->defError(6567, "The VIA DO statement is defined in the NET statement and is invalid.\nRemove this statement from your DEF file and try again.");
            CHKERR();
          }
        }
      }
#line 6805 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 448: /* path_item: K_MASK NUMBER T_STRING orient K_DO NUMBER K_BY NUMBER K_STEP NUMBER NUMBER  */
#line 2625 "def/def.y"
      {
        if (defData->validateMaskInput((int)(yyvsp[-9].dval), defData->sNetWarnings, defData->settings->SNetWarnings)) {
            if (((yyvsp[-5].dval) == 0) || ((yyvsp[-3].dval) == 0)) {
              if (defData->NeedPathData &&
                  defData->callbacks->SNetCbk) {
                if (defData->netWarnings++ < defData->settings->NetWarnings) {
                  defData->defError(6533, "Either the numX or numY in the VIA DO statement has the value. The value specified is 0.\nUpdate your DEF file with the correct value and then try again.\n");
                  CHKERR();
                }
              }
            }
            if (defData->NeedPathData && (defData->callbacks->SNetCbk && (defData->netOsnet==2))) {
                defData->PathObj.addViaMask((yyvsp[-9].dval)); 
                defData->PathObj.addVia((yyvsp[-8].string));
                defData->PathObj.addViaRotation((yyvsp[-7].integer));;
                defData->PathObj.addViaData((int)(yyvsp[-5].dval), (int)(yyvsp[-3].dval), (int)(yyvsp[-1].dval), (int)(yyvsp[0].dval));
            } else if (defData->NeedPathData && (defData->callbacks->NetCbk && (defData->netOsnet==1))) {
              if (defData->netWarnings++ < defData->settings->NetWarnings) {
                defData->defError(6567, "The VIA DO statement is defined in the NET statement and is invalid.\nRemove this statement from your DEF file and try again.");
                CHKERR();
              }
            }
        }
      }
#line 6834 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 451: /* $@83: %empty  */
#line 2651 "def/def.y"
                          { defData->dumb_mode = 6; }
#line 6840 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 452: /* path_item: K_MASK NUMBER K_RECT $@83 '(' NUMBER NUMBER NUMBER NUMBER ')'  */
#line 2652 "def/def.y"
    {
      if (defData->validateMaskInput((int)(yyvsp[-8].dval), defData->sNetWarnings, defData->settings->SNetWarnings)) {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2)))) {
          defData->PathObj.addMask((yyvsp[-8].dval));
          defData->PathObj.addViaRect((yyvsp[-4].dval), (yyvsp[-3].dval), (yyvsp[-2].dval), (yyvsp[-1].dval));
        }
      }
    }
#line 6854 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 453: /* $@84: %empty  */
#line 2662 "def/def.y"
    {
       if (defData->validateMaskInput((int)(yyvsp[0].dval), defData->sNetWarnings, defData->settings->SNetWarnings)) {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2)))) {
          defData->PathObj.addMask((yyvsp[0].dval)); 
        }
       }  
    }
#line 6867 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 455: /* path_item: path_pt  */
#line 2672 "def/def.y"
    {
       // reset defData->dumb_mode to 1 just incase the next token is a via of the path
        // 2/5/2004 - pcr 686781
        defData->dumb_mode = DEF_MAX_INT; defData->by_is_keyword = TRUE; defData->do_is_keyword = TRUE;
        defData->new_is_keyword = TRUE; defData->step_is_keyword = TRUE;
        defData->orient_is_keyword = TRUE;
    }
#line 6879 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 456: /* path_pt: '(' NUMBER NUMBER ')'  */
#line 2683 "def/def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addPoint(ROUND((yyvsp[-2].dval)), ROUND((yyvsp[-1].dval))); 
        defData->save_x = (yyvsp[-2].dval);
        defData->save_y = (yyvsp[-1].dval); 
      }
#line 6891 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 457: /* path_pt: '(' '*' NUMBER ')'  */
#line 2691 "def/def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addPoint(ROUND(defData->save_x), ROUND((yyvsp[-1].dval))); 
        defData->save_y = (yyvsp[-1].dval);
      }
#line 6902 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 458: /* path_pt: '(' NUMBER '*' ')'  */
#line 2698 "def/def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addPoint(ROUND((yyvsp[-2].dval)), ROUND(defData->save_y)); 
        defData->save_x = (yyvsp[-2].dval);
      }
#line 6913 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 459: /* path_pt: '(' '*' '*' ')'  */
#line 2705 "def/def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
            (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addPoint(ROUND(defData->save_x), ROUND(defData->save_y)); 
      }
#line 6923 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 460: /* path_pt: '(' NUMBER NUMBER NUMBER ')'  */
#line 2711 "def/def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
            (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addFlushPoint(ROUND((yyvsp[-3].dval)), ROUND((yyvsp[-2].dval)), ROUND((yyvsp[-1].dval))); 
        defData->save_x = (yyvsp[-3].dval);
        defData->save_y = (yyvsp[-2].dval);
      }
#line 6935 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 461: /* path_pt: '(' '*' NUMBER NUMBER ')'  */
#line 2719 "def/def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addFlushPoint(ROUND(defData->save_x), ROUND((yyvsp[-2].dval)),
          ROUND((yyvsp[-1].dval))); 
        defData->save_y = (yyvsp[-2].dval);
      }
#line 6947 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 462: /* path_pt: '(' NUMBER '*' NUMBER ')'  */
#line 2727 "def/def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addFlushPoint(ROUND((yyvsp[-3].dval)), ROUND(defData->save_y),
          ROUND((yyvsp[-1].dval))); 
        defData->save_x = (yyvsp[-3].dval);
      }
#line 6959 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 463: /* path_pt: '(' '*' '*' NUMBER ')'  */
#line 2735 "def/def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addFlushPoint(ROUND(defData->save_x), ROUND(defData->save_y),
          ROUND((yyvsp[-1].dval))); 
      }
#line 6970 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 464: /* virtual_pt: '(' NUMBER NUMBER ')'  */
#line 2744 "def/def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addVirtualPoint(ROUND((yyvsp[-2].dval)), ROUND((yyvsp[-1].dval))); 
        defData->save_x = (yyvsp[-2].dval);
        defData->save_y = (yyvsp[-1].dval);
      }
#line 6982 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 465: /* virtual_pt: '(' '*' NUMBER ')'  */
#line 2752 "def/def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addVirtualPoint(ROUND(defData->save_x), ROUND((yyvsp[-1].dval))); 
        defData->save_y = (yyvsp[-1].dval);
      }
#line 6993 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 466: /* virtual_pt: '(' NUMBER '*' ')'  */
#line 2759 "def/def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addVirtualPoint(ROUND((yyvsp[-2].dval)), ROUND(defData->save_y)); 
        defData->save_x = (yyvsp[-2].dval);
      }
#line 7004 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 467: /* virtual_pt: '(' '*' '*' ')'  */
#line 2766 "def/def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addVirtualPoint(ROUND(defData->save_x), ROUND(defData->save_y));
      }
#line 7014 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 468: /* rect_pts: '(' NUMBER NUMBER NUMBER NUMBER ')'  */
#line 2774 "def/def.y"
    {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2)))) {
          defData->PathObj.addViaRect((yyvsp[-4].dval), (yyvsp[-3].dval), (yyvsp[-2].dval), (yyvsp[-1].dval)); 
        }    
    }
#line 7025 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 473: /* opt_taper: K_TAPER  */
#line 2790 "def/def.y"
      { if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.setTaper(); }
#line 7033 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 474: /* $@85: %empty  */
#line 2793 "def/def.y"
                  { defData->dumb_mode = 1; }
#line 7039 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 475: /* opt_taper: K_TAPERRULE $@85 T_STRING  */
#line 2794 "def/def.y"
      { if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addTaperRule((yyvsp[0].string)); }
#line 7047 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 476: /* opt_style: K_STYLE NUMBER  */
#line 2799 "def/def.y"
      { 
        if (defData->VersionNum < 5.6) {
           if (defData->NeedPathData && (defData->callbacks->NetCbk ||
               defData->callbacks->SNetCbk)) {
             if (defData->netWarnings++ < defData->settings->NetWarnings) {
               defData->defMsg = (char*)malloc(1000);
               sprintf (defData->defMsg,
                  "The STYLE statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
               defData->defError(6534, defData->defMsg);
               free(defData->defMsg);
               CHKERR();
             }
           }
        } else
           if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
             (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
             defData->PathObj.addStyle((int)(yyvsp[0].dval));
      }
#line 7070 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 479: /* opt_shape_style: '+' K_SHAPE shape_type  */
#line 2824 "def/def.y"
      { if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addShape((yyvsp[0].string)); }
#line 7078 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 480: /* opt_shape_style: '+' K_STYLE NUMBER  */
#line 2828 "def/def.y"
      { if (defData->VersionNum < 5.6) {
          if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
            (defData->callbacks->SNetCbk && (defData->netOsnet==2)))) {
            if (defData->netWarnings++ < defData->settings->NetWarnings) {
              defData->defMsg = (char*)malloc(1000);
              sprintf (defData->defMsg,
                 "The STYLE statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
              defData->defError(6534, defData->defMsg);
              free(defData->defMsg);
              CHKERR();
            }
          }
        } else {
          if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
            (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
            defData->PathObj.addStyle((int)(yyvsp[0].dval));
        }
      }
#line 7101 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 481: /* end_nets: K_END K_NETS  */
#line 2848 "def/def.y"
          { 
            CALLBACK(defData->callbacks->NetEndCbk, defrNetEndCbkType, 0);
            defData->netOsnet = 0;
          }
#line 7110 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 482: /* shape_type: K_RING  */
#line 2854 "def/def.y"
            { (yyval.string) = (char*)"RING"; }
#line 7116 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 483: /* shape_type: K_STRIPE  */
#line 2856 "def/def.y"
            { (yyval.string) = (char*)"STRIPE"; }
#line 7122 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 484: /* shape_type: K_FOLLOWPIN  */
#line 2858 "def/def.y"
            { (yyval.string) = (char*)"FOLLOWPIN"; }
#line 7128 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 485: /* shape_type: K_IOWIRE  */
#line 2860 "def/def.y"
            { (yyval.string) = (char*)"IOWIRE"; }
#line 7134 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 486: /* shape_type: K_COREWIRE  */
#line 2862 "def/def.y"
            { (yyval.string) = (char*)"COREWIRE"; }
#line 7140 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 487: /* shape_type: K_BLOCKWIRE  */
#line 2864 "def/def.y"
            { (yyval.string) = (char*)"BLOCKWIRE"; }
#line 7146 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 488: /* shape_type: K_FILLWIRE  */
#line 2866 "def/def.y"
            { (yyval.string) = (char*)"FILLWIRE"; }
#line 7152 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 489: /* shape_type: K_FILLWIREOPC  */
#line 2868 "def/def.y"
            {
              if (defData->VersionNum < 5.7) {
                 if (defData->NeedPathData) {
                   if (defData->fillWarnings++ < defData->settings->FillWarnings) {
                     defData->defMsg = (char*)malloc(10000);
                     sprintf (defData->defMsg,
                       "The FILLWIREOPC is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                     defData->defError(6552, defData->defMsg);
                     free(defData->defMsg);
                     CHKERR();
                  }
                }
              }
              (yyval.string) = (char*)"FILLWIREOPC";
            }
#line 7172 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 490: /* shape_type: K_DRCFILL  */
#line 2884 "def/def.y"
            { (yyval.string) = (char*)"DRCFILL"; }
#line 7178 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 491: /* shape_type: K_BLOCKAGEWIRE  */
#line 2886 "def/def.y"
            { (yyval.string) = (char*)"BLOCKAGEWIRE"; }
#line 7184 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 492: /* shape_type: K_PADRING  */
#line 2888 "def/def.y"
            { (yyval.string) = (char*)"PADRING"; }
#line 7190 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 493: /* shape_type: K_BLOCKRING  */
#line 2890 "def/def.y"
            { (yyval.string) = (char*)"BLOCKRING"; }
#line 7196 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 497: /* snet_rule: net_and_connections snet_options ';'  */
#line 2900 "def/def.y"
        { CALLBACK(defData->callbacks->SNetCbk, defrSNetCbkType, &defData->Net); }
#line 7202 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 504: /* snet_other_option: '+' net_type  */
#line 2911 "def/def.y"
            {
             if (defData->VersionNum >= 5.8) {
                defData->specialWire_routeStatus = (yyvsp[0].string);
             } else {
                 if (defData->callbacks->SNetCbk) {   // PCR 902306 
                   defData->defMsg = (char*)malloc(1024);
                   sprintf(defData->defMsg, "The SPECIAL NET statement, with type %s, does not have any net statement defined.\nThe DEF parser will ignore this statemnet.", (yyvsp[0].string));
                   defData->defWarning(7023, defData->defMsg);
                   free(defData->defMsg);
                 }
             }
            }
#line 7219 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 505: /* $@86: %empty  */
#line 2924 "def/def.y"
            {
            if (defData->callbacks->SNetCbk) defData->Net.addWire((yyvsp[0].string), NULL);
            }
#line 7227 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 506: /* snet_other_option: '+' net_type $@86 spaths  */
#line 2928 "def/def.y"
            {
            // 7/17/2003 - Fix for pcr 604848, add a callback for each wire
            if (defData->callbacks->SNetWireCbk) {
               CALLBACK(defData->callbacks->SNetWireCbk, defrSNetWireCbkType, &defData->Net);
               defData->Net.freeWire();
            }
            defData->by_is_keyword = FALSE;
            defData->do_is_keyword = FALSE;
            defData->new_is_keyword = FALSE;
            defData->step_is_keyword = FALSE;
            defData->orient_is_keyword = FALSE;
            defData->virtual_is_keyword = FALSE;
            defData->mask_is_keyword = FALSE;
            defData->rect_is_keyword = FALSE;
            defData->needSNPCbk = 0;
            }
#line 7248 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 507: /* $@87: %empty  */
#line 2945 "def/def.y"
                       { defData->dumb_mode = 1; defData->no_num = 1; }
#line 7254 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 508: /* $@88: %empty  */
#line 2946 "def/def.y"
            { defData->shieldName = (yyvsp[0].string); 
              defData->specialWire_routeStatus = (char*)"SHIELD";
              defData->specialWire_routeStatusName = (yyvsp[0].string); 
            }
#line 7263 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 510: /* snet_other_option: '+' K_SHAPE shape_type  */
#line 2953 "def/def.y"
          {  
            defData->specialWire_shapeType = (yyvsp[0].string);
          }
#line 7271 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 511: /* snet_other_option: '+' K_MASK NUMBER  */
#line 2957 "def/def.y"
          {
            if (defData->validateMaskInput((int)(yyvsp[0].dval), defData->sNetWarnings, defData->settings->SNetWarnings)) {
                defData->specialWire_mask = (yyvsp[0].dval);
            }     
          }
#line 7281 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 512: /* $@89: %empty  */
#line 2962 "def/def.y"
                        { defData->dumb_mode = 1; }
#line 7287 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 513: /* $@90: %empty  */
#line 2963 "def/def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->SNetCbk) {
                if (defData->sNetWarnings++ < defData->settings->SNetWarnings) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The POLYGON statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
                  defData->defError(6535, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            
            defData->Geometries.Reset();
          }
#line 7308 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 514: /* snet_other_option: '+' K_POLYGON $@89 T_STRING $@90 firstPt nextPt nextPt otherPts  */
#line 2980 "def/def.y"
          {
            if (defData->VersionNum >= 5.6) {  // only add if 5.6 or beyond
              if (defData->callbacks->SNetCbk) {
                // defData->needSNPCbk will indicate that it has reach the max
                // memory and if user has set partialPathCBk, def parser
                // will make the callback.
                // This will improve performance
                // This construct is only in specialnet
                defData->Net.addPolygon((yyvsp[-5].string), &defData->Geometries, &defData->needSNPCbk, defData->specialWire_mask, defData->specialWire_routeStatus, defData->specialWire_shapeType,
                                                                defData->specialWire_routeStatusName);
                defData->specialWire_mask = 0;
                defData->specialWire_routeStatus = (char*)"ROUTED";
                defData->specialWire_shapeType = (char*)"";
                if (defData->needSNPCbk && defData->callbacks->SNetPartialPathCbk) {
                   CALLBACK(defData->callbacks->SNetPartialPathCbk, defrSNetPartialPathCbkType,
                            &defData->Net);
                   defData->Net.clearRectPolyNPath();
                   defData->Net.clearVia();
                }
              }
            }
          }
#line 7335 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 515: /* $@91: %empty  */
#line 3003 "def/def.y"
                     { defData->dumb_mode = 1; }
#line 7341 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 516: /* snet_other_option: '+' K_RECT $@91 T_STRING pt pt  */
#line 3004 "def/def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->SNetCbk) {
                if (defData->sNetWarnings++ < defData->settings->SNetWarnings) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The RECT statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
                  defData->defError(6536, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            if (defData->callbacks->SNetCbk) {
              // defData->needSNPCbk will indicate that it has reach the max
              // memory and if user has set partialPathCBk, def parser
              // will make the callback.
              // This will improve performance
              // This construct is only in specialnet
              defData->Net.addRect((yyvsp[-2].string), (yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y, &defData->needSNPCbk, defData->specialWire_mask, defData->specialWire_routeStatus, defData->specialWire_shapeType, defData->specialWire_routeStatusName);
              defData->specialWire_mask = 0;
              defData->specialWire_routeStatus = (char*)"ROUTED";
              defData->specialWire_shapeType = (char*)"";
              defData->specialWire_routeStatusName = (char*)"";
              if (defData->needSNPCbk && defData->callbacks->SNetPartialPathCbk) {
                 CALLBACK(defData->callbacks->SNetPartialPathCbk, defrSNetPartialPathCbkType,
                          &defData->Net);
                 defData->Net.clearRectPolyNPath();
                 defData->Net.clearVia();
              }
            }
          }
#line 7378 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 517: /* $@92: %empty  */
#line 3036 "def/def.y"
                    { defData->dumb_mode = 1; }
#line 7384 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 518: /* $@93: %empty  */
#line 3037 "def/def.y"
        {
          if (defData->VersionNum < 5.8) {
              if (defData->callbacks->SNetCbk) {
                if (defData->sNetWarnings++ < defData->settings->SNetWarnings) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The VIA statement is available in version 5.8 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
                  defData->defError(6536, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
          }
        }
#line 7403 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 519: /* snet_other_option: '+' K_VIA $@92 T_STRING orient_pt $@93 firstPt otherPts  */
#line 3052 "def/def.y"
        {
          if (defData->VersionNum >= 5.8 && defData->callbacks->SNetCbk) {
              defData->Net.addPts((yyvsp[-4].string), (yyvsp[-3].integer), &defData->Geometries, &defData->needSNPCbk, defData->specialWire_mask, defData->specialWire_routeStatus, defData->specialWire_shapeType,
                                                          defData->specialWire_routeStatusName);
              defData->specialWire_mask = 0;
              defData->specialWire_routeStatus = (char*)"ROUTED";
              defData->specialWire_shapeType = (char*)"";
              defData->specialWire_routeStatusName = (char*)"";
              if (defData->needSNPCbk && defData->callbacks->SNetPartialPathCbk) {
                 CALLBACK(defData->callbacks->SNetPartialPathCbk, defrSNetPartialPathCbkType,
                          &defData->Net);
                 defData->Net.clearRectPolyNPath();
                 defData->Net.clearVia();
              }
            }
        }
#line 7424 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 520: /* snet_other_option: '+' K_SOURCE source_type  */
#line 3070 "def/def.y"
            { if (defData->callbacks->SNetCbk) defData->Net.setSource((yyvsp[0].string)); }
#line 7430 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 521: /* snet_other_option: '+' K_FIXEDBUMP  */
#line 3073 "def/def.y"
            { if (defData->callbacks->SNetCbk) defData->Net.setFixedbump(); }
#line 7436 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 522: /* snet_other_option: '+' K_FREQUENCY NUMBER  */
#line 3076 "def/def.y"
            { if (defData->callbacks->SNetCbk) defData->Net.setFrequency((yyvsp[0].dval)); }
#line 7442 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 523: /* $@94: %empty  */
#line 3078 "def/def.y"
                         {defData->dumb_mode = 1; defData->no_num = 1;}
#line 7448 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 524: /* snet_other_option: '+' K_ORIGINAL $@94 T_STRING  */
#line 3079 "def/def.y"
            { if (defData->callbacks->SNetCbk) defData->Net.setOriginal((yyvsp[0].string)); }
#line 7454 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 525: /* snet_other_option: '+' K_PATTERN pattern_type  */
#line 3082 "def/def.y"
            { if (defData->callbacks->SNetCbk) defData->Net.setPattern((yyvsp[0].string)); }
#line 7460 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 526: /* snet_other_option: '+' K_WEIGHT NUMBER  */
#line 3085 "def/def.y"
            { if (defData->callbacks->SNetCbk) defData->Net.setWeight(ROUND((yyvsp[0].dval))); }
#line 7466 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 527: /* snet_other_option: '+' K_ESTCAP NUMBER  */
#line 3088 "def/def.y"
            { 
              // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
              if (defData->VersionNum < 5.5)
              {
                 if (defData->callbacks->SNetCbk) defData->Net.setCap((yyvsp[0].dval));
              }
              else
                 defData->defWarning(7024, "The ESTCAP statement is obsolete in version 5.5 and later.\nThe DEF parser will ignore this statement.");
            }
#line 7480 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 528: /* snet_other_option: '+' K_USE use_type  */
#line 3099 "def/def.y"
            { if (defData->callbacks->SNetCbk) defData->Net.setUse((yyvsp[0].string)); }
#line 7486 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 529: /* snet_other_option: '+' K_STYLE NUMBER  */
#line 3102 "def/def.y"
            { if (defData->callbacks->SNetCbk) defData->Net.setStyle((int)(yyvsp[0].dval)); }
#line 7492 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 530: /* $@95: %empty  */
#line 3104 "def/def.y"
                         {defData->dumb_mode = DEF_MAX_INT; }
#line 7498 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 531: /* snet_other_option: '+' K_PROPERTY $@95 snet_prop_list  */
#line 3106 "def/def.y"
            { defData->dumb_mode = 0; }
#line 7504 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 532: /* snet_other_option: extension_stmt  */
#line 3109 "def/def.y"
          { CALLBACK(defData->callbacks->NetExtCbk, defrNetExtCbkType, &defData->History_text[0]); }
#line 7510 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 533: /* orient_pt: %empty  */
#line 3112 "def/def.y"
        { (yyval.integer) = 0; }
#line 7516 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 534: /* orient_pt: K_N  */
#line 3113 "def/def.y"
               {(yyval.integer) = 0;}
#line 7522 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 535: /* orient_pt: K_W  */
#line 3114 "def/def.y"
               {(yyval.integer) = 1;}
#line 7528 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 536: /* orient_pt: K_S  */
#line 3115 "def/def.y"
               {(yyval.integer) = 2;}
#line 7534 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 537: /* orient_pt: K_E  */
#line 3116 "def/def.y"
               {(yyval.integer) = 3;}
#line 7540 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 538: /* orient_pt: K_FN  */
#line 3117 "def/def.y"
               {(yyval.integer) = 4;}
#line 7546 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 539: /* orient_pt: K_FW  */
#line 3118 "def/def.y"
               {(yyval.integer) = 5;}
#line 7552 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 540: /* orient_pt: K_FS  */
#line 3119 "def/def.y"
               {(yyval.integer) = 6;}
#line 7558 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 541: /* orient_pt: K_FE  */
#line 3120 "def/def.y"
               {(yyval.integer) = 7;}
#line 7564 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 542: /* shield_layer: %empty  */
#line 3123 "def/def.y"
            {
                if (defData->callbacks->SNetCbk) {
                    if (defData->VersionNum < 5.8) { 
                        defData->defMsg = (char*)malloc(1024);
                        sprintf(defData->defMsg, "The SPECIAL NET SHIELD statement doesn't have routing points definition.\nWill be ignored.");
                        defData->defWarning(7025, defData->defMsg);
                        free(defData->defMsg);
                    } else {  // CCR 1244433
                      defData->specialWire_routeStatus = (char*)"SHIELD";
                      defData->specialWire_routeStatusName = defData->shieldName;
                    }
                }
            }
#line 7582 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 543: /* $@96: %empty  */
#line 3137 "def/def.y"
            { // since the parser still supports 5.3 and earlier, 
              // can't just move SHIELD in net_type 
              if (defData->VersionNum < 5.4) { // PCR 445209 
                if (defData->callbacks->SNetCbk) defData->Net.addShield(defData->shieldName);
                defData->by_is_keyword = FALSE;
                defData->do_is_keyword = FALSE;
                defData->new_is_keyword = FALSE;
                defData->step_is_keyword = FALSE;
                defData->orient_is_keyword = FALSE;
                defData->virtual_is_keyword = FALSE;
                defData->mask_is_keyword = FALSE;
                defData->rect_is_keyword = FALSE;
                defData->specialWire_routeStatus = (char*)"ROUTED";
                defData->specialWire_routeStatusName = (char*)"";
                defData->shield = TRUE;   // save the path info in the defData->shield paths 
              } else
                if (defData->callbacks->SNetCbk) defData->Net.addWire("SHIELD", defData->shieldName);
                defData->specialWire_routeStatus = (char*)"ROUTED";
                defData->specialWire_routeStatusName = (char*)"";
            }
#line 7607 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 544: /* shield_layer: $@96 spaths  */
#line 3158 "def/def.y"
            {
              // 7/17/2003 - Fix for pcr 604848, add a callback for each wire
              if (defData->callbacks->SNetWireCbk) {
                 CALLBACK(defData->callbacks->SNetWireCbk, defrSNetWireCbkType, &defData->Net);
                 if (defData->VersionNum < 5.4)
                   defData->Net.freeShield();
                 else
                   defData->Net.freeWire();
              }
              if (defData->VersionNum < 5.4) {  // PCR 445209 
                defData->shield = FALSE;
                defData->by_is_keyword = FALSE;
                defData->do_is_keyword = FALSE;
                defData->new_is_keyword = FALSE;
                defData->step_is_keyword = FALSE;
                defData->nondef_is_keyword = FALSE;
                defData->mustjoin_is_keyword = FALSE;
                defData->orient_is_keyword = FALSE;
                defData->virtual_is_keyword = FALSE;
                defData->mask_is_keyword = FALSE;
                defData->rect_is_keyword = FALSE;
              } else {
                defData->by_is_keyword = FALSE;
                defData->do_is_keyword = FALSE;
                defData->new_is_keyword = FALSE;
                defData->step_is_keyword = FALSE;
                defData->orient_is_keyword = FALSE;
                defData->virtual_is_keyword = FALSE;
                defData->mask_is_keyword = FALSE;
                defData->rect_is_keyword = FALSE;
              }
              defData->needSNPCbk = 0;
            }
#line 7645 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 545: /* $@97: %empty  */
#line 3192 "def/def.y"
                        { defData->dumb_mode = 1; }
#line 7651 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 546: /* snet_width: '+' K_WIDTH $@97 T_STRING NUMBER  */
#line 3193 "def/def.y"
            {
              // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
              if (defData->VersionNum < 5.5)
              {
                 if (defData->callbacks->SNetCbk) defData->Net.setWidth((yyvsp[-1].string), (yyvsp[0].dval));
              }
              else
                 defData->defWarning(7026, "The WIDTH statement is obsolete in version 5.5 and later.\nThe DEF parser will ignore this statement.");
            }
#line 7665 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 547: /* $@98: %empty  */
#line 3203 "def/def.y"
                             { defData->dumb_mode = 1; defData->no_num = 1; }
#line 7671 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 548: /* snet_voltage: '+' K_VOLTAGE $@98 T_STRING  */
#line 3204 "def/def.y"
            {
              if (defrData::numIsInt((yyvsp[0].string))) {
                 if (defData->callbacks->SNetCbk) defData->Net.setVoltage(atoi((yyvsp[0].string)));
              } else {
                 if (defData->callbacks->SNetCbk) {
                   if (defData->sNetWarnings++ < defData->settings->SNetWarnings) {
                     defData->defMsg = (char*)malloc(1000);
                     sprintf (defData->defMsg,
                        "The value %s for statement VOLTAGE is invalid. The value can only be integer.\nSpecify a valid value in units of millivolts", (yyvsp[0].string));
                     defData->defError(6537, defData->defMsg);
                     free(defData->defMsg);
                     CHKERR();
                   }
                 }
              }
            }
#line 7692 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 549: /* $@99: %empty  */
#line 3221 "def/def.y"
                            { defData->dumb_mode = 1; }
#line 7698 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 550: /* $@100: %empty  */
#line 3222 "def/def.y"
            {
              if (defData->callbacks->SNetCbk) defData->Net.setSpacing((yyvsp[-1].string),(yyvsp[0].dval));
            }
#line 7706 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 551: /* snet_spacing: '+' K_SPACING $@99 T_STRING NUMBER $@100 opt_snet_range  */
#line 3226 "def/def.y"
            {
            }
#line 7713 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 554: /* snet_prop: T_STRING NUMBER  */
#line 3234 "def/def.y"
            {
              if (defData->callbacks->SNetCbk) {
                char propTp;
                char* str = defData->ringCopy("                       ");
                propTp = defData->session->SNetProp.propType((yyvsp[-1].string));
                CHKPROPTYPE(propTp, (yyvsp[-1].string), "SPECIAL NET");
                // For backword compatibility, also set the string value 
                sprintf(str, "%g", (yyvsp[0].dval));
                defData->Net.addNumProp((yyvsp[-1].string), (yyvsp[0].dval), str, propTp);
              }
            }
#line 7729 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 555: /* snet_prop: T_STRING QSTRING  */
#line 3246 "def/def.y"
            {
              if (defData->callbacks->SNetCbk) {
                char propTp;
                propTp = defData->session->SNetProp.propType((yyvsp[-1].string));
                CHKPROPTYPE(propTp, (yyvsp[-1].string), "SPECIAL NET");
                defData->Net.addProp((yyvsp[-1].string), (yyvsp[0].string), propTp);
              }
            }
#line 7742 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 556: /* snet_prop: T_STRING T_STRING  */
#line 3255 "def/def.y"
            {
              if (defData->callbacks->SNetCbk) {
                char propTp;
                propTp = defData->session->SNetProp.propType((yyvsp[-1].string));
                CHKPROPTYPE(propTp, (yyvsp[-1].string), "SPECIAL NET");
                defData->Net.addProp((yyvsp[-1].string), (yyvsp[0].string), propTp);
              }
            }
#line 7755 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 558: /* opt_snet_range: K_RANGE NUMBER NUMBER  */
#line 3266 "def/def.y"
            {
              if (defData->callbacks->SNetCbk) defData->Net.setRange((yyvsp[-1].dval),(yyvsp[0].dval));
            }
#line 7763 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 560: /* opt_range: K_RANGE NUMBER NUMBER  */
#line 3272 "def/def.y"
            { defData->Prop.setRange((yyvsp[-1].dval), (yyvsp[0].dval)); }
#line 7769 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 561: /* pattern_type: K_BALANCED  */
#line 3275 "def/def.y"
            { (yyval.string) = (char*)"BALANCED"; }
#line 7775 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 562: /* pattern_type: K_STEINER  */
#line 3277 "def/def.y"
            { (yyval.string) = (char*)"STEINER"; }
#line 7781 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 563: /* pattern_type: K_TRUNK  */
#line 3279 "def/def.y"
            { (yyval.string) = (char*)"TRUNK"; }
#line 7787 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 564: /* pattern_type: K_WIREDLOGIC  */
#line 3281 "def/def.y"
            { (yyval.string) = (char*)"WIREDLOGIC"; }
#line 7793 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 565: /* spaths: spath  */
#line 3285 "def/def.y"
      { 
        if (defData->NeedPathData && defData->callbacks->SNetCbk) {
           if (defData->needSNPCbk && defData->callbacks->SNetPartialPathCbk) { 
              // require a callback before proceed because defData->needSNPCbk must be
              // set to 1 from the previous pathIsDone and user has registered
              // a callback routine.
              CALLBACK(defData->callbacks->SNetPartialPathCbk, defrSNetPartialPathCbkType,
                       &defData->Net);
              defData->needSNPCbk = 0;   // reset the flag
              defData->pathIsDone(defData->shield, 1, defData->netOsnet, &defData->needSNPCbk);
              defData->Net.clearRectPolyNPath();
              defData->Net.clearVia();
           } else
              defData->pathIsDone(defData->shield, 0, defData->netOsnet, &defData->needSNPCbk);
        }
      }
#line 7814 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 566: /* spaths: spaths snew_path  */
#line 3302 "def/def.y"
      { }
#line 7820 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 567: /* $@101: %empty  */
#line 3304 "def/def.y"
                 { defData->dumb_mode = 1; }
#line 7826 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 568: /* snew_path: K_NEW $@101 spath  */
#line 3305 "def/def.y"
      { if (defData->NeedPathData && defData->callbacks->SNetCbk) {
           if (defData->needSNPCbk && defData->callbacks->SNetPartialPathCbk) {
              // require a callback before proceed because defData->needSNPCbk must be
              // set to 1 from the previous pathIsDone and user has registered
              // a callback routine.
              CALLBACK(defData->callbacks->SNetPartialPathCbk, defrSNetPartialPathCbkType,
                       &defData->Net);
              defData->needSNPCbk = 0;   // reset the flag
              defData->pathIsDone(defData->shield, 1, defData->netOsnet, &defData->needSNPCbk);
              // reset any poly or rect in special wiring statement
              defData->Net.clearRectPolyNPath();
              defData->Net.clearVia();
           } else
              defData->pathIsDone(defData->shield, 0, defData->netOsnet, &defData->needSNPCbk);
        }
      }
#line 7847 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 569: /* $@102: %empty  */
#line 3323 "def/def.y"
      { if (defData->NeedPathData && defData->callbacks->SNetCbk)
           defData->PathObj.addLayer((yyvsp[0].string));
        defData->dumb_mode = 0; defData->no_num = 0;
      }
#line 7856 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 570: /* $@103: %empty  */
#line 3331 "def/def.y"
      { defData->dumb_mode = DEF_MAX_INT; defData->by_is_keyword = TRUE; defData->do_is_keyword = TRUE;
        defData->new_is_keyword = TRUE; defData->step_is_keyword = TRUE;
         defData->orient_is_keyword = TRUE; defData->rect_is_keyword = TRUE, defData->mask_is_keyword = TRUE; 
         defData->virtual_is_keyword = TRUE;  }
#line 7865 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 571: /* spath: T_STRING $@102 width opt_spaths path_pt $@103 path_item_list  */
#line 3337 "def/def.y"
      { defData->dumb_mode = 0; defData->rect_is_keyword = FALSE, defData->mask_is_keyword = FALSE, defData->virtual_is_keyword = FALSE; }
#line 7871 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 572: /* width: NUMBER  */
#line 3340 "def/def.y"
      { if (defData->NeedPathData && defData->callbacks->SNetCbk)
          defData->PathObj.addWidth(ROUND((yyvsp[0].dval)));
      }
#line 7879 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 573: /* start_snets: K_SNETS NUMBER ';'  */
#line 3345 "def/def.y"
      { 
        if (defData->callbacks->SNetStartCbk)
          CALLBACK(defData->callbacks->SNetStartCbk, defrSNetStartCbkType, ROUND((yyvsp[-1].dval)));
        defData->netOsnet = 2;
      }
#line 7889 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 574: /* end_snets: K_END K_SNETS  */
#line 3352 "def/def.y"
      { 
        if (defData->callbacks->SNetEndCbk)
          CALLBACK(defData->callbacks->SNetEndCbk, defrSNetEndCbkType, 0);
        defData->netOsnet = 0;
      }
#line 7899 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 576: /* groups_start: K_GROUPS NUMBER ';'  */
#line 3362 "def/def.y"
      {
        if (defData->callbacks->GroupsStartCbk)
           CALLBACK(defData->callbacks->GroupsStartCbk, defrGroupsStartCbkType, ROUND((yyvsp[-1].dval)));
      }
#line 7908 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 579: /* group_rule: start_group group_members group_options ';'  */
#line 3372 "def/def.y"
      {
        if (defData->callbacks->GroupCbk)
           CALLBACK(defData->callbacks->GroupCbk, defrGroupCbkType, &defData->Group);
      }
#line 7917 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 580: /* $@104: %empty  */
#line 3377 "def/def.y"
                 { defData->dumb_mode = 1; defData->no_num = 1; }
#line 7923 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 581: /* start_group: '-' $@104 T_STRING  */
#line 3378 "def/def.y"
      {
        defData->dumb_mode = DEF_MAX_INT;
        defData->no_num = DEF_MAX_INT;
        /* dumb_mode is automatically turned off at the first
         * + in the options or at the ; at the end of the group */
        if (defData->callbacks->GroupCbk) defData->Group.setup((yyvsp[0].string));
        if (defData->callbacks->GroupNameCbk)
           CALLBACK(defData->callbacks->GroupNameCbk, defrGroupNameCbkType, (yyvsp[0].string));
      }
#line 7937 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 583: /* group_members: group_members group_member  */
#line 3390 "def/def.y"
      {  }
#line 7943 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 584: /* group_member: T_STRING  */
#line 3393 "def/def.y"
      {
        // if (defData->callbacks->GroupCbk) defData->Group.addMember($1); 
        if (defData->callbacks->GroupMemberCbk)
          CALLBACK(defData->callbacks->GroupMemberCbk, defrGroupMemberCbkType, (yyvsp[0].string));
      }
#line 7953 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 587: /* group_option: '+' K_SOFT group_soft_options  */
#line 3404 "def/def.y"
      { }
#line 7959 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 588: /* $@105: %empty  */
#line 3405 "def/def.y"
                           { defData->dumb_mode = DEF_MAX_INT; }
#line 7965 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 589: /* group_option: '+' K_PROPERTY $@105 group_prop_list  */
#line 3407 "def/def.y"
      { defData->dumb_mode = 0; }
#line 7971 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 590: /* $@106: %empty  */
#line 3408 "def/def.y"
                         { defData->dumb_mode = 1;  defData->no_num = 1; }
#line 7977 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 591: /* group_option: '+' K_REGION $@106 group_region  */
#line 3409 "def/def.y"
      { }
#line 7983 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 592: /* group_option: extension_stmt  */
#line 3411 "def/def.y"
      { 
        if (defData->callbacks->GroupMemberCbk)
          CALLBACK(defData->callbacks->GroupExtCbk, defrGroupExtCbkType, &defData->History_text[0]);
      }
#line 7992 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 593: /* group_region: pt pt  */
#line 3417 "def/def.y"
      {
        // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
        if (defData->VersionNum < 5.5) {
          if (defData->callbacks->GroupCbk)
            defData->Group.addRegionRect((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y);
        }
        else
          defData->defWarning(7027, "The GROUP REGION pt pt statement is obsolete in version 5.5 and later.\nThe DEF parser will ignore this statement.");
      }
#line 8006 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 594: /* group_region: T_STRING  */
#line 3427 "def/def.y"
      { if (defData->callbacks->GroupCbk)
          defData->Group.setRegionName((yyvsp[0].string));
      }
#line 8014 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 597: /* group_prop: T_STRING NUMBER  */
#line 3436 "def/def.y"
      {
        if (defData->callbacks->GroupCbk) {
          char propTp;
          char* str = defData->ringCopy("                       ");
          propTp = defData->session->GroupProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "GROUP");
          sprintf(str, "%g", (yyvsp[0].dval));
          defData->Group.addNumProperty((yyvsp[-1].string), (yyvsp[0].dval), str, propTp);
        }
      }
#line 8029 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 598: /* group_prop: T_STRING QSTRING  */
#line 3447 "def/def.y"
      {
        if (defData->callbacks->GroupCbk) {
          char propTp;
          propTp = defData->session->GroupProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "GROUP");
          defData->Group.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
        }
      }
#line 8042 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 599: /* group_prop: T_STRING T_STRING  */
#line 3456 "def/def.y"
      {
        if (defData->callbacks->GroupCbk) {
          char propTp;
          propTp = defData->session->GroupProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "GROUP");
          defData->Group.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
        }
      }
#line 8055 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 601: /* group_soft_options: group_soft_options group_soft_option  */
#line 3467 "def/def.y"
      { }
#line 8061 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 602: /* group_soft_option: K_MAXX NUMBER  */
#line 3470 "def/def.y"
      {
        // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
        if (defData->VersionNum < 5.5)
        {
          if (defData->callbacks->GroupCbk) defData->Group.setMaxX(ROUND((yyvsp[0].dval)));
        }
        else
          defData->defWarning(7028, "The GROUP SOFT MAXX statement is obsolete in version 5.5 and later.\nThe DEF parser will ignore this statement.");
      }
#line 8075 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 603: /* group_soft_option: K_MAXY NUMBER  */
#line 3480 "def/def.y"
      { 
        // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
        if (defData->VersionNum < 5.5)
        {
          if (defData->callbacks->GroupCbk) defData->Group.setMaxY(ROUND((yyvsp[0].dval)));
        }
        else
          defData->defWarning(7029, "The GROUP SOFT MAXY statement is obsolete in version 5.5 and later.\nThe DEF parser will ignore this statement.");
      }
#line 8089 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 604: /* group_soft_option: K_MAXHALFPERIMETER NUMBER  */
#line 3490 "def/def.y"
      { 
        // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
        if (defData->VersionNum < 5.5)
        {
          if (defData->callbacks->GroupCbk) defData->Group.setPerim(ROUND((yyvsp[0].dval)));
        }
        else
          defData->defWarning(7030, "The GROUP SOFT MAXHALFPERIMETER statement is obsolete in version 5.5 and later.\nThe DEF parser will ignore this statement.");
      }
#line 8103 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 605: /* groups_end: K_END K_GROUPS  */
#line 3501 "def/def.y"
      { 
        if (defData->callbacks->GroupsEndCbk)
          CALLBACK(defData->callbacks->GroupsEndCbk, defrGroupsEndCbkType, 0);
      }
#line 8112 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 608: /* assertions_start: K_ASSERTIONS NUMBER ';'  */
#line 3515 "def/def.y"
      {
        if ((defData->VersionNum < 5.4) && (defData->callbacks->AssertionsStartCbk)) {
          CALLBACK(defData->callbacks->AssertionsStartCbk, defrAssertionsStartCbkType,
                   ROUND((yyvsp[-1].dval)));
        } else {
          if (defData->callbacks->AssertionCbk)
            if (defData->assertionWarnings++ < defData->settings->AssertionWarnings)
              defData->defWarning(7031, "The ASSERTIONS statement is obsolete in version 5.4 and later.\nThe DEF parser will ignore this statement.");
        }
        if (defData->callbacks->AssertionCbk)
          defData->Assertion.setAssertionMode();
      }
#line 8129 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 609: /* constraints_start: K_CONSTRAINTS NUMBER ';'  */
#line 3529 "def/def.y"
      {
        if ((defData->VersionNum < 5.4) && (defData->callbacks->ConstraintsStartCbk)) {
          CALLBACK(defData->callbacks->ConstraintsStartCbk, defrConstraintsStartCbkType,
                   ROUND((yyvsp[-1].dval)));
        } else {
          if (defData->callbacks->ConstraintCbk)
            if (defData->constraintWarnings++ < defData->settings->ConstraintWarnings)
              defData->defWarning(7032, "The CONSTRAINTS statement is obsolete in version 5.4 and later.\nThe DEF parser will ignore this statement.");
        }
        if (defData->callbacks->ConstraintCbk)
          defData->Assertion.setConstraintMode();
      }
#line 8146 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 613: /* constraint_rule: wiredlogic_rule  */
#line 3548 "def/def.y"
      {
        if ((defData->VersionNum < 5.4) && (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)) {
          if (defData->Assertion.isConstraint()) 
            CALLBACK(defData->callbacks->ConstraintCbk, defrConstraintCbkType, &defData->Assertion);
          if (defData->Assertion.isAssertion()) 
            CALLBACK(defData->callbacks->AssertionCbk, defrAssertionCbkType, &defData->Assertion);
        }
      }
#line 8159 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 614: /* operand_rule: '-' operand delay_specs ';'  */
#line 3558 "def/def.y"
      { 
        if ((defData->VersionNum < 5.4) && (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)) {
          if (defData->Assertion.isConstraint()) 
            CALLBACK(defData->callbacks->ConstraintCbk, defrConstraintCbkType, &defData->Assertion);
          if (defData->Assertion.isAssertion()) 
            CALLBACK(defData->callbacks->AssertionCbk, defrAssertionCbkType, &defData->Assertion);
        }
   
        // reset all the flags and everything
        defData->Assertion.clear();
      }
#line 8175 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 615: /* $@107: %empty  */
#line 3570 "def/def.y"
               { defData->dumb_mode = 1; defData->no_num = 1; }
#line 8181 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 616: /* operand: K_NET $@107 T_STRING  */
#line 3571 "def/def.y"
      {
         if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
           defData->Assertion.addNet((yyvsp[0].string));
      }
#line 8190 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 617: /* $@108: %empty  */
#line 3575 "def/def.y"
               {defData->dumb_mode = 4; defData->no_num = 4;}
#line 8196 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 618: /* operand: K_PATH $@108 T_STRING T_STRING T_STRING T_STRING  */
#line 3576 "def/def.y"
      {
         if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
           defData->Assertion.addPath((yyvsp[-3].string), (yyvsp[-2].string), (yyvsp[-1].string), (yyvsp[0].string));
      }
#line 8205 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 619: /* operand: K_SUM '(' operand_list ')'  */
#line 3581 "def/def.y"
      {
        if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
           defData->Assertion.setSum();
      }
#line 8214 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 620: /* operand: K_DIFF '(' operand_list ')'  */
#line 3586 "def/def.y"
      {
        if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
           defData->Assertion.setDiff();
      }
#line 8223 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 622: /* operand_list: operand_list operand  */
#line 3593 "def/def.y"
      { }
#line 8229 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 624: /* $@109: %empty  */
#line 3596 "def/def.y"
                                  { defData->dumb_mode = 1; defData->no_num = 1; }
#line 8235 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 625: /* wiredlogic_rule: '-' K_WIREDLOGIC $@109 T_STRING opt_plus K_MAXDIST NUMBER ';'  */
#line 3598 "def/def.y"
      {
        if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
          defData->Assertion.setWiredlogic((yyvsp[-4].string), (yyvsp[-1].dval));
      }
#line 8244 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 626: /* opt_plus: %empty  */
#line 3605 "def/def.y"
      { (yyval.string) = (char*)""; }
#line 8250 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 627: /* opt_plus: '+'  */
#line 3607 "def/def.y"
      { (yyval.string) = (char*)"+"; }
#line 8256 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 630: /* delay_spec: '+' K_RISEMIN NUMBER  */
#line 3614 "def/def.y"
      {
        if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
          defData->Assertion.setRiseMin((yyvsp[0].dval));
      }
#line 8265 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 631: /* delay_spec: '+' K_RISEMAX NUMBER  */
#line 3619 "def/def.y"
      {
        if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
          defData->Assertion.setRiseMax((yyvsp[0].dval));
      }
#line 8274 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 632: /* delay_spec: '+' K_FALLMIN NUMBER  */
#line 3624 "def/def.y"
      {
        if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
          defData->Assertion.setFallMin((yyvsp[0].dval));
      }
#line 8283 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 633: /* delay_spec: '+' K_FALLMAX NUMBER  */
#line 3629 "def/def.y"
      {
        if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
          defData->Assertion.setFallMax((yyvsp[0].dval));
      }
#line 8292 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 634: /* constraints_end: K_END K_CONSTRAINTS  */
#line 3635 "def/def.y"
      { if ((defData->VersionNum < 5.4) && defData->callbacks->ConstraintsEndCbk) {
          CALLBACK(defData->callbacks->ConstraintsEndCbk, defrConstraintsEndCbkType, 0);
        } else {
          if (defData->callbacks->ConstraintsEndCbk) {
            if (defData->constraintWarnings++ < defData->settings->ConstraintWarnings)
              defData->defWarning(7032, "The CONSTRAINTS statement is obsolete in version 5.4 and later.\nThe DEF parser will ignore this statement.");
          }
        }
      }
#line 8306 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 635: /* assertions_end: K_END K_ASSERTIONS  */
#line 3646 "def/def.y"
      { if ((defData->VersionNum < 5.4) && defData->callbacks->AssertionsEndCbk) {
          CALLBACK(defData->callbacks->AssertionsEndCbk, defrAssertionsEndCbkType, 0);
        } else {
          if (defData->callbacks->AssertionsEndCbk) {
            if (defData->assertionWarnings++ < defData->settings->AssertionWarnings)
              defData->defWarning(7031, "The ASSERTIONS statement is obsolete in version 5.4 and later.\nThe DEF parser will ignore this statement.");
          }
        }
      }
#line 8320 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 637: /* scanchain_start: K_SCANCHAINS NUMBER ';'  */
#line 3660 "def/def.y"
      { if (defData->callbacks->ScanchainsStartCbk)
          CALLBACK(defData->callbacks->ScanchainsStartCbk, defrScanchainsStartCbkType,
                   ROUND((yyvsp[-1].dval)));
      }
#line 8329 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 639: /* scanchain_rules: scanchain_rules scan_rule  */
#line 3667 "def/def.y"
      {}
#line 8335 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 640: /* scan_rule: start_scan scan_members ';'  */
#line 3670 "def/def.y"
      { 
        if (defData->callbacks->ScanchainCbk)
          CALLBACK(defData->callbacks->ScanchainCbk, defrScanchainCbkType, &defData->Scanchain);
      }
#line 8344 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 641: /* $@110: %empty  */
#line 3675 "def/def.y"
                {defData->dumb_mode = 1; defData->no_num = 1;}
#line 8350 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 642: /* start_scan: '-' $@110 T_STRING  */
#line 3676 "def/def.y"
      {
        if (defData->callbacks->ScanchainCbk)
          defData->Scanchain.setName((yyvsp[0].string));
        defData->bit_is_keyword = TRUE;
      }
#line 8360 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 645: /* opt_pin: %empty  */
#line 3688 "def/def.y"
      { (yyval.string) = (char*)""; }
#line 8366 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 646: /* opt_pin: T_STRING  */
#line 3690 "def/def.y"
      { (yyval.string) = (yyvsp[0].string); }
#line 8372 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 647: /* $@111: %empty  */
#line 3692 "def/def.y"
                         {defData->dumb_mode = 2; defData->no_num = 2;}
#line 8378 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 648: /* scan_member: '+' K_START $@111 T_STRING opt_pin  */
#line 3693 "def/def.y"
      { if (defData->callbacks->ScanchainCbk)
          defData->Scanchain.setStart((yyvsp[-1].string), (yyvsp[0].string));
      }
#line 8386 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 649: /* $@112: %empty  */
#line 3696 "def/def.y"
                       { defData->dumb_mode = 1; defData->no_num = 1; }
#line 8392 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 650: /* scan_member: '+' K_FLOATING $@112 floating_inst_list  */
#line 3697 "def/def.y"
      { defData->dumb_mode = 0; defData->no_num = 0; }
#line 8398 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 651: /* $@113: %empty  */
#line 3699 "def/def.y"
      {
         defData->dumb_mode = 1;
         defData->no_num = 1;
         if (defData->callbacks->ScanchainCbk)
           defData->Scanchain.addOrderedList();
      }
#line 8409 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 652: /* scan_member: '+' K_ORDERED $@113 ordered_inst_list  */
#line 3706 "def/def.y"
      { defData->dumb_mode = 0; defData->no_num = 0; }
#line 8415 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 653: /* $@114: %empty  */
#line 3707 "def/def.y"
                   {defData->dumb_mode = 2; defData->no_num = 2; }
#line 8421 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 654: /* scan_member: '+' K_STOP $@114 T_STRING opt_pin  */
#line 3708 "def/def.y"
      { if (defData->callbacks->ScanchainCbk)
          defData->Scanchain.setStop((yyvsp[-1].string), (yyvsp[0].string));
      }
#line 8429 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 655: /* $@115: %empty  */
#line 3711 "def/def.y"
                             { defData->dumb_mode = 10; defData->no_num = 10; }
#line 8435 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 656: /* scan_member: '+' K_COMMONSCANPINS $@115 opt_common_pins  */
#line 3712 "def/def.y"
      { defData->dumb_mode = 0;  defData->no_num = 0; }
#line 8441 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 657: /* $@116: %empty  */
#line 3713 "def/def.y"
                        { defData->dumb_mode = 1; defData->no_num = 1; }
#line 8447 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 658: /* scan_member: '+' K_PARTITION $@116 T_STRING partition_maxbits  */
#line 3715 "def/def.y"
      {
        if (defData->VersionNum < 5.5) {
          if (defData->callbacks->ScanchainCbk) {
            if (defData->scanchainWarnings++ < defData->settings->ScanchainWarnings) {
              defData->defMsg = (char*)malloc(1000);
              sprintf (defData->defMsg,
                 "The PARTITION statement is available in version 5.5 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
              defData->defError(6538, defData->defMsg);
              free(defData->defMsg);
              CHKERR();
            }
          }
        }
        if (defData->callbacks->ScanchainCbk)
          defData->Scanchain.setPartition((yyvsp[-1].string), (yyvsp[0].integer));
      }
#line 8468 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 659: /* scan_member: extension_stmt  */
#line 3732 "def/def.y"
      {
        if (defData->callbacks->ScanChainExtCbk)
          CALLBACK(defData->callbacks->ScanChainExtCbk, defrScanChainExtCbkType, &defData->History_text[0]);
      }
#line 8477 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 660: /* opt_common_pins: %empty  */
#line 3738 "def/def.y"
      { }
#line 8483 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 661: /* opt_common_pins: '(' T_STRING T_STRING ')'  */
#line 3740 "def/def.y"
      {
        if (defData->callbacks->ScanchainCbk) {
          if (strcmp((yyvsp[-2].string), "IN") == 0 || strcmp((yyvsp[-2].string), "in") == 0)
            defData->Scanchain.setCommonIn((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "OUT") == 0 || strcmp((yyvsp[-2].string), "out") == 0)
            defData->Scanchain.setCommonOut((yyvsp[-1].string));
        }
      }
#line 8496 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 662: /* opt_common_pins: '(' T_STRING T_STRING ')' '(' T_STRING T_STRING ')'  */
#line 3749 "def/def.y"
      {
        if (defData->callbacks->ScanchainCbk) {
          if (strcmp((yyvsp[-6].string), "IN") == 0 || strcmp((yyvsp[-6].string), "in") == 0)
            defData->Scanchain.setCommonIn((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "OUT") == 0 || strcmp((yyvsp[-6].string), "out") == 0)
            defData->Scanchain.setCommonOut((yyvsp[-5].string));
          if (strcmp((yyvsp[-2].string), "IN") == 0 || strcmp((yyvsp[-2].string), "in") == 0)
            defData->Scanchain.setCommonIn((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "OUT") == 0 || strcmp((yyvsp[-2].string), "out") == 0)
            defData->Scanchain.setCommonOut((yyvsp[-1].string));
        }
      }
#line 8513 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 665: /* $@117: %empty  */
#line 3767 "def/def.y"
      {
        defData->dumb_mode = 1000;
        defData->no_num = 1000;
        if (defData->callbacks->ScanchainCbk)
          defData->Scanchain.addFloatingInst((yyvsp[0].string));
      }
#line 8524 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 666: /* one_floating_inst: T_STRING $@117 floating_pins  */
#line 3774 "def/def.y"
      { defData->dumb_mode = 1; defData->no_num = 1; }
#line 8530 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 667: /* floating_pins: %empty  */
#line 3777 "def/def.y"
      { }
#line 8536 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 668: /* floating_pins: '(' T_STRING T_STRING ')'  */
#line 3779 "def/def.y"
      {
        if (defData->callbacks->ScanchainCbk) {
          if (strcmp((yyvsp[-2].string), "IN") == 0 || strcmp((yyvsp[-2].string), "in") == 0)
            defData->Scanchain.addFloatingIn((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "OUT") == 0 || strcmp((yyvsp[-2].string), "out") == 0)
            defData->Scanchain.addFloatingOut((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "BITS") == 0 || strcmp((yyvsp[-2].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-1].string));
            defData->Scanchain.setFloatingBits(defData->bitsNum);
          }
        }
      }
#line 8553 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 669: /* floating_pins: '(' T_STRING T_STRING ')' '(' T_STRING T_STRING ')'  */
#line 3792 "def/def.y"
      {
        if (defData->callbacks->ScanchainCbk) {
          if (strcmp((yyvsp[-6].string), "IN") == 0 || strcmp((yyvsp[-6].string), "in") == 0)
            defData->Scanchain.addFloatingIn((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "OUT") == 0 || strcmp((yyvsp[-6].string), "out") == 0)
            defData->Scanchain.addFloatingOut((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "BITS") == 0 || strcmp((yyvsp[-6].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-5].string));
            defData->Scanchain.setFloatingBits(defData->bitsNum);
          }
          if (strcmp((yyvsp[-2].string), "IN") == 0 || strcmp((yyvsp[-2].string), "in") == 0)
            defData->Scanchain.addFloatingIn((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "OUT") == 0 || strcmp((yyvsp[-2].string), "out") == 0)
            defData->Scanchain.addFloatingOut((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "BITS") == 0 || strcmp((yyvsp[-2].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-1].string));
            defData->Scanchain.setFloatingBits(defData->bitsNum);
          }
        }
      }
#line 8578 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 670: /* floating_pins: '(' T_STRING T_STRING ')' '(' T_STRING T_STRING ')' '(' T_STRING T_STRING ')'  */
#line 3814 "def/def.y"
      {
        if (defData->callbacks->ScanchainCbk) {
          if (strcmp((yyvsp[-10].string), "IN") == 0 || strcmp((yyvsp[-10].string), "in") == 0)
            defData->Scanchain.addFloatingIn((yyvsp[-9].string));
          else if (strcmp((yyvsp[-10].string), "OUT") == 0 || strcmp((yyvsp[-10].string), "out") == 0)
            defData->Scanchain.addFloatingOut((yyvsp[-9].string));
          else if (strcmp((yyvsp[-10].string), "BITS") == 0 || strcmp((yyvsp[-10].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-9].string));
            defData->Scanchain.setFloatingBits(defData->bitsNum);
          }
          if (strcmp((yyvsp[-6].string), "IN") == 0 || strcmp((yyvsp[-6].string), "in") == 0)
            defData->Scanchain.addFloatingIn((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "OUT") == 0 || strcmp((yyvsp[-6].string), "out") == 0)
            defData->Scanchain.addFloatingOut((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "BITS") == 0 || strcmp((yyvsp[-6].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-5].string));
            defData->Scanchain.setFloatingBits(defData->bitsNum);
          }
          if (strcmp((yyvsp[-2].string), "IN") == 0 || strcmp((yyvsp[-2].string), "in") == 0)
            defData->Scanchain.addFloatingIn((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "OUT") == 0 || strcmp((yyvsp[-2].string), "out") == 0)
            defData->Scanchain.addFloatingOut((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "BITS") == 0 || strcmp((yyvsp[-2].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-1].string));
            defData->Scanchain.setFloatingBits(defData->bitsNum);
          }
        }
      }
#line 8611 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 673: /* $@118: %empty  */
#line 3848 "def/def.y"
      { defData->dumb_mode = 1000; defData->no_num = 1000; 
        if (defData->callbacks->ScanchainCbk)
          defData->Scanchain.addOrderedInst((yyvsp[0].string));
      }
#line 8620 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 674: /* one_ordered_inst: T_STRING $@118 ordered_pins  */
#line 3853 "def/def.y"
      { defData->dumb_mode = 1; defData->no_num = 1; }
#line 8626 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 675: /* ordered_pins: %empty  */
#line 3856 "def/def.y"
      { }
#line 8632 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 676: /* ordered_pins: '(' T_STRING T_STRING ')'  */
#line 3858 "def/def.y"
      {
        if (defData->callbacks->ScanchainCbk) {
          if (strcmp((yyvsp[-2].string), "IN") == 0 || strcmp((yyvsp[-2].string), "in") == 0)
            defData->Scanchain.addOrderedIn((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "OUT") == 0 || strcmp((yyvsp[-2].string), "out") == 0)
            defData->Scanchain.addOrderedOut((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "BITS") == 0 || strcmp((yyvsp[-2].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-1].string));
            defData->Scanchain.setOrderedBits(defData->bitsNum);
         }
        }
      }
#line 8649 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 677: /* ordered_pins: '(' T_STRING T_STRING ')' '(' T_STRING T_STRING ')'  */
#line 3871 "def/def.y"
      {
        if (defData->callbacks->ScanchainCbk) {
          if (strcmp((yyvsp[-6].string), "IN") == 0 || strcmp((yyvsp[-6].string), "in") == 0)
            defData->Scanchain.addOrderedIn((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "OUT") == 0 || strcmp((yyvsp[-6].string), "out") == 0)
            defData->Scanchain.addOrderedOut((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "BITS") == 0 || strcmp((yyvsp[-6].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-5].string));
            defData->Scanchain.setOrderedBits(defData->bitsNum);
          }
          if (strcmp((yyvsp[-2].string), "IN") == 0 || strcmp((yyvsp[-2].string), "in") == 0)
            defData->Scanchain.addOrderedIn((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "OUT") == 0 || strcmp((yyvsp[-2].string), "out") == 0)
            defData->Scanchain.addOrderedOut((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "BITS") == 0 || strcmp((yyvsp[-2].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-1].string));
            defData->Scanchain.setOrderedBits(defData->bitsNum);
          }
        }
      }
#line 8674 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 678: /* ordered_pins: '(' T_STRING T_STRING ')' '(' T_STRING T_STRING ')' '(' T_STRING T_STRING ')'  */
#line 3893 "def/def.y"
      {
        if (defData->callbacks->ScanchainCbk) {
          if (strcmp((yyvsp[-10].string), "IN") == 0 || strcmp((yyvsp[-10].string), "in") == 0)
            defData->Scanchain.addOrderedIn((yyvsp[-9].string));
          else if (strcmp((yyvsp[-10].string), "OUT") == 0 || strcmp((yyvsp[-10].string), "out") == 0)
            defData->Scanchain.addOrderedOut((yyvsp[-9].string));
          else if (strcmp((yyvsp[-10].string), "BITS") == 0 || strcmp((yyvsp[-10].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-9].string));
            defData->Scanchain.setOrderedBits(defData->bitsNum);
          }
          if (strcmp((yyvsp[-6].string), "IN") == 0 || strcmp((yyvsp[-6].string), "in") == 0)
            defData->Scanchain.addOrderedIn((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "OUT") == 0 || strcmp((yyvsp[-6].string), "out") == 0)
            defData->Scanchain.addOrderedOut((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "BITS") == 0 || strcmp((yyvsp[-6].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-5].string));
            defData->Scanchain.setOrderedBits(defData->bitsNum);
          }
          if (strcmp((yyvsp[-2].string), "IN") == 0 || strcmp((yyvsp[-2].string), "in") == 0)
            defData->Scanchain.addOrderedIn((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "OUT") == 0 || strcmp((yyvsp[-2].string), "out") == 0)
            defData->Scanchain.addOrderedOut((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "BITS") == 0 || strcmp((yyvsp[-2].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-1].string));
            defData->Scanchain.setOrderedBits(defData->bitsNum);
          }
        }
      }
#line 8707 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 679: /* partition_maxbits: %empty  */
#line 3923 "def/def.y"
      { (yyval.integer) = -1; }
#line 8713 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 680: /* partition_maxbits: K_MAXBITS NUMBER  */
#line 3925 "def/def.y"
      { (yyval.integer) = ROUND((yyvsp[0].dval)); }
#line 8719 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 681: /* scanchain_end: K_END K_SCANCHAINS  */
#line 3928 "def/def.y"
      { 
        if (defData->callbacks->ScanchainsEndCbk)
          CALLBACK(defData->callbacks->ScanchainsEndCbk, defrScanchainsEndCbkType, 0);
        defData->bit_is_keyword = FALSE;
        defData->dumb_mode = 0; defData->no_num = 0;
      }
#line 8730 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 683: /* iotiming_start: K_IOTIMINGS NUMBER ';'  */
#line 3940 "def/def.y"
      {
        if (defData->VersionNum < 5.4 && defData->callbacks->IOTimingsStartCbk) {
          CALLBACK(defData->callbacks->IOTimingsStartCbk, defrIOTimingsStartCbkType, ROUND((yyvsp[-1].dval)));
        } else {
          if (defData->callbacks->IOTimingsStartCbk)
            if (defData->iOTimingWarnings++ < defData->settings->IOTimingWarnings)
              defData->defWarning(7035, "The IOTIMINGS statement is obsolete in version 5.4 and later.\nThe DEF parser will ignore this statement.");
        }
      }
#line 8744 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 685: /* iotiming_rules: iotiming_rules iotiming_rule  */
#line 3952 "def/def.y"
      { }
#line 8750 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 686: /* iotiming_rule: start_iotiming iotiming_members ';'  */
#line 3955 "def/def.y"
      { 
        if (defData->VersionNum < 5.4 && defData->callbacks->IOTimingCbk)
          CALLBACK(defData->callbacks->IOTimingCbk, defrIOTimingCbkType, &defData->IOTiming);
      }
#line 8759 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 687: /* $@119: %empty  */
#line 3960 "def/def.y"
                        {defData->dumb_mode = 2; defData->no_num = 2; }
#line 8765 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 688: /* start_iotiming: '-' '(' $@119 T_STRING T_STRING ')'  */
#line 3961 "def/def.y"
      {
        if (defData->callbacks->IOTimingCbk)
          defData->IOTiming.setName((yyvsp[-2].string), (yyvsp[-1].string));
      }
#line 8774 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 691: /* iotiming_member: '+' risefall K_VARIABLE NUMBER NUMBER  */
#line 3972 "def/def.y"
      {
        if (defData->callbacks->IOTimingCbk) 
          defData->IOTiming.setVariable((yyvsp[-3].string), (yyvsp[-1].dval), (yyvsp[0].dval));
      }
#line 8783 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 692: /* iotiming_member: '+' risefall K_SLEWRATE NUMBER NUMBER  */
#line 3977 "def/def.y"
      {
        if (defData->callbacks->IOTimingCbk) 
          defData->IOTiming.setSlewRate((yyvsp[-3].string), (yyvsp[-1].dval), (yyvsp[0].dval));
      }
#line 8792 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 693: /* iotiming_member: '+' K_CAPACITANCE NUMBER  */
#line 3982 "def/def.y"
      {
        if (defData->callbacks->IOTimingCbk) 
          defData->IOTiming.setCapacitance((yyvsp[0].dval));
      }
#line 8801 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 694: /* $@120: %empty  */
#line 3986 "def/def.y"
                        {defData->dumb_mode = 1; defData->no_num = 1; }
#line 8807 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 695: /* $@121: %empty  */
#line 3987 "def/def.y"
      {
        if (defData->callbacks->IOTimingCbk) 
          defData->IOTiming.setDriveCell((yyvsp[0].string));
      }
#line 8816 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 697: /* iotiming_member: extension_stmt  */
#line 3996 "def/def.y"
      {
        if (defData->VersionNum < 5.4 && defData->callbacks->IoTimingsExtCbk)
          CALLBACK(defData->callbacks->IoTimingsExtCbk, defrIoTimingsExtCbkType, &defData->History_text[0]);
      }
#line 8825 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 698: /* $@122: %empty  */
#line 4002 "def/def.y"
              {defData->dumb_mode = 1; defData->no_num = 1; }
#line 8831 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 699: /* $@123: %empty  */
#line 4003 "def/def.y"
      {
        if (defData->callbacks->IOTimingCbk) 
          defData->IOTiming.setTo((yyvsp[0].string));
      }
#line 8840 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 702: /* $@124: %empty  */
#line 4010 "def/def.y"
                  {defData->dumb_mode = 1; defData->no_num = 1; }
#line 8846 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 703: /* iotiming_frompin: K_FROMPIN $@124 T_STRING  */
#line 4011 "def/def.y"
      {
        if (defData->callbacks->IOTimingCbk)
          defData->IOTiming.setFrom((yyvsp[0].string));
      }
#line 8855 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 705: /* iotiming_parallel: K_PARALLEL NUMBER  */
#line 4018 "def/def.y"
      {
        if (defData->callbacks->IOTimingCbk)
          defData->IOTiming.setParallel((yyvsp[0].dval));
      }
#line 8864 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 706: /* risefall: K_RISE  */
#line 4023 "def/def.y"
                 { (yyval.string) = (char*)"RISE"; }
#line 8870 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 707: /* risefall: K_FALL  */
#line 4023 "def/def.y"
                                                  { (yyval.string) = (char*)"FALL"; }
#line 8876 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 708: /* iotiming_end: K_END K_IOTIMINGS  */
#line 4026 "def/def.y"
      {
        if (defData->VersionNum < 5.4 && defData->callbacks->IOTimingsEndCbk)
          CALLBACK(defData->callbacks->IOTimingsEndCbk, defrIOTimingsEndCbkType, 0);
      }
#line 8885 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 709: /* floorplan_contraints_section: fp_start fp_stmts K_END K_FPC  */
#line 4032 "def/def.y"
      { 
        if (defData->callbacks->FPCEndCbk)
          CALLBACK(defData->callbacks->FPCEndCbk, defrFPCEndCbkType, 0);
      }
#line 8894 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 710: /* fp_start: K_FPC NUMBER ';'  */
#line 4038 "def/def.y"
      {
        if (defData->callbacks->FPCStartCbk)
          CALLBACK(defData->callbacks->FPCStartCbk, defrFPCStartCbkType, ROUND((yyvsp[-1].dval)));
      }
#line 8903 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 712: /* fp_stmts: fp_stmts fp_stmt  */
#line 4045 "def/def.y"
      {}
#line 8909 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 713: /* $@125: %empty  */
#line 4047 "def/def.y"
             { defData->dumb_mode = 1; defData->no_num = 1;  }
#line 8915 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 714: /* $@126: %empty  */
#line 4048 "def/def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.setName((yyvsp[-1].string), (yyvsp[0].string)); }
#line 8921 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 715: /* fp_stmt: '-' $@125 T_STRING h_or_v $@126 constraint_type constrain_what_list ';'  */
#line 4050 "def/def.y"
      { if (defData->callbacks->FPCCbk) CALLBACK(defData->callbacks->FPCCbk, defrFPCCbkType, &defData->FPC); }
#line 8927 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 716: /* h_or_v: K_HORIZONTAL  */
#line 4053 "def/def.y"
      { (yyval.string) = (char*)"HORIZONTAL"; }
#line 8933 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 717: /* h_or_v: K_VERTICAL  */
#line 4055 "def/def.y"
      { (yyval.string) = (char*)"VERTICAL"; }
#line 8939 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 718: /* constraint_type: K_ALIGN  */
#line 4058 "def/def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.setAlign(); }
#line 8945 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 719: /* constraint_type: K_MAX NUMBER  */
#line 4060 "def/def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.setMax((yyvsp[0].dval)); }
#line 8951 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 720: /* constraint_type: K_MIN NUMBER  */
#line 4062 "def/def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.setMin((yyvsp[0].dval)); }
#line 8957 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 721: /* constraint_type: K_EQUAL NUMBER  */
#line 4064 "def/def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.setEqual((yyvsp[0].dval)); }
#line 8963 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 724: /* $@127: %empty  */
#line 4071 "def/def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.setDoingBottomLeft(); }
#line 8969 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 726: /* $@128: %empty  */
#line 4074 "def/def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.setDoingTopRight(); }
#line 8975 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 730: /* $@129: %empty  */
#line 4081 "def/def.y"
                         {defData->dumb_mode = 1; defData->no_num = 1; }
#line 8981 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 731: /* row_or_comp: '(' K_ROWS $@129 T_STRING ')'  */
#line 4082 "def/def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.addRow((yyvsp[-1].string)); }
#line 8987 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 732: /* $@130: %empty  */
#line 4083 "def/def.y"
                       {defData->dumb_mode = 1; defData->no_num = 1; }
#line 8993 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 733: /* row_or_comp: '(' K_COMPS $@130 T_STRING ')'  */
#line 4084 "def/def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.addComps((yyvsp[-1].string)); }
#line 8999 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 735: /* timingdisables_start: K_TIMINGDISABLES NUMBER ';'  */
#line 4091 "def/def.y"
      { 
        if (defData->callbacks->TimingDisablesStartCbk)
          CALLBACK(defData->callbacks->TimingDisablesStartCbk, defrTimingDisablesStartCbkType,
                   ROUND((yyvsp[-1].dval)));
      }
#line 9009 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 737: /* timingdisables_rules: timingdisables_rules timingdisables_rule  */
#line 4099 "def/def.y"
      {}
#line 9015 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 738: /* $@131: %empty  */
#line 4101 "def/def.y"
                                   { defData->dumb_mode = 2; defData->no_num = 2;  }
#line 9021 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 739: /* $@132: %empty  */
#line 4102 "def/def.y"
                       { defData->dumb_mode = 2; defData->no_num = 2;  }
#line 9027 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 740: /* timingdisables_rule: '-' K_FROMPIN $@131 T_STRING T_STRING K_TOPIN $@132 T_STRING T_STRING ';'  */
#line 4103 "def/def.y"
      {
        if (defData->callbacks->TimingDisableCbk) {
          defData->TimingDisable.setFromTo((yyvsp[-6].string), (yyvsp[-5].string), (yyvsp[-2].string), (yyvsp[-1].string));
          CALLBACK(defData->callbacks->TimingDisableCbk, defrTimingDisableCbkType,
                &defData->TimingDisable);
        }
      }
#line 9039 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 741: /* $@133: %empty  */
#line 4110 "def/def.y"
                      {defData->dumb_mode = 2; defData->no_num = 2; }
#line 9045 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 742: /* timingdisables_rule: '-' K_THRUPIN $@133 T_STRING T_STRING ';'  */
#line 4111 "def/def.y"
      {
        if (defData->callbacks->TimingDisableCbk) {
          defData->TimingDisable.setThru((yyvsp[-2].string), (yyvsp[-1].string));
          CALLBACK(defData->callbacks->TimingDisableCbk, defrTimingDisableCbkType,
                   &defData->TimingDisable);
        }
      }
#line 9057 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 743: /* $@134: %empty  */
#line 4118 "def/def.y"
                    {defData->dumb_mode = 1; defData->no_num = 1;}
#line 9063 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 744: /* timingdisables_rule: '-' K_MACRO $@134 T_STRING td_macro_option ';'  */
#line 4119 "def/def.y"
      {
        if (defData->callbacks->TimingDisableCbk) {
          defData->TimingDisable.setMacro((yyvsp[-2].string));
          CALLBACK(defData->callbacks->TimingDisableCbk, defrTimingDisableCbkType,
                &defData->TimingDisable);
        }
      }
#line 9075 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 745: /* timingdisables_rule: '-' K_REENTRANTPATHS ';'  */
#line 4127 "def/def.y"
      { if (defData->callbacks->TimingDisableCbk)
          defData->TimingDisable.setReentrantPathsFlag();
      }
#line 9083 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 746: /* $@135: %empty  */
#line 4132 "def/def.y"
                           {defData->dumb_mode = 1; defData->no_num = 1;}
#line 9089 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 747: /* $@136: %empty  */
#line 4133 "def/def.y"
      {defData->dumb_mode=1; defData->no_num = 1;}
#line 9095 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 748: /* td_macro_option: K_FROMPIN $@135 T_STRING K_TOPIN $@136 T_STRING  */
#line 4134 "def/def.y"
      {
        if (defData->callbacks->TimingDisableCbk)
          defData->TimingDisable.setMacroFromTo((yyvsp[-3].string),(yyvsp[0].string));
      }
#line 9104 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 749: /* $@137: %empty  */
#line 4138 "def/def.y"
                         {defData->dumb_mode=1; defData->no_num = 1;}
#line 9110 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 750: /* td_macro_option: K_THRUPIN $@137 T_STRING  */
#line 4139 "def/def.y"
      {
        if (defData->callbacks->TimingDisableCbk)
          defData->TimingDisable.setMacroThru((yyvsp[0].string));
      }
#line 9119 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 751: /* timingdisables_end: K_END K_TIMINGDISABLES  */
#line 4145 "def/def.y"
      { 
        if (defData->callbacks->TimingDisablesEndCbk)
          CALLBACK(defData->callbacks->TimingDisablesEndCbk, defrTimingDisablesEndCbkType, 0);
      }
#line 9128 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 753: /* partitions_start: K_PARTITIONS NUMBER ';'  */
#line 4155 "def/def.y"
      {
        if (defData->callbacks->PartitionsStartCbk)
          CALLBACK(defData->callbacks->PartitionsStartCbk, defrPartitionsStartCbkType,
                   ROUND((yyvsp[-1].dval)));
      }
#line 9138 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 755: /* partition_rules: partition_rules partition_rule  */
#line 4163 "def/def.y"
      { }
#line 9144 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 756: /* partition_rule: start_partition partition_members ';'  */
#line 4166 "def/def.y"
      { 
        if (defData->callbacks->PartitionCbk)
          CALLBACK(defData->callbacks->PartitionCbk, defrPartitionCbkType, &defData->Partition);
      }
#line 9153 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 757: /* $@138: %empty  */
#line 4171 "def/def.y"
                     { defData->dumb_mode = 1; defData->no_num = 1; }
#line 9159 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 758: /* start_partition: '-' $@138 T_STRING turnoff  */
#line 4172 "def/def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setName((yyvsp[-1].string));
      }
#line 9168 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 760: /* turnoff: K_TURNOFF turnoff_setup turnoff_hold  */
#line 4179 "def/def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.addTurnOff((yyvsp[-1].string), (yyvsp[0].string));
      }
#line 9177 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 761: /* turnoff_setup: %empty  */
#line 4185 "def/def.y"
      { (yyval.string) = (char*)" "; }
#line 9183 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 762: /* turnoff_setup: K_SETUPRISE  */
#line 4187 "def/def.y"
      { (yyval.string) = (char*)"R"; }
#line 9189 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 763: /* turnoff_setup: K_SETUPFALL  */
#line 4189 "def/def.y"
      { (yyval.string) = (char*)"F"; }
#line 9195 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 764: /* turnoff_hold: %empty  */
#line 4192 "def/def.y"
      { (yyval.string) = (char*)" "; }
#line 9201 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 765: /* turnoff_hold: K_HOLDRISE  */
#line 4194 "def/def.y"
      { (yyval.string) = (char*)"R"; }
#line 9207 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 766: /* turnoff_hold: K_HOLDFALL  */
#line 4196 "def/def.y"
      { (yyval.string) = (char*)"F"; }
#line 9213 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 769: /* $@139: %empty  */
#line 4202 "def/def.y"
                                     {defData->dumb_mode=2; defData->no_num = 2;}
#line 9219 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 770: /* partition_member: '+' K_FROMCLOCKPIN $@139 T_STRING T_STRING risefall minmaxpins  */
#line 4204 "def/def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setFromClockPin((yyvsp[-3].string), (yyvsp[-2].string));
      }
#line 9228 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 771: /* $@140: %empty  */
#line 4208 "def/def.y"
                          {defData->dumb_mode=2; defData->no_num = 2; }
#line 9234 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 772: /* partition_member: '+' K_FROMCOMPPIN $@140 T_STRING T_STRING risefallminmax2_list  */
#line 4210 "def/def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setFromCompPin((yyvsp[-2].string), (yyvsp[-1].string));
      }
#line 9243 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 773: /* $@141: %empty  */
#line 4214 "def/def.y"
                        {defData->dumb_mode=1; defData->no_num = 1; }
#line 9249 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 774: /* partition_member: '+' K_FROMIOPIN $@141 T_STRING risefallminmax1_list  */
#line 4216 "def/def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setFromIOPin((yyvsp[-1].string));
      }
#line 9258 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 775: /* $@142: %empty  */
#line 4220 "def/def.y"
                         {defData->dumb_mode=2; defData->no_num = 2; }
#line 9264 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 776: /* partition_member: '+' K_TOCLOCKPIN $@142 T_STRING T_STRING risefall minmaxpins  */
#line 4222 "def/def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setToClockPin((yyvsp[-3].string), (yyvsp[-2].string));
      }
#line 9273 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 777: /* $@143: %empty  */
#line 4226 "def/def.y"
                        {defData->dumb_mode=2; defData->no_num = 2; }
#line 9279 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 778: /* partition_member: '+' K_TOCOMPPIN $@143 T_STRING T_STRING risefallminmax2_list  */
#line 4228 "def/def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setToCompPin((yyvsp[-2].string), (yyvsp[-1].string));
      }
#line 9288 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 779: /* $@144: %empty  */
#line 4232 "def/def.y"
                      {defData->dumb_mode=1; defData->no_num = 2; }
#line 9294 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 780: /* partition_member: '+' K_TOIOPIN $@144 T_STRING risefallminmax1_list  */
#line 4233 "def/def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setToIOPin((yyvsp[-1].string));
      }
#line 9303 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 781: /* partition_member: extension_stmt  */
#line 4238 "def/def.y"
      { 
        if (defData->callbacks->PartitionsExtCbk)
          CALLBACK(defData->callbacks->PartitionsExtCbk, defrPartitionsExtCbkType,
                   &defData->History_text[0]);
      }
#line 9313 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 782: /* $@145: %empty  */
#line 4245 "def/def.y"
      { defData->dumb_mode = DEF_MAX_INT; defData->no_num = DEF_MAX_INT; }
#line 9319 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 783: /* minmaxpins: min_or_max_list K_PINS $@145 pin_list  */
#line 4246 "def/def.y"
      { defData->dumb_mode = 0; defData->no_num = 0; }
#line 9325 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 785: /* min_or_max_list: min_or_max_list min_or_max_member  */
#line 4250 "def/def.y"
      { }
#line 9331 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 786: /* min_or_max_member: K_MIN NUMBER NUMBER  */
#line 4253 "def/def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setMin((yyvsp[-1].dval), (yyvsp[0].dval));
      }
#line 9340 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 787: /* min_or_max_member: K_MAX NUMBER NUMBER  */
#line 4258 "def/def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setMax((yyvsp[-1].dval), (yyvsp[0].dval));
      }
#line 9349 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 789: /* pin_list: pin_list T_STRING  */
#line 4265 "def/def.y"
      { if (defData->callbacks->PartitionCbk) defData->Partition.addPin((yyvsp[0].string)); }
#line 9355 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 792: /* risefallminmax1: K_RISEMIN NUMBER  */
#line 4271 "def/def.y"
      { if (defData->callbacks->PartitionCbk) defData->Partition.addRiseMin((yyvsp[0].dval)); }
#line 9361 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 793: /* risefallminmax1: K_FALLMIN NUMBER  */
#line 4273 "def/def.y"
      { if (defData->callbacks->PartitionCbk) defData->Partition.addFallMin((yyvsp[0].dval)); }
#line 9367 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 794: /* risefallminmax1: K_RISEMAX NUMBER  */
#line 4275 "def/def.y"
      { if (defData->callbacks->PartitionCbk) defData->Partition.addRiseMax((yyvsp[0].dval)); }
#line 9373 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 795: /* risefallminmax1: K_FALLMAX NUMBER  */
#line 4277 "def/def.y"
      { if (defData->callbacks->PartitionCbk) defData->Partition.addFallMax((yyvsp[0].dval)); }
#line 9379 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 798: /* risefallminmax2: K_RISEMIN NUMBER NUMBER  */
#line 4285 "def/def.y"
      { if (defData->callbacks->PartitionCbk)
          defData->Partition.addRiseMinRange((yyvsp[-1].dval), (yyvsp[0].dval)); }
#line 9386 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 799: /* risefallminmax2: K_FALLMIN NUMBER NUMBER  */
#line 4288 "def/def.y"
      { if (defData->callbacks->PartitionCbk)
          defData->Partition.addFallMinRange((yyvsp[-1].dval), (yyvsp[0].dval)); }
#line 9393 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 800: /* risefallminmax2: K_RISEMAX NUMBER NUMBER  */
#line 4291 "def/def.y"
      { if (defData->callbacks->PartitionCbk)
          defData->Partition.addRiseMaxRange((yyvsp[-1].dval), (yyvsp[0].dval)); }
#line 9400 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 801: /* risefallminmax2: K_FALLMAX NUMBER NUMBER  */
#line 4294 "def/def.y"
      { if (defData->callbacks->PartitionCbk)
          defData->Partition.addFallMaxRange((yyvsp[-1].dval), (yyvsp[0].dval)); }
#line 9407 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 802: /* partitions_end: K_END K_PARTITIONS  */
#line 4298 "def/def.y"
      { if (defData->callbacks->PartitionsEndCbk)
          CALLBACK(defData->callbacks->PartitionsEndCbk, defrPartitionsEndCbkType, 0); }
#line 9414 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 804: /* comp_names: comp_names comp_name  */
#line 4303 "def/def.y"
      { }
#line 9420 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 805: /* $@146: %empty  */
#line 4305 "def/def.y"
               {defData->dumb_mode=2; defData->no_num = 2; }
#line 9426 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 806: /* comp_name: '(' $@146 T_STRING T_STRING subnet_opt_syn ')'  */
#line 4307 "def/def.y"
      {
        // note that the defData->first T_STRING could be the keyword VPIN 
        if (defData->callbacks->NetCbk)
          defData->Subnet->addPin((yyvsp[-3].string), (yyvsp[-2].string), (yyvsp[-1].integer));
      }
#line 9436 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 807: /* subnet_opt_syn: %empty  */
#line 4314 "def/def.y"
      { (yyval.integer) = 0; }
#line 9442 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 808: /* subnet_opt_syn: '+' K_SYNTHESIZED  */
#line 4316 "def/def.y"
      { (yyval.integer) = 1; }
#line 9448 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 811: /* $@147: %empty  */
#line 4322 "def/def.y"
      {  
        if (defData->callbacks->NetCbk) defData->Subnet->addWire((yyvsp[0].string));
      }
#line 9456 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 812: /* subnet_option: subnet_type $@147 paths  */
#line 4326 "def/def.y"
      {  
        defData->by_is_keyword = FALSE;
        defData->do_is_keyword = FALSE;
        defData->new_is_keyword = FALSE;
        defData->step_is_keyword = FALSE;
        defData->orient_is_keyword = FALSE;
        defData->needNPCbk = 0;
      }
#line 9469 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 813: /* $@148: %empty  */
#line 4334 "def/def.y"
                         { defData->dumb_mode = 1; defData->no_num = 1; }
#line 9475 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 814: /* subnet_option: K_NONDEFAULTRULE $@148 T_STRING  */
#line 4335 "def/def.y"
      { if (defData->callbacks->NetCbk) defData->Subnet->setNonDefault((yyvsp[0].string)); }
#line 9481 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 815: /* subnet_type: K_FIXED  */
#line 4338 "def/def.y"
      { (yyval.string) = (char*)"FIXED"; defData->dumb_mode = 1; }
#line 9487 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 816: /* subnet_type: K_COVER  */
#line 4340 "def/def.y"
      { (yyval.string) = (char*)"COVER"; defData->dumb_mode = 1; }
#line 9493 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 817: /* subnet_type: K_ROUTED  */
#line 4342 "def/def.y"
      { (yyval.string) = (char*)"ROUTED"; defData->dumb_mode = 1; }
#line 9499 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 818: /* subnet_type: K_NOSHIELD  */
#line 4344 "def/def.y"
      { (yyval.string) = (char*)"NOSHIELD"; defData->dumb_mode = 1; }
#line 9505 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 820: /* begin_pin_props: K_PINPROPERTIES NUMBER opt_semi  */
#line 4349 "def/def.y"
      { if (defData->callbacks->PinPropStartCbk)
          CALLBACK(defData->callbacks->PinPropStartCbk, defrPinPropStartCbkType, ROUND((yyvsp[-1].dval))); }
#line 9512 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 821: /* opt_semi: %empty  */
#line 4354 "def/def.y"
      { }
#line 9518 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 822: /* opt_semi: ';'  */
#line 4356 "def/def.y"
      { }
#line 9524 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 823: /* end_pin_props: K_END K_PINPROPERTIES  */
#line 4359 "def/def.y"
      { if (defData->callbacks->PinPropEndCbk)
          CALLBACK(defData->callbacks->PinPropEndCbk, defrPinPropEndCbkType, 0); }
#line 9531 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 826: /* $@149: %empty  */
#line 4366 "def/def.y"
                       { defData->dumb_mode = 2; defData->no_num = 2; }
#line 9537 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 827: /* $@150: %empty  */
#line 4367 "def/def.y"
      { if (defData->callbacks->PinPropCbk) defData->PinProp.setName((yyvsp[-1].string), (yyvsp[0].string)); }
#line 9543 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 828: /* pin_prop_terminal: '-' $@149 T_STRING T_STRING $@150 pin_prop_options ';'  */
#line 4369 "def/def.y"
      { if (defData->callbacks->PinPropCbk) {
          CALLBACK(defData->callbacks->PinPropCbk, defrPinPropCbkType, &defData->PinProp);
         // reset the property number
         defData->PinProp.clear();
        }
      }
#line 9554 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 831: /* $@151: %empty  */
#line 4379 "def/def.y"
                         { defData->dumb_mode = DEF_MAX_INT; }
#line 9560 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 832: /* pin_prop: '+' K_PROPERTY $@151 pin_prop_name_value_list  */
#line 4381 "def/def.y"
      { defData->dumb_mode = 0; }
#line 9566 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 835: /* pin_prop_name_value: T_STRING NUMBER  */
#line 4388 "def/def.y"
      {
        if (defData->callbacks->PinPropCbk) {
          char propTp;
          char* str = defData->ringCopy("                       ");
          propTp = defData->session->CompPinProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "PINPROPERTIES");
          sprintf(str, "%g", (yyvsp[0].dval));
          defData->PinProp.addNumProperty((yyvsp[-1].string), (yyvsp[0].dval), str, propTp);
        }
      }
#line 9581 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 836: /* pin_prop_name_value: T_STRING QSTRING  */
#line 4399 "def/def.y"
      {
        if (defData->callbacks->PinPropCbk) {
          char propTp;
          propTp = defData->session->CompPinProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "PINPROPERTIES");
          defData->PinProp.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
        }
      }
#line 9594 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 837: /* pin_prop_name_value: T_STRING T_STRING  */
#line 4408 "def/def.y"
      {
        if (defData->callbacks->PinPropCbk) {
          char propTp;
          propTp = defData->session->CompPinProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "PINPROPERTIES");
          defData->PinProp.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
        }
      }
#line 9607 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 839: /* blockage_start: K_BLOCKAGES NUMBER ';'  */
#line 4420 "def/def.y"
      { if (defData->callbacks->BlockageStartCbk)
          CALLBACK(defData->callbacks->BlockageStartCbk, defrBlockageStartCbkType, ROUND((yyvsp[-1].dval))); }
#line 9614 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 840: /* blockage_end: K_END K_BLOCKAGES  */
#line 4424 "def/def.y"
      { if (defData->callbacks->BlockageEndCbk)
          CALLBACK(defData->callbacks->BlockageEndCbk, defrBlockageEndCbkType, 0); }
#line 9621 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 843: /* blockage_def: blockage_rule rectPoly_blockage rectPoly_blockage_rules ';'  */
#line 4433 "def/def.y"
      {
        if (defData->callbacks->BlockageCbk) {
          CALLBACK(defData->callbacks->BlockageCbk, defrBlockageCbkType, &defData->Blockage);
          defData->Blockage.clear();
        }
      }
#line 9632 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 844: /* $@152: %empty  */
#line 4440 "def/def.y"
                           { defData->dumb_mode = 1; defData->no_num = 1; }
#line 9638 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 845: /* $@153: %empty  */
#line 4441 "def/def.y"
      {
        if (defData->callbacks->BlockageCbk) {
          if (defData->Blockage.hasPlacement() != 0) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6539, "Invalid BLOCKAGE statement defined in the DEF file. The BLOCKAGE statment has both the LAYER and the PLACEMENT statements defined.\nUpdate your DEF file to have either BLOCKAGE or PLACEMENT statement only.");
              CHKERR();
            }
          }
          defData->Blockage.setLayer((yyvsp[0].string));
          defData->Blockage.clearPoly(); // free poly, if any
        }
        defData->hasBlkLayerComp = 0;
        defData->hasBlkLayerSpac = 0;
        defData->hasBlkLayerTypeComp = 0;
      }
#line 9658 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 847: /* $@154: %empty  */
#line 4460 "def/def.y"
      {
        if (defData->callbacks->BlockageCbk) {
          if (defData->Blockage.hasLayer() != 0) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6539, "Invalid BLOCKAGE statement defined in the DEF file. The BLOCKAGE statment has both the LAYER and the PLACEMENT statements defined.\nUpdate your DEF file to have either BLOCKAGE or PLACEMENT statement only.");
              CHKERR();
            }
          }
          defData->Blockage.setPlacement();
          defData->Blockage.clearPoly(); // free poly, if any
        }
        defData->hasBlkPlaceComp = 0;
        defData->hasBlkPlaceTypeComp = 0;
      }
#line 9677 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 851: /* layer_blockage_rule: '+' K_SPACING NUMBER  */
#line 4481 "def/def.y"
      {
        if (defData->VersionNum < 5.6) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defMsg = (char*)malloc(1000);
              sprintf (defData->defMsg,
                 "The SPACING statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
              defData->defError(6540, defData->defMsg);
              free(defData->defMsg);
              CHKERR();
            }
          }
        } else if (defData->hasBlkLayerSpac) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6541, "The SPACING statement is defined in the LAYER statement,\nbut there is already either a SPACING statement or DESIGNRULEWIDTH  statement has defined in the LAYER statement.\nUpdate your DEF file to have either SPACING statement or a DESIGNRULEWIDTH statement.");
              CHKERR();
            }
          }
        } else {
          if (defData->callbacks->BlockageCbk)
            defData->Blockage.setSpacing((int)(yyvsp[0].dval));
          defData->hasBlkLayerSpac = 1;
        }
      }
#line 9707 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 852: /* layer_blockage_rule: '+' K_DESIGNRULEWIDTH NUMBER  */
#line 4507 "def/def.y"
      {
        if (defData->VersionNum < 5.6) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6541, "The SPACING statement is defined in the LAYER statement,\nbut there is already either a SPACING statement or DESIGNRULEWIDTH  statement has defined in the LAYER statement.\nUpdate your DEF file to have either SPACING statement or a DESIGNRULEWIDTH statement.");
              CHKERR();
            }
          }
        } else if (defData->hasBlkLayerSpac) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6541, "The SPACING statement is defined in the LAYER statement,\nbut there is already either a SPACING statement or DESIGNRULEWIDTH  statement has defined in the LAYER statement.\nUpdate your DEF file to have either SPACING statement or a DESIGNRULEWIDTH statement.");
              CHKERR();
            }
          }
        } else {
          if (defData->callbacks->BlockageCbk)
            defData->Blockage.setDesignRuleWidth((int)(yyvsp[0].dval));
          defData->hasBlkLayerSpac = 1;
        }
      }
#line 9733 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 855: /* mask_blockage_rule: '+' K_MASK NUMBER  */
#line 4533 "def/def.y"
      {      
        if (defData->validateMaskInput((int)(yyvsp[0].dval), defData->blockageWarnings, defData->settings->BlockageWarnings)) {
          defData->Blockage.setMask((int)(yyvsp[0].dval));
        }
      }
#line 9743 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 856: /* $@155: %empty  */
#line 4541 "def/def.y"
                      { defData->dumb_mode = 1; defData->no_num = 1; }
#line 9749 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 857: /* comp_blockage_rule: '+' K_COMPONENT $@155 T_STRING  */
#line 4542 "def/def.y"
      {
        if (defData->hasBlkLayerComp) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6542, "The defined BLOCKAGES COMPONENT statement has either COMPONENT, SLOTS, FILLS, PUSHDOWN or EXCEPTPGNET defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES COMPONENT statement per layer.");
              CHKERR();
            }
          }
        } else {
          if (defData->callbacks->BlockageCbk) {
            defData->Blockage.setComponent((yyvsp[0].string));
          }
          if (defData->VersionNum < 5.8) {
            defData->hasBlkLayerComp = 1;
          }
        }
      }
#line 9771 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 858: /* comp_blockage_rule: '+' K_SLOTS  */
#line 4561 "def/def.y"
      {
        if (defData->hasBlkLayerComp || defData->hasBlkLayerTypeComp) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6542, "The defined BLOCKAGES COMPONENT statement has either COMPONENT, SLOTS, FILLS, PUSHDOWN or EXCEPTPGNET defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES COMPONENT statement per layer.");
              CHKERR();
            }
          }
        } else {
          if (defData->callbacks->BlockageCbk) {
            defData->Blockage.setSlots();
          }
          if (defData->VersionNum < 5.8) {
            defData->hasBlkLayerComp = 1;
          }
          if (defData->VersionNum == 5.8) {
            defData->hasBlkLayerTypeComp = 1;
          }
        }
      }
#line 9796 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 859: /* comp_blockage_rule: '+' K_FILLS  */
#line 4582 "def/def.y"
      {
        if (defData->hasBlkLayerComp || defData->hasBlkLayerTypeComp) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6542, "The defined BLOCKAGES COMPONENT statement has either COMPONENT, SLOTS, FILLS, PUSHDOWN or EXCEPTPGNET defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES COMPONENT statement per layer.");
              CHKERR();
            }
          }
        } else {
          if (defData->callbacks->BlockageCbk){
            defData->Blockage.setFills();
          }
          if (defData->VersionNum < 5.8) {
            defData->hasBlkLayerComp = 1;
          }
          if (defData->VersionNum == 5.8) {
            defData->hasBlkLayerTypeComp = 1;
          }
        }
      }
#line 9821 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 860: /* comp_blockage_rule: '+' K_PUSHDOWN  */
#line 4603 "def/def.y"
      {
        if (defData->hasBlkLayerComp) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6542, "The defined BLOCKAGES COMPONENT statement has either COMPONENT, SLOTS, FILLS, PUSHDOWN or EXCEPTPGNET defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES COMPONENT statement per layer.");
              CHKERR();
            }
          }
        } else {
          if (defData->callbacks->BlockageCbk){
            defData->Blockage.setPushdown();
          }
          if (defData->VersionNum < 5.8) {
            defData->hasBlkLayerComp = 1;
          }
        }
      }
#line 9843 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 861: /* comp_blockage_rule: '+' K_EXCEPTPGNET  */
#line 4621 "def/def.y"
      {
        if (defData->VersionNum < 5.7) {
           if (defData->callbacks->BlockageCbk) {
             if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
               defData->defMsg = (char*)malloc(10000);
               sprintf (defData->defMsg,
                 "The EXCEPTPGNET is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
               defData->defError(6549, defData->defMsg);
               free(defData->defMsg);
               CHKERR();
              }
           }
        } else {
           if (defData->hasBlkLayerComp) {
             if (defData->callbacks->BlockageCbk) {
               if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
                 defData->defError(6542, "The defined BLOCKAGES COMPONENT statement has either COMPONENT, SLOTS, FILLS, PUSHDOWN or EXCEPTPGNET defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES COMPONENT statement per layer.");
                 CHKERR();
               }
             }
           } else {
             if (defData->callbacks->BlockageCbk){
               defData->Blockage.setExceptpgnet();
             }
             if (defData->VersionNum < 5.8){
               defData->hasBlkLayerComp = 1;
             }
           }
        }
      }
#line 9878 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 864: /* $@156: %empty  */
#line 4658 "def/def.y"
                      { defData->dumb_mode = 1; defData->no_num = 1; }
#line 9884 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 865: /* placement_comp_rule: '+' K_COMPONENT $@156 T_STRING  */
#line 4659 "def/def.y"
      {
        if (defData->hasBlkPlaceComp) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6543, "The defined BLOCKAGES PLACEMENT statement has either COMPONENT, PUSHDOWN, SOFT or PARTIAL defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES PLACEMENT statement.");
              CHKERR();
            }
          }
        } else {
          if (defData->callbacks->BlockageCbk){
            defData->Blockage.setComponent((yyvsp[0].string));
          }
          if (defData->VersionNum < 5.8) {
            defData->hasBlkPlaceComp = 1;
          }
        }
      }
#line 9906 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 866: /* placement_comp_rule: '+' K_PUSHDOWN  */
#line 4677 "def/def.y"
      {
        if (defData->hasBlkPlaceComp) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6543, "The defined BLOCKAGES PLACEMENT statement has either COMPONENT, PUSHDOWN, SOFT or PARTIAL defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES PLACEMENT statement.");
              CHKERR();
            }
          }
        } else {
          if (defData->callbacks->BlockageCbk){
            defData->Blockage.setPushdown();
          }
          if (defData->VersionNum < 5.8) {
            defData->hasBlkPlaceComp = 1;
          }
        }
      }
#line 9928 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 867: /* placement_comp_rule: '+' K_SOFT  */
#line 4695 "def/def.y"
      {
        if (defData->VersionNum < 5.7) {
           if (defData->callbacks->BlockageCbk) {
             if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
               defData->defMsg = (char*)malloc(10000);
               sprintf (defData->defMsg,
                 "The PLACEMENT SOFT is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
               defData->defError(6547, defData->defMsg);
               free(defData->defMsg);
               CHKERR();
             }
           }
        } else {
           if (defData->hasBlkPlaceComp || defData->hasBlkPlaceTypeComp) {
             if (defData->callbacks->BlockageCbk) {
               if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
                 defData->defError(6543, "The defined BLOCKAGES PLACEMENT statement has either COMPONENT, PUSHDOWN, SOFT or PARTIAL defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES PLACEMENT statement.");
                 CHKERR();
               }
             }
           } else {
             if (defData->callbacks->BlockageCbk){
               defData->Blockage.setSoft();
             }
             if (defData->VersionNum < 5.8) {
               defData->hasBlkPlaceComp = 1;
             }
             if (defData->VersionNum == 5.8) {
               defData->hasBlkPlaceTypeComp = 1;
             }
           }
        }
      }
#line 9966 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 868: /* placement_comp_rule: '+' K_PARTIAL NUMBER  */
#line 4729 "def/def.y"
      {
        if (defData->VersionNum < 5.7) {
           if (defData->callbacks->BlockageCbk) {
             if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
                defData->defMsg = (char*)malloc(10000);
                sprintf (defData->defMsg,
                  "The PARTIAL is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                defData->defError(6548, defData->defMsg);
                free(defData->defMsg);
                CHKERR();
             }
           }
        } else {
           if (defData->hasBlkPlaceComp || defData->hasBlkPlaceTypeComp) {
             if (defData->callbacks->BlockageCbk) {
               if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
                 defData->defError(6543, "The defined BLOCKAGES PLACEMENT statement has either COMPONENT, PUSHDOWN, SOFT or PARTIAL defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES PLACEMENT statement.");
                 CHKERR();
               }
             }
           } else {
             if (defData->callbacks->BlockageCbk){
               defData->Blockage.setPartial((yyvsp[0].dval));
             } 
             if (defData->VersionNum < 5.8) {
               defData->hasBlkPlaceComp = 1;
             }
             if (defData->VersionNum == 5.8) {
               defData->hasBlkPlaceTypeComp = 1;
             }
           }
         }
      }
#line 10004 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 871: /* rectPoly_blockage: K_RECT pt pt  */
#line 4769 "def/def.y"
      {
        if (defData->callbacks->BlockageCbk)
          defData->Blockage.addRect((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y);
      }
#line 10013 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 872: /* $@157: %empty  */
#line 4774 "def/def.y"
      {
        if (defData->callbacks->BlockageCbk) {
            defData->Geometries.Reset();
        }
      }
#line 10023 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 873: /* rectPoly_blockage: K_POLYGON $@157 firstPt nextPt nextPt otherPts  */
#line 4780 "def/def.y"
      {
        if (defData->callbacks->BlockageCbk) {
          if (defData->VersionNum >= 5.6) {  // only 5.6 and beyond
            if (defData->Blockage.hasLayer()) {  // only in layer
              if (defData->callbacks->BlockageCbk)
                defData->Blockage.addPolygon(&defData->Geometries);
            } else {
              if (defData->callbacks->BlockageCbk) {
                if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
                  defData->defError(6544, "A POLYGON statement is defined in the BLOCKAGE statement,\nbut it is not defined in the BLOCKAGE LAYER statement.\nUpdate your DEF file to either remove the POLYGON statement from the BLOCKAGE statement or\ndefine the POLYGON statement in a BLOCKAGE LAYER statement.");
                  CHKERR();
                }
              }
            }
          }
        }
      }
#line 10045 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 875: /* slot_start: K_SLOTS NUMBER ';'  */
#line 4802 "def/def.y"
      { if (defData->callbacks->SlotStartCbk)
          CALLBACK(defData->callbacks->SlotStartCbk, defrSlotStartCbkType, ROUND((yyvsp[-1].dval))); }
#line 10052 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 876: /* slot_end: K_END K_SLOTS  */
#line 4806 "def/def.y"
      { if (defData->callbacks->SlotEndCbk)
          CALLBACK(defData->callbacks->SlotEndCbk, defrSlotEndCbkType, 0); }
#line 10059 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 879: /* slot_def: slot_rule geom_slot_rules ';'  */
#line 4814 "def/def.y"
      {
        if (defData->callbacks->SlotCbk) {
          CALLBACK(defData->callbacks->SlotCbk, defrSlotCbkType, &defData->Slot);
          defData->Slot.clear();
        }
      }
#line 10070 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 880: /* $@158: %empty  */
#line 4821 "def/def.y"
                       { defData->dumb_mode = 1; defData->no_num = 1; }
#line 10076 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 881: /* $@159: %empty  */
#line 4822 "def/def.y"
      {
        if (defData->callbacks->SlotCbk) {
          defData->Slot.setLayer((yyvsp[0].string));
          defData->Slot.clearPoly();     // free poly, if any
        }
      }
#line 10087 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 885: /* geom_slot: K_RECT pt pt  */
#line 4834 "def/def.y"
      {
        if (defData->callbacks->SlotCbk)
          defData->Slot.addRect((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y);
      }
#line 10096 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 886: /* $@160: %empty  */
#line 4839 "def/def.y"
      {
          defData->Geometries.Reset();
      }
#line 10104 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 887: /* geom_slot: K_POLYGON $@160 firstPt nextPt nextPt otherPts  */
#line 4843 "def/def.y"
      {
        if (defData->VersionNum >= 5.6) {  // only 5.6 and beyond
          if (defData->callbacks->SlotCbk)
            defData->Slot.addPolygon(&defData->Geometries);
        }
      }
#line 10115 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 889: /* fill_start: K_FILLS NUMBER ';'  */
#line 4854 "def/def.y"
      { if (defData->callbacks->FillStartCbk)
          CALLBACK(defData->callbacks->FillStartCbk, defrFillStartCbkType, ROUND((yyvsp[-1].dval))); }
#line 10122 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 890: /* fill_end: K_END K_FILLS  */
#line 4858 "def/def.y"
      { if (defData->callbacks->FillEndCbk)
          CALLBACK(defData->callbacks->FillEndCbk, defrFillEndCbkType, 0); }
#line 10129 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 893: /* fill_def: fill_rule geom_fill_rules ';'  */
#line 4866 "def/def.y"
      {
        if (defData->callbacks->FillCbk) {
          CALLBACK(defData->callbacks->FillCbk, defrFillCbkType, &defData->Fill);
          defData->Fill.clear();
        }
      }
#line 10140 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 894: /* $@161: %empty  */
#line 4872 "def/def.y"
                  { defData->dumb_mode = 1; defData->no_num = 1; }
#line 10146 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 895: /* $@162: %empty  */
#line 4873 "def/def.y"
      {
        if (defData->callbacks->FillCbk) {
          defData->Fill.setVia((yyvsp[0].string));
          defData->Fill.clearPts();
          defData->Geometries.Reset();
        }
      }
#line 10158 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 897: /* $@163: %empty  */
#line 4882 "def/def.y"
                       { defData->dumb_mode = 1; defData->no_num = 1; }
#line 10164 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 898: /* $@164: %empty  */
#line 4883 "def/def.y"
      {
        if (defData->callbacks->FillCbk) {
          defData->Fill.setLayer((yyvsp[0].string));
          defData->Fill.clearPoly();    // free poly, if any
        }
      }
#line 10175 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 902: /* geom_fill: K_RECT pt pt  */
#line 4896 "def/def.y"
      {
        if (defData->callbacks->FillCbk)
          defData->Fill.addRect((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y);
      }
#line 10184 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 903: /* $@165: %empty  */
#line 4901 "def/def.y"
      {
        defData->Geometries.Reset();
      }
#line 10192 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 904: /* geom_fill: K_POLYGON $@165 firstPt nextPt nextPt otherPts  */
#line 4905 "def/def.y"
      {
        if (defData->VersionNum >= 5.6) {  // only 5.6 and beyond
          if (defData->callbacks->FillCbk)
            defData->Fill.addPolygon(&defData->Geometries);
        } else {
            defData->defMsg = (char*)malloc(10000);
            sprintf (defData->defMsg,
              "POLYGON statement in FILLS LAYER is a version 5.6 and later syntax.\nYour def file is defined with version %g.", defData->VersionNum);
            defData->defError(6564, defData->defMsg);
            free(defData->defMsg);
            CHKERR();
        }
      }
#line 10210 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 909: /* fill_layer_opc: '+' K_OPC  */
#line 4929 "def/def.y"
      {
        if (defData->VersionNum < 5.7) {
           if (defData->callbacks->FillCbk) {
             if (defData->fillWarnings++ < defData->settings->FillWarnings) {
               defData->defMsg = (char*)malloc(10000);
               sprintf (defData->defMsg,
                 "The LAYER OPC is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
               defData->defError(6553, defData->defMsg);
               free(defData->defMsg);
               CHKERR();
             }
           }
        } else {
           if (defData->callbacks->FillCbk)
             defData->Fill.setLayerOpc();
        }
      }
#line 10232 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 910: /* fill_via_pt: firstPt otherPts  */
#line 4948 "def/def.y"
    {
        if (defData->callbacks->FillCbk) {
          defData->Fill.addPts(&defData->Geometries);
          CALLBACK(defData->callbacks->FillCbk, defrFillCbkType, &defData->Fill);
          defData->Fill.clear();
        }
    }
#line 10244 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 915: /* fill_via_opc: '+' K_OPC  */
#line 4967 "def/def.y"
      {
        if (defData->VersionNum < 5.7) {
           if (defData->callbacks->FillCbk) {
             if (defData->fillWarnings++ < defData->settings->FillWarnings) {
               defData->defMsg = (char*)malloc(10000);
               sprintf (defData->defMsg,
                 "The VIA OPC is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
               defData->defError(6554, defData->defMsg);
               free(defData->defMsg);
               CHKERR();
             }
           }
        } else {
           if (defData->callbacks->FillCbk)
             defData->Fill.setViaOpc();
        }
      }
#line 10266 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 916: /* fill_mask: '+' K_MASK NUMBER  */
#line 4987 "def/def.y"
      { 
        if (defData->validateMaskInput((int)(yyvsp[0].dval), defData->fillWarnings, defData->settings->FillWarnings)) {
             if (defData->callbacks->FillCbk) {
                defData->Fill.setMask((int)(yyvsp[0].dval));
             }
        }
      }
#line 10278 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 917: /* fill_viaMask: '+' K_MASK NUMBER  */
#line 4997 "def/def.y"
      { 
        if (defData->validateMaskInput((int)(yyvsp[0].dval), defData->fillWarnings, defData->settings->FillWarnings)) {
             if (defData->callbacks->FillCbk) {
                defData->Fill.setMask((int)(yyvsp[0].dval));
             }
        }
      }
#line 10290 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 919: /* nondefault_start: K_NONDEFAULTRULES NUMBER ';'  */
#line 5010 "def/def.y"
      { 
        if (defData->VersionNum < 5.6) {
          if (defData->callbacks->NonDefaultStartCbk) {
            if (defData->nonDefaultWarnings++ < defData->settings->NonDefaultWarnings) {
              defData->defMsg = (char*)malloc(1000);
              sprintf (defData->defMsg,
                 "The NONDEFAULTRULE statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
              defData->defError(6545, defData->defMsg);
              free(defData->defMsg);
              CHKERR();
            }
          }
        } else if (defData->callbacks->NonDefaultStartCbk)
          CALLBACK(defData->callbacks->NonDefaultStartCbk, defrNonDefaultStartCbkType,
                   ROUND((yyvsp[-1].dval)));
      }
#line 10311 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 920: /* nondefault_end: K_END K_NONDEFAULTRULES  */
#line 5028 "def/def.y"
      { if (defData->callbacks->NonDefaultEndCbk)
          CALLBACK(defData->callbacks->NonDefaultEndCbk, defrNonDefaultEndCbkType, 0); }
#line 10318 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 923: /* $@166: %empty  */
#line 5035 "def/def.y"
                    { defData->dumb_mode = 1; defData->no_num = 1; }
#line 10324 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 924: /* $@167: %empty  */
#line 5036 "def/def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          defData->NonDefault.clear(); 
          defData->NonDefault.setName((yyvsp[0].string));
        }
      }
#line 10335 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 925: /* nondefault_def: '-' $@166 T_STRING $@167 nondefault_options ';'  */
#line 5043 "def/def.y"
      { if (defData->callbacks->NonDefaultCbk)
          CALLBACK(defData->callbacks->NonDefaultCbk, defrNonDefaultCbkType, &defData->NonDefault); }
#line 10342 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 928: /* nondefault_option: '+' K_HARDSPACING  */
#line 5051 "def/def.y"
      {
        if (defData->callbacks->NonDefaultCbk)
          defData->NonDefault.setHardspacing();
      }
#line 10351 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 929: /* $@168: %empty  */
#line 5055 "def/def.y"
                    { defData->dumb_mode = 1; defData->no_num = 1; }
#line 10357 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 930: /* $@169: %empty  */
#line 5057 "def/def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          defData->NonDefault.addLayer((yyvsp[-2].string));
          defData->NonDefault.addWidth((yyvsp[0].dval));
        }
      }
#line 10368 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 932: /* $@170: %empty  */
#line 5064 "def/def.y"
                  { defData->dumb_mode = 1; defData->no_num = 1; }
#line 10374 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 933: /* nondefault_option: '+' K_VIA $@170 T_STRING  */
#line 5065 "def/def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          defData->NonDefault.addVia((yyvsp[0].string));
        }
      }
#line 10384 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 934: /* $@171: %empty  */
#line 5070 "def/def.y"
                      { defData->dumb_mode = 1; defData->no_num = 1; }
#line 10390 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 935: /* nondefault_option: '+' K_VIARULE $@171 T_STRING  */
#line 5071 "def/def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          defData->NonDefault.addViaRule((yyvsp[0].string));
        }
      }
#line 10400 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 936: /* $@172: %empty  */
#line 5076 "def/def.y"
                      { defData->dumb_mode = 1; defData->no_num = 1; }
#line 10406 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 937: /* nondefault_option: '+' K_MINCUTS $@172 T_STRING NUMBER  */
#line 5077 "def/def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          defData->NonDefault.addMinCuts((yyvsp[-1].string), (int)(yyvsp[0].dval));
        }
      }
#line 10416 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 941: /* nondefault_layer_option: K_DIAGWIDTH NUMBER  */
#line 5090 "def/def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          defData->NonDefault.addDiagWidth((yyvsp[0].dval));
        }
      }
#line 10426 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 942: /* nondefault_layer_option: K_SPACING NUMBER  */
#line 5096 "def/def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          defData->NonDefault.addSpacing((yyvsp[0].dval));
        }
      }
#line 10436 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 943: /* nondefault_layer_option: K_WIREEXT NUMBER  */
#line 5102 "def/def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          defData->NonDefault.addWireExt((yyvsp[0].dval));
        }
      }
#line 10446 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 944: /* $@173: %empty  */
#line 5109 "def/def.y"
                                    { defData->dumb_mode = DEF_MAX_INT;  }
#line 10452 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 945: /* nondefault_prop_opt: '+' K_PROPERTY $@173 nondefault_prop_list  */
#line 5111 "def/def.y"
      { defData->dumb_mode = 0; }
#line 10458 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 948: /* nondefault_prop: T_STRING NUMBER  */
#line 5118 "def/def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          char propTp;
          char* str = defData->ringCopy("                       ");
          propTp = defData->session->NDefProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "NONDEFAULTRULE");
          sprintf(str, "%g", (yyvsp[0].dval));
          defData->NonDefault.addNumProperty((yyvsp[-1].string), (yyvsp[0].dval), str, propTp);
        }
      }
#line 10473 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 949: /* nondefault_prop: T_STRING QSTRING  */
#line 5129 "def/def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          char propTp;
          propTp = defData->session->NDefProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "NONDEFAULTRULE");
          defData->NonDefault.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
        }
      }
#line 10486 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 950: /* nondefault_prop: T_STRING T_STRING  */
#line 5138 "def/def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          char propTp;
          propTp = defData->session->NDefProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "NONDEFAULTRULE");
          defData->NonDefault.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
        }
      }
#line 10499 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 952: /* styles_start: K_STYLES NUMBER ';'  */
#line 5151 "def/def.y"
      {
        if (defData->VersionNum < 5.6) {
          if (defData->callbacks->StylesStartCbk) {
            if (defData->stylesWarnings++ < defData->settings->StylesWarnings) {
              defData->defMsg = (char*)malloc(1000);
              sprintf (defData->defMsg,
                 "The STYLES statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
              defData->defError(6546, defData->defMsg);
              free(defData->defMsg);
              CHKERR();
            }
          }
        } else if (defData->callbacks->StylesStartCbk)
          CALLBACK(defData->callbacks->StylesStartCbk, defrStylesStartCbkType, ROUND((yyvsp[-1].dval)));
      }
#line 10519 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 953: /* styles_end: K_END K_STYLES  */
#line 5168 "def/def.y"
      { if (defData->callbacks->StylesEndCbk)
          CALLBACK(defData->callbacks->StylesEndCbk, defrStylesEndCbkType, 0); }
#line 10526 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 956: /* $@174: %empty  */
#line 5176 "def/def.y"
      {
        if (defData->callbacks->StylesCbk) defData->Styles.setStyle((int)(yyvsp[0].dval));
        defData->Geometries.Reset();
      }
#line 10535 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;

  case 957: /* styles_rule: '-' K_STYLE NUMBER $@174 firstPt nextPt otherPts ';'  */
#line 5181 "def/def.y"
      {
        if (defData->VersionNum >= 5.6) {  // only 5.6 and beyond will call the callback
          if (defData->callbacks->StylesCbk) {
            defData->Styles.setPolygon(&defData->Geometries);
            CALLBACK(defData->callbacks->StylesCbk, defrStylesCbkType, &defData->Styles);
          }
        }
      }
#line 10548 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"
    break;


#line 10552 "/home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/lefdef/5.8/def/def.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (defData, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, defData);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, defData);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (defData, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, defData);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, defData);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 5191 "def/def.y"


END_LEFDEF_PARSER_NAMESPACE
