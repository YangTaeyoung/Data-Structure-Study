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
	int op1Prec = getOper_order(op1); // ���� ���ؿ� �ִ� ��
	int op2Prec = getOper_order(op2); // ���� �߰��� �༮
	
	if (op1Prec > op2Prec) // ���ÿ� �ִ� ���� �켱������ �� ����.
		return 1;
	else if (op1Prec < op2Prec) // ���� ���� ���� �켱������ �� ����.
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
			if (c == '(') // ���� ���� ��ȣ�� ��
			{
				stack->push(c);
			}
			else if (c == ')') // ���� �ݴ� ��ȣ�� ��
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
			else if (isNum(c)) // ���� ������ ��
			{
				cout << c;
			}
			else if (isOper(c)) // ���� �������� ��
			{
				if (stack->empty()) // ������ ������� ��
				{
					stack->push(c);
				}
				else 
				{
					if (compareOper(stack->top(), c) == -1) // ���� ���� ���� �켱������ �� ����.
					{
						stack->push(c);
					}
					else // ���ÿ� �ִ� ���� �켱������ �� ����.
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