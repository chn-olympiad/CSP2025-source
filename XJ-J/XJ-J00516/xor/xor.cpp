#include <bits/stdc++.h>
using namespace std;
int a[100000][2],n,k,ans,o;
bool f=0;

int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
cin>>a[i][0];
if(a[i][0]!=1){
f=1;
}
}
if(f==0){
if(n%2==0){
cout<<n/2;
}else{
cout<<(n-1)/2;
}
}else{
for(int ll=1;ll<=n;ll++){	
for(int rr=ll;rr<=n;rr++){

f=0;
for(int i=ll;i<=rr;i++){
if(a[i][1]>0){
f=1;
}
}
if(f==1){
break;
}
if(ll==rr){
o=a[ll][0];
}else{
o=a[ll][0];
for(int i=ll+1;i<=rr;i++){
o^=a[i][0];
}
}
if(o==k){
for(int i=ll;i<=rr;i++){
a[i][1]+=1;
}
ans++;
}
}
}
cout<<ans;
}
return 0;
}
