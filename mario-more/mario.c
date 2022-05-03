#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //declare variable height
    int height;

    //Make sure number isn't < or > 1 & 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //creating a new line with integer line
    for (int line= 0; line < height; line++)

    {
        //creating space
        for (int space = height - line - 1; space > 0; space--)
        {
            printf(" ");
    }
        //creating the first hash pyramid
        for (int left_hash = 0; left_hash < line + 1; left_hash++)
        {
            printf("#");
        }
        //creating the gap between pyramids
        printf("  ");

        //creating second hash pyramid
        for (int right_hash = 0; right_hash < line + 1; right_hash++)
        {
            printf("#");
        }
        //end of the sequence
        printf("\n");
    }

}
