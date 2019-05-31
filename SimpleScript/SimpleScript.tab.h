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
#line 41 "SimpleScript.y" /* yacc.c:1921  */

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

#line 118 "SimpleScript.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SIMPLESCRIPT_TAB_H_INCLUDED  */
