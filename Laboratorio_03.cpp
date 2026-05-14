#include <iostream>
#include <string.h>

using namespace std;

class Nodo {
    char info;
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
};

void Pilha::adicionar(char letra) {
    Nodo *novoP = new Nodo;
    
    if(novoP == nullptr) {
        cout << "Pilha não criada" << endl;
        exit(1);
    }
    
    novoP -> info = letra;
    novoP -> prox = nullptr;
    topo = novoP;
}

char Pilha::remover() {
    char letraRem;
    Nodo *aux;
    
    if(topo == nullptr) {
        cout << "Pilha vazia!" << endl;
        exit(1);
    }
    
    aux = topo;
    letraRem = aux -> info;
    topo = aux -> prox;
    delete aux;
    return letraRem;
}

void Fila::adicionar(char letra) {
    Nodo *novoF = new Nodo;
    
    if(novoP == nullptr) {
        cout << "Pilha não criada" << endl;
        exit(1);
    }
    
    novoF -> info = letra;
    novoF -> prox = nullptr;
    
    if(inicio == nullptr && fim == nullptr) {
        inicio = fim = novoF;
        return;
    }
    
    fim -> prox = novoF;
    fim = novoF;
}
