#include <iostream>
using namespace std;

//Functor
class sumaAnali{
    int x;
    public:
    sumaAnali(int a):x(a){};//Analizaemos el contructor con los demas
    int operator()(int b){
        return x+b;
    }
};

template<class T,int n=0>//valor por deafault = 0
class suma{
    T priv_x = n;
    public:
    T operator()(T operador){
        return priv_x+operador;
    }
};

template<class T>
class suma2{
    T priv_x;
    public:
    suma2(T n):priv_x(n){};//Constructor
    T operator()(T operador){
        return priv_x+operador;
    }
};

template<class O>
class Ejecuta{
    public:
    O operador;
};

template<class T,class O>
class Ejecutado2{
    public:
    O operador;
    Ejecutado2(T n):operador(n){};
};

int main(){
    suma<int> objSuma;
    //Ya estamos definiendo el operador que vamos a utilizar y tambien como ya no es necesario inicializar un entero dado que el functor suma 
    //tiene como inializador por default al 0
    Ejecuta<suma<int>> exe;
    //Aqui modificamos el valor por default, lo remplazamos por 20
    Ejecuta<suma<int,20>> exe1;
    Ejecutado2<int,suma2<int>> exe2(30);

    cout<<objSuma(5)<<endl;
    cout<<exe.operador(5)<<endl;
    cout<<exe1.operador(5)<<endl;
    cout<<exe2.operador(5)<<endl; 

    return 0;
}