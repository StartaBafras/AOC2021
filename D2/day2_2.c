#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("d2.txt","r");

    int direction_value;
    char direction[10];

    int horizontal = 0,aim = 0,depth = 0;

    while (!feof(file))
    {
        fscanf(file,"%s %d",direction,&direction_value);

        if(!strcmp(direction,"up")) aim -= direction_value;

        if(!strcmp(direction,"down")) aim += direction_value;

        if(!strcmp(direction,"forward"))
        {
            if(aim != 0)
            {
                depth += direction_value*aim;
                horizontal +=direction_value;
            }
            else horizontal += direction_value;
            
        } 
        memset(direction,10,'\0');


    }

    printf("%d",horizontal*depth);
    
}