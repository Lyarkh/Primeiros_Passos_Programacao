#include <stdio.h>
#include <stdlib.h>
//ler 3 valores e verificar se formam um triângulo, se sim, calcule o perímetro, caso negativo, calcule a área do trapezio que tem a e b como base e c como altura.
int main(){

    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);

    if ((abs(b - c) < a < (b + c)) && ((a - c) < b < (a + c)) && ((a - b) < c < (a + b))){
        float perimetro = a + b + c;
        printf("%.1f", perimetro);
    }
    else{
        float area = (((a + b) / 2) * c);
        printf("%.1f", area);
    }
}
