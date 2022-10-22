%{
    #include "../headers/cal.h"
    int command = 0;
%}

%%

"!" {return EXMARK;}

"/help" {
    command = 1;
    return COMMAND;}

"/variables" {
    command = 2;
    return COMMAND;}

"?" {return QMARK;}

\$ {return DOLLAR;}

[\-\+\*\/] {return OP;}

m[0-9]* {return VAR;}

[0-9]+ {return NUM;}

\. {return DOT;}

" "* ;

. {printf("Error of syntax\n");}

%%

int yywrap(){
    return 1;
}
