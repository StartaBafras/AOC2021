#include <stdio.h>

int scroll(int array[],int size,int new_value)
{
    for(int i=0;i<size-1;i++)
    {
        array[i] = array[i+1];
    }

    array[size-1] = new_value;
}

int sum(int array[],int size)
{
    int sum = 0;
    for(int i=0;i<size;i++)
    {
        sum += array[i];
    }
    return sum;
}

int main(void)
{
    FILE *file = fopen("d1.txt","r");

    int box1[3];
    fscanf(file,"%d",&box1[0]);
    fscanf(file,"%d",&box1[1]);
    fscanf(file,"%d",&box1[2]);

    int first_sum,second_sum;

    first_sum = sum(box1,3);

    int temp;
    int answer=0;
    while (!feof(file))
    {
        fscanf(file,"%d",&temp);
        scroll(box1,3,temp);
        second_sum = sum(box1,3);

        if(first_sum<second_sum) answer++;

        first_sum = second_sum;

    }

    printf("%d",answer);
    
    
}