#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct segments
{

    char numbers[10][8];
}segments;


int matcher(segments *p,char tmp[])
{
    if(strlen(tmp) == 2)
    {
        strcpy(p->numbers[1],tmp);
        return 1;
    }

    else if(strlen(tmp) == 4)
    {
        strcpy(p->numbers[4],tmp);
        return 1;

    }

    else if(strlen(tmp) == 3)
    {
        strcpy(p->numbers[7],tmp);
        return 1;
    }

    else if(strlen(tmp) == 7)
    {
        strcpy(p->numbers[8],tmp);
        return 1;
    }

    return 0;
}

int decoder(segments *p,char tmp[])
{
    if(matcher(p,tmp)) return 0;

    if(comparator(p->numbers[1],tmp) == 2 && strlen(tmp) == 6 && comparator(p->numbers[4],tmp) == 4) // 9
    {
        strcpy(p->numbers[9],tmp);
        return 1;
    }
    else if(strlen(tmp) == 6 && comparator(p->numbers[7],tmp) == 3 && comparator(p->numbers[1],tmp) == 2) // 0
    {
        strcpy(p->numbers[0],tmp);
        return 1;
    }
    else if(strlen(tmp) == 6) // 6
    {
        strcpy(p->numbers[6],tmp);
        return 1;
    }

    if(comparator(p->numbers[4],tmp) == 3 && strlen(tmp) == 5 && comparator(p->numbers[1],tmp) != 2) //5
    {
        strcpy(p->numbers[5],tmp);
        return 1;
    }
    else if(comparator(p->numbers[1],tmp) == 2 && strlen(tmp) == 5) //3
    {
        strcpy(p->numbers[3],tmp);
        return 1;     
    }
    else if(comparator(p->numbers[4],tmp) == 2 && comparator(p->numbers[1],tmp) == 1 && comparator(p->numbers[8],tmp) == 5) //2
    {
        strcpy(p->numbers[2],tmp);
        return 1;
    }


}

int comparator(char s1[],char s2[])
{
    int control = 0;

    for(int i=0; i<strlen(s1); i++)
    {
        for(int j=0; j<strlen(s2); j++)
        {
            if(s1[i] == s2[j]) control++;
        }
    }

    return control;
}

int main(void)
{
    FILE *file = fopen("d8.txt","r");


    char tmp[8];

    int answer = 0;

    long carriage_return = 0;

    while (!feof(file))
    {
        segments *numbers = malloc(sizeof(segments));
        int answer_tmp = 0;
        carriage_return = ftell(file);
        //fseek(file,carriage_return +61,SEEK_SET);

        for(int i=0 ;i<10; i++)
        {
            fscanf(file,"%s",tmp);
            matcher(numbers,tmp);
        }

        fseek(file,carriage_return,SEEK_SET);

        for(int i=0; i<10; i++)
        {
            fscanf(file,"%s",tmp);
            decoder(numbers,tmp);
        }

        fseek(file,ftell(file)+2,SEEK_SET);

        
        for(int i=0 ;i<4; i++)
        {
            fscanf(file,"%s",tmp);
            for(int j=0;j<10; j++)
            {
                if(comparator(tmp,numbers->numbers[j]) == strlen(tmp) && comparator(tmp,numbers->numbers[j]) == strlen(numbers->numbers[j]))
                {

                    answer_tmp += j*pow(10,3-i);
                    break;

                }
            }
        }
        printf("%d\n",answer_tmp);
        answer += answer_tmp;



    }
    printf("%d",answer);
}