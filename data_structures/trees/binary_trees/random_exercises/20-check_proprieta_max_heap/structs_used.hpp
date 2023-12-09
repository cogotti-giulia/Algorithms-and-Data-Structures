/**
 * @file structs_used.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief strutture dati utilizzate per implementare l'albero
 * @version 1.0
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <vector>

struct node {
  int key;
  node *left;
  node *right;

  node(int k, node *sx = nullptr, node *dx = nullptr)
      : key{k}, left{sx}, right{dx} {};
};
typedef node *pnode;

struct tree {
  node *root;

  tree() : root{nullptr} {};
};
typedef tree *T;

struct vector_parent {
  std::vector<int> parent;
  std::vector<int> info;
  std::vector<char> child_position;

  vector_parent(const std::vector<int> &p, const std::vector<int> &i,
                const std::vector<char> &c_posi)
      : parent{p}, info{i}, child_position{c_posi} {};
};
typedef vector_parent *parr;