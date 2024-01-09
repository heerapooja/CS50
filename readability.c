#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

float count_letters(string s);
float count_words(string s);
float count_sentences(string s);

int main(void)
{
    string str = get_string("Text: ");
    float w = count_words(str);
    float l = count_letters(str) / w * 100;
    float s = count_sentences(str) / w * 100;

    // Coleman-Liau index formula:
    int x = round(0.0588 * l - 0.296 * s - 15.8);
    if (x >= 16)
        printf("Grade 16+\n");
    else if (x < 1)
        printf("Before Grade 1\n");
    else
        printf("Grade %d\n", x);
}
float count_letters(string t)
{
    float c = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        if (isalpha(t[i]))
            c++;
    }
    return c;
}
float count_words(string t)
{
    float c = 1;
    for (int i = 0; i < strlen(t); i++)
    {
        if (t[i] == ' ')
            c++;
    }
    return c;
}
float count_sentences(string t)
{
    float c = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        if (t[i] == '.' || t[i] == '!' || t[i] == '?')
            c++;
    }
    return c;
}
