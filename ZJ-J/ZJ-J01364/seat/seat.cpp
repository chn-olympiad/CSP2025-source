#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],r,c,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==r){
			c=n*m-i+1;
			break;
		}
	}
	if(c%n==0){
		x=c/n;
	}else{
		x=c/n+1;
	}
	if(x%2==1){
		if(c%n==0){
			cout<<x<<" "<<n;
		}else{
			cout<<x<<" "<<c%n;
		}
	}else{
		if(c%n==0){
			cout<<x<<" "<<1;
		}else{
			cout<<x<<" "<<n-c%n+1;
		}
	}
	return 0;
}