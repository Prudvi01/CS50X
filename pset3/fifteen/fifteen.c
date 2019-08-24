/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }
    
    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(200000);
    printf("Loading...\n");
    usleep(400000);
    for(int i=0;i<25;i++)
    {
        printf("#");
        usleep(200000);
    }
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // TODO
    int high=(d*d)-1;
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            board[i][j]=high;
            high--;
            
        }
    }
            if(d%2==0)
            {
                    board[d-1][d-3]=1;
                    board[d-1][d-2]=2;
            }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            if(j==d-1)
            {
                if(board[i][j]==0)
                {
                    printf("__  \n");
                }
                else
                {
                    printf("%2i  \n",board[i][j]);
                }
            }
            else
            {
                if(board[i][j]==0)
                {
                    printf("__  ");
                }
                else
                {
                    printf("%2i  ",board[i][j]);
                }
            }
        }
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO
    int tx,ty,bkx,bky;
    for(int a=0;a<d;a++)
    {
        for(int b=0;b<d;b++)
        {
            //to find to coordinates of the required tile
            if(board[a][b]==tile)
            {
                tx=a;
                ty=b;
                break;
            }
        }
    }
    for(int x=0;x<d;x++)
    {
        for(int y=0;y<d;y++)
        {
            //to find to coordinates of the blank tile
            if(board[x][y]==0)
            {
                bkx=x;
                bky=y;
                break;
            }
        }
    }
    if(board[tx][ty]==board[bkx+1][bky] || board[tx][ty]==board[bkx-1][bky] || board[tx][ty]==board[bkx][bky+1] || board[tx][ty]==board[bkx][bky-1])
    {
        int temp=board[tx][ty];
        board[tx][ty]=0;
        board[bkx][bky]=temp;
        
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    int check=1;
    int won_board[d][d];
    int value=1;
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            won_board[i][j]=value;
            value++;
             if(i==d-1 && j==d-1)
            {
                won_board[i][j]=0;
            }
        }
    }
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            if(board[i][j]==won_board[i][j])
            {
                check=0;
            }
            else
            {
                check=1;
                break;
            }
        }
    }
    if(check==0)
    {
        return true;
    }
    else
    {
        return false;
    }
   
    
}
