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
        void adicionar(int n);
        void remover();
        void imprimir();
};

void Pilha::adicionar(int n) {
    Nodo *novo = new Nodo;
    if(novo == nulptr) exit(1);
    novo -> prox = topo;
    topo = novo;
    return;
}

void Pilha::remover() {
    Nodo *aux = topo;
    topo = topo -> prox;
    delete aux;
}

void Pilha::imprimir() {
    Nodo *aux = topo;
    while(aux != nullptr) {
        cout << aux -> info << endl;
        aux = aux -> prox;
    }
    return;
}
