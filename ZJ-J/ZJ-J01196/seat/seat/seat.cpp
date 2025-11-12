#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,a,sum;
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=2; i<=n*m; i++) {
		int x;
		cin>>x;
		if(x>a)sum++;
	}
	sum++;
	if(sum%n==0) {
		cout<<sum/n;
	} else {
		cout<<sum/n+1;
	}
	cout<<" ";
	if(sum%(2*n)>=1&&sum%(2*n)<=n) {
		cout<<sum%(2*n);
	} else {
		sum=sum%n;
		if(sum==0)sum=n;
		cout<<n-sum+1;
	}
	return 0;
}
