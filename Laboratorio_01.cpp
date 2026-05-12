#include <iostream>

using namespace std;

class Nodo { public:
    int info;
    Nodo *prox;
};

class Pilha {
    private:
        Nodo *topo;
    public:
        Pilha();
        void empilhar(int bi);
        int desempilhar();
        void imprimir();
};

Pilha::Pilha() {
    topo = nullptr;
}

void Pilha::empilhar(int bi) {
    Nodo *novaPilha;
    novaPilha = new Nodo;
    if(novaPilha == nullptr) {
        cout << "Pilha não alocada no heap!";
        exit(1);
    }
    novaPilha -> info = bi;
    novaPilha -> prox = topo;
    topo = novaPilha;
}

int Pilha::desempilhar() {
    int n;
    Nodo *aux;
    if(topo == nullptr) {
        cout << "Pilha vazia!";
        return -1;
    }
    aux = topo;
    topo = aux -> prox;
    n = aux -> info;
    delete aux;
    return n;
}

void Pilha::imprimir() {
    Nodo *auxImp;
    if(topo == nullptr) {
        cout << "Pilha vazia!";
        exit(1);
    }
    auxImp = topo;
    while(auxImp != nullptr) {
        cout << auxImp -> info << " ";
        auxImp = auxImp -> prox;
    }
    cout << endl;
    return;
}

int main()
{
    int n;
    Pilha P;

    cout << "Digite um valor para ser convertido para binário: ";
    cin >> n;

    int valorOriginal = n;
    int qtVezesDiv = 0;

    while(n > 0) {
        int bi;
        bi = n % 2;
        P.empilhar(bi);
        n /= 2;
        qtVezesDiv++;
    }
    P.imprimir();
    
    int binPNum = 0;
    cout << "Retornando binário para número decimal" << ": ";
    for(int i = 0; i < qtVezesDiv; i++) {
    	int numDesempilhado;
    	numDesempilhado = P.desempilhar();
    	
    	binPNum = (binPNum * 2) + numDesempilhado;
	}
	cout << "" << binPNum << endl;
    
    return 0;
}

