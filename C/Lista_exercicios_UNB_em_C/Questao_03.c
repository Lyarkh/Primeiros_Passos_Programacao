#include <stdio.h>
#include <stdlib.h>


//Calculando salário funcionário multiplicando horas trabalhadas por preço/hora.
int main(){
    int number, horas_t;
    float pag_horas;

    scanf("%d", &number);
    scanf("%d", &horas_t);
    scanf("%f", &pag_horas);

    float total_salario = (float)(horas_t*pag_horas);

    printf("NUMBER = %d\n", number);
    printf("SALARY = U$ %.2f\n", total_salario);

}
