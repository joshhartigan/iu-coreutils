// lnum - prepend line numbers to the given input (stdin by default)
//      - intended to be used as a filter.

#include <stdio.h>

#include "constants.h"

void show_line_numbers(FILE *in);

int main(int argc, char **argv) {
  int arg_count = argc;
  char **arguments = argv;

  if (arg_count == 1) {
    show_line_numbers(stdin);
  } else {
    FILE *read = fopen( arguments[1], "r" );
    if (read == NULL) {
      perror( arguments[1] );
    }
    else { show_line_numbers(read); }
  }

}

void show_line_numbers(FILE *in) {
  int line_count = 1;
  char line[MAX_LINE_SIZE];

  while ( fgets(line, MAX_LINE_SIZE, in) ) {
    printf("%d\t%s", line_count, line);
    line_count++;
  }
}

