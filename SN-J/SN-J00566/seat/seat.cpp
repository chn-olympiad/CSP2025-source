//李熠骁 SN-J00566 曲江市第一中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int m,n,a[100000],R,ming;
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+nm+1);
	for(int i=1;i<=nm;i++){
		if(a[i]==R){
			ming=nm-i+1;
		}
	}
	int c,r;
	if(ming%n==0){
		if(ming%(2*n)==0){
			c=1;
		}
		else{
			c=n;
		}
		r=ming/n;
	}
	else{
		if(ming%(2*n)>n){
			r=n-ming%n+1;
		}
		else{
			r=ming%n;
		}
		c=ming/n+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
