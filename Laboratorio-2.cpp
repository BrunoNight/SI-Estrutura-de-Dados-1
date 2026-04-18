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
        return;
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

    contC = contP = 0;

    srand(time(NULL));

    // Sessão para adicionar clientes à fila
    for(int i = 0; i < 10; i++) {
        gerir(P, C, contP, contC);
    }

    // Sessão para atender clientes
    while(contC > 0 || contP > 0) {
        for(int i = 0; i < 3; i++) {
            if(contP > 0) {
                cout << "Prioritário atendido" << endl;
                P.remover();
                contP--;
            } else {
                break;
            }
        }

        if(contC > 0) {
            cout << "Comum atendido" << endl;
            C.remover();
            contC--;
        }
    }

    return 0;
}
