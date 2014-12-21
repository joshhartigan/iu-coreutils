// cat - read and output files

#include <stdio.h>

void output_file(FILE *in, FILE *out);

int main(int argc, char **argv) {

  if (argc == 1) {
    output_file(stdin, stdout);
  } else {
    FILE *read;
    while (--argc > 0) {
      read = fopen(*++argv, "r");

      if (read == NULL) {
        printf("*** cat: %s cannot be opened\n", *argv);
        return 1;
      }

      output_file(read, stdout);
      fclose(read);
    } // end while
  } // end else

}

void output_file(FILE *in, FILE *out) {
  static const size_t BUFFER_SZ = 1024;
  static char buffer[BUFFER_SZ];
  
  size_t sz; // Number of bytes read by fread()
  while ((sz = fread(buffer, 1, BUFFER_SZ, in)) != 0) {
    fwrite(buffer, 1, BUFFER_SZ, out);
  }
}

