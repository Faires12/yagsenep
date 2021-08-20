#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int main(){
    int run = true;
    int nums[3];
    int i = 0;
    int soma = 0;
    int produto = 1;
    double media = 0;

    while(run){
        soma = 0;
        produto = 1;
        media = 0;

        for(i=0;i<3;i++){
            printf("Entre com o valor do numero %d :\n", i+1);
            scanf("%d", &nums[i]);

            soma = soma + nums[i];
            produto = produto * nums[i];
            media = media + nums[i];
        }
        media = media/3;

        for(i=1; i<3;i++){
            if(nums[i] < nums[i-1]){
                run = false;
                break;
            }
        }

        if(run){
            printf("Soma: %d\n", soma);
            printf("Produto: %d\n", produto);
            printf("Media: %f\n", media);
        }
    }
    printf("Os numeros nao estao em ordem crescente");
    return 0;
}

