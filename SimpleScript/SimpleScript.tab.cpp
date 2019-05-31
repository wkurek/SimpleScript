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
	#include <string>
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

#line 108 "SimpleScript.tab.cpp" /* yacc.c:337  */
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
    SEMICOLON = 265,
    COMMA = 266,
    OPEN_BRACE = 267,
    CLOSE_BRACE = 268,
    IF = 269,
    WHILE = 270,
    VAR = 271,
    FUNCTION_T = 272,
    RETURN = 273,
    NO_ELSE = 274,
    ELSE = 275,
    AND = 276,
    OR = 277,
    LESS_THAN = 278,
    LESS_EQUAL_THAN = 279,
    GREATER_THAN = 280,
    GREATER_EQUAL_THAN = 281,
    EQUAL = 282,
    NOT_EQUAL = 283,
    PLUS = 284,
    MINUS = 285,
    ASTERISK = 286,
    SLASH = 287,
    INC = 288,
    DEC = 289,
    NOT = 290,
    NO_FUNCTION_CALL = 291,
    OPEN_PARENTHESIS = 292,
    CLOSE_PARENTHESIS = 293,
    DOT = 294,
    OPEN_BRACKET = 295,
    CLOSE_BRACKET = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 41 "SimpleScript.y" /* yacc.c:352  */

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

