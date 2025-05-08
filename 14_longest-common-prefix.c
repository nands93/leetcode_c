#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0;
    while (strs[i])
    {
    }
    
}

int main()
{
    char* strs[] = {"flower", "flow", "flight"};
    int size = sizeof(strs) / sizeof(strs[0]);
    char* result = longestCommonPrefix(strs, size);
    printf("Longest common prefix: %s\n", result);
    free(result);
    return 0;
}