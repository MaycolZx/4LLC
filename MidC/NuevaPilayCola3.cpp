#include <iostream>
using namespace std;

template<class T>
struct Nodo{
	Nodo* next;
	T valor;
	Nodo(T v, Nodo* n = NULL) {
		valor = v;
		next = n;
	}
};

template<class T>
class Pila {
private:
public:
	Nodo<T>* head = NULL;
	Pila() {}
	void push_back(T valor);
	T pop();
	void prinT();
};
template<class T>
void Pila<T>::push_back(T valor) {
	head = new Nodo<T>(valor, head);
}
template<class T>
T Pila<T>::pop() {
	Nodo<T>* tmp = head;
	head = head->next;
	T val = head->valor;
	delete tmp;
	return val;
}
template<class T>
void Pila<T>::prinT() {
	cout << "Top -> ";
	for (Nodo<T> *p  = head; p ; p = p->next){
		cout << p->valor<<" ";
	}
	cout<< " <-Fin" << endl;
}

template<class T>
class Cola{
private:
public:
	Nodo<T>* head = NULL;
	Nodo<T>* q = head;
	Cola();
	void push_back(T valor);
	void push_front(T valor);
	T pop();
	void prinT();
	~Cola();
};
template<class T>
void Cola<T>::push_back(T valor) {
	if (head == NULL) {
		head = new Nodo<T>(valor,NULL);
		q = head;
	}else {
		q->next = new Nodo<T>(valor,NULL);
		q = q->next;
	}
}
template<class T>
void Cola<T>::push_front(T valor) {
	head = new Nodo<T>(valor, head);
}
template<class T>
T Cola<T>::pop() {
	Nodo<T>* tmp = head;
	T val = head->valor;
	head = head->next;
	delete tmp;
	return val;
}
template<class T>
void Cola<T>::prinT() {
	cout << "Head-> ";
	for (Nodo<T>* p = head; p ; p = p->next){
		cout << p->valor << " ";
	}
	cout <<" <-Top" << endl;
}

template<class T>
Cola<T>::Cola(){}
template<class T>
Cola<T>::~Cola(){}

int main() {
	//Pila
	cout << "Pila" << endl;
	Pila<int> x;
	for (int i = 0; i < 10; i++){
		x.push_back(i);
	}
	x.prinT();
	for (int i = 0; i < 5; i++){
		x.pop();
	}
	x.prinT();
	//Cola
	cout << "Cola" << endl;
	Cola<int> y;
	for (int i = 0; i < 10; i++) {
		y.push_back(i);
	}
	y.prinT();
	y.push_front(20);
	y.prinT();
	for (int i = 0; i < 5; i++) {
		y.pop();
	}
	y.prinT();
	y.push_front(15);
	y.prinT();
	return 0;
}