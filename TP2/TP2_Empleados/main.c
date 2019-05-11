#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define ELEMENTOS 1000

int main()
{

    Employee eEmpleados[ELEMENTOS];
    char seguir='s';
    int nOpcion, nOpcionMostrar;

    initEmployees(eEmpleados,ELEMENTOS);

    do{
        //system("CLS");
        printf("1.Alta\n2.Modificar\n3.Baja\n4.Informar\n5.Salir\n");
        scanf("%d", &nOpcion);
        while(ValidarRangoEntero(nOpcion,5,1)!=0){

            printf("Reingrese Opcion: ");
            fflush(stdin);
            scanf("%d",&nOpcion);
        }

        switch(nOpcion){


                    case 1: DarAltaEmpleado(eEmpleados,ELEMENTOS);
                            break;



                    case 2: printEmployees(eEmpleados,ELEMENTOS);
                            ModificarEmpleado(eEmpleados, ELEMENTOS);
                            break;


                    case 3: printEmployees(eEmpleados,ELEMENTOS);
                            BajaEmployee(eEmpleados,ELEMENTOS);
                            break;


                    case 4:
                            printf("1.Listar empleados alfabeticamente\n2.Mostrar total y promedio de los salarios\n3.Volver al menu principal\n");
                            fflush(stdin);
                            scanf("%d", &nOpcionMostrar);
                            while(ValidarRangoEntero(nOpcionMostrar,3,1)!=0){

                                printf("Reingrese Opcion: ");
                                fflush(stdin);
                                scanf("%d",&nOpcionMostrar);
                            }

                            switch(nOpcionMostrar){

                                case 1: sortEmployees(eEmpleados,ELEMENTOS,1);
                                        printEmployees(eEmpleados,ELEMENTOS);
                                        break;

                                case 2: MostrarTotalSalarios(eEmpleados,ELEMENTOS);
                                        break;
                                case 3:
                                        break;

                            }
                            break;


                    case 5: seguir='n';
                            break;
        }

    }while(seguir=='s');




    return 0;
}
