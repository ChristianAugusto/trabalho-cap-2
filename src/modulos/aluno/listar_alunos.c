
void fn_listarAlunos() {
    FILE *baseAlunos = fopen(caminhoBaseAlunos, "r");
    
    Aluno tmp;
    tmp.nome = (char*)malloc(limiteNome * sizeof(char));
    tmp.curso = (char*)malloc(limiteCurso * sizeof(char));
    tmp.email = (char*)malloc(limiteEmail * sizeof(char));

    if (baseAlunos != NULL) {

        while (fscanf(baseAlunos, "%ld %s %s %s %d %d\n", &tmp.ra, tmp.nome, tmp.curso, tmp.email, &tmp.emprestimosFeitos, &tmp.emprestimosAtrasados) != EOF) {
            fn_removerCaracter(tmp.nome, '_', ' ');
            fn_removerCaracter(tmp.curso, '_', ' ');
            printf("RA:%-10ld Nome do aluno: %-50s Curso: %-25s Email: %-30s Emprestimos realizados: %-2d Emprestimos Atrasados: %-2d\n", tmp.ra, tmp.nome, tmp.curso, tmp.email, tmp.emprestimosFeitos, tmp.emprestimosAtrasados);
        }
        
    } else {
        fn_erroAberturaBase();
    }

    fclose(baseAlunos);
}