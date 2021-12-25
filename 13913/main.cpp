#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;
int before[MAX];
bool Check[MAX];
vector<int> sol;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    int frontM;
    int frontP;
    int front2;
    cin >> N >> K;
    queue<pair<int,int>> que;
    que.push(make_pair(N, 0));
    Check[N] = true;
    while (true)
    {
        int front = que.front().first;
        int nextTime = que.front().second+1;
        que.pop();
        if (front == K)
        {
            int iter = front;
            cout << nextTime - 1<<"\n";
            sol.push_back(iter);
            for (int i = 0; i < nextTime-2; i++)
            {
                iter = before[iter];
                sol.push_back(iter);
            }
            sol.push_back(N);
            for (int i = nextTime-1; i >=0; i--)
            {
                cout << sol[i] << " ";
            }
            cout << "\n";
            return 0;
        }
        frontM = front - 1;
        frontP = front + 1;
        front2 = front * 2;
        if (frontM >= 0 && !Check[frontM])
        {
            Check[frontM] = true;
            before[frontM] = front;
            que.push(make_pair(frontM, nextTime));
        }
        if (frontP <= 100000 && !Check[frontP])
        {
            Check[frontP] = true;
            before[frontP] = front;
            que.push(make_pair(frontP, nextTime));
        }
        if (front2 <= 100000 && !Check[front2])
        {
            Check[front2] = true;
            before[front2] = front;
            que.push(make_pair(front2, nextTime));
        }
    }
    return 0;

}