
void fn_dispararEmail(long int _isbnLivro, char *_emailDestinatario) {
  char *comandoFinal;
  comandoFinal = (char*)malloc(tamanhoMaxComando * sizeof(char));
    
  char *conteudoEmail;
  conteudoEmail = (char*)malloc(tamanhoMaxEmail * sizeof(char));
  sprintf(conteudoEmail, "-u %s -m 'O emprestimo do livro ISBN: %ld Titulo: viagem ao sobrenatural esta atrasado'", assuntoEmail, _isbnLivro);
  
  
  sprintf(comandoFinal, "sendemail -f %s -t %s %s -s %s -xu %s -xp %s", emailDisparador, _emailDestinatario, conteudoEmail, smtpGmail, emailDisparador, senhaEmailDisparador);

  system(comandoFinal);
}

int fn_emprestimoAtrasou(long int _dataEmprestimo, int _duracao) {
  long int duracaoSegundos = _duracao * 86400;
  
  time_t dataAtual;
  time(&dataAtual);
  
  long int tempoEmprestimo = dataAtual - _dataEmprestimo;
  if (tempoEmprestimo > duracaoSegundos) {
    return 1;
  }

  return 0;
}

void * fn_atualizarEmprestimos() {
  FILE * baseEmprestimos = fopen(caminhoBaseEmprestimos, "r");
  
  if (baseEmprestimos != NULL) {
    FILE * tmpEmprestimos = fopen(caminhoBaseEmprestimosTmp, "w");

    Emprestimo tmp;
    tmp.tituloLivro  = (char*)malloc(limiteTitulo * sizeof(char));
    tmp.nomeAluno    = (char*)malloc(limiteNome * sizeof(char));
    tmp.emailAluno   = (char*)malloc(limiteEmail * sizeof(char));

    while (fscanf(baseEmprestimos, "%ld %s %ld %s %ld %d %d %s %d\n", &tmp.isbnLivro, tmp.tituloLivro, &tmp.raAluno, tmp.nomeAluno, &tmp.dataEmprestimo, &tmp.tempoDias, &tmp.emprestimoAtrasado, tmp.emailAluno, &tmp.emailDisparado) != EOF) {
      
      if ((tmp.emprestimoAtrasado && !tmp.emailDisparado) || fn_emprestimoAtrasou(tmp.dataEmprestimo, tmp.tempoDias)) {
        tmp.emailDisparado = 1;
        tmp.emprestimoAtrasado = 1;

        fn_dispararEmail(tmp.isbnLivro, tmp.emailAluno);
      }

      fprintf(tmpEmprestimos, "%-13ld %-50s %-10ld %-50s %-20ld %-3d %-1d %-50s %-1d\n", tmp.isbnLivro, tmp.tituloLivro, tmp.raAluno, tmp.nomeAluno, tmp.dataEmprestimo, tmp.tempoDias, tmp.emprestimoAtrasado, tmp.emailAluno, tmp.emailDisparado);
    }
    fclose(baseEmprestimos);
    fclose(tmpEmprestimos);

    remove(caminhoBaseEmprestimos); 
    rename(caminhoBaseEmprestimosTmp, caminhoBaseEmprestimos);
  } else {
    fclose(baseEmprestimos);
  }
}