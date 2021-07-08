#include "backend.h"
#include <iostream>
#include <vector>

using namespace std;

vector<string> backend::getTest()
{
	vector<string> test(5);
	test[0] = "test0";
	test[1] = "test1";
	test[2] = "test2";
	test[3] = "test3";
	test[4] = "test4";
	return test;
}
