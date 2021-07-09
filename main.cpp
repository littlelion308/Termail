#include <iostream>
#include "backend.h"
#include <string>

using namespace std;

string statusText(int version)
{
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
};

int main()
{
	cout << statusText(0);
	backend backend1 {'s','c',"string"};
	cout << backend1.getRun("curl wttr.in") << endl;
	return 0;
}
