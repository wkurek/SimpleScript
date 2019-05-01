/* A Bison parser, made by GNU Bison 3.3.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "SimpleScript.y" /* yacc.c:337  */

    #include <iostream>
	#include <memory>
    using namespace std;

	#include "primitive.h"
	#include "identifier.h"
	#include "object.h"
	#include "function.h"
	#include "variable.h"
	#include "exception.h"
	#include "operation_expression.h"
	#include "statement.h"
	#include "assignment.h"
	#include "property.h"
	#include "program.h"

    extern int yylex(void);
    extern int yylineno;
    extern int yyparse();

    extern FILE *yyin;

    bool errorReported = false;

    void yyerror(const char* s) {
      if(!errorReported) {
         cerr << "ERROR:\t at line " << yylineno << ":\t" << s << endl;
      }
    }

    void yyerror(const char* s, char c) {
      cerr << "ERROR:\tat line " << yylineno << ": " << s << " \"" << c << "\"" << endl;
      errorReported = true;
    }

#line 107 "SimpleScript.tab.cpp" /* yacc.c:337  */
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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "SimpleScript.tab.h".  */
#ifndef YY_YY_SIMPLESCRIPT_TAB_H_INCLUDED
# define YY_YY_SIMPLESCRIPT_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER_T = 258,
    FLOAT_T = 259,
    BOOLEAN_T = 260,
    STRING_T = 261,
    IDENTIFIER = 262,
    ASSIGN = 263,
    COLON = 264,
    COMMA = 265,
    OPEN_BRACE = 266,
    CLOSE_BRACE = 267,
    IF = 268,
    WHILE = 269,
    VAR = 270,
    FUNCTION_T = 271,
    RETURN = 272,
    NO_ELSE = 273,
    ELSE = 274,
    AND = 275,
    OR = 276,
    LESS_THAN = 277,
    LESS_EQUAL_THAN = 278,
    GREATER_THAN = 279,
    GREATER_EQUAL_THAN = 280,
    EQUAL = 281,
    NOT_EQUAL = 282,
    PLUS = 283,
    MINUS = 284,
    ASTERISK = 285,
    SLASH = 286,
    INC = 287,
    DEC = 288,
    NOT = 289,
    NO_FUNCTION_CALL = 290,
    OPEN_PARENTHESIS = 291,
    CLOSE_PARENTHESIS = 292,
    DOT = 293,
    OPEN_BRACKET = 294,
    CLOSE_BRACKET = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 40 "SimpleScript.y" /* yacc.c:352  */

    int integerVal;
    float floatVal;
    bool booleanVal;
    char* stringVal;
	Identifier* identifierVal;
	StatementsList* statementsListVal;
	Statement* statementVal;
	OperationExpression* operationExpressionVal;
	ParametersList* parametersListVal;
	Object* objectVal;
	PropertyList* propertyListVal;
	Property* propertyVal;
	ArgumentsList* argumentsListyVal;
	OperationExpressionsList* operationExpressionsListVal;
	ObjectLiteral* objectLiteralVal;

#line 209 "SimpleScript.tab.cpp" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SIMPLESCRIPT_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

