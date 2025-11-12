#include <bits/stdc++.h>
using namespace std;
int main(){
	int m,n,x,xr,z,rz;
	cin>>n>>m;
	int a[m*n];
	for(int i=0;i<m*n,i++;){
		cin>>a[i];
	}
	xr=a[1];
	for(int j=0;j<m*n,j++;){
		for(int p=0;p<m*n-1,p++;){
			if(a[p]>a[p+1]){
				x=a[p];
				a[p]=a[p+1];
				a[p+1]=a[p];
			}
		}
	}
	for(int b=0;b<m*n,b++;){
		if (xr=a[b]){
			z=b+1;
		}
	}
	if(z%n==0){
		rz=z/n;
		if(rz%2==0){
			cout<<rz<<" "<<1;
		}else{
			cout<<rz<<" "<<n;
		}
	}else{
		rz=z/n;
		if(rz%2==0){
			cout<<rz+1<<" "<<n-z%n;
		}else{
			cout<<rz+1<<" "<<z%n;
		}
	}
	return 0;
}
