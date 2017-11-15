#include <iostream>
using namespace std;

class Node 
{
	public:
		int value;
		Node* next;
		Node (int v) { value = v; }
};

class LinkedList
{
	private:
		Node* head;
		Node* tail;
		
		
	public:
		LinkedList() { head = NULL; tail = NULL; }
		LinkedList(int v) { head = NULL; tail = NULL; addNodeEnd(v); }
		void addNodeEnd (int v)
		{
			// If the list is empty then we add the head
			if (head==NULL) { head = new Node(v); return; }
			
			// If the list is not empty, we browse it until we find the end
			Node* current = head;
			while (current->next != NULL)
				current = current->next;
			
			// We add the node at the end
			current->next = new Node(v);
		}

		void addNodeBeginning (int v)
		{
			Node* newNode = new Node(v);
			newNode->next = head;
			head = newNode;

		}

		void deleteNode(int v)
		{
			// Is it the head that we want to delete ?
			if (head->value == v)
			{
				head = head->next; 
				return;
			}
		
			for (Node* current = head; current!=NULL; current = current->next)
			{
				if (current->next && current->next->value==v)
				{
					// We "jump over" it
					current->next = current->next->next;
					return;
				}
			}	
			
		}

		void printAll() const
		{
			if (head == NULL) { cout << "Nothing to print yet!"; return; }
			Node* current = head;
			cout << head->value;
			while (current->next != NULL)
			{
				current = current->next;
				cout << " < " ;
				cout << current->value;
			}
		}
};


