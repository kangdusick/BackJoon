#include <iostream>
#include <random>
#include <time.h>
#include <map>
using namespace std;

map<int, map<int, bool>> testcase;
int n,a,b,s;
void init()
{
    testcase.clear();
}
void makeAB()
{
    a = rand() % n + 1;
    b = rand() % n + 1;
    s = rand() % 1001;
    if (a == b || testcase[a][b] == true)
    {
        makeAB();
    }
}
int main()
{
    srand(time(0));
    int T = 5;
    int  d,c;
    cout << T << endl;
    for (int j = 0; j < T; j++)
    {
        init();
    n = rand() % 10 + 1;
    d = rand() % 10 + 1;
    c = rand() % n + 1;
    cout << n << " " << d << " " << c << endl;
    for (int i = 0; i < d; i++)
    {
        makeAB();
        testcase[a][b] = true;
        cout << a << " " << b << " " << s<< endl;
    }

    }
    return 0;
}