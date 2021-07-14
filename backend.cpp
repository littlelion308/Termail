#include "backend.h"
#include <iostream>
#include <vector>
#include <curl/curl.h>

using namespace std;


backend::backend(char type_input, char tool_input, string options_input, string server_input)
{
	type = type_input;
	tool = tool_input;
	options = options_input;
	server = server_input;
	CURLcode res = CURLE_OK;
	while (!curl)
	{
	curl = curl_easy_init();
	}
	curl_easy_setopt(curl, CURLOPT_NETRC_FILE, "~./.config/Termail/netrc");
	curl_easy_setopt(curl, CURLOPT_USE_SSL, "CURLUSESSL_TRY");

};
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
	curl_easy_setopt(curl, CURLOPT_URL, server);
	res = curl_easy_perform(curl);
	const char *curl_easy_strerror(CURLcode errornum);




	/* string ret= *str.to_string(); */
	return "";

}
