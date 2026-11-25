#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: ./tinyhex <file>\n");
    return EXIT_FAILURE;
  }

  char *fn = argv[1];
  FILE *file = fopen(fn, "rb");

  if (file == NULL) {
    fprintf(stderr, "file opening error\n");
    return EXIT_FAILURE;
  }

  unsigned char buffer[8];

  size_t bytes_read = -1;
  while (bytes_read > 1) {
    bytes_read = fread(buffer, 1, sizeof(buffer), file);
    if (bytes_read == 0) {
      fclose(file);
      return EXIT_SUCCESS;
    }
    printf("Read %zu bytes\n", bytes_read);
  }
  
  return EXIT_SUCCESS;

}

