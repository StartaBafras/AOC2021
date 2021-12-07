#include <stdio.h>

int main(void)
{
    FILE *file = fopen("d1.txt","r");

    int first,second;
    int answer = 0;
    
    fscanf(file,"%d",&first);
    fscanf(file,"%d",&second);
    if(second>first) answer++;

    while (!feof(file))
    {
        first = second;
        fscanf(file,"%d",&second);
        if(second>first) answer++;
        
    }

    printf("%d",answer);
    
}