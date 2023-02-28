#include <iostream>
#include <queue>
using namespace std;

void trego(queue<int> q) {
    queue<int> g = q;
    while(! g.empty()) {
        int s = g.front();
        cout << '\t' << s;
        g.pop();
    }
}

int main() {
    queue<int> vk;
    vk.push(5);
    vk.push(5);
    vk.push(5);
    vk.emplace(5);
    trego(vk);
    vk.pop();
    vk.pop();
    vk.pop();
    vk.pop();



}