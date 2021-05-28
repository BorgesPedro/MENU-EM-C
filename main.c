#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

/******
Código desenvolvido por Pedro Henrique Borges para prova de Algoritmo
Engenharia da Computaçãoo - IFTM 1º Período 2021
******/

void gotoxy(int x, int y){

    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void tela(void)
{
    int col, lin;
    lin = 5;
    for(col= 30;col <= 80;col++)
    {
        gotoxy(col,lin);
        printf("*");
    }


    lin = 23;
    for(col= 30;col <= 80;col++)
    {
        gotoxy(col,lin);
        printf("*");
    }

    col = 30;
    for (lin = 5;lin <= 23;lin++)
    {
        gotoxy(col,lin);
        printf("*\n");
    }

    col = 80;
    for (lin = 5;lin <= 23;lin++)
    {
        gotoxy(col,lin);
        printf("*\n");
    }

    gotoxy(47,7);
    printf("MENU DE OPÇÕES");
    gotoxy(47,8);
    printf("==============");
    gotoxy(35,11);
    printf("1 – Caclular médias.");
    gotoxy(35,12);
    printf("2 – Cálculo de áreas.");
    gotoxy(35,13);
    printf("3 – Quadrado perfeito.");
    gotoxy(35,14);
    printf("4 – Sair.");

    gotoxy(32,17);
    printf("Escolha o número de uma das opções acima...:");

}

int validacao(int x)
{
    while (x < 0 || x >100)
    {
        printf("Valor incorreto, digite novamente: ");
        scanf("%d",&x);
    }

    return (x);
}
void mensagem()
{
    gotoxy(32,21);
    printf("VALOR INCORRET0, DIGITE NOVAMENTE");
    gotoxy(76,17);
    printf("  ");
    getch();
    gotoxy(32,21);
    printf("                                 ");
}
void emmanutencao(void)
{
    gotoxy(32,21);
    printf("Em manutenção!");
    getch();

}
//medias
float aritmetica(int nota1, int nota2, int nota3){
    float media;
    media = ((nota1+nota2+nota3)/3);

    return(media);
}

float media_ponderada(int nota1, int nota2, int nota3){
    int peso1 = 5, peso2 = 3, peso3 = 2;
    float media;
    media = ((nota1*peso1)+(nota2*peso2)+(nota3*peso3))/(peso1+peso2+peso3);

    return(media);
}

float harmonica(int nota1, int nota2, int nota3){
    float conjunto1,conjunto2,conjunto3;
    float n1 = nota1, n2 = nota2, n3 = nota3;
    float media;

    conjunto1 = 1/n1;
    conjunto2 = 1/n2;
    conjunto3 = 1/n3;

    media = 3/(conjunto1+conjunto2+conjunto3);
    return (media);
}
//calculo de areas
int areas(int lados, int lado1, int lado2){
    int area;

    printf("Quantos lados o poligono tem? ");
    scanf("%d", &lados);

    if(lados != 3 && lados != 4 && lados != 6){
        printf("Não sei medir os lados");
    }else{
        switch(lados){
            case 3:
                printf("Digite o primeiro lado: ");
                scanf("%d", &lado1);
                printf("Digite o segundo lado: ");
                scanf("%d", &lado2);
                area = lado1*lado2*1.73/4;
                printf("A area do tringulo é %d", area);
                break;
                case 4:
                printf("Digite o primeiro lado: ");
                scanf("%d", &lado1);
                printf("Digite o segundo lado: ");
                scanf("%d", &lado2);
                printf("%d, %d", lado1, lado2);
                area = lado1*lado2;
                printf("A area do quadrado é %d", area);
                break;
                case 6:
                printf("Digite o primeiro lado: ");
                scanf("%d", &lado1);
                printf("Digite o segundo lado: ");
                scanf("%d", &lado2);
                printf("%d, %d", lado1, lado2);
                area = 6*lado1*lado2*1.73/4;
                printf("A area do hexagono é %d", area);
                break;
        }
    }

}

//calculo de quadrado perfeito
int quadradoperfeito(int valor){
    int m, soma=0, contador, resultado;
    printf("Digite um numero: ");
    scanf("%d",&valor);

    for(contador=1; soma < valor; contador+=2){
        soma += contador;
    }

    m = ((contador+1) / 2) - 1;

    if((m*m) == valor){
        resultado = -999;
    };

    return(resultado);
}

int main()
{

    char opcao[2];
    int nota1, nota2, nota3;
    float resultadomedia;
    int lados, lado1, lado2;
    int numero;
    int resultado;
    setlocale(LC_ALL,"Portuguese");

    tela();

    int opc = 0;

    gotoxy(76,17);
    scanf("%d",&opc);
    while (opc <1 || opc > 4)
      {
        mensagem();
        gotoxy(76,17);
        scanf("%d",&opc);
    }
    do {

        switch (opc)
        {
        case 1:
            system("cls");
            printf("Escolha uma opção: \n");
            printf("A - Média aritmética\n");
            printf("P - Média Ponderada\n");
            printf("H - Média Harmônica\n");
            printf("V - Voltar\n");
            printf("> ");
            scanf("%s", opcao);

            switch(opcao[0]){
                case 'A':
                    system("cls");
                    printf("Digite uma nota: ");
                    scanf("%i", &nota1);
                    printf("Digite outra nota: ");
                    scanf("%i", &nota2);
                    printf("Digite a ultima nota: ");
                    scanf("%i", &nota3);
                    resultadomedia = aritmetica(nota1, nota2, nota3);
                    printf("A media aritmetica é: %.2f", resultadomedia);
                    getch();
                    break;
                case 'P':
                    system("cls");
                    printf("Digite uma nota: ");
                    scanf("%i", &nota1);
                    printf("Digite outra nota: ");
                    scanf("%i", &nota2);
                    printf("Digite a ultima nota: ");
                    scanf("%i", &nota3);
                    resultadomedia = media_ponderada(nota1, nota2, nota3);
                    printf("A media ponderada é: %.2f", resultadomedia);
                    getch();
                    break;
                case 'H':
                    system("cls");
                    printf("Digite uma nota: ");
                    scanf("%i", &nota1);
                    printf("Digite outra nota: ");
                    scanf("%i", &nota2);
                    printf("Digite a ultima nota: ");
                    scanf("%i", &nota3);
                    resultadomedia = harmonica(nota1, nota2, nota3);
                    printf("A media harmônica é: %.2f", resultadomedia);
                    getch();
                    break;
                case 'V':
                    break;
                default:
                    break;

            }
            break;
        case 2:
            system("cls");
            resultado = areas(lados, lado1, lado2);
            getch();
            break;
        case 3:
            system("cls");
            resultado = quadradoperfeito(numero);
            if(resultado == -999){
                printf("Quadrado perfeito!");
            }else{
                printf("Não é quadradro perfeito");
            }
            getch();
            break;
        case 4:
            gotoxy(32,21);
            printf("Programa Encerrado");
            return 0;
        }
        system("cls");
        tela();
        gotoxy(76,17);
        scanf("%d",&opc);
        while (opc <1 || opc > 4)
        {
            mensagem();
            gotoxy(76,17);
            scanf("%d",&opc);

        }
    }while (opc != 4);

    system("pause");
    return 0;
}
