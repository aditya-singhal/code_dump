#include<stdio.h>
#include<stdlib.h>


#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

void display_board(int n, char board[10][10]);                  // Displays the board 
void human_player(int n, char board[10][10]);                   // Executes to play with human players
int evaluate_score(int n, char board[10][10]);                  // Evaluates the score
_Bool moves_are_left(int n, char board[10][10]);                // Checks if any moves are left


void human_player(int n,char board[10][10])
{
    int won=0;
    display_board(n,board);
    while(moves_are_left(n,board))
    {
        int a,b;
again_inp1:     printf("Player 1 trun provide row and column");
        scanf("%d %d",&a,&b);
        if(a<0 || a>=n || b<0 || b>=n)
            goto again_inp1;
        if(board[a][b]=='_')
            board[a][b]='x';
        else 
        {printf("Position already occupied\n"); goto again_inp1;}
        display_board(n,board);
        if(evaluate_score(n,board)==-10)
            {printf("Player 1 won");won=1;break;}

again_inp2:     printf("Player 2 trun provide row and column");
        scanf("%d %d",&a,&b);
        if(a<0 || a>=n || b<0 || b>=n)
            goto again_inp2;
        if(board[a][b]=='_')
            board[a][b]='o';
        else 
        {printf("Position already occupied\n"); goto again_inp2;}
        display_board(n,board);
        if(evaluate_score(n,board)==10)
            {printf("Player 1 won");won=1;break;}

    }
    if(won==0)
        printf("Draw Match");
}



int evaluate_score(int n, char board[10][10])
{
    int i,j;
    for(i=0;i<n;i++)              // check if any row is fully filled with x and return -10 score
    {
        int flag=0;
        for(j=0;j<n;j++)
            if(board[i][j]=='x')
                flag++;
        if(flag==n)
        return -10; 
    }
    for(i=0;i<n;i++)              // check if any column is fully filled with x and return -10 score
    {
        int flag=0;
        for(j=0;j<n;j++)
            if(board[j][i]=='x')
                flag++;
        if(flag==n)
        return -10; 
    }


    for(i=0;i<n;i++)              // check if any row is fully filled with o and return 10 score
    {
        int flag=0;
        for(j=0;j<n;j++)
            if(board[i][j]=='o')
                flag++;
        if(flag==n)
        return 10;  
    }
    for(i=0;i<n;i++)              // check if any column is fully filled with o and return 10 score
    {
        int flag=0;
        for(j=0;j<n;j++)
            if(board[j][i]=='o')
                flag++;
        if(flag==n)
        return 10;  
    }
    int flag=0;
    for(i=0;i<n;i++)                // check if 1st diagonal is fully filled with o and return 10 score
    {
        
        if(board[i][i]=='o')
            flag++;
    }
    if(flag==n)
        return 10;

    flag=0;
    for(i=0;i<n;i++)                // check if 1st diagonal is fully filled with x and return -10 score
    {
        
        if(board[i][i]=='x')
            flag++;
    }
    if(flag==n)
        return -10;

    flag=0;                         // check if 2nd diagonal is fully filled with x and return -10 score
    for(i=0;i<=n;i++)
    {
        if(board[n-1-i][i]=='x')
            flag++;
    }
    if(flag==n)
        return -10;

    flag=0;                         // check if 2nd diagonal is fully filled with 0 and return 10 score
    for(i=0;i<=n;i++)
    {
        if(board[n-1-i][i]=='o')
            flag++;
    }
    if(flag==n)
        return 10;
    return 0;                       // return 0 if no one has won yet 
}

_Bool moves_are_left(int n, char board[10][10])
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(board[i][j]=='_') return 1;

    return 0;
}




void display_board(int n, char board[10][10])
{
    int i=0;
    int j=0;
    for(i=0;i<n;i++)
        {
        for(j=0;j<n;j++)
            {printf(" %c ",board[i][j]);if(j!=n-1)printf("|");}
        printf("\n");
        }
}

void main()
{
    int n,i,j;
Again:  printf("Enter Grid size 3-10\n");
    scanf("%d",&n);
    if(n<3 || n>10)
        goto Again;
    

    char board[10][10];
    for( i=0;i<n;i++)
    for(j=0;j<n;j++)
    board[i][j]='_';      



    human_player(n,board);
    

}