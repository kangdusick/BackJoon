#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
	char ML;
	char MR;
	char TL;
	char TR;

	cin >> ML >> MR >> TL >> TR;

	if (ML == MR)
	{
		switch (ML)
		{
		case 'S':
			if (TL == 'R' || TR == 'R')
			{
				cout << 'T' << 'K';
				return 0;
			}
			break;
		case 'R':
			if (TL == 'P' || TR == 'P')
			{
				cout << 'T' << 'K';
				return 0;
			}
			break;
		case 'P':
			if (TL == 'S' || TR == 'S')
			{
				cout << 'T' << 'K';
				return 0;
			}
			break;
		}
	}
	if (TL == TR)
	{
		switch (TL)
		{
		case 'S':
			if (ML == 'R' || MR == 'R')
			{
				cout << 'M' << 'S';
				return 0;
			}
			break;
		case 'R':
			if (ML == 'P' || MR == 'P')
			{
				cout << 'M' << 'S';
				return 0;
			}
			break;
		case 'P':
			if (ML == 'S' || MR == 'S')
			{
				cout << 'M' << 'S';
				return 0;
			}
			break;
		}
	}
	cout << '?';

	return 0;
}