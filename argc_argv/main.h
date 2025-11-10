#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * File: main.h
 * Author: Tamsir-ui bruh
 * Desc: Header file for the C - argc, argv project.
 * Contains prototypes of all functions used across
 * the project files.
 */

/* ======== Function Prototypes ======== */

/**
 * main - prints the name of the program.
 * @argc: number of arguments.
 * @argv: array of arguments.
 * Return: Always 0.
 */

int main(int argc, char *argv[]);
int print_program_name(int argc, char *argv[]);
int print_arg_count(int argc, char *argv[]);
int print_all_args(int argc, char *argv[]);
int multiply_args(int argc, char *argv[]);
int add_positive_numbers(int argc, char *argv[]);

#endif /* MAIN_H */
