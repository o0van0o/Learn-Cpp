#include <iostream>
using namespace std;

int main(){
    string str;
    while(1){
        getline(cin,str);
        if(!cin.eof()) cout << str << endl;
        else break;
    }
    return 0;
}