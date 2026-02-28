#include <fstream>
#include <iostream>

#include "solve_macro.h"
using namespace lhy;
void parse_macro(std::ifstream &file) {
    std::string line;
    std::string final_line;
    while (std::getline(file, line)) {
      if (line[0] == '#' || final_line != "") {
        final_line += line.substr(0, line.size());
        if (line.substr(line.size() - 1, 1) != "\\") {
          macro_solver.AddMacro(final_line);
          final_line = "";
        } else {
          final_line.pop_back();
        }
      } else if (line[0] == '/') {
        continue;
      } else {
        std::cout << macro_solver.SolveOneMacro(line) << std::endl;
        std::cout << std::endl;
      }
    }
    macro_solver.ClearAllMacro();
}

using namespace lhy;
int main(int argc, const char **argv) {
  if (argc != 2) {
    std::cout << "need <input> file path" << std::endl;
    return 0;
  }

  std::ifstream file(argv[1]);
  if (!file.is_open()) {
    std::cout << "file open '" << argv[1] << "' failed" << std::endl;
    return 1;
  }
  parse_macro(file);
  return 0;
}
