%{
    // No declarations
%}

%%
(0*|0*110*|0*101*010*)*    { printf("Divisible by 3\n");}
.*   { printf("Not divisible by 3\n");}
\n    {return 0;} 
%%
int yywrap(){} 
int main(){

    yylex();
    return 0;
}