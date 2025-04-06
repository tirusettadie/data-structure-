#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
	private:
		Node *head;

	public:
		SinglyLinkedList() : head(nullptr) {}

		void insertAtBeginning(int val) {
			Node *newNode = new Node(val);
			newNode->next = head;
			head = newNode;
			cout << val << " inserted at beginning.\n";
		}

		void insertAtEnd(int val) {
			Node *newNode = new Node(val);
			if (!head) {
				head = newNode;
			} else {
				Node *temp = head;
				while (temp->next) {
					temp = temp->next;
				}
				temp->next = newNode;
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
			for (int i = 0; temp && i < pos - 1; i++) {
				temp = temp->next;
			}

			if (!temp) {
				cout << "Position out of range!\n";
				delete newNode;
				return;
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
			Node *temp = head;
			head = head->next;
			cout << temp->data << " deleted from beginning.\n";
			delete temp;
		}

		void deleteFromEnd() {
			if (!head) {
				cout << "List is empty!\n";
				return;
			}

			if (!head->next) {
				cout << head->data << " deleted from end.\n";
				delete head;
				head = nullptr;
				return;
			}

			Node *temp = head;
			while (temp->next->next) {
				temp = temp->next;
			}
			cout << temp->next->data << " deleted from end.\n";
			delete temp->next;
			temp->next = nullptr;
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
			for (int i = 0; temp && i < pos; i++) {
				prev = temp;
				temp = temp->next;
			}

			if (!temp) {
				cout << "Position out of range!\n";
				return;
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
			cout << "Singly Linked List: ";
			while (temp) {
				cout << temp->data << " -> ";
				temp = temp->next;
			}
			cout << "NULL\n";
		}
};

int main() {
	SinglyLinkedList sll;
	int choice, value, position;

	do {
		cout << "\nSingly Linked List Operations\n";
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
				sll.insertAtBeginning(value);
				break;
			case 2:
				cout << "Enter value to insert: ";
				cin >> value;
				sll.insertAtEnd(value);
				break;
			case 3:
				cout << "Enter value to insert: ";
				cin >> value;
				cout << "Enter position: ";
				cin >> position;
				sll.insertAtPosition(value, position);
				break;
			case 4:
				sll.deleteFromBeginning();
				break;
			case 5:
				sll.deleteFromEnd();
				break;
			case 6:
				cout << "Enter position: ";
				cin >> position;
				sll.deleteFromPosition(position);
				break;
			case 7:
				sll.display();
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