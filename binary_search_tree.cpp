#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* pLeft;
	Node* pRight;
};

void InitTree(Node*& T) {
	T = NULL;
}

void makeTree(Node*& t, int& x) {
	if (t == NULL) {
		Node* p = new Node;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else {
		if (t->data > x) {
			makeTree(t->pLeft, x);
		}
		else if (t->data < x) {
			makeTree(t->pRight, x);
		}
	}
}

void nodeTemp(Node*& x,Node*& y) {
	if (y->pLeft != NULL) {
		nodeTemp(x, y->pLeft);
	}
	else {
		x->data = y->data;
		x = y;
		y = y->pRight;
	}
}

void deleteNode(Node*& tree, int data) {
	if (tree == NULL) {
		return;
	}
	else {
		if (data < tree->data) {
			deleteNode(tree->pLeft,data);
		}
		else if (data > tree->data) {
			deleteNode(tree->pRight, data);
		}
		else {
			Node* x = tree;
			if (tree->pLeft == NULL) {
				tree = tree->pRight;
			}
			else if (tree->pRight == NULL) {
				tree = tree->pLeft;
			}
			else {
				nodeTemp(x, tree->pRight);
			}
			delete x;
		}
	}
	
}

void printTree(Node*& t) {
	if (t != NULL) {
		cout << t->data << " ";
		printTree(t->pLeft);
		printTree(t->pRight);
	}

}
int main() {
	int n, x;
	cin >> n;
	Node* Tree = new Node;
	InitTree(Tree);
	for (int i = 0; i < n; i++) {
		cin >> x;
		makeTree(Tree, x);
	}

	printTree(Tree);
	int value;
	cin >> value;
	deleteNode(Tree, value);
	printTree(Tree);
	return 0;
}
