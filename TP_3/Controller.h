#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
int controller_loadFromText(char* , LinkedList* );
int controller_loadFromBinary(char* , LinkedList*);
int controller_addEmployee(LinkedList*);
int controller_editEmployee(LinkedList*);
int controller_removeEmployee(LinkedList*);
int controller_ListEmployee(LinkedList*);
int controller_sortEmployee(LinkedList*);
int controller_saveAsText(char* , LinkedList*);
int controller_saveAsBinary(char* , LinkedList*);
int controller_findEmployee(LinkedList* ,int);
int controller_filterEmployee(LinkedList*);
#endif // CONTROLLER_H_INCLUDED
