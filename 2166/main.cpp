#include <iostream>

using namespace std;

class XY
{
public:
	int x = 0;
	int y = 0;

};
XY xys[10001];
float A(XY xy1, XY xy2, XY xy3)
{
	return (xy1.x * xy2.y + xy2.x * xy3.y + xy3.x * xy1.y) - (xy2.x * xy1.y + xy3.x * xy2.y + xy1.x * xy3.y);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		XY xy;
		cin >> xy.x;
		cin >> xy.y;
		xys[i] = xy;
	}

	return 0;
}
