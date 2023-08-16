#ifndef _NODO_H_
#define _NODO_H_

template <typename Dato>
class Nodo
{
private:
    Dato dato;
    Nodo<Dato> *siguiente;

public:
    // CONSTRUCTTOR
    Nodo();

    // PRE: -
    // POS: Inicia el nodo guardando el elemento y con una referencia a 0 (nullptr).
    Nodo(Dato elemento);

    // PRE: -
    // POS: Devuelve el dato que guarda el nodo.
    Dato obtener_elemento();

    // PRE: -
    // POS: Devuelve la direccion de a donde apunta el nodo.
    Nodo<Dato> *obtener_siguiente();

    // PRE:
    // POS: Cambia la direccion a donde apunta el nodo, haciendo que apunte a "modificador".
    void cambiar_siguiente(Nodo<Dato> *modificador);
};

template <typename Dato>
Nodo<Dato>::Nodo()
{
}

template <typename Dato>
Nodo<Dato>::Nodo(Dato elemento)
{
    dato = elemento;
    siguiente = nullptr;
}

template <typename Dato>
Dato Nodo<Dato>::obtener_elemento()
{
    return dato;
}

template <typename Dato>
Nodo<Dato> *Nodo<Dato>::obtener_siguiente()
{
    return siguiente;
}

template <typename Dato>
void Nodo<Dato>::cambiar_siguiente(Nodo<Dato> *modificador)
{
    siguiente = modificador;
}

#endif // _NODO_H_
