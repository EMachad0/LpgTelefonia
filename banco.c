
void salvaBanco(no *nodo, FILE *f) {
    if (nodo == NULL) return;
    fwrite(nodo, sizeof(no), 1,  f);
    salvaBanco(nodo->esq, f);
    salvaBanco(nodo->dir, f);
}

no* leBanco(no *raiz, FILE *f) {
    while (1) {
        no *novo = malloc(sizeof(no));
        fread(novo, sizeof(no), 1, f);
        if (feof(f)) break;
        novo->esq = NULL;
        novo->dir = NULL;
        raiz = adiciona(raiz, novo);
    }
    return raiz;
}
