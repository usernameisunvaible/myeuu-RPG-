/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** Str to word array
*/

#include <stdlib.h>
#include "../../includes/include_all.h"

int isc1(char a, char l)
{
    if (a != l) {
        return 0;
    }
    return 1;
}

int cou(char *str, char l)
{
    int d = 0;
    int i;

    for (i = 0; i < my_strlen(str); ++i) {
        while (isc1(str[i], l) == 0 && str[i] != '\0')
            ++i;
        d += 1;
    }
    return d;
}

char **my_str_to_word_array(char *str, char l)
{
    int b = 0;
    int c = 0;
    int e = 0;
    char *w;
    char **a = malloc(sizeof(char *) * (cou(str, l) + 1));
    for (int i = 0; i < my_strlen(str); ++i) {
        for (;isc1(str[i + e], l) == 0 && str[i + e] != '\0'; e += 1);
        if (e) w = malloc(sizeof(char) * e + 1);
        for (;isc1(str[i], l) == 0 && str[i] != '\0'; b += 1, i += 1)
            w[b] = str[i];
        if (b >= 1) {
            w[b] = '\0';
            a[c] = w;
        }
        e = 0;
        if (b > 0) c += 1;
        b = 0;
    }
    a[c] = 0;
    return (a);
}
