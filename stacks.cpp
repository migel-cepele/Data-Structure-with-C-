#include <bits/stdc++.h>
 
using namespace std;

#define MAX 1000
/*
class Stack{
    int top;

    public:
    int a[MAX];
    Stack() {
        top = -1;
    }
    bool eshteBosh();
    bool pushin(int x);
    int pull();
    int shiko();

};


class Stack{
    int top;

    public:
    char a[MAX];
    Stack() {
        top = -1;
    }
    bool eshteBosh();
    bool pushin(char x);
    int pull();
    char shiko();

};

bool Stack::pushin(char x) {
    if (top >= MAX - 1) {
        cout << "U mbush" << endl;
    } else {
        a[++top] = x;
        cout << "Pushin P" << endl;
        return true;
    }
}

bool Stack::eshteBosh() {
    return (top < 0);

}

bool Stack::pushin(int x) {
    if (top >= MAX - 1) {
        cout << "U mbush" << endl;
    } else {
        a[++top] = x;
        cout << "Pushin P" << endl;
        return true;
    }
}

int Stack::pull () {
    if (top < 0) {
        cout << "Nuk ka me" << endl;
    } else {
        int x = a[top--];
        return x;
    }
}
char Stack::shiko() {
    if (top < 0) {
        cout << "Eshte bosh" << endl;
    } else {
        char x = a[top];
        return x;
    }

}
*/

bool jane_balancuar_kllapat(char a[], int n) {
    int q, l, m = 0;
    
    if((a[0] == ')') or (a[0] == ']') or (a[0] == '}')) {
        return false;
    } 
    else {
        stack<char> k;
        
        for(int i = 0; i < n; i++) {
            k.push(a[i]);
            if (k.top() == '{') {
                q++;
            }
            if (k.top() == '}') {
                q--;
            }
            if (k.top() == '(') {
                l++;
            }
            if (k.top() == ')') {
                l--;
            }
            if (k.top() == '[') {
                m++;
            }
            if (k.top() == ']') {
                m--;
            }
        }    
    }
    if ((q == 0) and (l == 0) and (m == 0)) {
        return true;
    }
    else return false;
}





int main() {

    char a[] = {'{', '{', '(', '[', ')', '(', ')', '}', '}', ']'};
    int n = sizeof(a)/sizeof(a[0]);

    cout << jane_balancuar_kllapat(a, n);

    
    return 0;
}