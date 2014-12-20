// cat - read and output files

#include <stdio.h>

void copy_file(FILE *in, FILE *out);

int main(int argc, char **argv) {

  if (argc == 1) {
    copy_file(stdin, stdout);
  } else {
    FILE *read;
    while (--argc > 0) {
      read = fopen(*++argv, "r");
      if (read == NULL) {
        printf("*** cat: %s cannot be opened\n", *argv);
        return 1;
      } else {
        copy_file(read, stdout);
        fclose(read);
      }
    } // end while
  } // end else

}

void copy_file(FILE *in, FILE *out) {
  int chr;
  while ( (chr = getc(in) ) != EOF ) {
    putc(chr, out);
  }
}

