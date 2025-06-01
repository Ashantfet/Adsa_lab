#include <iostream>
#include<queue>
using namespace std;

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
    while (data!=-1){
       root = insertbst(root,data);
        cin >> data;
    }
}
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
node* minimum(node* root){
    node* temp = root;
    while(temp ->left != NULL){
        temp = temp -> left;
    }
    return temp;
}
node* maximum(node* root){
    node* temp = root;
    while(temp ->right != NULL){
        temp = temp -> right;
    }
    return temp;
}
void levelordertraverse(node* root){
    queue <node*> q; 
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp =q.front();
        q.pop();
        if(temp==NULL){
            cout <<  endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp-> left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

        }
}
node* deletebst(node* root,int n){
    if(root == NULL){
        return root;
    }
    if(root->data == n){
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if(root->left != NULL && root->right==NULL){
            node* temp =root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right!=NULL){
            node* temp =root->right;
            delete root;
            return temp;
        }
        if(root->left != NULL && root->right!=NULL){
           int mini =minimum(root->right)->data;
           root ->data =mini;
           root->right=deletebst(root->right,mini);
           
            return root;
        }
    }
    else if(root->data > n){
        root->left =deletebst(root->left,n);
        return root;
    }
    else{
        root->right =deletebst(root->right,n);
        return root;
    }
}
void inorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }
    
    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}


void preorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

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
int kthsmallest(node* root, int k){
    int i=0;
    return kthsmall(root,k,i);
}
int height(node* root){
    if(root == NULL) return 0;
    int l=height(root->left);
    int r=height(root->right);
    return 1+max(l,r);
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
//right view
void rightview (node* root,int& mlevel, int i){
    if(root == NULL){
        return;
    }
    if(mlevel <i){
        cout << root-> data << " ";
        mlevel =i;
    }
    rightview(root->right,mlevel,i+1);
    righttview(root->left,mlevel,i+1);
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
int main() {
    node* root = NULL;
    cout << "Enter data for creation of BST: " << endl;
    takeinput(root);
    cout << " bst";
    levelordertraverse(root);
    deletebst(root,12);
    cout << "\ninorder";
    inorder(root);
    cout << "\npostorder";
    postorder(root);
    cout << "\npreorder";
    preorder(root);
    cout << search(root,10);
    cout <<"minimum" <<  minimum(root)-> data << "maximum" << maximum(root)-> data;
    cout <<" " <<  kthsmallest(root,3);
    cout << " " << height(root);
}