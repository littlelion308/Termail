#include "backend.h"
#include <iostram>
#include <vector>

public class backend{
	std::vector<std::string> getTest()
	{
		std::vector<std::string> test(5);
		test[0] = "test0";
		test[1] = "test1";
		test[2] = "test2";
		test[3] = "test3";
		test[4] = "test4";
		return test;
	}
}
