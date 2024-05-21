#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct tree {
    char inf;
    tree* right;
    tree* left;
    tree* parent;
};

tree* node(char x) { //начальный узел
    tree* n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

void insert(tree*& tr, char x) { //вставка
    tree* n = node(x);
    if (!tr)
        tr = n; //если дерево пустое - корень
    else {
        tree* y = tr;
        while (y) { //ищем куда вставлять
            if (n->inf > y->inf) { //правая ветка
                if (y->right)
                    y = y->right;
                else {
                    n->parent = y; //узел становится правым ребенком
                    y->right = n;
                    break;
                }
            }
            else if (n->inf < y->inf) { //левая ветка
                if (y->left)
                    y = y->left;
                else {
                    n->parent = y; //узел становится левым ребенком
                    y->left = n;
                    break;
                }
            }
        }
    }
}

void inorder(tree* tr) { //симметричный обход
    if (tr) {
        inorder(tr->left);
        cout << tr->inf << " ";
        inorder(tr->right);
    }
}
void Delete(tree*& tr, tree* v) {//удаление узла
    if (!v->left && !v->right) { // если нет детей
        if (v->parent) { // указатель родителя на NULL
            if (v->parent->left == v)
                v->parent->left = nullptr;
            else
                v->parent->right = nullptr;
        }
        else { // ���� ������ - ������ ������� ���
            tr = nullptr;
        }
        delete v;
    }
    else if (v->left && v->right) { // только один ребенок
        tree* min_right = v->right;
        while (min_right->left) {
            min_right = min_right->left;
        }
        v->inf = min_right->inf;
        Delete(tr, min_right);
    }
    else { 
        tree* child = (v->left) ? v->left : v->right;
        if (v->parent) {
            if (v->parent->left == v)
                v->parent->left = child;
            else
                v->parent->right = child;
        }
        else {
            tr = child; 
        }
        child->parent = v->parent;
        delete v;
    }
}
void deleteEvenNodes(tree*& tr) {
    if (tr) {
        deleteEvenNodes(tr->left); 
        deleteEvenNodes(tr->right); 

        if (tr->inf % 2 != 0) {
            Delete(tr, tr);
        }
    }
}
int main() {
    int n;
    cout << "n = ";
    cin >> n;
    tree* root = nullptr;
    for (int i = 0; i < n; ++i) {
        char x;
        cin >> x;
        insert(root, x);
    }
    deleteEvenNodes(root); 
    inorder(root); 
    cout << endl;
    return 0;
}