#include <iostream>
#include <bitset>
using namespace std;
int M;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> M;
	string input = "";
	int num;
	bitset<20> bits;
	bitset<20> temp;
	for (int i = 0; i < M; i++)
	{
		cin >> input;
		if (!(input[1] == 'l' || input[1] == 'm'))
		{
			cin >> num;
		}
		temp = 1 << (num-1);
		if (input[1] == 'd') //add
		{
			if ((bits & temp).none())
			{
				bits |= temp;
			}
		}
		else if (input[1] == 'e') //remove
		{
			if (!(bits & temp).none())
			{
				bits ^= temp;
			}
		}
		else if (input[1] == 'h') //check
		{
			if (!(bits & temp).none())
			{
				cout << 1<<"\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if (input[1] == 'o') //toggle 
		{
			if ((bits & temp).none()==true) //없으면 추가
			{
				bits |= temp;
			}
			else //있으면 제거
			{
				bits ^= temp;
			}
		}
		else if (input[1] == 'l') //all
		{
			bits.set();
		}
		else if (input[1] == 'm') //empty
		{
			bits.reset();
		}
		input.clear();
	}

	return 0;
}