#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(void)
{
    FILE *file = fopen("d8.txt","r");

    char tmp[8];


    int answer = 0;

    long carriage_return = 0;

    while (!feof(file))
    {

        carriage_return = ftell(file);
        fseek(file,carriage_return +61,SEEK_SET);


        for(int i=0; i<4; i++)
        {
            fscanf(file,"%s",tmp);
            if(strlen(tmp) == 3 || strlen(tmp) == 2 || strlen(tmp) == 7 || strlen(tmp) == 4) answer++;
        }




    }
    printf("%d",answer);
}