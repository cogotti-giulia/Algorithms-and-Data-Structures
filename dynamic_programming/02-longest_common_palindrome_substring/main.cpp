#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int lcpsubs_top_down_AUX(std::string X, std::vector<std::vector<int>> &lung,
                         int i, int j) {
  if (lung[i][j] == -1) { // se non ho ancora calcolato il valore

    if(i > j)
      return 0;

    if (i == j) // un carattere in comune
      lung[i][j] = 1;

    else {
      if (X.at(i) == X.at(j) &&
          (lcpsubs_top_down_AUX(X, lung, i + 1, j - 1) == (j - i - 1))) {
        // se trovo due caratteri uguali
        // controllo la porzione interna, andando in ricorsione (i+1 e j-1)
        // se tutta la stringa interna è palindroma
        // incremento il valore in i j del numero delle
        // lettere che compongono la sotto stringa (il 2 è
        // per le due lettere xi e xj)

        lung.at(i).at(j) = 2 + j - i - 1;

      } else {
        // altrimenti vado alla ricerca delle massime sotto stringhe
        // palindrome decrementando gli indici esterni
        lung.at(i).at(j) = std::max(lcpsubs_top_down_AUX(X, lung, i, j - 1),
                                    lcpsubs_top_down_AUX(X, lung, i + 1, j));
      }
    }
  }
  return lung.at(i).at(j);
}

void lcpsubs_top_down(std::string X) {
  int n = X.size();

  std::vector<std::vector<int>> lung;

  for (int i = 0; i < n; i++) {
    std::vector<int> tmp;
    for (int j = 0; j < n; j++) {
      tmp.push_back(-1);
    }
    lung.push_back(tmp);
  }

  std::cout << lcpsubs_top_down_AUX(X, lung, 0, n - 1);
  std::cout << std::endl;

  for (int r = 0; r < X.size(); r++) {
    for (int c = 0; c < X.size(); c++)
      std::cout << lung.at(r).at(c) << " ";
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  std::vector<std::string> words = {
      "colonna",     "ciao",   "aalpaa", "nitiikiigi",
      "iiivfghiilp", "aliila", "abba",   "x"};

  for (int i = 0; i < words.size(); i++) {
    std::cout << words.at(i) << std::endl;
    lcpsubs_top_down(words.at(i));
    std::cout << std::endl;
  }
}