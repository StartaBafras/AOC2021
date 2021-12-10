#include <stdio.h>

int main(void)
{

    FILE *file = fopen("d5.txt","r");

    int cordinate[4];
    int map[1000][1000] = {0};

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



    }
    int answer=0;

    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1000;j++)
        {
            if(map[i][j] >=2) answer++;
        }   
    }
    printf("%d",answer);
    
}