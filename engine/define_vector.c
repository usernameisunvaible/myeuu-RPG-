/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "includes/include_engine.h"

sfVector2i define_vectori(int a, int b)
{
    sfVector2i vec;

    vec.x = a;
    vec.y = b;
    return vec;
}

sfVector2f define_vectorf(float a, float b)
{
    sfVector2f vec;

    vec.x = a;
    vec.y = b;
    return vec;
}

sfVector3f define_vectortf(int a, int b, int c)
{
    sfVector3f vec;

    vec.x = a;
    vec.y = b;
    vec.z = c;
    return vec;
}
