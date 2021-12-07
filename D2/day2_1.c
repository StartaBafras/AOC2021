#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("d2.txt","r");

    int direction_value;
    char direction[10];

    int horizontal = 0,depth = 0;

    while (!feof(file))
    {
        fscanf(file,"%s %d",direction,&direction_value);

        if(!strcmp(direction,"up")) depth -= direction_value;

        if(!strcmp(direction,"down")) depth += direction_value;

        if(!strcmp(direction,"forward")) horizontal += direction_value;
        memset(direction,10,'\0');


    }

    printf("%d",horizontal*depth);
    
}