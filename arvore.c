no* adiciona(no *nodo, no *new) {
    if (nodo == NULL) return new;
    if (minString(new->p.nome, nodo->p.nome)) {
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
    else if (minString(nodo->p.nome, s)) nodo->esq = remover(nodo->esq, s);
    else if (minString(nodo->p.nome, s)) nodo->dir = remover(nodo->dir, s);
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
    } else if (nodo->esq != NULL) {
        if (minString(nodo->p.nome, s)) achaPessoa(nodo->esq, s);
    } else if (nodo->dir != NULL) {
        if (minString(nodo->p.nome, s)) achaPessoa(nodo->dir, s);
    } else {
        printPessoa(nodo->p);
    }
}

void achaMes(no *nodo, int *m, int *flag){
    if (nodo == NULL){
        printf("Pessoa não encontrada\n");
        return;
    }
    if (nodo->p.nasci.mes == *m){
        printPessoa(nodo->p);
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
        printPessoa(nodo->p);
        *flag = 1;
    }
    if (nodo->esq != NULL) achaDia(nodo->esq, m, dia, flag);
    if(nodo->dir != NULL) achaDia(nodo->dir, m, dia, flag);
}
