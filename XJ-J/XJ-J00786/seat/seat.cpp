#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[50][50],c,d,e,f,g;
int main(){
	freopen("seat,in","r",stdin);
	freopen("seat,out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	  cin>>a[i];
	c=a[1];
	for(int j=1;j<=n*m;j++){
	for(int i=2;i<=n*m;i++)  
	{
	  if(a[i]>a[i-1])  swap(a[i],a[i-1]);
}
}
	for(int i=1;i<=m*n;i++)	  if(a[i]==c)  d=i;
	cout<<d<<" ";
	if(d>n) f=floor(d/n)+1;
	else f=1;
	if(f%2==0){
	 	e=n-(d-n*(f-1)-1);
}
	else {
		 e=d-n*(f-1);
	}
	cout<<f<<" "<<e; 

	return 0;
}
