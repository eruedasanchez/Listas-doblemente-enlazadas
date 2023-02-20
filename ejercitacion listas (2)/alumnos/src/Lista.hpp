#include "Lista.h"

Lista::Lista() {
    // Completar
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    // Completar
}

Lista& Lista::operator=(const Lista& aCopiar) {
    // Completar
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    // Completar
}

void Lista::agregarAtras(const int& elem) {
    // Completar
}

void Lista::eliminar(Nat i) {
    // Completar
}

int Lista::longitud() const {
    // Completar
    return -1;
}

const int& Lista::iesimo(Nat i) const {
    // Completar
    assert(false);
}

int& Lista::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    assert(false);
}

void Lista::mostrar(ostream& o) {
    // Completar
}
