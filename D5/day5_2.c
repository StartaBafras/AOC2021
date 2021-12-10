#include <stdio.h>
#define array 1000
int main(void)
{

    FILE *file = fopen("d5.txt","r");

    int cordinate[4];
    int map[array][array] = {0};

    while (!feof(file))
    {
        fscanf(file,"%d,%d -> %d,%d",&cordinate[0],&cordinate[1],&cordinate[2],&cordinate[3]);

        if(cordinate[0] == cordinate[2])
        {
            if(cordinate[1] < cordinate[3])
            {
                for(int i=cordinate[1];i<=cordinate[3];i++)
                {
                    map[i][cordinate[0]]++;
                }
            }
            else
            {
                for(int i=cordinate[3];i<=cordinate[1];i++)
                {
                    map[i][cordinate[0]]++;
                }
            }

        }
        else if(cordinate[1] == cordinate[3])
        {
            if(cordinate[0]<cordinate[2])
            {
                for(int i=cordinate[0];i<=cordinate[2];i++)
                {
                    map[cordinate[1]][i]++;
                }
            }
            else
            {
                for(int i=cordinate[2];i<=cordinate[0];i++)
                {
                    map[cordinate[1]][i]++;
                }
            }

        }
        else if( (cordinate[3]-cordinate[1]) / (cordinate[2]-cordinate[0]) == -1)
        {
            if(cordinate[3] < cordinate[1] && cordinate[0] > cordinate[2])
            {
                for(int i=cordinate[3],j = cordinate[2];i<=cordinate[0];i++,j++)
                {
                    map[i][j]++;
                }
            }
            if(cordinate[0] < cordinate[2] && cordinate[1] > cordinate[3])
            {
                for(int i=cordinate[1],j = cordinate[0];j<=cordinate[2];i--,j++)
                {
                    map[i][j]++;
                }
            }
            if(cordinate[0]>cordinate[2] && cordinate[1]<cordinate[3])
            {
                for(int i=cordinate[1],j = cordinate[0];i<=cordinate[3];i++,j--)
                {
                    map[i][j]++;
                }
            }
        }
        else if( (cordinate[3]-cordinate[1]) / (cordinate[2]-cordinate[0]) == 1 )
        {
            if(cordinate[0] < cordinate[2] )
            {
                for(int i=cordinate[1],j = cordinate[0];i<=cordinate[2];i++,j++)
                {
                    map[i][j]++;
                }
            }
            else
            {
                for(int i=cordinate[3],j = cordinate[2];i<=cordinate[1];i++,j++)
                {
                    map[i][j]++;
                }
            }

        }



    }
    int answer=0;

    for(int i=0;i<array;i++)
    {
        for(int j=0;j<array;j++)
        {
            if(map[i][j] >=2) answer++;
            //printf("%d",map[i][j]);
        }
        //printf("\n");
    }
    printf("%d",answer);
    
}