/* generated by make_init.pl mod1.h mod2.h mod3.h */

#pragma once
#define main user_main

/* includes */
#include "memalloc.h"   			/* before any other include */

#include "mod1.h"

#include "mod2.h"

#include "mod3.h"


/* data types */
typedef int BOOL;


typedef struct Person Person;

typedef struct Person0 Person0;

typedef struct Person1 Person1;

typedef struct Person2 Person2;

typedef struct Person3 Person3;


/* declare functions */

/* Person: create, destroy, set/clear autodelete */
extern Person * new_Person (  char * name,  int age );
extern void delete_Person ( Person **pself );
extern void autodelete_Person ( Person *self, BOOL autodelete );

/* Person0: create, destroy, set/clear autodelete */
extern Person0 * new_Person0 ( void );
extern void delete_Person0 ( Person0 **pself );
extern void autodelete_Person0 ( Person0 *self, BOOL autodelete );

/* Person1: create, destroy, set/clear autodelete */
extern Person1 * new_Person1 ( void );
extern void delete_Person1 ( Person1 **pself );
extern void autodelete_Person1 ( Person1 *self, BOOL autodelete );

/* Person2: create, destroy, set/clear autodelete */
extern Person2 * new_Person2 ( void );
extern void delete_Person2 ( Person2 **pself );
extern void autodelete_Person2 ( Person2 *self, BOOL autodelete );

/* Person3: create, destroy, set/clear autodelete */
extern Person3 * new_Person3 ( void );
extern void delete_Person3 ( Person3 **pself );
extern void autodelete_Person3 ( Person3 *self, BOOL autodelete );