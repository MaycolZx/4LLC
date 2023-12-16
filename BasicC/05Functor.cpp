#include <iostream>
using namespace std;

class suma2{
    int x;
    public:
    suma2(int a):x(a){};//{x = a}
    int operator()(int b){
        return x+b;
    }
    //Observemos como sobrecargamos el operador "=".Enviamos por referencia S, 
    //que tiene "const" nos dice que no lo podemos modificar
    void operator = (const suma2 &S){
        x = S.x; //Esta implementacion es para modificar el valor de "x"
    }
    void modifica(int a){
        x = a;
    }
};

class suma{
    int x;
    public:
    suma(int a): x(a) {};
    int operator()(int b){
        return x+b;
    }
};

class multi{
    int x;
    public:
    multi(int a): x(a) {};
    int operator()(int b){
        return x*b;
    }
    // int operator()(int a,int b){
    //     return a*b;
    // }
};
template<class T>
class operador{
    public:
    void op(T opr){//Parametro "opr"
        for (int i = 1; i <= 10; i++){
            cout<<"operador("<<i<<") = "<<opr(i)<<endl;
        }        
    }
};

//Cuando yo paso un functor a una clase es como si yo pasase un metodo ,
//al literal estoy creando un metodo que se lo estoy pasando a un template
//Contruir metodos bajo una clase bajo parametro
template<class T,int N>// <suma,20>por ejemplo
class operador01{//Cuando queremos hacer una instaciacion, ponemos el tipo
    T opr = T(N);//Metodo privado de la clase  -->  suma S = suma(5);
    public:
    T oprp = T(N);//Es un metodo
    void op(){
        for (int i = 1; i <= 10; i++){
            cout<<"operador("<<i<<") = "<<opr(i)<<endl;
        }        
    }
};

int main(){
    // suma2 S(4);
    // cout<<S(3)<<endl;
    // S= 10;
    // cout<<S(3)<<endl;
    // S.modifica(15);
    // cout<<S(3)<<endl;

    operador<suma> a1;
    operador<multi> a2;

    // suma S = suma(5);
    // cout<<S(20)<<endl;
    
    operador01<suma,5> b1;
    operador01<multi,5> b2;

    cout<<"Tabla de la suma del 5: "<<endl;
    a1.op(suma (5));//Instaciamos el objeto "a1" con el metodo "op" con el numero 5
    cout<<"Tabla de la multiplicacion del 5"<<endl;
    a2.op(multi (5));//Instaciamos el objeto "a2" con el metodo "op" con el numero 5

    cout<<"*** Tabla de la suma del 5: "<<endl;
    b1.op();//Instaciamos el objeto "b1" con el metodo "op" con el numero 5
    cout<<"*** Tabla de la multiplicacion del 5: "<<endl;
    b2.op();//Instaciamos el objeto "b2" con el metodo "op" con el numero 5

    cout<<"---------------------------------"<<endl;
    cout<<b1.oprp(20)<<endl;//En la sobrecargar con el operador en si la ejecucion es 20 + 5 = 25 .Llamando al metodo publico "oprp"
    cout<<b2.oprp(20)<<endl;//En la sobrecargar con el operador en si la ejecucion es 20 * 5 = 100 .Llamando al metodo publico "oprp"
    
    return 0;
}