#include <vector>
#include <iostream>
#include <curl/curl.h>

#ifndef backend_H
#define backend_H

class backend{
	private:
		char type; // i.e s for smtp, i for imap, p for pop3
		char tool; // i.e. c for curl, m for msmtp and potentially others
		std::string options; // additional options to the commands, authentification
		std::string server;
		CURL *curl;
		CURLcode res;
	public:
		// constructor
		backend(char type_input, char tool_input,
				std::string options_input,
				std::string server_input ) ;
		// to be moved into the private section, when no longer used externally
		std::string getRun(std::string comand);
		// Test
		char getType();
		char getTool();
		std::string getOptions();

		std::string getMail(std::string Mailbox);
};
#endif
