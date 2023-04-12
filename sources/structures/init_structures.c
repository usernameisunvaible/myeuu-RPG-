/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"
#include <stdlib.h>
#include <stdio.h>

structures_t *init_structures(elements_t *elements)
{
    structures_t *temp = malloc(sizeof(structures_t));

    temp->belts = init_belts();
    temp->factories = init_factories(elements);
    return temp;
}
