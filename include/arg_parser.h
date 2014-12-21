#ifndef COMMON_ARG_PARSER_H
#define COMMON_ARG_PARSER_H

struct arg {
  const char *lng;
  char shrt;
  const char *help_txt;

  int has_arg :1;
};

#define ARG_PARSER_EXTRA -4
#define ARG_PARSER_LNG -3
#define ARG_PARSER_ERR -2
#define ARG_PARSER_DONE -1

int arg_parser(int parser_argc, char **parser_argv, const struct arg *args);
void display_help_text(const char *prog, const char *usage, const char *desc, const struct arg *args);

extern const void *argarg;

#endif
