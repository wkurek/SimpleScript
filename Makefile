SimpleScript: lex.yy.c SimpleScript.tab.c SimpleScript.tab.h
	g++ SimpleScript.tab.c lex.yy.c -lfl -o SimpleScript

SimpleScript.tab.c SimpleScript.tab.h: SimpleScript.y
	bison -d -v SimpleScript.y

lex.yy.c: SimpleScript.l SimpleScript.tab.h
	flex SimpleScript.l

test: SimpleScript
	./SimpleScript tests/test.js

clean:
	rm SimpleScript.tab.c SimpleScript.tab.h lex.yy.c SimpleScript SimpleScript.output
