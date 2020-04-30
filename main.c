#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void instrucoes();
void infodev();
void menuCadastro();
void menu(int select);

int main()
{
    int selecao;
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    printf("\n");

    printf("\nMenu Principal \n\n");
    printf("1 - Iniciar Jogo \n");
    printf("2 - Instruções do Jogo \n");
    printf("3 - Ranking \n");
    printf("4 - Informações do Desenvolvedor \n");

    printf("Selecione a opção: ");
    scanf("%d", &selecao);

    menu(selecao);
    return 0;
}

void instrucoes(){
    system("cls");
    printf("\n Instruções do Jogo \n");
    printf("\n O objetivo do jogo é matar os zombies e \n sobreviver aos barris que vem em sua direção.");
    printf("\n");
    printf("\n - Para atirar, aperte a tecla espaço.");
    printf("\n - Para pular, aperte a tecla direcional para cima. \n");
    printf("\n \n Aperte qualquer tecla para voltar...");
    system("pause>null");
    main();
}
void infodev(){
    system("cls");
    printf("\n Informações do Desenvolvedor");
    printf("\n ");
    printf("\n Desenvolvido por alunos da Faculdade Uniamérica: \n");
    printf("\n - Vinicius Oliveira");
    printf("\n - Larissa Lazzari");
    printf("\n - Oliver J. Godoy");
    printf("\n - Gabriel Hoffman");
    printf("\n");
    printf("\n \n Aperte qualquer tecla para voltar...");
    system("pause>null");
    main();
}
void menuCadastro(){
    char nome[50];
    system("cls");
    printf("\n Digite seu nome: ");
    scanf("%s", nome);

    play(nome);
}
void play(char nome[]){
    system("cls");
    printf("Bem vindo %s \n", nome);
    printf("\n \n Aperte qualquer tecla para voltar...");
    system("pause>null");
    main();
}

void menu(int select){
    switch(select){
    case 1:
        menuCadastro();
        break;
    ;

    case 2:
        instrucoes();
        break;
    ;
    case 3:

        printf("Ranking \n");
        printf("\n 1 - Usuário - 500");
        printf("\n 2 - Usuário2 - 300");
        printf("\n 3 - Usuário3 - 300");
        break;
    case 4:
        infodev();
        break;
    default:
        main();
    }
}
