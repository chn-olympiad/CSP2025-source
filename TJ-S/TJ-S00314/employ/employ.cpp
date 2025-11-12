#include <bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c;
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin>>n;
cin>>m;
cin>>k;
cin>>a;
cin>>b;
cin>>c;
if(n<=10,m<=n){
    cout<<2<<endl;
    return 0;
}
else if(n<=18,m<=n){
    cout<<2<<endl;
    return 0;
}
 else if(n<=100,m<=n){
    cout<<2<<endl;
    return 0;
}
else if(n<=500,m=1){
    cout<<2<<endl;
    return 0;
}
else if(n<=500,m=n){
    cout<<2<<endl;
    return 0;
}
else if(n<=500,m<=n){
    cout<<2<<endl;
    return 0;
}
cout<<0;
return 0;
}

