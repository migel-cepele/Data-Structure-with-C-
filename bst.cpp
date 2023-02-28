#include <iostream>
using namespace std;

class BST {                                          //ketu deklarohet struktura e binary search tree me ate te klases dhe objekteve

    public:                                          //objektet e deklaruara pjese e klases jane: nje variabel qe permban te dhenen "data",
                                                    //identifikuesi "celsi", dhe dy pointera per femijet: left dhe right
    char data;
    int celsi;
    BST *left;
    BST *right;

    BST(char vlera, int key) {                      // deklarimi i konstruktorit per inicializimin e objekteve, pointerat deklarohen null by default
        celsi = key;
        data = vlera;
        left = NULL;
        right = NULL;
    }
};
    bool BinarySearch(BST* root, int el) {         // ndertimi i algoritmit te binary search
    if (root->celsi == el or root == NULL) {
        return true;
    }
    if (root->celsi < el) {
        return BinarySearch(root->right, el);
    }
    else {return BinarySearch(root->left, el);}
   
}

int main() {                                                   //krijimi i nje peme binare kerkimi te thjeste me 4 nivele
    BST* root = new BST('a', 100);
    root->left = new BST('b', 80);
    root->right = new BST('c', 200);

    root->left->left = new BST('d', 70);
    root->left->right = new BST('e', 90);

    root->right->left = new BST('f', 170);
    root->right->right = new BST('g', 240);

    root->left->left->left = new BST('h', 65);
    root->left->left->right = new BST('i', 75);
    root->left->right->left = new BST('j', 85);
    root->left->right->right = new BST('k', 95);

    root->right->left->left = new BST('l', 160);
    root->right->left->right = new BST('w', 180);
    root->right->right->left = new BST('m', 230);
    root->right->right->right = new BST('n', 250);

    root->left->left->left->left = new BST('p', 55);
    root->left->right->left->right = new BST('q', 87);

    root->right->left->right->left = new BST('r', 175);
    root->right->left->right->right = new BST('z', 185);
    root->right->right->right->right = new BST('n', 255);

    cout<< BinarySearch(root, 230);                                 // thirrja e programit
                                                                     // rezultati do te tregoj 1 nese celsi i kerkuar gjendet ne peme

    
}