#define YYUNDEFTOK  2
#define YYMAXUTOK   295

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   112,   112,   115,   118,   122,   130,   131,   132,   133,
     134,   135,   138,   141,   146,   150,   157,   161,   173,   187,
     192,   196,   200,   208,   211,   217,   222,   223,   227,   231,
     235,   239,   243,   247,   251,   255,   259,   263,   267,   271,
     275,   279,   283,   287,   290,   291,   296,   303,   307,   311,
     319,   322,   328,   333,   341,   342,   353,   362,   371,   376,
     380,   388,   391,   396,   402,   406,   412,   413,   421,   428,
     435
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"integer\"", "\"FLOAT\"",
  "\"BOOLEAN\"", "\"STRING\"", "\"IDENTIFIER\"", "\"=\"", "\":\"", "\",\"",
  "\"{\"", "\"}\"", "\"if\"", "\"while\"", "\"var\"", "\"function\"",
  "\"return\"", "NO_ELSE", "ELSE", "AND", "OR", "LESS_THAN",
  "LESS_EQUAL_THAN", "GREATER_THAN", "GREATER_EQUAL_THAN", "EQUAL",
  "NOT_EQUAL", "PLUS", "MINUS", "ASTERISK", "SLASH", "INC", "DEC", "NOT",
  "NO_FUNCTION_CALL", "OPEN_PARENTHESIS", "CLOSE_PARENTHESIS", "DOT",
  "OPEN_BRACKET", "CLOSE_BRACKET", "$accept", "program", "statements_list",
  "statement", "expression_statement", "assignment_expression",
  "object_literal", "properties_names_and_values",
  "property_name_and_value", "operation_expression",
  "function_call_expression", "arguments_list", "argument",
  "variable_declaration_statement", "variable_declaration_list",
  "variable_declaration", "function_declaration_statement",
  "parameters_list", "function_body", "return_statement",
  "iteration_statement", "conditional_statement", "block", "identifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -89

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-89)))

#define YYTABLE_NINF -71

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     206,   -89,   -89,   -89,   -89,   -89,   -32,   -22,    71,    24,
      61,    25,    25,    61,    61,    73,   206,   -89,   -89,   -89,
     223,   -89,   -89,   -89,   -89,   -89,   -89,    -3,    61,    61,
      -1,   -89,    67,   -89,    32,    45,    77,   223,   -21,    41,
      41,   -89,   112,   -89,   -89,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    23,    61,    80,
      85,   146,   204,    71,    77,   -89,    48,   -89,   233,   233,
      -8,    -8,    -8,    -8,    -8,    -8,    52,    52,   -89,   -89,
      86,   -89,   223,   -89,   223,    51,   -89,   -89,    58,   114,
     114,   -89,    59,    99,    81,   100,    62,   -89,    61,   -89,
     -89,   206,   -89,    89,   -89,    81,   -89,   206,   -89,    23,
      86,   -89,   -89,   148,   114,   -89,   182,   -89,   223,   -89,
     -89,   -89,   -89,   -89
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    27,    28,    29,    30,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     5,     6,    12,
      13,    44,     7,     8,     9,    10,    11,    45,     0,     0,
      55,    54,    51,    53,     0,     0,    58,    62,    45,    17,
      18,    43,     0,     1,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,     0,     0,     0,    58,    60,     0,    26,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      20,    16,    14,    15,    50,     0,    49,    68,     0,     0,
       0,    52,     0,     0,     0,     0,     0,    22,     0,    46,
      69,     0,    67,    64,    63,     0,    59,     0,    57,     0,
       0,    19,    48,     0,     0,    56,     0,    25,    23,    24,
      21,    66,    65,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,   -88,   -14,   -89,    -7,     1,   -89,     2,    -4,
     -89,   -89,    13,   -89,   -89,    60,   -54,    92,    10,   -89,
     -89,   -89,   -28,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    15,    16,    17,    18,    19,    81,    96,    97,    20,
      21,    85,    86,    22,    32,    33,    23,    66,   108,    24,
      25,    26,   103,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      27,    31,    44,    83,    28,    57,    37,   -70,    34,    41,
      42,    39,    40,   113,    29,    58,    27,    59,    60,   116,
      53,    54,    55,    56,    61,    62,     1,     2,     3,     4,
       5,    35,     5,    58,    80,    59,    60,   -70,   -70,     9,
      57,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    82,    84,   119,    31,    13,    93,    14,
      36,    98,   104,    34,     1,     2,     3,     4,     5,    93,
      59,    60,   110,    43,   111,   102,   102,    63,    30,    59,
      60,    64,    55,    56,    65,    94,   122,    87,    99,    27,
      27,    88,   107,    95,    84,    13,   105,    14,   100,    44,
     102,    27,    44,    11,    12,   118,   106,    27,   114,   109,
     117,   112,   120,    27,    27,   115,    27,     1,     2,     3,
       4,     5,     0,    91,     0,   101,     0,     6,     7,     8,
       9,    10,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     0,     0,    11,    12,    13,    67,
      14,     1,     2,     3,     4,     5,    92,     0,     0,     0,
     121,     6,     7,     8,     9,    10,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     0,     0,
      11,    12,    13,    89,    14,     1,     2,     3,     4,     5,
       0,     0,     0,     0,   123,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,    11,    12,    13,     0,    14,     6,
       7,     8,     9,    10,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     0,     0,    11,    12,
      13,    90,    14,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56
};

