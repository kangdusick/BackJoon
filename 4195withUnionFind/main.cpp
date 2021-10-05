#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
template<typename T>
class UnionFind
{
public:
	map<T,T> parents;
	void Add(T data)
	{
		parents[data] = data;
	}
	T FindParents(T x)
	{
		if(parents[x] == x)
			return parents[x];
		else
		{
			T p = FindParents[p];
			parents[p] = x;
			return parents[p];

		}
	}
	void Union(T x, T y)
	{
		x = FindParents(x);
		y = FindParents(y);
		parents[y] = x;
	}
	
};

int main()
{
	UnionFind<int> abc;
	abc.Add(0);
	abc.Add(1);
	abc.Add(2);
	abc.Add(3);
	abc.Add(4);
	abc.Add(5);
	abc.Union(0, 1);
	abc.Union(1, 2);
	abc.Union(3, 4);
	abc.Union(0, 3);
	return 0;
}