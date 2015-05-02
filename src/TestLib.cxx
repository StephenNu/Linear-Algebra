#include "TestLib.h"

/**
  Always returns true
*/
bool do_i_work() {
  return true;
}

bool do_i_not_work() {
  return false;
}

class foo {

  public:
    /**
      doing a bar to k nicely
    */
    void dobar(int k) {
      k += 2;
    }
};
