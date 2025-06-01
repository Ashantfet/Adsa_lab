#include <iostream>
#include <set>
#include <utility>
using namespace std;

class Relation {
private:
    int n;  
    set<pair<int, int>> pairs;

public:
    
    void init(int size) {
        n = size;
        pairs.clear();
    }

    void add(int a, int b) {
        pairs.insert({a, b});
    }

    bool isReflexive() {
        for (int i = 1; i <= n; ++i) {
            if (pairs.find({i, i}) == pairs.end()) {
                return false;
            }
        }
        return true;
    }

    bool isSymmetric() {
        for (auto& p : pairs) {
            int a = p.first;
            int b = p.second;
            if (pairs.find({b, a}) == pairs.end()) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Relation R;
    
    int n;
    cout << "Enter the size of the set (n): ";
    cin >> n;
    R.init(n);

    char choice;
    do {
        int a, b;
        cout << "Enter a pair to add (a b): ";
        cin >> a >> b;
        R.add(a, b);

        cout << "Do you want to add another pair? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    if (R.isReflexive()) {
        cout << "The relation is reflexive." << endl;
    } else {
        cout << "The relation is not reflexive." << endl;
    }

    if (R.isSymmetric()) {
        cout << "The relation is symmetric." << endl;
    } else {
        cout << "The relation is not symmetric." << endl;
    }

    return 0;
}