static const yytype_int8 yycheck[] =
{
       0,     8,    16,    57,    36,     8,    10,     8,     8,    13,
      14,    11,    12,   101,    36,    36,    16,    38,    39,   107,
      28,    29,    30,    31,    28,    29,     3,     4,     5,     6,
       7,     7,     7,    36,    11,    38,    39,    38,    39,    16,
       8,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,   109,    63,    34,    10,    36,
      36,    10,    90,    63,     3,     4,     5,     6,     7,    10,
      38,    39,    10,     0,    12,    89,    90,    10,     7,    38,
      39,    36,    30,    31,     7,    37,   114,     7,    37,    89,
      90,     6,    11,     7,    98,    34,    37,    36,    40,   113,
     114,   101,   116,    32,    33,   109,     7,   107,    19,     9,
     109,    98,   110,   113,   114,   105,   116,     3,     4,     5,
       6,     7,    -1,    63,    -1,    11,    -1,    13,    14,    15,
      16,    17,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    32,    33,    34,    37,
      36,     3,     4,     5,     6,     7,    64,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    17,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      32,    33,    34,    37,    36,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    32,    33,    34,    -1,    36,    13,
      14,    15,    16,    17,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    32,    33,
      34,    37,    36,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    13,    14,    15,    16,
      17,    32,    33,    34,    36,    42,    43,    44,    45,    46,
      50,    51,    54,    57,    60,    61,    62,    64,    36,    36,
       7,    46,    55,    56,    64,     7,    36,    50,    64,    64,
      64,    50,    50,     0,    44,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     8,    36,    38,
      39,    50,    50,    10,    36,     7,    58,    37,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      11,    47,    50,    57,    50,    52,    53,     7,     6,    37,
      37,    56,    58,    10,    37,     7,    48,    49,    10,    37,
      40,    11,    44,    63,    63,    37,     7,    11,    59,     9,
      10,    12,    53,    43,    19,    59,    43,    47,    50,    57,
      49,    12,    63,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    44,    44,    44,    44,
      44,    44,    45,    45,    46,    46,    46,    46,    46,    47,
      48,    48,    48,    49,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    51,    52,    52,    52,
      53,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      58,    59,    60,    61,    62,    62,    63,    63,    64,    64,
      64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     2,     2,     3,
       0,     3,     1,     3,     3,     3,     3,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     4,     0,     3,     1,
       1,     2,     3,     1,     1,     1,     6,     5,     0,     3,
       1,     3,     2,     5,     5,     7,     3,     1,     3,     4,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 112 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Program(std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal))).evaluate();
									}
#line 1426 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 4:
#line 118 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyvsp[-1].statementsListVal)->add(std::shared_ptr<Statement>((yyvsp[0].statementVal)));
										(yyval.statementsListVal) = (yyvsp[-1].statementsListVal);
									}
#line 1435 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 5:
#line 122 "SimpleScript.y" /* yacc.c:1652  */
    {
										StatementsList* stmtsList = new StatementsList();
										stmtsList->add(std::shared_ptr<Statement>((yyvsp[0].statementVal)));

										(yyval.statementsListVal) = stmtsList;
									}
#line 1446 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 12:
#line 138 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.statementVal) = new ExpressionStatement(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1454 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 13:
#line 141 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.statementVal) = new ExpressionStatement(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1462 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 14:
#line 146 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new OperationExpressionAssignment(std::shared_ptr<Identifier>((yyvsp[-2].identifierVal)), 
												std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1471 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 15:
#line 150 "SimpleScript.y" /* yacc.c:1652  */
    {
										FunctionDeclarationStatement* fdstmtPtr = dynamic_cast<FunctionDeclarationStatement*> ((yyvsp[0].statementVal));
										Function funct = fdstmtPtr->getFunction();

										(yyval.operationExpressionVal) = new FunctionAssignment(std::shared_ptr<Identifier>((yyvsp[-2].identifierVal)), funct);

									}
