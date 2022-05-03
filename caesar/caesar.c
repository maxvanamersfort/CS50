#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

string rotate(string plaintext, int key);
int main(int argc, string argv[])

{
    //running on only one argument
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //make sure argv will be in digits
    for(int i= 0, dignum = strlen(argv[1]); i < dignum; i++)
    if(! isdigit(argv[1][i]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //convert string to int
    int key = (atoi(argv[1]));

    //prompt for plaintext
    string plaintext = get_string("plaintext: ");

    //implemnt rotate function
    string ciphertext = plaintext;
    string rotate(string plaintext, int key);
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (! isalpha(plaintext[i]))
        {
            //printf("%s\n", ciphertext);
        }
        if (isupper(plaintext[i]))
        {
            ciphertext[i] = (plaintext[i] - 65);
            ciphertext[i] = (plaintext[i] + key) % 26;
            ciphertext[i] = (plaintext[i] + 65);
            //printf("%s\n", ciphertext);
        }
        if (islower(plaintext[i]))
        {
            ciphertext[i] = (plaintext[i] - 97);
            ciphertext[i] = (plaintext[i] + key) % 26;
            ciphertext[i] = (plaintext[i] + 97);
            //printf("%s\n", ciphertext);
        }
    }
    printf("ciphertext: %s\n", ciphertext);

}