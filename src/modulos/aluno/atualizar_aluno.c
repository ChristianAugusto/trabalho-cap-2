
void fn_atualizarAluno(Aluno _aluno, int imprimirMensagem) {
  FILE * baseAlunos = fopen(caminhoBaseAlunos, "r");
  FILE * tmpAlunos  = fopen(caminhoBaseAlunosTmp, "w");

  Aluno tmp;
  tmp.nome = (char * ) malloc(limiteNome * sizeof(char));
  tmp.curso = (char * ) malloc(limiteCurso * sizeof(char));
  tmp.email = (char * ) malloc(limiteEmail * sizeof(char));

  if (baseAlunos != NULL) {

    int alunoAtualizado = 0;

    while (fscanf(baseAlunos, "%ld %s %s %s %d %d\n", &tmp.ra, tmp.nome, tmp.curso, tmp.email, &tmp.emprestimosFeitos, &tmp.emprestimosAtrasados) != EOF) {
      if (tmp.ra == _aluno.ra) {
        fprintf(tmpAlunos, "%-10ld %-50s %-25s %-30s %-2d %-2d\n", _aluno.ra, _aluno.nome, _aluno.curso, _aluno.email, _aluno.emprestimosFeitos, _aluno.emprestimosAtrasados);
        alunoAtualizado = 1;
      } else {
        fprintf(tmpAlunos, "%-10ld %-50s %-25s %-30s %-2d %-2d\n", tmp.ra, tmp.nome, tmp.curso, tmp.email, tmp.emprestimosFeitos, tmp.emprestimosAtrasados);
      }
    }

    if (alunoAtualizado && imprimirMensagem) {
      printf("\n\nO aluno foi atualizado!!\n\n");
    }

    fclose(baseAlunos);
    remove(caminhoBaseAlunos);

    fclose(tmpAlunos);
    rename(caminhoBaseAlunosTmp, caminhoBaseAlunos);

  } else {
    fn_erroAberturaBase();

    fclose(baseAlunos);
    remove(caminhoBaseAlunosTmp);
  }
}