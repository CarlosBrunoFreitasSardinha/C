#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, b;
	printf("Informe o valor de a: ");
	scanf("%d",&a);
	printf("Informe o valor de b: ");
	scanf("%d",&b);
	printf("\n\nValor A: %d Valor B: %d\n", a,b);
	a = a*b;
	b = a/b;
	a = a/b;
	printf("Valor A: %d Valor B: %d", a,b);
}
