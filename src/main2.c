
#include "./modulos/config.c"

int main(void) {
  pthread_t thread2;
  int threadFinalizada = 0;


  printf("\n\n\n");

  printf("Seja bem vindo ao sistema da sua biblioteca!\n\n\n");

  while (1) {
    if (threadFinalizada == 0) {
      threadFinalizada = pthread_create(&thread2, NULL, fn_atualizarEmprestimos, NULL);
    }

    /* MENU */
    printf("Digite o numero da opcao:\n");
    printf("1 -> Registar Aluno\n");
    printf("2 -> Listar Alunos\n");
    printf("3 -> Remover Aluno\n");
    printf("-----------------\n");
    printf("4 -> Registar Livro\n");
    printf("5 -> Listar Livros\n");
    printf("6 -> Remover Livro\n");
    printf("-----------------\n");
    printf("7 -> Realizar Emprestimo\n");
    printf("8 -> Listar Emprestimos\n");
    printf("9 -> Finalizar Emprestimo\n");
    printf("-----------------\n");
    printf("0 -> Sair\n");

    printf("Digite: ");
    int opcao = fn_lerInt();

    printf("\n\n\n");

    if (opcao == 0) {
      break;
    } 
    else if (opcao == 1) {
      fn_registrarAluno(fn_criarAluno());
    } 
    else if (opcao == 2) {
      fn_listarAlunos();
    } 
    else if (opcao == 3) {
      fn_removerAluno();
    } 
    else if (opcao == 4) {
      fn_registrarLivro(fn_criarLivro());
    } 
    else if (opcao == 5) {
      fn_listarLivros();
    } 
    else if (opcao == 6) {
      fn_removerLivro();
    } 
    else if (opcao == 7) {
      if (threadFinalizada != 0) {
        pthread_join(thread2, NULL);
      }
      fn_realizarEmprestimo();
    }
    else if (opcao == 8) {
      if (threadFinalizada != 0) {
        pthread_join(thread2, NULL);
      }
      fn_listarEmprestimos();
    }
    else if (opcao == 9) {
      if (threadFinalizada != 0) {
        pthread_join(thread2, NULL);
      }
      fn_finalizarEmprestimo();
    }

    printf("\nAperte enter para prosseguir: ");
    getchar();

    printf("\n\n\n");
  }

  printf("Adeus!\n");

  if (threadFinalizada != 0) {
    pthread_join(thread2, NULL);
  }

  return 0;
}