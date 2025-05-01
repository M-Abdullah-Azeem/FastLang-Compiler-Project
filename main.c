#include <stdio.h>

extern int yyparse();
extern FILE *yyin;
extern FILE *out;

int main()
{
    char filename[100];
    printf("Enter the source filename: ");
    scanf("%s", filename);

    yyin = fopen(filename, "r");
    if (!yyin)
    {
        perror("Cannot open source file");
        return 1;
    }

    out = fopen("output.txt", "w");
    if (!out)
    {
        perror("Cannot create output.txt");
        return 1;
    }

    if (yyparse() == 0)
    {
        printf("Parsing completed successfully. Intermediate code written to output.txt\n");
    }
    else
    {
        printf("Parsing failed.\n");
    }

    fclose(yyin);
    fclose(out);
    return 0;
}
