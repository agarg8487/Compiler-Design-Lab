%{
    // No declarations
%}

%%
[0-9]   {printf("Digit ");}
[0-9]+  {printf("Digits ");}
[0-9]+(\.[0-9]+)?(E[+-]?[0-9]+)?    {printf("Number ");}
[a-zA-Z]    {printf("Letter ");}
int|INT|FLOAT|float {printf("Datatype");}
for|while {printf("Loop");}
read|print {printf("I/O");}
if|else|then    {printf("Keyword ");}
main {printf("Main-Function");}
[a-zA-Z]([a-zA-Z]|[0-9]+)*  {printf("ID ");}
>|<|<>|<=|>=|=|\+= {printf("Relop ");}
%%
int yywrap(){} 
int main(){
    extern FILE *yyin;
    yyin=fopen("q3.txt","r");
    yylex();
    fclose(yyin);
    return 0;
}