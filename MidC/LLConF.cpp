#include <iostream>
using namespace std;

struct Node{
	Node* next;
	int valor;
	Node(int v) {
		valor = v;
		next = 0;
	}
};

class CList {
private:
public:
	Node* head = NULL;
	CList() {};
	bool Find(int x, Node**& p);
	bool Insert(int x);
	bool Remove(int x);
	void Print();
};

bool CList::Find(int x, Node**& p) {
	p = &head;
	while (*p && (*p)->valor < x) {
		p = &(*p)->next;
	}
	return *p && (*p)->valor == x;
}
bool CList::Insert(int x) {
	Node** p;
	if (Find(x,p)){
		return 0;
	}
	Node* t;
	t = new Node(x);
	t->next = *p;
	*p = t;
	return 1;
}
bool CList::Remove(int x) {
	Node** p;
	if (Find(x, p)) {
		Node* tmp;
		tmp= *p;
		*p = tmp->next;
		delete tmp;
		return 1;
	}
	return 0;
}
void CList::Print() {
	cout << "HEAD -> ";
	for (Node* p = head; p; p = p->next) {
		cout << p->valor << " -> ";
	}cout<<"NULL"<< endl;
}

int main() {
	CList x;
	for (int i = 0; i < 10; i++){
		x.Insert(i);
	}
	x.Print();
	x.Insert(5);
	x.Print();
	x.Remove(5);
	x.Print();
	x.Remove(5);
	x.Print();
	x.Remove(1);
	x.Print();
	x.Remove(0);
	x.Print();
	x.Remove(9);
	x.Print();
	x.Remove(9);
	x.Print();
	x.Remove(9);
	x.Print();
	return 0;
}