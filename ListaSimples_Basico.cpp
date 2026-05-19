#include <iostream>

using namespace std;

class Nodo { public:
    int info;
    Nodo *prox;
};

class Lista {
    private:
        Nodo *inic;
    public:
        Lista() {
            inic = nullptr;
        }
        void adicionar(int n);
        void remover();
        void imprimir();
};

void Lista::adicionar(int n) {
    Nodo *novo = new Nodo;
    if(novo == nullptr) exit(1);
    novo -> info = n;
    novo -> prox = nullptr;
    if(inic == nullptr) {
        inic = novo;
        return;
    }
    Nodo *aux = inic;
    while(aux -> prox != nullptr) {
        aux = aux -> prox;
    }
    aux -> prox = novo;
    return;
}

void Lista::remover() {
    if(inic == nullptr) {
        cout << "Não há o que remover" << endl;
        return;
    }
    Nodo *aux = inic;
    Nodo *ant = nullptr;
    while(aux -> prox != nullptr) {
        ant = aux;
        aux = aux -> prox;
    }
    if(ant == nullptr) {
        inic = nullptr;
    } else {
        ant -> prox = nullptr;
    }
    delete aux;
    return;
}

void Lista::imprimir() {
    if(inic == nullptr) {
        cout << "Não há o que imprimir" << endl;
        return;
    }
    Nodo *aux = inic;
    while(aux != nullptr) {
        cout << aux -> info << endl;
        aux = aux -> prox;
    }
    return;
}
