#include "backend.h"
#include <iostream>
#include <vector>
#include <curl/curl.h>
#include <stdio.h>

using namespace std;


backend::backend(char type_input, char tool_input, string options_input, string server_input)
{
	type = type_input;
	tool = tool_input;
	options = options_input;
	server = server_input;
	/* CURL *curl; */
	/* CURLcode res = CURLE_OK; */
	/* curl = curl_easy_init(); */
	/* if (curl) */
	/* { */
	/* 	curl_easy_setopt(curl, CURLOPT_NETRC_FILE, "~/.config/Termail/netrc"); */
	/* 	curl_easy_setopt(curl, CURLOPT_USE_SSL, "CURLUSESSL_TRY"); */

	/* 	curl_easy_setopt(curl, CURLOPT_URL, server); */
	/* } */

};

string backend::getMail(string mailbox)
{
	cout << "function initialised" << endl;
	/* curl_easy_setopt(curl, CURLOPT_URL, "imap://imap-mail.outlook.com"); */
	cout << "Curl opt set" << endl;
	CURL *curl;
	CURLcode res = CURLE_OK;
	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_NETRC_FILE, "~/.config/Termail/netrc");
		/* curl_easy_setopt(curl, CURLOPT_USERNAME, ""); */
		/* curl_easy_setopt(curl, CURLOPT_PASSWORD, ""); */

		curl_easy_setopt(curl, CURLOPT_USE_SSL, "CURLUSESSL_TRY");
		curl_easy_setopt(curl, CURLOPT_URL, server);
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "EXAMINE INBOX");


		cout << "Curl == true" << endl;
		cout << "All curl opts set" << endl;
		res = curl_easy_perform(curl);
		cout << "Curl performed" << endl;
	}
	cout << "Curl performed" << endl;
	const char *curl_easy_strerror(CURLcode errornum);


	if(res != CURLE_OK)
		fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));



	/* string ret= *str.to_string(); */
	return "";

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
