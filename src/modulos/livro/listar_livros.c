
void fn_listarLivros() {
    FILE *baseLivros = fopen(caminhoBaseLivros, "r");
    
    Livro tmp;
    tmp.titulo = (char*)malloc(limiteTitulo * sizeof(char));
    tmp.editora = (char*)malloc(limiteEditora * sizeof(char));

    if (baseLivros != NULL) {
        while(fscanf(baseLivros, "%ld %s %s %d %d %d %d\n", &tmp.isbn, tmp.titulo, tmp.editora, &tmp.ano, &tmp.total, &tmp.emprestados, &tmp.disponiveis) != EOF) {
            fn_removerCaracter(tmp.titulo, '_', ' ');
            fn_removerCaracter(tmp.editora, '_', ' ');
            printf("ISBN: %-13ld Titulo: %-50s Editora: %-50s Ano: %-5d Total de livros: %-3d Emprestados: %-3d Disponiveis: %-3d\n", tmp.isbn, tmp.titulo, tmp.editora, tmp.ano, tmp.total, tmp.emprestados, tmp.disponiveis);
        }
    } else {
        fn_erroAberturaBase();
    }

    fclose(baseLivros);
}
