#include <bits/stdc++.h>
using namespace std;

int n,m,q,s,so=0,jc=0;
bool a[105];

int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
cin>>q;
if(i==1){
s=q;
}
a[q]=1;
}
for(int i=100;i>=s;i--){
if(a[i]==1){
so++;
}
}
for(int x=1;x<=m;x++){
if(x%2==1){
for(int y=1;y<=n;y++){
jc++;
if(jc==so){
cout<<x<<' '<<y;
}
}
}else{
for(int y=n;y>=1;y--){
jc++;
if(jc==so){
cout<<x<<' '<<y;
}
}
}
}



return 0;
}
