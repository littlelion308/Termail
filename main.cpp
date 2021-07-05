#include <iostream>
using namespace std;
string statusText(int version)
{
	/* string statusText = "" ; */
	string endline = "\n";
	switch (version)
	{
		case 0:
			return "Hello World, but this should be an email client" + endline ;
			break;
		default:

			return "unable to find Version info" + endline ;
			break;


	}
}
int main()
{
	cout << statusText(0);
	/* cout << "Hello World, but this should" << endl; */
	/* cout << "be an email client"; */
	/* cout << endl; */
	return 0;
}
