#include <string.h>
#include <stdbool.h>
#include <stdio.h>

bool isValid(char* s) 
{
    size_t len = strlen(s);
    if (len % 2 != 0)
        return false;
    int i = 0;
    int j = 0;
    char characters[len];
    while (s[i] != '\0')
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            characters[j++] = s[i];
       else if (s[i] == '}')
        {
            if (j == 0 || characters[--j] != '{')
                return false;
        }
        else if (s[i] == ']')
        {
            if (j == 0 || characters[--j] != '[')
                return false;
        }
        else if (s[i] == ')')
        {
            if (j == 0 || characters[--j] != '(')
                return false;
        }
        i++;
    }
    return true;
}

int main()
{
    char* s = "{[()]}";
    if (isValid(s))
        printf("The string is valid.\n");
    else
        printf("The string is not valid.\n");
    return 0;
}