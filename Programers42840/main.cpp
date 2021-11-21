#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> person[3];
    person[0] = { 1,2,3,4,5 };
    person[1] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    person[2] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int answersSize = answers.size();
    vector<int> answer;
    int solCount[3];
    for (int i = 0; i < 3; i++)
    {
        int personLen = person[i].size();
        int cnt = 0;
        int sol = 0;
        for (int j = 0; j < answersSize; j++)
        {
            if (answers[j] == person[i][cnt])
            {
                sol++;
            }
            cnt++;
            if (cnt == personLen)
            {
                cnt = 0;
            }
        }
        solCount[i] = sol;
    }
    int max = 0;
    for (int i = 0; i < 3; i++)
    {
        if (solCount[i] > max)
        {
            max = solCount[i];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (solCount[i] == max)
        {
            answer.push_back(i + 1);
        }
    }
    return answer;
}

int main()
{
    vector<int> answers = { 1,3,2,4,2 };
    vector<int> a = solution(answers);
    return 0;
}