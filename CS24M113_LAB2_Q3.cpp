#include <iostream>
#include <queue>
#include <string>
using namespace std;

void printBinaryStrings(int n) {
    if (n <= 0) return;
    queue<string> q;
    q.push("0");
    q.push("1");
    for (int i = 0; i < n; ++i) {
        string a = q.front();
        q.pop();
        cout << a << endl;
        q.push(a + "0");
        q.push(a + "1");
    }
}

int main() {
    int n;
    cin >> n;

    printBinaryStrings(n);

    return 0;
}
