#include "backend.h"
#include <iostream>
#include <vector>

using namespace std;


string backend::getRun(string command)
{

	char buffer[128];
	string result = "";

	// Open pipe to file
	FILE* pipe = popen(command.c_str(), "r");
	if (!pipe) {
		return "popen failed!";
	}

	// read till end of process:
	while (!feof(pipe)) {

		// use buffer to read and add to result
		if (fgets(buffer, 128, pipe) != NULL)
			result += buffer;
	}

	pclose(pipe);
	return result;
}

char backend::getType()
{
	cout << type << endl;
	return type;
}
char backend::getTool()
{
	cout << tool << endl;
	return tool;
}
string backend::getOptions()
{
	cout << options << endl;
	return options;
}
string backend::getMail(string mailbox)
{
	string toRun = "curl -X GET imap://" + server + "/" + mailbox + ";MAILINDEX=10";
	return getRun(toRun);

}
