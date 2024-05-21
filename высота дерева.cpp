#include <iostream>
#include <string>
#include <stack>
#include <algorithm> 
#include <queue>
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


int height(tree* root) {
    if (root == nullptr)
        return 0;
    else {
        int left_height = height(root->left);
        int right_height = height(root->right);
        return max(left_height, right_height) + 1;
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
    cout << "Высота дерева: "<< height(root)<< endl;

    return 0;
}