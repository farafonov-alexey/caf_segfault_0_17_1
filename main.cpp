#include "caf/all.hpp"
using namespace caf;

int main() {
  caf::actor_system_config cfg;
  caf::actor_system system(cfg);
  return 0;
}