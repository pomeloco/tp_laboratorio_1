//Prototipos
struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;


/*****************************************************/
int initEmployees(Employee*, int);
int addEmployee(Employee*, int, char [],char [],float,int);
int findEmployeeById(Employee*, int,int);
int removeEmployee(Employee*, int, int);
int sortEmployees(Employee*, int, int);
int printEmployees(Employee*, int);



/*******************************************************/
int buscarLibreEmpoyees(Employee*, int);
void DarAltaEmpleado (Employee*,int);
int ValidarString (char [],int);
int ValidarEnteroRango (int,int,int);
int ValidarFloatPositivo(float);
int ValidarCharacter(char,char,char);
int ModificarEmployee(Employee*, int);
int BajaEmployee(Employee* , int);
void MostrarTotalSalarios(Employee* ,int);
