#include <cs50.h>
#include <stdio.h>

int main(void)
{
  printf("Enter the desired height : ");
  
  int ht=get_int();
  while(ht<0 || ht>23)
  {
   printf("Enter a number between 0 and 23 only\nEnter:");   
   ht=get_int();
  }
  for(int i=1; i<=ht; i++)
  {
      for(int j=ht-i; j>0; j--)
      {
          printf(" ");
          
      }
      for(int k=1;k<=i+1;k++)
      {
          printf("#");
          
      }
      printf("\n");
  }
    
}