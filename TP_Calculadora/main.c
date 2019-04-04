#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"

int main()
{

    int nOpcion, nPrimerOperando=0, nSegundoOperando=0, nSuma = 0, nResta = 0, flag = 0, nMultiplicacion=0, nFactorialA=0, nFactorialB=0;
    float fDivicion;

    do{
        system("cls");
        printf("1. Ingresar 1er operando: (A=%d)\n2. Ingresar 2do operando: (B=%d)\n3. Calcular todas las operaciones\n4. Informar Resultados\n5. Salir ",nPrimerOperando,nSegundoOperando);
        printf("\nIngresar opcion: ");
        scanf("%d", &nOpcion);

        nOpcion=ValidarRango(nOpcion,5,1);

        switch(nOpcion){

            case 1: printf("Ingrese el primer operando: ");
                    scanf("%d", &nPrimerOperando);
                    break;

            case 2: printf("Ingrese el segundo operando: ");
                    scanf("%d", &nSegundoOperando);
                    break;

            case 3: nSuma=Calc_Suma(nPrimerOperando, nSegundoOperando);
                    nResta=Calc_Resta(nPrimerOperando, nSegundoOperando);

                    if(nPrimerOperando == 0 || nSegundoOperando ==0){
                    flag =1;
                    }else{
                    fDivicion = Calc_Divicion(nPrimerOperando, nSegundoOperando);
                    flag=0;
                    }

                    nMultiplicacion= Calc_Multiplicacion(nPrimerOperando, nSegundoOperando);
                    nFactorialA=Calc_Factorial(nPrimerOperando);
                    nFactorialB=Calc_Factorial(nSegundoOperando);
                    break;

            case 4: Calc_Mostrar(nSuma,nResta,fDivicion,nMultiplicacion,nFactorialA,nFactorialB,nPrimerOperando,nSegundoOperando,flag);
                    system("pause");
                    break;

            case 5:
                    break;
        }


    }while(nOpcion != 5);


    return 0;
}
