#include <stdio.h>


int check(int puzzle[5][5])
{
    int counter = 0;
    for(int i=0;i<5;i++)
    {
        counter = 0;
        for(int j=0;j<5;j++)
        {
            if(puzzle[i][j] == -1)
            {
                counter++;
            }
        }
        if(counter == 5) return 1;
    }

    for(int i=0;i<5;i++)
    {
        counter = 0;
        for(int j=0;j<5;j++)
        {
            if(puzzle[j][i] == -1)
            {
                counter++;
            }
        }
        if(counter == 5) return 1;
    }

    return 0;
}

int sum(int puzzle[5][5])
{
    int sum=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(puzzle[i][j] != -1) sum += puzzle[i][j];
        }
    }
    
    return sum;
}

int search(int puzzle[5][5],int check_list[])
{

    int flag=0;

    for(int d=0;d<100;d++)
    {
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                {
                    if(puzzle[i][j] == check_list[d])
                    {
                        puzzle[i][j] = -1;
                        flag = check(puzzle);
                        if(flag == 1)
                        {
                            
                            return d;
                        } 
                    }
                }
            }
        }

        
    }
    
}

int main(void)
{
    int check_list[] = {72,99,88,8,59,61,96,92,2,70,1,32,18,10,95,33,20,31,66,43,26,24,91,44,11,15,48,90,27,29,14,68,3,50,69,74,54,4,16,55,64,12,73,80,58,83,6,87,30,41,25,39,93,60,9,81,63,75,46,19,78,51,21,28,94,7,17,42,53,13,97,98,34,76,89,23,86,52,79,85,67,84,47,22,37,65,71,49,82,40,77,36,62,0,56,45,57,38,35,5};

    FILE *file = fopen("d4.txt","r");

    int puzzle_array[5][5] = {0};
    int answer[100][2] = {0};
    int i=0;
    int counter=0;
    while (!feof(file))
    {
        fscanf(file,"%d %d %d %d %d",&puzzle_array[i][0],&puzzle_array[i][1],&puzzle_array[i][2],&puzzle_array[i][3],&puzzle_array[i][4]);
        i++;
        if(i%5 == 0)
        {
            fscanf(file,"\n");
            i = 0;
            answer[counter][0] = search(puzzle_array,check_list);
            answer[counter][1] = check_list[answer[counter][0]]*sum(puzzle_array);
            counter++;
        }
    }

    int winner=0;
    int temp= answer[0][0];
    for(int i=0;i<100;i++)
    {
        if( answer[i][0] < temp) //for part to make >
        {
            temp = answer[i][0];
            winner = i;
        } 
    }

    printf("%d",answer[winner][1]);
    

    
}