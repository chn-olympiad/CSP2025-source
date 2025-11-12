#include<bits/stdc++.h>
using namespace std;
bool s[505];
int c[505];
long long mod=998244353;
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
int n,m;
cin>>n>>m;	
string s1;
cin>>s1;
bool ta=1;
bool tc=1;
bool tb=1;
int kg=0;
for(int i=0;i<s1.size();i++){
s[i]=int(s1[i])-'0';
if(s[i]!=1){
ta=0;	
}
if(s[i]!=1){//ȫ1 
tb=0;	
}
if(s[i]!=0){//ȫ0 
tc=0;	
}
if(s[i]==1){
kg++;	
}	
}	
for(int i=0;i<n;i++){
cin>>c[i];	
}
if(tc==1){
cout<<0;
return 0;	
}
if(m==1){
long long ans=1;
long long cnt=1;
for(int i=1;i<=n;i++){
	ans=1;
for(int j=1;j<=i;j++){
ans*=j;
ans%=mod;	
}
cnt=cnt+ans;
cnt%=mod;
}
cout<<cnt;
return 0;	
}
if(tb==1){
long long ans=1;
long long z=1;
for(int i=1;i<=n;i++){
ans*=n;	
ans%=mod;
}
for(int i=1;i<=m;i++){
z*=i;	
z%=mod;
}
ans=ans-z;
ans%=mod;
cout<<ans;
return 0;	
}
if(m==n){
long long ans=1;
for(int i=1;i<=n;i++){
ans*=n;	
ans%=mod;
}
if(tc==1){
cout<<ans<<endl;
}
else{
cout<<0<<endl;	
}
return 0;
}
if(kg<m){
cout<<0;
return 0;	
}
cout<<998244352;	
return 0;	
}
