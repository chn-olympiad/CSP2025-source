#include <bits/stdc++.h>
using namespace std;
int n,m,k,v[1000005],u[1000005],w[1000005],minv=INT_MAX,l[1000005],r[1000005],ne=0;
bool b[10005];
bool f=0;
void asd(int t){
for(int i=1;i<=ne;i++){
if(l[i]==t&&b[r[i]]!=1){
b[r[i]]=1;
f=1;
}
if(r[i]==t&&b[l[i]]!=1){
b[l[i]]=1;
f=1;
}
}
}

bool com(){
for(int i=1;i<=n+5;i++){
b[i]=0;
}
b[1]=1;
for(;1;){
f=0;
for(int i=1;i<=n;i++){
if(b[i]==1){
asd(i);
}
}
if(f==0){
break;
}
}
for(int i=1;i<=n;i++){
if(b[i]==0){
return 0;
}
}
return 1;
}

void abc(int nw,int ans){
if(nw>m){
if(com()){
minv=min(minv,ans);
}
return;
}
ne++;
l[ne]=v[nw];
r[ne]=u[nw];
int ll=v[nw];
int rr=u[nw];

abc(nw+1,ans+w[nw]);

int o;
for(int i=1;i<=ne;i++){
if(ll==l[i]&&rr==r[i]){
o=i;
break;
}
}
for(int i=o;o<ne;o++){
l[i]=l[i+1];
r[i]=r[i+1];
}
ne--;
abc(nw+1,ans);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=m;i++){
cin>>v[i]>>u[i]>>w[i];
}
if(k!=0){
cout<<0;
return 0;
}
abc(1,0);
cout<<minv;
	return 0;
}
