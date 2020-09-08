
void fn_removerLivro() {
  printf("\nDigite o isbn do livro que desejas remover: ");
  long int isbnAlvo = fn_lerLongInt();

  FILE * baseLivros = fopen(caminhoBaseLivros, "r");
  FILE * tmpLivros = fopen(caminhoBaseLivrosTmp, "w");

  Livro tmp;
  tmp.titulo = (char * ) malloc(limiteTitulo * sizeof(char));
  tmp.editora = (char * ) malloc(limiteEditora * sizeof(char));

  if (baseLivros != NULL) {

    int livroRemovido = 0;

    while (fscanf(baseLivros, "%ld %s %s %d %d %d %d\n", &tmp.isbn, tmp.titulo, tmp.editora, &tmp.ano, &tmp.total, &tmp.emprestados, &tmp.disponiveis) != EOF) {
      if (tmp.isbn == isbnAlvo) {
        livroRemovido = 1;
      } else {
        fprintf(tmpLivros, "%-13ld %-50s %-50s %-5d %-3d %-3d %-3d\n", tmp.isbn, tmp.titulo, tmp.editora, tmp.ano, tmp.total, tmp.emprestados, tmp.disponiveis);
      }
    }

    if (livroRemovido) {
      printf("\n\nO livro foi removido!!\n\n");
    } else {
      printf("\n\nO livro nao foi removido!! Esse livro ja esta registrado na base?\n\n");
    }

    fclose(baseLivros);
    remove(caminhoBaseLivros);

    fclose(tmpLivros);
    rename(caminhoBaseLivrosTmp, caminhoBaseLivros);
    
  } else {
    fn_erroAberturaBase();

    fclose(baseLivros);
    remove(caminhoBaseLivrosTmp);
  }
}