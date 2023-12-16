#include <iostream>
using namespace std;

//Functor
class suma{
    int x;
    public:
    suma(int a):x(a){};//Constructor
    int operator()(int b){
        return x+b;
    }
};
//Functor
class suma01{
    int x;
    public:
    suma01(int a):x(a){};//Constructor
    int operator()(int b){
        return x*b;
    }
};
//Functor
template<class T>
class fibo{
    public:
    void operator()(int *p, T op){//Recordar que "op" es el llamado al functor para ser usado dentro de esta clase 
        //TO DO
        // cout<<endl<<"que es esto "<<*(p+1)<<endl;
        *p = *(p+1);
        *(p+1) = op(*(p+1));
        // *(p+1) = op(*p);
    }
};
//Functor
template<class T>
class fact{
    public:
    void operator()(int *p, T op){//Recordar que "op" es el llamado al functor para ser usado dentro de esta clase 
        // cout<<endl<<"que es esto "<<*(p+1)<<endl;
        *p= op(*(p+1));
        *(p+1) = *(p+1)+1;
    }
};
//Main
int main(){
    //FIBONACCI
    int a[2] = {0,1};
    fibo<suma> f;
    for (int i = 0; i < 10; i++){
        cout<<*a<<" ";
        f(a,suma(*a));
    }
    cout<<endl;
    //FACTORIAL
    int b[2] = {1,2};
    fact<suma01> g;
    for (int i = 0; i < 10; i++){
        cout<<*b<<" ";
        g(b,suma01(*b));
    }
    cout<<endl;
    return 0;
}
