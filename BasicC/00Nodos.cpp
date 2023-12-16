#include <iostream>
using namespace std;

class nodo{
    public:
    int valor;//el valor que le asignamos al nodo
    nodo *next;//puntero
};

void printLE(nodo *head){
    //Observemos los parametros del "for"
    //  -nodo *p=head
    //  -p != nullptr: esto indica que la direccion de memoria p 
    //                tiene que ser diferente del nullptr para que la condicion acabe
    //  -p=p->next: de esta manera avanzamos con los nodos con el "p->next"
    cout<<"HEAD->";
    for (nodo *p = head; p != nullptr; p=p->next){
        cout<<p->valor<<"->";
    }
    cout<<"NULL"<<endl;
}

//primera regla: si ya le puse p y aca lo voy a igual a head , ya no voy a necesitar esta inicializacion "nodo *p = head"
//no necesito igualarlo al head , porque ya lo voya ingualar cuando llame a la funcion
void printLEv2(nodo *p){
    cout<<"HEAD->";
    for (;p; p=p->next){//Obsevermos como "p"(segundo parametro), cuando ponemos solamente "p" decimos:"Si "p" apunta a
                        //algo es verdadero, pero si "p" apunto a nulo "p" es falso,y en cuando "p" es falso se rompe la condicion"
        cout<<p->valor<<"->";
    }
    cout<<"NULL"<<endl;
}

int main(){
    //"head" apunta a nulo y "tmp" quiere apuntar al valor de "head" que apunta a nulo , esto daria un error,
    //yo no puedo hacer esta operacion a un puntero nulo , siempre me dara un error en cualquier compilador,
    //para evitar esto siempre debo asegurarme de que el puntero no sea nulo,el error "segmentation fault"
    //indica que he perdido un puntero "HAY QUE TENER CUIDADO"
    // nodo * head = NULL;  ---> "Cuidado"
    // int tmp = head->valor; ---> "Cuidado"

    nodo * head;//---> Esto esta bien
    //creando nodo 1
    head = new nodo;//genera un objeto nodo
    head-> valor = 1;//le asigna el valor de 1 al nodo
    head->next = nullptr;//le asigna la direccion de momoria "next"="NULL" //DatoCurioso:El nullptr viene desde la nueva version de c++ 11
    //creando nodo 2
    head->next = new nodo;//Ahora la direccion de memoria "next" del nodo 1 apunta a la direccion de memoria de un nuevo nodo
    head->next->valor = 2;
    head->next->next = NULL;//DatoCurioso: el NULL es mas universal
    //creadno nodo 5
    head->next->next = new nodo;//Ahora la direccion de memoria "next" del nodo 2 apunta a la direccion de memoria de un nuevo nodo
    head->next->next->valor = 5;
    head->next->next->next = 0;//DatoCurioso: el poner 0 como nullpointer viene desde la programacion mas antigua
    //Ejemplo practico: Insertar el nodo 3 en medio del 2 y 5 y ver que vaya en orden
    //Ejemplo practico:Introducimos el 3 entre 2 y 5.
    nodo * tmp;
    tmp = head->next->next;//guardamos a donde apunta el nodo 2 el nodo 5
    head->next->next = new nodo;
    head->next->next->valor = 3;
    head->next->next->next = tmp;

    //Ambos print(printLE y printLEv2) son validos, pero printLEv2 digamos es mas estetico dado que reducimos el codigo
    // printLE(head);//VALIDO
    printLEv2(head);//VALIDO y mas estetico
    return 0;
}
//Observemos como usamos tres tipos de nullpointers: "nullptr","NULL","0".
//NOTA:Basta que perdamos un puntero ,ya perdimos un pedazo de la estrucra de datos