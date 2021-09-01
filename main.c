#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define true 1
#define false 0

int main()
{
    setlocale(LC_ALL, "");

    int run = true, opc;

    while(run){
        system("cls");
        printf("============== Egg Race ==============\n");
        printf("\nEscolha uma das opções:\n");
        printf("1 - Play\n");
        printf("2 - History\n");
        printf("3 - Rankings\n");
        printf("4 - Credits\n");
        printf("5 - Exit\n");
        scanf("%d", &opc);
        system("cls");

        switch(opc){
            case 1:
                printf("Em construção...\n");
                printf("\nPressione qualquer tecla para retornar ao menu\n");
                getch();
            break;
            case 2:
                contarHistória();
                break;
            case 3:
                for(int i = 1; i <= 5; i++){
                    printf("%d lugar\n", i);
                }
                printf("\nPressione qualquer tecla para retornar ao menu\n");
                getch();
            break;
            case 4:
                printf("Desenvolvido pela equipe Mono Migare\n==============\nFares Solibie\nGabriel Felipe Verle\nHenrique Amaral da Silva\n");
                printf("\nPressione qualquer tecla para retornar ao menu\n");
                getch();
            break;
            case 5:
                run = false;
            break;
            default:
                printf("Opção Inválida!\n\nPor Favor, insira um valor válido!\n");
                printf("\n\nPressione qualquer tecla para retornar ao menu\n");
                getch();
            break;
        }
    }
    return 0;
}

void contarHistoria(){
    char text[] =
    "Seu Zé é um trabalhador independente, seu sustento\n"
    "vem da venda diárias de ovos  que ele faz.\n"
    "Com seu negócio crescendo, seu zé decide te\n"
    "contratar para ajudá-lo com as entregas. Com isso seu objetivo\n"
    "agora é vender o maior número de ovos sem atrasar e\n"
    "sem inutilizar o veículo\n";
    for(int i = 0; i < sizeof(text); i++){
        printf("%c", text[i]);
        usleep(30000);
    }
    printf("\nPressione qualquer tecla para retornar ao menu\n");
    getch();
}
