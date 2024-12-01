#include <stdio.h>


int main() {

	int x, y, *p; // declara as variaveis e o ponteiro
	y = 0; // variavel inteira y recebe 0
	  printf("y = %d\n", y);
	p = &y; // ponteiro aponta para o endereço de memória de y
	  printf("p = %d\n", p);
	x = *p; // x recebe o valor do endereço de memória de *p, no caso 0
	  printf("x = %d\n", x);
	x = 4; // x passa a valer 4
	  printf("x = %d\n", x);
	(*p)++; // o valor do endereço de memória de *p que no caso é y recebe 1 ao seu valor(0), ficando valendo 1;
	 printf("p = %d\n", *p);
	--x; // x passa a valer 3 pois foi subtraido 1 
	  printf("x = %d\n", x);
	(*p) += x; // o ponteiro aponta para o endereço de y que agora vale 1 e é acresido o valor de x que vale 3, totalizando 4
      printf("p = %d\n", *p);

    return 0; 
}
