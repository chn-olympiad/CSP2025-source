#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,kz,kx,ky;
	cin>>n>>m;
	int a[n][m];
	int b[100000];
	int c[100000];
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		k=b[1];
	}	
	sort(b,b+n*m+1);
	for (int i=n*m;i>=1;i--){
		c[n*m-i+1]=b[i];	
		if (c[n*m-i+1]==k){
			kz=n*m-i+1;
		}
	}
	if (kz<=n){
		cout<<1<<" "<<kz;
	}
	else if(kz/n%2==1 && kz%n!=0){
		kx=kz/n+1;
		ky=n-(kz%n)+1;
		cout<<kx<<" "<<ky;
	}
	else if(kz/n%2==0 && kz%n!=0){
		kx=kz/n+1;
		ky=kz%n;
		cout<<kx<<" "<<ky;
	}else if(kz/n==0) {
		if (kz%n%2==0){
			cout<<kz/2<<" "<<1;
		}
		else{
			cout<<kz/2<<" "<<n;
		}
	}
	return 0;
}
