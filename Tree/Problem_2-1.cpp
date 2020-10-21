#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	int data;
	Node* parent;
	vector<Node*> children;
	Node(int data)
	{
		this->data = data;
		this->parent = nullptr;
	}
	~Node() {}

	void setParent(Node* parent)
	{
		this->parent = parent;
	}
	void insertChild(Node* child)
	{
		this->children.push_back(child);
	}
	void delChild(Node* child)
	{
		for (unsigned int i = 0; i < this->children.size(); i++)
		{
			if (this->children[i] == child)
				this->children.erase(this->children.begin() + i);
		}
	}
};

class Tree
{
private:
	Node* root;
	vector<Node*> node_list;
public:

	Tree()
	{
		root = new Node(1);
		node_list.push_back(root);
	}
	~Tree() {}
	int size()
	{
		return node_list.size();
	}
	void insertNode(int par_data, int data)
	{
		for (int i = 0; i < size(); i++)
		{
			if (node_list[i]->data == par_data)
			{
				Node* node = new Node(data);
				node->setParent(node_list[i]);
				node_list[i]->insertChild(node);
				node_list.push_back(node);
				return;
			}
		}
	}
	void delNode(int data)
	{
		Node* nownode;
		Node* par;
		for (int i = 0; i < size(); i++)
		{
			if (this->node_list[i]->data == data)
			{
				nownode = node_list[i];
				if (nownode == root)
				{
					return;
				}
				par = nownode->parent;
				for (Node*& child : nownode->children)
				{
					par->insertChild(child);
					child->parent = par;
				}
				par->delChild(nownode);
				this->node_list.erase(this->node_list.begin() + i);
				delete nownode;
			}
		}
		return;
	}
	void printChild(int data)
	{
		for (int i = 0; i < size(); i++)
		{
			if (node_list[i]->data == data)
			{
				if (node_list[i]->children.size() == 0)
				{
					cout << "0" << endl;
					return;
				}
				else
				{
					for (unsigned int j = 0; j < node_list[i]->children.size(); j++)
					{
						cout << node_list[i]->children[j]->data << " ";
					}
					cout << endl;
					return;
				}
			}
		}
	}
	void printSibling(int data)
	{
		for (int i = 0; i < size(); i++)
		{
			if (node_list[i]->data == data)
			{
				if (node_list[i]->parent == nullptr)
				{
					cout << data << endl;
					return;
				}
				else
				{
					Node* par_node = node_list[i]->parent;
					for (unsigned j = 0; j < par_node->children.size(); j++)
					{
						cout << par_node->children[j]->data << " ";
					}
					cout << endl;
					return;
				}
			}
		}
		cout << 0 << endl;
	}
	int getDepth(int data)
	{
		int depth = 0;
		for (int i = 0; i < size(); i++)
		{
			if (node_list[i]->data == data)
			{
				for (Node* tmp = node_list[i]; tmp != root; tmp = tmp->parent)
				{
					depth++;
				}
				break;
			}
		}
		return depth;
	}
};

int main()
{
	int N, M;
	cin >> N >> M;
	Tree* tree = new Tree();
	for (int i = 0; i < N; i++)
	{
		int par, data;
		cin >> par >> data;
		tree->insertNode(par, data);
	}
	for (int i = 0; i < M; i++)
	{
		int data;
		cin >> data;
		cout << tree->getDepth(data) << endl;
	}
}
