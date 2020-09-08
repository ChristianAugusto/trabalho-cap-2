
int fn_finalizarEmprestimo() {
  FILE * baseEmprestimos = fopen(caminhoBaseEmprestimos, "r");

  if (baseEmprestimos != NULL) {
    printf("\nDigite o RA do aluno: ");
    long int raAlvo = fn_lerLongInt();
    
    printf("\nDigite o ISBN do livro: ");
    long int isbnAlvo = fn_lerLongInt();

    FILE * tmpEmprestimos  = fopen(caminhoBaseEmprestimosTmp, "w");

    Emprestimo tmp;
    tmp.tituloLivro = (char*)malloc(limiteTitulo * sizeof(char));
    tmp.nomeAluno   = (char*)malloc(limiteNome * sizeof(char));
    tmp.emailAluno   = (char*)malloc(limiteEmail * sizeof(char));

    int emprestimoFinalizado = 0;
    while (fscanf(baseEmprestimos, "%ld %s %ld %s %ld %d %d %s %d\n", &tmp.isbnLivro, tmp.tituloLivro, &tmp.raAluno, tmp.nomeAluno, &tmp.dataEmprestimo, &tmp.tempoDias, &tmp.emprestimoAtrasado, tmp.emailAluno, &tmp.emailDisparado) != EOF) {
      if (tmp.raAluno == raAlvo && tmp.isbnLivro == isbnAlvo && !emprestimoFinalizado) {
        Aluno aluno = fn_pegarAluno(raAlvo);
        Livro livro = fn_pegarLivro(isbnAlvo);

        aluno.emprestimosFeitos--;
        if (tmp.emprestimoAtrasado) {
          aluno.emprestimosAtrasados--;
        }

        livro.disponiveis++;
        livro.emprestados--;

        fn_atualizarLivro(livro, 0);
        fn_atualizarAluno(aluno, 0);

        emprestimoFinalizado = 1;
      } else {
        fprintf(tmpEmprestimos, "%-13ld %-50s %-10ld %-50s %-20ld %-3d %-1d %-50s %-1d\n", tmp.isbnLivro, tmp.tituloLivro, tmp.raAluno, tmp.nomeAluno, tmp.dataEmprestimo, tmp.tempoDias, tmp.emprestimoAtrasado, tmp.emailAluno, tmp.emailDisparado);
      }
    }

    if (emprestimoFinalizado) {
      printf("\nEmprestimo finalizado!!\n");
    }

    fclose(baseEmprestimos);
    fclose(tmpEmprestimos);

    remove(caminhoBaseEmprestimos); 
    rename(caminhoBaseEmprestimosTmp, caminhoBaseEmprestimos);

    return 1;
  } else {
    fclose(baseEmprestimos);
  }

  return 0;
}