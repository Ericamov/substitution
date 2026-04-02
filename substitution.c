#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int validate_key(string key);
void encipher(string key, string text);

int main(int argc, string argv[])
{
    // Check number of arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    // Check if key is valid
    if (validate_key(argv[1]))
        return 1;

    // Get plaintext from user
    string plaintext = get_string("plaintext: ");

    // Encipher text and print it
    printf("ciphertext: ");
    encipher(argv[1], plaintext);
    return 0;
}

int validate_key(string key)
{
    int len = strlen(key);

    // If key isn't 26 characters long print error message and return status code 1
    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // If a character is not a letter print error message and return 1
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        // If a letter is repeated print error message and return 1
        char current_char = key[i];

        for (int j = i + 1; j < len; j++)
        {
            if (toupper(key[j]) == toupper(current_char))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    return 0;
}

// Iterate through plaintext and substitute each letter with corresponding letter from key
void encipher(string key, string text)
{
    int len = strlen(text);
    char letter;
    int index;

    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                // Substitute uppercase letter
                index = text[i] - 'A';
                letter = toupper(key[index]);
            }
            else
            {
                // Substitute lowercase letter
                index = text[i] - 'a';
                letter = tolower(key[index]);
            }
            printf("%c", letter);
        }
        // If it's not a letter print char as it is
        else
            printf("%c", text[i]);
    }
    printf("\n");
}
