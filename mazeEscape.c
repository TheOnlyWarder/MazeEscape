/*
Author:Sinan Cem Daðtekin
Purpose:to find shortest way out in a 2D matrix.
*/
#include <stdio.h>
#define SIZE1 6
#define SIZE2 12
//manual map entrance
    int map[SIZE1][SIZE2]={
                            {1,0,1,1,1,0,0,1,0,1,1,0},
                            {1,0,1,1,1,1,1,0,1,0,0,0},
                            {1,1,1,1,1,1,1,0,1,0,1,0},
                            {1,0,0,1,0,1,0,1,1,1,1,1},
                            {0,1,1,1,1,1,1,1,0,0,0,1},
                            {1,1,1,0,1,1,1,1,1,1,1,1}
                          };
    int i,j;//counter values for loop

void shortestWayFunc(int x,int y)//function which founds and prints shortest way
{

    if(x<SIZE1&&map[x+1][y]==1)
    {
        map[x+1][y]=4;
        return shortestWayFunc(x+1,y);
    }
    else if(y<SIZE2&&map[x][y+1]==1)
    {
        map[x][y+1]=4;
        return shortestWayFunc(x,y+1);
    }
    else if(x-1>=0&&map[x-1][y]!=0)
    {
        map[x][y]=0;
        return shortestWayFunc(x-1,y);
    }
    else if(y-1>=0&&map[x][y-1]!=0)
    {
        map[x][y]=0;
        return shortestWayFunc(x,y-1);
    }

}

int main()
{
    //printing the maze
printf("THE LABIRENT\n");
    for(i=0;i<SIZE1;i++)
    {
        for(j=0;j<SIZE2;j++)
        {
            printf("%d",map[i][j]);
        }
        printf("\n");
    }
    //function caling
    if(map[0][0]==1)
    {
        shortestWayFunc(0,0);
        printf("[%d][%d]\n",0,0);
    }
    else
        printf("wrong input");
//for path printing as array
    for(i=0;i<SIZE1;i++)
    {
        for(j=0;j<SIZE2;j++)
        {
            if(map[i][j]==4)
                printf("[%d][%d]\n",i,j);
        }
    }
    printf("[%d][%d]\n",SIZE1-1,SIZE2-1);
//for path printing in a maze
    for(i=0;i<SIZE1;i++)
    {
        for(j=0;j<SIZE2;j++)
        {
            printf("%d",map[i][j]);
        }
        printf("\n");
    }

return 0;
}
