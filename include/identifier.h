#include <vector>
#include <string>
using namespace std;

class Identifier
{
  vector<string> names;

  Identifier();

public:
  Identifier(string);
  Identifier(const Identifier, string);
  ~Identifier();

  string getHead();
  Identifier getTail();
  bool hasTail();
}
