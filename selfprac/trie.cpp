#include<iostream>
using namespace std;

class trienode{
    public:
    char data;
    trienode* child[26];
    bool isterminal;

    trienode(char ch){
        data =ch;
        for (int i=0;i<26;i++){
            child[i]=NULL;
        }
        isterminal = false;
    }
};

class trie{
    public:
    trienode* root;

    trie(){
        root =new trienode ('\0');
    }
    void insertnode(trienode* root,string word){
        //base case
        if(word.length()==0){
            root->isterminal= true;
            return;
        }
        //assumption if word in small
        int index =word[0]-'a';
        trienode* newnode;
        //present
        if(root->child[index] != NULL){
            newnode = root->child[index];

        }
        else{
            //absent
            newnode =new trienode(word[0]);
            root->child[index]=newnode;
        }
        //recursion
        insertnode(newnode,word.substr(1));
    }

    void insertword(string word){
        insertnode(root,word);
    }

    bool searchnode(trienode* root,string word){
        if(word.length()==0){
            return root->isterminal;
        }
        int index=word[0]- 'a';
        trienode* newnode;
        //present
        if(root->child[index]!= NULL){
            newnode = root->child[index];
        }
        else{
            return false;
        }
        return searchnode(newnode,word.substr(1));
    }
    bool search(string word){
        return searchnode(root,word);
    }
};
int main(){
    trie *t =new trie;
    t-> insertword("abcd");
    t-> insertword("absd");
    t-> insertword("time");
    t-> insertword("ab");
    cout << "present or not" << t->search("abd")<<endl;
    return 0;
}