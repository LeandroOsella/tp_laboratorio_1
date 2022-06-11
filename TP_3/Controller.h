int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger, int* id, char* path);
int controller_editPassenger(LinkedList* pArrayListPassenger, int nextId);
int controller_removePassenger(LinkedList* pArrayListPassenger, int nextId);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
int controller_searchPassenger(LinkedList* pArrayListPassenger, int id, int* index);
int controller_saveAsTextId(char* path , int id);


