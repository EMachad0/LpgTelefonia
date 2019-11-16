#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100005

// Structs
typedef struct{
    char rua[TAM];
    char bairro[TAM];
    char cidade[TAM];
    char estado[TAM];
    char pais[TAM];
    int numero;
    int cep;
    char complemento[TAM];
} adress;

typedef struct{
    int cod_nacional;
    int cod_area;
    int num;
} telefone;

typedef struct{
    int dia;
    int mes;
    int ano;
} nascimento;

typedef struct{
    char nome[TAM];
    char email[TAM];
    char obs[TAM];
    adress adre;
    telefone tele;
    nascimento nasci;
} pessoa;

typedef struct no{
    pessoa p;
    struct no* esq;
    struct no* dir;
} no;

// Menu
void add_contato();
void salva_programa();
void print_agenda();
void remove_contato();
void print_dados();
void print_niverMes();
void print_niverDia();

// Console Interation
void leString(char *s);
void printNome(pessoa p);
void printPessoa(pessoa p);
void leInt(int *n);

// Arquivo
void salvaBanco(no *nodo, FILE *f);
no* leBanco(no *raiz, FILE *f);

// Arvore
no* adiciona(no *nodo, no *new);
void print(no *n);
no* findMin(no *nodo);
no* remover(no *nodo, char *s);
void achaPessoa(no *nodo, char *s);
void achaMes(no *nodo, int *m, int *flag);
void achaDia(no *nodo, int *m, int *dia, int *flag);

no *raiz = NULL;

int main() {
    FILE *f = fopen("./banco.txt", "rb");
    if (f != NULL) {
        raiz = leBanco(raiz, f);
        fclose(f);
    }

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

// Menu
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
    printf("Número de telefone:\n");
    leInt(&new->p.tele.num);
    // nascimento
    printf("Data de nascimento (dd/mm/aaaa)\n");
    printf("Dia(dd):\n");
    leInt(&new->p.nasci.dia);
    printf("Mês(mm):\n");
    leInt(&new->p.nasci.mes);
    printf("Ano(aaaa):\n");
    leInt(&new->p.nasci.ano);
    // obs
    printf("Observação:\n");
    leString(new->p.obs);
    new->esq = NULL;
    new->dir = NULL;

    raiz = adiciona(raiz, new);
}

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
    leInt(&dia);
    leInt(&mes);
    achaDia(raiz, &mes, &dia, &flag);
    if (flag == 0) printf("Nenhum aniversariante nesse dia\n");
}

// Console Interation
void leString(char *s) {
    fflush(stdin);
    scanf("%[^\n]s", s);
    getchar();
}

void printNome(pessoa p) {
    printf("%s\n", p.nome);
}

void printPessoa(pessoa p) {
    printf("Nome: %s\n", p.nome);
    printf("Email: %s\n", p.email);
    printf("País: %s\n", p.adre.pais);
    printf("Estado: %s\n", p.adre.estado);
    printf("Cidade: %s\n", p.adre.cidade);
    printf("Bairro: %s\n", p.adre.bairro);
    printf("Rua: %s\n", p.adre.rua);
    printf("Numero: %d\n", p.adre.numero);
    printf("CEP: %d\n", p.adre.cep);
    printf("Complemento: %s\n", p.adre.complemento);
    printf("Código nacional: %d\n", p.tele.cod_nacional);
    printf("Códgio de área: %d\n", p.tele.cod_area);
    printf("Número: %d\n", p.tele.num);
    printf("Data de nascimento:\n");
    printf("Dia: %d\n", p.nasci.dia);
    printf("Mês: %d\n", p.nasci.mes);
    printf("Ano: %d\n", p.nasci.ano);
    printf("Observação: %s\n", p.obs);
}

void leInt(int *n) {
    if (scanf("%d", n) == EOF) *n = 0;
    getchar();
}

// Banco
void salvaBanco(no *nodo, FILE *f) {
    if (nodo == NULL) return;
    fwrite(nodo, sizeof(no), 1,  f);
    salvaBanco(nodo->esq, f);
    salvaBanco(nodo->dir, f);
}

no* leBanco(no *raiz, FILE *f) {
    while (1) {
        no *novo = malloc(sizeof(no));
        fread(novo, sizeof(no), 1, f);
        if (feof(f)) break;
        novo->esq = NULL;
        novo->dir = NULL;
        raiz = adiciona(raiz, novo);
    }
    return raiz;
}

// Arvore
no* adiciona(no *nodo, no *new) {
    if (nodo == NULL) return new;
    if (strcmp(new->p.nome, nodo->p.nome) < 0) {
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
    else if (strcmp(nodo->p.nome, s) > 0) nodo->esq = remover(nodo->esq, s);
    else if (strcmp(nodo->p.nome, s) < 0) nodo->dir = remover(nodo->dir, s);
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
    } else if (nodo->esq != NULL && strcmp(nodo->p.nome, s) > 0) achaPessoa(nodo->esq, s);
    else if (nodo->dir != NULL && strcmp(nodo->p.nome, s) < 0) achaPessoa(nodo->dir, s);
    else printPessoa(nodo->p);
}

void achaMes(no *nodo, int *m, int *flag){
    if (nodo == NULL){
        printf("Pessoa não encontrada\n");
        return;
    }
    if (nodo->p.nasci.mes == *m){
        printNome(nodo->p);
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
        printNome(nodo->p);
        *flag = 1;
    }
    if (nodo->esq != NULL) achaDia(nodo->esq, m, dia, flag);
    if(nodo->dir != NULL) achaDia(nodo->dir, m, dia, flag);
}
