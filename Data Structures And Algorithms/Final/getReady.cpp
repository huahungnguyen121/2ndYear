#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string haystack, string separator)
{
	vector<string> tokens;
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

		return tokens;
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

	return tokens;
}

vector<int> readDataArray(string dataStr) {
    vector<string> temp = split(dataStr, " ");
    vector<int> arr;

    for (size_t i = 0; i < temp.size(); i++)
        arr.push_back(stoi(temp[i]));

    return arr;
}