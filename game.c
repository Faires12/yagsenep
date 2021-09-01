#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define true 1
#define false 0

void voltarMenu(int run){
    if(run == true){
        printf("\n\nPressione qualquer tecla para retornar ao menu...\n");
    }else{
        printf("\n\nPressione qualquer tecla para fechar o jogo...\n");
    }  
    getch();
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
}

void rankings(){
    printf("============================\n");
    printf("Rankings EggRace\n");
    printf("============================\n");
    for(int i = 1; i <= 5; i++){
        printf("# lugar #");
    }
}

void creditos(){
    printf("Desenvolvido pela equipe Mono Migare\n");
    printf("==============\n");
    printf("Fares Solibie\nGabriel Felipe Verle\nHenrique Amaral da Silva\n");
}

void ShowMenu(){
    system("cls");
    printf("============== Egg Race ==============\n");
    printf("\nEscolha uma das opções:\n");
    printf("1 - Play\n");
    printf("2 - History\n");
    printf("3 - Rankings\n");
    printf("4 - Credits\n");
    printf("5 - Exit\n");    
}

void jogar(){
    printf("Aguarde... Jogo ainda em Desennvolvimento...");
}

int main()
{
    setlocale(LC_ALL, "");

    int run = true, opc;

    while(run){
        //Menu do jogo
        ShowMenu();
        scanf("%d", &opc);
        system("cls");
        switch(opc){
            case 1: //1- Play
                printf("Em construção...\n");
            break;
            case 2: //2- História
                contarHistoria();
            break;
            case 3: //3- Rankings
                rankings();
            break;
            case 4: //4- Créditos
                creditos();
            break;
            case 5: //5- Sair
                run = false;
            break;
            default: //Inválido
                printf("Opção Inválida!\n\nPor Favor, insira um valor válido!\n");
            break;
        }
        voltarMenu(&run);
    }
    return 0;
}