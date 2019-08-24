#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc,string argv[])
{
    if(argc==2)
    {
    int n=strlen(argv[argc-1]);
    for(int z=0;z<n;z++)
    {
        if(isalpha(argv[argc-1][z])==0)
        {
            printf("Enter only alphabets as input");
            return 1;
        }
    }
    printf("plaintext: ");
    string plain_text=get_string();
    int len=strlen(plain_text);
    printf("ciphertext: ");
    int letter;
    int p=0;
    char r;
    for(int i=0;i<len;i++)
    {
        r=argv[argc-1][(i-p)%n];
        if (isalpha(plain_text[i]) !=0)
        {
            if(isupper(r) !=0)
            {
               letter=(r-'A')+plain_text[i];
            }
            else if(islower(r) !=0)
            {
               letter=(r-'a')+plain_text[i];
            }
        
            if(isupper(plain_text[i]))
            {
               if(letter>90)
               {
                   printf("%c",65+((letter-65)%26));
               }
               else
               {
                   printf("%c",letter);
               }
            }
            else if(islower(plain_text[i]))
            {
              if(letter>122)
              {
                  printf("%c",97+((letter-97)%26));
              }
              else
              {
                  printf("%c",letter);
              }
            }
       
        }
        else if (isalpha(plain_text[i])==0)
        {
            printf("%c",plain_text[i]);
            p+=1;
            
        }
    }
    printf("\n");
    }
    else
    {
        printf("Usage: ./vigenere k");
        return 1;
    }
}