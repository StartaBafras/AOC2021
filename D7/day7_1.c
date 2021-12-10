#include <stdio.h>

int abs(int value)
{
    if(value < 0) return -value;
    else return value;
}

int sum(int number)
{
    int answer = 0;
    for(int i=0;i<=number;i++)
    {
        answer += i;
    }

    return answer;
}

int main(void)
{
    FILE *file = fopen("d7.txt","r");

    int counter = 0;
    int temp = 0;
    while (!feof(file))
    {
        fscanf(file,"%d,",&temp);
        counter++;
    }

    int data[counter];
    counter = 0;

    rewind(file);

    while (!feof(file))
    {
        fscanf(file,"%d,",&data[counter]);
        counter++;
    }

    int answer = 999999999;
    temp=0;

    
    for(int x=0;x<2000;x++)
    {
        
        temp =0;
        for(int j=0;j<counter;j++)
        {
            temp += abs( (data[j] - x) );
        }
        if(answer>temp) answer = temp;
    }

    printf("%d",answer);
    
}