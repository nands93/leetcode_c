#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0 || strs[0] == NULL)
        return "";
    int i = 0;
    int len = strlen(strs[0]);
    char *result = (char*)malloc(len + 1);
    result = strcpy(result, strs[0]);
    for (int i = 0; i <= strsSize - 1; i++)
    {
        int j = 0;
        while (result[j] && strs[i][j] && result[j] == strs[i][j])
            j++;
        result[j] = '\0';
    }
    return (result);
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