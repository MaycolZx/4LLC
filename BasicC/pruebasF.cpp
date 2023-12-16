#include <iostream>
using namespace std;

template<class T>
class division{
    T x;
    public:
    division(int a):x(a){};
    int operator()(T b){
    return x / b;
    }
};

class suma{
    int x;
    public:
    suma(int a):x(a){};
    int operator()(int b){
        return x + b;
    }
};

class multi{
    int x;
    public:
    multi(int a):x(a){};
    int operator()(int b){//primera sobrecarga
    return x*b;
    }
    int operator()(int a,int b){//Segunda sobrecarga
        return a*b;
    }
};

template <class T>
void operandoList(int *lista,int sizeL,T S){
    for (int *p = lista; p < (lista+sizeL); p++){
        cout<<"La suma de "<<*p<<" = "<<S(*p)<<endl;
    }
}

template<class T,int N>
class operador{
    public:
    T oprpA = T (N);
};

int main(){
    cout<<"---------------------------------------------------------------"<<endl;
    suma A(5);
    cout<<"La suma del objeto A con instaciacion 5 -> + 20 = "<<A(20)<<endl;

    cout<<"---------------------------------------------------------------"<<endl;
    division<int> B(10);
    cout<<"La division del objeto S con instaciacion 10 -> / 5 = "<<B(5)<<endl;

    cout<<"---------------------------------------------------------------"<<endl;
    int lista[100]={5,7,9,11,13,15};
    operandoList(lista,6,suma(10));

    cout<<"---------------------------------------------------------------"<<endl;
    operador <suma,5> C;     
    return 0;
}