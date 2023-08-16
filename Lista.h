#ifndef _LISTA_H_
#define _LISTA_H_

#include "Nodo.h"

template <typename Dato>
class Lista
{
protected:
    Nodo<Dato> *primero;
    int cantidad;

public:
    // PRE: -
    // POST: Inicia la lista con valores nulos.
    Lista();

    // PRE: Posicion tiene que ser menor a la (cantidad+1) y mayor/igual a 0.
    // POST: Agrega un elemento en la posicion indicada, y pisa si ya tenia guardado un elemento.
    void alta(Dato elemento, int posicion);

    // PRE: -
    // POST: Agrega el elemento ordenadamente segun el orden > del "Dato".
    void alta_ordenada(Dato elemento);

    // PRE: Posicion tiene que ser menor a la cantidad y mayor o igual a 0.
    // POST: Borra el elemento en la posicion indicada.
    void baja(int posicion);

    // PRE: -
    // POST: Si la cantidad de elementos de la lista es 0 devulve true.
    bool vacia();

    // PRE: Posicion tiene que ser menor a la cantidad y mayor o igual a 0.
    // POST: Retorna el elemento guardado en la posicion indicada.
    Dato consulta(int posicion);

    // PRE: -
    // POST: Retorna la cantidad de elementos guardados.
    int obtener_cantidad();

    // PRE: -
    // POST: Da de baja todos los elementos de la lista.
    ~Lista();

protected:
    // PRE: Posicion tiene que ser menor a la cantidad y mayor o igual a 0.
    // POST: Devulve el nodo en la posicion indicada.
    Nodo<Dato> *obtener_nodo(int posicion);
};

template <typename Dato>
Lista<Dato>::Lista()
{
    primero = nullptr;
    cantidad = 0;
}

template <typename Dato>
void Lista<Dato>::alta(Dato elemento, int posicion)
{
    Nodo<Dato> *aux = new Nodo<Dato>(elemento);
    if (posicion == 0)
    {
        aux->cambiar_siguiente(primero);
        primero = aux;
    }
    else
    {
        Nodo<Dato> *anterior = obtener_nodo(posicion - 1);
        aux->cambiar_siguiente(anterior->obtener_siguiente());
        anterior->cambiar_siguiente(aux);
    }
    cantidad++;
}

template <typename Dato>
void Lista<Dato>::alta_ordenada(Dato elemento)
{
    if (vacia())
    {
        alta(elemento, 0);
    }
    else
    {
        Nodo<Dato> *aux = primero;
        int i = 0;
        while (i < cantidad && (elemento > aux->obtener_elemento()))
        {
            aux = aux->obtener_siguiente();
            i++;
        }
        alta(elemento, i);
    }
}

template <typename Dato>
void Lista<Dato>::baja(int posicion)
{
    Nodo<Dato> *aux = primero;
    if (posicion == 0)
    {
        primero = aux->obtener_siguiente();
    }
    else
    {
        Nodo<Dato> *ant = obtener_nodo(posicion - 1);
        aux = ant->obtener_siguiente();
        ant->cambiar_siguiente(aux->obtener_siguiente());
    }
    delete aux;
    cantidad--;
}

template <typename Dato>
bool Lista<Dato>::vacia()
{
    return (cantidad == 0);
}

template <typename Dato>
Dato Lista<Dato>::consulta(int posicion)
{
    Nodo<Dato> *aux = obtener_nodo(posicion);
    return (aux->obtener_elemento());
}

template <typename Dato>
int Lista<Dato>::obtener_cantidad()
{
    return (cantidad);
}

template <typename Dato>
Nodo<Dato> *Lista<Dato>::obtener_nodo(int posicion)
{
    Nodo<Dato> *aux = primero;
    for (int i = 0; i < posicion; i++)
    {
        aux = aux->obtener_siguiente();
    }
    return aux;
}

template <typename Dato>
Lista<Dato>::~Lista()
{
    while (!vacia())
    {
        baja(0);
    }
}

#endif // _LISTA_H_