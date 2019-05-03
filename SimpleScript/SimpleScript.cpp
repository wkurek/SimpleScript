#include <iostream>

extern int yyparse();
extern FILE* yyin;

using namespace std;

int main(int argc, char** argv)
{
	if (argc <= 1) {
		if (argv[0])
			std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
		else
			std::cerr << "Usage: <program name> <file_path>" << std::endl;

		exit(1);
	} else if (argc > 1) {
		fopen_s(&yyin, argv[1], "r+");

		if (yyin == NULL) {
			std::cerr << "error: could not open file \"" << argv[1] << "\" for reading" << std::endl;
			std::cerr << "Usage: <program name> <file_path>" << std::endl;
			
			exit(1);
		}

		yyparse();
	}

	return 0;
}
