#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////

struct CBinNode
{
    CBinNode(int _v)
    {
        value = _v; nodes[0] = nodes[1] = 0;
    }
    int value;
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
    void InOrder(CBinNode* n);
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
    if (Find(x, p)) {
        CBinNode** q = p;
        q = &(*q)->nodes[1];
        while ((*q) != NULL) {
            for (; *q && (*q)->value != x;
                q = &((*q)->nodes[(*q)->value < x]));
            if (*q && (*q)->value == x) {
                q = &(*q)->nodes[1];
            }
        }
        *q = new CBinNode(x);
        return 0;
    }
    *p = new CBinNode(x);
    return 0;
}
bool CBinTree::Remove(int x)
{
    CBinNode** p;
    if (!Find(x, p)) return 0;
    CBinNode** w = p;
    while (Find(x, w)) {
        if ((*w)->nodes[0] && (*w)->nodes[1]) {
            CBinNode** q = Rep(w);
            (*w)->value = (*q)->value;
            w = q;
        }
        CBinNode* t = *w;
        *w = (*w)->nodes[(*w)->nodes[0] == 0];
        delete t;
        w = &(*p);
    }
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

void CBinTree::Print()
{
    InOrder(m_root);
    cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    CBinTree t;

    t.Insert(30); t.Insert(20); t.Insert(40);
    t.Insert(15); t.Insert(25); t.Insert(35);
    t.Insert(50); t.Insert(40);
    t.Insert(42);
    t.Insert(40); t.Insert(47); t.Insert(30);
    t.Insert(20); t.Insert(21); t.Insert(22);
    t.Insert(20);
    t.Print();
    cout << "---\n";
    t.Remove(47); t.Print();
    t.Remove(40); t.Print();
    t.Remove(15); t.Print();
    t.Remove(20); t.Print();
    t.Remove(25); t.Print();
    t.Remove(30); t.Print();
}
