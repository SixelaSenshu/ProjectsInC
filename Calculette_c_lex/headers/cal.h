#ifndef _CAL_H

#define DOT 1
#define QMARK 2
#define EXMARK 3
#define DOLLAR 4
#define OP 5
#define NUM 6
#define VAR 7
#define COMMAND 8
#define EMPTY -1

#define SIZE_VAR 30
#define MAX_SIZE_NAME 20
    
typedef enum state State;
enum state {WAIT,DISCMD,STOCMD,EVALCMD,SKIP,COMCMD};

#define _CAL_H 1

#endif


