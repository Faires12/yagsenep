#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int main()
{
    int run = true;
    int opc;

    while(run){
        printf("1 - Play\n");
        printf("2 - History\n");
        printf("3 - Rankings\n");
        printf("4 - Credits\n");
        printf("5 - Exit\n");
        scanf("%d", &opc);

        switch(opc){
            case 1:
                printf("Em construcao...\n");
                break;
            case 2:
                printf("History\n");
                break;
            case 3:
                for(int i = 1; i <= 5; i++){
                    printf("%d lugar\n", i);
                }
                break;
            case 4:
                printf("Fares Solibie\nGabriel Felipe\nHenrique Amaral");
                break;
            case 5:
                run = false;
                break;
            default:
                break;
        }
    }
    return 0;
}
