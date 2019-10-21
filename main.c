#include "std.c"
#include "structs.c"
#include "arvore.c"
#include "stringhandler.c"

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
