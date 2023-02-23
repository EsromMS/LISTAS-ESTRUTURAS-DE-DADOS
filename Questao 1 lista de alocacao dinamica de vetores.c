#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Função para calcular o percentual de mulheres que gostaram do produto//
float porcentagem_fem (int *genero_aux, int *opiniao_aux, int quantidade_aux){
    float percentual_fem = 0, total_fem = 0;
    int i;
    for(i = 0; i < quantidade_aux; i++){
        if (opiniao_aux[i] == 1 && genero_aux[i] == 0 ){
            percentual_fem++;

        }
    }
    for(i = 0; i < quantidade_aux;i++){
        if(genero_aux[i] == 0){
            total_fem++;
        }
    }
    percentual_fem = (percentual_fem/total_fem) * 100;
return (percentual_fem);
}


//função para calcular o percentual de homens que não gostaram do produto//

float porcentagem_masc (int *genero_aux, int *opiniao_aux, int quantidade_aux){
    float percentual_masc = 0, total_masc = 0;
    int i;
    for(i = 0; i < quantidade_aux; i++){
        if (opiniao_aux[i] == 0 && genero_aux[i] == 1 ){
            percentual_masc++;
        }
    }
    for(i = 0; i < quantidade_aux;i++){
        if(genero_aux[i] == 1){
            total_masc++;
        }
    }
    percentual_masc = (percentual_masc/total_masc) * 100;
return (percentual_masc);
}

int main(){

int quantidade, masc, fem, index, sim, nao;

printf("Quantas pessoas deseja entrevistar? ");
scanf("%d", &quantidade);


//alocando o vetor dinamicamente//
int *genero = (int*) malloc(quantidade * sizeof(int));
int *opiniao = (int*) malloc (quantidade * sizeof (int));

//checagem das respostas//

for(index = 0; index < quantidade; index++){
    printf("Qual seu sexo? masculino (1), feminino (0)\n ");
        scanf("%d", &genero[index]);

    printf("Voce gostou do produto? sim (1), nao(0)\n");
        scanf("%d", &opiniao[index]);

if(genero[index] == 1 && opiniao[index] == 1){
masc++;
sim++;

}
else if (genero[index] == 1 && opiniao[index] == 0){
masc++;
nao++;
}
else if (genero[index] == 0 && opiniao == 1 ){
fem++;
sim++;
}
else if (genero[index] == 0 && opiniao[index] == 0){
fem++;
nao++;
}
}
//Checagem da porcentagem de pessoas do sexo femino que gostaram do produto//
printf("%.1f porcento das pessoas do sexo feminino gostaram do produto\n", porcentagem_fem(genero, opiniao, quantidade));
//Checagem da porcentagem de pessoas do sexo masculino que não gostaram do produto//
printf("%.1f porcento das pessoas do sexo masculino nao gostaram do produto", porcentagem_masc(genero, opiniao, quantidade));

return 0;
}
