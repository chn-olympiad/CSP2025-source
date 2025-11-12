#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int m,n;
cin>>m>>n;
int c,s[n*m];
for(int i=0;i<n*m;i++){
cin>>s[i];
}
int r=s[0];
for(int i=0;i<n*m;i++){
for(int j=0;j<n*m;j++){
int a=0,b=n*m-1;
if(s[a]<s[b]){
    c=s[a];
    s[a]=s[b];
    s[b]=c;
}
}
cout<<s[i];
}

return 0;
}

