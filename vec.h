#ifndef VEC_H_
#define VEC_H_

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#ifndef VEC_MALLOC
#include <stdlib.h>
#define VEC_MALLOC malloc
#endif

#ifndef VEC_ASSERT
#include <assert.h>
#define VEC_ASSERT assert
#endif

typedef struct
{
  size_t held;
  size_t size;
  double *elements;
} double_vec;

typedef struct
{
  size_t held;
  size_t size;
  float *elements;
} float_vec;

typedef struct
{
  size_t held;
  size_t size;
  int8_t *elements;
} int8_vec;

typedef struct
{
  size_t held;
  size_t size;
  int16_t *elements;
} int16_vec;

typedef struct
{
  size_t held;
  size_t size;
  int32_t *elements;
} int32_vec;

typedef struct
{
  size_t held;
  size_t size;
  int64_t *elements;
} int64_vec;

typedef struct
{
  size_t held;
  size_t size;
  uint8_t *elements;
} uint8_vec;

typedef struct
{
  size_t held;
  size_t size;
  uint16_t *elements;
} uint16_vec;

typedef struct
{
  size_t held;
  size_t size;
  uint32_t *elements;
} uint32_vec;

typedef struct
{
  size_t held;
  size_t size;
  uint64_t *elements;
} uint64_vec;

double_vec   double_vec_alloc(size_t s);
float_vec    float_vec_alloc(size_t s);
int8_vec     int8_vec_alloc(size_t s);
int16_vec    int16_vec_alloc(size_t s);
int32_vec    int32_vec_alloc(size_t s);
int64_vec    int64_vec_alloc(size_t s);
uint8_vec    uint8_vec_alloc(size_t s);
uint16_vec   uint16_vec_alloc(size_t s);
uint32_vec   uint32_vec_alloc(size_t s);
uint64_vec   uint64_vec_alloc(size_t s);

void double_vec_resize(double_vec *v, size_t new_size);
void float_vec_resize(float_vec *v, size_t new_size);
void int8_vec_resize(int8_vec *v, size_t new_size);
void int16_vec_resize(int16_vec *v, size_t new_size);
void int32_vec_resize(int32_vec *v, size_t new_size);
void int64_vec_resize(int64_vec *v, size_t new_size);
void uint8_vec_resize(uint8_vec *v, size_t new_size);
void uint16_vec_resize(uint16_vec *v, size_t new_size);
void uint32_vec_resize(uint32_vec *v, size_t new_size);
void uint64_vec_resize(uint64_vec *v, size_t new_size);

void double_vec_print(double_vec v);
void float_vec_print(float_vec v);
void int8_vec_print(int8_vec v);
void int16_vec_print(int16_vec v);
void int32_vec_print(int32_vec v);
void int64_vec_print(int64_vec v);
void uint8_vec_print(uint8_vec v);
void uint16_vec_print(uint16_vec v);
void uint32_vec_print(uint32_vec v);
void uint64_vec_print(uint64_vec v);

void double_vec_push_times_2_realloc(double_vec *v, double value);
void float_vec_push_times_2_realloc(float_vec *v, float value);
void int8_vec_push_times_2_realloc(int8_vec *v, int8_t value);
void int16_vec_push_times_2_realloc(int16_vec *v, int16_t value);
void int32_vec_push_times_2_realloc(int32_vec *v, int32_t value);
void int64_vec_push_times_2_realloc(int64_vec *v, int64_t value);
void uint8_vec_push_times_2_realloc(uint8_vec *v, uint8_t value);
void uint16_vec_push_times_2_realloc(uint16_vec *v, uint16_t value);
void uint32_vec_push_times_2_realloc(uint32_vec *v, uint32_t value);
void uint64_vec_push_times_2_realloc(uint64_vec *v, uint64_t value);

void double_vec_fill_zero(double_vec *v);
void float_vec_fill_zero(float_vec *v);
void int8_vec_fill_zero(int8_vec *v);
void int16_vec_fill_zero(int16_vec *v);
void int32_vec_fill_zero(int32_vec *v);
void int64_vec_fill_zero(int64_vec *v);
void uint8_vec_fill_zero(uint8_vec *v);
void uint16_vec_fill_zero(uint16_vec *v);
void uint32_vec_fill_zero(uint32_vec *v);
void uint64_vec_fill_zero(uint64_vec *v);
#endif // VEC_H

#ifdef VEC_IMPLEMENTATION

//MALLOCS
double_vec double_vec_alloc(size_t size){
  double_vec return_this;
  return_this.size = size;
  return_this.held = 0;
  return_this.elements = malloc(sizeof(*return_this.elements)*size);
  VEC_ASSERT(return_this.elements != NULL);
  return return_this;
}

float_vec float_vec_alloc(size_t size){
  float_vec return_this;
  return_this.size = size;
  return_this.held = 0;
  return_this.elements = malloc(sizeof(*return_this.elements)*size);
  VEC_ASSERT(return_this.elements != NULL);
  return return_this;
}

