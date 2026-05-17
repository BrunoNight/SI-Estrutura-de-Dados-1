#include <iostream>
#include <string.h>

using namespace std;

class Nodo { public: // Ok
    char info;
    Nodo *prox;
};

class Lista { // Ok
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

int Lista::tamanho() { // Ok
    int qtNum = 0;
    Nodo *atual;
    atual = inicio;

    while(atual != nullptr) {
        qtNum++;
        atual = atual -> prox;
    }

    return qtNum;
}

void Lista::adicionar(int valor) { // Ok
    Nodo *novo = new Nodo;
    
    if(novo == nullptr) {
        cout << "Espaço não criado!" << endl;
        exit(1);
    }
    
    novo -> info = valor;
    novo -> prox = nullptr;
    
    Nodo *atual;
    atual = inicio;
    
    if(inicio == nullptr) {
        inicio = novo;
        return;
    }
    
    while(atual -> prox != nullptr) {
        atual = atual -> prox;
    }
    
    atual -> prox = novo;
    return;
}

void Lista::inserePos(int valor, int pos) { // Ok
    if(pos == 0) {
        cout << "Posição inválida!" << endl;
        return;
    }
    
    Nodo *novo = new Nodo;
    
    if(novo == nullptr) {
        cout << "Espaço não criado!" << endl;
        exit(1);
    }
    
    novo -> info = valor;
    
    if(inicio == nullptr || pos == 1) {
        novo -> prox = inicio;
        inicio = novo;
        return;
    }
    
    Nodo *atual;
    atual = inicio;
    
    for(int i = 0; i < pos - 2; i++) {
        if(atual -> prox == nullptr) {
            break;
        }
        atual = atual -> prox;
    }
    
    novo -> prox = atual -> prox;
    atual -> prox = novo;
    return;
}

void Lista::retirar(int valor) { // Ok
    if(inicio == nullptr) {
        cout << "Lista vazia!" << endl;
        return;
    }
    
    Nodo *atual, *anterior;
    atual = inicio;
    anterior = nullptr;
    
    while(atual != nullptr && atual -> info != valor) {
        anterior = atual;
        atual = atual -> prox;
    }
    
    if(atual == nullptr) {
        cout << "Elemento não encontrado" << endl;
        return;
    } else if(atual == inicio) {
        inicio = inicio -> prox;
        delete atual;
        return;
    }
    
    anterior -> prox = atual -> prox;
    delete atual;
    return;
}

void Lista::ordenar() { // Ok
    if(inicio == nullptr || inicio -> prox == nullptr) {
        cout << "Sem elementos suficientes para ordenar" << endl;
        return;
    }
    
    Nodo *atual = inicio;
    Nodo *aux = nullptr;
    
    while(atual -> prox != nullptr) {
        aux = atual -> prox;
        
        while(aux != nullptr) {
            if(atual -> info > aux -> info) {
                int temp = atual -> info;
                atual -> info = aux -> info;
                aux -> info = temp;
            }
            aux = aux -> prox;
        }
        atual = atual -> prox;
    }
    
    return;
}

void Lista::imprimir() { // Ok
    if(inicio == nullptr) {
        cout << "Lista vazia!" << endl;
        return;
    }
    
    Nodo *atual;
    atual = inicio;
    
    while(atual != nullptr) {
        cout << atual -> info << " " << endl;
        atual = atual -> prox;
    }
    
    return;
}
