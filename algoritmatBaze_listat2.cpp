#include <iostream>
#include  <string>
using namespace std;

class pol{
    public:
    int koeficient;
    int fuqia;
    pol* pas;

};

//funksion qe krijon polinom

void krijoPolinom(pol* head, pol* tail) { //ne ekzekutimin e ketij fun dhe atij me poshte kufiza e pare do te jete 0,0 sepse head sherben si qelize dummy
    int i = 0;
    int k;
    int f;

    cout << "Vendosni koeficientin: ";
    cin >> k;
    while(k != 0) {

        cout <<"Vendosni fuqine: ";
        cin >> f;

        pol* eliri = NULL;
        eliri = new pol();

        eliri->koeficient = k;
        eliri->fuqia = f;
        eliri->pas = NULL;
        if(i < 1) {
            
            tail = eliri;
            head->pas = tail;

        } else {
            tail->pas = eliri;
            tail = eliri;
        
        }
        i++;
        cout << tail->koeficient << " ," << tail->fuqia << " ";
        cout << "Vendosni koeficientin: ";
        cin >> k;    
    }
}

pol* shuma_pol(pol* head1, pol* head2) {
    pol* p = NULL;
    p = new pol();
    pol* bishti = NULL;
    bishti = new pol();

    int i = 0;
    while((head1->pas) and (head2->pas)) {
        pol* eliri = NULL;
        eliri = new pol();

        int f1 = head1->pas->fuqia;
        int f2 = head2->pas->fuqia;
        if(f1 > f2) {
            eliri->fuqia = f1;
            eliri->koeficient = head1->pas->koeficient;
            head1->pas = head1->pas->pas;
        }
        else if(f2 > f1) {
            eliri->fuqia = f2;
            eliri->koeficient = head2->pas->koeficient;
            head2->pas = head2->pas->pas;
        }
        else{
            eliri->fuqia = f1;
            eliri->koeficient = head1->pas->koeficient + head2->pas->koeficient;
            head1->pas = head1->pas->pas;
            head2->pas = head2->pas->pas;
        }

        if(i < 1) {
            bishti = eliri;
            p->pas = bishti;
        } else {
            bishti->pas = eliri;
            bishti = eliri;
        }
        i++;
    }
    if(head1->pas != NULL) {
        bishti->pas = head1->pas;
    }
    if(head2->pas != NULL) {
        bishti->pas = head2->pas;
    }
    return p;
    
}


pol* derivati_pol(pol* p) {
    int i = 0;

    pol* head = NULL;
    head = new pol();
    pol* bishti = NULL;
    bishti = new pol();

    while(p->pas!= NULL) {

        pol* eliri = NULL;
        eliri = new pol();

        eliri->fuqia = p->pas->fuqia - 1;
        eliri->koeficient = p->pas->koeficient * p->pas->fuqia;
        eliri->pas = NULL;
        

        if ( i < 1) {
            bishti = eliri;
            head->pas = bishti;
        } else {
            bishti->pas = eliri;
            bishti = eliri;
        }
        i++;
        p->pas = p->pas->pas;
    }
    return head; 
}

void printList(pol* list) {
    pol* q = list;
    
    while(q != NULL) {
        cout << q->koeficient << ", " << q->fuqia << " "; 
        q = q->pas;

    }
    cout << endl;
}

int main() {

    pol* head1 = NULL;
    pol* tail1 = NULL;
    head1 = new pol();
    tail1 = new pol();

    pol* head2 = NULL;
    pol* tail2 = NULL;
    head2 = new pol();
    tail2 = new pol();

    krijoPolinom(head1, tail1);
    tail1 = derivati_pol(head1);
    printList(tail1);
    
    

    


}