#include <iostream>
#include <string>

using namespace std;

class Nodo { public:
    string palavra;
    Nodo *prox;
    Nodo *ant;
};

class Frase {
    private:
        Nodo *inic;
        Nodo *fim;
        Nodo *atual;
    public:
        Frase() {
            inic = nullptr;
            fim = nullptr;
            atual = nullptr;
        }
        void inserir(string p);
        void corrigir(string p);
        void remover(string p);
        void palavraAnt();
        void palavraPos();
};

void Frase::inserir(string p) {
    Nodo *novo = new Nodo;
    
    if(novo == nullptr) {
        cout << "Espaço não criado" << endl;
        return;
    }
    
    novo -> palavra = p;
    
    if(inic == nullptr) {
        novo -> prox = nullptr;
        novo -> ant = nullptr;
        inic = novo;
        fim = inic;
        atual = inic;
        return;
    }
    
    novo -> prox = atual -> prox;
    novo -> ant = atual;
    
    if(atual -> prox != nullptr) {
        atual -> prox -> ant = novo;
    } else {
        fim = novo;
    }
    
    atual -> prox = novo;
    atual = novo;
    return;
}

void Frase::corrigir(string p) {
    atual -> palavra = p;
}

void Frase::retirar() {
    if(inic == nullptr) {
        cout << "Não há frase" << endl;
        return;
    } 
    
    Nodo *remover = atual;
    
    if(inic == fim) {
        inic = nullptr;
        fim = nullptr;
        atual = nullptr;
        delete remover;
        return;
    }
    
    if(atual == inic) {
        inic = inic -> prox;
        inic -> ant = nullptr;
        atual = inic;
    } else if(atual == fim) {
        fim = fim -> ant;
        fim -> prox = nullptr;
        atual = fim;
    } else {
        atual -> ant -> prox = atual -> prox;
        atual -> prox -> ant = atual -> ant;
        atual = atual -> prox;
    }
    
    delete remover;
    return;
}