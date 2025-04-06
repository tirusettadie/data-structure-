#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *prev;
		Node *next;
		Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class CircularDoublyLinkedList {
	private:
		Node *head;

	public:
		CircularDoublyLinkedList() : head(nullptr) {}

		void insertAtBeginning(int val) {
			Node *newNode = new Node(val);
			if (!head) {
				newNode->next = newNode;
				newNode->prev = newNode;
				head = newNode;
			} else {
				newNode->next = head;
				newNode->prev = head->prev;
				head->prev->next = newNode;
				head->prev = newNode;
				head = newNode;
			}
			cout << val << " inserted at beginning.\n";
		}

		void insertAtEnd(int val) {
			Node *newNode = new Node(val);
			if (!head) {
				newNode->next = newNode;
				newNode->prev = newNode;
				head = newNode;
			} else {
				newNode->next = head;
				newNode->prev = head->prev;
				head->prev->next = newNode;
				head->prev = newNode;
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
			newNode->prev = temp;
			temp->next->prev = newNode;
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
			head->prev->next = head->next;
			head->next->prev = head->prev;
			head = head->next;
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

			Node *temp = head->prev;
			temp->prev->next = head;
			head->prev = temp->prev;
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
			for (int i = 0; i < pos; i++) {
				temp = temp->next;
				if (temp == head) {
					cout << "Position out of range!\n";
					return;
				}
			}

			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			cout << temp->data << " deleted from position " << pos << ".\n";
			delete temp;
		}

		void displayForward() {
			if (!head) {
				cout << "List is empty!\n";
				return;
			}

			Node *temp = head;
			cout << "Circular Doubly Linked List (Forward): ";
			do {
				cout << temp->data << " <-> ";
				temp = temp->next;
			} while (temp != head);
			cout << "(head)\n";
		}

		void displayBackward() {
			if (!head) {
				cout << "List is empty!\n";
				return;
			}

			Node *temp = head->prev;
			cout << "Circular Doubly Linked List (Backward): ";
			do {
				cout << temp->data << " <-> ";
				temp = temp->prev;
			} while (temp != head->prev);
			cout << "(tail)\n";
		}
};

int main() {
	CircularDoublyLinkedList cdll;
	int choice, value, position;

	do {
		cout << "\nCircular Doubly Linked List Operations\n";
		cout << "1. Insert at beginning\n";
		cout << "2. Insert at end\n";
		cout << "3. Insert at position\n";
		cout << "4. Delete from beginning\n";
		cout << "5. Delete from end\n";
		cout << "6. Delete from position\n";
		cout << "7. Display forward\n";
		cout << "8. Display backward\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter value to insert: ";
				cin >> value;
				cdll.insertAtBeginning(value);
				break;
			case 2:
				cout << "Enter value to insert: ";
				cin >> value;
				cdll.insertAtEnd(value);
				break;
			case 3:
				cout << "Enter value to insert: ";
				cin >> value;
				cout << "Enter position: ";
				cin >> position;
				cdll.insertAtPosition(value, position);
				break;
			case 4:
				cdll.deleteFromBeginning();
				break;
			case 5:
				cdll.deleteFromEnd();
				break;
			case 6:
				cout << "Enter position: ";
				cin >> position;
				cdll.deleteFromPosition(position);
				break;
			case 7:
				cdll.displayForward();
				break;
			case 8:
				cdll.displayBackward();
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