#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
	int value;
	Node* left;
	Node* right;

	Node(int value)
	{
		this->value = value;
		left = NULL;
		right = NULL;
	}
};

class BinarySearchTree
{
public:
	Node* root;

	BinarySearchTree()
	{
		root = NULL;
	}
	~BinarySearchTree()
	{
		deleteAllNode(root);
	}

	void deleteAllNode(Node* node)
	{
		if (node == NULL) return;
		if (node->left != NULL)
		{
			deleteAllNode(node->left);
		}
		if (node->right != NULL)
		{
			deleteAllNode(node->right);
		}
		delete node;
	}

	bool insertNode(int value)
	{
		Node* node = new Node(value);

		if (root == NULL)
		{
			root = node;
			return true;
		}

		Node* tmp = root;
		while (true)
		{
			if (node->value == tmp->value)
			{
				cout << "Trying to add value to what already exists!" << endl;
				delete node;
				return false;
			}
			if (node->value < tmp->value)
			{
				if (tmp->left == NULL)
				{
					tmp->left = node;
					return true;
				}
				tmp = tmp->left;
			}
			else
			{
				if (tmp->right == NULL)
				{
					tmp->right = node;
					return true;
				}
				tmp = tmp->right;
			}
		}
	}

	void DFSPreOrderSearchPrintAllNodes(Node* node)
	{
		cout << node->value << ", ";
		if (node->left != NULL)
		{
			DFSPreOrderSearchPrintAllNodes(node->left);
		}
		if (node->right != NULL)
		{
			DFSPreOrderSearchPrintAllNodes(node->right);
		}
	}

	Node* DFSPreOrderSearch(Node* node, int searchValue)
	{
		if (node == NULL || node->value == searchValue)
		{
			return node;
		}

		if (searchValue < node->value)
		{
			return DFSPreOrderSearch(node->left, searchValue);
		}
		else
		{
			return DFSPreOrderSearch(node->right, searchValue);
		}
	}

	void DFSPostOrderSearchPrintAllNodes(Node* node)
	{
		if (node->left != NULL)
		{
			DFSPostOrderSearchPrintAllNodes(node->left);
		}
		if (node->right != NULL)
		{
			DFSPostOrderSearchPrintAllNodes(node->right);
		}
		cout << node->value << ", ";
	}

	void DFSInOrderSearchPrintAllNodes(Node* node)
	{
		if (node->left != NULL)
		{
			DFSInOrderSearchPrintAllNodes(node->left);
		}
		cout << node->value << ", ";
		if (node->right != NULL)
		{
			DFSInOrderSearchPrintAllNodes(node->right);
		}	
	}

	void BreadthFirstSearch()
	{
		queue<Node*> queue1;
		queue1.push(root);

		while (queue1.size() > 0)
		{
			Node* node = queue1.front();
			queue1.pop();
			cout << node->value << ", ";

			if (node->left != NULL)
			{
				queue1.push(node->left);
			}
			if (node->right != NULL)
			{
				queue1.push(node->right);
			}
		}
	}
};

int main()
{
	BinarySearchTree* bst = new BinarySearchTree();
	bst->insertNode(52);
	bst->insertNode(27);
	bst->insertNode(15);
	bst->insertNode(30);
	bst->insertNode(78);
	bst->insertNode(65);
	bst->insertNode(53);

	
	bst->insertNode(76);
	bst->insertNode(12);

	//bst->DFSPreOrderSearchPrintAllNodes(bst->root);

	Node* ptr = bst->DFSPreOrderSearch(bst->root, 1);
	if (ptr != NULL)
	{
		cout << "Find your search value in bst: " << ptr->value << endl;
	}
	else
	{
		cout << "There is not your search value in bst!" << endl;
	}

	delete ptr;
	
	bst->DFSPreOrderSearchPrintAllNodes(bst->root);
	cout << endl;
	bst->DFSPostOrderSearchPrintAllNodes(bst->root);
	cout << endl;
	bst->DFSInOrderSearchPrintAllNodes(bst->root);
	cout << endl;
	bst->BreadthFirstSearch();

	delete bst;
	return 0;
}