#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(int argc,string argv[])
{
    if(argc==2)
    {
    int key=atoi(argv[1]);
    printf("plaintext: ");
    string plain_text=get_string();
    int len=strlen(plain_text);
    printf("ciphertext: ");
    int c;
    for(int i=0;i<len;i++)
    {
        c=key+plain_text[i];
        if(plain_text[i]>=65 && plain_text[i]<=90)
        {
            if(c>90)
            {
                printf("%c",65+((c-65)%26));
            }
            else
            {
                printf("%c",c);
            }
        }
        else if(plain_text[i]>=97 && plain_text[i]<=122)
        {
            if(c>122)
            {
            printf("%c",97+((c-97)%26));
            }
            else
            {
                printf("%c",c);
            }
        }
        else
        {
            printf("%c",plain_text[i]);
        }
    }
    printf("\n");
    }
    else
    {
        printf("retry");
        return 1;
    }
}