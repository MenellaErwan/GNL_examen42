#include "get_next_line.h"
#define BUFFER_SIZE 1

int ft_strlen(char *str)
{
    int i;
    i = 0;
    while(str[i])
        i++;
    return (i);
}

char    *ft_strchr(char *str, char c)
{
    size_t i;
    i = -1;
    while (str[++i])
        if (str[i] == c)
            return(&str[i]);
    return (NULL);
}

char *ft_strjoin_free(char *s1, char *s2)
{
    int     lens1;
    int     lens2;
    int     i;
    char    *str;
    i = 0;
    lens1 = 0;
    if (s1)
        lens1 = ft_strlen(s1);
    lens2 = ft_strlen(s2);
    if (!(str = malloc(sizeof(char) * (lens1 + lens2 + 1))))
        return(NULL);
    while (i < lens1 + lens2)
    {
        if (i < lens1)
            str[i] = s1[i];
        else if (i >= lens1)
            str[i] = s2[i - lens1];
        i++;
    }
    str[lens1 + lens2] = '\0';
    free(s1);
    return (str);
}

int get_next_line(char **line)
{
    static char buffer[BUFFER_SIZE + 1];
    int readed;
    readed = 0;
    if(!(*line = malloc(sizeof(char))))
        return (-1);
    *line[0] = 0;
    while ((readed = read(0, buffer, BUFFER_SIZE)) > 0 && !ft_strchr(buffer, '\n'))
    {
        buffer[BUFFER_SIZE] = '\0';
        *line = ft_strjoin_free(*line, buffer);
    }
    if (readed != 1)
        return(0);
    else
        return(1);
}