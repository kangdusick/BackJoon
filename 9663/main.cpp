#include <iostream>
#define MAX 15
using namespace std;

int col[MAX];
int N, total = 0;

bool check(int level)
{
    for (int i = 0; i < level; i++)
    {//가로 세로 대각선
        if (col[i] == col[level] || i == level || abs(col[i] - col[level]) == abs(i - level))
        {
            return false;
        }
    }
    return true;
}

void nqueen(int x)
{
    if (x == N)
        total++;
    else
    {
        for (int i = 0; i < N; i++)
        {
            col[x] = i;
            if (check(x))
            {
                nqueen(x + 1);
            }
        }
    }
}
int main() {
    cin >> N;
    nqueen(0);
    cout << total;
}