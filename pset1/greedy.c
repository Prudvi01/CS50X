#include <cs50.h>
#include <stdio.h>
#include<math.h>

int main(void)
{
    // TODO
    printf("How much amount do I owe you?\nEnter: ");
    float owe=get_float();
    int cents = rint(owe* 100);
    int quarter=25;
    int dime=10;
    int nickel=5;
    int penny=1;
    int count=0;
    while(cents<0)
    {
        printf("Enter valid value\nEnter: ");
        owe=get_float();
        cents = rint(owe * 100);
    }



    while(cents!=0)
    {


    if(cents>=quarter)
    {
        count++;
        cents=cents-quarter;


    }
    else if(cents>=dime && cents<25)
    {
        count++;
        cents=cents-dime;


    }
    else if(cents>=nickel && cents<10)
    {
        count++;
        cents=cents-nickel;


    }
    else if(cents>=penny && cents<5)
    {
        count++;
        cents-=penny;


    }

    }
    printf("%i\n",count);

}













