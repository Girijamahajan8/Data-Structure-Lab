#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    return node;
}

void printRange(struct Node* root, int low, int high) {
    if (root == NULL) return;

    if (low < root->data)
        printRange(root->left, low, high);

    if (root->data >= low && root->data <= high)
        printf("%d ", root->data);

    if (high > root->data)
        printRange(root->right, low, high);
}

void solveExample(int arr[], int size, int l, int h, int exampleNum) {
    struct Node* root = NULL;

    for (int i = 0; i < size; i++) {
        root = insert(root, arr[i]);
    }

    printf("Example %d:\n", exampleNum);
    printf("Input Range: l = %d, h = %d\n", l, h);
    printf("Output: ");
    printRange(root, l, h);
    printf("\n\n");
}

int main() {
    int ex1_values[] = {17, 4, 18, 2, 9};
    int n1 = sizeof(ex1_values) / sizeof(ex1_values[0]);
    solveExample(ex1_values, n1, 4, 24, 1);

    int ex2_values[] = {16, 7, 20, 1, 10};
    int n2 = sizeof(ex2_values) / sizeof(ex2_values[0]);
    solveExample(ex2_values, n2, 13, 23, 2);

    return 0;
}
