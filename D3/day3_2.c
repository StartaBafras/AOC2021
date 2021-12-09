#include <stdio.h>
#define array 1000
#define bits 13

void search(char data[][bits],int index, int mod)
{
    int zero = 0;
    int one = 0;

    for(int i = 0;i<array;i++)
    {
        if(data[i][index] == '1') one++;

        else if(data[i][index] == '0') zero++;
    }

    if(one+zero != 1 )
    {
        if(mod == 1)
        {
            if(one>zero || one == zero) delete(data,index,'1');
            else delete(data,index,'0');
        }
        else
        {
            if(one>zero || one == zero) delete(data,index,'0');
            else delete(data,index,'1');
        }
    }



}

void delete(char data[][bits],int index,char value)
{
    for(int i = 0;i<array;i++)
    {
        if(data[i][index] != value && data[i][index] != '2')
        {
            for(int j=0;j<bits;j++)
            {
                data[i][j] = '2';
            }
        }
    }
}

int main(void)
{
    FILE *file = fopen("d3.txt","r");

    char tmp[bits];
    char answer[array][bits];

    int counter = 0;

    while(!feof(file))
    {
        fscanf(file,"%s",answer[counter]);
        counter++;
    }

    for(int i=0;i<bits-1;i++)
    {
        search(answer,i,1);
    }

    for(int i=0;i<array;i++)
    {
        if(answer[i][0] != '2') printf("\n%s",answer[i]);
    }


    rewind(file);
    counter = 0;

    while(!feof(file))
    {
        fscanf(file,"%s",answer[counter]);
        counter++;
    }

    for(int i=0;i<bits-1;i++)
    {
        search(answer,i,0);
    }

    for(int i=0;i<array;i++)
    {
        if(answer[i][0] != '2') printf("\n%s",answer[i]);
    }
}