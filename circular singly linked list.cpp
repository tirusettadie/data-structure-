#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node(int val) : data(val), next(nullptr) {}
};

class CircularSinglyLinkedList {
	private:
		Node *head;

	public:
		CircularSinglyLinkedList() : head(nullptr) {}

		void insertAtBeginning(int val) {
			Node *newNode = new Node(val);
			if (!head) {
				head = newNode;
				head->next = head;
			} else {
				Node *temp = head;
				while (temp->next != head) {
					temp = temp->next;
				}
				newNode->next = head;
				temp->next = newNode;
				head = newNode;
			}
			cout << val << " inserted at beginning.\n";
		}

		void insertAtEnd(int val) {
			Node *newNode = new Node(val);
			if (!head) {
				head = newNode;
				head->next = head;
			} else {
				Node *temp = head;
				while (temp->next != head) {
					temp = temp->next;
				}
				temp->next = newNode;
				newNode->next = head;
			}
			cout << val << " inserted at end.\n";
		}

		void insertAtPosition(int val, int pos) {
			if (pos < 0) {
				cout << "Invalid position!\n";
				return;
			}

			if (pos == 0) {
				insertAtBeginning(val);
				return;
			}

			Node *newNode = new Node(val);
			Node *temp = head;
			for (int i = 0; i < pos - 1; i++) {
				temp = temp->next;
				if (temp == head) {
					cout << "Position out of range!\n";
					delete newNode;
					return;
				}
			}

			newNode->next = temp->next;
			temp->next = newNode;
			cout << val << " inserted at position " << pos << ".\n";
		}

		void deleteFromBeginning() {
			if (!head) {
				cout << "List is empty!\n";
				return;
			}

			if (head->next == head) {
				cout << head->data << " deleted from beginning.\n";
				delete head;
				head = nullptr;
				return;
			}

			Node *temp = head;
			Node *last = head;
			while (last->next != head) {
				last = last->next;
			}
			head = head->next;
			last->next = head;
			cout << temp->data << " deleted from beginning.\n";
			delete temp;
		}

		void deleteFromEnd() {
			if (!head) {
				cout << "List is empty!\n";
				return;
			}

			if (head->next == head) {
				cout << head->data << " deleted from end.\n";
				delete head;
				head = nullptr;
				return;
			}

			Node *temp = head;
			Node *prev = nullptr;
			while (temp->next != head) {
				prev = temp;
				temp = temp->next;
			}
			prev->next = head;
			cout << temp->data << " deleted from end.\n";
			delete temp;
		}

		void deleteFromPosition(int pos) {
			if (!head || pos < 0) {
				cout << "Invalid operation!\n";
				return;
			}

			if (pos == 0) {
				deleteFromBeginning();
				return;
			}

			Node *temp = head;
			Node *prev = nullptr;
			for (int i = 0; i < pos; i++) {
				prev = temp;
				temp = temp->next;
				if (temp == head) {
					cout << "Position out of range!\n";
					return;
				}
			}

			prev->next = temp->next;
			cout << temp->data << " deleted from position " << pos << ".\n";
			delete temp;
		}

		void display() {
			if (!head) {
				cout << "List is empty!\n";
				return;
			}

			Node *temp = head;
			cout << "Circular Singly Linked List: ";
			do {
				cout << temp->data << " -> ";
				temp = temp->next;
			} while (temp != head);
			cout << "(head)\n";
		}
};

int main() {
	CircularSinglyLinkedList csll;
	int choice, value, position;

	do {
		cout << "\nCircular Singly Linked List Operations\n";
		cout << "1. Insert at beginning\n";
		cout << "2. Insert at end\n";
		cout << "3. Insert at position\n";
		cout << "4. Delete from beginning\n";
		cout << "5. Delete from end\n";
		cout << "6. Delete from position\n";
		cout << "7. Display list\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter value to insert: ";
				cin >> value;
				csll.insertAtBeginning(value);
				break;
			case 2:
				cout << "Enter value to insert: ";
				cin >> value;
				csll.insertAtEnd(value);
				break;
			case 3:
				cout << "Enter value to insert: ";
				cin >> value;
				cout << "Enter position: ";
				cin >> position;
				csll.insertAtPosition(value, position);
				break;
			case 4:
				csll.deleteFromBeginning();
				break;
			case 5:
				csll.deleteFromEnd();
				break;
			case 6:
				cout << "Enter position: ";
				cin >> position;
				csll.deleteFromPosition(position);
				break;
			case 7:
				csll.display();
				break;
			case 0:
				cout << "Exiting...\n";
				break;
			default:
				cout << "Invalid choice!\n";
		}
	} while (choice != 0);

	return 0;
}

