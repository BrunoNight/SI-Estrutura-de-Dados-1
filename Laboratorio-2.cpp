#include <iostream>
#include <random>

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
        void adicionar(int senha);
        void remover();
        void imprimir();
};

void Fila::adicionar(int senha) {
    Nodo *aux;
    aux = new Nodo;
    
    if(aux == nullptr) {
        std::cout << "Espaço de memória não alocado!" << std::endl;
        return;
    }
    
    aux -> info = senha;
    aux -> prox = nullptr;
    
    if(inicio == nullptr) {
        inicio = aux;
    } else {
        fim -> prox = aux;
    }
    
    fim = aux;
}

void Fila::remover() {
    Nodo *aux;
    
    if(inicio == nullptr) {
        std::cout << "Fila vazia!";
    }
    
    aux = inicio;
    inicio = inicio -> prox;
    delete aux;
}

void gerir(Fila &P, Fila &C, int &contP, int &contC) {
    int idade;
    idade = rand() % 100 + 1;
    
    if(idade >= 60) {
        P.adicionar(contP);
        contP++;
    } else {
        C.adicionar(contC);
        contC++;
    }
}

int main() {
    Fila P, C;
    int contC, contP;
    int contAtender = 0;
    
    contC = contP = 1;
    
    srand(time(NULL));
    
    if(contP % 3 != 0) { // WHILE ENQUANTO TIVER PESSOAS NA FILA E FUNÇÃO PARA ADMINISTRAR REMOÇÃO DE PESSOAS DA FILA?
        
    }
    
    
    
    
    
    
    
    
    
    
    
    if(contP <= 3 || contC <= 1) {
        gerir(P, C, contP, contC);
    } else {
        contC = cont P = 1;
    }
    
}
