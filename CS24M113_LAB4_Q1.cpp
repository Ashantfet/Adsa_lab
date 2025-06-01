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
//minimum element
node* minimum(node* root){
    node* temp = root;
    while(temp ->left != NULL){
        temp = temp -> left;
    }
    return temp;
}
//3. maximum element
node* maximum(node* root){
    node* temp = root;
    while(temp ->right != NULL){
        temp = temp -> right;
    }
    return temp;
}
//4.search an element
bool search(node* root,int n){
    node *temp =root;
    while(temp!=NULL){
        if(temp-> data == n){
            return true;
        }
        if(temp->data > n){
            temp = temp -> left;
        }
        else{
            temp = temp -> right;
        }
    }
    return false;
}
//5. kth smallest element
int kthsmall(node* root,int& k,int& i){
    
    if(root == NULL){
        return -1;
    }
    int left = kthsmall(root->left,k,i);
    if(left!=-1){
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }
    return kthsmall(root->right,k,i);

}
//6.height of bst
int height(node* root){
    if(root == NULL) return 0;
    int l=height(root->left);
    int r=height(root->right);
    return 1+max(l,r);
}
//7.preorder traversal
void preorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }
    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);
}
//8.postorder traversal
void postorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";
}
//9.inorder traversal
void inorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }
    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);
}

int main() {
    int n;
    cin >> n;
    node* root = NULL;
    while(n>0){
        int k;
        cin >> k;
        switch(k){
            case 1:
                  takeinput(root);
                  break;
            case 2:
                   cout << minimum(root)-> data << endl;
                   break;
            case 3:
                   cout << maximum(root)-> data << endl;
                   break;
            case 4:
                   int key;
                   cin >> key;
                   cout << search(root,key) << endl;
                   break;
            case 5:
                   int k;
                   cin >> k;
                   int i;
                   i=0;
                   cout << kthsmall(root,k,i) << endl;
                   break;
            case 6:
                   cout << height(root)-1 << endl;
                   break;
            case 7:
                   preorder(root);
                   cout << endl;
                   break;
            case 8:
                   postorder(root);
                   cout << endl;
                   break;
            case 9:
                   inorder(root);
                   cout << endl;
                   break;
            
        }
        n--;
             

    }
    return 0;
    
}
