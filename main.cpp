#include <iostream>
#include "backend.h"
#include <string>

/* using namespace std; */

std::string statusText(int version)
{
	std::string endline = "\n";
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
	std::cout << statusText(0);
	backend backend1;
	std::vector<std::string> test ;
	test = backend1.getTest();
	std::cout << test[0] << "\n";
	return 0;
}
