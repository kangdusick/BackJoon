#include <iostream>
using namespace std;
int arr[1048577];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    while (cin >> num)
    {
        int Q = num / 32;
        int R = 1 << (num % 32);
        if (!(arr[Q] & R))
        {
            arr[Q] += R;
            cout << num << " ";
        }
    }
    cout << "\n";
    return 0;
}