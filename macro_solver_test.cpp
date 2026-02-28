//
// Created by 连昊宇 on 25-3-12.
//
#include <filesystem>

#include "solve_macro.h"
using namespace lhy;
int main() {
  for (int i = 1; i <= 9; i++) {
    std::filesystem::path fpath =
        std::filesystem::path(__FILE__).parent_path() / "tests" / ("define_list" + std::to_string(i) + ".txt");
    macro_solver.SolveMacroWithFile(fpath);
  }
}
