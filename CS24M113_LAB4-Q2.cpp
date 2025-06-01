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
//left view 
void leftview (node* root,int& mlevel, int i){
    if(root == NULL){
        return;
    }
    if(mlevel <i){
        cout << root-> data << " ";
        mlevel =i;
    }
    leftview(root->left,mlevel,i+1);
    leftview(root->right,mlevel,i+1);
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
    leftview(root,mlevel,0);
    cout  << endl;
        n--;
    }
    return 0;
}