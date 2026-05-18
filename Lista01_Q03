#include <iostream>
#include <string>

using namespace std;

class Nodo { public:
    int cod;
    string nome;
    Nodo *prox;
};

class Lista {
    private:
        Nodo *inic;
    public:
        Lista() {
            inic = nullptr
        }
        Lista fundirListas(Lista &A, Lista &B);
};

Lista Lista:fundirListas(Lista &A, Lista &B) {
    Lista Final;
    if(A.inic == nullptr && B.inic == nullptr) {
        cout << "Listas vazias" << endl;
        exit(1);
    } else if(A.inic == nullptr) {
        cout << "Lista A vazia" << endl;
        Final = B;
        return Final;
    } else if(B.inic == nullptr) {
        cout << "Lista B vazia" << endl;
        Final = A;
        return Final;
    }
    
    Nodo *atualA = A.inic;
    Nodo *atualB = B.inic;
    Nodo *atualF = nullptr;
    
    if(atualA -> cod < atualB -> cod) {
        Final.inic = atualA;
        atualA = atual -> prox;
    } else {
        Final.inic = atualB;
        atualB = atual -> prox;   
    }
    atualF = Final.inic;
    
    while(atualA != nullptr && atualB != nullptr) {
        if(atualA -> cod < atualB -> cod) {
            atualF -> prox = atualA;
            atualF = atualF -> prox;
            atualA = atualA -> prox;
        } else {
            atualF -> prox = atualB;
            atualF = atualF -> prox;
            atualB = atualB -> prox;
        }
    }
    
    if(atualA == nullptr) {
        atualF -> prox = atualB;
    } else {
        atualF -> prox = atualA;
    }
    
    atualA = nullptr;
    atualB = nullptr;
    
    return Final;
}
