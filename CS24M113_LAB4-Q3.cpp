#include <iostream>
using namespace std;
// node creation
class node{
    public:
           int data;
           node* left;
           node* right;

           node (int k){
            this -> data =k;
            this -> left = NULL;
            this -> right = NULL;
           }
};
//insert an element
node* insertbst(node* root,int n){
        //base case
        if (root==NULL){
            root = new node(n);
            return root;
        }
        if(n > root->data){
            root->right =insertbst(root->right,n);
        }
        else{
            root->left =insertbst(root->left,n);
        }
        return root;
}
void takeinput(node* &root){
    int data;
    cin >> data;
    root = insertbst(root,data);
}
//ncr formula
int ncr(int n, int k) {
    if (k > n) return 0;
    int res = 1;
    for (int i = 0; i < k; ++i) {
        res = res * (n - i) / (i + 1);
    }
    return res;
}
// count of nodes
int count(node* root) {
    if (root==NULL) 
    return 0;
    return 1 + count(root->left) + count(root->right);
}
//count of sequences
int Sequences(node* root) {
    if (root==NULL) 
    return 1;
    int S1 = Sequences(root->left); 
    int S2 = Sequences(root->right);
    int l = count(root->left);
    int r = count(root->right);
    return ncr(l + r, l) * S1 * S2; 
}
int main(){
    int n;
    cin >> n;
    
    while(n>0){
        int k;
        cin >> k;
        node* root = NULL; 
        while(k>0){
            
            takeinput(root);
            k--;
        }
    int mlevel = -1;
    cout << Sequences(root);
    cout  << endl;
        n--;
    }
    return 0;
}