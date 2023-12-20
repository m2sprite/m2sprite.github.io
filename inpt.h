#ifndef INPT_H_
#define INPT_H_

#include <stdlib.h>

typedef struct {
  size_t size;
  char*  buffer;
}Input;

Input input_alloc(const char *filename);
#endif

#ifdef INPT_IMPLEMENTATION

Input input_alloc(const char *filename){
  Input input;
  FILE *file;

  file = fopen(filename, "rb");

  if(file == NULL)
  {
    printf("Error opening file\n");
  }

  fseek(file,0,SEEK_END);
  long int file_size = ftell(file);
  rewind(file);

  size_t to_alloc = file_size / sizeof(char);
  printf("read size: %ld bytes %ld bits %ld chars \n", file_size, file_size*8, to_alloc);

  input.buffer = (char *)malloc(to_alloc);

  if(input.buffer == NULL) {
    perror("error allocating buffer");
    fclose(file);
  }

  input.size = to_alloc;

  fread(input.buffer, 1, to_alloc, file);
  fclose(file);

  //print_buffer(input.buffer);
  return input;
}

#endif//INPT_IMPLEMENTATION
