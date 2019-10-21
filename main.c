#include "std.c"
#include "structs.c"
#include "arvore.c"

int main() {
    no *raiz = NULL;

    int tam = 12;
    for (int i = 0; i < tam; i++) {
        no *new = malloc(sizeof(no));

        fflush(stdin);
        scanf("%[^\n]s", new->p.nome);
        getchar();
        scanf("%[^\n]s", new->p.email);
        getchar();

        raiz = adiciona(raiz, new);
    }

    print(raiz);
}
