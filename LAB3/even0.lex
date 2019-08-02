%{
    // No declarations
%}

%%
((1*01*01*)*)|1*    { printf("Even 0s found\n");}
.*   { printf("Even 0s not found");}
\n    {return 0;} 
%%
int yywrap(){} 
int main(){

    yylex();
    return 0;
}