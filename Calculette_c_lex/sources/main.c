#include "../headers/cal.h"
#include "../headers/stack.h"
#include "../headers/utils.h"

extern int yylex();
extern char* yytext;
extern int yylineno;
extern int command;

int main(void){
    printf("\n----- Starting of program -----------------------------------------------\n\n");
    help();
    int res[SIZE_VAR] = {};
    int size = SIZE_VAR; 
    char * var;
    Stack * stack = initEmptyStack(SIZE_VAR);
    State state = WAIT;

    printf("Command: ");

    int token =yylex();
    while(token){
        switch(token)
        {
        /*Dans le cas ou on a un .*/
        case DOT:
            if(state == WAIT){
                printf("----- Closing of program -----------------------------------------------\n\n");
                exit(EXIT_SUCCESS);
            }
            else if(state == EVALCMD){
                res[0] = pop(stack);
                printf("* [RES]The result is : %d \n",res[0]);
                state = WAIT;
            }else state = WAIT;
            break;
            
        /*Dans le cas ou on a un ?*/
        case QMARK:
            if(state == WAIT) state = EVALCMD;
            else if(state != SKIP) {
                fprintf(stderr , "* [ERR]Error of detection of symbole ? \n" ) ;
                state = SKIP;
            }
            break;
        
        /*Dans le cas ou on a une commande */
        case COMMAND:
            if(state == WAIT){
                state = COMCMD;
                if(command == 1) help();
                else if(command == 2) variables(res, size);
                state = WAIT;
            }
            else if(state != SKIP) {
                fprintf(stderr , "* [ERR]Error of detection \\command \n" ) ;
                state = SKIP;
            }
            break;

        /*Dans le cas ou on a un !*/
        case EXMARK:
            if(state == WAIT) state = STOCMD;
            else if(state != SKIP){
                fprintf(stderr , "* [ERR]Error of detection of symbole ! \n" ) ;
                state = SKIP;
            }
            break;

        /*Dans le cas ou on a un dollar*/
        case DOLLAR:
            if(state == WAIT) state = DISCMD;
            else if(state != SKIP){
                fprintf(stderr , "* [ERR]Error of detection of symbole $ \n" ) ;
                state = SKIP;}
            break;

        /*Dans le cas ou on a un operateur*/
        case OP:
            if(state == EVALCMD){
                int var1 = pop(stack), var2 = pop(stack);
                if(!var1 || !var2) printf("* [ERR]There aren't enough arguments\n");
                else{
                    switch (yytext[0]){
                    case '+':
                        push(stack,var1 + var2);
                        break;
                    case '-':
                        push(stack,var2 - var1);
                        break;
                    case '*':
                        push(stack,var1 * var2);
                        break;
                    case '/':
                        printf("%d / %d \n", var2, var1);
                        push(stack,var2 / var1);
                        break;
                    default:
                        break;
                    }
                }
            }else if(state != SKIP){
                fprintf(stderr ,"* [ERR]Error of detection of operator\n" ) ;
                state = SKIP;
            }
            break;
        /*Dans le cas ou on a un nombre*/
        case NUM:
            if(state == EVALCMD){
                push(stack,atoi(yytext));
            }else if(state != SKIP){
                fprintf(stderr ,"* [ERR]Error of detection of numbers \n" ) ;
                state = SKIP;
            }
            break;

        /*Dans le cas ou on a une variable*/
        case VAR:
            // On récupère la variable
            char * var = (char*) malloc(sizeof(char) * strlen(yytext)-1);
            for(int i = 0 ; i < strlen(yytext); i++) {
                var[i] = yytext[i+1];
            }// On regarde l'état
            if(state == DISCMD){ 
                if(atoi(var) >= 0  && atoi(var) < size && res[atoi(var)]){
                    printf("- [RES]The value is [%d]\n",res[atoi(var)]);
                }else if (atoi(var) > size){
                    printf(": [WARNING]The maximal value is %d \n",SIZE_VAR );
                } 
                else{
                    printf("- [RES]The value is 0\n");
                }
            }else if(state == EVALCMD){
                // On regarde si la valeur est présente 
                if(atoi(var) >= 0  && atoi(var) < size && res[atoi(var)]){
                    push(stack,res[atoi(var)]);
                }else{
                    push(stack,0);
                }
            }else if(state == STOCMD){ 
                // On regarde si il y a eu un calcul avant 
                if(atoi(var) >= 0  && atoi(var) < size && res[0]){
                    res[atoi(var)] = res[0];    
                }else{  
                    printf("* [ERR]There are any values in memories! \n");
                } 
            }else if(state != SKIP){
                fprintf(stderr , "* [ERR]Error of detection of variable \n" ) ;
                state = SKIP;
            }
            free(var);
            break;

        /*Dans le cas ou on a un caractère inattendu*/
        default:
            if(state != SKIP) printf("Syntax error in line %d\n", yylineno);
            break;
        }
        token = yylex();
    }
    freeStack(stack);
    printf("\n----- Starting of program -----------------------------------------------\n");
    return EXIT_SUCCESS;
}