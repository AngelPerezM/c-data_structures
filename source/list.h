//***********************************************************************************************
//*					List header file					*
//***********************************************************************************************

#ifndef LIST_H_
#define LIST_H_

/**
 * List Interface, declares methods and funcitons applicable to a list data structure, all these
 * operations are based on the List interface from Java.
 */
typedef struct List {
    // CREATORS

    /* Empty because is an interface*/
    
    // MANIPULATORS

    /**
     *
     */
    int (*add) (List *me, void *element);
    /**
     *
     */
    void (*add) (List *me, int index, void *element);
    /**
     *
     */
    int (*remove) (List *me, int index);
    /**
     *
     */
    int (*remove) (List *me, void *element);
    /**
     *
     */
    void (*set) (List *me, int index, void *element);

    // ACCESORS

    /**
     *
     */
    int (*contains) (List *me, void *element);
    /**
     *
     */
    void (*get) (List *me, int index);
    /**
     *
     */
    int (*isEmpty) (List *me);
    /**
     *
     */
    int (*size) (List *me);

} List;

#endif // LIST_H_
