#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//Estructura nodo
template <class T>
struct nodo {
    T valor;
    nodo* next;
    nodo(T v, nodo* n = NULL) {
        valor = v;
        next = n;
    }
};
//El ultimo en entrar es el ultimo en salir
template<class T>
class Pila {
private:
    nodo<T>* top = NULL;
public:
    Pila() {};
    void push(T v);
    T pop();
    void prinT();
    ~Pila() {};
};
template<class T>
void Pila<T>::push(T v) {
    top = new nodo<T>(v, top);
}
template<class T>
T Pila<T>::pop() {
    nodo<T>* tmp = top;
    if (top == NULL) {
        return 0;
    }
    T valorR = top->valor;
    top = top->next;
    delete tmp;
    return valorR;
}
template<class T>
void Pila<T>::prinT() {
    cout << "Top-> ";
    for (nodo<T>* p = top; p != NULL; p = p->next) {
        cout << p->valor << " ";
    }
    cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

struct CBinNode
{
    CBinNode(int _v)
    {
        value = _v; nodes[0] = nodes[1] = 0; state = 0;
    }
    int value,state;
    CBinNode* nodes[2];
};

////////////////////////////////////////////////////////////////////////////////////////////////////////

class CBinTree
{
public:
    CBinTree();
    ~CBinTree();
    bool Insert(int x);
    bool Remove(int x);
    void Print();
private:
    bool Find(int x, CBinNode**& p);
    CBinNode** Rep(CBinNode** p);
    void InOrder(CBinNode* n);//InOrder
    void PostOrder(CBinNode* n);//PostOrder
    void PreOrder(CBinNode* n);//PreOrder
    void Reverse(CBinNode* n);//Reverse
    void ContProf(CBinNode* n);
    void printNivel(CBinNode* n, int nivel, int distProm);
    void PrintArbol();
    void NivelOne(CBinNode* n, int nivel);
    void NivelTwo(CBinNode* n);
    void Clear(CBinNode* n);
    void InOrderMyStack(CBinNode* n);//My InOrder
    void PostOrderMyStack(CBinNode* n);//My PostOrder
    void PreOrderMyStack(CBinNode *n);//My PreOrder
    int Prof = NULL, nMval = NULL, nivelAvC = NULL;
    vector<int> ramas;
    CBinNode* m_root;
    bool m_b;
};

CBinTree::CBinTree(){
    m_root = 0;
    m_b = 0;
}

CBinTree::~CBinTree()
{
    // ?
}

bool CBinTree::Find(int x, CBinNode**& p)
{
    for (p = &m_root;
        *p && (*p)->value != x;
        p = &((*p)->nodes[(*p)->value < x]));
    return *p && (*p)->value == x;
}

bool CBinTree::Insert(int x)
{
    CBinNode** p;
    if (Find(x, p)) return 0;
    *p = new CBinNode(x);
    return 0;
}
bool CBinTree::Remove(int x)
{
    CBinNode** p;
    if (!Find(x, p)) return 0;
    if ((*p)->nodes[0] && (*p)->nodes[1])
    {
        CBinNode** q = Rep(p);
        (*p)->value = (*q)->value;
        p = q;
    }
    CBinNode* t = *p;
    *p = (*p)->nodes[(*p)->nodes[0] == 0];
    delete t;
    return 1;
}

CBinNode** CBinTree::Rep(CBinNode** q)
{
    m_b = !m_b;
    q = &((*q)->nodes[!m_b]);
    while ((*q)->nodes[m_b])
        q = &((*q)->nodes[m_b]);
    return q;
}

void CBinTree::Clear(CBinNode* n) {
    if (!n) return;
    Clear(n->nodes[0]);
    n->state = 0;
    Clear(n->nodes[1]);
}

void CBinTree::InOrder(CBinNode* n)
{
    if (!n) return;
    InOrder(n->nodes[0]);
    cout << n->value << " ";
    InOrder(n->nodes[1]);
}
void CBinTree::InOrderMyStack(CBinNode *n) {
    Pila<CBinNode *> lB;
    CBinNode* mov = n;
    while (mov) {
        if (mov->state == 0) {
            mov->state = 1;
            lB.push(mov);
            mov = mov->nodes[0];
        }
        if (!mov) {
            mov = lB.pop();
        }
        if (mov) {
            if (mov->state == 1) {
                mov->state = 2;
                cout << mov->value << " ";
            }
            if (mov->state == 2) {
                mov->state = 3;
                mov = mov->nodes[1];
            }
        }
        if (!mov) {
            mov = lB.pop();
        }
    }
}

void CBinTree::PostOrder(CBinNode* n)
{
    if (!n) return;
    PostOrder(n->nodes[0]);
    PostOrder(n->nodes[1]);
    cout << n->value << " ";
}
void CBinTree::PostOrderMyStack(CBinNode* n) {
    Pila<CBinNode*> lB;
    CBinNode* mov = n;
    while (mov) {
        if (mov->state == 0) {
            mov->state = 1;
            lB.push(mov);
            mov = mov->nodes[0];
        }
        if (!mov) {
            mov = lB.pop();
        }
        if (mov) {
            if (mov->state == 3) {
                cout << mov->value << " ";
                mov = lB.pop();
            }
        }
        if (mov) {
            if (mov->state == 1)mov->state = 2;
            if (mov->state == 2) {
                mov->state = 3;
                lB.push(mov);
                mov = mov->nodes[1];
            }
        }
        if (!mov) {
            mov = lB.pop();
        }
    }
}

void CBinTree::PreOrder(CBinNode* n)
{
    if (!n) return;
    cout << n->value << " ";
    PreOrder(n->nodes[0]);
    PreOrder(n->nodes[1]);
}
void CBinTree::PreOrderMyStack(CBinNode* n) {
    Pila<CBinNode*> lB;
    CBinNode* mov = n;
    while (mov) {
        if (mov->state == 0) {
            cout << mov->value << " ";
            mov->state = 1;
            lB.push(mov);
            mov = mov->nodes[0];
        }
        if (!mov) {
            mov = lB.pop();
        }
        if (mov) {
            if (mov->state == 1) {
                mov->state = 2;
            }
            if (mov->state == 2) {
                mov->state = 3;
                mov = mov->nodes[1];
            }
        }
        if (!mov) {
            mov = lB.pop();
        }
    }
}

void CBinTree::Reverse(CBinNode* n) {
    if (!n) return;
    Reverse(n->nodes[1]);
    cout << n->value << " ";
    Reverse(n->nodes[0]);
}

int numDigit(int val) {
    int multi = 1, resultado = NULL;
    while (val >= 10 * multi) {
        resultado++;
        multi *= 10;
    }
    return resultado;
}
void CBinTree::ContProf(CBinNode* n) 
{
    if (!n) return;
    if (n->state == 0) {
        Prof++;
    }
    n->state = 1;
    ContProf(n->nodes[0]);
    if (n->state == 1 && !n->nodes[0] && !n->nodes[1]) {
        if (Prof > nMval) {
            nMval = Prof;
        }
    }
    if (n->state == 1 && n == m_root) {
        Prof = 0;
    }
    n->state = 2;
    n->state = 3;
    ContProf(n->nodes[1]);
    if (n->state == 3 || n == m_root) {
        Prof--;
    }
}
void CBinTree::printNivel(CBinNode* n, int nivel, int distProm) {
    if (!n || nivelAvC == nivel) return;
    nivelAvC++;
    if (n && nivelAvC == nivel) {
        ramas.push_back(1);
    }
    printNivel(n->nodes[0], nivel, distProm);
    if ((!n->nodes[0] || !n->nodes[1]) && (nivel - nivelAvC) >= 1 && nivelAvC != nivel) {
        if (!n->nodes[0] && !n->nodes[1]) {
            for (int i = 0; i < (nivel - nivelAvC) * 2; i++) {
                for (int j = 1; j < distProm; j++) {
                    cout << " ";
                }
                cout << " ";
                for (int j = 1; j < distProm; j++) {
                    cout << " ";
                }
                cout << " ";
                ramas.push_back(0);
            }
        }
        else {
            for (int i = 0; i < pow(2, (nivel - nivelAvC - 1)); i++) {
                for (int j = 1; j < distProm; j++) {
                    cout << " ";
                }
                cout << " ";
                for (int j = 1; j < distProm; j++) {
                    cout << " ";
                }
                cout << " ";
                ramas.push_back(0);
            }
        }

    }
    if (nivelAvC == nivel) {
        for (int i = 1; i < distProm; i++) {
            cout << " ";
        }
        cout << n->value << " ";
        for (int i = 1; i < distProm - 1; i++) {
            cout << " ";
        }
    }
    printNivel(n->nodes[1], nivel, distProm);
    nivelAvC--;
}
void CBinTree::PrintArbol() {
    CBinNode** p = &m_root;
    CBinNode* prov = m_root;
    int contador = NULL;
    ContProf(m_root);
    cout << "Prof " << nMval << endl;
    int maxDist = NULL;
    for (int i = 0; i < nMval; i++) {
        maxDist = pow(2, i);
    }
    //Haber
    int hast = maxDist / 2;
    for (int i = 1; i <= nMval; i++) {//avanzara 5 niveles
        printNivel(m_root, i, maxDist);//imprimira la fila de numeros por nivel
        cout << endl;
        for (int j = 0; j < hast; j++) {//es un bucle que avanzara tomando en cuenta la altura
            for (int l = 0; l < ramas.size(); l++) {//un bucle que tomara el tamano del array actualmente tomado
                if (ramas[l] == 1) {
                    for (int k = 1; k < maxDist + j; k++) {
                        if (k == maxDist - 1 - j)cout << "/";
                        cout << " ";
                    }cout << "\\";
                    for (int k = 1; k < maxDist - 1 - j; k++) {
                        cout << " ";
                    }
                    cout << " ";
                }
                else {
                    for (int k = 0; k < maxDist + numDigit(30) + j; k++) {
                        cout << " ";
                    }
                    for (int k = 0; k < maxDist - numDigit(30) - j; k++) {
                        cout << " ";
                    }
                }
            }cout << endl;
        }
        ramas.clear();
        hast /= 2;
        maxDist /= 2;
    }
    cout << endl;
}


void CBinTree::NivelOne(CBinNode* n, int nivel) {
    if (!n || nivelAvC == nivel) return;
    nivelAvC++;
    NivelOne(n->nodes[0], nivel);
    if (nivelAvC == nivel) {
        cout << n->value << " ";
    }
    NivelOne(n->nodes[1], nivel);
    nivelAvC--;
}
void CBinTree::NivelTwo(CBinNode* n) {}

void CBinTree::Print()
{
    cout << "InOrder: " << endl;
    InOrder(m_root);
    cout << endl;
    InOrderMyStack(m_root);
    Clear(m_root);
    cout << endl << "PostOrder: " << endl;
    PostOrder(m_root);
    cout << endl;
    PostOrderMyStack(m_root);
    Clear(m_root);
    cout << endl << "PreOrder: " << endl;
    PreOrder(m_root);
    cout << endl;
    PreOrderMyStack(m_root);
    Clear(m_root);
    cout << endl << "Reverse: " << endl;
    Reverse(m_root);
    Clear(m_root);

    cout << endl << "Imprimimos por nivel(One)" << endl;
    ContProf(m_root);
    for (int i = 1; i <= nMval; i++) {
        NivelOne(m_root, i);
    }
    Clear(m_root);
    cout << endl << "Imprimimos por nivel(Two)" << endl;
    cout << endl << "Imprimimos el Arbol ASCCI" << endl;
    PrintArbol();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    CBinTree t;
    //Ejemplo de examen
    t.Insert(30); t.Insert(20); t.Insert(40);
    t.Insert(15); t.Insert(25); t.Insert(35);
    t.Insert(50); t.Insert(40); t.Insert(42);
    t.Insert(40); t.Insert(47); t.Insert(30);
    t.Insert(20); t.Insert(21); t.Insert(22);
    t.Insert(20);
    //Mi ejemplo
    /*t.Insert(25); 
    t.Insert(15); t.Insert(10); t.Insert(22); t.Insert(4); t.Insert(12); t.Insert(18); t.Insert(24);
    t.Insert(50); t.Insert(35); t.Insert(31); t.Insert(44); t.Insert(70); t.Insert(66); t.Insert(90);*/

    t.Print();
    cout << "---\n";
    //t.Remove(47); t.Print();
    //t.Remove(40); t.Print();
    //t.Remove(15); t.Print();
    //t.Remove(20); t.Print();
    //t.Remove(25); t.Print();
    //t.Remove(30); t.Print();
}
