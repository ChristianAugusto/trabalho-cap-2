
Aluno fn_pegarAluno(long int _raAlvo) {
  FILE * baseAlunos = fopen(caminhoBaseAlunos, "r");

  Aluno tmp;
  tmp.nome = (char * ) malloc(limiteNome * sizeof(char));
  tmp.curso = (char * ) malloc(limiteCurso * sizeof(char));
  tmp.email = (char * ) malloc(limiteEmail * sizeof(char));

  if (baseAlunos != NULL) {

    while (fscanf(baseAlunos, "%ld %s %s %s %d %d\n", &tmp.ra, tmp.nome, tmp.curso, tmp.email, &tmp.emprestimosFeitos, &tmp.emprestimosAtrasados) != EOF) {
      if (tmp.ra == _raAlvo) {
        fclose(baseAlunos);
        return tmp;
      }
    }

    printf("\n\nO aluno nao foi encontrado!! Esse aluno ja esta registrado na base?\n\n");
    fclose(baseAlunos);
  } else {
    fn_erroAberturaBase();
    fclose(baseAlunos);
  }

  tmp.ra = 0;
  return tmp;
}