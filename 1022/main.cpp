#include <iostream>
using namespace std;
int r1, c1, r2, c2;
int CalLen(int num)
{
	int len = 0;
	while (num>0)
	{
		num /= 10;
		len++;
	}
	return len;
}
int CalNum(int i, int j)
{
	int absI = abs(i);
	int absJ = abs(j);
	int high = absI > absJ ? absI : absJ;
	int less = absI > absJ ? j : i;
	int gap = abs(absI - absJ);
	int standard;
	int res;
	if (i > 0 && j > 0)
	{

		if (i < j) //대각선 위쪽에 있는경우
		{
			high--;
			standard = (high * 2 + 1) * (high * 2 + 1);
			res = standard + gap;
		}
		else //대각선 아래쪽에 있는경우
		{
			standard = (high * 2 + 1) * (high * 2 + 1);
			res = standard - gap ;
		}
	}
	else if (i > 0 && j <= 0)
	{
		standard = (high * 2 + 1) * (high * 2 + 1) - high * 2;
		if (less == j) //j 절대값이 더 작음
		{
			res = standard + gap;
		}
		else  //i 절대값이 더 작음
		{
			res = standard - gap ;
		}
	}
	else if (i <= 0 && j <= 0)
	{
		standard = (high * 2 + 1) * (high * 2 + 1) - high * 4;
		if (less == j) //j 절대값이 더 작음
		{
			res = standard - gap;
		}
		else  //i 절대값이 더 작음
		{
			res = standard + gap ;
		}

	}
	else if (i <= 0 && j > 0)
	{
		standard = (high * 2 + 1) * (high * 2 + 1) - high * 6;
		if (less == j) //j 절대값이 더 작음
		{
			res = standard + gap;
		}
		else  //i 절대값이 더 작음
		{
			res = standard - gap ;
		}
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r1 >> c1 >> r2 >> c2;
	int maxnum = 0;
	if (maxnum < CalNum(r1, c1))
	{
		maxnum = CalNum(r1, c1);
	}
	if (maxnum < CalNum(r2, c1))
	{
		maxnum = CalNum(r2, c1);
	}
	if (maxnum < CalNum(r1, c2))
	{
		maxnum = CalNum(r1, c2);
	}
	if (maxnum < CalNum(r2, c2))
	{
		maxnum = CalNum(r2, c2);
	}
	int maxLen = CalLen(maxnum);
	int tempNum;
	int tempLen;
	int tempgap;
	for (int i = r1; i <= r2; i++)
	{
		for (int j = c1; j <= c2; j++)
		{
			tempNum = CalNum(i, j);
			tempLen = CalLen(tempNum);
			tempgap = maxLen - tempLen;
			for (int ii = 0; ii < tempgap; ii++)
			{
				cout << " ";
			}
			cout<< tempNum<<" ";

		}
		cout << "\n";
	}
	return 0;
}
