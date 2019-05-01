#include <iostream>

extern int yyparse();
extern FILE* yyin;

using namespace std;

int main(int argc, char** argv)
{
	if (argc > 1) {
		fopen_s(&yyin, argv[1], "r+");

		if (yyin == NULL) {
			cerr << "error: could not open file \"" << argv[1] << "\" for reading" << endl;
			return 1;
		}

		yyparse();
	}

	return 0;
}
