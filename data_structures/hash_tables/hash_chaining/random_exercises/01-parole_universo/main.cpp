/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test sulle stringhe
 * @version 1.0
 * @date 2024-01-29
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "header.cpp"
#include <vector>

int main() {

  std::vector<std::string> words = {"MARTE",   "LUNA", "COMETA",
                                    "PIANETI", "SOLE", "SOLI"};

  T tab = new hash_table();

  for (int i = 0; i < words.size(); i++) {
    insert(tab, new my_elem(words.at(i), nullptr, nullptr));
    print_hash_table(tab);
  }
}