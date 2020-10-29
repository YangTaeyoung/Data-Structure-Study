#include <iostream>
using namespace std;

class Stack
{
private:
	char* data;
	int N;
	int cur;
public:
	Stack(int N)
	{
		cur = 0;
		this->N = N;
		data = new char[N];
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
	void push(char X)
	{
		data[cur] = X;
		cur++;
	}
	char pop()
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
bool isOper(char item)
{
	if (item == '+' || item == '-' || item == '*' || item == '/')	
		return true;
	return false;
}
bool isNum(char item)
{
	if (item >= '0' && item<='9')
	{
		return true;
	}
	return false;
}
int getOper_order(char op)
{
	switch (op)
	{
	case '*':
		return 2;
	case '-':
		return 1;
	case '+':
		return 1;
	case '(':
		return 0;
	}
}
int compareOper(char op1, char op2)
{
	int op1Prec = getOper_order(op1); // 현재 스텍에 있는 넘
	int op2Prec = getOper_order(op2); // 새로 추가할 녀석
	
	if (op1Prec > op2Prec) // 스택에 있는 놈이 우선순위가 더 높다.
		return 1;
	else if (op1Prec < op2Prec) // 현재 들어온 놈이 우선순위가 더 높다.
		return -1;
	else
		return 0;
}
int main()
{
	int N;
	cin >> N;
	Stack* stack = new Stack(10000);
	for (int i = 0; i < N; i++)
	{
		string exp;
		cin >> exp;
		for (char& c : exp)
		{
			if (c == '(') // 현재 여는 괄호일 때
			{
				stack->push(c);
			}
			else if (c == ')') // 현재 닫는 괄호일 때
			{
				char tmp = '\0';
				while (true)
				{
					tmp = stack->pop();
					if (tmp != '(')
						cout << tmp;
					else
						break;
				}
			}
			else if (isNum(c)) // 현재 숫자일 때
			{
				cout << c;
			}
			else if (isOper(c)) // 현재 연산자일 때
			{
				if (stack->empty()) // 스텍이 비어있을 때
				{
					stack->push(c);
				}
				else 
				{
					if (compareOper(stack->top(), c) == -1) // 현재 들어온 놈이 우선순위가 더 높다.
					{
						stack->push(c);
					}
					else // 스택에 있는 놈이 우선순위가 더 높다.
					{
						cout << stack->pop();
						stack->push(c);
					}
				}
			}
			
		} // for end
		while (!stack->empty())
		{
			cout << stack->pop();
		}
		cout << endl;
	}
	return 0;
}