#include<stdio.h>
#include<stdlib.h>

float soma (float num1, float num2) {
	return num1 + num2;
}

float subtracao (float num1, float num2) {
	return num1 - num2;
}

float divisao (float num1, float num2) {
	return num1 / num2;
}

float multiplicacao (float num1, float num2) {
	return num1 * num2;
}

int main () {
	char operacao;
	float num1;
	float num2;
	float resultado;
	
	while (1) {
		printf("Digite a operação a ser calculada: (Ex. 25 * 3)\n >> ");
		scanf("%f %c %f", &num1, &operacao, &num2);
		switch (operacao) {
			case '+':
				resultado = soma(num1, num2);
				break;
			case '-':
				resultado = subtracao(num1, num2);
				break;
			case '/':
				resultado = divisao(num1, num2);
				break;
			case '*':
				resultado = multiplicacao(num1, num2);
				break;
		}
		printf("%.2f %c %.2f = %.2f\n\n", num1, operacao, num2, resultado);
	}
	
	return 0;
}
