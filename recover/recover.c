#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE* raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Please use valid file\n");
        return 1;
    }

    unsigned char buffer[BLOCK_SIZE];

    int count = 0;
    FILE* image = NULL;
    int found = 0;

    while (fread(buffer, BLOCK_SIZE, 1, raw_file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (found == 1)
            {
                fclose(image);
            }
            else
            {
                found = 1;
            }

            char filename[8];
            sprintf(filename, "%03d.jpg", count);
            image = fopen(filename, "a");
            count++;
        }

        if (found == 1)
        {
            fwrite(&buffer, BLOCK_SIZE, 1, image);
        }
    }

    fclose(raw_file);
    fclose(image);

    return 0;
}