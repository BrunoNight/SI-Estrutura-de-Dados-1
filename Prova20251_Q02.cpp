#include <iostream>

using namespace std;

class Nodo { public:
    int info;
    Nodo *prox, *ant;
};

class Lista {
    private:
        Nodo *inicio;
    public:
        Lista() {
            inicio = nullptr;
        }
        void remover_AeS(int valor);
};

void Lista::remover_AeS(int valor) {
    if(inicio == nullptr) {
        cout << "Lista vazia" << endl;
        exit(1);
    }
    
    Nodo *aux = inicio;
    
    while(aux != nullptr) {
        if(aux -> info == valor) {
            Nodo *remAnt = aux -> ant;
            Nodo *remProx = aux -> prox;
            if(remAnt != nullptr) {
                if(remAnt -> ant != nullptr) {
                    remAnt -> ant -> prox = aux;
                    aux -> ant = remAnt -> ant;
                } else {
                    inicio = aux;
                    aux -> ant = nullptr;
                }
            }
            
            if(remProx != nullptr) {
                if(remProx -> prox != nullptr) {
                    remProx -> prox -> ant = aux;
                    aux -> prox = remProx -> prox;
                } else {
                    aux -> prox = nullptr;
                }
            }
            
            if(remAnt != nullptr) {
                delete remAnt;
            }
            
            if(remProx != nullptr) {
                delete remProx;
            }
        } else {
            aux = aux -> prox;
        }
    return;
}
