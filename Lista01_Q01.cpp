#include <iostream>

using namespace std;

class Nodo { public:
    int num;
    Nodo *prox;
};

class Lista {
    private:
        Nodo *inic;
    public:
        Lista() {
            inic = nullptr;
        }
        void adicionar(int num);
        bool ehPrimo(int n);
        void remov_IPOD();
        void removerPares();
}

void Lista::adicionar(int num) {
    Nodo *novo = new Nodo;
    
    if(novo == nullptr) {
        cout << "Espaço não criado" << endl;
        return;
    }
    
    novo -> num = num;
    
    if(inic == nullptr) {
        novo -> prox = nullptr;
        inic = novo;
        return;
    }
    
    if(num < inic -> num) {
        novo -> prox = inic;
        inic = novo;
        return;
    }
    
    Nodo *atual = inic;
    
    while(atual -> prox != nullptr && num > atual -> prox -> num) {
        atual = atual -> prox;
    }
    
    novo -> prox = atual -> prox;
    atual -> prox = novo;
    return;
}

bool Lista::ehPrimo(int n) {
    if(n < 2) { return false; }
    if(n == 2) { return true; }
    if(n % 2 = 0) { return false; }
    for(int i = 2; i < n; i++) {
        if(n % i == 0) { return false; }
    }
    return true;
}

void Lista::remov_IPOD() {
    if(inic == nullptr) {
        cout << "Não há elementos para remover" << endl;
        return;
    }
    
    Nodo *atual = inic;
    Nodo *anterior = nullptr;
    
    while(atual != nullptr) {
        if(atual -> num % 2 != 0 && ehPrimo(atual -> num)) {
            Nodo *remover = atual;
            if(anterior == nullptr) { // Primeiro elemento a ser removido
                inic = inic -> prox;
            } else { // Elemento a ser removido do meio/fim
                anterior -> prox = atual -> prox;
            }
            atual = atual -> prox;
            delete remover;
        } else {
            anterior = atual;
            atual = atual -> prox;
        }
    }
    
    if(inic == nullptr) {
        cout << "Lista esvaziou, impossível ordenar decrescente" << endl;
        return;
    }
    
    atual = inic;
    
    while(atual != nullptr) {
        aux = atual -> prox;
        while(aux != nullptr) {
            if(atual -> num < aux -> num) {
                int temp = atual -> num;
                atual -> num = aux -> num;
                aux -> num = temp;
            }
            aux = aux -> prox;
        }
        atual = atual -> prox;
    }
}

void Lista::removerPares() {
    if(inic == nullptr) {
        cout << "Não há elementos para remover" << endl;
        return;
    }
    
    Nodo *atual = inic;
    Nodo *ant = nullptr
    
    while(atual != nullptr) {
        Nodo *remover = atual;
        if(atual -> num % 2 == 0) {
            if(ant == nullptr) {
                inic = inic -> prox
            } else {
                anterior -> prox = atual -> prox;
            }
            atual = atual -> prox;
            delete remover;
        } else {
            ant = atual;
            atual = atual -> prox;
        }
    }
}
