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
        void retirarRepetidos(Lista &L);
}

void Lista::retirarRepetidos(Lista &L) {
    if(L.inic == nullptr) {
        cout << "Lista vazia" << endl;
        return;
    }
    
    Nodo *atual = L.inic;
    Nodo *aux;
    Nodo *ant;
    
    while(atual != nullptr) {
        aux = atual -> prox;
        ant = atual;
        while(aux != nullptr) {
            Nodo *remover = aux;
            if(atual -> info == aux -> info) {
                aux = aux -> prox;
                ant -> prox = aux;
                delete remover;
            } else {
                ant = aux;
                aux = aux -> prox;
            }
        }
        atual = atual -> prox;
    }
    
    return;
}
