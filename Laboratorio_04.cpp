#include <iostream>

using namespace std

class Nodo { public:
    int info;
    Nodo *prox;
}

class Lista {
    private:
        Nodo *inicio;
    public:
        Lista() {
            inicio = nullptr;
        }
        int tamanho();
        void append(valor);
        void inserePos(valor, pos);
        void retirar(valor);
        void ordena();
        void imprime();
}

void Lista :: append(int valor) {
    Nodo *novo = new Nodo;
    
    if(novo == nullptr) {
        cout << "Espaço não criado!" << endl;
    }
    
    novo -> info = valor;
    novo -> prox = nullptr;
    
    if(inicio == nullptr) {
        inicio = novo;
        return;
    }
    
    inicio -> prox = novo;
    return;
}

//void Lista :: retirar(int valor) {
    if(inicio == nullptr) {
        cout << "Lista vazia!" << endl;
        return;
    }
    
    Nodo *aux;
    
    while(inicio != nullptr) {
        if(valor == inicio -> info) {
            aux = inicio;
            inicio -> prox = prox;
            
        }
    }
    
}

void Lista :: ordenar() {
    if(inicio == nullptr) {
        cout << "Lista vazia!" << endl;
        return;
    }
    
    Nodo *ant, *atual, *aux, *iniX = nullptr;
    
    while(inicio != nullptr) {
        aux = inicio;
        inicio = inicio -> prox;
        atual = iniX;
        if(iniX == nullptr) {
            iniX = aux;
            aux -> prox = nullptr
        } else {
            while(atual != nullptr) {
                ant = atual;
                atual = atual -> prox;
            }
        }
        
        if(atual == iniX) {
            aux -> prox = iniX;
            iniX = aux;
        } else if(atual == nullptr) {
            ant -> prox = aux;
            aux -> prox = nullptr;
        } else {
            ant -> prox = aux;
            aux -> prox = atual;
        }
    }
}

//int Lista :: tamanho() {
    
//}
