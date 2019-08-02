%{
    // No declarations
%}

%%
[0-9]   {printf("Digit\n");}
[0-9]+  {printf("Digits\n");}
[0-9]+(\.[0-9]+)?(E[+-]?[0-9]+)?    {printf("Number\n");}
[a-zA-Z]    {printf("Letter\n");}
if|else|then    {printf("Keyword\n");}
[a-zA-Z]([a-zA-Z]|[0-9]+)*  {printf("ID\n");}
>|<|<>|<=|>=|= {printf("Relop\n");}
.*   { printf("Unknown\n");}
\n    {return 0;}
%%
int yywrap(){} 
int main(){

    yylex();
    return 0;
}