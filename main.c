#include "std.c"
#include "structs.c"
#include "console.c"
#include "arvore.c"

int main() {
    no *raiz = NULL;
    while(1){
        int ordem;
        printf("\n");
        printf("Bem-vindo ao menu, como posso ajudá-lo?\n");
        printf("0 -> Para sair da agenda digite 0\n");
        printf("1 -> Para adicionar novo contato digite 1\n");
        printf("2 -> Para remover contato digite 2\n");
        printf("3 -> Para imprimir a agenda digite 3\n");
        printf("4 -> Para imprimir os dados de determinada pessoa digite 4\n");
        printf("5 -> Para imprimir os aniversariantes do mês digite 5\n");
        printf("6 -> Para imprimir os aniversariantes do dia digite 6\n");
        printf("\n");
        leInt(&ordem);
        if (ordem == 0) return 0;
        else if (ordem == 1){
            printf("Para adicionar novo contato, digite:\n");
            no *new = malloc(sizeof(no));
            printf("Nome:\n");
            leString(new->p.nome);
            printf("Email:\n");
            leString(new->p.email);
            raiz = adiciona(raiz, new);
        }
        // else if (ordem == 2)
        else if (ordem == 3) print(raiz);
        // else if (ordem == 4)
        // else if (ordem == 5)
        // else if (ordem == 6)
        else printf("Digite novamente\n");
    }
}
