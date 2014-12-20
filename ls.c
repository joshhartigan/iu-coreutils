// ls - list files and directories inside a directory

#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

void list_items(DIR *directory, bool show_all);

int main(int argc, char **argv) {
  int first_argument_index = 1;
  bool show_all = false;

  if ( getopt(argc, argv, "a") != -1 ) {
    argc--;
    first_argument_index = 2;
    show_all = true;
  }

  DIR *directory = opendir( argv[first_argument_index] );

  if (argc == 1) {
    return 1;
  }

  if (directory == NULL) {
    printf( "*** ls: %s cannot be opened\n", argv[first_argument_index] );
    return 1;
  }

  list_items(directory, show_all);
  printf("\n");
}

void list_items(DIR *directory, bool show_all) {
  struct dirent *item;

  while ( (item = readdir(directory)) ) {
    char *item_name = item -> d_name;

    if ( item_name[0] == '.' && show_all ) {
      printf("%s\t", item_name);
    } else if ( item_name[0] != '.' ) {
      printf("%s\t", item_name);
    }
  }
}