#line 1483 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 16:
#line 157 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new ObjectLiteralAssignment(std::shared_ptr<Identifier>((yyvsp[-2].identifierVal)), 
											std::shared_ptr<ObjectLiteral>((yyvsp[0].objectLiteralVal)));
									}
#line 1492 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 17:
#line 161 "SimpleScript.y" /* yacc.c:1652  */
    {
										Variable one = Variable(1);
										ConstantExpression oneConstantExpression =
											ConstantExpression(std::shared_ptr<Variable>(new Variable(one)));

										OperationExpression* expression = new Addition(
											std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>((yyvsp[0].identifierVal)))),
											std::shared_ptr<OperationExpression>(new ConstantExpression(oneConstantExpression)));
										
										(yyval.operationExpressionVal) = new OperationExpressionAssignment(std::shared_ptr<Identifier>((yyvsp[0].identifierVal)), 
												std::shared_ptr<OperationExpression>(expression));
									}
#line 1509 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 18:
#line 173 "SimpleScript.y" /* yacc.c:1652  */
    {
										Variable one = Variable(1);
										ConstantExpression oneConstantExpression =
											ConstantExpression(std::shared_ptr<Variable>(new Variable(one)));

										OperationExpression* expression = new Subtraction(
											std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>((yyvsp[0].identifierVal)))),
											std::shared_ptr<OperationExpression>(new ConstantExpression(oneConstantExpression)));
										
										(yyval.operationExpressionVal) = new OperationExpressionAssignment(std::shared_ptr<Identifier>((yyvsp[0].identifierVal)), 
												std::shared_ptr<OperationExpression>(expression));
									}
#line 1526 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 19:
#line 187 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.objectLiteralVal) = new ObjectLiteral(shared_ptr<PropertyList>((yyvsp[-1].propertyListVal)));
									}
#line 1534 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 20:
#line 192 "SimpleScript.y" /* yacc.c:1652  */
    {
										PropertyList* propertyList = new PropertyList();
										(yyval.propertyListVal) =  propertyList;
									}
#line 1543 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 21:
#line 196 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyvsp[-2].propertyListVal)->add(std::shared_ptr<Property>((yyvsp[0].propertyVal)));
										(yyval.propertyListVal) = (yyvsp[-2].propertyListVal);
									}
#line 1552 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 22:
#line 200 "SimpleScript.y" /* yacc.c:1652  */
    { 
										PropertyList* propertyList = new PropertyList();
										propertyList->add(std::shared_ptr<Property>((yyvsp[0].propertyVal)));

										(yyval.propertyListVal) = propertyList;
									}
#line 1563 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 23:
#line 208 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.propertyVal) = new Property((yyvsp[-2].stringVal), std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1571 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 24:
#line 211 "SimpleScript.y" /* yacc.c:1652  */
    {
										FunctionDeclarationStatement* fdstmtPtr = dynamic_cast<FunctionDeclarationStatement*> ((yyvsp[0].statementVal));
										Function funct = fdstmtPtr->getFunction();

										(yyval.propertyVal) = new Property((yyvsp[-2].stringVal), std::shared_ptr<Function>(new Function(funct)));
									}
#line 1582 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 25:
#line 217 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.propertyVal) = new Property((yyvsp[-2].stringVal), std::shared_ptr<ObjectLiteral>((yyvsp[0].objectLiteralVal)));
									}
#line 1590 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 26:
#line 222 "SimpleScript.y" /* yacc.c:1652  */
    { (yyval.operationExpressionVal) = (yyvsp[-1].operationExpressionVal); }
#line 1596 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 27:
#line 223 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Primitive primitive = Primitive((yyvsp[0].integerVal));
										(yyval.operationExpressionVal) = new ConstantExpression(std::shared_ptr<Variable>(new Variable(primitive))); 
									}
