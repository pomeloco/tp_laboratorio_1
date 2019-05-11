//implementaciones

#include "ArrayEmployees.h"
#include <string.h>
#include <stdio.h>


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param eEmpleados Employee* Pointer to array of employees
 * \param nCant int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* eEmpleados, int nCant){

    int initReturn = 0, i;


            for(i=0;i<nCant;i++){


                eEmpleados[i].isEmpty = 1;

            }

    return initReturn;
}




/** \brief Busca el primer lugar libre en el array
 *  de la estructura empleados
 * \param eEmpleados Employee* Pointer to array of employees
 * \param nCant int Array length
 * \return retorna el primer index libre y -1 si no hay lugar libre
 *
 */

int buscarLibreEmpoyees(Employee* eEmpleados, int nCant){

    int nIndexLibre= -1 ,i;

    for(i=0;i<nCant;i++){

        if(eEmpleados[i].isEmpty == 1){


            nIndexLibre = i;
            break;
        }

    }

    return nIndexLibre;
}







/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param eEmpleado employee*
 * \param nCant int
 * \param
 * \param szName[] char
 * \param szLastName[] char
 * \param fSalary float
 * \param nSector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */

int addEmployee(Employee* eEmpleado, int nCant, char szName[],char szLastName[],float fSalary,int nSector){

    int nIndexLibre;

    nIndexLibre = buscarLibreEmpoyees(eEmpleado, nCant);


    if(nIndexLibre != -1){

        eEmpleado[nIndexLibre].id = nIndexLibre+100;
        eEmpleado[nIndexLibre].salary = fSalary;
        strcpy(eEmpleado[nIndexLibre].name, szName);
        strcpy(eEmpleado[nIndexLibre].lastName, szLastName);
        eEmpleado[nIndexLibre].sector = nSector;
        eEmpleado[nIndexLibre].isEmpty = 0;

    }else{


        return -1;

    }


 return 0;
}








/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param eEmpleados Employee*
 * \param nCant int
 * \param nId int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* eEmpleados, int nCant,int nId){

    int nIndexEmpleado=-1,i;


        for(i=0;i<nCant;i++){

            if(eEmpleados[i].id == nId){



                nIndexEmpleado = i;
                break;
            }


        }


    return nIndexEmpleado;
}




/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param eEmpleado Employee*
 * \param nCant int
 * \param nId int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* eEmpleado, int nCant, int nId){

    int i;
    int returnRemove=-1;


    for(i=0;i<nCant;i++){

        if(eEmpleado[i].id == nId || eEmpleado[i].isEmpty == 0){

            eEmpleado[i].isEmpty = 1;
            returnRemove = 0;
        }
    }


 return returnRemove;
}






/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param eEmpleado Employee*
 * \param nCant int
 * \param nOrder int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* eEmpleado, int nCant, int nOrder){

    Employee eEmpleadoAuxiliar;
     int   i,j;

    if(nOrder == 1){

        for(i=0;i<nCant-1;i++){


            for(j=i+1;j<nCant;j++){


                if(strcmp(eEmpleado[i].lastName,eEmpleado[j].lastName) > 0 || eEmpleado[i].sector > eEmpleado[j].sector ){

                    eEmpleadoAuxiliar=eEmpleado[i];
                    eEmpleado[i]=eEmpleado[j];
                    eEmpleado[j]=eEmpleadoAuxiliar;


                }

            }
        }


    }else if (nOrder == 0){

        for(i=0;i<nCant-1;i++){


            for(j=i+1;j<nCant;j++){


                if(strcmp(eEmpleado[i].lastName,eEmpleado[j].lastName) < 0 || eEmpleado[i].sector < eEmpleado[j].sector ){

                    eEmpleadoAuxiliar=eEmpleado[j];
                    eEmpleado[j]=eEmpleado[i];
                    eEmpleado[i]=eEmpleadoAuxiliar;


                }

            }
        }



    }


 return -1;
}


/** \brief print the content of employees array
 *
 * \param eEmpleados Employee*
 * \param nCantidad int
 * \return int
 *
 */
int printEmployees(Employee* eEmpleados, int nCantidad)
{

    int i;


    for (i=0;i<nCantidad;i++){



        if  (eEmpleados[i].isEmpty == 0){


            printf("%d %s,%s\n$%.2f Sector: %d\n\n\n", eEmpleados[i].id,eEmpleados[i].lastName,eEmpleados[i].name,eEmpleados[i].salary,eEmpleados[i].sector);

        }

    }


 return 0;
}

