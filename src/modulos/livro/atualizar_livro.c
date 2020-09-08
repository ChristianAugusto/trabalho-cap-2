
void fn_atualizarLivro(Livro _livro, int imprimirMensagem) {
  FILE * baseLivros = fopen(caminhoBaseLivros, "r");
  FILE * tmpLivros = fopen(caminhoBaseLivrosTmp, "w");

  Livro tmp;
  tmp.titulo = (char * ) malloc(limiteTitulo * sizeof(char));
  tmp.editora = (char * ) malloc(limiteEditora * sizeof(char));

  if (baseLivros != NULL) {

    int livroAtualizado = 0;

    while (fscanf(baseLivros, "%ld %s %s %d %d %d %d\n", &tmp.isbn, tmp.titulo, tmp.editora, &tmp.ano, &tmp.total, &tmp.emprestados, &tmp.disponiveis) != EOF) {
      if (tmp.isbn == _livro.isbn) {
        fprintf(tmpLivros, "%-13ld %-50s %-50s %-5d %-3d %-3d %-3d\n", _livro.isbn, _livro.titulo, _livro.editora, _livro.ano, _livro.total, _livro.emprestados, _livro.disponiveis);
        livroAtualizado = 1;
      } else {
        fprintf(tmpLivros, "%-13ld %-50s %-50s %-5d %-3d %-3d %-3d\n", tmp.isbn, tmp.titulo, tmp.editora, tmp.ano, tmp.total, tmp.emprestados, tmp.disponiveis);
      }
    }

    if (livroAtualizado && imprimirMensagem) {
      printf("\n\nO livro foi atualizado!!\n\n");
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