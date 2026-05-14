#include <iostream>
#include <string.h>

using namespace std;

class Nodo { public:
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
        bool vazio() {
            if(topo == nullptr) {
                return true;
            }
            return false;
        }
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
        bool vazio() {
            if(inicio == nullptr) {
                return true;
            }
            return false;
        }
};

void Pilha::adicionar(char letra) {
    Nodo *novoP = new Nodo;

    if(novoP == nullptr) {
        cout << "Pilha não criada" << endl;
        exit(1);
    }

    novoP -> info = letra;
    novoP -> prox = topo;
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

    if(novoF == nullptr) {
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

char Fila::remover() {
    char letraRem;
    Nodo *aux;

    if(inicio == nullptr) {
        cout << "Fila vazia!" << endl;
        exit(1);
    }

    aux = inicio;
    letraRem = aux -> info;
    inicio = aux -> prox;

    if(inicio == nullptr) {
        fim = nullptr;
    }

    delete aux;
    return letraRem;
}

bool palindromo(Pilha &P, Fila &F, string palavra) {
    for(char c: palavra) {
        P.adicionar(c); // Última letra a entrar é a primeira a sair
        F.adicionar(c); // Primeira letra a entrar é a primeira a sair
    }

    while(!P.vazio() && !F.vazio()) {
        char letraCompP = P.remover();
        char letraCompF = F.remover();

        if(letraCompP != letraCompF) {
            return false;
        }
    }

    return true;
}

int main() {
    Pilha P;
    Fila F;
    string palavra;
    
    cout << "Digite palavra: ";
    cin >> palavra;
    
    if(palindromo(P, F, palavra)) {
        cout << "É palíndromo";
    } else {
        cout << "Não é palíndromo";
    }
    
    return 0;
}
