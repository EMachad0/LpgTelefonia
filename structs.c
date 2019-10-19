#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 500
#define TAM_AGENDA 1

// typedef struct pessoa pessoa;

struct adress{
    char rua[TAM];
    char bairro[TAM];
    char cidade[TAM];
    char estado[TAM];
    char pais[TAM];
    int numero;
    int cep;
    int complemento;
};

struct telefone{
    int cod_nacional;
    int cod_area;
    int num;
};

struct pessoa{
    char nome[TAM];
    char email[TAM];
    // char obs[TAM];
    // struct adress;
    // struct telefone;
    // struct nascimento;
}agenda[TAM_AGENDA];

// void preencher_agenda(struct pessoa agenda){
//     for(int i = 0; i < TAM_AGENDA; i++){
//         scanf("%[^\n]s", agenda[i].nome);
//         fflush(stdin);
//         scanf("%[^\n]s", agenda[i].email);
//     }
// }

int main(){
    // struct pessoa agenda[TAM_AGENDA];
    // preencher_agenda(agenda);
    for(int i = 0; i < TAM_AGENDA; i++){
        scanf("%s", agenda[i].nome);
        fflush(stdin);
        scanf("%s", agenda[i].email);
    }

    for(int i = 0; i < TAM_AGENDA; i++){
        printf("nome: %s, email: %s\n", agenda[i].nome, agenda[i].email);
    }
}
