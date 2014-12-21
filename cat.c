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
        fprintf(stderr, "*** cat: %s cannot be opened\n", *argv);
        return 1;
      }

      output_file(read_file, stdout);
      fclose(read_file);
    } // end while
  } // end else

}

void output_file(FILE *in, FILE *out) {
  int chr;
  while ( (chr = getc(in) ) != EOF ) {
    putc(chr, out);
  }
}

