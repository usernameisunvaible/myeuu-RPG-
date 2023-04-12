/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef EDITOR_H_
    #define EDITOR_H_

    #include "../engine/includes/include_engine.h"

    #define NB_OBJ 12

typedef struct build_obj_s {
    int obj;
    sprite_sheet_t *preview;
}build_obj_t;

typedef struct build_tool_s {
    sfBool isactive;
    int obj;
    build_obj_t **all_object;
}build_tool_t;

#endif //EDITOR_H_
