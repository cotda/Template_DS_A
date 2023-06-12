#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* pNext;
};

struct List {
	Node* pHead;
	Node* pTail;
};

Node* makeNode( int& data) {
	Node* temp = new Node;
	temp->data = data;
	temp->pNext = NULL;
	return temp;
}

void InitList(List& lst) {
	lst.pHead = NULL;
	lst.pTail = NULL;
}

void insertFirst(List& lst,int& data) {
	Node* temp = makeNode(data);
	if (lst.pHead == NULL) {
		lst.pHead = temp;
		lst.pTail = temp;
	}
	else {
		temp->pNext = lst.pHead;
		lst.pHead = temp;
	}
}

void insertLast(List& lst, int& data) {
	Node* temp = makeNode(data);
	if (lst.pHead == NULL) {
		lst.pHead = temp;
		lst.pTail = temp;
	}
	else {
		lst.pTail->pNext = temp;
		lst.pTail = temp;
	}
}

int size(List lst) {
	int cnt = 0;
	while (lst.pHead != NULL) {
		++cnt;
		lst.pHead = lst.pHead->pNext;
	}
	return cnt;
}

void print(List lst) {
	if (lst.pHead == NULL) {
		cout << "NULL";
	}
	while (lst.pHead != NULL) {
		cout << lst.pHead->data<<" ";
		lst.pHead = lst.pHead->pNext;
	}
}

int main() {
	int n;
	cin >> n;
	List lst;
	InitList(lst);
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		insertFirst(lst, data);
	}
	print(lst);
	return 0;
}
