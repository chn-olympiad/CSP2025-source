#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("number.in","r","stdin");
    freopen("number.out","w","stdout");
    string s;
    char a[105]={0};
    cin>>s;
    int n=0;
    for(int i=0;i<sizeof(s);i++){
        if(s[i]>='0' && s[i]<='9'){
            a[i]=s[i];
            n=n+1;
        }
    }
    int b=0;
    for(int i=0;i<105;i++){
        if(a[i]!='0'){
            b++;
        }
    }
    for(int i=0;i<b;i++){
        for(int j=i+1;j<b;j++){
            if(a[i]<a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=0;i<b;i+=2){
            cout<<a[i];
        }
    return 0;
}

