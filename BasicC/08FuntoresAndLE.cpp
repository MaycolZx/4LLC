//Maycol Alexander Canaveri Taco - Ciencia de la Computación II - CCOMP3-1
#include <iostream>
using namespace std;

struct asc
{
  bool operator()(int a, int b)
  {return a<b;}
};

struct desc
{
  bool operator()(int a, int b)
  {return a>b;}
};

struct nodo
{
  int valor;
  nodo * next;
  nodo(int v, nodo* n=NULL)
  { valor = v; next=n;}
};

void crear(int *p, nodo*& lista)
{
  lista = new nodo(*p);
  p++;
   for(nodo* n =lista;*p>0;p++,n=n->next)
     n->next = new nodo(*p);
     
}

void print(nodo *lista)
{
  cout<<"lista -> ";
  for(;lista;lista=lista->next)
     cout<<lista->valor<<" -> ";
  cout<<"NULL"<<endl;
}

template<typename T>
void newOrden1ar(nodo*& lista, T comp)
{
  //por hacer
	int contador=0;
    nodo *p = lista;
	for(lista;p;p=p->next)
	  	contador+=1;
	contador-=1;
	nodo* newOrden1=lista;
	nodo* newnewOrden12=NULL;
	nodo* temporal1=NULL;
	nodo* temporal2=NULL;
	int control=1;
	while(control == 1){
		control = 0;
        if(!(comp(newOrden1->valor , newOrden1->next->valor))){
			temporal1=newOrden1;
			temporal2=newOrden1->next->next;
			newOrden1=newOrden1->next;
			newOrden1->next=temporal1;
			temporal1->next=temporal2;
			lista=newOrden1;
			control=1;
			temporal1=NULL;
			temporal2=NULL;			
        }
        newOrden1 = newOrden1 ->next;
        int i =1;
        while (i<=cantidad-1){
            if(!(comp(newOrden1->valor , newOrden1->next->valor))){
				temporal1=newOrden1;
				temporal2=newOrden1->next->next;
				newOrden1=newOrden1->next;
				newOrden1->next=temporal1;
				temporal1->next=temporal2;
				newnewOrden12->next=newOrden1;
				control=1;
				temporal1=NULL;
				temporal2=NULL;
            }
            newOrden1=newOrden1->next;
            newnewOrden12=newOrden1;
		}
    newOrden1=lista;
	newnewOrden12=NULL;
	cantidad--;
	if(control == 0)
        break;
	}
}


int main() {
  int A[] = {7,7,27,7,12,9,18,9,8,7,-1};
  nodo *miLista;

  crear(A,miLista);
  print(miLista);

  //newOrden1 asc
  newOrden1ar(miLista,asc());
  print(miLista);

//newOrden1 desc
  newOrden1ar(miLista,desc());
  print(miLista);

}
