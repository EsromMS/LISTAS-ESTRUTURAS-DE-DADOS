#include<stdio.h>
#include<stdlib.h>

//Iniciando a struct com as variaveis necessárias//

typedef struct funcionario{
	char nome[50];
	float salario;
	int identificador;
	char cargo[50];
}Funcionario;

//funçao para preencher um vetor do tipo Funcionario//

void preencher(Funcionario *preenche, int qtd){
	for(int i = 0; i < qtd; i++){
	printf("Informe o nome do funcionario: ");
	scanf(" %[^\n]s", preenche[i].nome);
	printf("Informe o salario: ");
	scanf("%f", &preenche[i].salario);
	printf("Informe o identificador do funcionario: ");
	scanf("%d", &preenche[i].identificador);
	printf("Informe o cargo: ");
	scanf(" %[^\n]s", preenche[i].cargo);

	//Imprimindo as informaçoes alocadas no vetor//

	printf("Nome do funcionario e %s, seu salario e de %.1f, o identificador e %d, com cargo de %s \n", preenche[i].nome, preenche[i].salario, preenche[i].identificador, preenche[i].cargo);
}
}
// funçao para alterar o salario//
float altera (Funcionario * altera, int indice){
	altera[indice].salario += 1000;
}
// funçao para saber qual funcionario tem maior salario e qual tem menor salario//
void maior_menor(Funcionario * mem, int qtd){
 float	menor = 0, maior = 0;
 int indice_maior, indice_menor;
	for(int i = 0; i < qtd; i++){
		if(i == 0){
			menor = mem[i].salario;
		}
		// aqui a funçao vai atualizar o salario maior se caso existir algum que supere//
		if(mem[i].salario > maior){
			maior = mem[i].salario;
			indice_maior = i;
		}
		// aqui a funçao vai atualizar o salario menor se caso existir algum salario menor que o atual//
		if(mem[i].salario < menor){
			menor = mem[i].salario;
			indice_menor = i;
		}
	}
	//imprimindo os funcionarios com maior e menor salario//
	printf("O funcionario com maior salario e %s, com salario de %.1f", mem[indice_maior].nome, mem[indice_maior].salario);
	printf("O funcionario com menor salario e %s, com salario de %.1f", mem[indice_menor].nome, mem[indice_menor].salario);
}

int main (){
	int quantidade, index;
	printf("Informe a quantidade de funcionarios: ");
	scanf ("%i", &quantidade);
// alocando o vetor dinamicamente//
	Funcionario * empresa = (Funcionario*) malloc (quantidade*sizeof(Funcionario) );
	if(empresa == NULL){
		exit (1);
	}
// chamando as funçoes para o programa//
	preencher(empresa, quantidade);
	altera(empresa, 0);
	maior_menor(empresa, quantidade);


	return 0;
}

