#include <iostream>	
using namespace std;
	
template<class T>
struct nodo
{
  T value;
  nodo<T> *next;
  nodo(T v, nodo<T> *n=NULL)
  {
    value = v;
    next = n;
  }
};

void ArrayToLE(int *A, int elem, nodo<int> *&ini)
{
  nodo<int> *tmp;
  for(int i=0; i<elem; i++,A++)
    {
      if(i==0){  
        ini = new nodo<int>(*A);
        tmp = ini;
      }
      else
      {
        tmp->next = new nodo<int>(*A);
        tmp = tmp->next;
      }
    }
}

void print(nodo<int>* ini)
{
  cout<<"Inicio->";
  for(;ini;ini = ini->next)
    cout<<ini->value<<"->";
  cout<<"NULL"<<endl;
}

void merge(nodo<int>*& head,nodo<int>*& v){
    cout<<endl;
    nodo<int> *tmp = NULL;
    nodo<int> *tmp01 = NULL;//*tmp03 = NULL
    nodo<int> *pos = NULL;
    //1<2
    tmp = v;//  A
    v = v->next;//  A
    pos = head;//la posicion de 2, nos moveremos por for?
    tmp01 = pos;//2
    head = tmp;//   A
    pos = head;
    pos -> next = tmp01;//  A
    //9<10
    tmp = v;//  A
    v = v->next;//  A
    pos = head ->next->next->next;//la posicion de 10, nos moveremos por for ?
    tmp01 = pos;//  A
    head ->next->next->next = tmp;//    A
    pos = head ->next->next->next;
    pos ->next = tmp01;//   A
    //21<26
    tmp = v;// A
    v = v->next;//A
    pos = head ->next->next->next->next->next->next->next->next;//la posicion de 26, nos moveremos por for ?
    tmp01 = pos;//  A
    head ->next->next->next->next->next->next->next->next = tmp;//  A
    pos = head ->next->next->next->next->next->next->next->next;//la posicion de 26, nos moveremos por for ?
    pos -> next = tmp01;//  A
    //25<26
    tmp = v;// A
    v = v->next;//  A
    pos = head ->next->next->next->next->next->next->next->next->next;//la posicion de 26, nos moveremos por for ?
    tmp01 = pos;//  A
    head ->next->next->next->next->next->next->next->next->next = tmp;
    pos = head ->next->next->next->next->next->next->next->next->next;//la posicion de 26, nos moveremos por for ?
    pos -> next = tmp01;//  A
    //31<44
    tmp = v;// A
    v = v->next;//  A
    pos = head ->next->next->next->next->next->next->next->next->next->next->next->next;//la posicion de 26, nos moveremos por for ?
    tmp01 = pos;//  A
    head ->next->next->next->next->next->next->next->next->next->next->next->next = tmp;
    pos = head ->next->next->next->next->next->next->next->next->next->next->next->next;//la posicion de 26, nos moveremos por for ?
    pos -> next = tmp01;//  A
    //37<44
    tmp = v;// A
    v = v->next;//  A
    pos = head ->next->next->next->next->next->next->next->next->next->next->next->next->next;//la posicion de 26, nos moveremos por for ?
    tmp01 = pos;//  A
    head ->next->next->next->next->next->next->next->next->next->next->next->next->next = tmp;
    pos = head ->next->next->next->next->next->next->next->next->next->next->next->next->next;//la posicion de 26, nos moveremos por for ?
    pos -> next = tmp01;//  A
    //41<44
    tmp = v;// A
    v = v->next;//  A
    pos = head ->next->next->next->next->next->next->next->next->next->next->next->next->next->next;//la posicion de 26, nos moveremos por for ?
    tmp01 = pos;//  A
    head ->next->next->next->next->next->next->next->next->next->next->next->next->next->next = tmp;
    pos = head ->next->next->next->next->next->next->next->next->next->next->next->next->next->next;//la posicion de 26, nos moveremos por for ?
    pos -> next = tmp01;//  A
    //ya al final agregamos el resto 51 55 63
    
    
    // cout<<pos->value<<endl;
    // tmp = head;
    // for (nodo<int> *p = v; p; p = p->next){
    //     cout<<"esto "<<p->value<<" ";
    //     if(p->value<tmp->value){
    //         tmp03 = tmp;//Almacenamos el nodo en el tmp03
    //         tmp = p;
    //         tmp = tmp ->next;
    //     }
    // }
    // cout<<endl;
    // print(tmp);
    cout<<endl;
}

int main() {
int A[10] = {2,8,10,12,16,20,26,30,44,48};
int B[10] = {1,9,21,25,31,37,41,51,55,63};

nodo<int> *p,*q;

ArrayToLE(A,10,p);
print(p);
ArrayToLE(B,10,q);
print(q);
merge(p,q);
print(p);
print(q);
return 0;
}