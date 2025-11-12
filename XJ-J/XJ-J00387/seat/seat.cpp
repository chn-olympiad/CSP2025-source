#include<bits/stdc++.h>
using namespace std;
int main(){
int a[101];
int n,m,g,x=0,dx=1,dy=1,k=0,p=0;
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>m;
cin>>n;
for(int i=1;i<=n*m;i++){
cin>>a[i];
}
g=a[1];
sort(a,a+m*n+1);
for(int j=1;j<=m*n+1;j++){
	x=j;
	if(a[j]==g){
	x++;
	break;
	}
}
x=m*n+1-x;
dx=(x+n-1)/n;
dy=(x%(n+n));
if(dy<=n&&dy!=0){
dy=dy;
}
if(dy>n){
dy=(n+n+1-dy);
}
if(dy==0){
dy=1;
}
cout<<dx<<" "<<dy;
return 0;
}

