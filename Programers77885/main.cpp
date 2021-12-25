#include <string>
#include <vector>
#include <bitset>
#include <map>
using namespace std;
map<long long,long long> solss;
long long fx(long long a)
{
    if (solss[a] != 0)
    {
        return solss[a];
    }
    bitset<64> bi1 = a;
    bitset<64> bi2 = a+1;
    long long a2 = a + 1;
    while (true)
    {
        
        if ((bi1 ^ bi2).count() <= 2)
        {
            solss[a] = a2;
            return a2;
        }
        else
        {
            a2++;
            bi2 = a2;
        }
    }
    
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer; 
    int numsSize = numbers.size();

    for (int i = 0; i < numsSize; i++)
    {
        answer.push_back(fx(numbers[i]));
    }

    return answer;
}

int main()
{
    long long a = 1000000000000000;
    vector<long long> numbers = { a,a,a-5 };
    solution(numbers);
    return 0;
}