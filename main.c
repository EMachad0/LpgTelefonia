#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.c"
#include "console.c"
#include "arvore.c"
#include "banco.c"

no *raiz = NULL;

void add_contato(){
    printf("Para adicionar novo contato, digite:\n");
    no *new = malloc(sizeof(no));
    //nome, email e endereço
    printf("Nome:\n");
    leString(new->p.nome);
    printf("Email:\n");
    leString(new->p.email);
    printf("País:\n");
    leString(new->p.adre.pais);
    printf("Estado:\n");
    leString(new->p.adre.estado);
    printf("Cidade:\n");
    leString(new->p.adre.cidade);
    printf("Bairro:\n");
    leString(new->p.adre.bairro);
    printf("Rua:\n");
    leString(new->p.adre.rua);
    printf("Numero:\n");
    leInt(&new->p.adre.numero);
    printf("CEP:\n");
    leInt(&new->p.adre.cep);
    printf("Complemento:\n");
    leString(new->p.adre.complemento);
    // telefone
    printf("Código nacional:\n");
    leInt(&new->p.tele.cod_nacional);
    printf("Código de área:\n");
    leInt(&new->p.tele.cod_area);
    printf("Número:\n");
    leInt(&new->p.tele.num);
    // nascimento
    printf("Data de nascimento:\n");
    printf("Dia:\n");
    leInt(&new->p.nasci.dia);
    printf("Mês:\n");
    leInt(&new->p.nasci.mes);
    printf("Ano:\n");
    leInt(&new->p.nasci.ano);
    // obs
    printf("Observação:\n");
    leString(new->p.obs);
    new->esq = NULL;
    new->dir = NULL;

    raiz = adiciona(raiz, new);
}
// __fpluerg

void salva_programa() {
    FILE *f = fopen("./banco.txt", "wb");
    salvaBanco(raiz, f);
    fclose(f);
    exit(0);
}

void print_agenda(){
    printf("Lista de contatos completa:\n");
    print(raiz);
}

void remove_contato(){
    char s[100005];
    leString(s);
    raiz = remover(raiz, s);
}

void print_dados(){
    char s[100005];
    leString(s);
    achaPessoa(raiz, s);
}

void print_niverMes(){
    int mes, flag = 0;
    printf("Digite o mês que deseja procurar:\n");
    leInt(&mes);
    achaMes(raiz, &mes, &flag);
    if (flag == 0) printf("Nenhum aniversariante nesse mês\n");
}

void print_niverDia(){
    int mes, dia, flag = 0;
    printf("Digite o dia e mês que deseja procurar:\n");
    leInt(&mes);
    leInt(&dia);
    achaDia(raiz, &mes, &dia, &flag);
    if (flag == 0) printf("Nenhum aniversariante nesse dia\n");
}

int main() {
    FILE *f = fopen("./banco.txt", "rb");
    raiz = leBanco(raiz, f);
    fclose(f);

    while(1){
        int ordem = -1;
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
        if (ordem == 0) salva_programa();
        else if (ordem == 1) add_contato();
        else if (ordem == 2) remove_contato();
        else if (ordem == 3) print_agenda();
        else if (ordem == 4) print_dados();
        else if (ordem == 5) print_niverMes();
        else if (ordem == 6) print_niverDia();
        else printf("Digite novamente\n");
    }
}
