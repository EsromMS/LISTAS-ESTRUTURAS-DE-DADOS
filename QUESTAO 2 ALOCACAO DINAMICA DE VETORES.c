#include <stdio.h>
#include <stdlib.h>

int main(){

int index, cont, percentual;
int resposta = 0;
float qtd_questoes, nota = 0;

//Aramazenando a quantidade de questoes//
printf("Quantas questoes a prova possui?\n");
scanf("%f", &qtd_questoes);

//Alocando dinamicamente os vetores//
float *prova = (float*) malloc(10*sizeof(float));
int *gabarito = (int*) malloc(qtd_questoes*sizeof(int));


//Preenchendo o gabarito da prova//
printf("Preencha o gabarito da prova com (1) (2) (3)\n");
for(index = 0; index<qtd_questoes; index++){
    printf("Gabarito da questao %d : ", index+1);
    scanf("%d", &gabarito[index]);
}

//Alunos respondem as provas e a variavel nota vai armazenar seus pontos//
for ( index = 0; index < 10; index++){
    for (cont = 0; cont < qtd_questoes; cont++){
        printf("Responda a questao %d do aluno %d: ",cont+1,index+1);
        scanf("%d", &resposta);
        if(resposta == gabarito[cont]){
            nota += 10/qtd_questoes;
        }
    }
    prova[index] = nota;
    nota = 0;
}
//Imprimindo a nota de cada aluno e seu percentual//
for ( index = 0; index < 10; index++){
    printf("Aluno - %d nota - %.1f\n",index+1,prova[index]);
    if (prova[index]>=6){
        percentual++;
    }
    }
printf("Percentual de alunos aprovados e de: %d%%", percentual*10);


return 0;
}
