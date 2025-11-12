#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],h,c,l,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	h=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==h){
			c=n*m-i+1;
		}
	}
	l=c/n;
	r=c%n;
	if(r==0){
		if(l%2==1){
			cout<<l<<" "<<n;
		}else{
			cout<<l<<" "<<1;
		}
	}else{
		if(l%2==1){
			cout<<l+1<<" "<<n-r+1;
		}else{
			cout<<l+1<<" "<<r;
		}
	}
	return 0;
}