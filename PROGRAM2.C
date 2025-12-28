#include <stdio.h>
#include <ctype.h>

#define MAX 50
char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char infix[50], postfix[50];
    int i = 0, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();  
        }
        else {  
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
        i++;
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
