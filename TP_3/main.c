#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
/******************************************************************************
Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 5. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
10. Salir
******************************************************************************/


int main(){
    int nOpcion, flControl;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        fflush(stdin);
        system("cls");
        printf("\n1. Cargar datos de los empleados desde archivo de texto.\n2. Cargar datos de los empleados desde archivo binario.\n3. Alta.\n4. Baja.\n5. Modificacion.\n6. Listar empleados.\n7. Ordenar empleados.\n8. Guardar datos de los empleados en texto.\n9. Guardar datos de los empleados en binario.\n10.Salir.\n");
        scanf("%d",&nOpcion);


        switch(nOpcion){
            case 1:

                flControl = controller_loadFromText("data.csv",listaEmpleados);

                if (flControl){
                    printf("\nArchivo cargado con exito.\n\n");
                }else{
                    printf("\nNo se pudo abrir el archivo.\n\n");
                }

                system("pause");
                break;

            case 2:

                flControl = controller_loadFromBinary("data.bin",listaEmpleados);

                if (flControl){
                    printf("\nArchivo cargado con exito.\n\n");
                }else{
                    printf("\nNo se pudo abrir el archivo.\n\n");
                }

                system("pause");
                break;

            case 3:

                flControl = controller_addEmployee(listaEmpleados);
                system("pause");
                break;

            case 4:

                flControl = controller_removeEmployee(listaEmpleados);
                system("pause");
                break;

            case 5:

                flControl = controller_editEmployee(listaEmpleados);
                system("pause");
                break;

            case 6:

                flControl = controller_ListEmployee(listaEmpleados);
                system("pause");
                break;

            case 7:

                if (ll_len(listaEmpleados)>1){
                    flControl = controller_sortEmployee(listaEmpleados);
                }else{
                    printf("\nEl archivo contiene menos de dos elementos y no se puede ordenar.\n");
                    system("pause");
                }
                break;

            case 8:

                flControl = controller_saveAsText("data.csv",listaEmpleados);


                if (flControl){
                    printf("\nArchivo guardado exitosamente.\n\n");
                }else{
                    printf("\nNo se puede guardar el archivo.\n\n");
                }

                system("pause");
                break;

            case 9:
                flControl = controller_saveAsBinary("data.bin",listaEmpleados);


                if (flControl){
                    printf("\nArchivo guardado exitosamente.\n\n");
                }else{
                    printf("\nNo se puede guardar el archivo.\n\n");
                }

                system("pause");
                break;

            case 10:
                break;
        }
    }while (nOpcion != 10);
    return 0;
}
