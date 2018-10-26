#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct Stack{
    char val;
    int length;
    struct Stack* next;
};
struct Stack* stack_init(){
    struct Stack* stack = malloc(sizeof(struct Stack));
    stack->length = 0;
    stack->val = 'a';
    stack->next = NULL;
    return stack;
}
struct Stack* stack_push(struct Stack* stack, char val){
    struct Stack* s = malloc(sizeof(struct Stack));
    s->next = stack;
    s->length = stack->length + 1;
    s->val = val;
    stack = s; 
    return s;
}

char stack_pop(struct Stack* stack){
    char val = stack->val;
    *stack = *(stack->next);
    return val;
}

bool isValid(char* s){
    struct Stack* stack = stack_init();   
    printf("stack init addr %d\n",*stack);
    int length = strlen(s);
    int i;
    for(i = 0; i < length; i++){
        if( s[i] == '{' || s[i] == '[' || s[i] == '('){
            stack = stack_push(stack, s[i]);
        }else{
            if(stack->length == 0) return false;
            if(s[i] == '}' && stack_pop(stack) != '{') return false;
            if(s[i] == ']' && stack_pop(stack) != '[') return false;
            if(s[i] == ')' && stack_pop(stack) != '(') return false;
        }
    }
    return stack->length == 0;
}

bool isValidBetter(char* s){
    int n=0;
    int length = strlen(s);
    char* stack = malloc(sizeof(char) * length); 
    int i;
    for(i = 0; i < length; i++){
        if( s[i] == '{' || s[i] == '[' || s[i] == '('){
            stack[++n] = s[i];
        }else{
            if(n == 0) return false;
            if(s[i] == '}' && stack[n--] != '{') return false;
            if(s[i] == ']' && stack[n--] != '[') return false;
            if(s[i] == ')' && stack[n--] != '(') return false;
        }
    }
    return n == 0;
}

int main(void){
    char s[] = "{{[]}}";
    bool b = isValidBetter(s);
    printf("%d\n", b);
}
