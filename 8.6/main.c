#include <stdio.h>
 #include <string.h>

 /* Comercializadora farmac�utica.
 El programa maneja informaci�n sobre ventas, inventario, reabastecimiento y nuevos productos de una comercializadora farmac�utica. */

 typedef struct  /* Declaraci�n de la estructura producto. */
 {
 int clave;
 char nombre[15];
 float precio;
 int existencia;
 } producto;
 void Lectura(producto *, int);                /*Prototipos de funciones. */

void Ventas(producto *, int);
 void Reabastecimiento(producto *, int);
 void Nuevos_Productos(producto *, int *);
void Inventario(producto *, int);
 void main(void)
 {
 producto INV[100];
 /* Se declara un arreglo unidimensional de tipo estructura producto. */
 int TAM, OPE;
 do
 {
 printf("Ingrese el n�mero de productos: ");
 scanf("%d", &TAM);
 }
 while (TAM > 100  | | TAM < 1);
/* Se verifica que el n�mero de productos ingresados sea correcto. */
 Lectura(INV, TAM);
 printf("\nIngrese operaci�n a realizar. \n\t\t1 � Ventas \n\t\t 2 Reabastecimiento \n\t\t   3 - Nuevos Productos \n\t\t 4 � Inventario \n\t\t   0 - Salir: ");
 scanf("%d", &OPE);
 while (OPE)
 {
 switch (OPE)
 {
 case1: Ventas(INV, TAM);
 break;
 case2: Reabastecimiento(INV, TAM);
 break;
 case3: Nuevos_Productos(INV, &TAM);
/* Se pasa el par�metro por referencia, porque se puede modificar el n�mero de elementos del arreglo en la funci�n. */
 break;
 case4: Inventario(INV, TAM);
 break;
 };
 printf("\nIngrese operaci�n a realizar. \n\t\t1 � Ventas \n\t\t 2 Reabastecimiento \n\t\t 3 - Nuevos Productos \n\t\t 4 � Inventario \n\t\t   0 - Salir: ");
 scanf("%d", &OPE);
 }
 }
 void ectura(producto A[], intT)
 /* Esta funci�n se utiliza para leer un arreglo unidimensional de tipo estructura productode Telementos. */
 {
 int I;
 for (I=0; I<T; I++)
 {
 printf("\nIngrese informaci�n del producto %d", I+1);
 printf("\n\tClave: ");
 scanf("%d", &A[I].clave);
 fflush(stdin);
  printf("\tNombre:");
 gets(A[I].nombre);
 printf("\tPrecio:");
 scanf("%f", &A[I].precio);
 printf("\tExistencia: ");
 scanf("%d", &A[I].existencia);
 }
 }
 void Ventas(producto A[], int T)
 /* Esta funci�n se utiliza para manejar las venta a un cliente. Se ingresan productos y cantidades, el fin de datos est� dado por el cero. Adem�s de obtener el total de las ventas, se actualiza el inventario. */
 {
 int CLA, CAN, I, RES;
 float TOT, PAR;
 printf("\nIngrese clave del producto -0 para salir-: ");
 scanf("%d", &CLA);
 TOT = 0.0;
 while(CLA)
 {
 printf("\tCantidad: ");
 scanf("%d", &CAN);
 I = 0;
 while ((I < T) && (A[I].clave < CLA))
/* Se realiza una b�squeda para localizar la clave del producto. */
 I++;
 if ((I == T) | | (A[I].clave > CLA))
 printf("\nLa clave del producto es incorrecta");
 else
 if(A[I].existencia >= CAN)
 /* Se analiza si el stock es suficiente para satisfacer el pedido. */
 {
 A[I].existencia -= CAN;    /* Se actualiza el stock del producto. */
 PAR = A[I].precio * CAN;
 TOT += PAR;
 }
 else
 {
 printf("\nNo existe en inventario la cantidad solicitada. Solo hay %d", A[I].existencia);
 printf(" \nLos lleva 1 - Si   0 � No?: ");
scanf("%d", &RES);
 if(RES)
 {
 PAR = A[I].precio * A[I].existencia;
 A[I].existencia = 0;          /* El stock queda en cero. */
 TOT += PAR;
 }
 }

