SimpleScript: lex.yy.c SimpleScript.tab.c SimpleScript.tab.h
	g++ SimpleScript.tab.c lex.yy.c -lfl -o SimpleScript

lex.yy.c: SimpleScript.l SimpleScript.tab.h
	flex SimpleScript.l

SimpleScript.tab.c SimpleScript.tab.h: SimpleScript.y
	bison -d SimpleScript.y