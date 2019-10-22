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

int remover(no *n, char *s) {
    if (n == NULL) return 0;
    if (strcmp(n->p.nome, s) == 0) {

        return 1;
    }
    return remover(n->esq, s) || remover(n->dir, s);
}
