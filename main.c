#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define true 1
#define false 0

typedef struct{
    char nome[5];
    int pontuacao;
} Ranking;

void voltarMenu(int run){
    if(run == true){
        printf("\n\nPressione qualquer tecla para retornar ao menu...\n");
    }else{
        printf("\n\nPressione qualquer tecla para fechar o jogo...\n");
    }
    getch();
}

void contarHistoria(){
    int i;
    char text[] =
    "Seu Zé é um trabalhador independente, seu sustento\n"
    "vem da venda diárias de ovos  que ele faz.\n"
    "Com seu negócio crescendo, seu zé decide te\n"
    "contratar para ajudá-lo com as entregas. Com isso seu objetivo\n"
    "agora é vender o maior número de ovos sem atrasar e\n"
    "sem inutilizar o veículo\n";
   for(i = 0; i < sizeof(text); i++){
        printf("%c", text[i]);
        usleep(30000);
    }
}

void rankings(){
    FILE *pf;
    Ranking ranking;
    Ranking rankings[100];
    int index = 0;

    printf("============================\n");
    printf("Rankings EggRace\n");
    printf("============================\n");

    pf = fopen("rankings.txt", "wb");
    for(int i = 0; i < 5; i++){
        scanf("%s", &ranking.nome);
        ranking.pontuacao = i*100;
        fwrite(&ranking, sizeof(ranking), 1, pf);
    }
    fclose(pf);
    
    pf = fopen("rankings.txt", "rb");
    while(fread(&ranking, sizeof(ranking), 1, pf) == 1){
        if(index < 100){
            rankings[index] = ranking;
            index++;
        }   
    }
    fclose(pf);

    for(int i = 0; i < index; i++){
        int maior = i;
        for(int j = i+1; j < index; j++){
            if(rankings[j].pontuacao > rankings[maior].pontuacao)
                maior = j;
        }
        Ranking temp = rankings[maior];
        rankings[maior] = rankings[i];
        rankings[i] = temp;
    }

    for(int i = 0; i < index; i++){
        printf("%d lugar - %s, pontuacao: %d\n", i+1, rankings[i].nome, rankings[i].pontuacao);
    }
}

void creditos(){
    printf("Desenvolvido pela equipe Mono Migare\n");
    printf("==============\n");
    printf("Fares Solibie\nGabriel Verle\nHenrique Amaral da Silva\n");
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
    int i;
    char text[] =
    "hmm...\n"
    "Você me parece um bom motorista";
    for(i = 0; i < sizeof(text); i++){
        printf("%c", text[i]);
        usleep(30000);
    }
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
                jogar();
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
        voltarMenu(run);
    }
    return 0;
}
