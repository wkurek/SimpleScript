SimpleScript: lex.yy.c SimpleScript.tab.c SimpleScript.tab.h
	g++ SimpleScript.tab.c lex.yy.c -lfl -o SimpleScript

SimpleScript.tab.c SimpleScript.tab.h: SimpleScript.y
	bison -d -v SimpleScript.y

lex.yy.c: SimpleScript.l SimpleScript.tab.h
	flex SimpleScript.l

