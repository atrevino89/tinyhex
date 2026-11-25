#include <ctype.h>
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
    perror("file opening error");
    return EXIT_FAILURE;
  }

  unsigned char buffer[8];

  size_t bytes_read;
  size_t offset = 0;
  while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
    printf("%08zx  ", offset);
    for (size_t i = 0; i < bytes_read; i++) {
      printf("%02x ", buffer[i]);
    }

    // fill up with spaces when there are less bytes_read than 8 (bytes)
    for (size_t c = bytes_read; c < sizeof(buffer); c++) {
      printf("   ");
    }
    putchar(' ');
    putchar('|');
    for (size_t i = 0; i < bytes_read; i++) {
      if (!isprint(buffer[i])) {
        putchar('.');
        continue;
      }
      putchar(buffer[i]);
    }
    putchar('|');
    putchar('\n');
    offset += bytes_read;
  }
  int exit_status = EXIT_SUCCESS;
  if (ferror(file)) {
    exit_status = EXIT_FAILURE;
    perror("error on file");
  }

  int err = fclose(file);
  if (err) {
    exit_status = EXIT_FAILURE;
    perror("error closing the file");

  }
  return exit_status;
}
