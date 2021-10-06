#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<int, vector<string>> person;
	map<int, vector<string>>::iterator iter;
	int N;
	int i;
	int age;
	int size;
	string name;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> age;
		cin >> name;
		person[age].push_back(name);
	}
	iter = person.begin();
	while (true)
	{
		size = (*iter).second.size();
		for (i = 0; i < size; i++)
		{
			cout << (*iter).first<<" ";
			cout << (*iter).second[i] <<"\n";
		}
		
		iter++;
		if (iter == person.end())
			break;
	}
	return 0;
}
