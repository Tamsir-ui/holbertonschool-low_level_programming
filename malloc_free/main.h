#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

/**
 * File: main.h
 * Author: Djibril Tamsir Niang
 * Desc: Header file for the C - malloc, free project.
 * Contains all function prototypes used across the project.
 */

/* ======== Function Prototypes ======== */

char *create_array(unsigned int size, char c);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
int **alloc_grid(int width, int height);
void free_grid(int **grid, int height);

#endif /* MAIN_H */
