#ifndef LS_H
#define LS_H 

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdbool.h>

char* get_dir_entry(DIR* curr_dir);

const char* get_entry_ext(const char *filename);

void ls();

#endif 