#include <stdio.h>
#include <windows.h>
#include <locale.h>

// Prot�tipo de Fun��es
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
void Trailer();
void TrocaCursor(int value);
void menu(int select);

// Var�aveis globais
int aberto = 0;

// Fun��es
int main()
{
    int selecao;
    // Esconde o cursor
    TrocaCursor(0);
    // Limpa a tela
    system("cls");
    // Define a cor amarela
    system("color 6");
    // Chama a tela de apresenta��o
    if(aberto == 0){
            Trailer();
            aberto = 1;
            // Dorme durante 3 segundos
            sleep(3);
    }
    // Limpa a tela
    system("cls");
    printf("\n");
    // Chama a fun��o que monta o menu
    MontaMenu();
    return 0;
}

// Mostra(1 == true) ou esconde(0 == false) a | na hora de digitar
void TrocaCursor(int value){
    HANDLE hOut;
    CONSOLE_CURSOR_INFO cursor;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    cursor.dwSize = 10;
    cursor.bVisible = value;
    SetConsoleCursorInfo(hOut, &cursor);
}
// Mostra a logo
void Trailer(){



printf("\n\n\n\n\n\n");
printf("                             '##:::::'##:'########::'######::'########:\n");
printf("                              ##:'##: ##: ##.....::'##... ##:... ##..::\n");
printf("                              ##: ##: ##: ##::::::: ##:::..::::: ##::::\n");
printf("                              ##: ##: ##: ######:::. ######::::: ##::::\n");
printf("                              ##: ##: ##: ##...:::::..... ##:::: ##::::\n");
printf("                              ##: ##: ##: ##:::::::'##::: ##:::: ##::::\n");
printf("                             . ###. ###:: ########:. ######::::: ##::::\n");
printf("                             :...::...:::........:::......::::::..:::::\n");
printf("               '########::'#######::'##::::'##:'########::'####:'########::'######::\n");
printf("               ..... ##::'##.... ##: ###::'###: ##.... ##:. ##:: ##.....::'##... ##:\n");
printf("               :::: ##::: ##:::: ##: ####'####: ##:::: ##:: ##:: ##::::::: ##:::..::\n");
printf("               ::: ##:::: ##:::: ##: ## ### ##: ########::: ##:: ######:::. ######::\n");
printf("               :: ##::::: ##:::: ##: ##. #: ##: ##.... ##:: ##:: ##...:::::..... ##:\n");
printf("               : ##:::::: ##:::: ##: ##:.:: ##: ##:::: ##:: ##:: ##:::::::'##::: ##:\n");
printf("                ########:. #######:: ##:::: ##: ########::'####: ########:. ######::\n");
printf("               ........:::.......:::..:::::..::........:::....::........:::......:::\n");
}
// Abre o arquivo para armazenar os nomes
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
        printf("N�o foi poss�vel abrir o arquivo");
        exit(0);
    }
    return arquivo;
}
// Fecha o arquivo que armazena os nomes
void FecharArquivo(FILE * arquivo){
    fclose(arquivo);
}
// Cadastra um nome e os pontos no arquivo aberto.
void Cadastra(char nome[30], int pontos){
    FILE *arquivo;
    arquivo = AbreArquivo('a', "nomes.txt");
    fprintf(arquivo, "%s %d\n", nome, pontos);
    FecharArquivo(arquivo);
}
// Lista os nomes, int tamanho pra definir quantas linhas mostrar
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
// Cria linha superior no menu usando tabela ascii
void LinhaSuperior(int tamanho){
    int i;
    printf("%c", 201);
    for(i=0; i < tamanho;i++){
        printf("%c", 205);
    }
    printf("%c\n", 187);
}
// Cria linha no rodap� do menu usando tabela ascii
void LinhaRodape(int tamanho){
    int i;
    printf("%c", 200);
    for(i=0; i < tamanho;i++){
        printf("%c", 205);
    }
    printf("%c", 188);
}
// Cria um item do menu acompanhando as linhas superiores e do rodap� usando tabela ascii
void MenuItem(int tamanho, char string[]){

    printf("%c", 186);

        printf("%-*s", tamanho, string);


    printf("%c\n", 186);
}
// Cria uma linha de separa��o horizontal usando tabela ascii
void LinhaHorizontal(int tamanho){
    int i;
    printf("%c", 204);
    for(i = 0; i < tamanho; i++)
        printf("%c", 205);
    printf("%c\n", 185);
}

