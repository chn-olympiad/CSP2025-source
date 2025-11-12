#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int j[1000002],t=0;
    cin>>s;
    for (int i=0;i<s.length();i++){
        int m;
        m=s[i]-'0';
        if (m>=0 && m<=9){
            j[t]=m;
            t++;
        }
    }
    for (int p=9;p>=0;p--){
        for (int i=0;i<t;i++){
            if (j[i]==p){
                cout<<j[i];
            }
        }
    }
    return 0;
}
