#include <iostream>
#include<unordered_map>
#include<string>
#include<bitset>
using namespace std;
//conversion into binary
string encodetobinary(string& encode){
    string binary= "";
    for(char ch:encode){
        int ascii =ch - 48;
        binary +=bitset<6> (ascii).to_string();
    }
    return binary;
}

void huffmandecode(int ch,int lastbits,unordered_map<string,char>&code, string& encode){
    string binary = encodetobinary(encode);
    if(binary.empty()) return;
    int validbits =binary.size();
    if(lastbits>0)
    {
        validbits =(encode.size()*6)-(6-lastbits);
    }
    //
    if(validbits >0 && validbits <= binary.size()){
        binary =binary.substr(0,validbits);
    }
    string ans ="";
    string tem ="";
    for(char bit:binary){
        tem+=bit;
        if(code.find(tem)!=code.end()){
            ans += code[tem];
            tem ="";
        }
    }
    cout << ans << endl;
}
int main(){
    int tc;
    cin >> tc;

    while(tc--){
        int ch;
        cin >> ch;
        int lastbits;
        cin >> lastbits;
        unordered_map<string,char> code;
        cin.ignore();
        for(int i=0;i<ch;i++){
            string cha;
            getline(cin,cha);
            char le =cha[0];
            string huffcode =cha.substr(2);
            code[huffcode]=le;
        }
        string encode;
        getline(cin,encode);
        huffmandecode(ch,lastbits,code,encode);
    }
    return 0;
}