#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int c[105];
int n,m,s=1,q=0,r=0;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n*m;i++){
cin>>c[i];
}
q=c[0];
sort(c,c+n*m);
for(int i=n*m-1;i>=0;i--){
if(c[i]==q){
r=n*m-i;
}
}
for(int i=0;i<m;i++){
if(i%2==0){
for(int j=0;j<n;j++){
a[j][i]=s;
s++;
}
}else{
for(int j=n-1;j>=0;j--){
a[j][i]=s;
s++;
}
}
}
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(a[i][j]==r){
cout<<j+1<<" "<<i+1;
return 0;
}
}
}
fclose(stdin);
fclose(stdout);
return 0;
}
