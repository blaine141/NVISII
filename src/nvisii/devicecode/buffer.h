#pragma once
#include <owl/owl.h>
#include <owl/owl_device_buffer.h>

// doesn't seem to have a significant impact on framerate
#define CHECK_ACCESSES 

template<class T>
class Buffer : public owl::device::Buffer
{
  public:
  __both__
  inline T get(size_t address, uint32_t line) {
    #if defined(__CUDACC__)
    #ifdef CHECK_ACCESSES
    if (data == nullptr) {::printf("Device Side Error on Line %d: buffer was nullptr.\n", line); asm("trap;");}
    if (address >= count) {::printf("Device Side Error on Line %d: out of bounds access (address: %d, size %d).\n", line, uint32_t(address), uint32_t(count)); asm("trap;");}
    #endif
    #endif
    return ((T*)data)[address];
  }

  __both__
  inline T* getPtr(size_t address, uint32_t line) {
    #if defined(__CUDACC__)
    #ifdef CHECK_ACCESSES
    if (data == nullptr) {::printf("Device Side Error on Line %d: buffer was nullptr.\n", line); asm("trap;");}
    if (address >= count) {::printf("Device Side Error on Line %d: out of bounds access (address: %d, size %d).\n", line, uint32_t(address), uint32_t(count)); asm("trap;");}
    #endif
    #endif
    return &((T*)data)[address];
  }
};

#define GET(RETURN, TYPE, BUFFER, ADDRESS) \
if (BUFFER.data == nullptr) {::printf("Device Side Error on Line %d: buffer was nullptr.\n", __LINE__); asm("trap;");} \
if (ADDRESS >= BUFFER.count) {::printf("Device Side Error on Line %d: out of bounds access (address: %d, size %d).\n", __LINE__, ADDRESS, uint32_t(BUFFER.count)); asm("trap;");} \
RETURN = ((TYPE*)BUFFER.data)[ADDRESS];\