#line 211 "SimpleScript.tab.cpp" /* yacc.c:352  */
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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   368

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   117,   120,   124,   132,   133,   134,   135,
     136,   137,   140,   143,   148,   152,   159,   163,   176,   191,
     196,   200,   204,   212,   215,   221,   226,   227,   231,   235,
     239,   244,   248,   252,   256,   260,   264,   268,   272,   276,
     280,   284,   288,   292,   295,   298,   299,   304,   311,   315,
     319,   327,   330,   336,   341,   349,   350,   361,   369,   378,
     382,   386,   394,   397,   400,   405,   411,   415,   421,   422,
     430,   433,   440,   447
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"integer\"", "\"FLOAT\"",
  "\"BOOLEAN\"", "\"STRING\"", "\"IDENTIFIER\"", "\"=\"", "\":\"", "\";\"",
  "\",\"", "\"{\"", "\"}\"", "\"if\"", "\"while\"", "\"var\"",
  "\"function\"", "\"return\"", "NO_ELSE", "ELSE", "AND", "OR",
  "LESS_THAN", "LESS_EQUAL_THAN", "GREATER_THAN", "GREATER_EQUAL_THAN",
  "EQUAL", "NOT_EQUAL", "PLUS", "MINUS", "ASTERISK", "SLASH", "INC", "DEC",
  "NOT", "NO_FUNCTION_CALL", "OPEN_PARENTHESIS", "CLOSE_PARENTHESIS",
  "DOT", "OPEN_BRACKET", "CLOSE_BRACKET", "$accept", "program",
  "statements_list", "statement", "expression_statement",
  "assignment_expression", "object_literal", "properties_names_and_values",
  "property_name_and_value", "operation_expression",
  "function_call_expression", "arguments_list", "argument",
  "variable_declaration_statement", "variable_declaration_list",
  "variable_declaration", "function_declaration_statement",
  "parameters_list", "function_body", "return_statement",
  "iteration_statement", "conditional_statement", "block", "delimiter",
  "identifier", YY_NULLPTR
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
     295,   296
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -57

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     218,   -95,   -95,   -95,   -95,   -95,   -30,   -10,    -3,     7,
      30,   253,    34,    34,   253,   253,    80,   218,   -95,   -95,
      75,   270,   -95,   -95,   -95,   -95,   -95,   -95,    31,   253,
     253,    12,   -95,    66,   -95,     3,    49,    85,   -95,   270,
     -95,   -11,    47,    44,    44,   -95,   282,   -95,   -95,   -95,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   -95,   237,   253,    86,    81,   300,   318,    -3,
     -95,    85,   -95,    50,   -95,   -95,   109,   109,    43,    43,
      43,    43,    43,    43,    47,    47,   -95,   -95,    87,   -95,
     336,   -95,   336,    51,   -95,   -95,    54,   113,   113,   -95,
      53,    89,    88,    90,     5,   -95,   253,   -95,   -95,   218,
     -95,    82,   -95,    88,   -95,   218,   -95,   237,    87,   -95,
     -95,   148,   113,   -95,   183,   -95,   336,   -95,   -95,   -95,
     -95,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    27,    28,    29,    30,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     5,     6,
       0,     0,    45,     7,     8,     9,    10,    11,    46,     0,
       0,    73,    55,     0,    54,     0,     0,    59,    70,     0,
      64,    46,    44,    17,    18,    43,     0,     1,     4,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,     0,    48,     0,     0,     0,     0,     0,
      52,    59,    61,     0,    63,    26,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    20,    16,
      14,    15,    51,     0,    50,    71,     0,     0,     0,    53,
       0,     0,     0,     0,     0,    22,     0,    47,    72,     0,
      69,    66,    65,     0,    60,     0,    58,     0,     0,    19,
      49,     0,     0,    57,     0,    25,    23,    24,    21,    68,
      67,    62
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -95,   -95,   -94,   -16,   -95,    -6,   -14,   -95,    -8,    -5,
     -95,   -95,    -2,   -95,   -95,    38,   -60,    40,     1,   -95,
     -95,   -95,   -32,    -1,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    16,    17,    18,    19,    20,    89,   104,   105,    21,
      22,    93,    94,    23,    33,    34,    24,    73,   116,    25,
      26,    27,   111,    40,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    48,    32,    91,    31,    39,    42,    29,    35,    45,
      46,    63,    43,    44,    36,   121,   118,    28,   119,    49,
      62,   124,   -56,   -56,    67,    68,    64,    30,    65,    66,
      12,    13,    70,     1,     2,     3,     4,     5,    74,    63,
      38,     5,    65,    66,    37,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,   127,    90,    92,
      11,   101,   106,    32,   101,    14,   112,    15,    64,    35,
      65,    66,    58,    59,    60,    61,    38,    69,    60,    61,
      47,   110,   110,    65,    66,    38,    71,    96,   102,   107,
     130,   113,    72,    95,   103,   108,   114,    28,    28,   117,
     115,    92,   122,   125,   120,    48,   110,    99,    48,    28,
     128,   100,   126,     0,   123,    28,     1,     2,     3,     4,
       5,    28,    28,     0,    28,   109,     0,     6,     7,     8,
       9,    10,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,     0,    11,     0,     0,    12,    13,    14,     0,
      15,     1,     2,     3,     4,     5,     0,     0,     0,     0,
       0,   129,     6,     7,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,    12,    13,    14,     0,    15,     1,     2,     3,     4,
       5,     0,     0,     0,     0,     0,   131,     6,     7,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,     0,    12,    13,    14,     0,
      15,     1,     2,     3,     4,     5,     0,     0,     0,     0,
       0,     0,     6,     7,     8,     9,    10,     0,     0,     0,
       1,     2,     3,     4,     5,     0,     0,     0,    11,    88,
       0,    12,    13,    14,     9,    15,     1,     2,     3,     4,
       5,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,     0,    14,     0,    15,     0,     0,     0,     0,     0,
      38,     0,     0,    11,     0,     0,     0,     0,    14,     0,
      15,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,     0,     0,     0,     0,     0,
      75,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,     0,     0,     0,     0,     0,    97,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     0,     0,     0,     0,     0,    98,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61
};

