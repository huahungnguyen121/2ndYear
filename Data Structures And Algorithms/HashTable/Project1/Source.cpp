#include "Header.h"

void Tokenizer::split(string haystack, string separator)
{
	int startPos = 0;

	if (separator == " ")
	{
		while (true)
		{
			size_t foundPos = haystack.find(separator, startPos);
			if (foundPos != string::npos)
			{
				string token = haystack.substr(startPos, foundPos - startPos);
				if (token != "")
					tokens.push_back(token);

				startPos = foundPos + separator.length();
			}
			else
			{
				string token = haystack.substr(startPos, foundPos - startPos);
				if (token != "")
					tokens.push_back(token);
				break;
			}
		}

		return;
	}

	while (true)
	{
		size_t foundPos = haystack.find(separator, startPos);
		if (foundPos != string::npos)
		{
			string token = haystack.substr(startPos, foundPos - startPos);
			tokens.push_back(token);

			startPos = foundPos + separator.length();
		}
		else
		{
			string token = haystack.substr(startPos, foundPos - startPos);
			tokens.push_back(token);
			break;
		}
	}
}

void Tokenizer::printTokens()
{
	int size = this->tokens.size();
	for (int i = 0; i < size; i++)
		cout << tokens[i] << " ";
}