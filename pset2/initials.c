#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    // TODO
 
    string name=get_string();
    int length=strlen(name);
    int count=0;
    
    for(int i = 0; i<length ; i++)
    {
       
       
       if(name[i]==' ' || name[i+1]=='\0')
        { 
           
            char c=toupper(name[count]);
            printf("%c",c);
            count=i+1;
        }
    }
    printf("\n");
}