static const yytype_int8 yycheck[] =
{
       0,    17,     8,    63,     7,    10,    11,    37,     8,    14,
      15,     8,    12,    13,     7,   109,    11,    17,    13,    20,
      21,   115,    10,    11,    29,    30,    37,    37,    39,    40,
      33,    34,    33,     3,     4,     5,     6,     7,    39,     8,
      10,     7,    39,    40,    37,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   117,    63,    64,
      30,    11,    11,    69,    11,    35,    98,    37,    37,    69,
      39,    40,    29,    30,    31,    32,    10,    11,    31,    32,
       0,    97,    98,    39,    40,    10,    37,     6,    38,    38,
     122,    38,     7,     7,     7,    41,     7,    97,    98,     9,
      12,   106,    20,   117,   106,   121,   122,    69,   124,   109,
     118,    71,   117,    -1,   113,   115,     3,     4,     5,     6,
       7,   121,   122,    -1,   124,    12,    -1,    14,    15,    16,
      17,    18,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    30,    -1,    -1,    33,    34,    35,    -1,
      37,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    -1,    37,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    33,    34,    35,    -1,
      37,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    30,    12,
      -1,    33,    34,    35,    17,    37,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    35,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    -1,
      37,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      38,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    38,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    14,    15,    16,    17,
      18,    30,    33,    34,    35,    37,    43,    44,    45,    46,
      47,    51,    52,    55,    58,    61,    62,    63,    66,    37,
      37,     7,    47,    56,    57,    66,     7,    37,    10,    51,
      65,    66,    51,    66,    66,    51,    51,     0,    45,    65,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    65,     8,    37,    39,    40,    51,    51,    11,
      65,    37,     7,    59,    65,    38,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    12,    48,
      51,    58,    51,    53,    54,     7,     6,    38,    38,    57,
      59,    11,    38,     7,    49,    50,    11,    38,    41,    12,
      45,    64,    64,    38,     7,    12,    60,     9,    11,    13,
      54,    44,    20,    60,    44,    48,    51,    58,    50,    13,
      64,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    45,    45,    45,
      45,    45,    46,    46,    47,    47,    47,    47,    47,    48,
      49,    49,    49,    50,    50,    50,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    52,    53,    53,
      53,    54,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    59,    60,    61,    61,    62,    63,    63,    64,    64,
      65,    66,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     3,     3,     2,     2,     3,
       0,     3,     1,     3,     3,     3,     3,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     1,     1,     4,     0,     3,
       1,     1,     3,     3,     1,     1,     1,     6,     5,     0,
       3,     1,     3,     3,     2,     5,     5,     7,     3,     1,
       1,     3,     4,     1
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
#line 114 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Program(std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal))).evaluate();
									}
#line 1452 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 4:
#line 120 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyvsp[-1].statementsListVal)->add(std::shared_ptr<Statement>((yyvsp[0].statementVal)));
										(yyval.statementsListVal) = (yyvsp[-1].statementsListVal);
									}
#line 1461 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 5:
#line 124 "SimpleScript.y" /* yacc.c:1652  */
    {
										StatementsList* stmtsList = new StatementsList();
										stmtsList->add(std::shared_ptr<Statement>((yyvsp[0].statementVal)));

										(yyval.statementsListVal) = stmtsList;
									}
#line 1472 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 12:
#line 140 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.statementVal) = new ExpressionStatement(std::shared_ptr<OperationExpression>((yyvsp[-1].operationExpressionVal))); 
									}
#line 1480 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 13:
#line 143 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.statementVal) = new ExpressionStatement(std::shared_ptr<OperationExpression>((yyvsp[-1].operationExpressionVal))); 
									}
#line 1488 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 14:
#line 148 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new OperationExpressionAssignment(std::shared_ptr<Identifier>((yyvsp[-2].identifierVal)), 
												std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1497 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 15:
#line 152 "SimpleScript.y" /* yacc.c:1652  */
    {
										FunctionDeclarationStatement* fdstmtPtr = dynamic_cast<FunctionDeclarationStatement*> ((yyvsp[0].statementVal));
										Function funct = fdstmtPtr->getFunction();

										(yyval.operationExpressionVal) = new FunctionAssignment(std::shared_ptr<Identifier>((yyvsp[-2].identifierVal)), funct);

									}
#line 1509 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 16:
#line 159 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new ObjectLiteralAssignment(std::shared_ptr<Identifier>((yyvsp[-2].identifierVal)), 
											std::shared_ptr<ObjectLiteral>((yyvsp[0].objectLiteralVal)));
									}
