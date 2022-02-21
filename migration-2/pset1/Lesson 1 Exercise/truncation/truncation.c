#include <stdio.h>
#include <cs50.h>

int main(void)
{
 
     // Get a numbers from user  
    int x = get_int ("x: ");
    int y = get_int ("y: ");
    
    // divide x by y

    printf ("%f\n", (float) x / (float) y); 
   
}