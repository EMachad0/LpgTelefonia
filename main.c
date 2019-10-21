#include "std.c"

no* adiciona(no *raiz, no *novo) {
    if (raiz == NULL) return novo;
    raiz->next = adiciona(raiz->next, novo);
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

        fflush(stdin);
        scanf("%[^\n]s", novo->p.nome);
        getchar();
        scanf("%[^\n]s", novo->p.email);
        getchar();

        raiz = adiciona(raiz, novo);
    }


    print(raiz);
}
