#include <iostream>
using namespace std;

class Stack
{
private:
	int* data;
	int N;
	int cur;
public:
	Stack(int N)
	{
		cur = 0;
		this->N = N;
		data = new int[N];
		for (int i = 0; i < N; i++)
		{
			data[i] = 0;
		}
	}
	bool empty()
	{

		return cur == 0;
	}
	int top()
	{
		if (empty())	return -1;
		return data[cur - 1];
	}
	void push(int X)
	{
		data[cur] = X;
		cur++;
	}
	int pop()
	{
		if (empty())	return -1;
		cur--;
		return data[cur];
	}
	int size()
	{
		return cur;
	}
};

int calculate(Stack *s, char op)
{
	int tmp2 = s->pop();
	int tmp1 = s->pop();
	switch (op)
	{
	case '+':
		return tmp1 + tmp2;
	case '-':
		return tmp1 - tmp2;
	case '*':
		return tmp1 * tmp2;
	case '/':
		return tmp1 / tmp2;
	}
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		Stack* stack = new Stack(10000);
		string exp;
		cin >> exp;
		for (int j = 0; j < (int)exp.length(); j++)
		{
			if ('0' <= exp[j] && exp[j] <= '9')
			{
				stack->push((int)(exp[j] - '0'));
			}
			else
			{
				stack->push(calculate(stack, exp[j]));
			}
		}
		cout << stack->pop() << endl;
	}
}