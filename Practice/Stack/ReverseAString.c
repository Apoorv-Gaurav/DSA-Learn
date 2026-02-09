#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int main() {
    char str[MAX];
    int i;

    printf("Enter a string: ");
    fgets(str,MAX,stdin);

    for(i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    for(i = 0; i < strlen(str); i++) {
        str[i] = pop();
    }

    printf("Reversed string: %s", str);

    return 0;
}
