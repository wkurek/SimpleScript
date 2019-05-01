/* A Bison parser, made by GNU Bison 3.3.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
#line 40 "SimpleScript.y" /* yacc.c:1921  */

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

#line 117 "SimpleScript.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SIMPLESCRIPT_TAB_H_INCLUDED  */
