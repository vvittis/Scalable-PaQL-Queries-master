/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDE = 258,
     NUM = 259,
     NAT_NUM = 260,
     INFTY = 261,
     SELECT = 262,
     FROM = 263,
     WHERE = 264,
     PACKAGE = 265,
     REPEAT = 266,
     SUCH = 267,
     THAT = 268,
     AS = 269,
     ALL = 270,
     DEF = 271,
     LIMIT = 272,
     ORDER = 273,
     GROUP = 274,
     BY = 275,
     MAXIMIZE = 276,
     MINIMIZE = 277,
     INPUT = 278,
     OUTPUT = 279,
     DISTINCT = 280,
     OR = 281,
     AND = 282,
     NOT = 283,
     Op = 284,
     BETWEEN = 285,
     IN_P = 286,
     AT = 287,
     COLLATE = 288,
     UMINUS = 289,
     TYPECAST = 290
   };
#endif
/* Tokens.  */
#define IDE 258
#define NUM 259
#define NAT_NUM 260
#define INFTY 261
#define SELECT 262
#define FROM 263
#define WHERE 264
#define PACKAGE 265
#define REPEAT 266
#define SUCH 267
#define THAT 268
#define AS 269
#define ALL 270
#define DEF 271
#define LIMIT 272
#define ORDER 273
#define GROUP 274
#define BY 275
#define MAXIMIZE 276
#define MINIMIZE 277
#define INPUT 278
#define OUTPUT 279
#define DISTINCT 280
#define OR 281
#define AND 282
#define NOT 283
#define Op 284
#define BETWEEN 285
#define IN_P 286
#define AT 287
#define COLLATE 288
#define UMINUS 289
#define TYPECAST 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

