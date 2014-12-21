// cat - read and output files

#include <stdio.h>

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

#define BUFFER_SZ 1024

void output_file(FILE *in, FILE *out) {
  static char buffer[BUFFER_SZ];

  size_t sz; // Number of bytes read by fread()
  while ((sz = fread(buffer, 1, BUFFER_SZ, in)) != 0) {
    fwrite(buffer, 1, sz, out);
  }
}