// go to x ou y;
void gotoxy(int x,int y){
    COORD c; // Pega as coordenadas atuais
    c.X = x; // Joga a coordenada x para var�avel x;
    c.Y = y; // Joga a coordenada y para variavel y;
    // endere�a o cursor no console, utilizando linhas e colunas;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
// Monta o menu
void MontaMenu(){
    int li = 4; // Var�avel de escolha
    int tecla;
    LinhaSuperior(40);
    MenuItem(40, "            Menu Principal");
    LinhaHorizontal(40);
    MenuItem(40, "    1 - Iniciar Jogo");
    MenuItem(40, "    2 - Instrucoes do Jogo");
    MenuItem(40, "    3 - Ranking");
    MenuItem(40, "    4 - Informacoes do Desenvolvedor");
    MenuItem(40, "    5 - Sair");
    LinhaRodape(40);
    gotoxy(1,li); // vai para a linha 1 coluna no valor de li que seria 4 inicialmente
    printf(" -> "); // adiciona a primeira flechinha nas coordenadas da fun��o fotoxy
     do{
        tecla = getch(); // Captura teclas que o usu�rio digita sem que imprima na tela.
        gotoxy(1,li); // vai para a linha 1 coluna no valor de li que seria 4 inicialmente
        printf("   "); // adiciona caracteres em branco nos 3 primeiros espa�os do menu come�ando da coluna 1
            if(tecla == 72){
                li--;
            } // se pressionado a tecla 72 que seria a tecla direcional para cima usando getch() subtrai na variavel li

             // C�digo Especial:  ao serem pressionadas certas teclas (ou combina��o de teclas) que n�o correspondem
             // a um  caracter ASCII, o teclado envia ao 'buffer' do computador dois c�digos, sendo o primeiro sempre 0.
             // Por exemplo, se a tecla [F1] f or pressionada os valores 0 e 59 ser�o armazenados e a fun��o deve ser
             // chamada duas vezes para ler os dois c�digos.
            else{
                if(tecla == 80)
                        li++;
            }// se pressionado a tecla 80 que seria a tecla direcional para baixo usando getch() subtrai na variavel li
                if(li > 8){
                    li=4;
                } // se li for maior que 8 atribui novamente o valor 4 na var�avel li
                else{
                    if(li < 4){
                        li = 8;
                    } // se li for menor que 4 atribui novamente o valor 8 na var�avel li
                }
                gotoxy(1,li);
                printf(" -> "); // comen�ando da coluna 1 ele vai substituir 4 espa�os pela flechinha
            }
        while(tecla != 13); // enquanto n�o for pressionado a tecla 13(enter) da tabela ascii continua sendo executado
        menu(li); // ao pressionar a tecla 13 vai ser chamado a fun��o menu passando o par�metro da var�avel li
}
// Fun��o que guarda as informa��es do menu Instru��es
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
// Fun��o que guarda as informa��es do menu Informa��es do Desenvolvedor
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
// Fun��o que pede ao usu�rio digitar um nome e a quantidade de pontos e em seguida chama a fun��o Cadastra para cadastrar no arquivo
void menuCadastro(){
    char nome[50];
    int pontos;
    system("cls");
    TrocaCursor(1);
    printf("\nDigite seu nome: ");
    setbuf(stdin, NULL);
    gets(nome);
    printf("\nDigite uma quantidade de pontos: ");
    scanf("%d", &pontos);
    Cadastra(nome,pontos);

    play(nome);
}
// Fun��o que chama a fun��o Listar mostrando os nomes cadastrados e pontos cadastrados
void ranking(){
    system("cls");
    printf("Ranking \n");
    Listar(5);
    printf("\nAperte qualquer tecla para voltar...");
    system("pause>null");
    main();
}
// Fun��o que apresenta o nome rec�m cadastrado
void play(char nome[]){
    system("cls");
    printf("Bem vindo %s \n", nome);
    printf("\n\nAperte qualquer tecla para voltar...");
    system("pause>null");
    main();
}
// Fun��o da escolha do menu
void menu(int select){
    char nome[30];
    switch(select){
    case 4:
        menuCadastro();
        break;
    ;

    case 5:
        instrucoes();
        break;
    ;
    case 6:
        ranking();
        break;
    case 7:
        infodev();
        break;
    case 8:
        exit(0);
        break;
    default:
        main();
    }
}
