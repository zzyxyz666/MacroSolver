#include <filesystem>
#include <iostream>

#include "solve_macro.h"
using namespace lhy;

int main(int argc, const char **argv) {
  if (argc != 2) {
    std::cout << "need <input> file path" << '\n';
    return 0;
  }

  std::filesystem::path fpath = std::filesystem::path(argv[1]);
  macro_solver.SolveMacroWithFile(fpath);
  return 0;
}