/** \brief valida una cadena de caracteres
 *
 * \param string Char*
 * \param nCantidadMaxima int
 * \return si devuelve -1 La cadena no es valida (se exede de caracteres permitidos) si no, 0 todo ok
 *
 */

int ValidarString(char string[],int nCantMaxima){

    int returnValidar =-1,Contador;


    Contador=strlen(string);

    if(Contador<nCantMaxima){

        returnValidar=0;
    }

    return returnValidar;
}


/** \brief Validar un rango de numeros enteros
 *
 * \param nNumero int
 * \param nMax int
 * \param nMin int
 * \return si devuelve -1 el numero esta fuera de rango si devuelve 0 ok
 *
 */
int ValidarRangoEntero(int nNumero, int nMax, int nMin){

    int ReturnValidarRango=-1;


    if(nNumero>=nMin && nNumero<=nMax){


        ReturnValidarRango = 0;
    }

    return ReturnValidarRango;
}

/** \brief Validar un numero float
 *
 * \param fFloat float
 * \return si devuelve -1 el numero es negativo 0 ok
 *
 */
int ValidarFloatPositivo(float fFloat){

    int ReturnFloatPositivo=-1;

    if(fFloat>0){

        ReturnFloatPositivo=0;
    }


    return ReturnFloatPositivo;
}




/** \brief Da de alta un empleado en el array
 *
 * \param eEmpleado Employee
 * \param nCantidad int
 * \return
 *
 */
void DarAltaEmpleado(Employee* eEmpleado,int nCant){

    char szNombre[100],szApellido[100];
    int nAuxInt;
    float fAuxFloat;
    int AgregarEmpleado;


    printf("Ingresar Nombre del empleado: ");
    fflush(stdin);
    gets(szNombre);

    while(ValidarString(szNombre,50)!=0){

        printf("Reingrese Nombre del empleado: ");
        fflush(stdin);
        gets(szNombre);
    }
    printf("Ingresar Apellido del empleado: ");
    fflush(stdin);
    gets(szApellido);

    while(ValidarString(szApellido,50)!=0){

        printf("Reingrese Apellido del empleado: ");
        fflush(stdin);
        gets(szApellido);
    }

    printf("Ingrese salario: ");
    fflush(stdin);
    scanf("%f", &fAuxFloat);

    while(ValidarFloatPositivo(fAuxFloat) != 0){

        printf("Reingresar salario: ");
        fflush(stdin);
        scanf("%f",&fAuxFloat);
    }


    printf("Ingrese sector al que pertenece: ");
    fflush(stdin);
    scanf("%d", &nAuxInt);

    while(ValidarRangoEntero(nAuxInt,3,1)!=0){

        printf("Reingrese el sector: ");
        fflush(stdin);
        scanf("%d",&nAuxInt);
    }


   AgregarEmpleado = addEmployee(eEmpleado, nCant,szNombre,szApellido,fAuxFloat,nAuxInt);

   if(AgregarEmpleado != 0){
    printf("OCURRIO UN ERROR AL CARGAR EMPLEADO!");
   }

}

/** \brief Valida un caracter, si es una opcion o la otra
 *
 * \param cChar char
 * \param cOpcionUno char
  * \param cOpcionDos char
 * \return -1 si es error, 0 si Ok
 */
int ValidarCharacter(char cChar, char cOpcionUno, char cOpcionDos){

    int ReturnChar=-1;


    if(cChar == cOpcionUno ||cChar == cOpcionDos){

        ReturnChar = 0;
    }


    return ReturnChar;
}

/** \brief Modifica un empleado del array
 *
 * \param eEmpleado Employee
 * \param nCantidad int
  * \param cOpcionDos char
 * \return -1 si es error, 0 si Ok
 */
