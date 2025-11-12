#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int m,n;
cin>>m>>n;
int c,s[n*m];
for(int i=0;i<n*m;i++){
cin>>s[i];
}
for(int i=0;i<n*m;i++){
for(int j=0;j<n*m;j++){
int a=0,bn*m-1;
if(s[a]<s[b]){
    c=s[a];
    s[a]=s[b];
    s[b]=c;
}
}
}
return 0;
}

