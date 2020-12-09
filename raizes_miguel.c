/*###############################################
# Exercício programa 1
# Autor: Miguel A. N. Garcia
# Data: 11/12/2020
#      Recebe valores para A, B e C e realiza o cáculo das
#      raízes através da fórmula de Bhaskara.
###############################################*/

#include <math.h>
#include <stdio.h>

  int main(){

    int a, b, c, equacao1, equacao2; //define as variáveis
      printf("Defina o valor de A: ");
        scanf( "%d", &a); //salva o valor de A cedido pelo user
      printf("Defina o valor de B: ");
        scanf( "%d", &b); //salva o valor de B cedido pelo user
      printf("Defina o valor de C: ");
        scanf( "%d", &c); //salva o valor de C cedido pelo user

          equacao1 = (-b + (b*b -4 * a * c))/ 2*a; //calcula a raíz 1
          equacao2 = equacao1* -1; //calcula a raíz 2

            printf("As raízes da equação são: %d e %d \n\n", equacao1, equacao2); //imprime o resultado
  }
