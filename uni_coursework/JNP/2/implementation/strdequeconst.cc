#include "strdequeconst.h"
#include <iostream>
#define EMPTY_ID 0

namespace jnp1{

  unsigned long emptystrdeque() {
    #ifdef NDEBUG
      std::cerr << "emptystrdeque()\n";
    #endif
    return EMPTY_ID;
  }

}
