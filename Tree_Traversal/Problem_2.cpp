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
	Node* getRoot()
	{
		return root;
	}
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
	int getDepth(Node* elem)
	{
		int depth = 0;
		for (Node* tmp = elem; tmp != root; tmp = tmp->parent)
		{
			depth++;
		}
		return depth;
	}
	vector<int> getEqualDepth(int depth)
	{
		vector<int> depth_vector;
		for (int i = 0; i < size(); i++)
		{
			if (getDepth(node_list[i]) == depth)
			{
				depth_vector.push_back(node_list[i]->data);
			}
		}
		return  depth_vector;
	}
	int getMax(vector<int> vec)
	{
		int max = 0;
		for (unsigned int i = 0; i < vec.size(); i++)
		{
			if (vec[i] > max)
			{
				max = vec[i];
			}
		}
		return max;
	}
	void preorder(Node* node)
	{
		if (!node) return;
		cout << node->data << " ";
		for (unsigned int i = 0; i < node->children.size(); i++)
		{
			preorder(node->children[i]);
		}
	}
	void postorder(Node* node)
	{
		if (!node) return;
		for (unsigned int i = 0; i < node->children.size(); i++)
		{
			postorder(node->children[i]);
		}
		cout << node->data << " ";
	}
	Node* atIndex(int data)
	{
		for (int i = 0; i < size(); i++)
		{
			if (data == node_list[i]->data)
			{
				return node_list[i];
			}
		}
		return nullptr;
	}
	void getSeedLess(Node* node)
	{
		if (!node) return;
		for (unsigned int i = 0; i < node->children.size(); i++)
		{
			getSeedLess(node->children[i]);
		}
		if(node->children.size() == 0) // 자식이 없을 떄
			cout << node->data << " "; //데이터 출력
	}
};

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int M, grape;
		cin >> M >> grape;
		Tree* tree = new Tree();
		for (int i = 0; i < M; i++)
		{
			int par, data;
			cin >> par >> data;
			tree->insertNode(par, data);
		}
		tree->getSeedLess(tree->atIndex(grape));
		cout << endl;
	}

}
