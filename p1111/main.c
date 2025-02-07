#include <stdio.h>
#include <stdlib.h>

//flujo
//seleccion
//repeticion
int main()
{
    //0-1 es un infante
    //1-12 es un nino
    //13-17 es un adolecente
    //18-40 es un adulto
    //41-78 es un adulto mayor
    //79-120 es un envejeciente
//tipo    indentificador    inicializacion
  int         edad           = 0;
    printf("\nIngrese su edad: ");
    scanf("%d",&edad);

    if(edad >= 0 && edad <=120)
    {
      if(edad <= 1)
      {
          printf("\nUsted es un infante");
      }else if(edad <= 12)
      {
          printf("\nUsted es un nino");
      }else if(edad <= 17)
      {
          printf("\nUsted es un adolecente");
      }else if(edad <= 40)
      {
         printf("\nUsted es un adulto");
      }else if(edad <= 78)
      {
          printf("\nUsted es un adulto mayor");
      }else if(edad <= 120)
      {
          printf("\nUsted es un envejeciente");
      }
    }else
    {
      printf("\nEdad no valida");
      printf("\nEdad debe ser un valor de 0 a 120");
    }


    printf("\n\n\n----Fin del Programa----");
    return 0;
}
