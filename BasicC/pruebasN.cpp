#include <iostream>
using namespace std;

// void probamosRefe(int &numero){
//     cout<<*& numero<<endl;
// }

// int main(){
//     // int nprueb = 15;
//     // int* p = &nprueb;
//     // probamosRefe(*p);
//     //*******************************
//     // LE<int> intLE;//Esto es valido
//     // LE<char> cLE;//Esto es valido
//     // LE<nodo<int>> xLE;//Esto es valido
//     //********************************

//     return 0;
// }

// void pruebFor(){
//   int valor = 0;
//   for ( valor; valor <= 10;cout<<valor<<" - ", valor++);
// }
// int main(){
//   pruebFor();
//   return 0;
// }
template<class T>
class PruebaPunteroMetodo{
  public:
  T value;
  PruebaPunteroMetodo *algo;
  PruebaPunteroMetodo(T x,PruebaPunteroMetodo *n=nullptr)
  {value = x;algo = n;}
};

template<class T>
class Impri{
  public:
  PruebaPunteroMetodo<T>*head = nullptr;
  bool existe(T v,PruebaPunteroMetodo<T> *&pos);
  void existeDOS(T v);
};

template<class T>
bool Impri<T>::existe(T v,PruebaPunteroMetodo<T> *&pos){
  int p = 4,q = 8;
  pos = &p;
  for ( int valor = 0; valor < 10;cout<<pos=&q, valor++);
  return true;
};

template<class T>
void Impri<T>::existeDOS(T v){
  PruebaPunteroMetodo<T> *pos;
  
  if(existe(5,pos)){
    cout<<"La direccion de memoria de pos: "<<pos<<"y el valor de pos es "<< *&pos<<endl;
  }
  cout<<"El valor del parametro de v es: "<<v<<endl;
};

int main(){
  Impri<int> funciona;
  funciona.existeDOS(5);
  return 0;
}