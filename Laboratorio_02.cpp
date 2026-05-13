#include <iostream>
#include <random>

using namespace std;

class Nodo { public:
    int info;
    Nodo *prox;
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
        void inserir(int senha);
        void remover();
};

void Fila::inserir(int contador) {
    Nodo *novo = new Nodo;
    if(novo == nullptr) {exit(1);}
    
    novo -> info = contador;
    novo -> prox = nullptr;
    
    if(inicio == nullptr) {
        inicio = fim = novo;
        return;
    }
    
    fim -> prox = novo;
    fim = novo;
}

void Fila::remover() {
    Nodo *aux;
    
    if(inicio == nullptr) {
        return;
    }
    
    aux = inicio;
    inicio = inicio -> prox;
    
    if(inicio == nullptr) {
        fim = nullptr;
    }
    
    delete aux;
    return;
}

void gerir(Fila &P, Fila &C, int &contP, int &contC, int &senha) {
    int idade;
    idade = rand() % 100 + 1;
    
    if(idade >= 60) {
        P.inserir(contP);
        contP++;
    } else {
        C.inserir(contC);
        contC++;
    }
    
    senha++;
    return;
}

int main() {
    srand(time(0));
    
    Fila P, C;
    int contP, contC;
    int senha;
    
    contP = contC = 0;
    senha = 0;
    
    for(int i = 0; i < 20; i++) {
        gerir(P, C, contP, contC, senha);
    }
    
    while(contP > 0 || contC > 0) {
        for(int i = 0; i < 3; i++) {
            if(contP == 0) {
                break;
            }
            P.remover();
            contP--;
        }
        
        if(contC > 0) {
            contC--;
        }
    }
    
    cout << "Senhas geradas: " << senha;
    
    return 0;
}
