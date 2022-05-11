#include <iostream> 
using namespace std;
int R, C;
char** board;
int maxx = 0;
bool check[26];
int ConvertAlphaToInt(char a)
{
	switch (a)
	{
	case 'A':
		return 0;
	case 'B':
		return 1;
	case 'C':
		return 2;
	case 'D':
		return 3;
	case 'E':
		return 4;
	case 'F':
		return 5;
	case 'G':
		return 6;
	case 'H':
		return 7;
	case 'I':
		return 8;
	case 'J':
		return 9;
	case 'K':
		return 10;
	case 'L':
		return 11;
	case 'M':
		return 12;
	case 'N':
		return 13;
	case 'O':
		return 14;
	case 'P':
		return 15;
	case 'Q':
		return 16;
	case 'R':
		return 17;
	case 'S':
		return 18;
	case 'T':
		return 19;
	case 'U':
		return 20;
	case 'V':
		return 21;
	case 'W':
		return 22;
	case 'X':
		return 23;
	case 'Y':
		return 24;
	case 'Z':
		return 25;
	}
}
void alpha(int x, int y, int sol)
{
	int temp;
	check[ConvertAlphaToInt(board[x][y])] = true;
	if (sol > maxx)
	{
		maxx = sol;
	}
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0://╩С
			temp = x - 1;
			if (temp >= 0 && check[ConvertAlphaToInt(board[temp][y])] == false)
			{
				alpha(temp, y, sol + 1);
				check[ConvertAlphaToInt(board[temp][y])] = false;
			}
			break;
		case 1://го
			temp = x + 1;
			if (temp < R && check[ConvertAlphaToInt(board[temp][y])] == false)
			{
				alpha(temp, y, sol + 1);
				check[ConvertAlphaToInt(board[temp][y])] = false;
			}
			break;
		case 2://аб
			temp = y - 1;
			if (temp >= 0 && check[ConvertAlphaToInt(board[x][temp])] == false)
			{
				alpha(x, temp, sol + 1);
				check[ConvertAlphaToInt(board[x][temp])] = false;
			}
			break;
		case 3://©Л
			temp = y + 1;
			if (temp < C && check[ConvertAlphaToInt(board[x][temp])] == false)
			{
				alpha(x, temp, sol + 1);
				check[ConvertAlphaToInt(board[x][temp])] = false;
			}
			break;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;
	board = new char* [R];
	for (int i = 0; i < R; i++)
	{
		board[i] = new char[C];
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
		}
	}
	alpha(0, 0, 1);
	cout << maxx;
	return 0;
}