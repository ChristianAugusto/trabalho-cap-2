Trabalho CAP II - CI23A - 2019

Christian Augusto Martins dos Santos Barros     12084
Thiago Lopes Onofre                             86468
Nikolas Henrique Santos Leite                   120175


Dois arquivos principais:
main.c    <- Funcionamento sem threads
main2.c   <- Funcionamento com threads


O email é disparado pelo sendemail do linux.
sudo apt-get install sendemail

Para rodar o programa, entre na pasta src com o terminal e execute:
gcc main.c -o main; ./main                    <- Sem thread
gcc -pthread main2.c -o main2; ./main2        <- Com thread