#include <bits/stdc++.h>
using namespace std;
int n,m,c,r,num,sum;
int main(){
    freopen(seat.in,"r",stdin)
    freopen(seat.out,"w",stdout)
	cin>>n>>m;
	int a[n*m];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=100-a[1];
	c=sum/n+1;
	r=sum%m+1;
	cout<<c<<" "<<r;
	feclose(stdin);
	feclose(stdout);
}
