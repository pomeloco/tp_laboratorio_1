#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
typedef struct{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;
/**************************************************************************/
Employee* employee_new();
Employee* employee_newParametros(char* ,char* ,char* ,char* );
/**************************************************************************/
void employee_delete();
/**************************************************************************/
int employee_setId(Employee* ,int);
int employee_setNombre(Employee*,char*);
int employee_setHorasTrabajadas(Employee*,int);
int employee_setSueldo(Employee*,int);
/**************************************************************************/
int employee_getId(Employee*, int*);
int employee_getNombre(Employee*, char*);
int employee_getHorasTrabajadas(Employee*, int*);
int employee_getSueldo(Employee*, int*);
/**************************************************************************/
int employee_sortById(void*, void*);
int employee_sortByNombre(void*, void*);
int employee_sortBySueldo(void*, void*);
int employee_sortByHorasTrabajadas(void*, void*);
#endif // EMPLOYEE_H_INCLUDED
