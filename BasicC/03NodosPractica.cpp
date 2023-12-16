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
    //TO DO
    //mezclas P y Q, donde P apunta a la lista mezclada en orden
    // Q apunta a nulo
    //Prohibido crear nodos y borrar nodos (no usar new o delete)
    //Debe mover los enlaces (NEXT)
    cout<<endl;
    nodo<int> *tmp,*tmp01,*tmp03,*pos = NULL;
    // tmp03 = v;
    // v = v->next;
    // tmp = head->next->next->next;
    // print(tmp);
    // tmp = tmp03;
    // print(tmp);
    // while(v != nullptr){
        for (nodo<int> *p = head; p->value > v->value; pos =p, p=p->next);
        // if (pos != nullptr){
            // head = new nodo<T>(v,head);
        tmp = v;
        tmp01 = head;
        v = v->next;
        head = tmp;
        head->next = tmp01;
            // break;
        // }
        // }else{
        //     pos->next = new nodo<T>(v,pos->next);
        // }
    // }
    // for (nodo<int> *p = head; p; p=p->next){
        // cout<<"el valor de p es "<<p->value<<" la direccion de memoria almacenada es: "<<p<<endl;
        // tmp01 = head;
        // tmp01 = tmp01->next;
        // cout<<tmp01<<" - ";
        // if(v->value<p->value){
            // tmp = v;
            // tmp01 = p;
            // v = v->next;
            // p =tmp;
            // p ->next = tmp01;
        // }
        // if(v->value < p->value){
        //     cout<<v->value<<"<"<<p->value<<" ->";
        //     tmp = v;
        //     tmp01 = p;
        //     v = v->next;
        //     p = tmp;
        //     p->next = tmp01;
            // break;
        // }
    // }
    // while (v->next!=NULL){
    //     tmp = v;
    //     tmp01 = head;
    //     v = v->next;
    //     head = tmp;
    //     head->next = tmp01;
    //     head = head->next;/* condition */
    // }
    int contador=0;
    tmp01 = head;
    nodo<int> * tmp3;
    // while (contador != 4){
    //     tmp01 = tmp01->next;
    //     cout<<tmp01->value<<" - ";
    //     if (v->value < tmp01->value){//v < valor de head
    //         tmp = v;
    //         tmp3 = tmp01;
    //         v = v->next;
    //         tmp01 = tmp;
    //         tmp01->next = tmp3;
    //     }
        
    //     contador++;
    // }
    
    cout<<endl;
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