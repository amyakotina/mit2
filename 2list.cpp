#include <iostream>
using namespace std;
struct list{
    int inf;
    list *next;
    list *prev;
};

void push(list *&h, list *&t, int x){
    list *r = new list;
    r->inf = x;
    r->next = NULL;
    if (!h && !t){
        r->prev = NULL;
        h = r;
    }
    else{
        t->next = r;
        r->prev = t;
    }
    t = r;
}

void del_node(list *&h, list *&t, list *r){
    if (r == h && r == t){
        h = t = NULL;
    }
    else if(r == t){
        t = t->prev;
        t->next = NULL;
    }
    else{
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    delete r;
}

void print(list *&h, list *&t){
    list *p = h;
    while (p){
        cout << p->inf << " ";
        p = p->next;
    }
}


void move_numbers(list *&h, list *&t, int X) {
    list *p = h;
    list *prev = NULL;

    while (p) {
        if (p->inf < X) {
            if (p == h) {
                prev = p;
                p = p->next;
            } else {
                list *tmp = p;
                p = p->next;

                if (tmp == t) {
                    t = prev;
                    prev->next = NULL;
                } else {
                    tmp->prev->next = tmp->next;
                    tmp->next->prev = tmp->prev;
                }

                tmp->next = h;
                tmp->prev = NULL;
                h->prev = tmp;
                h = tmp;
            }
        } else {
            prev = p;
            p = p->next;
        }
    }
}

void result(list *&h, list *&t){
    int X;
    cout << "X = "; 
    cin >> X;

    list *p = h;
    while(p){
        list *k = p->next;
        move_numbers(h, t, X);
        p = k;
    }
}

int main(){
    list *h = NULL;
    list *t = NULL;
    int n, y;
    cout << "n = "; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> y;
        push(h, t, y);
    }
    result(h,t);
    print(h, t);
}