#include <cs50.h>
#include <stdio.h>

int main(void)

{
    
    // Get positive integer from user
    
    int height;
    do
    {
        
        height = get_int("Height:");
        
    }
    while (height < 1 || height > 8);
    
    
    // height of the blocks
    
    for (int i = 0; i < height; i++)
    {
        
        //spaces from left to right
        for (int j = height - 1; j > i; j--)
        {
            printf(" ");
        }
        
        //number of #
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }  
        
        printf("\n");
    }
      
}