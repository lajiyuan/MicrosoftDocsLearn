#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
using namespace std;
class Text
{
public:
	explicit Text(string  context_): context(std::move(context_)){}
	~Text()
	{
		cout << "Text " << context << " destruct.";
		context.clear();
	}
	string context;
};
Text text("haha");
int main()
{
	cout << text.context << '\n';
	// exit(1); when exit , the program will output "Text haha destruct."
	abort();
}