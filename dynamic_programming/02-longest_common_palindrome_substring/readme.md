## Seconda prova intermedia 06/06/2022 (esercizio I)

Scrivere un algoritmo per individuare, all’interno di una stringa x1 . . . xn la lunghezza massima di una sottostringa (di caratteri consecutivi) palindroma. Ad esempio, nella stringa colonna la sottostringa palindroma di lunghezza massima è olo, dunque la lunghezza massima è 3. Più precisamente:

1. dare una caratterizzazione ricorsiva della lunghezza massima lung[i, j] di una sottostringa palindroma di xi ...xj;
2. tradurre tale definizione in un algoritmo di programmazione dinamica con il metodo top-down che determina la lunghezza massima;
3. valutare e giustificare la complessità dell’algoritmo.

### Idea

Confronto della stringa con se stessa nella tabella lung (n x n). Se la stringa è vuota la lunghezza sarà zero, se l'indice i è uguale all'indice j, sono sulla diagonale e sto confrontando la sotto stringa di un carattere che, sicuramente è palindroma e ha lunghezza 1. Altrimenti se trovo due caratteri esterni uguali, vado in ricorsione controllando se la sotto stringa è palindroma. Se lo è incremento il valore in lung[i, j] della lunghezza della sottostringa (j-i-1) più 2(i caratteri esterni). Poi mi tengo memorizzato la lunghezza massima guardando nelle porzioni [i+1, j] e [i, j-1].

### Caratterizzazione ricorsiva di lung[i, j]

lung[i, j] =

- 1 se i == j
- 2+(j-i-1) se se i != j and x<sub>i</sub> == x<sub>j</sub> AND lung[i+1, j-1] == (j-i-1)
- max{lung[i+1, j], lung[i, j-1]} altrimenti

### Codice c++

```c++

int lcpsubs_top_down_AUX(std::string X, std::vector<std::vector<int>> &lung, int i, int j) {
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
}
```

### Analisi complessità

L'inizializzazione della matrice lung porta via un tempo pari ad (n\*n). Il numero di chiamate ricorsive è al più O(n \* n), tanti quanti sono i possibili sottoproblemi.

In particolare, l'approccio top down risulta ottimo, rispetto al bottom up, nel caso in cui l'intera stringa di input sia palindroma. Infatti vengono effettuate solamente O(n) chiamate!

```
Esempio!
aliila
6
-1 -1 -1 -1 -1 6
-1 -1 -1 -1 4 -1
-1 -1 -1 2 -1 -1
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1
```

### Consigli

Inizializzare sempre con -1 (anche se qua anche zero avrebbe funzionato in quanto non può esserci una stringa palindroma lunga zero). 

La cosa importante è la caratterizzazione ricorsiva del problema!

### Test case

stringa, lunghezza massima sotto stringa palindroma e tabella lung

```
colonna
3
1 1 1 3 3 3 3
-1 1 1 3 3 3 3
-1 -1 1 1 1 2 2
-1 -1 -1 1 1 2 2
-1 -1 -1 -1 1 2 2
-1 -1 -1 -1 -1 1 1
-1 -1 -1 -1 -1 -1 1


ciao
1
1 1 1 1
-1 1 1 1
-1 -1 1 1
-1 -1 -1 1


aalpaa
2
-1 2 2 2 2 2
-1 1 1 1 1 2
-1 -1 1 1 1 2
-1 -1 -1 1 1 2
-1 -1 -1 -1 1 2
-1 -1 -1 -1 -1 -1


nitiikiigi
5
1 1 1 3 3 3 3 5 5 5
-1 1 1 3 3 3 3 5 5 5
-1 -1 1 1 2 2 3 5 5 5
-1 -1 -1 1 2 2 3 5 5 5
-1 -1 -1 -1 1 1 3 3 3 3
-1 -1 -1 -1 -1 1 1 2 2 3
-1 -1 -1 -1 -1 -1 1 2 2 3
-1 -1 -1 -1 -1 -1 -1 1 1 3
-1 -1 -1 -1 -1 -1 -1 -1 1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1


iiivfghiilp
3
-1 -1 3 3 3 3 3 3 3 3 3
-1 1 2 2 2 2 2 2 2 2 2
-1 -1 1 1 1 1 1 1 2 2 2
-1 -1 -1 1 1 1 1 1 2 2 2
-1 -1 -1 -1 1 1 1 1 2 2 2
-1 -1 -1 -1 -1 1 1 1 2 2 2
-1 -1 -1 -1 -1 -1 1 1 2 2 2
-1 -1 -1 -1 -1 -1 -1 1 2 2 2
-1 -1 -1 -1 -1 -1 -1 -1 1 1 1
-1 -1 -1 -1 -1 -1 -1 -1 -1 1 1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 1


aliila
6
-1 -1 -1 -1 -1 6
-1 -1 -1 -1 4 -1
-1 -1 -1 2 -1 -1
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1


abba
4
-1 -1 -1 4
-1 -1 2 -1
-1 -1 -1 -1
-1 -1 -1 -1


x
1
1

```
