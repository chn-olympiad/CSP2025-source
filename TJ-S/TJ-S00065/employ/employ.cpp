#include<bits/stdc++.h>
using namespace std;
int n,m,a=1;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int sc0=0,sc_=0;
    cin>>n>>m;
    cin>>s;
    int c[n];
    for(int e=0;e<n;e++){
        cin>>c[e];
        if(c[e]==0) sc0++;
        else sc_++;
    }
    if((sc_<m)||((sc0>0)&&(m==n))) {
    cout<<0;
    return 0;}
    if(m==1) {
        for(int l=2;l<sc_;l++) a*=l;
        cout<<a;
        return 0;
    }
    for(int l=2;l<sc_;l++) a*=l;
    int b=1;
    for(int l=2;l<sc0;l++) b*=l;
    a-=b;
    cout<<a;
    return 0;
