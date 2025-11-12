#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i = 0;i<n*m;i++){
		cin>>a[i];
	}
	int t=a[0];
	sort(a,a+n*m);
	double u;
	for(int i = 0;i<n*m;i++){
		if(t==a[i])u=n*m-i;
	}
	int y = u;
	int c = ceil(u/n);
	if(y%n==0){
		if(c%2==0)cout<<c<<" "<<1;
		else cout<<c<<" "<<n;
	}else{
		if(c%2==0)cout<<c<<" "<<n-y%n+1;
		else cout<<c<<" "<<y%n;
	}
	return 0;
}

