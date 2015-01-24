// cat - read and output files

#include <stdio.h>

#include "constants.h"

void output_file(FILE *in, FILE *out);

int main(int argc, char **argv) {
  int arg_count = argc;
  char **arguments = argv;

  if (arg_count == 1) {
    output_file(stdin, stdout);
    return 0;
  }

  FILE *read_file;
  while (--arg_count > 0) {
    read_file = fopen(*++arguments, "r");

    if (read_file == NULL) {
      perror(*arguments);
      return 1;
    }

    output_file(read_file, stdout);
    fclose(read_file);
  } // end while

}

void output_file(FILE *in, FILE *out) {
  static char buffer[MAX_SIZE];

  size_t size; // Number of bytes read by fread()
  while ( (size = fread(buffer, 1, MAX_SIZE, in) ) != 0) {
    fwrite(buffer, 1, size, out);
  }
}
