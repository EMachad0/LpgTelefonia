#define TAM 10005

typedef struct{
    char rua[TAM];
    char bairro[TAM];
    char cidade[TAM];
    char estado[TAM];
    char pais[TAM];
    int numero;
    int cep;
    int complemento;
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

struct aux{
    pessoa p;
    struct aux *next;
};
typedef struct aux no;
