#include <stdlib.h>
#include <stdio.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }

    char *infile = argv[1];

    // Open file
    FILE *file = fopen(infile, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Cannot open file %s.\n", infile);
        return 2;
    }

    // Create buffer to hold JPG blocks
    unsigned char buffer[BLOCK_SIZE];
    // Count how many jpgs recovered
    int jpg_count = 0;
    // Boolean to check when the first image header is found
    int first_header_found = 0;
    // Holds file name for recovered jpg
    char filename[8];
    // Holds file pointer for jpg
    FILE *img;

    // Read from file until reaching EOF
    while(fread(buffer, BLOCK_SIZE, 1, file) == 1)
    {
        // Check if first 4 bytes of buffer match JPG header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(first_header_found)
            {
                // close image
                fclose(img);
            }
            else
            {
                first_header_found = 1;
            }

            jpg_count++;

            // Name file with format 00x, where x is the jpg count
            sprintf(filename, "%03i.jpg", jpg_count);

            img = fopen(filename, "w");
            fprintf(stderr, "Found file %s.\n" , filename);
        }

        // Write into img
        if (first_header_found)
        {
            // Continue writing into file
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
    }
}