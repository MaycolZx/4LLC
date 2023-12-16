#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class suma{
    int x;
    public:
    suma(int X): x(X) {};
    int operator()(int a){
        return a+x;
    }
};

//Segunda forma de inicializar un functor
// struct suma2{
//     suma2(int X): x(X) {};
//     int operator()(int a){
//         return a+x;
//     }
//     private:
//     int x;
// };

class multi{
    int x;
    public:
    multi(int X): x(X) {};
    int operator()(int a){//primera sobrecarga
        return a*x;
    }
    int operator()(int a,int b){//segunda sobrecarga
        return a*b;
    }
};
//Tabla no dinamica
void tabla(int numero,suma S){
    for (int i = 1; i <=numero; i++){
        cout<<"con "<<i<<" = "<<S(i)<<endl;
    }
}
//Tabla dinamica
template <class T>
void tabla2(int numero,T S){
    for (int i = 1; i <=numero; i++){
        cout<<"con "<<i<<" = "<<S(i)<<endl;
    }
}
//Tabla3
template <class T>
void tabla3(int numero,int b,T S){//enviamos un template class T a la tabla 3
    for (int i = 1; i <=numero; i++){
        cout<<b<<" con "<<i<<" = "<<S(i,b)<<endl;
    }
}

int main(){
    suma S(4);//4 va a igualarse a la variable x

    tabla(10,S);
    cout<<"--------------------------"<<endl;
    tabla(10,suma(10));
    cout<<"--------------------------"<<endl;
    tabla2(10,S);
    cout<<"--------------------------"<<endl;
    tabla2(10,suma(10));//usando "template" yo puedo enviar a esta tabla cualquier functor
    cout<<"--------------------------"<<endl;
    tabla2(10,multi(2));//usando "template" yo puedo enviar a esta tabla cualquier functor
    cout<<"--------------------------"<<endl;
    tabla3(10,5,multi(2));
    cout<<"--------------------------"<<endl;
    multi Z(4);//Observemos como si o si necesitamos definir la variable x del contructor
    cout<<Z(2,5)<<endl;//Usamos la segunda sobrecarga del operador parentesis

    // suma2 A(5);
    // cout<<S(2)<<endl;//Llamamos a la sobreacarga "5"(constructor) + "2"
    // cout<<S(8)<<endl;
    // cout<<A(4)<<endl;
    // cout<<A(6)<<endl;
    return 0;
}