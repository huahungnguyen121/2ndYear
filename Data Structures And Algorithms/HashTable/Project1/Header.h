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

struct Company {
	string name;
	string profit_tax;
	string address;
};

vector<Company> ReadCompanyList(string file_name);
long long HashString(string company_name);

#endif