#include <iostream>
using namespace std;

struct stack {
    int inf;
    stack *next;
};

void push(stack *&h, stack *&t, int x) {
    stack *r = new stack;
    r->inf = x;
    r->next = NULL;
    if (!h && !t) {
        h = t = r;
    } else {
        t->next = r;
        t = r;
    }
}

int pop(stack *&h, stack *&t) {
    int i = h->inf;
    stack *r = h;
    h = h->next;
    if (!h) {
        t = NULL;
    }
    delete r;
    return i;
}

void result(stack *&h, stack *&t) {
    stack *h1 = NULL, *t1 = NULL;
    stack *h2 = NULL, *t2 = NULL;
    int x;
    while (h) {
        x = pop(h, t);
        if (x < 10) {
            push(h1, t1, x);
        } else {
            push(h2, t2, x);
        }
    }
    h = h1;
    t = t1;
    while (h2) {
        push(h, t, pop(h2, t2));
    }
}

int main(){
    stack *h = NULL, *t = NULL;
    int n, x;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        push(h, t, x);
    }
    result (h, t);
    while (h && t){
        cout << pop(h, t) << " ";
    }
    cout << endl;
    return 0;
}