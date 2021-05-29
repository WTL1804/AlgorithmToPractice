//
//  main.cpp
//  括号匹配
//
//  Created by 王天亮 on 2020/10/29.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isValid(string s) {
        vector <char> vec;
        int l=s.size();
        if(l%2 || l==0) return false;
        for(int i=0;i<l;i++){
            if(s[i]=='{' || s[i]=='[' || s[i]=='(')
                vec.push_back(s[i]);
            else{
                if(vec.empty()) return false;
                if(s[i]=='}'  &&  vec.back()!='{')
                    return false;
                if(s[i]==']'&& vec.back()!='[')
                    return false;
                if(s[i]==')'&& vec.back()!='(')
                    return false;
                vec.pop_back();
                }
            }
        if(vec.empty()) return true;
        else return false;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string s;
    cin>>s;
    printf("%d", isValid(s));
    return 0;
}
