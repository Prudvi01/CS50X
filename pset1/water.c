#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("How many minutes did you spend in the shower?\n");
    int min=get_int();
    int bott=min*12;
    printf("Minutes: %i\n",min);
    if(min==1)
    {
    printf("%i minute equals to %i bottles\n", min, bott);
    }
    else
    {
      printf("%i minutes equals to %i bottles\n",min,bott);  
    }
   
    
}