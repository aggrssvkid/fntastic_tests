#include "../headers/convert.h"

void    convert_str(char *convert_str, char *source_str)    // convert_str-строка для записи информации, source_str-строка для считывания информации
{
    char    *checker;                                       // указатель, которым я пробегаюсь по всей исходной строке и сравниваю с текущим символом исходной строки
    char    *source_move;                                   // перебираем каждый символ исходной строки с помощью этого указателя
    char    *convert_move;                                  // записываем выходные данные этим указателем
    int     flag_find;                                      // флажек, обозначающий, нашли ли мы повтор текущего символа в исходной строке

    convert_move = convert_str;
    source_move = source_str;
    while (*source_move != '\0' && *source_move != '\n')    // внешний цикл, в котором мы проходимся по каждому символу исходной строки
    {
        checker = source_str;
        flag_find = 0;
        while (*checker != '\0' && *checker != '\n')        // внутренний цикл, в котором мы ищем совпадения с символом, на который указывает source_move в данный момент
        {
            if (checker == source_move)                     // осторожно! не надо проверять на совпадение текущий символ. Он всегда совпадает сам с собой!
                checker++;
            else if (is_duplicate(*checker, *source_move) == 1) // запускаем функцию сравнивания символов, если совпадение есть, то флажек ставим в единичку
            {
                flag_find = 1;
                break;
            }
            else
                checker++;
        }
        if (flag_find == 0)                                 // записываем в выходную строку подходящий символ по итогам сравнения
            *convert_move = '(';
        else
            *convert_move = ')';
        source_move++;                                      // переходим к следующем элементу для сравнения
        convert_move++;
    }
}