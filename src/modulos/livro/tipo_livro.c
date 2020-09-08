
/* Livro */
typedef struct Livro {
    long int isbn;
    char *titulo;
    char *editora;
    int ano;
    int total;

    int emprestados;
    int disponiveis;
} Livro;