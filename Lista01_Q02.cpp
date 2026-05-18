#include <iostream>

using namespace std;

class Nodo { public:
    int info;
    Nodo *prox;
};

class Lista {
    private:
        Nodo *inic;
    public:
        Lista() {
            inic = nullptr;
        }
        Lista ordenar(Lista &L);
};

Lista Lista::ordenar(Lista &L) {
    if(L.inic == nullptr) {
        cout << "Lista vazia" << endl;
        return L;
    }
    
    Nodo *atual = L.inic;
    Nodo *aux;
    
    while(atual != nullptr) {
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
    
    return L;
}
