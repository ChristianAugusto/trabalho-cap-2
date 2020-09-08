
/* Emprestimo */
typedef struct Emprestimo {
  // long int id;
  int tempoDias;
  long int dataEmprestimo;

  long int raAluno;
  char *nomeAluno;
  char *emailAluno;

  long int isbnLivro;
  char *tituloLivro;

  int emprestimoAtrasado;
  int emailDisparado;
} Emprestimo;