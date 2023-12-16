#include <iostream>
using namespace std;

//Estructura nodo
template <class T>
struct nodo{
    T value;//valor de tipo T
    nodo *next;//puntero next de tipo nodo
    nodo(T v, nodo * n = NULL)//Contructor
    {value = v; next = n;}
};
//Creamos una lista enlazada
template<class T>
class LE{
    //Recordar cada vez que empleemeos el objeto nodo si lo hacemos con "class" tenemos 
    //poner "public" ya que de lo contrario si el "class" siempre lo tomara como "private"
    public: 
    nodo<T>* head = NULL;
    bool find(T v, nodo<T>*& pos);//Primero definiremos el metodo find
    void add(T v);//Segundo definiremos el metodo add
    void del(T v);//Tercero definiremos el del
    void print();//Cuarto definiremos el printLE
    ~LE();//Solo se ejecuta cuando el programa a terminado
};
//Definimos el metodo "find"
template<class T>
bool LE<T>::find(T v,nodo <T> *&pos){
    nodo<T>* p;
    pos = NULL;
    //EL "for" ira recorriendo hasta que "p->value < v"(se mayor que el valor que estoy buscando) o "p" sea igual a nulo
    //cuando salgo del "for" hay dor posibilidades:1.p->value <v || 2.p->value ==v
    for (p = head; p&&p->value<v; pos =p, p=p->next);
    //Recordemos que solamente "p" es igual a decir que "p!=NULL"
    //continuando ... && p->value == v
    //En otras palabras si "p!=NULL" && "que el valor de 'p' que recorrimos con el 'for' es igual al parametro v" -> return TRUE.
    if (p&&p -> value == v)
        return true;
    return false;
}
//Definimos el metodo "add"
template<class T>
void LE<T>::add(T v){
    nodo<T> *pos;
    if (!find(v,pos))//Si no encontro(find) el valor se ejecutara
    {
        //Si el "find" retorna "falso" atravez del "if" diriamos que "!falso == true" por lo que si se ejecutaria si no
        //encontrara un valor despues del head  
        if (!pos){//If !(pos!=NULL) Caso1: si pos=head es igual a NULL entonces
            head = new nodo<T>(v,head);//head = NULL
        }else{//Si el pos no es NULL entonces se ejutara el else
            pos->next = new nodo<T>(v,pos->next);
        }
    }
}
//Definimos el metodo "del"
template<class T>
void LE<T>::del(T v){
    //Sabemos que para eliminar punteros debemos tomar la posicion anterior del nodo que queremos aliminar
    //Creamos un nodo "tmp" que apuntara al valor(v) que valor a eliminar, para ello sabemos que find nos debe retornar TRUE 
    nodo<T>*tmp, *pos;
    if(find(v,pos)){
        if(!pos){
            //Caso donde solo tenemos un "unico elemento" o queramos eleminar el primer elemento,
            //por lo que tmp sera igual al nodo "head", y "head" apuntara al siguiente elemento  
            tmp=head;
            head=head->next;
        }else{
            //Caso donde el nodo a eliminar se encuentra despues del primero
            tmp=pos->next;//Almacena la direccion de memoria que se apunta dentro del tmp para al final eliminarla
            pos->next = tmp->next;//
        }
        delete tmp;//Al final elminamos el tmp
    }
}
//Definimos el metodo printLE
template<class T>
void LE<T>::print(){
    cout<<"HEAD->";
    for (nodo<T> *p = head;p; p=p->next)
        cout<<p->value<<"->";
    cout<<"NULL"<<endl;
}

template<class T>
LE<T>::~LE(){
    // while(head)//Mientras head != NULL 
    //     del(head->value);
    while(head){
        cout<<"Destruyendo "<<head->value<<endl;
        del(head->value);
    }
}

int main(){
    LE<int> lista;

    lista.print();
    lista.add(5);
    lista.print();
    lista.add(1);
    lista.print();
    lista.add(7);
    lista.print();
    lista.add(3);
    lista.add(6);
    lista.print();
    lista.del(5);
    lista.print();
    lista.del(7);
    lista.print();
    lista.del(1);
    lista.print();
    lista.del(3);
    lista.del(6);
    lista.print();
    lista.del(7);
    lista.print();  

    return 0;
}   