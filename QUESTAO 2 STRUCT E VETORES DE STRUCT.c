#include <stdio.h>
#include <stdlib.h>

//Definindo quais as informações necessarias na struct//
typedef struct pessoa{
char nome[50];
int documento;
int idade;
}Pessoa;

//funçao para cadastrar cada pessoa//
void cadastra(Pessoa *vetor_de_pessoas,int qnt_pessoas){
    int index;
    //laço para preencher os campos do vetor com cada informação necessaria da struct//
    for(index=0; index < qnt_pessoas; index++){
        printf("Digite o nome da pessoa: ");
        scanf(" %[^\n]s", vetor_de_pessoas[index].nome);
        printf("Digite o documento: ");
        scanf(" %d", &vetor_de_pessoas[index].documento);
        printf("Digite a idade: ");
        scanf("%d", &vetor_de_pessoas[index].idade);
    }
}
//função para definir a pessoa com maior e menor idade//
void maior_menor(Pessoa* mem, int qtd){
 int menor = 0, maior = 0;
 int i, indice_maior, indice_menor;

    for( i = 0; i < qtd; i++){
		if(i == 0){
			menor = mem[i].idade;
		}
        //atualizando as informações da pessoa com maior idade caso surja alguem com a idade superior a atual//
		if(mem[i].idade > maior){
			maior = mem[i].idade;
			indice_maior = i;
		}
		// atualizando as informaçoes da pessoa com menor idade caso exista alguem com a idade menor que a atual//
		if(mem[i].idade < menor){
			menor = mem[i].idade;
			indice_menor = i;
		}
	}
	printf("A Pessoa com maior idade e %s, com idade de %d\n", mem[indice_maior].nome, mem[indice_maior].idade);
	printf("A Pessoa com menor idade e %s, com idade de %d\n", mem[indice_menor].nome, mem[indice_menor].idade);
}

//função para imprmir todas as pessoas listadas e seus dados//

void imprime (Pessoa *pessoa, int index){
    printf("Nome: %s\nDocumento: %d\nIdade: %d\n",pessoa[index].nome,pessoa[index].documento,pessoa[index].idade);
}

int main (){
    int qnt_pessoas, index = 0;
    printf ("Informe a quantidade de alunos: ");
    scanf("%d", &qnt_pessoas);
    Pessoa * vetor_de_pessoas = (Pessoa*) malloc(qnt_pessoas*sizeof(Pessoa));

    if (vetor_de_pessoas==NULL){
        printf("ERRO!!!");
    }
    //chamando as funções//

    cadastra(vetor_de_pessoas,qnt_pessoas);

    imprime(vetor_de_pessoas, 0);

    maior_menor(vetor_de_pessoas,qnt_pessoas);

    //liberando espaço do vetor//

    free(vetor_de_pessoas);

    return 0;
}
