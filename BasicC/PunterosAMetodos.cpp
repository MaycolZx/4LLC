#include <iostream>
using namespace std;

class Foo{
    public:
    static int n;//Ahora este atributo es estatico
    void x(){n++;}
    int suma(int a,int b)
    {return a+b;}
    int mult(int a,int b)
    {return a*b;}

    static int negado(int a)//Es el mismo metodo para todas las instancias
    {return -a;}
};
int Foo::n=1;

//parametros:
    //-Numero entero a,
    //-Numero entero.b,
    //-Necesitamos una instacia del obj,pero le vamos a pasar todos el objeto por eso tiene un asterisco, 
    //-Este es para a puntar a un de los metodos del objeto.
int call1(int a,int b, Foo *pFoo, int(Foo::*pf)(int, int)){
    //Voy a ir al puntero de este objeto y voy a entrar al metodo
    //que esta apuntando pf, se podria decir que hay dos punteros
    return (pFoo->*pf)(a,b);
    // return ((pFoo).*pf)(a,b);//Segunda manera que este podria ser escrito
}

//"typedef" lo hace un tipo de dato
typedef int (Foo::*Foo_pf)(int,int);
int call2(int a,int b, Foo *pFoo, Foo_pf pf){
    // return (pFoo->*pf)(a,b);
    return ((*pFoo).*pf)(a,b);
}

int call3(int a, int(*pf)(int)){
    return pf(a);
}

typedef int(*PF)(int);
int call4(int a,PF pf){
    return pf(a);
}

int main(){
    Foo foo, foo1;
    cout<<"Foo::suma(4,6) = "<<call1(4,6,&foo,&Foo::suma)<<endl;
    cout<<"Foo::multi(4,6) = "<<call2(4,6,&foo,&Foo::mult)<<endl;

    cout<<"foo.n "<<foo.n<<endl;
    cout<<"foo1.n "<<foo1.n<<endl;
    cout<<"Foo::n"<<Foo::n<<endl;
    foo.x();   
    cout<<"foo.n "<<foo.n<<endl;
    cout<<"foo1.n "<<foo1.n<<endl;
    cout<<"Foo::n"<<Foo::n<<endl;
    foo1.x();   
    cout<<"foo.n "<<foo.n<<endl;
    cout<<"foo1.n "<<foo1.n<<endl;
    cout<<"Foo::n"<<Foo::n<<endl;

    cout<<"Foo::negado(10) = "<<call3(10,Foo::negado)<<endl;
    cout<<"Foo::negado(10) = "<<call3(10,&Foo::negado)<<endl;

    cout<<"Foo::negado(10) = "<<call4(10,Foo::negado)<<endl;
    cout<<"Foo::negado(10) = "<<call4(10,&Foo::negado)<<endl;

    foo.x();
    return 0;
}