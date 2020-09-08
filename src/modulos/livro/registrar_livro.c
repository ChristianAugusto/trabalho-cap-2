
Livro fn_criarLivro() {
    Livro novoLivro;


    while(1) {
        printf("\nDigite o ISBN do libro: ");
        novoLivro.isbn = fn_lerLongInt();
        if (novoLivro.isbn > 0) {
            break;
        }
        printf("\nO ISBN precisa ter um valor maior que zero");
    }

    printf("Digite o titulo do livro: ");
    novoLivro.titulo = fn_lerString(limiteTitulo, 1);

    printf("Digite a editora do livro: ");
    novoLivro.editora = fn_lerString(limiteEditora, 1);

    printf("Digite o ano de lancamento do livro: ");
    novoLivro.ano = fn_lerInt();

    printf("Digite o total de exemplares desse livro: ");
    novoLivro.total = fn_lerInt();

    novoLivro.emprestados = 0;
    novoLivro.disponiveis = novoLivro.total;

    return novoLivro;
}

void fn_registrarLivro(Livro _novoLivro) {
    FILE *baseLivros = fopen(caminhoBaseLivros, "r");
    FILE *tmpLivros  = fopen(caminhoBaseLivrosTmp, "w");

    if (baseLivros != NULL) {

        Livro tmp;
        tmp.titulo = (char*)malloc(limiteTitulo * sizeof(char));
        tmp.editora = (char*)malloc(limiteEditora * sizeof(char));

        int novoLivroSalvo = 0;
        int isbnExiste = 0;

        while(fscanf(baseLivros, "%ld %s %s %d %d %d %d\n", &tmp.isbn, tmp.titulo, tmp.editora, &tmp.ano, &tmp.total, &tmp.emprestados, &tmp.disponiveis) != EOF) {
            if (_novoLivro.isbn == tmp.isbn) {
                isbnExiste = 1;
                fn_isbnJaExiste();
            }

            if (_novoLivro.isbn < tmp.isbn && !novoLivroSalvo && !isbnExiste) {
                fprintf(tmpLivros, "%-13ld %-50s %-50s %-5d %-3d %-3d %-3d\n", _novoLivro.isbn, fn_lowerCase(_novoLivro.titulo), fn_lowerCase(_novoLivro.editora), _novoLivro.ano, _novoLivro.total, _novoLivro.emprestados, _novoLivro.disponiveis);
                fprintf(tmpLivros, "%-13ld %-50s %-50s %-5d %-3d %-3d %-3d\n", tmp.isbn, tmp.titulo, tmp.editora, tmp.ano, tmp.total, tmp.emprestados, tmp.disponiveis);
                novoLivroSalvo = 1;
            } else {
                fprintf(tmpLivros, "%-13ld %-50s %-50s %-5d %-3d %-3d %-3d\n", tmp.isbn, tmp.titulo, tmp.editora, tmp.ano, tmp.total, tmp.emprestados, tmp.disponiveis);
            }
        }

        if (!novoLivroSalvo && !isbnExiste) {
            fprintf(tmpLivros, "%-13ld %-50s %-50s %-5d %-3d %-3d %-3d\n", _novoLivro.isbn, fn_lowerCase(_novoLivro.titulo), fn_lowerCase(_novoLivro.editora), _novoLivro.ano, _novoLivro.total, _novoLivro.emprestados, _novoLivro.disponiveis);
        }

        fclose(baseLivros);
        remove(caminhoBaseLivros);

        fclose(tmpLivros);
        rename(caminhoBaseLivrosTmp, caminhoBaseLivros);

    } else {
        fn_erroAberturaBase();

        fclose(baseLivros);
        remove(caminhoBaseLivrosTmp);
    }
}