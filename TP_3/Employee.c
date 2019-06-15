#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new(){

    Employee* pEmpleado = malloc(sizeof(Employee));
    pEmpleado->id = -1;

    return pEmpleado;
}

Employee* employee_newParametros(char* nId,char* szNombre,char* szHorasTrabajadas,char* szSueldo){

    Employee* pEmpleado = employee_new();

    if(pEmpleado != NULL){
        pEmpleado->id = atoi(nId);
        strncpy(pEmpleado->nombre, szNombre, 50);
        pEmpleado->horasTrabajadas = atoi(szHorasTrabajadas);
        pEmpleado->sueldo = atof(szSueldo);
    }

    return pEmpleado;
}

/*void employee_delete(){
}*/

int employee_setId(Employee* this, int nId){

    int retorno = 0;
    if (nId >= 0 && nId <10000 && this != NULL){
        this->id = nId;
        retorno = 1;
    }

    return retorno;
}

int employee_getId(Employee* this, int* nId){

    int retorno = 0;
    if (nId != NULL && this != NULL){
        *nId = this->id;
        retorno = 1;
    }

    return retorno;
}

int employee_setNombre(Employee* this,char* szNombre){

    int retorno = 0;

    if (strlen(szNombre) > 0 && this != NULL){
        strncpy(this->nombre, szNombre, 50);
        retorno = 1;
    }

    return retorno;
}

int employee_getNombre(Employee* this,char* szNombre){
    int retorno = 0;
    if (strlen(this->nombre) > 0 && this != NULL){
        strncpy(szNombre, this->nombre, 50) ;
        retorno = 1;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int nHorasTrabajadas){

    int retorno = 0;
    if (nHorasTrabajadas >= 0 && nHorasTrabajadas <500 && this != NULL){
        this->horasTrabajadas = nHorasTrabajadas;
        retorno = 1;
    }

    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* nHorasTrabajadas){
    int retorno = 0;

    if (nHorasTrabajadas != NULL && this != NULL){
        *nHorasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,int nSueldo){

    int retorno = 0;
    if (nSueldo >= 0  && this != NULL){
        this->sueldo = nSueldo;
        retorno = 1;
    }

    return retorno;
}

int employee_getSueldo(Employee* this,int* nSueldo){

    int retorno = 0;
    if (nSueldo != NULL && this != NULL){

        *nSueldo = this->sueldo;
        retorno = 1;
    }

    return retorno;
}

int employee_sortById(void* auxEmpleadoUno, void* auxEmpleadoDos){

    int retorno = 0;
    if(((Employee*)auxEmpleadoUno)->id<((Employee*)auxEmpleadoDos)->id){

        retorno = 1;
    }

    return retorno;
}

int employee_sortByNombre(void* auxEmpleadoUno, void* auxEmpleadoDos){

    int retorno = 0;
    if(strcmp(((Employee*)auxEmpleadoUno)->nombre, ((Employee*)auxEmpleadoDos)->nombre) > 0){

        retorno = 1;
    }

    return retorno;
}

int employee_sortBySueldo(void* auxEmpleadoUno, void* auxEmpleadoDos){

    int retorno = 0;
    if(((Employee*)auxEmpleadoUno)->sueldo<((Employee*)auxEmpleadoDos)->sueldo){

        retorno = 1;
    }

    return retorno;
}

int employee_sortByHorasTrabajadas(void* auxEmpleadoUno, void* auxEmpleadoDos){

    int retorno = 0;
    if(((Employee*)auxEmpleadoUno)->horasTrabajadas<((Employee*)auxEmpleadoDos)->horasTrabajadas){

        retorno = 1;
    }

    return retorno;
}
