#include <iostream>
using namespace std;

template<class T>
struct CNode
{
    CNode(T x)
    {
        value = x; next = 0;
    }
    T value;
    CNode<T>* next;
};

template<class T>
class CList
{
public:
    CList();
    ~CList();
    void push_front(T x);
    void print();
    void Merge(CNode<T>* h1, CNode<T>* h2);
    CNode<T>* head;
};

template<class T>
CList<T>::CList()
{
    head = 0;
}

template<class T>
CList<T>::~CList()
{}

template<class T>
void CList<T>::push_front(T x)
{
    CNode<T>* t = new CNode<T>(x);
    t->next = head;
    head = t;
}

template<class T>
void CList<T>::Merge(CNode<T>* h1, CNode<T>* h2)
{
    CNode<T>* p = h1,* q = h1,* tmp = NULL,* tmpOne = NULL,*tmpTree = NULL;
    int cont = 1;
    while (cont != 0 || q->next){
        if (!q->next) {
            cont = 0;
            p = head;
            q = p;
        };
        if (q->next->value < p->value) {
            tmp->next = q->next;
            tmpTree = q->next;
            tmpTree = tmpTree->next;
            tmp = tmp->next;
            if (p->next->value == q->next->value) {
                tmp->next = tmpOne;
            }else {
                tmp->next = tmpOne->next;
            }
            q->next = tmpOne;
            tmpOne->next = tmpTree;
            p = tmp->next;
            tmpOne = tmp->next;
            q = p;
            cont++;
            continue;
        }
        q = q->next;
        if (!q->next) {
            tmp = p;
            p = p->next;
            tmpOne = p;
            q = p;
        }
    }
}

template<class T>
void CList<T>::print()
{
    CNode<T>* p;
    for (p = head; p; p = p->next)
        std::cout << p->value << "[" << p << "]\n";
    std::cout << "-----\n";
}

int main()
{
    CList<int> l;
    CNode<int>* h1, * h2;
    l.push_front(8);
    l.push_front(6);
    l.push_front(4);
    l.push_front(2);
    h2 = l.head;
    l.push_front(7);
    l.push_front(5);
    l.push_front(3);
    l.push_front(1);
    h1 = l.head;
    l.print();
    l.Merge(h1, h2);
    l.print();
}

