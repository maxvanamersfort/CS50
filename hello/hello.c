#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //defining name and creating the string
    string name = get_string("What's your name?");

    //print the variable "name" with the string
    printf("Hello, %s\n", name);
}