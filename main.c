#include "std.c"

no* adiciona(no *raiz, no *novo) {
    if (raiz == NULL) {
        // printf("LAIS\n");
        return novo;
    }
    // printf("ELITON\n");
    raiz->next = adiciona(raiz->next, novo);
    // printf("%s\n%s\n", raiz->p.nome, raiz->p.email);
    return raiz;
}

void print(no *n) {
    printf("%s\n%s\n", n->p.nome, n->p.email);
    if (n->next != NULL) print(n->next);
}

int main() {
    no *raiz = NULL;

    int tam = 3;
    for (int i = 0; i < tam; i++) {
        no *novo = malloc(sizeof(no));
        // if (i != 0) printf("NOVO: %s %s\n", novo->p.nome, novo->p.email);

        fflush(stdin);
        scanf("%[^\n]s", novo->p.nome);
        getchar();
        scanf("%[^\n]s", novo->p.email);
        getchar();

        raiz = adiciona(raiz, novo);

        // printf("RAIZ: %s %s\n", raiz->p.nome, raiz->p.email);
    }


    print(raiz);
}
