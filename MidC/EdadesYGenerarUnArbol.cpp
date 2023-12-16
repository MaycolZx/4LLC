#include<iostream>
#include<vector>
#include<stack>
#include<math.h>
using namespace std;

struct NodoBin{
	NodoBin* nodes[2];
	int valor;
	NodoBin(int v) {
		valor = v; nodes[0] = nodes[1] = NULL;
	}
};

class CBinTree {
private:
	vector<int>nodes;
	int* arr; int tamano; int niveles = 1;
public:
	NodoBin* m_root;
	CBinTree(int* arrgL, int tamanogL) {
		arr = arrgL;
		tamano = tamanogL;
		m_root = 0;
	}
	void suma();
	void InOrder(NodoBin* n);
	void creaTree(NodoBin* n);
	void printArbol();
};

void CBinTree::suma() {
	int seg = tamano;
	for (int* p = arr; p < arr + tamano; p++) {
		nodes.push_back(*p);
	}
	while (seg !=1) {
		seg /= 2;
		tamano+= seg;
		niveles++;
	}
	tamano--;
	for (int p = 0; p < tamano; p = p + 2) {
		int suma = nodes[p] + nodes[p + 1];
		nodes.push_back(suma);
	}
}
//20,13,16,18,21,8,25,17,33,34,29,42,67,71,138
void CBinTree::creaTree(NodoBin* n){
	int lv = 0;
	vector<NodoBin*> pos,tmp;
	m_root = new NodoBin(nodes[tamano --]);
	pos.push_back(m_root);
	//NodoBin* op = m_root;//1,2,4,8,16,32//2-0,2-1,2-2,2-3,2-4
	while (lv != niveles-1) {
		for (int i = 0; i < pow(2,lv); i++) {
			pos[i]->nodes[1] = new NodoBin(nodes[tamano--]);
			tmp.push_back(pos[i]->nodes[1]);
			pos[i]->nodes[0] = new NodoBin(nodes[tamano--]);
			tmp.push_back(pos[i]->nodes[0]);
		}
		pos.clear();
		pos = tmp;
		tmp.clear();
		lv++;
	}
}

void CBinTree::InOrder(NodoBin *n) {
	if (!n) return;
	InOrder(n->nodes[0]);
	cout << n->valor << " ";
	InOrder(n->nodes[1]);
};
void CBinTree::printArbol() {
	suma();
	creaTree(m_root);
	cout << "Imprimiendo el arbol " << endl;
	InOrder(m_root);
};
int main() {
	int arr[8] = { 20,13,16,18,21,8,25,17 };
	int tamano = sizeof(arr) / sizeof(arr[0]);
	CBinTree x(arr,tamano);
	x.printArbol();
	return 0;
}
