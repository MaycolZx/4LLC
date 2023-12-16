#include <iostream>
using namespace std;

class Foo{
    public:
    static int n;
    void x(){n++;}
    int suma(int a,int b)
    {return a+b;}
    int mult(int a,int b)
    {return a*b;}
    static int negado(int a)
    {return -a;}
};
int Foo::n=1;

//Para el siguiente caso ya no necesitariamos enviar la direccion de memorio con el "&" basta con simplemente llamanrlo
int call1(int a,int b, Foo &pFoo,int (Foo::*pf)(int,int)){//Observemos el "&"
    return (pFoo.*pf)(a,b);//Veamos como ya no es necesario usar la flecha "->"
}

//"typedef" lo hace un tipo de dato
typedef int (Foo::*Foo_pf)(int,int);
int call2(int a,int b, Foo &pFoo, Foo_pf pf){//Observemos el "&"
    return (pFoo.*pf)(a,b);//Veamos como ya no es necesario usar la flecha "->"
}

int main(){
    Foo foo;
    cout<<"Foo::suma(4,6) = "<<call1(4,6,foo,&Foo::suma)<<endl;
    cout<<"Foo::multi(4,6) = "<<call2(4,6,foo,&Foo::mult)<<endl;
    return 0;
}