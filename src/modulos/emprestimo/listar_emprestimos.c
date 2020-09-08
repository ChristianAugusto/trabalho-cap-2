
void fn_listarEmprestimos() {
  FILE * baseEmprestimos = fopen(caminhoBaseEmprestimos, "r");

  Emprestimo tmp;
  tmp.tituloLivro = (char*)malloc(limiteTitulo * sizeof(char));
  tmp.nomeAluno   = (char*)malloc(limiteNome * sizeof(char));
  tmp.emailAluno   = (char*)malloc(limiteEmail * sizeof(char));


  if (baseEmprestimos != NULL) {

    while (fscanf(baseEmprestimos, "%ld %s %ld %s %ld %d %d %s %d\n", &tmp.isbnLivro, tmp.tituloLivro, &tmp.raAluno, tmp.nomeAluno, &tmp.dataEmprestimo, &tmp.tempoDias, &tmp.emprestimoAtrasado, tmp.emailAluno, &tmp.emailDisparado) != EOF) {
      fn_removerCaracter(tmp.tituloLivro, '_', ' ');
      fn_removerCaracter(tmp.nomeAluno, '_', ' ');
      printf("ISBN: %-13ld Titulo: %-50s RA: %-10ld Nome: %-50s Data de emprestimo: %-20ld Dias de emprestimo: %-3d Emprestimos atrasados: %-1d Email: %-50s Email disparado: %-1d\n", tmp.isbnLivro, tmp.tituloLivro, tmp.raAluno, tmp.nomeAluno, tmp.dataEmprestimo, tmp.tempoDias, tmp.emprestimoAtrasado, tmp.emailAluno, tmp.emailDisparado);
    }
  }


  fclose(baseEmprestimos);
}