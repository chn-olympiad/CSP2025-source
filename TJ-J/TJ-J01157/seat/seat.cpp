#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
	int a[110],b[110];
	int n,m,q,u,s,d;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	d=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]>=a[j+1]){
			u=a[j];
			if(u>=s){
			 s=a[j];
			 q=j;}
		 }else{
			 u=a[j+1];
			 if(u>=s){
			 s=a[j+1];
			 q=j+1;}
			}
		}
		a[q]=0;
		b[i]=s;
		s=0;
		
} 
for(int i=1;i<=n*m;i++){
		if(d==b[i])d=i;
	}
	if(d%(2*m)<=m&&d%(2*m)==0)
	cout<<d/m<<" "<<d%(2*m);
	if(d%(2*m)>m&&d%(2*m)==0)
	cout<<d/m<<" "<<m-(d%(2*m)-m);
	if(d%(2*m)<=m&&d>1&&d%(2*m)!=0)
	cout<<d/m+1<<" "<<d%(2*m);
	if(d%(2*m)>m&&d>1&&d%(2*m)!=0)
	cout<<d/m+1<<" "<<m-(d%(2*m)-m);
	return 0;
} 
