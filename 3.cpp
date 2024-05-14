#include <iostream>
using namespace std;

struct stack {
    int inf;
    stack *next;
};

void push(stack *&h, int x){
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h=r;
}

int pop(stack *&h){
    int i = h->inf;
    stack *r = h;
    h = h->next;
    delete r;
    return i;
}

void revers(stack *h){
    stack *head1 = NULL;
    while(h){
        push(head1,pop(h));
    }
    h = head1;
}

int stack_min(stack *h){
    stack *temp = NULL;
    int min = pop(h), x;
    push(temp,min);
    while(h){
        x = pop(h);
        if (x < min){
            min = x;
        push(temp,x);
        }
    }
    revers(temp);
    h = temp;
    return min;
}

stack *result(stack *h){
    int min = stack_min(h);
    stack *temp = NULL;
    while(h){
        x = pop(h);
        if (x == min){
            pop(x);
        }
    }
}

int main(){
    stack *h = NULL;
    int n,x;
    cout << "n = "; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        push(h, x);
    }
    h = result(h);
    while(h){
        cout << pop(h) << " ";
    }
}
