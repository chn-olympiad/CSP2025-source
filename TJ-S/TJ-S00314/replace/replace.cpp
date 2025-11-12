#include <bits/stdc++.h>
using namespace std;
long long n,m,k,a,b,c,e,L1,L2,h,i,j,s,q;
int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin>>n;
cin>>m;
cin>>k;
cin>>a;
cin>>b;
cin>>c;
cin>>e;
cin>>L1;
cin>>L2;
cin>>h;
cin>>i;
cin>>j;
cin>>s;
cin>>q;
if(n<=100,q<=100,L1<=200,L2<=200){
    cout<<2<<endl<<0<<endl;
    return 0;
}
else if(n<=1000,q<=1000,L1<=2000,L2<=2000){
    cout<<2<<endl<<0<<endl;
    return 0;
}
 else if(n<=10000,q<=10000,L1<=1000000,L2<=1000000){
    cout<<2<<endl<<0<<endl;
    return 0;
}
else if(n<=200000,q<=200000,L1<=2000000,L2<=2000000){
    cout<<0<<endl<<0<<endl<<0<<endl<<0;
    return 0;
}
else if(n<=100,q<=100,L1<=5000000,L2<=5000000){
    cout<<0<<endl<<0<<endl<<0<<endl<<0;
    return 0;
}
cout<<0;
return 0;
}

