/**
 * @file header.cpp
 * @author cogotti-giulia
 * @brief implementazione metodi e funzioni utilizzate
 * @version 1.1
 * @date 2023-11-29
 */
#include "header.hpp"
#include <iostream>
#include <queue>
#include <unordered_map>

void cancella(pnode u) {
  cancella_aux(u, nullptr); // radice, non ha un padre!
}

void cancella_aux(pnode u, pnode padre) {
  if (u != nullptr) {
    // il nodo corrente è il padre
    cancella_aux(u->left, u);
    cancella_aux(u->right, u);

    if (u->left == nullptr && u->right == nullptr) // è una foglia
      if (padre->left == u && padre->key == u->key)
        // è figlio sinistro con chiave uguale al padre
        padre->left = nullptr;
  }
}

void visita_dfs(pnode u) {
  std::queue<pnode> q;
  q.push(u);

  while (!q.empty()) {
    pnode tmp = q.front();
    q.pop();

    if (tmp != nullptr) {
      std::cout << tmp->key << " ";
      q.push(tmp->left);
      q.push(tmp->right);
    }
  }
}

pnode crea_albero(parr vet_padri) {
  // numero di nodi
  int n = vet_padri->info.size();
  // crea una mappa vuota
  std::unordered_map<int, pnode> map;
  // crea un nuovo nodo per ogni info del padre e la mette nella mappa
  for (int i = 0; i < n; i++) {
    map[i] = new node(vet_padri->info.at(i));
  }
  // radice
  pnode root = nullptr;
  // scorre tutte le celle
  for (int i = 0; i < n; i++) {
    // indice del padre
    int index_parent = vet_padri->parent.at(i);
    // nodo corrente
    pnode nuovo = map.at(i);
    // posizione del nodo corrente ('l': figlio sinistro, 'r': figlio destro,
    // 'z': radice)
    char child_posi = vet_padri->child_position.at(i);

    // se è -1 allora è la radice
    if (index_parent == -1) {
      root = nuovo;
    } else {
      // prende il padre del nodo corrente, tramite la mappa
      pnode padre = map[index_parent];

      // se è 'l' lo attacca come figlio sinistro
      if (child_posi == 'l')
        padre->left = nuovo;
      else if (child_posi == 'r') // altrimenti come figlio destro
        padre->right = nuovo;
    }
  }
  return root;
}