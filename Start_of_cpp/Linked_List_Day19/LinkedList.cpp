#include <iostream>

using namespace std;

class Node {
public:
	int value;
	Node* next;

	Node(int value)
	{
		this->value = value;
		next = NULL;
	}
};

class LinkedList
{
private:
	Node* head;
	Node* tail;
	int count;

public:
	LinkedList(int value)
	{
		Node* node = new Node(value);
		head = node;
		tail = node;
		count = 1;
	}

	~LinkedList()
	{
		Node* tmp = head;
		while (head)
		{
			head = head->next;
			delete tmp;
			tmp = head;
		}
	}

	void printHead()
	{
		if (head != NULL)
		{
			cout << "Head: " << head->value << endl;
		}
	}

	void printTail()
	{
		if (head != NULL)
		{
			cout << "Tail: " << tail->value << endl;
		}
	}

	void getcount()
	{
		cout << "List count: " << this->count << endl;
	}

	void appendList(int value)
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

	void printList()
	{
		Node* tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->value << ", ";
			tmp = tmp->next;
		}
		cout << endl;
	}

	void deleteLastNode()
	{
		if (count == 0)
			return;

		Node* temp1 = head;
		Node* temp2 = head;

		while (temp1->next)
		{
			temp2 = temp1;
			temp1 = temp1->next;
		}
		
		tail = temp2;
		tail->next = NULL;
		count--;

		if (count == 0)
		{
			head = NULL;
			tail = NULL;
		}

		delete temp1;
	}

	void addFirst(int value)
	{
		Node* node = new Node(value);

		if (count == 0)
		{
			head = node;
			tail = node;
		}
		else
		{
			node->next = head;
			head = node;
		}
		count++;
	}

	void deleteFirst()
	{
		if (count == 0)
			return;

		Node* temp = head;

		if (count == 1)
		{
			head = NULL;
			tail = NULL;
		}
		else {
			head = head->next;
		}
		delete temp;
		count--;
	}

	Node* getNode(int index)
	{
		if (index < 0 || index >= count)
			return NULL;

		Node* temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return temp;
	}

	bool setValue(int index, int newValue)
	{
		Node* temp = this->getNode(index);
		if (temp != NULL) // if (temp)
		{
			temp->value = newValue;
			return true;
		}
		return false;
	}

	bool insertNode(int index, int value)
	{
		if (index >= 0 && index <= count)
		{
			if (index == 0)
			{
				addFirst(value);
				return true;
			}
			else if (index == count)
			{
				appendList(value);
				return true;
			}

			Node* newNode = new Node(value);
			Node* temp = getNode(index - 1);
			newNode->next = temp->next;
			temp->next = newNode;
			count++;
			return true;
		}
		else
			return false;
	}

	bool deleteNode(int index)
	{
		if (index >= 0 && index < count)
		{
			if (index == 0)
			{
				deleteFirst();
				return true;
			}
			else if (index == (count - 1))
			{
				deleteLastNode();
				return true;
			}
			else
			{
				Node* del = getNode(index);
				Node* temp = getNode(index - 1);

				temp->next = del->next;
				delete del;
				count--;
				return true;
			}
		}
	}
};

int main()
{
	LinkedList* linkedlis1 = new LinkedList(12);
	linkedlis1->appendList(5);
	linkedlis1->appendList(24);
	linkedlis1->appendList(8);
	linkedlis1->appendList(7);

	linkedlis1->getcount();
	linkedlis1->printHead();
	linkedlis1->printTail();
	linkedlis1->printList();

	//linkedlis1->deleteLastNode();
	//linkedlis1->deleteLastNode();
	//linkedlis1->addFirst(1);

	//linkedlis1->deleteFirst();
	//linkedlis1->deleteFirst();
	//linkedlis1->printList();

	
	Node* result = linkedlis1->getNode(0);
	if (result != NULL)
		cout << result->value << endl;
	else
		cout << "Boundary condition error!" << endl;
	
	
	if (linkedlis1->setValue(3, 10))
		cout << "Chenged values!" << endl;
	else
		cout << "Not Chenged values! Check your index" << endl;
	
	
	if (linkedlis1->insertNode(5, 42))
		cout << "Added values!" << endl;
	else
		cout << "Not added values! Check your index" << endl;
	

	if (linkedlis1->deleteNode(4))
		cout << "Deleted values!" << endl;
	else
		cout << "Not deleted values! Check your index" << endl;

	linkedlis1->printList();

	delete linkedlis1;
}