#include <stdio.h>

int main(void)
{
    FILE *file = fopen("d3.txt","r");

    char tmp[13];
    char answer[13];
    char answer2[13];

    int value=0;
    int counter=0;

    for(int i=0;i<12;i++)
    {
        value = 0;
        counter = 0;
        while(!feof(file))
        {
            fscanf(file,"%s",tmp);
            if(tmp[i] == '1') value++;
            counter++;
        }
        if(value > counter-value) answer[i] = '1';
        else answer[i] = '0';



        rewind(file);
    }

    printf("\n%s",answer);

}