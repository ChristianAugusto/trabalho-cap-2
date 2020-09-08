
Aluno fn_criarAluno() {
    Aluno novoAluno;

    while(1) {
        printf("\nDigite o RA do aluno: ");
        novoAluno.ra = fn_lerLongInt();
        if (novoAluno.ra > 0) {
            break;
        }
        printf("\nO RA precisa ter um valor maior que zero");
    }

    printf("Digite o nome do aluno: ");
    novoAluno.nome = fn_lerString(limiteNome, 1);
    
    printf("Digite o curso do aluno: ");
    novoAluno.curso = fn_lerString(limiteCurso, 1);

    while (1) {
        char *novoEmail;
        printf("Digite o email do aluno, Example: marinho@email.com: ");
        novoEmail = fn_lerString(limiteEmail, 0);

        if (fn_formatoEmailCorreto(novoEmail)) {
            novoAluno.email = novoEmail;
            break;
        }
        printf("Email digitado esta fora do formato correto!! ");
        printf("Tente Novamente\n");

        free(novoEmail);
    }

    novoAluno.emprestimosFeitos = 0;
    novoAluno.emprestimosAtrasados = 0;

    return novoAluno;
}


void fn_registrarAluno(Aluno _novoAluno) {
    FILE *baseAlunos = fopen(caminhoBaseAlunos, "r");
    FILE *tmpAlunos  = fopen(caminhoBaseAlunosTmp, "w");

    if (baseAlunos != NULL) {
        Aluno tmp;
        tmp.nome = (char*)malloc(limiteNome * sizeof(char));
        tmp.curso = (char*)malloc(limiteCurso * sizeof(char));
        tmp.email = (char*)malloc(limiteEmail * sizeof(char));

        int novoAlunoSalvo = 0;
        int raExiste = 0;

        while(fscanf(baseAlunos, "%ld %s %s %s %d %d\n", &tmp.ra, tmp.nome, tmp.curso, tmp.email, &tmp.emprestimosFeitos, &tmp.emprestimosAtrasados) != EOF) {
            if (_novoAluno.ra == tmp.ra) {
                raExiste = 1;
                fn_raJaExiste();
            }

            if (_novoAluno.ra < tmp.ra && !novoAlunoSalvo && !raExiste) {
                fprintf(tmpAlunos, "%-10ld %-50s %-25s %-30s %-2d %-2d\n", _novoAluno.ra, fn_lowerCase(_novoAluno.nome), fn_lowerCase(_novoAluno.curso), _novoAluno.email, _novoAluno.emprestimosFeitos, _novoAluno.emprestimosAtrasados);
                fprintf(tmpAlunos, "%-10ld %-50s %-25s %-30s %-2d %-2d\n", tmp.ra, tmp.nome, tmp.curso, tmp.email, tmp.emprestimosFeitos, tmp.emprestimosAtrasados);
                novoAlunoSalvo = 1;
            } else {
                fprintf(tmpAlunos, "%-10ld %-50s %-25s %-30s %-2d %-2d\n", tmp.ra, tmp.nome, tmp.curso, tmp.email, tmp.emprestimosFeitos, tmp.emprestimosAtrasados);
            }
        }

        if (!novoAlunoSalvo && !raExiste) {
            fprintf(tmpAlunos, "%-10ld %-50s %-25s %-30s %-2d %-2d\n", _novoAluno.ra, fn_lowerCase(_novoAluno.nome), fn_lowerCase(_novoAluno.curso), _novoAluno.email, _novoAluno.emprestimosFeitos, _novoAluno.emprestimosAtrasados);
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