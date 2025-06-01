#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

struct node {
    string intnodes;
    int frequency;
    node *left, *right;
    node(string intnodes, int frequency) {
        left = right = nullptr;
        this->intnodes = intnodes;
        this->frequency = frequency;
    }
};

// Comparison function
struct comp {
    bool operator()(node* l, node* r) {
        if (l->frequency == r->frequency) {
            return l->intnodes > r->intnodes;
        }
        return l->frequency > r->frequency;
    }
};

// Saving Huffman code
void save(node* root, string str, unordered_map<char, string>& huffmancode) {
    if (!root) return;
    // Saving only for leaf nodes
    if (!root->left && !root->right && root->intnodes.size() == 1) {
        huffmancode[root->intnodes[0]] = str;
    }
    save(root->left, str + "0", huffmancode);
    save(root->right, str + "1", huffmancode);
}

// Huffman tree
node* buildtree(string para, unordered_map<char, string>& huffmancode) {
    unordered_map<char, int> fre;
    for (char ch : para) fre[ch]++;
    priority_queue<node*, vector<node*>, comp> minheap;
    // Creation of leaf node for each letter
    for (auto pair : fre) {
        minheap.push(new node(string(1, pair.first), pair.second));
    }
    //bilding tree
    while (minheap.size() != 1) {
        node *left = minheap.top();
        minheap.pop();
        node *right = minheap.top();
        minheap.pop();
        int sum = left->frequency + right->frequency;
        string data = left->intnodes + right->intnodes;
        node* top = new node(data, sum);
        top->left = left;
        top->right = right;
        minheap.push(top);
    }
    save(minheap.top(), "", huffmancode);
    return minheap.top();
}

// Binary string to 6-bit ASCII values
string encodetoascii(string bits) {
    string ans;
    int len = bits.size();
    for (int i = 0; i < len; i += 6) {
        string cut = bits.substr(i, 6);
        if (cut.size() < 6) {
            cut.append(6 - cut.size(), '0');
        }
        int val = stoi(cut, nullptr, 2);
        ans += char(val + 48);
    }
    return ans;
}

// Main function
string huffmanencoding(string para) {
    unordered_map<char, string> huffmancode;
    buildtree(para, huffmancode);
    string encode = "";
    for (char ch : para) {
        encode += huffmancode[ch];
    }
    return encodetoascii(encode);
}

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Clear newline character from buffer
    while (tc--) {
        string para;
        getline(cin, para);

        string finalanswer = huffmanencoding(para);
        cout << finalanswer << endl;
    }
    return 0;
}
