#include <iostream>

using namespace std;

class Nodo { public:
    int info;
    Nodo *prox, *ant;
};

class ListaDupla {
    private:
        Nodo *inic;
    public:
        ListaDupla() {
            inic = nullptr;
        }
        void adicionar(int n);
        void remover();
        void imprimir();
};

void ListaDupla::adicionar(int n) {
    Nodo *novo = new Nodo;
    if(novo == nullptr) exit(1);
    novo -> info = n;
    novo -> prox = nullptr;
    if(inic == nullptr) {
        novo -> ant = nullptr;
        inic = novo;
        return;
    }
    Nodo *atual = inic;
    while(atual -> prox != nullptr) {
        atual = atual -> prox;
    }
    atual -> prox = novo;
    novo -> ant = atual;
    return;
}

void ListaDupla::remover() {
    if(inic == nullptr) {
        cout << "Não há o que remover" << endl;
        return;
    }
    Nodo *atual = inic;
    while(atual -> prox != nullptr) {
        atual = atual -> prox;
    }
    if(atual == inic) {
        inic = nullptr;
    } else {
        atual -> ant -> prox = atual -> prox;
    }
    delete atual;
    return;
}

void ListaDupla::imprimir() {
    if(inic == nullptr) {
        cout << "Não há o que imprimir" << endl;
        return;
    }
    Nodo *atual = inic;
    while(atual != nullptr) {
        cout << atual -> info << endl;
        atual = atual -> prox;
    }
    return;
}
