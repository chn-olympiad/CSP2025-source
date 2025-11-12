#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[10*10*10*10*10*10]={};
    cin>>s;
    int n[strlen(s)]={},m=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='0'&&s[i]<='9'){
            n[m]=s[i]-'0';
            m++;
        }
    }
    sort(n,n+m);
    for(int i=m-1;i>=0;i--){
        cout<<n[i];
    }
    return 0;
}
