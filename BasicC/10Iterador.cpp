#include <iostream>
using namespace std;

//Los iteradores sobrecargan un monton de parentesis, la idea es que el iterador simplifique las operaciones afuera
template<class T>
class Iterator{
    T* it;
    public:
    void operator=(T* valor){
        it = valor;
    }
    void operator=(T valor){
        *it = valor;
    }
    bool operator<=(T* otro){
        return it<=otro;
    }
    T* operator ++(int){
        it++;
        return it;
    }
    T operator*(){
        return *it;
    }
    friend istream &operator>>(istream &input, Iterator I){
        input >> *(I.it);//input>>(*I.it)
        return input;
    }

};

//La idea del iterador es que represente o simplifique las operaciones que harias con la clase "vector"
template<class T,class I>
class Vector{
    T a[10];
    public:
    //Defininimos el "it_vector" como un "tipo de dato" para usarlo fuera de la clase
    typedef I it_vector;//"it_vector" es una instancia de la clase Vector
    T* begin(){
        return &a[0];//o return a; Sabemos que vamos a retornar la direccion del primer elemento
    }
    T* end(){
        return &a[9];//o return (a+9); Sabemos que vamos a retornar la direccion del ultimo elemento
    }
};

int main(){
    Vector<int,Iterator<int>> Ent;
    Vector<int,Iterator<int>>::it_vector It;
    int x = 100;
    for (It = Ent.begin(); It <= Ent.end(); It++){
        It = x;
        x += 10;
    }
    for (It = Ent.begin(); It <= Ent.end(); It++){
        cout<<*It<<endl;
    }
    cout<<"-------------------------------------------"<<endl;
    for (It = Ent.begin(); It<=Ent.end(); It++){
        cout<<"Ingrese un numero entero: ";
        cin>>It;
    }
    for (It = Ent.begin(); It<=Ent.end(); It++){
        cout<<*It<<endl;
    }
    return 0;
}
//Son formas en que usamos clases y sobrecargas
//Cuando sobrecargamos solamente el parentesis se le llama functor, cuando sobrecargas el "+","=","etc"
//Y el objetivo es simplificar la navegacion dentro de otro objeto es lo que llamamos iterador
//Este iterador puede usarse en una lista enlazada,arbol,grafo, para simplificar la navegacion en las operacion
//la idea es que iteremos de ahi el nombre