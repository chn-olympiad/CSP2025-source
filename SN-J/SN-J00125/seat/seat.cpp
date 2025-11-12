#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b,c,r,y,k;
	cin>>n>>m;
	int x=m*n;
	int a[x];
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	 y=a[1];
	for(int i=0;i<x;i++){
		for(int m=0;m<x;m++){
			if(a[m]<a[m+1]){
				b=a[m];
				a[m]=a[m+1];
				a[m+1]=b;
			}
		}
	}
	for(int i=0;i<x;i++){
		if(a[i]==y){
			k=i;
		}
	}
	if((k/m)%2==0){
		if(k%m=0){
			c=(k/m);
			
		}else{
			c=(k/m)+1;
		}
		r=n-(k%m);
	}else{
		if(k%m=0){
			c=(k/m);
			r=m;
		}else{
			c=(k/m)+1;
			r=k%m;
		}
		;
	}
	cout<<c<<" "<<r;
	return 0;
} 

