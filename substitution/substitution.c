#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

const int N = 26;
const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(int argc, string argv[])

{

    //make sure only one argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //make sure it's alpabatical
    int letters[N];
    for (int i = 0, keylen = strlen(argv[1]); i < keylen; i++)
    {
    if (! isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    //make sure lowercase or uppercase doesnt matter for the encryption
    else if (islower(argv[1][i]))
        {
        argv[1][i] = toupper(argv[1][i]);
        }

    //make sure no double letters used
    for(int j= 0; j < N; j++)
        {
        if((argv[1][i]) == letters[j])
            {
                printf("Key can't contain the same letters\n");
                return 1;
            }
        }
        letters[i]= argv[1][i];
    }


    //make sure that input is 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //make plaintext prompt
    string plaintext = get_string("plaintext: ");

    //make sure it runs on input encryption
    int l = strlen(plaintext);
    char ciphertext[l + 1];

    //running trough the plaintext
    for(int i= 0; i < l; i++)
    {
        //for the non alphabetical chars
        if (! isalpha(plaintext[i]))
        {
            ciphertext[i] = plaintext[i];
        }

        //for uppercase chars
        if (isupper(plaintext[i]) != 0)
        {
            for(int j= 0; j < N; j++)
            {
                if (plaintext[i] == alphabet[j])
                {
                    ciphertext[i] = argv[1][j];
                    break;
                }
            }
        }

        //for lowercase chars
        if (islower(plaintext[i]) != 0)
        {
            for(int j= 0; j < strlen(alphabet); j++)
            {
                if (plaintext[i] == tolower(alphabet[j]))
                {
                    ciphertext[i] = tolower(argv[1][j]);
                    break;
                }
            }
        }
    }
    //going back to string
    ciphertext[l] = '\0';

    //print the ciphertext
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}