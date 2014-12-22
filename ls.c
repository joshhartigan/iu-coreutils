// ls - list files and directories inside a directory

#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "constants.h"

void list_items(DIR *directory, bool show_all);

int main(int argc, char **argv) {
  bool show_all = false;

  // if the `-a` flag is given, include hidden files.
  int c = getopt(argc, argv, "a");
  if (c == 'a') {
    argc--; // obviously we should ignore the flag as an argument
    argv++;
    show_all = true;
  }

  if (argc == 1) { // no arguments? - use the current directory
    char current_dir[MAX_SIZE];
    getcwd( current_dir, sizeof(current_dir) );

    DIR *directory = opendir(current_dir);

    list_items(directory, show_all);
  }

  while (--argc > 0) {
    DIR *directory = opendir(*++argv);

    if (directory == NULL) {
      perror(*argv);
      return 1;
    }

    list_items(directory, show_all);
  }

  printf("\n");
}

void list_items(DIR *directory, bool show_all) {
  struct dirent *item;

  while ( (item = readdir(directory)) ) {
    char *item_name = item -> d_name;

    if ( item_name[0] == '.' && show_all ) {
      printf("%s  ", item_name);
    } else if ( item_name[0] != '.' ) {
      printf("%s  ", item_name);
    }
  }
}

