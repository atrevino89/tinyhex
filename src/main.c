#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: ./tinyhex <file>\n");
    return EXIT_FAILURE;
  }

  printf("%s\n", argv[1]);
  return EXIT_SUCCESS;
}

