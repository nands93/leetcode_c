#include <string.h>
#include <stdio.h>

int romanToInt(char* s)
{
    char    arr[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int     num[] = {1, 5, 10, 50, 100, 500, 1000};
    int    new_arr = 0;
    int  len = strlen(s) - 1;
    int arr_len = (sizeof(arr) / sizeof(arr[0]));
    int result = 0;

    for (int i = len; i >= 0; i--)
    {
        for (int j = arr_len - 1; j >= 0; j--)
        {
            new_arr = 0;
            if (s[i] == arr[j])
            {
                if  (i > 0 && (s[i] == 'V') && (s[i - 1] == 'I'))
                {
                    new_arr = num[j] - num[j - 1];
                    i--;
                }
                else if ((i > 0 && ((s[i] == 'X') && (s[i - 1] == 'L'))) || (i > 0 && ((s[i] == 'C') && (s[i - 1] == 'D'))))
                {
                    new_arr = num[j + 1] + num[j];
                    i--;
                }
                else if ((i > 0 && ((s[i] == 'X') && (s[i - 1] == 'I'))) || (i > 0 && ((s[i] == 'C') && (s[i - 1] == 'X'))) || (i > 0 && ((s[i] == 'M') && (s[i - 1] == 'C'))))
                {
                    new_arr = num[j] - num[j - 2];
                    i--;
                }
                else
                {
                    new_arr = new_arr + num[j];
                }
                result += new_arr;
                break;
            }
        }
    }
    return (result);
}

int main()
{
    char* s = "MCDLXXVI";
    int number = romanToInt(s);
    printf("%d\n", number);
    return (0);
}