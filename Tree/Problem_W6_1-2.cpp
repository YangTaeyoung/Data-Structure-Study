#include<iostream>
#include<vector>
using namespace std;
class Node
{
private:
	int data;
	Node* parent;
	vector<Node*> children;

public:
	Node(Node* parent, int data)
	{
		this->parent = parent;
		this->data = data;
	}
	Node(int data) // 루트일때
	{
		this->parent = nullptr;
		this->data = data;
	}
	void setParent(Node* parent)
	{
		this->parent = parent;
	}
	Node* getParent()
	{
		return parent;
	}
	void setData(int data)
	{
		this->data = data;
	}
	int getData()
	{
		return data;
	}
	void insertChild(Node* child)
	{
		this->children.push_back(child);
	}
	Node* insertChild(int data)
	{
		Node* child = new Node(this, data);
		this->children.push_back(child);
		return child;
	}
	void delChild(int data)
	{
		for (int i = 0; i < children.size(); i++)
		{
			if (children.at(i)->data == data)
			{
				children.erase(children.begin() + i);
			}
		}
	}
	vector<Node*> getChildren()
	{
		return children;
	}
	void printChild()
	{
		if (!children.empty())
		{
			for (int i = 0; i < children.size(); i++)
			{
				cout << children.at(i)->data << " ";
			}
			cout << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	void printSibiling()
	{
		if (parent != nullptr && !parent->children.empty())
		{
			for (int i = 0; i < parent->children.size(); i++)
			{
				cout << parent->children.at(i)->data << " ";
			}
			cout << endl;
		}
		else // 루트일 경우 루트 하나만 출력함.
		{
			cout << 1 << endl;
		}
	}
};

class Tree
{
private:
	Node* root;
	vector<Node*> node_list;
public:
	Tree(int data)
	{
		root = new Node(data);
		node_list.push_back(root);
	}
	void insert(int par_data, int chi_data)
	{
		for (int i = 0; i < node_list.size(); i++)
		{
			if (node_list.at(i)->getData() == par_data)
			{
				node_list.push_back(node_list.at(i)->insertChild(chi_data));
			}
		}
	}
	void remove(int data)
	{
		for (int i = 0; i < node_list.size(); i++)
		{
			if (node_list.at(i)->getData() == data)
			{
				Node* nowNode = node_list.at(i); // 삭제할 대상
				Node* par = nowNode->getParent(); // 삭제할 대상의 부모
				par->delChild(data); // par의 children에서 nowNode 삭제.
				for (int j = 0; j < nowNode->getChildren().size(); j++)
				{
					nowNode->getChildren().at(j)->setParent(par);
					par->insertChild(nowNode->getChildren().at(j)); // 부모의 자식으로 삭제할 대상의 자식을 insert

				}
				node_list.erase(node_list.begin() + i);
			}
		}
	}
	void printChild(int data)
	{
		for (int i = 0; i < node_list.size(); i++)
		{
			if (node_list.at(i)->getData() == data)
			{
				Node* nowNode = node_list.at(i);
				nowNode->printChild();
				return;
			}
		}
	}
	void printSibiling(int data)
	{
		for (int i = 0; i < node_list.size(); i++)
		{
			if (node_list.at(i)->getData() == data)
			{
				Node* nowNode = node_list.at(i);
				nowNode->printSibiling();
				return;
			}
		}
	}
};

int main()
{
	int N;
	cin >> N;
	Tree* tree = new Tree(1);
	for (int i = 0; i < N; i++)
	{
		string operation;
		cin >> operation;
		if (operation == "insert")
		{
			int par_data, chi_data;
			cin >> par_data >> chi_data;
			tree->insert(par_data, chi_data);
		}
		if (operation == "delete")
		{
			int data;
			cin >> data;
			tree->remove(data);
		}
		if (operation == "print")
		{
			int data;
			cin >> data;
			//tree->printChild(data);
			tree->printSibiling(data);
		}
	}
	delete tree;
	return 0;
}