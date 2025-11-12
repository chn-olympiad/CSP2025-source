#include<bits/stdc++.h>
using namespace std;
string a,b="";
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++) if(isdigit(a[i])) b+=a[i];
    sort(b.begin(),b.end(),greater<char>());
    cout<<b;
    return 0;
}
