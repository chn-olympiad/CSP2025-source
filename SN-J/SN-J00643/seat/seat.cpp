#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	b=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			b=i;
			break;
		}
	}
	c=ceil(b/(n*1.0));
	if(c%2==1){
		r=b%n;
	}else{
		if(b%n!=0){
			r=n-b%n+1;
		}else{
			r=1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
