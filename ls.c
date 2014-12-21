// ls - list files and directories inside a directory

#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

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

  if (argc == 1) {
    return 1;
  }

  while (--argc > 0) {
    DIR *directory = opendir(*++argv);

    if (directory == NULL) {
      fprintf(stderr, "*** ls: %s cannot be opened\n", *argv);
      return 1;
    }

    list_items(directory, show_all);
    printf("\n");
  }
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

