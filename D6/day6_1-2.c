#include <stdio.h>
int timer_f(long int *incubation)
{
    long int temp = incubation[0];
    for(int i=0;i<6;i++)
    {
        incubation[i] = incubation[i+1];
    }
    incubation[6] = incubation[7] + temp;
    incubation[7] = incubation[8];
    incubation[8] = temp;
}

int main(void)
{
    FILE *file = fopen("d6.txt","r");

    long int timer[9] = {0};
    int temp=0;
    while (!feof(file))
    {
        fscanf(file,"%d,",&temp);
        timer[temp]++;
    }

    for(int i=0;i<256;i++)
    {
        timer_f(&timer);
    }

    long answer = 0;
    for(int i=0;i<9;i++)
    {
        answer += timer[i];
    }
    printf("%d",answer);
    
}