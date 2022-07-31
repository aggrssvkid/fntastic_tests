static int  is_source_low_case(char checker, char source)
{
    if (checker + 32 == source)
        return (1);
    return (0);
}

static int  is_source_up_case(char checker, char source)
{
    if (checker - 32 == source)
        return (1);
    return (0);
}

int is_duplicate(char checker, char source)
{
    if (checker == source)
        return (1);
    else if ((checker >= 'A' && checker <= 'Z') && \
    is_source_low_case(checker, source) == 1)
        return (1);
    else if ((checker >= 'a' && checker <= 'z') && \
    is_source_up_case(checker, source) == 1)
        return (1);
    return (0);
}