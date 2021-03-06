#include "stdio.h"

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    
    int value;
} Node;

void add_to_list(struct Node *head, struct Node *to_add) {
    struct Node *last = head;
    while (last->next != NULL) last = last->next;
    
    last->next = to_add;
    to_add->prev = last;
}

struct Node *find_in_list(struct Node *head, struct Node *to_find) {
    struct Node *curr = head;
    while (curr->next != NULL) {
        if (curr->value == to_find->value) return curr;
        curr = curr->next;
    }
    return NULL;
}

void remove_from_list(struct Node *head, struct Node *to_remove) {
    struct Node *curr = head;

    while (curr != NULL) {
        if (curr->value != to_remove->value) {
            curr = curr->next;
            continue;
        }
        if (curr->next != NULL)
            curr->next->prev = curr->prev != NULL ? curr->prev : NULL;
        if (curr->prev != NULL)
            curr->prev->next = curr->next != NULL ? curr->next : NULL;
        break;
    }
}

void print_list (struct Node *head) {
    struct Node *curr = head;

    while (curr != NULL) {
        printf(
            "%d, prev: %d, next: %d\n",
            curr->value,
            curr->prev == NULL ? -1 : curr->prev->value,
            curr->next == NULL ? -1 : curr->next->value
        );
        curr = curr->next;
    }
}

int main () {
    struct Node first = { NULL, NULL, 10 };
    
    printf("\nInitial list:\n");
    print_list(&first);

    printf("\nAdding elements:\n");
    add_to_list(&first, &(Node) {NULL, NULL, 20});
    add_to_list(&first, &(Node) {NULL, NULL, 30});
    add_to_list(&first, &(Node) {NULL, NULL, 40});
    add_to_list(&first, &(Node) {NULL, NULL, 50});
    print_list(&first);

    printf("\nRemoving every second element:\n");
    remove_from_list(&first, &(Node) { NULL, NULL, 20 });
    remove_from_list(&first, &(Node) { NULL, NULL, 50 });
    print_list(&first);
    
    printf("\nFinding element:\n");
    struct Node *found = find_in_list(&first, &(Node) {NULL, NULL, 30});
    printf(
        "%d, prev: %d, next: %d\n",
        found->value,
        found->prev == NULL ? -1 : found->prev->value,
        found->next == NULL ? -1 : found->next->value
    );

    return 0;
}