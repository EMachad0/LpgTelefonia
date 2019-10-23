no* adiciona(no *nodo, no *new) {
    if (nodo == NULL) return new;
    if (strcmp(new->p.nome, nodo->p.nome) < 0) {
        nodo->esq = adiciona(nodo->esq, new);
    } else {
        nodo->dir = adiciona(nodo->dir, new);
    }
    return nodo;
}

void print(no *n) {
    if (n == NULL) return;
    if (n->esq != NULL) print(n->esq);
    printPessoa(n->p);
    if (n->dir != NULL) print(n->dir);
}

no* findMin(no *nodo) {
    if (nodo->esq != NULL) return findMin(nodo->esq);
    else return nodo;
}

no* remover(no *nodo, char *s) {
    if (nodo == NULL) return nodo;
    else if (strcmp(nodo->p.nome, s) > 0) nodo->esq = remover(nodo->esq, s);
    else if (strcmp(nodo->p.nome, s) < 0) nodo->dir = remover(nodo->dir, s);
    else {
        if (nodo->esq == NULL && nodo->dir == NULL) {
            free(nodo);
            nodo = NULL;
        } else if (nodo->esq == NULL) {
            no *aux = nodo;
            nodo = nodo->dir;
            free(aux);
        } else if (nodo->dir == NULL) {
            no *aux = nodo;
            nodo = nodo->esq;
            free(aux);
        } else {
            no *mi = findMin(nodo->dir);
            nodo->p = mi->p;
            nodo->dir = remover(nodo->dir, mi->p.nome);
        }
    }
    return nodo;
}

void achaPessoa(no *nodo, char *s){
    if (nodo == NULL){
        printf("Pessoa não encontrada\n");
        return;
    }
    else if (strcmp(nodo->p.nome, s) == 0){
        printPessoa(nodo->p);
    }
    else if (nodo->esq != NULL) {
        if (strcmp(nodo->p.nome, s) > 0) achaPessoa(nodo->esq, s);
    }
    else if (nodo->dir != NULL) {
        if (strcmp(nodo->p.nome, s) < 0) achaPessoa(nodo->dir, s);
    }
}
