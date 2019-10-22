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
    if (n->esq != NULL) print(n->esq);
    printPessoa(n->p);
    if (n->dir != NULL) print(n->dir);
}

int rm_dfs(no* raiz, no *n, char *s) {
    if (n == NULL) return 0;
    if (n->esq != NULL && strcmp(n->esq->p.nome, s) == 0) {
        no aux = *n->esq;
        n->esq = NULL;
        if (aux.esq != NULL) adiciona(raiz, aux.esq);
        if (aux.dir != NULL) adiciona(raiz, aux.dir);
        return 1;
    }
    if (n->dir != NULL && strcmp(n->dir->p.nome, s) == 0) {
        no aux = *n->dir;
        n->dir = NULL;
        if (aux.esq != NULL) adiciona(raiz, aux.esq);
        if (aux.dir != NULL) adiciona(raiz, aux.dir);
        return 1;
    }
    return rm_dfs(raiz, n->esq, s) || rm_dfs(raiz, n->dir, s);
}

int remover(no *raiz, char *s) {
    return rm_dfs(raiz, raiz, s);
}
