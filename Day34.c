/* Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. 
Final stack top is result. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;
Node *top = NULL;
void push(int x) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}
int pop() {
    Node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}
int main() {
    char expr[1000];
    fgets(expr, sizeof(expr), stdin);
    char *token = strtok(expr, " \n");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        } else {
            int b = pop();
            int a = pop();
            switch (token[0]) {
                case '+':
                    push(a + b);
                    break;
                case '-':
                    push(a - b);
                    break;
                case '*':
                    push(a * b);
                    break;
                case '/':
                    push(a / b);
                    break;
            }
        }
        token = strtok(NULL, " \n");
    }
    printf("%d", pop());
    return 0;
}