int8_vec int8_vec_alloc(size_t size){
  int8_vec return_this;
  return_this.size = size;
  return_this.held = 0;
  return_this.elements = malloc(sizeof(*return_this.elements)*size);
  VEC_ASSERT(return_this.elements != NULL);
  return return_this;
}

int16_vec int16_vec_alloc(size_t size){
  int16_vec return_this;
  return_this.size = size;
  return_this.held = 0;
  return_this.elements = malloc(sizeof(*return_this.elements)*size);
  VEC_ASSERT(return_this.elements != NULL);
  return return_this;
}

int32_vec int32_vec_alloc(size_t size){
  int32_vec return_this;
  return_this.size = size;
  return_this.held = 0;
  return_this.elements = malloc(sizeof(*return_this.elements)*size);
  VEC_ASSERT(return_this.elements != NULL);
  return return_this;
}

int64_vec int64_vec_alloc(size_t size){
  int64_vec return_this;
  return_this.size = size;
  return_this.held = 0;
  return_this.elements = malloc(sizeof(*return_this.elements)*size);
  VEC_ASSERT(return_this.elements != NULL);
  return return_this;
}

uint8_vec uint8_vec_alloc(size_t size){
  uint8_vec return_this;
  return_this.size = size;
  return_this.held = 0;
  return_this.elements = malloc(sizeof(*return_this.elements)*size);
  VEC_ASSERT(return_this.elements != NULL);
  return return_this;
}

uint16_vec uint16_vec_alloc(size_t size){
  uint16_vec return_this;
  return_this.size = size;
  return_this.held = 0;
  return_this.elements = malloc(sizeof(*return_this.elements)*size);
  VEC_ASSERT(return_this.elements != NULL);
  return return_this;
}

uint32_vec uint32_vec_alloc(size_t size){
  uint32_vec return_this;
  return_this.size = size;
  return_this.held = 0;
  return_this.elements = malloc(sizeof(*return_this.elements)*size);
  VEC_ASSERT(return_this.elements != NULL);

  return return_this;
}

uint64_vec uint64_vec_alloc(size_t size){
  uint64_vec return_this;
  return_this.size = size;
  return_this.held = 0;
  return_this.elements = malloc(sizeof(*return_this.elements)*size);
  VEC_ASSERT(return_this.elements != NULL);
  return return_this;
}

//RESIZE
void double_vec_resize(double_vec *v, size_t new_size){
  v->elements = realloc(v->elements, sizeof(double)*new_size);
  v->size = new_size;
}

void float_vec_resize(float_vec *v, size_t new_size){
  v->elements = realloc(v->elements, sizeof(float)*new_size);
  v->size = new_size;
}

void int8_vec_resize(int8_vec *v, size_t new_size){
  v->elements = realloc(v->elements, sizeof(int8_t)*new_size);
  v->size = new_size;
}

void int16_vec_resize(int16_vec *v, size_t new_size){
  v->elements = realloc(v->elements, sizeof(int16_t)*new_size);
  v->size = new_size;
}

void int32_vec_resize(int32_vec *v, size_t new_size){
  v->elements = realloc(v->elements, sizeof(int32_t)*new_size);
  v->size = new_size;
}

void int64_vec_resize(int64_vec *v, size_t new_size){
  v->elements = realloc(v->elements, sizeof(int64_t)*new_size);
  v->size = new_size;
}

void uint8_vec_resize(uint8_vec *v, size_t new_size){
  v->elements = realloc(v->elements, sizeof(uint8_t)*new_size);
  v->size = new_size;
}

void uint16_vec_resize(uint16_vec *v, size_t new_size){
  v->elements = realloc(v->elements, sizeof(uint16_t)*new_size);
  v->size = new_size;
}

void uint32_vec_resize(uint32_vec *v, size_t new_size){
  v->elements = realloc(v->elements, sizeof(uint32_t)*new_size);
  v->size = new_size;
}

void uint64_vec_resize(uint64_vec *v, size_t new_size){
  v->elements = realloc(v->elements, sizeof(uint64_t)*new_size);
  v->size = new_size;
}

//PUSH
void double_vec_push_times_2_realloc(double_vec *v, double value){
  if(v->held+1 > v->size){
    double_vec_resize(v, v->size*2);
  }
  v->elements[v->held] = value;
  v->held++;
}

void float_vec_push_times_2_realloc(float_vec *v, float value){
  if(v->held+1 > v->size){
    float_vec_resize(v, v->size*2);
  }
  v->elements[v->held] = value;
  v->held++;
}

void int8_vec_push_times_2_realloc(int8_vec *v, int8_t value){
  if(v->held+1 > v->size){
    int8_vec_resize(v, v->size*2);
  }
  v->elements[v->held] = value;
  v->held++;
}

void int16_vec_push_times_2_realloc(int16_vec *v, int16_t value){
  if(v->held+1 > v->size){
    int16_vec_resize(v, v->size*2);
  }
  v->elements[v->held] = value;
  v->held++;
}

void int32_vec_push_times_2_realloc(int32_vec *v, int32_t value){
  if(v->held+1 > v->size){
    int32_vec_resize(v, v->size*2);
  }
  v->elements[v->held] = value;
  v->held++;
}