#line 1518 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 17:
#line 163 "SimpleScript.y" /* yacc.c:1652  */
    {
										Primitive onePrimitive = Primitive(1);
										Variable one = Variable(onePrimitive);
										ConstantExpression oneConstantExpression =
											ConstantExpression(std::shared_ptr<Variable>(new Variable(one)));

										OperationExpression* expression = new Addition(
											std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>((yyvsp[0].identifierVal)))),
											std::shared_ptr<OperationExpression>(new ConstantExpression(oneConstantExpression)));
										
										(yyval.operationExpressionVal) = new OperationExpressionAssignment(std::shared_ptr<Identifier>((yyvsp[0].identifierVal)), 
												std::shared_ptr<OperationExpression>(expression));
									}
#line 1536 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 18:
#line 176 "SimpleScript.y" /* yacc.c:1652  */
    {
										Primitive onePrimitive = Primitive(1);
										Variable one = Variable(onePrimitive);
										ConstantExpression oneConstantExpression =
											ConstantExpression(std::shared_ptr<Variable>(new Variable(one)));

										OperationExpression* expression = new Subtraction(
											std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>((yyvsp[0].identifierVal)))),
											std::shared_ptr<OperationExpression>(new ConstantExpression(oneConstantExpression)));
										
										(yyval.operationExpressionVal) = new OperationExpressionAssignment(std::shared_ptr<Identifier>((yyvsp[0].identifierVal)), 
												std::shared_ptr<OperationExpression>(expression));
									}
#line 1554 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 19:
#line 191 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.objectLiteralVal) = new ObjectLiteral(shared_ptr<PropertyList>((yyvsp[-1].propertyListVal)));
									}
#line 1562 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 20:
#line 196 "SimpleScript.y" /* yacc.c:1652  */
    {
										PropertyList* propertyList = new PropertyList();
										(yyval.propertyListVal) =  propertyList;
									}
#line 1571 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 21:
#line 200 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyvsp[-2].propertyListVal)->add(std::shared_ptr<Property>((yyvsp[0].propertyVal)));
										(yyval.propertyListVal) = (yyvsp[-2].propertyListVal);
									}
#line 1580 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 22:
#line 204 "SimpleScript.y" /* yacc.c:1652  */
    { 
										PropertyList* propertyList = new PropertyList();
										propertyList->add(std::shared_ptr<Property>((yyvsp[0].propertyVal)));

										(yyval.propertyListVal) = propertyList;
									}
#line 1591 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 23:
#line 212 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.propertyVal) = new Property((yyvsp[-2].stringVal), std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1599 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 24:
#line 215 "SimpleScript.y" /* yacc.c:1652  */
    {
										FunctionDeclarationStatement* fdstmtPtr = dynamic_cast<FunctionDeclarationStatement*> ((yyvsp[0].statementVal));
										Function funct = fdstmtPtr->getFunction();

										(yyval.propertyVal) = new Property((yyvsp[-2].stringVal), std::shared_ptr<Function>(new Function(funct)));
									}
#line 1610 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 25:
#line 221 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.propertyVal) = new Property((yyvsp[-2].stringVal), std::shared_ptr<ObjectLiteral>((yyvsp[0].objectLiteralVal)));
									}
#line 1618 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 26:
#line 226 "SimpleScript.y" /* yacc.c:1652  */
    { (yyval.operationExpressionVal) = (yyvsp[-1].operationExpressionVal); }
#line 1624 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 27:
#line 227 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Primitive primitive = Primitive((yyvsp[0].integerVal));
										(yyval.operationExpressionVal) = new ConstantExpression(std::shared_ptr<Variable>(new Variable(primitive))); 
									}
#line 1633 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 28:
#line 231 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Primitive primitive = Primitive((yyvsp[0].floatVal));
										(yyval.operationExpressionVal) = new ConstantExpression(std::shared_ptr<Variable>(new Variable(primitive))); 
									}
#line 1642 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 29:
#line 235 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Primitive primitive = Primitive((yyvsp[0].booleanVal));
										(yyval.operationExpressionVal) = new ConstantExpression(std::shared_ptr<Variable>(new Variable(primitive))); 
									}
