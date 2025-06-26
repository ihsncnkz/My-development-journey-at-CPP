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

class Queue
{
private:
	int count;
	Node* head;
	Node* tail;

public:
	Queue(int value)
	{
		Node* node = new Node(value);
		head = node;
		tail = node;
		count = 1;
	}
	~Queue()
	{
		Node* temp = head;
		while (head)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
	}

	void printAll()
	{
		Node* temp = head;
		while (temp)
		{
			cout << temp->value << " , ";
			temp = temp->next;
		}
		cout << endl;
	}

	int getHeadValue()
	{
		if (head != NULL)
		{
			return head->value;
		}
		else
		{
			cout << "There is no head in queue!";
			return -1;
		}
	}

	int getTailValue()
	{
		if (tail != NULL)
		{
			return tail->value;
		}
		else
		{
			cout << "There is no tail in queue!";
			return -1;
		}
	}

	int getCount()
	{
		if (count != 0)
		{
			return count;
		}
		else
		{
			cout << "There is no element in queue!";
			return 0;
		}
	}

	void enqueue(int value)
	{
		Node* node = new Node(value);
		if (count == 0)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
		count++;
	}

	int dequeue()
	{
		if (count == 0)
			return INT_MIN;

		Node* temp = head;
		int value = head->value;
		if (count == 1)
		{
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head->next;
		}
		delete temp;
		count--;
		return value;
	}

	bool isEmpty()
	{
		if (count == 0)
			return true;
		else
			return false;
	}

};

int main()
{
	Queue *queue1 = new Queue(12);

	queue1->enqueue(24);
	queue1->enqueue(7);
	queue1->enqueue(15);
	queue1->printAll();

	

	cout << "Head: " << queue1->getHeadValue() << endl;
	cout << "tail: " << queue1->getTailValue() << endl;
	cout << "Count: " << queue1->getCount() << endl;

	cout << "Node value coming out of the queue: " << queue1->dequeue() << endl;
	queue1->printAll();
	cout << "Head: " << queue1->getHeadValue() << endl;
	cout << "Count: " << queue1->getCount() << endl;

	cout << "Are there any nodes in the queue? " << queue1->isEmpty() << endl;
	

	return 0;
}