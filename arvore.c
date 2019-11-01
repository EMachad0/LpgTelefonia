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
    printNome(n->p);
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
    } else if (nodo->esq != NULL && strcmp(nodo->p.nome, s) > 0) achaPessoa(nodo->esq, s);
    else if (nodo->dir != NULL && strcmp(nodo->p.nome, s) < 0) achaPessoa(nodo->dir, s);
    else printPessoa(nodo->p);
}

void achaMes(no *nodo, int *m, int *flag){
    if (nodo == NULL){
        printf("Pessoa não encontrada\n");
        return;
    }
    if (nodo->p.nasci.mes == *m){
        printNome(nodo->p);
        *flag = 1;
    }
    if (nodo->esq != NULL) achaMes(nodo->esq, m, flag);
    if(nodo->dir != NULL) achaMes(nodo->dir, m, flag);
}

void achaDia(no *nodo, int *m, int *dia, int *flag){
    if (nodo == NULL){
        printf("Pessoa não encontrada\n");
        return;
    }
    if (nodo->p.nasci.mes == *m && nodo->p.nasci.dia == *dia){
        printNome(nodo->p);
        *flag = 1;
    }
    if (nodo->esq != NULL) achaDia(nodo->esq, m, dia, flag);
    if(nodo->dir != NULL) achaDia(nodo->dir, m, dia, flag);
}
