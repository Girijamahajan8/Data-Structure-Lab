#include <stdio.h>
#include <string.h>

#define MAX 1000000

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int isBalanced(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[')
            push(c);
        else {
            if (isEmpty()) return 0;

            char t = pop();

            if ((c == ')' && t != '(') ||
                (c == '}' && t != '{') ||
                (c == ']' && t != '['))
                return 0;
        }
    }
    return isEmpty();
}

int main() {
    char s[] = "{[()]}";

    if (isBalanced(s))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
