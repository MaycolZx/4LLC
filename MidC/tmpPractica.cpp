// SortLeX.cpp : Este archivo contiene la funci�n "main". La ejecuci�n del programa comienza y termina ah�.
//

#include <iostream>
using namespace std;

template <class T>
struct nodo
{
    T valor[3];
    nodo* next;
    nodo()
    {
        next = nullptr;
    }
};


template<class T>
struct SortLeX
{
    nodo<T>* head = nullptr;
    int nro_elementos = 0; //cantidad de elementos en la estructura
    ~SortLeX()
    {
        nodo<T>* tmp;

        while (head)
        {
            tmp = head;
            head = tmp->next;
            //cout << "Destruyendo " << tmp->valor << endl;
            delete tmp;
        }
    };
    void add(T v);
    void print();
    bool find(T v, nodo<T>*& pos, int& recorridos); //pos - posici�n del nodo, recorridos - items recorridos
    void remove(T v);
};

template<class T>
void SortLeX<T>::print()
{
    int cont = 0;
    int elem_round = 0;

    if (nro_elementos % 3 != 0)
        elem_round = nro_elementos + (3 - nro_elementos % 3);
    else
        elem_round = nro_elementos;
    cout << "Head->";
    for (nodo<T>* p = head; p; p = p->next)
    {
        cout << "[ ";
        for (int i = 0; i < 3 && cont < elem_round; i++, cont++)
        {
            if (cont < nro_elementos)
            {
                cout << p->valor[i];
                if (i < 2)
                    cout << " | ";
                else
                    cout << " ] ";

            }
            else
            {
                if (i < 2)
                    cout << " | ";
                else
                    cout << " ] ";
            }

        }
        cout << " -> ";
    }
    cout << "NULL" << endl;
}
template<class T>
bool SortLeX<T>::find(T v, nodo<T>*& pos, int& recorridos)
{
    nodo<T>* p = head;
    pos = p;

    int cont = 0;
    int i = 0;

    for (; cont < nro_elementos && p && p->valor[i] < v; cont++, i++)
        if (i == 2)
        {
            i = -1;
            p = p->next;
            if (p)
                pos = p;
        };

    recorridos = cont;

    if (p && p->valor[i] == v)
        return true;
    return false;
}

template<class T>
void SortLeX<T>::add(T v)
{
    nodo<T>* pos;
    int recor = 0, i;
    T t;
    if (!find(v, pos, recor))
    {
        if (!pos)
        {
            head = new nodo<int>;
            head->valor[0] = v;
            nro_elementos++;
        }
        else
        {
            i = recor % 3;
            if (i == 0 && recor == nro_elementos)
            {
                pos->next = new nodo<int>;
                pos->next->valor[0] = v;
            }
            else
            {
                for (; recor <= nro_elementos; recor++, i++)
                {
                    if (i > 2)
                    {
                        i = 0;
                        if (pos->next)
                        {
                            pos = pos->next;
                            i = 0;
                        }
                        else
                        {
                            pos->next = new nodo<int>;
                            pos = pos->next;
                        }
                    }
                    t = pos->valor[i];
                    pos->valor[i] = v;
                    v = t;
                }
            }
            nro_elementos++;
        }

    }
}

template<class T>
void SortLeX<T>::remove(T v)
{
    //TO DO
    nodo<T>* pos;
    int recorr = 0;
    if (find(v, pos, recorr)) {
        pos->valor[recorr % 3] = NULL;
        for (nodo<T>* p = pos; p ; p = p->next){
            for (int i = recorr; i % 3 != 2 && recorr != nro_elementos-1; i++) {
                //cout << "Seleccionamos " << p->valor[recorr % 3] << " = " << pos->valor[(recorr + 1) % 3];
                p->valor[recorr % 3] = pos->valor[(recorr + 1) % 3];
                recorr++;
            }
            if (pos->next == NULL) {
                pos->valor[recorr % 3] = NULL;
            }
            if (pos->next != NULL) {
                //cout << "Seleccionamos " << p->valor[recorr % 3] << " = " << pos->next->valor[0];
                p->valor[recorr % 3] = pos->next->valor[0];
                recorr++;
                pos = pos->next;
            }
        }
        if ( nro_elementos != 1 && pos->valor[0] == NULL) {
            nodo<T>* tmp = head;
            if (tmp->next != NULL) {
                for (; tmp->next != pos; tmp = tmp->next);
            }
            tmp->next = NULL;
            delete pos;
        }
        if (nro_elementos == 1) {
            delete pos;
            head = nullptr;
        }
        nro_elementos--;
    }
}
//Tiempo que me demore 56:00 min
int main() {
    SortLeX<int> lista;
    int Entrada[10] = { 5, 1, 6, 3, 9 , 2, 4, 8, 10, 7 };
    //int Entrada[10] = { 5, 1, 6, 7, 9 , 2, 4, 8, 10, 7 };

    lista.print();
    for (int i = 0; i < 10; i++)
    {
        lista.add(Entrada[i]);
        cout << "add(" << Entrada[i] << ") \n";
        lista.print();
    }

    cout << endl << "<------------------------------------>" << endl;

    for (int i = 0; i < 10; i++)
    {
        lista.remove(Entrada[i]);
        cout << "remove(" << Entrada[i] << ") \n";
        lista.print();
    }

    return 0;
}

// Ejecutar programa: Ctrl + F5 o men� Depurar > Iniciar sin depurar
// Depurar programa: F5 o men� Depurar > Iniciar depuraci�n

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de c�digo fuente
//   3. Use la ventana de salida para ver la salida de compilaci�n y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de c�digo, o a Proyecto > Agregar elemento existente para agregar archivos de c�digo existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
