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
    printf("%s %s\n", n->p.nome, n->p.email);
    if (n->dir != NULL) print(n->dir);
}