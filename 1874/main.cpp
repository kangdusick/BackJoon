#include <iostream>

using namespace std;
class Stack
{
public:
	int data;
	Stack* next = nullptr;
	int GetTop()
	{
		Stack* top = next;
		if (top == nullptr)
		{
			return -1;
		}
		return top->data;
	}
	int Pop()
	{
		Stack* popData = this->next;
		if (popData == nullptr)
		{
			return -1;
		}
		int data = popData->data;
		this->next = popData->next;
		delete popData;
		return data;
	}
	void Push(int data)
	{
		Stack* s = new Stack;
		s->data = data;
		s->next = this->next;
		this->next = s;
	}

};

int main()
{
	Stack* stack = new Stack();
	int n = 1;
	int count = 0;
	cin >> n;
	int* destiny = new int[n];
	char* pm = new char[n * 2];
	int pmIndex = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> *(destiny + i);
	}
	for (int i = 1; i <= n; i++)
	{
		stack->Push(i);
		pm[pmIndex] = '+';
		pmIndex++;
		while (stack->GetTop() == destiny[count])
		{
			count++;
			stack->Pop();
			pm[pmIndex] = '-';
			pmIndex++;
		}
	}
	for (int i = 0; i < n * 2; i++)
	{
		cout << pm[i];
	}

	return 0;
}