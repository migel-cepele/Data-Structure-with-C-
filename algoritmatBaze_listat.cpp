#include <iostream>
#include  <string>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

class matrica{
    public:
    int data;
    int shtylla;
    matrica* pas;

};

int end(Node* list) {
    Node* q = list;
    int count = 0;
    while (q->next != NULL) {
        q = q->next;
        count++;
    }

    return count;
}

bool insert(Node* head, int x, int p) {
    Node* q = head;
    for(int i = 0; i < p; i++) {
        q = q->next;
    }
    Node* temp = q->next;
    Node* k;
    k = new Node();
    q->next = k;
    k->data = x;
    k->next = temp;

    return true;
}

bool fshi(Node* head, int p) {
    for(int i = 0; i < p; i++) {
        head = head->next;
    }
    head->next = head->next->next;
    return true;
}

int vendodhja(Node* head, int x) {
    int count = 0;
    while(head != NULL) {
        if(head->data == x) {
            return count;
        } else {
            count++;
        }
        head = head->next;

    }
    return -1;
}

int retrieve(Node* head, int p) {
    for(int i =0; i < p; i++) {
        head = head->next;

    }
    return head->data;
}

bool purge(Node* head) {
    for(int i = 0; i < end(head) - 1; i++) {
        Node* q = head->next;
        head = head->next;
        for(int j = vendodhja(q, q->data); j < end(q); j++) {
            if(retrieve(head, i) == retrieve(q, j)) {
                fshi(q, j);
            } else {
                q = q->next;
            }
        }
    }
    return true;
}

void min_max (Node* head) {
    int min = INT_FAST16_MAX;
    int max = INT_FAST16_MIN;

    for(int i = 0; i < end(head); i++) {
        if(head->data < min) {
            min = head->data;
        }
        if(head->data > max) {
            max = head->data;
        }
        head = head->next;
    }

    cout << "elementi max: " << max << endl;
    cout << "elementi min: " << min << endl;
}

bool shto_x_pas_vl(int x, int vl, Node* head) {
    if (head == NULL) {
        return false;
    }
    else if(head->data == vl ) {
        int c = vendodhja(head,vl);
        insert(head,x,c);
        return true;
    }
    return shto_x_pas_vl(x, vl, head->next);
    
}



void printoMatrice(matrica* a[], int n ) {
    for(int i = 0; i < n; i++) {
        if(a[i] != NULL) {
            matrica* q = a[i]->pas;
            while(q != NULL) {
                cout << q->data << " ";
                q = q->pas;
            }
            cout << endl;
        }
    }
}

Node* merge(Node* head1, Node* head2) {
    Node* p = NULL;
    p = new Node();
    Node* bishti = NULL;
    bishti = new Node();

    int i = 0;
    while((head1 != NULL) and (head2 != NULL)) {
        Node* eliri = NULL;
        eliri = new Node();

        int f1 = head1->data;
        int f2 = head2->data;
        if(f1 > f2) {
            eliri->data = f2;
            eliri->next = NULL;
            head2 = head2->next;
        }
        else if (f1 < f2) {
            eliri->data = f1;
            eliri->next = NULL;
            head1 = head1->next;
        } else {
            eliri->data = f1;
            eliri->next = NULL;
            head1 = head1->next;
        }
        

        if(i < 1) {
            bishti = eliri;
            p->next = bishti;
        } else {
            bishti->next = eliri;
            bishti = eliri;
        }
        i++;
    }
    if(head1 != NULL) {
        bishti->next = head1;
    }
    if(head2 != NULL) {
        bishti->next = head2;
    }
    return p;
    
}

void printList(Node* list) {
    Node* q = list;
    while(q != NULL) {
        cout << q->data << " ";
        q = q->next;

    }
    cout << endl;
}

int main() {

    Node* last = NULL;
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();
    last = new Node();

    head->data = 1;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data= 9;
    third->next = last;

    last->data = 20;
    last->next = NULL;

    Node* d1 = NULL;
    Node* d2 = NULL;
    Node* d3 = NULL;
    Node* d4 = NULL;

    d1 = new Node();
    d2 = new Node();
    d3 = new Node();
    d4 = new Node();

    d1->data = 2;
    d1->next = second;

    d2->data = 3;
    d2->next = third;

    d3->data= 8;
    d3->next = last;

    d4->data = 15;
    d4->next = NULL;

    Node* k = merge(d1, head);
    printList(k);
    

   /*int n = 8;
   matrica* a[n];

   for(int i = 0; i < n; i++) {
    a[i] = NULL;
   }
   for(int i = 0; i < n; i++) {
    a[i] = new matrica();
   }


   matrica* r1_1 = NULL;//rreshti pare
   r1_1 = new matrica();
   matrica* r1_2 = NULL;
   r1_2 = new matrica();
   matrica* r2_1 = NULL;//rreshti dyte
   r2_1 = new matrica();
   matrica* r2_2 = NULL;
   r2_2 = new matrica();
   matrica* r2_3 = NULL;
   r2_3 = new matrica();
   matrica* r4_1 = NULL;//reshti kater
   r4_1 = new matrica();
   matrica* r5_1 = NULL;//rreshti 5
   r5_1 = new matrica();
   matrica* r8_1 = NULL;//rreshti 8
   r8_1 = new matrica();

   a[0]->pas = r1_1;    //inicializimi i tabeles se pointerave
   a[1]->pas = r2_1;
   a[2]->pas = NULL;
   a[3]->pas = r4_1;
   a[4]->pas = r5_1;
   a[5]->pas = NULL;
   a[6]->pas = NULL;
   a[7]->pas = r8_1;


   r1_1->data = 1;    //inicializimi matrices
   r1_1->shtylla = 1;
   r1_1->pas = r1_2;
   r1_2->data = 2;
   r1_2->shtylla = 2;
   r1_2->pas = NULL;
   r2_1->data = 8;
   r2_1->shtylla = 1;
   r2_1->pas = r2_2;
   r2_2->data = 7;
   r2_2->shtylla = 2;
   r2_2->pas = r2_3;
   r2_3->data = 4;
   r2_3->shtylla = 3;
   r2_3->pas = NULL;
   r4_1->data = 2;
   r4_1->shtylla = 1;
   r4_1->pas = NULL;
   r5_1->data = 5;
   r5_1->shtylla = 1;
   r5_1->pas = NULL;
   r8_1->data = 2;
   r8_1->shtylla = 1;
   r8_1->pas = NULL;


   printoMatrice(a,n);
   */


   




}