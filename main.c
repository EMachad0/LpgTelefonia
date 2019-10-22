#include "std.c"
#include "structs.c"
#include "arvore.c"
#include "stringhandler.c"

int main() {
    int ordem;;
    while(1){
        // system("clear");
        printf("\n");
        printf("Bem-vindo ao menu, como posso ajudá-lo?\n");
        printf("-> Para sair da agenda digite 0\n");
        printf("-> Para imprimir a agenda digite 1\n");
        printf("-> Para imprimir os dados de determinada pessoa digite 2\n");
        printf("-> Para imprimir os aniversariantes do mês digite 3\n");
        printf("-> Para imprimir os aniversariantes do dia digite 4\n");
        printf("-> Para adicionar novo contato digite 5\n");
        printf("-> Para remover contato digite 6\n");
        printf("\n");
        scanf("%d", &ordem);
        getchar();
        if (ordem == 0) return 0;
        // if (ordem == 1)
        // if (ordem == 2)
        // if (ordem == 3)
        // if (ordem == 4)
        if (ordem == 5){
            while(1){
                printf("Para adicionar novo contato, digite:\n");
                no *raiz = NULL;
                no *new = malloc(sizeof(no));
                // int tam = 3;
                // for (int i = 0; i < tam; i++) {
                // no *new = malloc(sizeof(no));

                printf("Nome: ");

                leString(new->p.nome);
                printf("\nEmail: ");
                leString(new->p.email);
                printf("\n");
                raiz = adiciona(raiz, new);
                print(raiz);
                // }
                printf("\nDeseja retornar ao menu? (0 ou 1) ");
                int resp;
                scanf("%d", &resp);
                getchar();
                if(resp == 0) break;
                // leString(new->p.nome);
                // leString(new->p.email);
                // raiz = adiciona(raiz, new);
                // print(raiz);
            }
            // if (ordem == 6)

        }

    }
    //
    // int tam = 12;
    // for (int i = 0; i < tam; i++) {
    //     no *new = malloc(sizeof(no));
    //
    //     leString(new->p.nome);
    //     leString(new->p.email);
    //
    //     raiz = adiciona(raiz, new);
    // print(raiz);
}
