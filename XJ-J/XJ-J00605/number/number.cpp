#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    if(a!=b){
        return a>b;
    }
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    string a;
    for(int i=0;i<=s.size();i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'|s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            a+=s[i];
        }
    }
    for(int i=1;i<=100;i++){
        if(a[i-1]<a[i]){
            int t;
            t=a[i-1];
            a[i-1]=a[i];
            a[i]=t;
        }
    }
    if(a.size()==0){
        cout<<0;
        return 0;
    }else{
        cout<<a;
    }
    return 0;
}
