#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void instrucoes();
void infodev();
void menuCadastro();
void menu(int select);

FILE * AbreArquivo(char modo, char caminho[30]){
    FILE *arquivo;
    switch(modo){
        case 'g':
            arquivo = fopen(caminho, "wt");
            break;
        case 'l':
            arquivo = fopen(caminho, "rt");
            break;
        case 'a':
            arquivo = fopen(caminho, "a");
            break;
    }
    if(arquivo==NULL){
        printf("Não foi possível abrir o arquivo");
        exit(0);
    }
    return arquivo;
}

void FecharArquivo(FILE * arquivo){
    fclose(arquivo);
}

void Cadastra(char nome[30]){
    FILE *arquivo;
    arquivo = AbreArquivo('a', "nomes.txt");
    fprintf(arquivo, "%s\n", nome);
    FecharArquivo(arquivo);
}

void Listar(){
    FILE *arquivo;
    char nome[30];

    arquivo = AbreArquivo('l', "nomes.txt");

    while(!feof(arquivo)){
        fscanf(arquivo, "%s \n", &nome);
        printf("Nome: %s \n", nome);
    }
    FecharArquivo(arquivo);

}
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
    printf("\nDigite seu nome: ");
    setbuf(stdin, NULL);
    gets(nome);
    Cadastra(nome);

    play(nome);
}
void play(char nome[]){
    system("cls");
    printf("Bem vindo %s \n", nome);
    printf("\n\nAperte qualquer tecla para voltar...");
    system("pause>null");
    main();
}

void menu(int select){
    char nome[30];
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
        Listar();
        break;
    case 4:
        infodev();
        break;
    default:
        main();
    }
}
