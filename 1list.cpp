#include <iostream>
#include <climits>
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

void del_node(list *&h, list *&t, list *min_node){
    if(min_node){
        if (min_node == h && min_node == t){
            h = t = nullptr;
        } else if(min_node == t){
            t = t->prev;
            t->next = nullptr;
        } else if(min_node == h){
            h = h->next;
            if(h)
                h->prev = nullptr;
        } else {
            min_node->next->prev = min_node->prev;
            min_node->prev->next = min_node->next;
        }
        delete min_node;
    }
}


void print(list *&h, list *&t){
    list *p = h;
    while (p){
        cout << p->inf << " ";
        p = p->next;
    }
}

void result(list *&h, list *&t){
    int min_elem_first = INT_MAX;
    int min_elem_last = INT_MAX;
    list *min_node_first = nullptr;
    list *min_node_last = nullptr;

    list *p = h;
    while(p){
        list *k = p->next;
        if (p->inf <= min_elem_first){
            if (p->inf < min_elem_first) {
                min_elem_first = p->inf;
                min_node_first = p;
            } else {
                min_elem_last = p->inf;
                min_node_last = p;
            }
        }
        p = k;
    }

    del_node(h, t, min_node_first);
    del_node(h, t, min_node_last);
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
    result(h, t);
    print(h, t);
}