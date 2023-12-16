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
    // nodo<int> *tmp = NULL;
    // nodo<int> *tmp01 = NULL;
    // nodo<int> *tmp02 = NULL;
    // tmp02 = head; 
    // for (nodo<int> *p = head; p; p = p->next){
    //   if (v->value<p->value){
    //     tmp = v;//  A
    //     v = v->next;//  A
        
    //     // pos = head;//la posicion de 2, nos moveremos por for?
    //     tmp01 = p;//2
    //     head = tmp;//   A
    //     p = head;
    //     p -> next = tmp01;//  A
    //     // break;
    //     // head = head->next;
    //   }
    // }
    nodo<int> *tmp = NULL;
    nodo<int> *pos = NULL;
    while (v){
      for (nodo <int> *p = head; p&&p->value < v->value ; pos =p, p=p->next);//p->value menor que v->value
      if(!pos){
            cout<<"EL valor de pos es en el camino 1 "<<pos<<" < ... "<<endl;
            tmp=head;// A
            head=v;// A
            v = v->next;//  A
            head ->next = tmp;//  A
            cout<<"CAMINO 1"<<endl;
        }else{
            cout<<"EL valor de pos es en el camino 2 "<<pos<<" < ... "<<endl;
            tmp=pos->next;
			      pos->next=v;
			      v=v->next;//  A
			      pos->next->next=tmp;
            cout<<"CAMINO 2"<<endl;
        }
    }
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