#include <iostream>
using namespace std;

template< typename T>
class suma{
    T x;
    public:
    suma(T a): x(a) {};
    T operator()(T b){
        return x+b;
    }
};

template< typename T>
class multi{
    T x;
    public:
    multi(){x = 0; }//Contructor
    multi(T a): x(a) {};
    T operator()(T b){
        return x*b;
    }
    void operator =(const multi &M){
        x = M.x;
    }
};

template<class T, class O>
class operador{
    public:
    void op(O opr){
        for (T i = 1; i <= 10; i++){
            cout<<"opr("<<i<<") = "<<opr(i)<<endl;
        }
    }
};

template<class T,class O, T N>//Por alguna razon que esta en el propio
class operador1{              //lenguje de c++ "T N siempre lo tomara"
    O opr = O(N);             //como un entero
    public:
    void op(){
        for (T i = 1; i <= 10; i++){
            cout<<"opr("<<i<<") = "<<opr(i)<<endl;
        }
    }
};

template<class T,class O>
class operador2{
    O opr;
    public:
    operador2(T N){
        opr = N;
    }
    void op(){
    for(T i=1; i<=10;i++)
      cout<<"opr("<<i<<") = "<<opr(i)<<endl;
    }
};

template <class T,class O>
class operador3{
    T N;
    O opr= O(N);
    public:
    operador3(T n):N(n){}
    void op(){
        for(T i=1;i<=10;i++){
            cout<<"OPR("<<i<<") = "<<opr(i)<<endl;
        }
    }
};

int main(){
    // operador<double,suma<double> > a1;
    // operador<int, multi<int> > a2;

    cout<<"Tabla de suma del 5.1"<<endl;
    // a1.op(suma(5.1));
    // a1.op(suma(5.1));
    cout<<"Tabla de la multiplicacion del 2"<<endl;
    // a2.op(multi(2));

    //OPERADOR1
    operador1<int,suma<int>,5> b1;
    operador1<int,multi<int>,5> b2;
    
    cout<<"Tabla de suma del 5"<<endl;
    b1.op();
    cout<<"Tabla de la multiplicacion del 5"<<endl;
    b2.op();
    
    //OPERADOR2
    operador2<double,multi<double>> c1(3.14);
    operador3<double,multi<double>> c2(5.1);
    cout<<"Tabla de multiplicacion del 3.14"<<endl;
    c1.op();
    cout<<"Tabla de suma del 5.1"<<endl;
    c2.op();

    return 0;
}