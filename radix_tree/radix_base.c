#include "radix_base.h"

Node *get_node(void) {
  Node *node_pointer = NULL;

  node_pointer = (Node *)malloc(sizeof(Node));

  if (node_pointer) {
    node_pointer->end_point = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
      node_pointer->children[i] = NULL;
    }
  }

  return node_pointer;
}

void insert(Node *root, const char *key) {
  int length = strlen(key);
  int index;

  Node *search_pointer = root;

  for (int level = 0; level < length; level++) {
    index = (int)key[level] - (int)'a';
    if (!search_pointer->children[index])
      search_pointer->children[index] = get_node();

    search_pointer = search_pointer->children[index];
  }

  search_pointer->end_point = true;
}

bool search(Node *root, const char *key) {
  int length = strlen(key);
  int index;
  Node *crawl_pointer = root;

  for (int level = 0; level < length; level++) {
    index = (int)key[level] - (int)'a';

    if (!crawl_pointer->children[index])
      return false;

    crawl_pointer = crawl_pointer->children[index];
  }

  return (crawl_pointer != NULL && crawl_pointer->end_point);
}