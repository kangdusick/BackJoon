#include <iostream>
using namespace std;
string* strings;
char path[26];
int maxLevel;
int R, C;
bool isEnd = false;
bool CheckPath(int level, int x, int y)
{
	if (x < 0 || y < 0 || x >= R || y >= C)
	{
		return false;
	}
	for (int i = 0; i <= level; i++)
	{
		if (path[i] == strings[x][y])
		{
			return false;
		}
	}
	return true;
}
void FindPath(int level, int x, int y )
{
	if (isEnd == true)
	{
		return;
	}
	path[level] = strings[x][y];
	if (CheckPath(level, x + 1, y))
	{
		FindPath(level + 1, x + 1, y);
	}
	else
	{
		if (maxLevel < level)
		{
			maxLevel = level;
			if (maxLevel == 25)
			{
				isEnd = true;
			}
		}
	}
	if (CheckPath(level, x - 1, y))
	{
		FindPath(level + 1, x - 1, y);
	}
	else
	{
		if (maxLevel < level)
		{
			maxLevel = level;
		}
	}
	if (CheckPath(level, x, y+1))
	{
		FindPath(level + 1, x , y+1);
	}
	else
	{
		if (maxLevel < level)
		{
			maxLevel = level;
		}
	}
	if (CheckPath(level, x , y-1))
	{
		FindPath(level + 1, x, y-1);
	}
	else
	{
		if (maxLevel < level)
		{
			maxLevel = level;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;
	strings = new string[R];
	for (int i = 0; i < R; i++)
	{
		cin >> strings[i];
	}
	FindPath(0, 0, 0);
	cout << maxLevel+1;
	return 0;
}

/*
20 20
ZYXWVUTSRQPONMLKJIHG
YXWVUTSRQPONMLKJIHGF
XWVUTSRQPONMLKJIHGFE
WVUTSRQPONMLKJIHGFED
VUTSRQPONMLKJIHGFEDC
UTSRQPONMLKJIHGFEhDCB
TSRQPONMLKJIHGFEDCBA
SRQPONMLKJIHGFEDCBAA
RQPONMLKJIHGFEDCBAAA
QPONMLKJIHGFEDCBAAAA
PONMLKJIHGFEDCBAAAAA
ONMLKJIHGFEDCBAAAAAA
NMLKJIHGFEDCBAAAAAAA
MLKJIHGFEDCBAAAAAAAA
LKJIHGFEDCBAAAAAAAAA
KJIHGFEDCBAAAAAAAAAA
JIHGFEDCBAAAAAAAAAAA
IHGFEDCBAAAAAAAAAAAA
HGFEDCBAAAAAAAAAAAAA
GFEDCBAAAAAAAAAAAAAA
´ä:26
*/