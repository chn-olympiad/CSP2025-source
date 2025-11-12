#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000010],n=0;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            num[++n]=s[i]-'0';
        }
    }
    sort(num+1,num+1+n,cmp);
    for(int i=1;i<=n;i++) cout<<num[i];
    return 0;
}
