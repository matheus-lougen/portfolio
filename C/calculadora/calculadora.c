#include<stdio.h>
#include<stdlib.h>

int main () {
	char operacao;
	float num1;
	float num2;
	float resultado;
	
	while (1) {
		printf("Operacoes possiveis (+, -, /, *)\n");
		printf("Digite a operacao a ser calculada: (Ex. 25 * 3)\n >> ");
		scanf("%f %c %f", &num1, &operacao, &num2);
		switch (operacao) {
			case '+':
				resultado = num1 + num2;
				break;
			case '-':
				resultado = num1 - num2;
				break;
			case '/':
				resultado = num1 / num2;
				break;
			case '*':
				resultado = num1 * num2;
				break;
			default:
				printf("Operação não reconhecida!");
				break;
		}
		printf("%.2f %c %.2f = %.2f\n\n", num1, operacao, num2, resultado);
	}
	
	return 0;
}
