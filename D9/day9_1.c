#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define h 100
#define v 100

typedef struct data
{
    int map[v][h];
    int x;
    int y;
    int border_x;
    int border_y;

}data;

int con_num(char number);


int sonar(data *data)
{
    int circle[4] = {-1,-1,-1,-1};

    
    if(data->x > 0)
    {
        circle[0] = data->map[data->y][((data->x)-1)];
    }

    if(data->y > 0)
    {
        circle[1] = data->map[data->y-1][data->x];
    }

    if(data->border_x != data->x )
    {
        circle[2] = data->map[data->y][data->x+1];
    }

    if(data->border_y != data->y )
    {
        circle[3] = data->map[data->y+1][data->x];
    }
    

   

    int min = 10;
    for(int i=0; i<4; i++)
    {
        if(circle[i] != -1 && circle[i] < min)
        {
            min = circle[i];
        }
    }

    if(data->map[data->y][data->x] >= min )
    {
        return 0;
    } 
    else
    {
        //printf("\n%d",data->map[data->y][data->x]);
        return data->map[data->y][data->x]+1;  
    } 
    
    
}



int main(void)
{
    FILE *file = fopen("d9.txt","r");

    char tmp;
    int horizontal = 0; 

    while(tmp != '\n')
    {
        fscanf(file,"%c",&tmp);
        horizontal++;
    }

    horizontal--; // for \n
    fseek(file,0,SEEK_END);
    int end = ftell(file);
    int vertical = end/horizontal;


    rewind(file);

    int number_map[vertical][horizontal];



    for(int i=0; i<vertical; i++)
    {
        for(int j=0; j<horizontal; j++)
        {
                
            fscanf(file,"%c",&tmp);
            if( tmp != '\n')
            {
                number_map[i][j] = con_num(tmp);
            }
            else j--;

        }
            
    }
    

    data *data1 = malloc(sizeof(data));

    data1->border_x = horizontal-1;
    data1->border_y = vertical-1;
    
    for(int i=0; i<vertical;i++)
    {
        for( int j=0; j<horizontal; j++)
        {
            data1->map[i][j] = number_map[i][j];
        }
    }

   
    data1->x = 0;
    data1->y = 0;

    int risk_level=0;
    for(int i=0; i<vertical;i++)
    {
        for(int j=0;j<horizontal;j++)
        {
            data1->y = i;
            data1->x = j;
            risk_level += sonar(data1);
        }
    }
    printf("\n%d",risk_level);


}

int con_num(char number)
{
    if(number == '0') return 0;
    else if(number == '1') return 1;
    else if(number == '2') return 2;
    else if(number == '3') return 3;
    else if(number == '4') return 4;
    else if(number == '5') return 5;
    else if(number == '6') return 6;
    else if(number == '7') return 7;
    else if(number == '8') return 8;
    else if(number == '9') return 9;
}