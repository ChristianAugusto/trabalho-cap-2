
void fn_removerAluno() {
  printf("\nDigite o ra do aluno que desejas remover: ");
  long int raAlvo = fn_lerLongInt();

  FILE * baseAlunos = fopen(caminhoBaseAlunos, "r");
  FILE * tmpAlunos  = fopen(caminhoBaseAlunosTmp, "w");

  Aluno tmp;
  tmp.nome = (char * ) malloc(limiteNome * sizeof(char));
  tmp.curso = (char * ) malloc(limiteCurso * sizeof(char));
  tmp.email = (char * ) malloc(limiteEmail * sizeof(char));

  if (baseAlunos != NULL) {

    int alunoRemovido = 0;

    while (fscanf(baseAlunos, "%ld %s %s %s %d %d\n", &tmp.ra, tmp.nome, tmp.curso, tmp.email, &tmp.emprestimosFeitos, &tmp.emprestimosAtrasados) != EOF) {
      if (tmp.ra == raAlvo) {
        alunoRemovido = 1;
      } else {
        fprintf(tmpAlunos, "%-10ld %-50s %-25s %-30s %-2d %-2d\n", tmp.ra, tmp.nome, tmp.curso, tmp.email, tmp.emprestimosFeitos, tmp.emprestimosAtrasados);
      }
    }

    if (alunoRemovido) {
      printf("\n\nO aluno foi removido!!\n\n");
    } else {
      printf("\n\nO aluno nao foi removido!! Esse aluno ja esta registrado na base?\n\n");
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