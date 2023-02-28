#include <iostream>
#include <queue>

#include  <string>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

};

void printList(Node* n) {
    while(n != NULL) {
        cout << n->data << endl;
        n = n->next;

    }
}

int gjatesia(Node* n) {
    int count = 0;
    while(n != NULL) {
        count+=1;
        n = n->next;
    }
    return count;
}

void insert(Node* n, int x = 3, int p = 3) {
    int temp = 5;
}

int main() {
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();


    head-> data = 1;
    head->next = second;   // krijohet nyja e pare me header qe shenjon te nr 1 dhe pointeri next qe shenjon ne nyjen e dyte

    second->data = 2;
    second->next = third;

    third->data = 4;
    third->next = NULL;
    printList(head);

    cout << gjatesia(head);




}