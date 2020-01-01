#include "radix_base.h"

int main() {
  int number_of_elements;
  int max_string_length;
  printf("Please load your radix tree with values! (only use a-z)\n");
  printf("How many elements do you want in your tree?:");
  scanf("%d", &number_of_elements);
  printf("How long is the largest element in your tree?:");
  scanf("%d", &max_string_length);

  char **elements;
  elements = malloc(number_of_elements * sizeof(char *));
  for (int i = 0; i < number_of_elements; i++)
    elements[i] = malloc((max_string_length + 1) * sizeof(char));
  printf("Please input your elements:\n");
  for (int i = 0; i < number_of_elements; i++) {
    scanf("%s", elements[i]);
  }

  Node *root = get_node();

  for (int i = 0; i < number_of_elements; i++)
    insert(root, elements[i]);

  printf("Searching in the tree  (to exit, type \":q\"):\n");

  bool exit_condition = false;
  while (!exit_condition) {
    char output[][13] = {"Not found!", "It is found!"};
    char input[max_string_length];
    scanf("%s", input);
    if (!strcmp(input, ":q")) {
      exit_condition = true;
      printf("Thank you, bye!\n");
    } else {
      printf("%s\n", output[search(root, input)]);
    }
  }

  for (int i = 0; i < number_of_elements; ++i) {
    free(elements[i]);
  }
  free(elements);

  return 0;
}