#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define SIZE_OF_BLOCK 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover picture\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    //if fails openning, it shows "Failed to open" with return error code 3
    if (input_file == NULL)
    {
        printf("Failed to open\n");
        return 3;
    }

    //Declaration of variable "buffer" to store 512
    unsigned char buffer[SIZE_OF_BLOCK];

    //declare variable to be used in loop later on
    int count_image = 0;

    //Outputs data from input file
    FILE *output_file = NULL;

    char *filename = malloc(8 * sizeof(char));


    //*Reads input file and stores in buffer*
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        //Loops to check to find out when bytes are found in a JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //writes name of files
            sprintf(filename, "%03i.jpg", count_image);

            output_file = fopen(filename, "w");

            //count number of image found
            count_image++;
        }

        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), SIZE_OF_BLOCK, output_file);
        }

    }
    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;
}