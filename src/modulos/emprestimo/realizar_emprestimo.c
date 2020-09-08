
int fn_realizarEmprestimo() {
  printf("\nDigite o isbn do livro: ");
  long int isbn = fn_lerLongInt();

  printf("\nDigite o RA do aluno: ");
  long int ra = fn_lerLongInt();

  Livro livro = fn_pegarLivro(isbn);

  Aluno aluno = fn_pegarAluno(ra);

  if (!aluno.ra) {
    printf("\nO aluno nao foi encontrado\n");
    return 0;
  } 
  else if (!livro.isbn) {
    printf("\nO livro nao foi encontrado\n");
    return 0;
  } 
  else if (aluno.emprestimosAtrasados > limiteAtrasos) {
    printf("\nO aluno nao pode realizar emprestimos\npois possui emprestimo(s) atrasado(s)\n");
    return 0;
  } 
  else if (livro.disponiveis <= 0) {
    printf("\nO livro nao esta disponivel\n");
    return 0;
  }


  int dias;
  while (1) {
    printf("\nDigite a quantidade em dias do emprestimo: ");
    dias = fn_lerInt();
    if (dias > 0) {
      break;
    }
    printf("\nA quantidade de dias precisa ser maior que zero");
  }



  time_t segundos;
  time(&segundos);



  Emprestimo novoEmprestimo;
  novoEmprestimo.tituloLivro = (char*)malloc(limiteTitulo * sizeof(char));
  novoEmprestimo.nomeAluno   = (char*)malloc(limiteNome * sizeof(char));
  novoEmprestimo.emailAluno   = (char*)malloc(limiteEmail * sizeof(char));

  strcpy(novoEmprestimo.tituloLivro, livro.titulo);
  strcpy(novoEmprestimo.nomeAluno, aluno.nome);
  strcpy(novoEmprestimo.emailAluno, aluno.email);
  novoEmprestimo.isbnLivro          = livro.isbn;
  novoEmprestimo.raAluno            = aluno.ra;
  novoEmprestimo.dataEmprestimo     = segundos;
  novoEmprestimo.tempoDias          = dias;
  novoEmprestimo.emprestimoAtrasado = 0;
  novoEmprestimo.emailDisparado     = 0;

  FILE * baseEmprestimos = fopen(caminhoBaseEmprestimos, "a");
  fprintf(baseEmprestimos, "%-13ld %-50s %-10ld %-50s %-20ld %-3d %-1d %-50s %-1d\n", novoEmprestimo.isbnLivro, novoEmprestimo.tituloLivro, novoEmprestimo.raAluno, novoEmprestimo.nomeAluno, novoEmprestimo.dataEmprestimo, novoEmprestimo.tempoDias, novoEmprestimo.emprestimoAtrasado, novoEmprestimo.emailAluno, novoEmprestimo.emailDisparado);
  fclose(baseEmprestimos);

  livro.disponiveis--;
  livro.emprestados++;

  aluno.emprestimosFeitos++;

  fn_atualizarLivro(livro, 0);
  fn_atualizarAluno(aluno, 0);

  printf("\nEmprestimo feito!!\n");

  return 1;
}