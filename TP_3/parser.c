#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "Employee.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
    Employee* auxEmpleado = employee_new();
    Employee *pEmpleado;
    char id[10],nombre[50],horasTrabajadas[10],sueldo[10];
    int cantidad, retorno = 1, r[4];
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
    while(!feof(pFile)){
        cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
        if(cantidad == 4){
            r[0] = isInteger(id);
            r[1] = areCharacters(nombre);
            r[2] = isInteger(horasTrabajadas);
            r[3] = isFloat(sueldo);
            if (r[0] && r[1] && r[2] && r[3]){
                r[0] = employee_setId(auxEmpleado, atoi(id));
                r[1] = employee_setNombre(auxEmpleado, nombre);
                r[2] = employee_setHorasTrabajadas(auxEmpleado, atoi(horasTrabajadas));
                r[3] = employee_setSueldo(auxEmpleado, atof(sueldo));
                /**< Creo un nuevo empleado una vez validado los campos del CSV */
                if (r[0] && r[1] && r[2] && r[3]){
                    pEmpleado = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
                    if (pEmpleado != NULL)
                        ll_add(pArrayListEmployee,pEmpleado);
                    else
                        printf("No se pudo conseguir memoria libre.");
                }
            }
        }
        else
            retorno = 0;
    }
    free(auxEmpleado);
    return retorno;
}/**< FINALIZADO */
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){
    Employee auxEmpleado;
    int cantidad, retorno = 0;
    while(!feof(pFile)){
        cantidad = fread(&auxEmpleado, sizeof(Employee), 1, pFile);
        Employee *pEmpleado = employee_new();
        if(cantidad == 1){
            pEmpleado->id = auxEmpleado.id;
            strcpy(pEmpleado->nombre,auxEmpleado.nombre);
            pEmpleado->horasTrabajadas = auxEmpleado.horasTrabajadas;
            pEmpleado->sueldo = auxEmpleado.sueldo;
            ll_add(pArrayListEmployee, pEmpleado);
            retorno = 1;
        }
        else{
            if(!feof(pFile))
                break;
        }
    }
    fclose(pFile);
    return retorno;
}/**< FINALIZADO */
