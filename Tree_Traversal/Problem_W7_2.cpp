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
		else
		{
			cout << 0 << endl;
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
				Node* child = new Node(node_list.at(i), chi_data);
				node_list.at(i)->insertChild(child);
				node_list.push_back(child);
				break;
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
	vector<Node*> getEqualDepth(int depth)
	{
		vector<Node*> list;
		for (int i = 0; i < node_list.size(); i++)
		{
			if (getDepth(node_list.at(i)->getData()) == depth)
			{
				list.push_back(node_list.at(i));
			}
		}
		return list;
	}
	int getMax(vector<Node*> candidate_list)
	{
		if (!candidate_list.empty())
		{
			int max = candidate_list.at(0)->getData();
			for (int i = 1; i < candidate_list.size(); i++)
			{
				if (max < candidate_list.at(i)->getData())
				{
					max = candidate_list.at(i)->getData();
				}
			}
			return max;
		}
		else
			return 0;
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
	int getDepth(int data)
	{
		int depth = 0;
		for (int i = 0; i < node_list.size(); i++)
		{
			if (node_list.at(i)->getData() == data)
			{
				Node* nowNode = node_list.at(i);
				for (Node* tmp = nowNode; tmp != root; tmp = tmp->getParent())
				{
					depth++;
				}
				break;
			}
		}
		return depth;
	}
	Node* getRoot()
	{
		return root;
	}
	void setRoot(Node* root)
	{
		this->root = root;
	}
	void postOrderPrint(Node* node)
	{
		for (int i = 0; i < node->getChildren().size(); i++)
		{
			postOrderPrint(node->getChildren().at(i));
		}
		cout << node->getData() << " ";
	}
	void preOrderPrint(Node* node)
	{
		cout << node->getData() << " ";
		for (int i = 0; i < node->getChildren().size(); i++)
		{
			preOrderPrint(node->getChildren().at(i));
		}

	}
};

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;
		Tree* tree = new Tree(1);
		for (int j = 0; j < M; j++)
		{
			int par_data, chi_data;
			cin >> par_data >> chi_data;
			tree->insert(par_data, chi_data);
		}
		tree->postOrderPrint(tree->getRoot());
		cout << endl;
		delete tree;
	}
	return 0;
}