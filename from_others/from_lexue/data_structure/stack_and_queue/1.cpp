#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<cctype>
using namespace std;
#define MAX_SIZE 200
#define stackSize 100
typedef struct 
{
    char data[stackSize];
    int top;
}stack;
typedef enum {
    ADD = 0, SUB, MUL, DIV, POW, LEFT, RIGHT, VARIABLE, END, OTHERS
}OP;
int priority[] = {1, 1, 2, 2, 3, 0, 4};
int combination_order[] = {0, 0, 0, 0, 1, 0, 0};
stack* initStack() {
    stack *s = (stack*) malloc(sizeof(stack));
    s->top = -1;
    return s;
}
bool isEmpty(stack *p) {
    return p->top == -1;
}
bool isFull(stack *p) {
    return p->top == stackSize - 1;
}
void push(stack*p, char c) {
    if (isFull(p)) return ;
    p->data[++(p->top)] = c; 
}
void pop(stack *p) {
    if (isEmpty(p)) return ;
    p->top--;
}
char top(stack *p) {
    if (isEmpty(p)) return '\0';
    return p->data[p->top];
}
void clear(stack *p) {
    free(p);
}
OP read(char c) {
    switch (c)
    {
    case '+':
        return ADD;
        break;
    case '-':
        return SUB;
        break;
    case '*':
        return MUL;
        break;
    case '/':
        return DIV;
        break;
    case '^':
        return POW;
        break;
    case '(':
        return LEFT;
        break;
    case ')':
        return RIGHT;
        break;
    case '#':
        return END;
        break;
    default:
        if (isalpha(c)) return VARIABLE;
        return OTHERS;
        break;
    }
}
void deal(OP op, stack *p, char c) {
    if (op == RIGHT) {
        while (!isEmpty(p) && top(p) != '(') {
            cout<<top(p);
            pop(p);
        }
        pop(p);
    }
    else if (op == LEFT) {
        push(p, c);
    }
    else if (isEmpty(p)) {push(p, c);}
    else {
        if (combination_order[op] == 0) {
            if (priority[op] > priority[read(top(p))]) {push(p, c);}
            else {
                while (!isEmpty(p) && priority[op] <= priority[read(top(p))]) {
                    cout << top(p);
                    pop(p);
                }
                push(p, c);
            }
        }
        else {
            if (priority[op] >= priority[read(top(p))]) {push(p, c);}
            else {
                while (!isEmpty(p) && priority[op] < priority[read(top(p))]) {
                    cout << top(p);
                    pop(p);
                }
                push(p, c);
            }
        }
    }
}
void change(char input[], stack *p) {
    //遍历输入，字母直接输出，非字母则栈操作，最后全部出栈
    for (int i = 0; i < strlen(input); i += 1) {
        OP op = read(input[i]);
        if (op == VARIABLE) cout << input[i];
        else if (op == OTHERS) {continue;}
        else if (op == END) {break;}
        else deal(op, p, input[i]);
    }
    while(!isEmpty(p)) {cout << top(p);pop(p);}
    cout << endl;
}
int main() {
    int n;
    scanf("%d\n", &n);
    while (n--) {
        char input[MAX_SIZE];
        fgets(input, sizeof(input), stdin);
        stack *s = initStack();
        change(input, s);
    }
}
