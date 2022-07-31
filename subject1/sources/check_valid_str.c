#include "../headers/convert.h"

int check_valid_str(char *str)
{
    if (str == 0)
    {
        printf("Bad string, try again\n");
        return (0);
    }
    if (*str == '\n' && *(str + 1) == '\0')
    {
        printf("Nothing to convert.\n");
        free(str);
        return (0);
    }
    return (1);
}