// ls - list files and directories inside a directory

#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "arg_parser.h"

#define DIRMAX 200

static const char *usage_str = "[Flags] [Files]";
static const char *desc_str  = "Files: List of files to provide information on.\n"
                               "       An empty list means all files in the current directory\n";

#define XARGS \
  X(all, "all", 0, 'a', "Do not ignore entries starting with '.'") \
  X(lng, NULL,  0, 'l', "Use a long listing format") \
  X(help, "help", 0, 'h', "Display help") \
  X(last, NULL, 0, '\0', NULL)

enum arg_index {
  ARG_EXTRA = ARG_PARSER_EXTRA,
  ARG_LNG = ARG_PARSER_LNG,
  ARG_ERR = ARG_PARSER_ERR,
  ARG_DONE = ARG_PARSER_DONE,
#define X(enu, id, arg, op, help_text) ARG_##enu,
  XARGS
#undef X
};

static const struct arg ls_args[] = {
#define X(enu, id, arg, op, help_text) [ARG_##enu] = { .lng = id, .shrt = op, .help_txt = help_text, .has_arg = arg },
  XARGS
#undef X
};

void list_items(DIR *directory, bool show_all);

int main(int argc, char **argv) {
  bool show_all = false;
  int dirs = 0, i;
  const char *dirarray[DIRMAX] = { NULL };

  enum arg_index ret;

  while ((ret = arg_parser(argc, argv, ls_args)) != ARG_DONE) {
    switch (ret) {
    case ARG_help:
      display_help_text(argv[0], usage_str, desc_str, ls_args);
      return 0;
    case ARG_all:
      show_all = true;
      break;
    case ARG_EXTRA:
      if (dirs < sizeof(dirarray)) {
          dirarray[dirs++] = argarg;
      } else {
          fprintf(stderr, "%s: To many directories given to ls\n", argv[0]);
          return 1;
      }
      break;
    default:
      return 0;
    }
  }

  if (dirs == 0)
      dirarray[dirs++] = "./";

  for (i = 0; i < dirs; i++) {
    DIR *directory = opendir(dirarray[i]);

    if (directory == NULL) {
      perror(*argv);
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

