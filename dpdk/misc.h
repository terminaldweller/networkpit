
#ifndef MISC_H
#define MISC_H

#include <stdio.h>
#include <unistd.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define BLACK "\033[1;30m"
#define BROWN "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define GRAY "\033[1;37m"
#define DARKGRAY "\033[1;30m"
#define YELLOW "\033[1;33m"
#define NORMAL "\033[0m"
#define CLEAR	"\033[2J"

#if 0
#define  PRINT_WITH_COLOR(X, ...) \
  do{\
    if (isatty(fileno(stdout))) {\
      printf(X "%s", __VA_ARGS__);\
      } else {\
      printf(__VA_ARGS__);\
      }\
  }while(0)
#endif

#define PRINT_WITH_COLOR_LB(X,Y, ...) \
  do{\
    if (isatty(fileno(stdout))) {\
      printf(__func__);\
      printf(" : ");\
      printf(X Y, ##__VA_ARGS__);\
      printf(NORMAL);\
      printf("\n");\
      } else {\
        printf (Y, ##__VA_ARGS__);\
        printf("\n");\
      }\
  }while(0)
#endif