#line 1605 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 28:
#line 227 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Primitive primitive = Primitive((yyvsp[0].floatVal));
										(yyval.operationExpressionVal) = new ConstantExpression(std::shared_ptr<Variable>(new Variable(primitive))); 
									}
#line 1614 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 29:
#line 231 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Primitive primitive = Primitive((yyvsp[0].booleanVal));
										(yyval.operationExpressionVal) = new ConstantExpression(std::shared_ptr<Variable>(new Variable(primitive))); 
									}
#line 1623 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 30:
#line 235 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Primitive primitive = Primitive((yyvsp[0].stringVal));
										(yyval.operationExpressionVal) = new ConstantExpression(std::shared_ptr<Variable>(new Variable(primitive))); 
									}
#line 1632 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 31:
#line 239 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new LogicalAnd(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1641 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 32:
#line 243 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new LogicalOr(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1650 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 33:
#line 247 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new LessThan(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1659 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 34:
#line 251 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new LessThanOrEqualTo(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1668 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 35:
#line 255 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new GreaterThan(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1677 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 36:
#line 259 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new GreaterThanOrEqualTo(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1686 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 37:
#line 263 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new Equals(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1695 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 38:
#line 267 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new NotEquals(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1704 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 39:
#line 271 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new Addition(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1713 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 40:
#line 275 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new Subtraction(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1722 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 41:
#line 279 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new Multiplication(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1731 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 42:
#line 283 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new Division(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1740 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 43:
#line 287 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new LogicalNot(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1748 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 44:
#line 290 "SimpleScript.y" /* yacc.c:1652  */
    { (yyval.operationExpressionVal) = (yyvsp[0].operationExpressionVal); }
#line 1754 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 45:
#line 291 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new IdentifierExpression(std::shared_ptr<Identifier>((yyvsp[0].identifierVal))); 
									}
#line 1762 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 46:
#line 296 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new FunctionCallExpression(
											std::shared_ptr<Identifier>((yyvsp[-3].identifierVal)), 
											std::shared_ptr<ArgumentsList>((yyvsp[-1].argumentsListyVal)));
									}
#line 1772 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 47:
#line 303 "SimpleScript.y" /* yacc.c:1652  */
    { 
										ArgumentsList* argsList = new ArgumentsList();
										(yyval.argumentsListyVal) = argsList;
									}
#line 1781 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 48:
#line 307 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyvsp[-2].argumentsListyVal)->add(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
										(yyval.argumentsListyVal) = (yyvsp[-2].argumentsListyVal);
									}
#line 1790 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 49:
#line 311 "SimpleScript.y" /* yacc.c:1652  */
    { 
										ArgumentsList* argsList = new ArgumentsList();
										argsList->add(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));

										(yyval.argumentsListyVal) = argsList;
									}
#line 1801 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 50:
#line 319 "SimpleScript.y" /* yacc.c:1652  */
    { (yyval.operationExpressionVal) = (yyvsp[0].operationExpressionVal); }
#line 1807 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 51:
#line 322 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.statementVal) = new VariableDeclarationStatement(
											std::shared_ptr<OperationExpressionsList>((yyvsp[0].operationExpressionsListVal)));
									}
#line 1816 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 52:
#line 328 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyvsp[-2].operationExpressionsListVal)->add(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));

										(yyval.operationExpressionsListVal) = (yyvsp[-2].operationExpressionsListVal);
									}
#line 1826 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 53:
#line 333 "SimpleScript.y" /* yacc.c:1652  */
    { 
										OperationExpressionsList* list = new OperationExpressionsList();
										list->add(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));

										(yyval.operationExpressionsListVal) = list;
									}
#line 1837 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 54:
#line 341 "SimpleScript.y" /* yacc.c:1652  */
    { (yyval.operationExpressionVal) = (yyvsp[0].operationExpressionVal); }
#line 1843 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 55:
#line 342 "SimpleScript.y" /* yacc.c:1652  */
    {
										Primitive zeroPrimitive = Primitive(0);
										Variable zero = Variable(zeroPrimitive);
										ConstantExpression zeroConstantExpression =
											ConstantExpression(std::shared_ptr<Variable>(new Variable(zero)));
										
										(yyval.operationExpressionVal) = new OperationExpressionAssignment(std::shared_ptr<Identifier>(new Identifier((yyvsp[0].stringVal))), 
												std::shared_ptr<OperationExpression>(new ConstantExpression(zeroConstantExpression)));
									}
