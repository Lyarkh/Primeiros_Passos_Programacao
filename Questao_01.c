#include <stdio.h>
#include <math.h>


// código para calcular a distância entre dois pontos.

int main()
{
    printf("Digite X1 e Y1: ");
    double x1,y1 = scanf("%f %f", &x1, &y1);

    printf("Digite X1 e Y2: ");
    double x2,y2 = scanf("%f %f", &x2, &y2);

    double distancia = sqrt(pow(x2-x1,2)+pow(y2-y1,2));

    printf("%.4f", distancia);
}
