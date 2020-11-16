#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Animal{
	char Type;
	string ID;
	float Weight;
	Animal* pNext;
};

struct AnimalList{
	Animal* pFirst;
	Animal* pLast;
};

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

Animal* createNode(string info)
{
	Animal* temp = new Animal;
	vector<string> data = split(info, " ");
	if (data.size() != 3)
	{
		delete temp;
		return NULL;
	}
	temp->Type = data[0];
	temp->ID = data[1];
	temp->Weight = stof(data[2]);
	temp->pNext = NULL;
	return temp;
}

void addHead(AnimalList*& L, Animal*& data)
{
	data->pNext = L->pFirst;
	L->pFirst = data;
}

void addTail(AnimalList*& L, Animal*& data)
{
	if (L->pFirst == NULL && L->pLast == NULL)
	{
		addHead(L, data);
		return;
	}
	
	L->pLast->pNext = data;
	L->pLast = data;
	return;
}

void removeAll(AnimalList*& L)
{
	while (L->pFirst)
	{
		if (L->pFirst == NULL)
			continue;
		if (L->pFirst->pNext == NULL)
		{
			Animal* temp = L->pFirst;
			L->pFirst = NULL;
			L->pLast = NULL;
			delete temp;
			continue;
		}
		
		Animal* temp = L->pFirst;
		L->pFirst = L->pFirst->pNext;
		delete temp;
	}
}

void main(int argc, char **argv){
	bool flag = false;
	if (argc == 1)
		cout << "Error: no input argument.";
	else{
		if (strcmp(argv[1], "-b"))
		{
			flag = true;
			
			fstream f;
			string buffer;
			AnimalList* list = new AnimalList;
			
			list->pFirst = NULL;
			list->pLast = NULL;
			
			f.open("input.txt", ios::in);
			
			while (!f.eof())
			{
				getline(f, buffer, '\n');
				Animal* temp = createNode(buffer);
				
				if (temp->Type == 'C')
				{
					addHead(list, temp);
					continue;
				}
				if (temp->Type = 'D')
				{
					addTail(list, temp);
					continue;
				}
				delete temp;
			}
			
			f.close();
			
			for (Animal* p = list->pFirst; p; p = p->pNext)
				cout << p->Type << " " << p->ID << " " << p->Weight << endl;
				
			removeAll(list);
			
			return;
		}
		if (strcmp(argv[1], "-c"))
		{
			flag = true;
			
			fstream f;
			string buffer;
		
			f.open("input.txt", ios::in);
			
			while (!f.eof())
			{
				getline(f, buffer, '\n');
				Animal* temp = createNode(buffer);

				if (temp == NULL)
				{
					cout << buffer << endl;
					delete temp;
					continue;
				}
				
				if (temp->Type != 'C' && temp->Type != 'D')
				{
					cout << temp->Type << " " << temp->ID << endl;
				}
				if (temp->ID.length() != 3)
				{
					cout << temp->Type << " " << temp->ID << endl;
				}
				if (temp->Weight < 0)
				{
					cout << temp->Type << " " << temp->ID << endl;
				}
				if (temp->Type == 'C' && (temp->Weight <= 1 || temp->Weight >= 3.5))
				{
					cout << temp->Type << " " << temp->ID << endl;
				}
				if (temp->Type == 'D' && (temp->Weight <= 1.5 || temp->Weight >= 5.5))
				{
					cout << temp->Type << " " << temp->ID << endl;
				}
				delete temp;
			}
			
			f.close();
			
			return;
		}
		if (strcmp(argv[1], "-d"))
		{
			flag = true;
			
			flag = true;
			
			fstream f;
			string buffer;
			AnimalList* list = new AnimalList;
			
			list->pFirst = NULL;
			list->pLast = NULL;
			
			f.open("input.txt", ios::in);
			
			while (!f.eof())
			{
				getline(f, buffer, '\n');
				Animal* temp = createNode(buffer);
				
				if (temp->Type == 'C')
				{
					addHead(list, temp);
					continue;
				}
				if (temp->Type = 'D')
				{
					addTail(list, temp);
					continue;
				}
				delete temp;
			}
			
			f.close();
			
			f.open("output.txt", ios::out);
			
			for (Animal* p = list->pFirst; p; p = p->pNext)
			{
				string writer = "";
				if (temp->Type == 'C' && temp->Weight > 2.5)
					cout << p->Type << " " << p->ID << " " << p->Weight << endl;
				else if (temp->Type == 'D' && temp->Weight > 3)
					cout << p->Type << " " << p->ID << " " << p->Weight << endl;
				else
				{
					writer = p->Type + " " + p->ID + " " + p->Weight;
					
					f << writer << endl;
				}
			}
			
			f.close();
			
			removeAll(list);
			
			return;	
		}
		if (flag == false)
			cout << "Syntax Error.\n";
	}
}
