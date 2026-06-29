bool Arvore::arvoresIguais(NodoA* raizA, NodoA* raizB) {
    if(raizA == nullptr && raizB == nullptr) {
        return true;
    }
    
    if((raizA == nullptr && raizB != nullptr) || (raizB == nullptr && raizA != nullptr)) {
        return false;
    }
    
    if(raizA -> info != raizB -> info) {
        return false;
    } else {
        return arvoresIguais(raizA -> esq, raizB -> esq) && arvoresIguais(raizA -> dir, raizB -> dir);
    }
}

// ou

bool Arvore::arvoresIguais(NodoA* raizA, NodoA* raizB) {
    // 1. Se ambos são nulos, são idênticos
    if (raizA == nullptr && raizB == nullptr) return true;
    
    // 2. Se um é nulo e o outro não, ou se os valores diferem, são diferentes
    if (raizA == nullptr || raizB == nullptr || raizA->info != raizB->info) {
        return false;
    }
    
    // 3. Verifica recursivamente ambos os lados
    return arvoresIguais(raizA->esq, raizB->esq) && 
           arvoresIguais(raizA->dir, raizB->dir);
}
