#include <iostream>
using namespace std;

template<class T>
class nodo{
    public:
    T valor;
    nodo * next;nodo *prev;
    nodo(T v,nodo *n = NULL,nodo *p = NULL)
    {valor =v;next =n; prev = p;}
};

int main(){
    nodo <int> *head = new nodo <int>(5);//Creamos un nuevo nodo con el "valor" de 5 y direccion de memoria en "next" y "prev" igual a nulo
    //NEXT: Head->nodo(5)
    // PREV: NULL
    head = new nodo <int> (3,head);//Head sera igual a un nuevo nodo con el "valor" de 3 que en next apuntara al "head"
    //NEXT: Head->nodo(3)->nodo(5)
    //PREV: NULL
    head ->next -> prev =head;//La direccion de memoria del "prev" con el valor de "5" apunta al "head"
    //NEXT: Head-nodo(3)->nodo(5)
    //PREV: Head<-nodo(5)
    head ->next =new nodo <int> (4,head ->next);
    //NEXT: Head->nodo(3)->nodo(4)->nodo(5)
    //PREV: Head<-nodo(5)
    head -> next ->next ->prev=head->next;
    //NEXT: Head->nodo(3)->nodo(4)->nodo(5)
    //PREV: Head<-nodo(4)<-nodo(5)
    head -> next -> prev = head;
    //NEXT: Head->nodo(3)->nodo(4)->nodo(5)
    //PREV: Head<-head(3)<-nodo(4)<-nodo(5)
    cout << head ->next ->valor <<endl;//Imprimimos el valor del nodo(4) que es 4.
    return 0;
}