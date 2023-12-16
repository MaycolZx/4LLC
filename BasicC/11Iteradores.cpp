#include <iostream>
using namespace std;

template<class T>
struct asc{//Estamos dejando el contructor por defecto
    bool operator()(T a,T b){
        return a<b;
    }
};
template<class T>
struct des{//Estamos dejando el contructor por defecto
    bool operator()(T a,T b){
        return a>b;
    }
};
template<class T,class S>
struct Iterator{
    void operator=(T *obj){
        it = obj;
    }
    bool operator!=(T *obj){
        return it!=obj;
    }
    T* operator++(int){
        it = it->next;
        return it;
    }
    S operator*(){
        return it->value;
    }
    private:
    T *it;
};



//Estructura nodo
template <class T>
struct nodo{
    T value;//valor de tipo T
    nodo *next;//puntero next de tipo nodo
    nodo(T v, nodo * n = NULL)//Contructor
    {value = v; next = n;}
};
//Creamos una lista enlazada
template<class T,class O,class I>
class LE{
    //Recordar cada vez que empleemeos el objeto nodo si lo hacemos con "class" tenemos 
    //poner "public" ya que de lo contrario si el "class" siempre lo tomara como "private"
    public: 
    nodo<T>* head = NULL;
    O order;
    typedef I IT_LE;
    bool find(T v, nodo<T>*& pos);//Primero definiremos el metodo find
    void add(T v);//Segundo definiremos el metodo add
    void del(T v);//Tercero definiremos el del
    void print();//Cuarto definiremos el printLE
    ~LE();//Solo se ejecuta cuando el programa a terminado
};
//Definimos el metodo "find"
template<class T,class O,class I>
bool LE<T,O,I>::find(T v,nodo <T> *&pos){
    nodo<T>* p;
    pos = NULL;
    //EL "for" ira recorriendo hasta que "p->value < v"(se mayor que el valor que estoy buscando) o "p" sea igual a nulo
    //cuando salgo del "for" hay dor posibilidades:1.p->value <v || 2.p->value ==v
    for (p = head; p&&order(p->value,v); pos =p, p=p->next);
    //Recordemos que solamente "p" es igual a decir que "p!=NULL"
    //continuando ... && p->value == v
    //En otras palabras si "p!=NULL" && "que el valor de 'p' que recorrimos con el 'for' es igual al parametro v" -> return TRUE.
    if (p&&p -> value == v)
        return true;
    return false;
}
//Definimos el metodo "add"
template<class T,class O,class I>
void LE<T,O,I>::add(T v){
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
template<class T,class O,class I>
void LE<T,O,I>::del(T v){
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
template<class T,class O,class I>
void LE<T,O,I>::print(){
    cout<<"HEAD->";
    for (nodo<T> *p = head;p; p=p->next)
        cout<<p->value<<"->";
    cout<<"NULL"<<endl;
}

template<class T,class O,class I>
LE<T,O,I>::~LE(){
    // while(head)//Mientras head != NULL 
    //     del(head->value);
    while(head){
        cout<<"Destruyendo "<<head->value<<endl;
        del(head->value);
    }
}

int main(){
    // LE<int,des<int>> lista; ->evoluciona->  LE<int,des<int>,Iterator<nodo<int>>> lista;
    
    LE<int,asc<int>,Iterator<nodo<int>,int>> lista;
    LE<int,asc<int>,Iterator<nodo<int>,int>>::IT_LE lista_it;

    // LE<int,des<int>,Iterator<nodo<int>,int>> lista;
    // LE<int,asc<int>,Iterator<nodo<int>,int>>::IT_LE lista_it;

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

    cout<<endl<<"Imprimir LE con Iterador"<<endl;
    cout<<"HEAD->";
    lista_it = lista.head;
    for (;lista_it!=NULL; lista_it++){
        cout<<(*lista_it)<<"->";
    }
    cout<<"NULL"<<endl<<endl;

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

    int j = 1;
    cout<<"Este es el valor de j = "<<j++<<endl;
    cout<<j<<endl;

    j=1;
    cout<<"Este es el valor de j = "<<++j<<endl;
    cout<<j<<endl;

    j=1;
    cout<<"wtf"<<endl;
    cout<<j++ + ++j<<endl;//2 + 2 = 4
    cout<<j<<endl;// 3
    return 0;
}   