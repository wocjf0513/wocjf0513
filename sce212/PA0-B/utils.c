#include "dir_file.h"
#include "utils.h"

void open_file(char* fname, FILE** input) {
	assert(fname != NULL);

	if (access(fname, F_OK) == -1) {
		fprintf(stderr, "The '%s' file does not exists\n", fname);
		exit(1);
	}

	*input = fopen(fname, "r");

	if (input == NULL) {
		fprintf(stderr, "The '%s' file did not open\n", fname);
		exit(1);
	}

}

// This parse_str_to_list() split string to the tokens, and put the tokens in token_list.
// The value of return is the number of tokens.

int parse_str_to_list(const char* str, char*** token_list) {
	char delimeter[3] = "/\n\t"; //토큰화 하기 위한 기준
	int tmp = 0; //토큰의 개수
	if (str != NULL) {
		token_list = strtok(str, delimeter);
	}
	while (token_list) {
		tmp++;
		printf("%s\n", token_list);
		token_list = strtok(NULL, delimeter);
	}
	return tmp;
}

void free_token_list(char** token_list, int num_token) {
	int index;

	for (index = 0; index < num_token; index++) {
		free(token_list[index]);
	}

	free(token_list);
}