// lnum - prepend line numbers to the given input (stdin by default)
//      - intended to be used as a filter.

#include <stdio.h>

void line_number(FILE *in);

int main(int argc, char **argv) {

  if (argc == 1) {
    line_number(stdin);
  } else {
    FILE *read = fopen( argv[1], "r" );
    if (read == NULL) { printf( "*** lnum: %s cannot be opened\n", argv[1] ); }
    else { line_number(read); }
  }

}

void line_number(FILE *in) {
  int chr;
  int lines;
  while ( (chr = getc(in) ) != EOF ) {
    if (chr == '\n') {
      lines++;
    }
    putc(chr, stdout);
  }
}

