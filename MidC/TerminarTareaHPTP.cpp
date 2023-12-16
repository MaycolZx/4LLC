#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////

struct CBinNode
{
    CBinNode(int _v)
    {
        value = _v; nodes[0] = nodes[1] = 0; state = 0;secState = 0;
    }
    int value;
    CBinNode* nodes[2];
    int state;
    bool secState;
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
    int contA = 0, avanz = 0;
    bool Find(int x, CBinNode**& p);
    CBinNode** Rep(CBinNode** p);
    void InOrder(CBinNode* n);
    void Primos(CBinNode* n);
    void PrimosOne(CBinNode* n, int valor);
    void PrimosTwo(CBinNode* n, int valor);
    CBinNode* m_root;
    bool m_b;
};

CBinTree::CBinTree()
{
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

void CBinTree::InOrder(CBinNode* n)
{
    if (!n) return;
    InOrder(n->nodes[0]);
    cout << n->value << " ";
    InOrder(n->nodes[1]);
}

void Hijos(CBinNode* n) {
    if (!n) return;
    if (n->nodes[0] && n->nodes[1]) {
        cout << n->value << " -> (" << n->nodes[0]->value << "," << n->nodes[1]->value << ")"<<endl;
    }
    if (n->nodes[0] && !n->nodes[1]) {
        cout << n->value << " -> (" << n->nodes[0]->value << ", )" << endl;;
    }
    if (!n->nodes[0] && n->nodes[1]) {
        cout << n->value << " -> (" << n->nodes[1]->value << ", )" << endl;;
    }
    Hijos(n->nodes[0]);
    Hijos(n->nodes[1]);
}

void Hermanos(CBinNode* n) {
    if (!n) return;
    if (n->nodes[0] && n->nodes[1]) {
        cout <<"(" << n->nodes[0]->value << "," << n->nodes[1]->value << ")" << endl;
    }
    Hermanos(n->nodes[0]);
    Hermanos(n->nodes[1]);
}

void CBinTree::Primos(CBinNode *n) {
    if (!n) return;
    /*if (n->nodes[0] && n->nodes[1]) {
        contA++;
    }*/
    if (n->nodes[0] && n->nodes[1]) {
        contA++;
        n->nodes[0]->state += contA;
        n->nodes[1]->state += contA;
    }
    Primos(n->nodes[0]);
    if (n == m_root) {
        contA = 1;
    }
    Primos(n->nodes[1]);
}

void CBinTree::PrimosOne(CBinNode* n,int valor) {
    if (!n)return;
    if (n->state == valor && avanz > 0) {
        cout <<n->value<<",";
    }
    if (n->nodes[0] && n->nodes[0]->state == valor && avanz == NULL && n->nodes[0]->secState == 0) {
        cout << n->nodes[0]->value << " -> (";
        avanz++;
        n->nodes[0]->secState = 1;
        return;
    }
    if (n->nodes[1] && n->nodes[1]->state == valor && avanz == NULL && n->nodes[1]->secState == 0) {
        cout << n->nodes[1]->value << " -> (";
        avanz++;
        n->nodes[1]->secState = 1;
        return;
    }
    PrimosOne(n->nodes[0],valor);
    PrimosOne(n->nodes[1],valor);
}

void CBinTree::PrimosTwo(CBinNode* n, int valor) {
    if (!n)return;
    if (n->state == valor && avanz > 0) {
        cout << n->value << ",";
    }
    if (n->nodes[0] && n->nodes[0]->state == valor && avanz == NULL && n->nodes[0]->secState == 0) {
        cout << n->nodes[0]->value << " -> (";
        avanz++;
        n->nodes[0]->secState = 1;
        return;
    }
    if (n->nodes[1] && n->nodes[1]->state == valor && avanz == NULL && n->nodes[1]->secState == 0) {
        cout << n->nodes[1]->value << " -> (";
        avanz++;
        n->nodes[1]->secState = 1;
        return;
    }
    PrimosOne(n->nodes[1], valor);
    PrimosOne(n->nodes[0], valor);
}

int L(CBinNode* n) {
    if (!n) return 0;
    int l = L(n->nodes[0]);
    int r = L(n->nodes[1]);
    return max(l, r) + 1;
}

void CBinTree::Print()
{
    cout << "La profundidad: " << L(m_root) << endl;
    InOrder(m_root);
    cout << endl<<"Hijos:"<<endl;
    Hijos(m_root);
    cout << endl<<"Hermanos"<<endl;
    Hermanos(m_root);
    cout << endl << "Primos" << endl;
    Primos(m_root->nodes[0]);
    contA = 0;
    Primos(m_root->nodes[1]);
    int j = 1;
    for (int i = 1; i < 3; i++){
        PrimosOne(m_root,j);
        avanz = NULL;
        cout <<")" << endl;
    }
    for (int i = 1; i < 3; i++) {
        PrimosTwo(m_root, j);
        avanz = NULL;
        cout << ")" << endl;
    }
    cout << endl << "Tio" << endl;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    CBinTree t;
    t.Insert(8); t.Insert(3); t.Insert(10); t.Insert(1); t.Insert(5); t.Insert(9); t.Insert(11); t.Insert(12);
    t.Print();

    //////////////////////////////////////////////////////////////
    //t.Insert(30); t.Insert(20); t.Insert(40);
    //t.Insert(15); t.Insert(25); t.Insert(35);
    //t.Insert(50); t.Insert(40); t.Insert(42);
    //t.Insert(40); t.Insert(47); t.Insert(30);
    //t.Insert(20); t.Insert(21); t.Insert(22);
    //t.Insert(20);
    //t.Print();
    //cout << "---\n";
    //t.Remove(47); t.Print();
    //t.Remove(40); t.Print();
    //t.Remove(15); t.Print();
    //t.Remove(20); t.Print();
    //t.Remove(25); t.Print();
    //t.Remove(30); t.Print();
}
