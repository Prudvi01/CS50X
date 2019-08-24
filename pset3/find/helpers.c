/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int left=0;
    int right=n-1;
    int mid=(left+right)/2;
    do
    {
        if(value==values[mid])
        {
            return true;
            break;
        }
        else if(value>values[mid])
        {
            left=mid+1;
            mid=(left+right)/2;
        }
        else if(value<values[mid])
        {
            right=mid-1;
            mid=(left+right)/2;
        }
    }
    while(left <= right);
    {
        return false;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    int temp=0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
        if(values[j]>values[j+1])
        {
            temp=values[j];
            values[j]=values[j+1];
            values[j+1]=temp;
            
        }
        }
    }
}
