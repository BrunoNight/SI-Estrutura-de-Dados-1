#include <iostream>

using namespace std;

class Nodo { public:
    int info;
    Nodo *prox;
};

class Pilha {
    private:
        Nodo *topo;
    public:
        Pilha() {
            topo = nullptr;
        }
        void removerNeg();
};

void Pilha::removerNeg() {
    if(topo == nullptr) {
        cout << "Pilha vazia" << endl;
        exit(1);
    }
    
    Pilha PAux;
    
    while(topo != nullptr) {
        Nodo *remover = topo;
        if(topo -> info >= 0) {
            topo = topo -> prox;
            remover -> prox = PAux.topo;
            PAux.topo = remover;
        } else {
            topo = topo -> prox;
            delete remover;
        }
    }
    
    while(PAux.topo != nullptr) {
        Nodo *aux = PAux.topo;
        PAux.topo = PAux.topo -> prox;
        aux -> prox = topo;
        topo = aux;
    }
    
    return;
}