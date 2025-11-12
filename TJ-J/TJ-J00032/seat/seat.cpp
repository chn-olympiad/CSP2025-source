#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m],s=1;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<n*m;i++){
		if(a[0]<a[i]){
			s++;
		}
	}
	int c,r;
	if(s%n==0){
		c=s/n;
	}else{
		c=s/n+1;
	}
	if(c%2==0){
		if(s%n==0){
			r=1;
		}else{
			r=n-s%n+1;
		}
	}else{
		if(s%n==0){
			r=n;
		}else{
			r=s%n;
		}
	}

	cout<<c<<' '<<r;
	
	return 0;
} 
