#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
string encrypt(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    if (argc == 2)
    { // first argument is prog name and second is the key
        string s = argv[1];
        int len = strlen(s);
        if (len != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        bool flag[26];
        for (int i = 0; i < 26; i++)
        {
            flag[i] = 1;
        }
        for (int i = 0; i < 26; i++)
        {
            if (isalpha(s[i]))
            {
                if (islower(s[i]))
                    flag[s[i] - 97] = 0;
                else if (isupper(s[i]))
                    flag[s[i] - 65] = 0;
            }
            else
            {
                printf("Key must contain alphabetic characters.\n");
                return 1;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (flag[i])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
        string ans = encrypt(s);
        printf("ciphertext: %s\n", ans);
    }
    return 0;
}

string encrypt(string s)
{
    string str = get_string("plaintext: ");
    for (int i = 0; i < strlen(str); i++)
    {
        if (islower(str[i])) // lower case letters
            str[i] = tolower(s[str[i] - 97]);
        else if (isupper(str[i])) // upper case letters
            str[i] = toupper(s[str[i] - 65]);
    }
    return str;
}