#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_TOKEN_NUM 256
#define MAX_BUFFER_SIZE 1024
#define DELIM "/\n"

void open_file(char* fname, FILE** input);

// Return number of token
int parse_str_to_list(const char* str, char*** token_list);

void free_token_list(char** token_list, int num_token);

#endif
