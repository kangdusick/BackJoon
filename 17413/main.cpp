#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	vector<string> strs;
	stack<char> stk;
	string temp;
	int strLen = str.length();
	bool iscontinue = false;
	for (int i = 0; i < strLen; i++)
	{
		if (str[i] == '<')
		{
			while (stk.size() != 0)
			{
				temp.push_back(stk.top());
				stk.pop();
			}
			if (temp.size() != 0)
			{
				strs.push_back(temp);
				temp.clear();
			}
			temp.push_back('<');
			i++;
			while (true)
			{
				if (str[i] == '>')
				{
					temp.push_back('>');
					strs.push_back(temp);
					temp.clear();
					iscontinue = true;
					break;
				}
				else
				{
					temp.push_back(str[i]);
					i++;
				}
			}
		}
		if (iscontinue)
		{
			iscontinue = false;
			continue;
		}
		if (str[i] == ' ')
		{
			while (stk.size() != 0)
			{
				temp.push_back(stk.top());
				stk.pop();
			}
			if (temp.size() != 0)
			{
				temp.push_back(' ');
				strs.push_back(temp);
				temp.clear();
				continue;
			}
		}
		stk.push(str[i]);
	}
	while (stk.size() != 0)
	{
		temp.push_back(stk.top());
		stk.pop();
	}
	if (temp.size() != 0)
	{
		strs.push_back(temp);
	}
	for (int i = 0; i < strs.size(); i++)
	{
		cout << strs[i];
	}
	
	return 0;
}