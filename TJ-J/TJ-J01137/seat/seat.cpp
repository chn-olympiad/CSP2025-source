#include <bits/stdc++.h>
using namespace std;
int n,m,k,f,c,r;
int a[1000000];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			f=i; 
		}
	}	
	if(f%n==0){
		c=f/n;
	}else{
		c=f/n+1;
	}
	r=f-c*n+n;
	if(c%2!=0){
		cout<<c<<" "<<r;
	}else{
		cout<<c<<" "<<n-r+1;
	}
	return 0;
} 
