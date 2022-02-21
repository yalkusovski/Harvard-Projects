#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)

{
    
    // list of variables
       float dollars;
       int cents;
       int coins = 0;

    // Ask user how much change is owned to them
        
    do
       {
           
        dollars = get_float("How much change is owed?:");
        
       }
        
    // Keep repeating until user provides positive number
    while (dollars < 0);
        
    //round dollars to cents
        cents = round(dollars * 100);
        
        
    // To get minimum number of coins
    while (cents >= 25)
    {
        cents = cents - 25;
        coins++;
        
    }
        
    while (cents >= 10)
    {
        cents = cents - 10;
        coins++;
        
    }
    while (cents >= 5)
        
    {
            
        cents = cents - 5;
        coins++;
        
    }
    while (cents >= 1)
    {
            
        cents--;
        coins++;
        
    }
    //The number of coints owned to the user
    printf("%d\n", coins);
        
        
}
    