#line 1651 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 30:
#line 239 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Primitive primitive = Primitive(std::string((yyvsp[0].stringVal)), true);
										(yyval.operationExpressionVal) = new ConstantExpression(std::shared_ptr<Variable>(new Variable(primitive))); 

									}
#line 1661 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 31:
#line 244 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new LogicalAnd(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1670 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 32:
#line 248 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new LogicalOr(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1679 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 33:
#line 252 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new LessThan(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1688 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 34:
#line 256 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new LessThanOrEqualTo(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1697 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 35:
#line 260 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new GreaterThan(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1706 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 36:
#line 264 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new GreaterThanOrEqualTo(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1715 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 37:
#line 268 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new Equals(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1724 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 38:
#line 272 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new NotEquals(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1733 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 39:
#line 276 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new Addition(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1742 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 40:
#line 280 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new Subtraction(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1751 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 41:
#line 284 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new Multiplication(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1760 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 42:
#line 288 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new Division(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1769 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 43:
#line 292 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new LogicalNot(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1777 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 44:
#line 295 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new Negation(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal))); 
									}
#line 1785 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 45:
#line 298 "SimpleScript.y" /* yacc.c:1652  */
    { (yyval.operationExpressionVal) = (yyvsp[0].operationExpressionVal); }
#line 1791 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 46:
#line 299 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new IdentifierExpression(std::shared_ptr<Identifier>((yyvsp[0].identifierVal))); 
									}
#line 1799 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 47:
#line 304 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = new FunctionCallExpression(
											std::shared_ptr<Identifier>((yyvsp[-3].identifierVal)), 
											std::shared_ptr<ArgumentsList>((yyvsp[-1].argumentsListyVal)));
									}
#line 1809 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 48:
#line 311 "SimpleScript.y" /* yacc.c:1652  */
    { 
										ArgumentsList* argsList = new ArgumentsList();
										(yyval.argumentsListyVal) = argsList;
									}
#line 1818 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 49:
#line 315 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyvsp[-2].argumentsListyVal)->add(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
										(yyval.argumentsListyVal) = (yyvsp[-2].argumentsListyVal);
									}
#line 1827 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 50:
#line 319 "SimpleScript.y" /* yacc.c:1652  */
    { 
										ArgumentsList* argsList = new ArgumentsList();
										argsList->add(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));

										(yyval.argumentsListyVal) = argsList;
									}
#line 1838 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 51:
#line 327 "SimpleScript.y" /* yacc.c:1652  */
    { (yyval.operationExpressionVal) = (yyvsp[0].operationExpressionVal); }
#line 1844 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 52:
#line 330 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.statementVal) = new VariableDeclarationStatement(
											std::shared_ptr<OperationExpressionsList>((yyvsp[-1].operationExpressionsListVal)));
									}
#line 1853 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 53:
#line 336 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyvsp[-2].operationExpressionsListVal)->add(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));

										(yyval.operationExpressionsListVal) = (yyvsp[-2].operationExpressionsListVal);
									}
#line 1863 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 54:
#line 341 "SimpleScript.y" /* yacc.c:1652  */
    { 
										OperationExpressionsList* list = new OperationExpressionsList();
										list->add(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));

										(yyval.operationExpressionsListVal) = list;
									}
#line 1874 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 55:
#line 349 "SimpleScript.y" /* yacc.c:1652  */
    { (yyval.operationExpressionVal) = (yyvsp[0].operationExpressionVal); }
#line 1880 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 56:
#line 350 "SimpleScript.y" /* yacc.c:1652  */
    {
										Primitive zeroPrimitive = Primitive(0);
										Variable zero = Variable(zeroPrimitive);
										ConstantExpression zeroConstantExpression =
											ConstantExpression(std::shared_ptr<Variable>(new Variable(zero)));
										
										(yyval.operationExpressionVal) = new OperationExpressionAssignment(std::shared_ptr<Identifier>(new Identifier((yyvsp[0].stringVal))), 
												std::shared_ptr<OperationExpression>(new ConstantExpression(zeroConstantExpression)));
									}
