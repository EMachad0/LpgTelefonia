#include "std.c"
#include "structs.c"
#include "console.c"
#include "arvore.c"

int main() {
    no *raiz = NULL;

    int tam = 12;
    for (int i = 0; i < tam; i++) {
        no *new = malloc(sizeof(no));

        leString(new->p.nome);
        leString(new->p.email);

        raiz = adiciona(raiz, new);
    }

    print(raiz);
}
