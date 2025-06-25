#include <iostream>

using namespace std;

class Node
{
public:
	int value;
	Node* next;

	Node(int value)
	{
		this->value = value;
		next = NULL;
	}
};

class Stack
{
private:
	Node* top;
	int count;

public:
	Stack(int value)
	{
		Node* node = new Node(value);
		top = node;
		count = 1;
	}

	~Stack()
	{
		Node* temp = top;
		while (temp)
		{
			top = top->next;
			delete temp;
			temp = top;
		}
		
	}

	void printStack()
	{
		Node* temp = top;
		while (temp != NULL)
		{
			cout << temp->value << " , ";
			temp = temp->next;
		}
		cout << endl;
	}

	void printTop()
	{
		if (top != NULL)
			cout << "Top value: " << top->value << endl;
		else
			cout << "Stack is empty!" << endl;
	}

	void getCount()
	{
		cout << "Count: " << count << endl;
	}

	void push(int value)
	{
		Node* node = new Node(value);
		node->next = top;
		top = node;
		count++;
	}

	bool pop()
	{
		if (count != 0)
		{
			Node* temp = top;
			top = top->next;
			delete temp;
			count--;
			return true;
		}
		else
		{
			cout << "Stack Empty!";
			return false;
		}
	}

	bool isEmpty()
	{
		if (count != 0)
			return false;
		else
			return true;
	}
};

int main()
{
	Stack* stack1 = new Stack(24);
	stack1->printTop();
	if (stack1->isEmpty())
		cout << "Stack is empty" << endl;

	stack1->printTop();
	stack1->getCount();

	stack1->push(7);
	stack1->push(19);
	stack1->printStack();

	stack1->pop();
	stack1->printStack();
	stack1->pop();
	stack1->pop();
	stack1->pop();
	if (stack1->isEmpty())
		cout << "Stack is empty" << endl;
	stack1->printTop();

	delete stack1;
	return 0;
}