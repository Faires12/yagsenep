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
                break;
            case 2:
                printf("History\n");
                break;
            case 3:
                break;
            case 4:
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
