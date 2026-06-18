int Arvore::altura(Nodo *raiz) {
    if(raiz == nullptr) {
        return -1;
    }
    int alturaEsq = altura(raiz -> e);
    int alturaDir = altura(raiz -> d);
    
    if(alturaEsq > alturaDir) {
        return alturaEsq + 1;
    } else {
        return alturaDir + 1;
    }
}
