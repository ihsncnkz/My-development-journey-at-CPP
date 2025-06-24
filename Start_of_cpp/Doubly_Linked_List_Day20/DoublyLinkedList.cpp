#include <iostream>

using namespace std;

class Node
{
public:
	int value;
	Node* next;
	Node* prev;

	Node(int value)
	{
		this->value = value;
		next = NULL;
		prev = NULL;
	}
};

class DoublyLinkedList
{
private:
	int count;
	Node* head;
	Node* tail;

public:
	DoublyLinkedList(int value)
	{
		Node* node = new Node(value);
		head = node;
		tail = node;
		count = 1;
	}

	~DoublyLinkedList()
	{
		Node* tmp = head;
		while (head)
		{
			head = head->next;
			delete tmp;
			tmp = head;
		}
	}

	void printList()
	{
		Node* tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->value << " , ";
			tmp = tmp->next;
		}
		cout << endl;
	}

	void printHead()
	{
		if (head != NULL)
			cout << "Head: " << head->value << endl;
	}

	void printTail()
	{
		if (tail != NULL)
			cout << "Tail: " << tail->value << endl;
	}

	void getCount()
	{
		cout << "Count: " << this->count << endl;
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
			node->prev = tail;
			tail = node;
		}
		count++;
	}

	void deleteLastNode()
	{
		if (count == 0)
			return;

		Node* temp = tail;

		if (count == 1)
		{
			head = NULL;
			tail = NULL;
		}
		else if (count != 1)
		{
			tail = tail->prev;
			tail->next = NULL;
		}

		delete temp;
		count--;
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
			head->prev = node;
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
		else if (count != 1)
		{
			head = head->next; //temp->next = head;
			head->prev = NULL;
		}

		delete temp;
		count--;
	}

	Node* getNode(int index)
	{
		if (index < 0 || index >= count)
			return NULL;

		Node* temp = head;
		if (index < count / 2)
		{
			for (int i = 0; i < index; i++)
			{
				temp = temp->next;
			}
		}
		else
		{
			temp = tail;
			for (int i = count - 1; i > index; i--)
			{
				temp = temp->prev;
			}
		}
		return temp;
	}

	bool setNode(int index, int value)
	{
		Node* changedNode = getNode(index);

		if (changedNode != NULL)
		{
			changedNode->value = value;
			return true;
		}
		else
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

			Node* node = new Node(value);
			Node* leftNode = getNode(index - 1);
			Node* rightNode = getNode(index);
			node->next = rightNode;
			node->prev = leftNode;
			leftNode->next = node;
			rightNode->prev = node;
			count++;
			return true;
		}
		else
			return false;
	}

	bool deleteNode(int index)
	{
		if (index >= 0 && index <= count)
		{
			if (index == 0)
			{
				deleteFirst();
				return true;
			}
			else if (index == count)
			{
				deleteLastNode();
				return true;
			}
			Node* delNod = getNode(index);
			delNod->prev->next = delNod->next;
			delNod->next->prev = delNod->prev;

			delete delNod;
			count--;
			return true;
		}
		else
			return false;
	}
};

int main()
{
	DoublyLinkedList* doublyLinkedList1 = new DoublyLinkedList(12);
	
	doublyLinkedList1->getCount();
	doublyLinkedList1->printHead();
	doublyLinkedList1->printTail();
	doublyLinkedList1->printList();
	

	doublyLinkedList1->appendList(5);
	doublyLinkedList1->appendList(24);
	doublyLinkedList1->appendList(9);
	doublyLinkedList1->printList();
	
	doublyLinkedList1->addFirst(42);
	doublyLinkedList1->addFirst(52);
	doublyLinkedList1->printList();
	

	//doublyLinkedList1->deleteLastNode();
	
	
	doublyLinkedList1->deleteFirst();
	doublyLinkedList1->deleteFirst();
	doublyLinkedList1->printList();
	

	//cout << doublyLinkedList1->getNode(3)->value << endl;

	//doublyLinkedList1->setNode(2, 14);
	//doublyLinkedList1->insertNode(2, 14);

	doublyLinkedList1->deleteNode(2);
	doublyLinkedList1->printList();

	delete doublyLinkedList1;

	return 0;
}