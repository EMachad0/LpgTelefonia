void leString(char *s) {
    fflush(stdin);
    scanf("%[^\n]s", s);
    getchar();
}

void printPessoa(pessoa p) {
    printf("%s %s\n", p.nome, p.email);
}

void leInt(int *n) {
    if (scanf("%d", n) == EOF) *n = 0;
    getchar();
}
