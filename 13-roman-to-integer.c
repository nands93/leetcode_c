#include <string.h>
#include <stdio.h>

int romanToInt(char* s)
{

    int total = 0;
    int i = 0;
    int len = strlen(s);

    while(i < len)
    {
        int current = 0;
        int next = 0;
        
        switch(s[i])
        {
            case 'I': current = 1; break;
            case 'V': current = 5; break;
            case 'X': current = 10; break;
            case 'L': current = 50; break;
            case 'C': current = 100; break;
            case 'D': current = 500; break;
            case 'M': current = 1000; break;
        }
        
        if (i + 1 < len) {
            switch(s[i + 1])
            {
                case 'I': next = 1; break;
                case 'V': next = 5; break;
                case 'X': next = 10; break;
                case 'L': next = 50; break;
                case 'C': next = 100; break;
                case 'D': next = 500; break;
                case 'M': next = 1000; break;
            }
        }
        
        if (current < next) {
            total += (next - current);
            i += 2;
        } else {
            total += current;
            i++;
        }
    }
    
    return total;
}

int main()
{
    int number = 0;
    char* roman[] = {"III", "LVIII", "MCMXCIV", "MCDLXXVI", "MMMXLV"};

    for (int i = 0; i <= 4; i++)
    {
        number = romanToInt(roman[i]);
        printf("%s is %d\n", roman[i], number);
    }
    return (0);
}