#line 1857 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 56:
#line 353 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Function* functionPtr = new Function(std::shared_ptr<ParametersList>((yyvsp[-2].parametersListVal)), 
											std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal)));

										(yyval.statementVal) = new FunctionDeclarationStatement(std::shared_ptr<Function>(functionPtr), 
											std::shared_ptr<Identifier>(new Identifier((yyvsp[-4].stringVal))));

										delete [] (yyvsp[-4].stringVal);
									}
#line 1871 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 57:
#line 362 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Function* functionPtr = new Function(std::shared_ptr<ParametersList>((yyvsp[-2].parametersListVal)), 
											std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal)));

										(yyval.statementVal) = new FunctionDeclarationStatement(std::shared_ptr<Function>(functionPtr));

									}
#line 1883 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 58:
#line 371 "SimpleScript.y" /* yacc.c:1652  */
    { 
										cout<< "program start" << endl; 
										ParametersList* paramsList = new ParametersList();
										(yyval.parametersListVal) = paramsList;
									}
#line 1893 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 59:
#line 376 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyvsp[-2].parametersListVal)->add((yyvsp[0].stringVal));
										(yyval.parametersListVal) = (yyvsp[-2].parametersListVal);
									}
#line 1902 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 60:
#line 380 "SimpleScript.y" /* yacc.c:1652  */
    { 
										ParametersList* paramsList = new ParametersList();
										paramsList->add((yyvsp[0].stringVal));

										(yyval.parametersListVal) = paramsList;
									}
#line 1913 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 61:
#line 388 "SimpleScript.y" /* yacc.c:1652  */
    { (yyval.statementsListVal) = (yyvsp[-1].statementsListVal); }
#line 1919 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 62:
#line 391 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.statementVal) = new ReturnStatement(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1927 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 63:
#line 396 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.statementVal) = new IterationStatement(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
												std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal)));
									}
#line 1936 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 64:
#line 402 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.statementVal) = new ConditionalStatement(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
												std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal)));
									}
#line 1945 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 65:
#line 406 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.statementVal) = new ConditionalStatement(std::shared_ptr<OperationExpression>((yyvsp[-4].operationExpressionVal)), 
												std::shared_ptr<StatementsList>((yyvsp[-2].statementsListVal)), std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal)));
									}
#line 1954 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 66:
#line 412 "SimpleScript.y" /* yacc.c:1652  */
    { (yyval.statementsListVal) = (yyvsp[-1].statementsListVal); }
#line 1960 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 67:
#line 413 "SimpleScript.y" /* yacc.c:1652  */
    { 
										StatementsList* stmtsList = new StatementsList();
										stmtsList->add(std::shared_ptr<Statement>((yyvsp[0].statementVal)));

										(yyval.statementsListVal) = stmtsList;
									}
#line 1971 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 68:
#line 421 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Identifier* id = new Identifier(*((yyvsp[-2].identifierVal)), (yyvsp[0].stringVal));
										(yyval.identifierVal) = id;

										delete (yyvsp[-2].identifierVal);
										delete [] (yyvsp[0].stringVal);
									}
#line 1983 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 69:
#line 428 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Identifier* id = new Identifier(*((yyvsp[-3].identifierVal)), (yyvsp[-1].stringVal));
										(yyval.identifierVal) = id;

										delete (yyvsp[-3].identifierVal);
										delete [] (yyvsp[-1].stringVal);
									}
#line 1995 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 70:
#line 435 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Identifier* id = new Identifier((yyvsp[0].stringVal));
										(yyval.identifierVal) = id;
										delete [] (yyvsp[0].stringVal);
									}
#line 2005 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;


#line 2009 "SimpleScript.tab.cpp" /* yacc.c:1652  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
                      yytoken, &yylval);
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 443 "SimpleScript.y" /* yacc.c:1918  */

