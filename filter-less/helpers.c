#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int x = 0; x < width; x++)
        {

            float Total = image[i][x].rgbtBlue + image[i][x].rgbtRed + image[i][x].rgbtGreen;
            int average = (round)(Total / 3);
            image[i][x].rgbtBlue = image[i][x].rgbtRed = image[i][x].rgbtGreen = average;

        }


    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed, originalGreen, originalBlue;
    int sepiaRed, sepiaBlue, sepiaGreen;
   // going thought the height
    for ( int i = 0; i < height; i++)
    {
        for (int x = 0; x < width; x++)
        {
           // assign value to the created variables created above
            originalRed = image[i][x].rgbtRed;
            originalGreen = image[i][x].rgbtGreen;
            originalBlue = image[i][x].rgbtBlue;

            // calculation of the sepia Red color and update with the new value
            sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);


            if (sepiaRed > 255)
            {
                image[i][x].rgbtRed = 255;
            }
            else
            {
                image[i][x].rgbtRed = sepiaRed;
            }

            // calculation of the sepia Green color and update with the new value
            sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            if (sepiaGreen > 255)
            {
                image[i][x].rgbtGreen = 255;
            }
            else
            {
                image[i][x].rgbtGreen = sepiaGreen;
            }

             // calculation of the sepia Blue color and update with the new value
            sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);
            if (sepiaBlue > 255)
            {
                image[i][x].rgbtBlue = 255;
            }
            else
            {
                image[i][x].rgbtBlue = sepiaBlue;
            }
        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int x = 0; x < width / 2; x++)
        {
            RGBTRIPLE temp = image[i][x];
            image[i][x] = image[i][width - (x + 1)];
            image[i][width - (x + 1)] = temp;
        }

    }

    return;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create temp image
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int total_Red, total_Blue, total_Green;
            total_Red = total_Blue = total_Green = 0;
            float counter = 0.00;

          // get pixes from neigboring
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    // check validiy of neighboring pixels
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    // get image
                    total_Red += image[currentX][currentY].rgbtRed;
                    total_Green += image[currentX][currentY].rgbtGreen;
                    total_Blue += image[currentX][currentY].rgbtBlue;

                    counter++;
                }

                 //average of neighboring pixels
                temp[i][j].rgbtRed = round(total_Red / counter);
                temp[i][j].rgbtGreen = round(total_Green / counter);
                temp[i][j].rgbtBlue = round(total_Blue / counter);
            }
        }

    }
// copy the blur image into the original one

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}