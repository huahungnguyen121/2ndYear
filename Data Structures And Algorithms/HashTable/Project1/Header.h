#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <vector>

using namespace std;

class Tokenizer
{
public:
	vector<string> tokens;
	void split(string haystack, string separator = " ");
	void printTokens();
};



#endif