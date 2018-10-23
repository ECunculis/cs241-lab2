#include <stdio.h>
#include <stdlib.h>


struct element {
    struct element * next;
    int data;
};
struct linked_list {
    struct element * head;
};

void append_int(struct linked_list * list, int val) {
      struct element * elem = malloc(sizeof(struct element));
      elem->data = val;
      elem->next = NULL; // Really important to explicitly set this to null. Malloc does not zero memory
      if (list->head == NULL) {
          // Empty list, we need to append to head
          list->head = elem;
      } else {
          // List has some elements, find the end and append to that
          struct element * tail = list->head;
          while (tail->next != NULL) {
              tail = tail->next;
          }
          tail->next = elem;
      }
}

// removes the element at the head and returns it
int remove_int(struct linked_list *list) {
    if (list->head == NULL) {
        return 0;
    } else {
        struct element * head = list->head;
        int value = head->data;
        // remove the element by setting it equal to the next pointing element
        head = head->next;
        return value;
    }
}

int main() {
    struct linked_list list;
    append_int(&list, 5);
    append_int(&list, 3);

    printf("%d\n", remove_int(&list));
    printf("%d\n", remove_int(&list));
    printf("%d\n", remove_int(&list));
    return 0;
}
