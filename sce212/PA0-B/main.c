#include "utils.h"
#include "dir_file.h"

int main(int argc, char **argv) {	
	char buff[MAX_BUFFER_SIZE];
	int num_token;
	char **token_list, *dir_fname, *file_fname;
	directory_t *dir, *root_dir;
	FILE *file_input, *dir_input;

	if (argc != 3) {
		fprintf(stderr, "Usage: pa0_b <file_input file> <dir_input file>\n");
		exit(1);
	}

	file_fname = argv[1];
	dir_fname = argv[2];

	open_file(file_fname, &file_input);
	open_file(dir_fname, &dir_input);

	root_dir = create_dir("root");
	
	// Parse the string written in file_input and create a hierarchical structure of directories and files.
	while (fgets(buff, MAX_BUFFER_SIZE, file_input) != NULL) {
		token_list = NULL;
		num_token = 0;

		num_token = parse_str_to_list(buff, &token_list);

		make_dir_and_file(root_dir, token_list, num_token);

		free_token_list(token_list, num_token);
	}

	// Find the location of directory written in dir_input and print the file in it.
	while (fgets(buff, MAX_BUFFER_SIZE, dir_input) != NULL) {	
		token_list = NULL;
		dir = NULL;
		num_token = 0;

		num_token = parse_str_to_list(buff, &token_list);

		dir = find_target_dir(root_dir, token_list, num_token);

		if (dir == NULL) {
			free_token_list(token_list, num_token);
			continue;
		}

		print_file_on_dir(dir);
		
		free_token_list(token_list, num_token);
	}

	free_dir_and_file(root_dir);

	fclose(file_input);
	fclose(dir_input);

	return 0;	
}

