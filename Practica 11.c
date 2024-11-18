Palacios Garces Diego
practica 11 -imprimir inverso*/

#include <stdio.h>
#include <string.h>


void imprimir(char[]);

int main ()
{
    char nombre[] = "Facultad de Ingenieria";
    imprimir(nombre);
}

void imprimir(char s[])
{
    int tam;
    for ( tam=strlen(s)-1 ; tam>=0 ; tam--)
        printf("%c", s[tam]);
    printf("\n");
}
Ejercicio 2 
impresiones 
#include <stdio.h>
#include<stdio.h>

int enteraGlobal;

void incremento();

int main()
{
    int cont;
    enteraGlobal = 0; // La función main accede a la variable global
    for (cont=0 ; cont<5 ; cont++)
    {
        incremento();
    }
    return 0;
}
void incremento()
{
    int enteraLocal = 5;
    enteraGlobal += 2;
    printf("global(%i) + local(%i) = %d\n",enteraGlobal, enteraLocal, enteraGlobal+enteraLocal);

Ejercicio 3
#include <stdio.h>
#include <stdlib.h>
#define a 10
#define b 100
void read_comp(int arr[a][b])
{
    int i,j;
    int total, comp;
    //Inicializacion de la matriz
    for(i = 0; i < a; i++)
        for(j = 0; j < b; j++)
            arr[i][j] = 0;
    printf("La matriz se inicializo\n");
    //Lectura de datos
    printf("Introducir el numero de componentes por aparato.\n");
    for(i = 0; i < a; i++)
    {
        printf("Total de componentes del aparato %d: ", i+1);
        scanf("%d", &total);
        for(j = 0; j < total; j++)
        {
            printf("Posición del componente %d: ", j+1);
            scanf("%d", &comp);
            arr[i][comp] = 1;
        }
    }
}
void read_month(int arr[a][b], int arr2[])
{
    int i, j, temp;
    printf("Introducir el numero de aparatos fabricados mensualmente.\n");
    //Lectura de datos mensuales
    for(i = 0; i < a; i++)
    {
        temp  = 0;
        for(j = 0; j < b; j++)
        {
            temp = temp + arr[i][j];
        }
        if (temp != 0)
        {
            printf("Aparato %d: ", i+1);
            scanf("%d", &arr2[i]);
        }
    }
}
void total_month(int arr[a][b], int month[], int total[])
{
    int i, j;
    //Inicializacion del arreglo
    for(i = 0; i < b; i++)
    {
        total[i] = 0;
    }
    //Calculo de los componentes mensuales
    printf("Numero de unidades de cada componente utilizados mensualmente.\n");
    for(i = 0; i < b; i++)
    {
        for(j = 0; j < a; j++)
        {
            total[i] = total[i] + (arr[j][i] * month[j]);
        }
        if(total[i] != 0)
        {
            printf("Componente %d: %d\n", i, total[i]);
        }
        
    }
}
void max_comp(int total[])
{
    int i, comp, max = 0;
    for(i = 0; i < 100; i++)
    {
        if(max < total[i])
        {
            max = total[i];
            comp = i;
        }
    }
    printf("El componente electronico %d es el mas utilizado, se necesitan %d unidades.", comp, max);
}   
int main (int argc, char *argv )
{
    int arr[a][b];
    int month[a], total[b];
    read_comp(arr);
    printf("\n\n");
    read_month(arr, month);
    printf("\n\n");
    total_month(arr, month, total);
    printf("\n\n");
    max_comp(total);
    return 0;
}
Ejercicio 4 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j;
    int var1, var2, bebida, acum, bebida2, acum2, pueblo;
    int max = 0;  
    int max2 = 0;
    int max3 = 0;
    int arr[100][8]; 
    //nombre[8][12] = {"Natural", "Refresco", "Vino", "Cerveza", "Whisky", "Licores", "Energeticos", "Combinados"};
    int total[8] = {0,0,0,0,0,0,0,0};
    int total2[8] = {0,0,0,0,0,0,0,0};
    int total3[100];

    //Inicializar matriz
    for(i = 0; i < 100; i++)
    {
        for(j = 0; j < 8; j++)
        {
            arr[i][j] = 0;
        }
    }
    printf("Se inicializo la matriz de forma correcta.\n");

    //Llenar la matriz con información
    for(i = 0; i <= 99; i++)
    {
        printf("Dame la bebida correspondiente del pueblo %d: ", i);
        scanf("%d", &var1);
        while(var1 != -1)
        {
            printf("Dame la cantidad en litros: ");
            scanf("%d", &var2);
            arr[i][var1] = var2;
            printf("Dame otra bebida: ");
            scanf("%d", &var1);
        }

    }

    //Determinar cual es la bebida mas consumida entre los pueblos
    for(j = 0; j <= 7; j++)
    {
        for(i = 0; i <= 99; i++);
        {
            total[j] = total[j] + arr[i][j];
        }
    }

    for(i = 0; i < 8; i++)
    {
        if(max < total[i])
        {
            max = total[i];
            bebida = i;
        }
    }
    printf("La bebida %d es la bebida que mas se consume con %d litros.\n",
            bebida, max);
    
    //Bebida mas consumida
    for(i = 0; i < 8; i++)
    {
        acum = 0;
        if(i != 1 || i != 6)
        {
            for(j = 0; j < 100; j++)
            {
                acum = acum + arr[j][i];
            }
            total2[i] = acum;
        }
    }

    for(i = 0; i < 8; i++)
    {
        if(max2 < total2[i])
        {
            max2 = total2[i];
            bebida2 = i;
        }
    }
    printf("La bebida %d es la mas consumida con %d litros.\n", bebida2, max2);

    //Pueblo que bebe mas alcohol en total
    for(i = 0; i < 100; i++)
    {
        total3[i] = 0;
    }

    for(i =0; i < 100; i++)
    {
        acum2 = 0;
        for(j = 0; j < 8; j++)
        {
            if(j != 1 || j !=6)
            {
                acum2 = acum2 + arr[i][j];
            }
            
        }
        total3[i] = acum2;
    }

    for(i = 0; i < 100; i++)
    {
        if(max3 < total3[i])
        {
            max3 = total3[i];
            pueblo = i;
        }
    }
    printf("El pueblo %d comsume mas alcohol con %d litros.", pueblo, max3);
    return 0;
    
}