void int64_vec_push_times_2_realloc(int64_vec *v, int64_t value){
  if(v->held+1 > v->size){
    int64_vec_resize(v, v->size*2);
  }
  v->elements[v->held] = value;
  v->held++;
}

void uint8_vec_push_times_2_realloc(uint8_vec *v, uint8_t value){
  if(v->held+1 > v->size){
    uint8_vec_resize(v, v->size*2);
  }
  v->elements[v->held] = value;
  v->held++;
}

void uint16_vec_push_times_2_realloc(uint16_vec *v, uint16_t value){
  if(v->held+1 > v->size){
    uint16_vec_resize(v, v->size*2);
  }
  v->elements[v->held] = value;
  v->held++;
}

void uint32_vec_push_times_2_realloc(uint32_vec *v, uint32_t value){
  if(v->held+1 > v->size){
    uint32_vec_resize(v, v->size*2);
  }
  v->elements[v->held] = value;
  v->held++;
}

void uint64_vec_push_times_2_realloc(uint64_vec *v, uint64_t value){
  if(v->held+1 > v->size){
    uint64_vec_resize(v, v->size*2);
  }
  v->elements[v->held] = value;
  v->held++;
}

//ZERO
void double_vec_fill_zero(double_vec *v){
  for(size_t i = 0; i < v->size; ++i){
    v->elements[i] = 0;
  }
  v->held = 0;
}

void float_vec_fill_zero(float_vec *v){
  for(size_t i = 0; i < v->size; ++i){
    v->elements[i] = 0;
  }
  v->held = 0;
}

void int64_vec_fill_zero(int64_vec *v){
  for(size_t i = 0; i < v->size; ++i){
    v->elements[i] = 0;
  }
  v->held = 0;
}

void int32_vec_fill_zero(int32_vec *v){
  for(size_t i = 0; i < v->size; ++i){
    v->elements[i] = 0;
  }
  v->held = 0;
}

void int16_vec_fill_zero(int16_vec *v){
  for(size_t i = 0; i < v->size; ++i){
    v->elements[i] = 0;
  }
  v->held = 0;
}

void int8_vec_fill_zero(int8_vec *v){
  for(size_t i = 0; i < v->size; ++i){
    v->elements[i] = 0;
  }
  v->held = 0;
}

void uint64_vec_fill_zero(uint64_vec *v){
  for(size_t i = 0; i < v->size; ++i){
    v->elements[i] = 0;
  }
  v->held = 0;
}

void uint32_vec_fill_zero(uint32_vec *v){
  for(size_t i = 0; i < v->size; ++i){
    v->elements[i] = 0;
  }
  v->held = 0;
}

void uint16_vec_fill_zero(uint16_vec *v){
  for(size_t i = 0; i < v->size; ++i){
    v->elements[i] = 0;
  }
  v->held = 0;
}

void uint8_vec_fill_zero(uint8_vec *v){
  for(size_t i = 0; i < v->size; ++i){
    v->elements[i] = 0;
  }
  v->held = 0;
}



//PRINT
void double_vec_print(double_vec v){
  for(size_t i = 0; i < v.held; ++i){
    printf(" %f ", v.elements[i]);
  }
  printf("\n");
}

void float_vec_print(float_vec v){
  for(size_t i = 0; i < v.held; ++i){
    printf(" %f ", v.elements[i]);
  }
  printf("\n");
}

void int8_vec_print(int8_vec v){
  for(size_t i = 0; i < v.held; ++i){
    printf(" %" PRId8 " ", v.elements[i]);
  }
  printf("\n");
}

void int16_vec_print(int16_vec v){
  for(size_t i = 0; i < v.held; ++i){
    printf(" %" PRId16 " ", v.elements[i]);
  }
  printf("\n");
}

void int32_vec_print(int32_vec v){
  for(size_t i = 0; i < v.held; ++i){
    printf(" %" PRId32 " ", v.elements[i]);
  }
  printf("\n");
}

void int64_vec_print(int64_vec v){
  for(size_t i = 0; i < v.held; ++i){
    printf(" %" PRId64 " ", v.elements[i]);
  }
  printf("\n");
}

void uint8_vec_print(uint8_vec v){
  for(size_t i = 0; i < v.held; ++i){
    printf(" %" PRIu8 " ", v.elements[i]);
  }
  printf("\n");
}

void uint16_vec_print(uint16_vec v){
  for(size_t i = 0; i < v.held; ++i){
    printf(" %" PRIu16 " ", v.elements[i]);
  }
  printf("\n");
}

void uint32_vec_print(uint32_vec v){
  for(size_t i = 0; i < v.held; ++i){
    printf(" %" PRIu32 " ", v.elements[i]);
  }
  printf("\n");
}

void uint64_vec_print(uint64_vec v){
  for(size_t i = 0; i < v.held; ++i){
    printf(" %" PRIu64 " ", v.elements[i]);
  }
  printf("\n");
}

#endif // VEC_IMPLEMENTATION