#line 1894 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 57:
#line 361 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Function* functionPtr = new Function(std::shared_ptr<ParametersList>((yyvsp[-2].parametersListVal)), 
											std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal)));

										(yyval.statementVal) = new FunctionDeclarationStatement(std::shared_ptr<Function>(functionPtr), 
											std::shared_ptr<Identifier>(new Identifier((yyvsp[-4].stringVal))));

									}
#line 1907 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 58:
#line 369 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Function* functionPtr = new Function(std::shared_ptr<ParametersList>((yyvsp[-2].parametersListVal)), 
											std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal)));

										(yyval.statementVal) = new FunctionDeclarationStatement(std::shared_ptr<Function>(functionPtr));

									}
#line 1919 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 59:
#line 378 "SimpleScript.y" /* yacc.c:1652  */
    { 
										ParametersList* paramsList = new ParametersList();
										(yyval.parametersListVal) = paramsList;
									}
#line 1928 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 60:
#line 382 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyvsp[-2].parametersListVal)->add((yyvsp[0].stringVal));
										(yyval.parametersListVal) = (yyvsp[-2].parametersListVal);
									}
#line 1937 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 61:
#line 386 "SimpleScript.y" /* yacc.c:1652  */
    { 
										ParametersList* paramsList = new ParametersList();
										paramsList->add((yyvsp[0].stringVal));

										(yyval.parametersListVal) = paramsList;
									}
#line 1948 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 62:
#line 394 "SimpleScript.y" /* yacc.c:1652  */
    { (yyval.statementsListVal) = (yyvsp[-1].statementsListVal); }
#line 1954 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 63:
#line 397 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.statementVal) = new ReturnStatement(std::shared_ptr<OperationExpression>((yyvsp[-1].operationExpressionVal)));
									}
#line 1962 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 64:
#line 400 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.statementVal) = new ReturnStatement();
								}
#line 1970 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 65:
#line 405 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.statementVal) = new IterationStatement(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
												std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal)));
									}
#line 1979 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 66:
#line 411 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.statementVal) = new ConditionalStatement(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)), 
												std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal)));
									}
#line 1988 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 67:
#line 415 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.statementVal) = new ConditionalStatement(std::shared_ptr<OperationExpression>((yyvsp[-4].operationExpressionVal)), 
												std::shared_ptr<StatementsList>((yyvsp[-2].statementsListVal)), std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal)));
									}
#line 1997 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 68:
#line 421 "SimpleScript.y" /* yacc.c:1652  */
    { (yyval.statementsListVal) = (yyvsp[-1].statementsListVal); }
#line 2003 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 69:
#line 422 "SimpleScript.y" /* yacc.c:1652  */
    { 
										StatementsList* stmtsList = new StatementsList();
										stmtsList->add(std::shared_ptr<Statement>((yyvsp[0].statementVal)));

										(yyval.statementsListVal) = stmtsList;
									}
#line 2014 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 71:
#line 433 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Identifier* id = new Identifier(*((yyvsp[-2].identifierVal)), (yyvsp[0].stringVal));
										(yyval.identifierVal) = id;

										delete (yyvsp[-2].identifierVal);
										delete [] (yyvsp[0].stringVal);
									}
#line 2026 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 72:
#line 440 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Identifier* id = new Identifier(*((yyvsp[-3].identifierVal)), (yyvsp[-1].stringVal), true);
										(yyval.identifierVal) = id;

										delete (yyvsp[-3].identifierVal);
										delete [] (yyvsp[-1].stringVal);
									}
#line 2038 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;

  case 73:
#line 447 "SimpleScript.y" /* yacc.c:1652  */
    { 
										Identifier* id = new Identifier((yyvsp[0].stringVal));
										(yyval.identifierVal) = id;
										delete [] (yyvsp[0].stringVal);
									}
#line 2048 "SimpleScript.tab.cpp" /* yacc.c:1652  */
    break;


#line 2052 "SimpleScript.tab.cpp" /* yacc.c:1652  */
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
#line 455 "SimpleScript.y" /* yacc.c:1918  */

