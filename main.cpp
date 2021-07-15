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
	cout << "Test per creation" << endl;
	backend backend1('s','c',"", "imap://imap-mail.outlook.com");
	/* cout << backend1.getRun("curl wttr.in") << endl; */
	cout << "Test object initialized" << endl;
	/* cout << backend1.getType() << endl; */
	/* cout << backend1.getTool()  << endl; */
	/* cout << backend1.getOptions()  << endl; */
	backend1.getType();backend1.getTool();backend1.getOptions();
	cout << "Test after output" << endl;
	cout << backend1.getMail("INBOX") << endl;
	return 0;
}
