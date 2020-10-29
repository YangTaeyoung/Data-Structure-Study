#include <iostream>
using namespace std;

class Queue
{
private:
	int* data;
	int f;
	int r;
	int N;
public:
	Queue(int N)
	{
		this->N = N;
		data = new int[N];
		f = 0;
		r = 0;
	}
	bool full()
	{
		return (r - f) == N;
	}
	bool empty()
	{
		return (r - f) == 0;
	}
	int front()
	{
		return data[f];
	}
	int rear()
	{
		return data[r - 1];
	}
	int size()
	{
		return r - f;
	}
	void enqueue(int X)
	{
		if (full())
			cout << "Full" << endl;
		else
		{
			data[r % N] = X;
			r++;
		}

	}
	int dequeue()
	{
		/*if (empty())
			cout << "Empty" << endl;
		else
		{
			cout << data[f % N] << endl;
			f++;
		}*/
		f++;
		return data[(f - 1) % N];
	}
};

class Game
{
private:
	Queue* p1;
	Queue* p2;

	int p1_score;
	int p2_score;
	int N;
public:
	Game(int N)
	{
		this->N = N;
		p1 = new Queue(N);
		p2 = new Queue(N);
		p1_score = 0;
		p2_score = 0;
	}
	void enqueue_p1(int card)
	{
		p1->enqueue(card);
	}
	void enqueue_p2(int card)
	{
		p2->enqueue(card);
	}
	int restHP(int p1_card, int p2_card)
	{
		return p1_card - p2_card;
	}
	int battle(int p1_card, int p2_card)
	{
		if (p1_card > p2_card)
		{
			return 1; // p1 이김
		}
		else if (p1_card < p2_card)
		{
			return 2; // p2 이김
		}
		else
		{
			return 0; // 비김
		}
	}
	void play()
	{	
		int addedHP = 0; // 남은 체력을 담는 임시 저장변수

		for (int i = 0; i < N; i++)
		{
			int p1_card = p1->dequeue(); // 플레이어 1 카드
			int p2_card = p2->dequeue(); // 플레이어 2 카드
			if (addedHP > 0)
				p1_card += (addedHP-1); 
			else if (addedHP < 0)
			{
				p2_card -= (addedHP+1);
			}
			if (battle(p1_card, p2_card) == 1)
			{
				p1_score++;
			}
			if (battle(p1_card, p2_card) == 2)
			{
				p2_score++;
			}
			addedHP = restHP(p1_card, p2_card);
		}
		cout << battle(p1_score, p2_score) << endl;
	}
};

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		Game* game = new Game(N);
		for (int i = 0; i < N; i++)
		{
			int card;
			cin >> card;
			game->enqueue_p1(card);
		}
		for (int i = 0; i < N; i++)
		{
			int card;
			cin >> card;
			game->enqueue_p2(card);
		}
		game->play();
	}

	
	return 0;
}