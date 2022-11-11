



#include <iostream>

using namespace std;

//snglylinkedlistin qalan methodlarini yazin

class Node {
public:
	string data;
	Node* next;

	Node(const string& data) {

		this->data = data;
		next = nullptr;
	}
};


class SingleList {
	Node* head = nullptr;

public:

	void addfront(const string& value) {
		Node* newnode = new Node(value);
		newnode->next = head;
		head = newnode;
	}

	void addend(const string& value) {
		Node* newNode = new Node(value);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node* temp = head;

		while (temp->next != nullptr)
		{
			temp = temp->next;
		}

		temp->next = newNode;
		temp = nullptr;
	}

	void deletefront() {
		if (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void deleteend() {
		if (head != nullptr) {
			Node* temp = head;



			while (temp->next->next != nullptr)
			{
				temp = temp->next;
			}

			delete temp->next;
			temp->next = nullptr;
		}
	}

	void print() {
		if (head != nullptr) {
			Node* temp = head;

			while (temp != nullptr)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	void addElementbefore(const string& x, const string& value) {
		Node* newNode = new Node(value);
		if (head != nullptr) {

			Node* temp = head;
			while (temp->next->data != x)
			{
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;

		}
	}


	void addElementafter(const string& x, const string& value) {
		Node* newNode = new Node(value);
		if (head != nullptr) {

			Node* temp = head;
			while (temp->data != x)
			{
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;

		}

	}

	void deletebyvalue(const string value) {
		if (head != nullptr) {
			Node* temp = head;
			while (temp->next->data != value)
			{
				temp = temp->next;
			}
			temp->next = temp->next->next;

		}
	}
};
int main() {
	SingleList sl;

	sl.addfront("3");
	sl.addfront("2");
	sl.addfront("1");
	sl.print();
	system("pause");
	sl.addElementbefore("2", "66");
	sl.print();
	system("pause");
	sl.addElementafter("2", "99");
	sl.print();
	sl.deletebyvalue("2");
	system("pause");
	sl.print();
}