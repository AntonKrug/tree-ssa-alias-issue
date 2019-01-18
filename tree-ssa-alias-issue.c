#include <stdint.h>

//When LOOP_ITERATIONS is defined to 6 or more it will cause internal compiler error
#ifndef LOOP_ITERATIONS
#define LOOP_ITERATIONS 6
#endif

typedef union {
 uint32_t value;
} TypeA;

typedef struct {
  TypeA fieldA[16];
} TypeB;

void innerCall(uint32_t* inputArray) {
  TypeB* bPointer = (TypeB*) 0x10000000;
  for(uint32_t idx = 0; idx < LOOP_ITERATIONS; ++idx) {
    bPointer->fieldA[0].value = inputArray[idx];
  }
}

int main(int argc, const char* argv[]) {
  uint32_t inputArray[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  innerCall(inputArray);
  return(0);
}
