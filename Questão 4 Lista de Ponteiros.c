#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//fun�ao para calcular a area e o perimetro de um hexagono//

void calcula_hexagono(float l, float *area, float *perimetro){

	*area = ((3 * pow(l,2)) * sqrt(3))/ 2;
	*perimetro = 6 * l;

	//imprimindo os resultados//
    printf("Area %.1f \nPerimetro %.1f\n", *area,  *perimetro);
    system("Pause");
}

int main(){
	float lado = 0, *area, *perimetro;

	// aqui o usu�rio ir� informar o tamanho do lado//
	printf("Informe o tamanho do lado -> ");
	scanf("%f", &lado);

	// chamando a fun��o para calcular ap�s ter recebido o tamanho//
	calcula_hexagono(lado, &area, &perimetro);

	return 0;
}
