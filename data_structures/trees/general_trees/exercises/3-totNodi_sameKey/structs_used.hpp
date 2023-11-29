/**
 * @file structs_used.hpp
 * @author me, myself and I
 * @brief strutture dati utilizzate per rappresentare l'albero generale
 * @version 1.0
 * @date 2023-11-29
 */

struct node {
  int key;
  node *left_child;
  node *right_sibling;

  node(int k, node *lc = nullptr, node *rs = nullptr)
      : key{k}, left_child{lc}, right_sibling{rs} {};
};
typedef node *pnodeG;

struct tree {
  node *root;

  tree() : root{nullptr} {};
};
typedef tree *T;