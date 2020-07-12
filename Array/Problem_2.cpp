#include<iostream>
using namespace std;
class Bank
{
public:
	int* arr;
	int size;
	int n;
	Bank(int size)
	{
		n = 0;
		this->size = size;
		arr = new int[size];
	}
	void setArr(int data)
	{
		arr[n] = data;
		n++;
	}
	int getKoreanCount()
	{
		int count = 0;
		for (int i = 0; i < size; i += 3)
		{
			if(arr[i] != 0)
				count++;
		}
		return count;
	}
	int getKoreanTotal()
	{
		int total = 0;
		for (int i = 0; i < size; i += 3)
		{
			total += arr[i];
		}
		return total;
	}
	int getKoreanAvg()
	{
		return getKoreanTotal() / getKoreanCount();
	}
	int getChinesesCount()
	{
		int count = 0;
		for (int i = 1; i < size; i += 3)
		{
			if (arr[i] != 0)
				count++;
		}
		return count;
	}
	int getChinesesTotal()
	{
		int total = 0;
		for (int i = 1; i < size; i += 3)
		{
			total += arr[i];
		}
		return total;
	}
	int getChinesesAvg()
	{
		return getChinesesTotal() / getChinesesCount();
	}
	int getJapaneseCount()
	{
		int count = 0;
		for (int i = 2; i < size; i += 3)
		{
			if (arr[i] != 0)
				count++;
		}
		return count;
	}
	int getJapaneseTotal()
	{
		int total = 0;
		for (int i = 2; i < size; i += 3)
		{
			total += arr[i];
		}
		return total;
	}
	int getJapaneseAvg()
	{
		return getJapaneseTotal() / getJapaneseCount();
	}
};
int main()
{
	int M;
	cin >> M;
	for(int i = 0; i< M; i++)
	{
		int size;
		cin >> size;
		Bank* bank = new Bank(size);
		for(int j = 0; j < size; j++)
		{
			int data;
			cin >> data;
			bank->setArr(data);
		}
		cout << bank->getKoreanTotal() << " " << bank->getChinesesTotal() << " " << bank->getJapaneseTotal() << endl;
		cout << bank->getKoreanAvg() << " " << bank->getChinesesAvg() << " " << bank->getJapaneseAvg() << endl;
	}
	return 0;
}