// cat - read and output files

#include <stdio.h>

#include "constants.h"

void output_file(FILE *in, FILE *out);

int main(int argc, char **argv) {

  if (argc == 1) {
    output_file(stdin, stdout);
  } else {
    FILE *read_file;
    while (--argc > 0) {
      read_file = fopen(*++argv, "r");

      if (read_file == NULL) {
        perror(*argv);
        return 1;
      }

      output_file(read_file, stdout);
      fclose(read_file);
    } // end while
  } // end else

}

void output_file(FILE *in, FILE *out) {
  static char buffer[MAX_SIZE];

  size_t size; // Number of bytes read by fread()
  while ( (size = fread(buffer, 1, MAX_SIZE, in) ) != 0) {
    fwrite(buffer, 1, size, out);
  }
}

