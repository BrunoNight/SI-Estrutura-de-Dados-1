#include <iostream>
#include <string.h>

using namespace std;

class Nodo {
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
        void adicionar(char letra);
        char remover();
        void imprimir();
};

class Fila {
    private:
        Nodo *inicio;
        Nodo *fim;
    public:
        Fila() {
            inicio = nullptr;
            fim = nullptr;
        }
        void adicionar(char letra);
        char remover();
        void imprimir();
}
