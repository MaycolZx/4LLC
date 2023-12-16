#include <iostream>
#include <vector>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////

struct CBinNode
{
    CBinNode(int _v)
    {
        value = _v; nodes[0] = nodes[1] = 0; state = 0; secState = 0;
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

    int nivelAvC = NULL;
    vector<int> nivelAll, hermanos;
    void PrintArbol();
    void printNivel(CBinNode* n, int nivel);

    vector<int> mTio;
    void uncle(CBinNode* n,int nOl);
    void Tios();
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
        cout << n->value << " -> (" << n->nodes[0]->value << "," << n->nodes[1]->value << ")" << endl;
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
        cout << "(" << n->nodes[0]->value << "," << n->nodes[1]->value << ")" << endl;
    }
    Hermanos(n->nodes[0]);
    Hermanos(n->nodes[1]);
}

int L(CBinNode* n) {
    if (!n) return 0;
    int l = L(n->nodes[0]);
    int r = L(n->nodes[1]);
    return max(l, r) + 1;
}

void CBinTree::printNivel(CBinNode* n, int nivel) {
    if (!n || nivelAvC == nivel) return;
    nivelAvC++;
    if ((n->nodes[0] || n->nodes[1]) && nivelAvC + 1 == nivel) {
        if (n->nodes[0] && n->nodes[1]) {
            hermanos.push_back(n->nodes[0]->value);
            hermanos.push_back(n->nodes[1]->value);
        }
        if (n->nodes[0] && !n->nodes[1]) {
            hermanos.push_back(n->nodes[0]->value);
            hermanos.push_back(0);
        }
        if (!n->nodes[0] && n->nodes[1]) {
            hermanos.push_back(0);
            hermanos.push_back(n->nodes[1]->value);
        }
    }
    printNivel(n->nodes[0], nivel);
    if (nivelAvC == nivel) {
        nivelAll.push_back(n->value);
    }
    printNivel(n->nodes[1], nivel);
    nivelAvC--;
}

void CBinTree::PrintArbol() {
    int a = 2;
    while (a != L(m_root)){
        a++;
        printNivel(m_root, a);
        int index = 0;
        for (int i = 0; i < nivelAll.size(); i++) {
            if (nivelAll.size() > 1) {
                cout << nivelAll[i] << "->(";
            }else {
                break;
            }
            for (int j = 0; j < nivelAll.size(); j++) {
                if (nivelAll[j] != hermanos[index] && nivelAll[j] != hermanos[index+1]) {
                    cout << "-" << nivelAll[j] << "-";
                }
            }
            if (i%2 != 0) {
                index +=2;
            }
            cout << ")" << endl;
        }
        nivelAll.clear();hermanos.clear();
    }
}

void CBinTree::uncle(CBinNode* n,int nOl) {
    if (!n || nivelAvC == nOl) return;
    nivelAvC++;
    if ((n->nodes[0] || n->nodes[1]) && nivelAvC + 1 == nOl) {
        if (n->nodes[0] && n->nodes[1]) {
            mTio.push_back(n->nodes[0]->value);
            mTio.push_back(n->nodes[1]->value);
            mTio.push_back(n->value);
        }
        if (n->nodes[0] && !n->nodes[1]) {
            mTio.push_back(n->nodes[0]->value);
            mTio.push_back(0);
            mTio.push_back(n->value);
        }
        if (!n->nodes[0] && n->nodes[1]) {
            mTio.push_back(0);
            mTio.push_back(n->nodes[1]->value);
            mTio.push_back(n->value);
        }
    }
    uncle(n->nodes[0], nOl);
    uncle(n->nodes[1], nOl);
    nivelAvC--;
}
//      5
//  3       7
//1   4   6   8
void CBinTree::Tios() {
    int a = 1;
    while (a != L(m_root)-1) {
        a++;
        printNivel(m_root, a);
        uncle(m_root,a+1);
        int index = 0;
        for (int j = 0; j < mTio.size()-1; j++){
            if (mTio[j] == 0) {
                j++;
                index++;
            }
            cout << mTio[j] << "->( ";
            for (int i = 0; i < nivelAll.size(); i++) {
                if (mTio[j + 2 - index] != nivelAll[i]) {
                    cout << nivelAll[i] << " ";
                }
            }cout<<")"<< endl;
            index++;
            if (index == 2) {
                index = 0;
                j++;
            }
        }
        nivelAll.clear(); mTio.clear();
    }
}


void CBinTree::Print()
{
    cout << "La profundidad: " << L(m_root) << endl;
    InOrder(m_root);
    cout << endl << "Hijos:" << endl;
    Hijos(m_root);
    cout << endl << "Hermanos" << endl;
    Hermanos(m_root);
    cout << endl << "Primos" << endl;
    PrintArbol();
    cout << endl << "Tio" << endl;
    Tios();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    CBinTree t;
    t.Insert(8); t.Insert(3); t.Insert(10); t.Insert(1); t.Insert(5); t.Insert(9); t.Insert(11); t.Insert(12);
    t.Print();
    /*t.Insert(15); t.Insert(6); t.Insert(20); t.Insert(3); t.Insert(9); t.Insert(18); t.Insert(24); t.Insert(1);
    t.Insert(4); t.Insert(7); t.Insert(12); t.Insert(17);*/
    //t.Print();
    //      5
    //  3       7
    //1   4   6   8
    //t.Insert(5); t.Insert(3); t.Insert(1); t.Insert(4);  t.Insert(7); t.Insert(6); t.Insert(8);
    //t.Print();

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





