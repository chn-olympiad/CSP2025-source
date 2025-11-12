#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int a[101][101],n,m,num=1;
cin>>n>>m;
for(int i=1;i<=n;i++){
for(int j=1;j<=m;j++){
cin>>a[i][j];
}
}
int c=a[1][1];
for(int i=1;i<=n;i++){
for(int j=1;j<=m;j++){
if(c<a[i][j])num++;
}
}
int b=num/n;
int v=num%n;
if(v==0){
	cout<<b<<" ";
}
if(v!=0){
	cout<<b+1<<" ";
}
if(b%2==0){
	cout<<v;
}
else if(b%2==1){
	cout<<n-v+1;
}
fclose(stdin);
fclose(stdout);
return 0;
}