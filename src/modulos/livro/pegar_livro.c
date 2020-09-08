
Livro fn_pegarLivro(long int _isbnAlvo) {
  FILE * baseLivros = fopen(caminhoBaseLivros, "r");

  Livro tmp;
  tmp.titulo = (char * ) malloc(limiteTitulo * sizeof(char));
  tmp.editora = (char * ) malloc(limiteEditora * sizeof(char));

  if (baseLivros != NULL) {

    while (fscanf(baseLivros, "%ld %s %s %d %d %d %d\n", &tmp.isbn, tmp.titulo, tmp.editora, &tmp.ano, &tmp.total, &tmp.emprestados, &tmp.disponiveis) != EOF) {
      if (tmp.isbn == _isbnAlvo) {
        fclose(baseLivros);
        return tmp;
      }
    }

    printf("\n\nO livro nao foi encontrado!! Esse livro ja esta registrado na base?\n\n");
    fclose(baseLivros);
  } else {
    fn_erroAberturaBase();
    fclose(baseLivros);
  }

  tmp.isbn = 0;
  return tmp;
}