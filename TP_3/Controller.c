#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#define TAM 50


/** \brief Carga los datos desde txt
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){

    FILE *text;
    int retorno = 0;

    if ((text = fopen(path, "r"))!=NULL){

        retorno = parser_EmployeeFromText(text, pArrayListEmployee);
    }

    fclose(text);

    return retorno;

}

/** \brief Carga los datos de los empleados desde bin
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){

    FILE *binary;
    int retorno = 0;

    if ((binary = fopen(path, "rb")) != NULL){

        retorno = parser_EmployeeFromBinary(binary, pArrayListEmployee);
    }
    fclose(binary);
    return retorno;
}

/** \brief Alta
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_addEmployee(LinkedList* pArrayListEmployee){

    Employee* pEmpleado = NULL;
    Employee* auxEmpleado = employee_new();

    int retorno = 0, nControl, nAuxiliar[4];
    char szNombre[TAM], szId[10], szHorasTrabajadas[5] , szSueldo[15];

    system("cls");
    printf("*** Alta empleado ***\n");

    do{

        fflush(stdin);
        printf("\nIngrese el ID: ");
        fgets(szId, 10-2, stdin);

        nAuxiliar[0] = isDigit(szId);

        if (nAuxiliar[0]){

            nControl = controller_findEmployee(pArrayListEmployee, atoi(szId));
        }

    }while (nControl != -1);

    if (nControl == -1){

        printf("\nID libre [%s]\n",szId);

        do{

            fflush(stdin);
            printf("\nIngrese el nombre: ");
            fgets(szNombre, TAM-2, stdin);

            nAuxiliar[0] = areCharacters(szNombre);

        }while (nAuxiliar[0] == 0);

        do{

            fflush(stdin);
            printf("\nIngrese horas trabajadas: ");
            scanf("%s",szHorasTrabajadas);

            nAuxiliar[0] = isDigit(szHorasTrabajadas);

        }while (nAuxiliar[0] == 0);

        do{

            fflush(stdin);
            printf("\nIngrese el sueldo: ");
            scanf("%s",szSueldo);

            nAuxiliar[0] = isFloat(szSueldo);

        }while (nAuxiliar[0] == 0);

        nAuxiliar[0] = employee_setId(auxEmpleado, atoi(szId));

        if (!nAuxiliar[0]){

            printf("\nEl ID se encuentra fuera de rango.\n");
        }

        nAuxiliar[1] = employee_setNombre(auxEmpleado, szNombre);

        if (!nAuxiliar[1]){

            printf("\nEl nombre es invalido.\n");
        }

        nAuxiliar[2] = employee_setHorasTrabajadas(auxEmpleado, atoi(szHorasTrabajadas));

        if (!nAuxiliar[2]){
            printf("\nLas horas trabajadas se encuentran fuera de rango.\n");
        }

        nAuxiliar[3] = employee_setSueldo(auxEmpleado, atof(szSueldo));

        if (!nAuxiliar[3]){
            printf("\nEl sueldo se encuentra fuera de rango.\n");
        }

        if (nAuxiliar[0] && nAuxiliar[1] && nAuxiliar[2] && nAuxiliar[3]){//1

            pEmpleado = employee_newParametros(szId , szNombre, szHorasTrabajadas, szSueldo);

            if (pEmpleado != NULL){//2
                nControl= ll_add(pArrayListEmployee,pEmpleado);

                if (nControl){
                    printf("\nEmpleado no cargado exitosamente.\n\n");
                }

                else{

                    printf("\nEmpleado cargado exitosamente.\n\n");
                }
            }//2

            else{
                printf("\nNo se pudo conseguir memoria libre.\n");
            }
        }//1
        else{
            printf("\nEmpleado no cargado exitosamente (algun valor fuera de rango).\n\n");
        }
    }
    free(pEmpleado);
    free(auxEmpleado);
    return retorno;
}

/** \brief Modificar
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee){

    Employee* pEmpleado = NULL;
    Employee* auxEmpleado = employee_new();

    char szNombre[TAM], szId[10], szHorasTrabajadas[5] , szSueldo[15], szOpcion = '0';
    int nAuxiliar, nControl, nIndex, retorno = 0, flag = 0;

    system("cls");

    printf("*** Modificar empleado ***\nIngrese el ID: ");
    fflush(stdin);
    fgets(szId, 10-2, stdin);

    nIndex = controller_findEmployee(pArrayListEmployee, atoi(szId));

    if (nIndex != -1){

        pEmpleado = (Employee*) ll_get(pArrayListEmployee, nIndex);
        fflush(stdin);

        printf("\n1- Modificar ID [%d].\n2- Modificar Nombre [%s].\n3- Modificar horas trabajadas [%d].\n4- Modificar Salario [%6.2f].\n5- Volver al menu principal.\n",pEmpleado->id,pEmpleado->nombre,pEmpleado->horasTrabajadas,pEmpleado->sueldo);
        scanf("%c",&szOpcion);

        switch(szOpcion){

            case '1':

                do{

                    fflush(stdin);
                    printf("\nIngrese el NUEVO ID: ");
                    fgets(szId, 10-2, stdin);

                    nAuxiliar = isDigit(szId);

                    if (nAuxiliar){
                        nControl = controller_findEmployee(pArrayListEmployee, atoi(szId));
                    }
                }while (nControl != -1);

                nAuxiliar = employee_setId(auxEmpleado, atoi(szId));

                if (nAuxiliar){

                    employee_setId(pEmpleado, atoi(szId));
                    flag = 1;

                }else{
                    printf("\nEl ID se encuentra fuera de rango.\n");
                }

                break;

            case '2':

                do{
                    fflush(stdin);

                    printf("\nIngrese el NUEVO nombre: ");
                    fgets(szNombre, TAM-2, stdin);


                    nAuxiliar = areCharacters(szNombre);

                }while (nAuxiliar == 0);

                nAuxiliar = employee_setNombre(auxEmpleado, szNombre);

                if (nAuxiliar){

                    employee_setNombre(pEmpleado, szNombre);

                    flag = 1;

                }else{

                    printf("\nEl nombre es invalido.\n");
                }

                break;

            case '3':

                do{
                    fflush(stdin);
                    printf("\nIngrese horas trabajadas: ");
                    scanf("%s",szHorasTrabajadas);

                    nAuxiliar = isDigit(szHorasTrabajadas);

                }while (nAuxiliar == 0);

                nAuxiliar = employee_setHorasTrabajadas(auxEmpleado, atoi(szHorasTrabajadas));

                if (nAuxiliar){

                    employee_setHorasTrabajadas(pEmpleado, atoi(szHorasTrabajadas));
                    flag = 1;
                }
                else{
                    printf("\nLas horas trabajadas se encuentran fuera de rango.\n");
                }

                break;

            case '4':

                do{

                    fflush(stdin);
                    printf("\nIngrese el sueldo: ");
                    scanf("%s",szSueldo);

                    nAuxiliar = isFloat(szSueldo);

                }while (nAuxiliar == 0);

                nAuxiliar = employee_setSueldo(auxEmpleado, atof(szSueldo));

                if (nAuxiliar){

                    employee_setSueldo(pEmpleado, atof(szSueldo));
                    flag = 1;

                }else{

                    printf("\nEl sueldo se encuentra fuera de rango.\n");
                }

                break;
        }
        if (flag){
            printf("\nEmpleado modificado exitosamente.\n");
        }
        else{
            printf("\nEmpleado no modificado.\n");
        }
    }
    else{
        printf("\nEmpleado no encontrado.\n");
    }

    printf("\n");
    return retorno;
}

/** \brief Baja
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee){

    Employee* pEmpleado;
    int nIndex, retorno = 0;
    char szId[10], szOpcion;

    system("cls");

    printf("*** Borrar empleado ***\nIngrese el ID: ");
    fflush(stdin);
    fgets(szId, 10-2, stdin);


    nIndex = controller_findEmployee(pArrayListEmployee, atoi(szId));

    if (nIndex != -1){

        pEmpleado = (Employee*) ll_get(pArrayListEmployee, nIndex);
        printf("\nEmpleado a borrar:\nID\tNombre\t\tHoras\tSueldo\n");
        printf("\n%4d\t%s\t\t%d\t%6.2f\n",pEmpleado->id,pEmpleado->nombre,pEmpleado->horasTrabajadas,pEmpleado->sueldo);

        printf("\n%cEst%c seguro? S/N: ", 168, 160);
        fflush(stdin);
        scanf("%c",&szOpcion);

        if (szOpcion == 's' || szOpcion == 'S'){

            retorno =  !ll_remove(pArrayListEmployee, nIndex);
            printf("\nBorrado exitoso.\n");
        }
        else{
            printf("\nBorrado cancelado.\n");
        }
    }
    else{
        printf("\nEmpleado no encontrado.\n");
    }

    printf("\n");
    return retorno;
}


/** \brief Listar
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_ListEmployee(LinkedList* pArrayListEmployee){

    Employee *pEmpleado;
    int i, retorno = 1;

    system("cls");

    for (i=0; i < ll_len(pArrayListEmployee); i++){

        pEmpleado = ll_get(pArrayListEmployee, i);
        printf("%5d %20s %3d %6.2f\n",pEmpleado->id,pEmpleado->nombre,pEmpleado->horasTrabajadas,pEmpleado->sueldo);

        if(i==500){
            getche();
        }
    }
    printf("\n");

    return retorno;
}


/** \brief Ordenar
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_sortEmployee(LinkedList* pArrayListEmployee){

    int retorno = 0;
    char opcion;

    do{

        system("cls");
        printf("*** Ordenar empleados ***\n1- Ordenar por ID.\n2- Ordenar por nombre.\n3- Ordenar por horas trabajadas.\n4- Ordenar por sueldo.\n5- Volver al menu principal.\nElija una opcion: ");
        fflush(stdin);
        scanf("%c",&opcion);

        switch (opcion){

            case '1':

                ll_sort(pArrayListEmployee,employee_sortById,1);
                retorno = 1;
                break;

            case '2':

                ll_sort(pArrayListEmployee,employee_sortByNombre,1);
                retorno = 1;
                break;

            case '3':

                ll_sort(pArrayListEmployee,employee_sortByHorasTrabajadas,1);
                retorno = 1;
                break;

            case '4':

                ll_sort(pArrayListEmployee,employee_sortBySueldo,1);
                retorno = 1;
                break;

        }

    }while (opcion != '5');

    return retorno;
}


/** \brief Guardar txt
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){

    FILE* text;
    Employee* this;
    int retorno = 0, largo, i;
    text = fopen(path, "w");
    largo = ll_len(pArrayListEmployee);

    if(text != NULL && pArrayListEmployee != NULL){

        fprintf(text, "id,nombre,horasTrabajadas,sueldo\n");

        for(i=0; i < largo; i++){

            this = (Employee*) ll_get(pArrayListEmployee, i);

            fprintf(text, "%d,%s,%d,%.2f\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        }
        retorno = 1;
    }

    fclose(text);

    return retorno;
}


/** \brief Guarda bin
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){

    FILE* binary;
    Employee* this;
    int retorno = 0, largo, i;

    binary = fopen(path, "wb");

    largo = ll_len(pArrayListEmployee);

    if(binary != NULL && pArrayListEmployee != NULL){

        for(i=0; i<largo; i++){

            this = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(this, sizeof(Employee), 1, binary);
        }
        retorno = 1;
    }

    fclose(binary);
    return retorno;

}


/** \brief Buscar el ID
 *
 * \param pArrayListEmployee LinkedList*
 * \param ID int
 * \return int
 *
 */


int controller_findEmployee(LinkedList* pArrayListEmployee, int id){

    Employee* pEmpleado;
    int i, retorno = -1;

    for (i=0; i < ll_len(pArrayListEmployee); i++){

        pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);

        if (id == pEmpleado->id){

            retorno = i;

            break;
        }
    }

    return retorno;
}

