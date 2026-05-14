#include <iostream>
#include <string.h>

using namespace std;

class Nodo { public:
    char info;
    Nodo *prox;
};

class Lista {
    private:
        Nodo *inicio;
    public:
        Lista() {
            inicio = nullptr;
        }
        int tamanho();
        void adicionar(int valor);
        void inserePos(int valor, int pos);
        void retirar(int valor);
        void ordenar();
        void imprimir();
}

int Lista::tamanho() {
    int qtNum = 0;
    Nodo *atual;
    
    if(inicio == nullptr) {
        return qtNum;
    }
    
    atual = inicio;
    
    while(atual != nullptr) {
        if(atual == nullptr) {
            break;
        }
        qtNum++;
        atual = atual -> prox;
    }
    
    return qtNum;
}
