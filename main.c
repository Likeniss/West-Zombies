#include <stdio.h>
#include <windows.h>
#include <locale.h>

// Protótipo de Funções
FILE * AbreArquivo(char modo, char caminho[30]);
void FecharArquivo(FILE * arquivo);
void Cadastra(char nome[30], int pontos);
void Listar(int tamanho);
void LinhaSuperior(int tamanho);
void LinhaRodape(int tamanho);
void MenuItem(int tamanho, char string[]);
void LinhaHorizontal(int tamanho);
void MontaMenu();
void instrucoes();
void infodev();
void menuCadastro();
void menu(int select);

// Funções
int main()
{
    int selecao;
    system("cls");
    system("color 6");
    printf("\n");
    MontaMenu();
    printf("\nSelecione a opcao: ");
    scanf("%d", &selecao);
    menu(selecao);

    return 0;
}

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

void Cadastra(char nome[30], int pontos){
    FILE *arquivo;
    arquivo = AbreArquivo('a', "nomes.txt");
    fprintf(arquivo, "%s %d\n", nome, pontos);
    FecharArquivo(arquivo);
}

void Listar(int tamanho){
    FILE *arquivo;
    char nome[30];
    int pontos;
    int i;
    arquivo = AbreArquivo('l', "nomes.txt");

    for(i = 0; i < tamanho; i++){
        fscanf(arquivo, "%s %d\n", &nome,&pontos);
        printf("\nNome: %s \nPontos: %d \n", nome, pontos);
    }
    FecharArquivo(arquivo);

}
void LinhaSuperior(int tamanho){
    int i;
    printf("%c", 201);
    for(i=0; i < tamanho;i++){
        printf("%c", 205);
    }
    printf("%c\n", 187);
}
void LinhaRodape(int tamanho){
    int i;
    printf("%c", 200);
    for(i=0; i < tamanho;i++){
        printf("%c", 205);
    }
    printf("%c", 188);
}
void MenuItem(int tamanho, char string[]){

    printf("%c", 186);

        printf("%-*s", tamanho, string);


    printf("%c\n", 186);
}

void LinhaHorizontal(int tamanho){
    int i;
    printf("%c", 204);
    for(i = 0; i < tamanho; i++)
        printf("%c", 205);
    printf("%c\n", 185);
}

void MontaMenu(){
    LinhaSuperior(40);
    MenuItem(40, "Menu Principal");
    LinhaHorizontal(40);
    MenuItem(40, "1 - Iniciar Jogo");
    MenuItem(40, "2 - Instrucoes do Jogo");
    MenuItem(40, "3 - Ranking");
    MenuItem(40, "4 - Informacoes do Desenvolvedor");
    MenuItem(40, "5 - Sair");
    LinhaRodape(40);
}

void instrucoes(){
    system("cls");
    printf("\nInstrucoes do Jogo \n");
    printf("\nO objetivo do jogo e matar os zombies e \n sobreviver aos barris que vem em sua direcao.");
    printf("\n");
    printf("\n- Para atirar, aperte a tecla espaco.");
    printf("\n- Para pular, aperte a tecla direcional para cima. \n");
    printf("\n\nAperte qualquer tecla para voltar...");
    system("pause>null");
    main();
}
void infodev(){
    system("cls");
    printf("\nInformacoes do Desenvolvedor");
    printf("\n ");
    printf("\nDesenvolvido por alunos da Faculdade Uniamerica: \n");
    printf("\n- Vinicius Oliveira");
    printf("\n- Larissa Lazzari");
    printf("\n- Oliver J. Godoy");
    printf("\n- Gabriel Hoffman");
    printf("\n");
    printf("\n\nAperte qualquer tecla para voltar...");
    system("pause>null");
    main();
}
void menuCadastro(){
    char nome[50];
    int pontos;
    system("cls");
    printf("\nDigite seu nome: ");
    setbuf(stdin, NULL);
    gets(nome);
    printf("\nDigite uma quantidade de pontos: ");
    scanf("%d", &pontos);
    Cadastra(nome,pontos);

    play(nome);
}
void ranking(){
    system("cls");
    printf("Ranking \n");
    Listar(5);
    printf("\nAperte qualquer tecla para voltar...");
    system("pause>null");
    main();
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
        ranking();
        break;
    case 4:
        infodev();
        break;
    case 5:
        exit(0);
        break;
    default:
        main();
    }
}
