#include <iostream>
#include <stack>
using namespace std;
class Stack {
private:
	struct Node {
		int data;
		Node* next;
	};
	Node* head;
public:
	Stack() {
		head = NULL;
	}
	void push(int x) {
		Node* curr = new Node;
		curr->data = x;
		curr->next = head;
		head = curr;
	}
	void pop() {
		Node* del = head;
		head = head->next;
		delete del;
	}
	int top() {
		return head->data;
	}
	bool empty() {
		if (head == NULL) return true;
		else return false;
	}
	int size() {
		int size = 0;
		Node* curr = head;
		while (curr != NULL) {
			size++;
			curr = curr->next;
		}
		return size;
	}
	~Stack() {
		Node* del = head;
		while (head != NULL) {
			head = head->next;
			delete del;
			del = head;
		}
	}
};
void main() {
	Stack a;
	a.push(0);
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	a.push(6);
	a.push(7);
	a.push(8);
	a.push(9);
	cout << "Size of stack: " << a.size() << endl;
	while (!a.empty()) {
		cout << a.top() << endl;
		a.pop();
	}
	cout << "Size of stack: " << a.size() << endl;
}
