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
    stack *temp1 = NULL;
    stack *temp2 = NULL;
    bool firstMin = true;
    revers(h);
    while(h){
        int x = pop(h);
        if (x == min && firstMin){
            firstMin = false; // помечаем первое встреченное минимальное значение
            continue; // пропускаем его
        }
        push(temp1, x);
    }

    firstMin = true; // восстанавливаем первоначальное состояние
     // разворачиваем временный стек

    while(temp1){
        int x = pop(temp1);
        if (x == min && firstMin){
            firstMin = false; // помечаем второе встреченное минимальное значение
            continue; // пропускаем его
        }
        push(temp2, x);
    }

    h = temp2;
    return h;
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
