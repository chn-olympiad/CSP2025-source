#include<bits/stdc++.h>
#include<cstdio> 
using namespace std ;
bool cmp(int x,int y){
return x>y ;
}
string n ;
int main(){
freopen("number.in","r",stdin) ;
freopen("number.out","w",stdout) ;
cin >> n ;
char a[n.size()]={0} ;
for(int i=0;i<n.size();i++){
a[i]=n[i] ;
}
sort(a+0,a+n.size(),cmp) ;
for(int i=0;i<n.size();i++){
if(a[i]>=48&&a[i]<=57) cout << a[i] ;
}
return 0 ;
}
