#include <string.h>
#include <stdbool.h>
#include <stdio.h>

bool isValid(char* s) 
{
    size_t len = strlen(s);
    if (len % 2 != 0)
        return false;
    int j = 0;
    char characters[len];
    for (size_t i = 0; s[i] != '\0'; i++) 
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            if (j >= len) {
                return false;
            }
            characters[j++] = s[i];
        }
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
        else
            return false;
    }
    return (j == 0);
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