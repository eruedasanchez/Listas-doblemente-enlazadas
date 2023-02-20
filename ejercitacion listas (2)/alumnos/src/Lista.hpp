#include "Lista.h"

Lista::Lista() {
    /* Completar */
    _first = nullptr;              // El puntero al primer nodo es nulo porque no hay elementos en la lista
    _last = nullptr;               // El puntero al ultimo nodo es nulo porque no hay elementos en la lista
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    /* Completar */
    while (_first != nullptr){
        sacarPrimero();
    }
}

void Lista::sacarPrimero() {
    Nodo* head = _first;
    _first = _first->next;
    delete head;
}

Lista& Lista::operator=(const Lista& aCopiar) {
    /* Completar */
    borrar();                                              // Se borran todos los elementos de la lista para poder agregar los de la lista "aCopiar"
    Nodo* node_actual = aCopiar._first;                   //  Se apunta node_actual al primer nodo de la lista "aCopiar"
    while (node_actual != nullptr){                      //   Se recorre la lista "aCopiar"
        this->agregarAtras(node_actual->data);          //    Se agregan los elementos de la lista "aCopiar" en "this"
        node_actual = node_actual->next;               //     Se avanza al siguiente nodo de la lista "aCopiar"
    }
    return *this;                                          // Se devuelve la lista "aCopiar" con todos los elementos copiados
}

void Lista::borrar() {
    while (_first != nullptr){
        sacarPrimero();
    }
}

void Lista::agregarAdelante(const int& elem) {
    /* Completar */
    Nodo* new_node_ad = new Nodo(elem);                        // Se crea el nodo a insertar adelante
    /* Caso 1: No hay nodos en la lista  */
    if(_first == nullptr){
        _first = new_node_ad;
        _last = new_node_ad;
        /* Caso 2: Solo hay un unico nodo en la lista */
    } else if (_first == _last) {
        _first->prev = new_node_ad;
        new_node_ad->next = _last;
        _first = new_node_ad;
        /* Caso 3: Hay mas de un nodo en la lista */
    } else {
        _first->prev = new_node_ad;
        new_node_ad->next = _first;
        _first = new_node_ad;
    }
}

void Lista::agregarAtras(const int& elem) {
    /* Completar */
    Nodo* new_node_at = new Nodo(elem);                               // Se crea el nodo a insertar atras
    /* Caso 1: No hay nodos en la lista  */
    if(_first == nullptr){
        _first = new_node_at;
        _last = new_node_at;
        /* Caso 2: Hay un unico nodo en la lista  */
    } else if (_first == _last) {
        _first->next = new_node_at;
        new_node_at->prev = _first;
        _last = new_node_at;
        /* Caso 3: Hay mas de un nodo en la lista  */
    } else {
        _last->next = new_node_at;
        new_node_at->prev = _last;
        _last = new_node_at;
    }
}

void Lista::eliminar(Nat i) {
    /* Completar */
    Nodo* node_actual = _first;                       // Se crea un puntero apuntando al primer nodo de la lista

    /* Se recorre el ciclo i veces hasta encontrar la posicion del elementno a eliminar */
    while (i > 0) {
        i--;
        node_actual = node_actual->next;
    }
    Nodo* node_ant_actual = node_actual->prev;
    Nodo* node_sig_actual = node_actual->next;
    /* Caso 1: La lista tiene unicamente un solo elemento y lo quiero borrar  */
    if (node_ant_actual == nullptr && node_sig_actual == nullptr) {
        _first = nullptr;
        _last = nullptr;
        delete node_actual;
    }
    /* Caso 2: Se quiere borrar el primer elemento de la lista  */
    if (node_ant_actual == nullptr && node_sig_actual != nullptr) {
        _first = node_sig_actual;
        node_sig_actual->prev = nullptr;
        delete node_actual;
    }
    /* Caso 3: Se quiere borrar el ultimo elemento de la lista  */
    if (node_ant_actual != nullptr && node_sig_actual == nullptr) {
        _last = node_ant_actual;
        node_ant_actual->next = nullptr;
        delete node_actual;
    }
    /* Caso 4: Se quiere borrar un elemento que no sea ni el primero ni el ultimo de la lista  */
    if (node_ant_actual != nullptr && node_sig_actual != nullptr) {
        node_ant_actual->next = node_sig_actual;
        node_sig_actual->prev = node_ant_actual;
        delete node_actual;
    }
}

int Lista::longitud() const {
    /* Completar */
    int tam = 0;
    Nodo* tmp = _first;
    while (tmp != nullptr){
        tam++;
        tmp = tmp->next;
    }
    return tam;

}

const int& Lista::iesimo(Nat i) const {
    /* Completar */
    Nodo* node_actual = _first;
    while (i > 0){
        i--;
        node_actual = node_actual->next;
    }
    return node_actual->data;
}

int& Lista::iesimo(Nat i) {
    /* Completar (hint: es igual a la anterior...) */
    Nodo* node_actual = _first;
    while (i > 0){
        i--;
        node_actual = node_actual->next;
    }
    return node_actual->data;
}

void Lista::mostrar(ostream& o) {
    /* Completar (opcional) */
    Nodo* actual = _first;
    while (actual != nullptr){
        o << actual->data;
        actual = actual->next;
    }
}


