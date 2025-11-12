#include<bits/stdc++.h>
using namespace std;
string s;
int x,a[1000009];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[x++]=s[i]-'0';
        }
    }
    sort(a,a+x,cmp);
    for(int i=0;i<x;i++){
        cout<<a[i];
    }
    return 0;
}
