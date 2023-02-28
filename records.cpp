#include <iostream>
#include <queue>

#include  <string>
using namespace std;

class Rekord{

    public:
    
    string emer;
    string mbiemer;
    int mosha;
    string pozicioni;
    bool disponimi;
    Rekord(string emri, string mbiemri, int vitet, string vendi, bool disponueshmeria) {
        emer = emri;
        mbiemer = mbiemri;
        mosha = vitet;
        pozicioni = vendi;
        disponimi = disponueshmeria;
        
    }
    string print() {
        return emer;
        
    }

};

int main() {



Rekord lojtari_1("robert", "lewandowski", 25, "qenderSulmues", false);
cout << lojtari_1.print();
}


