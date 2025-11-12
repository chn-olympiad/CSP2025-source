#include<bits/stdc++.h>
using namespace std;

int n,m,a[110],R;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1);
	int i=1;
	for(;i<=n*m;i++){
		if(a[n*m-i+1]==R) break;
	}
	int c=(i%n==0 ? i/n : i/n+1);
	int r=(i%n==0 ? n : i%n);
	if(c%2==0) r=n-r+1;
	cout<<c<<" "<<r;
	return 0;
}
