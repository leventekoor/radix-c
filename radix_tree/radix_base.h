#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef RADIX_BASE
#define RADIX_BASE

#define ALPHABET_SIZE 26

typedef struct Node {
  struct Node *children[ALPHABET_SIZE];
  bool end_point;
} Node;

Node *get_node(void);
bool search(Node *root, const char *key);
void insert(Node *root, const char *key);

#endif
