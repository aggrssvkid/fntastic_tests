#include "../headers/convert.h"

int main()
{
    char    *str;                                       // указатель, указывающий на область памяти, в которую мы запишем входные данные
    char    *converted_str;                             // указатель, указывающий на область памяти, в которую мы запишем вЫходные данные

    printf("Wakeup, Neo and...Enter the line!\n");
    str = get_next_line(0);                             // считываем введеную с консоли строку
    if (check_valid_str(str) == 0)                      // проверяем данные на корректность
        return (0);
    if (*(str + ft_strlen(str) - 1) == '\n')            // выделяем память под строку, в которые будем записывать выходные данные
        converted_str = malloc(ft_strlen(str) - 1);
    else
        converted_str = malloc(ft_strlen(str));
    if (converted_str == 0)                             // проверяем, выделила ли ОС требуемую память
    {
        printf("malloc error!\n");
        free(str);
        return (0);
    }
    convert_str(converted_str, str);                    // конвертируем исходную строку
    if (*(str + ft_strlen(str) - 1) == '\n')            
        printf("%s\n", converted_str);                  //выводим обновленные данные в консоль
    else
        printf("\n%s\n", converted_str);
    free(converted_str);                                //освобождаем память, выделенную в процессе работы программы
    free(str);
    return (0);
}