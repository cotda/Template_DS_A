#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int data;
	Node* pNext;
};

void InitHash(vector<Node*>& hash, int& size) {
	for (int i = 0; i < size; i++) {
		hash[i] = NULL;
	}
}

Node* makeNode(int& value) {
	Node* temp = new Node;
	temp->data = value;
	temp->pNext = NULL;
	return temp;
}

int hashFunc(int& value,int& size) {
	return value % size;
}
 
void insertNode(vector<Node*>& hash, int& size,int &value) {
	int key = hashFunc(value, size);
	Node* temp = hash[key];
	Node* prev = NULL;
	while (temp != NULL && temp->data < value) {
		prev = temp;
		temp = temp->pNext;
	}
	Node* p = makeNode(value);
	if (prev == NULL) {
		hash[key] = p;
		p->pNext = temp;
	}
	else if (temp == NULL) {
		prev->pNext = p;
	}
	else {
		p->pNext = temp;
		prev->pNext = p;
	}
}

void print(vector<Node*> hash, int& n) {
	for (int i = 0; i < n; i++) {
		if (hash[i] != NULL) {
			cout << "----- Bucket " << i << " ------"<<endl;
			Node* temp = hash[i];
			while (temp != NULL) {
				cout << temp->data << "    ";
				temp = temp->pNext;
			}
			cout << endl;
		}
	}
}

Node* search(vector<Node*> hash, int& value) {
	int size = hash.size();
	int key = hashFunc(value,size);
	Node* temp = hash[key];
	while (temp != NULL && temp->data != value) {
		temp = temp->pNext;
	}
	return temp;
}

int main() {
	int n;
	cin >> n;
	vector<Node*>hash(n);
	InitHash(hash, n);
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		insertNode(hash, n, value);
	}
	print(hash, n);
	int value; 
	cin >> value;
	if (search(hash, value) == NULL) {
		cout << "Not find value: " << value;
	}
	else {
		cout << "Find value: " << value;
	}
	return 0;
}
