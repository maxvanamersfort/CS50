#include "helpers.h"
#include <stdlib.h>
#include <math.h>

#define BLUR 3

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float greyscale;

    for (int i = 0; i < height; i++)
    {
        for (int  j = 0; j < width; j++)
        {
            greyscale = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.00);

            image[i][j].rgbtRed = greyscale;
            image[i][j].rgbtGreen = greyscale;
            image[i][j].rgbtBlue = greyscale;
        }
    }
    return;
}

int limit(int rgb)
{
    if (rgb > 255)
    {
        rgb = 255;
    }
    return rgb;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed;
            int sepiaGreen;
            int sepiaBlue;
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            sepiaRed = limit(round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue));
            sepiaGreen = limit(round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue));
            sepiaBlue = limit(round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue));

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
   int temp[3];
     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels from left to right
            temp[0] = image[i][j].rgbtBlue;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = temp[0];
            image[i][width - j - 1].rgbtGreen = temp[1];
            image[i][width - j - 1].rgbtRed = temp[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE new_image[height][width];
    double average_blue, average_green, average_red;
    int stat;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average_blue = average_green = average_red = stat = 0;
            // Box Blur
            for (int rows = i - ((BLUR - 1) / 2); rows <= i + ((BLUR - 1) / 2); rows++)
            {
               for (int cols = j - ((BLUR - 1) / 2); cols <= j + ((BLUR - 1) / 2); cols++)
               {
                   if ((rows >= 0 && rows < height) && (cols >= 0 && cols < width))
                   {
                        average_blue += image[rows][cols].rgbtBlue;
                        average_green += image[rows][cols].rgbtGreen;
                        average_red += image[rows][cols].rgbtRed;
                        stat++;
                   }
               }
            }
            if (stat != 0)
            {
                average_blue =  round(average_blue / (double) stat);
                average_green = round(average_green / (double) stat);
                average_red = round(average_red / (double) stat);
                new_image[i][j].rgbtBlue = average_blue;
                new_image[i][j].rgbtGreen = average_green;
                new_image[i][j].rgbtRed = average_red;
            }
            else
            {
                return;
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }
    return;
}
