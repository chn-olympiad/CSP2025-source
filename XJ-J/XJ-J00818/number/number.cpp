#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[100001];
    cin>>s;
    char z[100001];
    int l=strlen(s);
    for(int i=0;i<l;i++){
        if(s[i]=='0' or s[i]>='1' and s[i]<='9'){
            z[i]=s[i];
        }

    }
    if(strlen(z)==1){
        cout<<z[0];
    }
    int h=z[0];
    for(int i=0;i<strlen(z);i++){
        if(z[i]<z[i+1]){
            z[i]=z[i+1];
            z[i+1]==h;
            h=z[i+1];
        }
    }
    int zh=0;
    for(int i=0;i<strlen(z);i++){
        zh=zh*10+z[i];
    }
    cout<<zh;
    return 0;
}