int ModificarEmpleado (Employee* eEmpleado, int nCantidad){

    int ReturnModificar=-1,nAuxiliar,nOpcion,nAuxInt;
    char Seguir='s',cVerificar, szApellido[70],szNombre[70];
    float fAuxFloat;


    printf("Ingrese ID para modificar: ");
    scanf("%d", &nAuxiliar);

    nAuxiliar=findEmployeeById(eEmpleado,nCantidad,nAuxiliar);

    if(nAuxiliar==-1){

        printf("No se encontro la ID buscada");

    }else{

        do{
        //system("CLS");
        printf("1.Modificar Nombre\n2.Modificar Apellido\n3.Modificar Salario\n4.Modificar Sector\n5.Volver al Menu principal\n");
        fflush(stdin);
        scanf("%d", &nOpcion);

        switch(nOpcion){

            case 1: printf("Ingresar Nombre del empleado: ");
                    fflush(stdin);
                    gets(szNombre);

                    while(ValidarString(szNombre,50)!=0){

                        printf("Reingrese Nombre del empleado: ");
                        fflush(stdin);
                        gets(szNombre);
                    }
                    strcpy(eEmpleado[nAuxiliar].name,szNombre);
                    break;


            case 2:    printf("Ingresar Apellido del empleado: ");
                       fflush(stdin);
                        gets(szApellido);

                        while(ValidarString(szApellido,50)!=0){

                            printf("Reingrese Apellido del empleado: ");
                            fflush(stdin);
                            gets(szApellido);
                            }
                            strcpy(eEmpleado[nAuxiliar].lastName,szApellido);
                        break;


            case 3:     printf("Ingrese salario: ");
                        fflush(stdin);
                        scanf("%.2f", &fAuxFloat);

                        while(ValidarFloatPositivo(fAuxFloat) != 0){

                            printf("Reingresar salario: ");
                            fflush(stdin);
                            scanf("%.2f",&fAuxFloat);
                        }
                        eEmpleado[nAuxiliar].salary = fAuxFloat;
                        break;

            case 4:      printf("Ingrese sector al que pertenece: ");
                        fflush(stdin);
                        scanf("%d", &nAuxInt);

                        while(ValidarRangoEntero(nAuxInt,3,1)!=0){

                            printf("Reingrese el sector: ");
                            fflush(stdin);
                            scanf("%d",&nAuxInt);
                            }
                            eEmpleado[nAuxiliar].sector = nAuxInt;
                    break;


            case 5: /*printf("Desea guardar los cambios?");
                    fflush(stdin);
                    scanf("%c",&cVerificar);

                    if(ValidarCharacter(cVerificar,'s','n')==0){
                        if(cVerificar=='s'){
                            strcpy(eEmpleado[nAuxiliar].name,szNombre);
                            strcpy(eEmpleado[nAuxiliar].lastName,szApellido);
                            eEmpleado[nAuxiliar].salary = fAuxFloat;
                            eEmpleado[nAuxiliar].sector = nAuxInt;
                        }
                    }*/
                    Seguir='n';
                    break;


        }
        }while(Seguir=='s');
    }


    return ReturnModificar;

}





/** \brief Da de baja un empleado del array
 *
 * \param eEmpleado Employee
 * \param nCantidad int
  * \param
 * \return -1 si es error, 0 si Ok
 */

int BajaEmployee(Employee* Empleados, int nCant){

    int BajaReturn=-1,nAuxID, index;

    printf("ingresar ID a dar de abaja: ");
    scanf("%d", &nAuxID);

    index = findEmployeeById(Empleados,nCant,nAuxID);

    if(index == -1 ){

        printf("No se encontro la Id a buscar");

    }else{

        nAuxID=removeEmployee(Empleados,nCant,index);

        if(nAuxID == 0){
            printf("Dada de baja con exito");
            BajaReturn=0;
        }else{
        printf("Error al dar de baja");
        }
    }


    return BajaReturn;
}





/** \brief muestra el sueldo total entre todos los empleados del array
 *
 * \param eEmpleado Employee
 * \param nCantidad int
  * \param
 * \return -1 si es error, 1 si Ok
 */
void MostrarTotalSalarios(Employee* Empleados ,int nCant){

    int i,nContadorEmpleadosActivos=0;
    float TotalSalarios=0,PromedioSalarios=0;

    for(i=0;i<nCant;i++){

        if(Empleados[i].isEmpty == 0){
        TotalSalarios=+Empleados[i].salary;
        nContadorEmpleadosActivos++;
        }
    }
    printf("%d", nContadorEmpleadosActivos);
    if(nContadorEmpleadosActivos>=1){
    PromedioSalarios=TotalSalarios/nContadorEmpleadosActivos;
    }

    printf("La suma total de los salarios es: %.2f\nEl Promedio Total de los salarios es: %.2f\n", TotalSalarios,PromedioSalarios);
}
