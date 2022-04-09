#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;

// 스택 초기화 함수 
void init(StackType* s)
{
    s->top = -1;
}
// 공백 상태 검출 함수 
int is_empty(StackType* s)
{
    return (s->top == -1);
}
// 포화 상태 검출 함수 
int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}


// 삽입함수 
void push(StackType* s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->stack[++(s->top)] = item;
}
// 삭제함수 
element pop(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->stack[(s->top)--];
}
// 피크함수 
element peek(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->stack[s->top];
}


int prec(char op) {
    switch (op) {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

int eval(char* exp) {
    int op1, op2, value = 0, i = 0;
    int len = strlen(exp);
    char ch, ch2;
    StackType s;
    init(&s);

    for (i = 0; i < len; i++) {

        ch = exp[i];

        if (ch == ' ')  
            ch = exp[++i];

        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') { 
            ch2 = exp[i + 1];       

            if (ch2 != '+' && ch2 != '-' && ch2 != '*' && ch2 != '/' && ch2 != ' ')
            {
                value = (((ch - '0') * 10) + (ch2 - '0'));
                push(&s, value); 
                i++; 
            }

            else 
            {
                value = ch - '0';
                push(&s, value);
            }
        }

        else
        {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch) {
            case '+': push(&s, op1 + op2); break;
            case '-': push(&s, op1 - op2); break;
            case '*': push(&s, op1 * op2); break;
            case '/': push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}

void infix_to_postfix(char exp[], char cexp[]) {
    int i = 0;
    int j = 0;
    char ch, ch2, top_op;
    int len = (int)strlen(exp);

    StackType s;
    init(&s);

    for (i = 0; i < len; i++) {
        ch = exp[i];
        ch2 = exp[i + 1];
        switch (ch) {
        case '+': case '-': case '*': case '/':
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
                cexp[j++] = pop(&s);
                cexp[j++] = ' ';
            }
            push(&s, ch);
            break;

        case '(':       
            push(&s, ch);
            break;
        case ')':        
            top_op = pop(&s);

            while (top_op != '(') {         
                cexp[j++] = top_op;
                cexp[j++] = ' ';

                top_op = pop(&s);


            }
            break;

        default:
            cexp[j++] = ch; 
            if (ch2 != '+' && ch2 != '-' && ch2 != '*' && ch2 != '/' && ch2 != ' ' && ch2 != '\0' &&
                ch2 != '(' && ch2 != ')')
            {
                cexp[j++] = ch2; 
                i++;
            }
            cexp[j++] = ' ';

            break;
        }
    }

    while (!is_empty(&s)) {
        cexp[j++] = pop(&s);
        cexp[j] = NULL;

    }
}

void main() {
    char a[100];
    char b[100];

    printf("수식을 입력하세요: ");
    scanf_s("%s", a, sizeof(a));
    printf("중위표기 : %s \n", a);
    infix_to_postfix(a, b);
    printf("후위표기 : %s \n", b);

    printf("\n");
    printf("계산 값 : %d \n", eval(b));
}