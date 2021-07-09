#include "backend.h"
#include <iostream>
#include <vector>

using namespace std;

backend::backend(char type_input, char tool_input, string options_input)
{
	char type = type_input;
	char tool = tool_input;
	string options = options_input;
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
