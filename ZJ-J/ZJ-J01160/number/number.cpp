#include <bits/stdc++.h>
using  namespace std;
int a[10];
int main(){
    // Bur, CCF, test 4 are you K me?
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int slen = s.length();
    for(int i=0;i<slen;i++){
        if(s[i]>='0' && s[i]<='9'){
            ++a[s[i]-'0'];
        }
    }
    for(int i=9;i>=0;i--){
        while(a[i]>0){
            printf("%d",i);
            --a[i];
        }
    }
}
