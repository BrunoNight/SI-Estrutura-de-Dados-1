#include <iostream>

using namespace std;

class Nodo { public:
    int info;
    Nodo *prox;
};

class Fila {
    private:
        Nodo *inic;
        Nodo *fim;
    public:
        Fila() {
            inic = nullptr;
            fim = nullptr;
        }
        void adicionar(int n);
        void remover();
        void imprimir();
};

void Fila::adicionar(int n) {
    Nodo *novo = new Nodo;
    if(novo == nullptr) exit(1);
    novo -> info = n;
    novo -> prox = nullptr;
    if(inicio == nullptr) {
        inicio = novo;
        fim = novo;
    } else {
        fim -> prox = novo;
        fim = novo;
    }
    return;
}

void Fila::remover() {
    if(inicio == nullptr) exit(1);
    Nodo *aux = inicio;
    inicio = inicio -> prox;
    delete aux;
    return;
}

void Fila::imprimir() {
    if(inicio == nullptr) exit(1);
    Nodo *aux = inicio;
    while(aux != nullptr) {
        cout << aux -> info << endl;
        aux = aux -> prox;
    }
    return;
}
