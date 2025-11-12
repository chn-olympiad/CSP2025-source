#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int rt;
	cin>>rt;
	int ans=1;
	for (int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>rt) ans++;
	}
	if(n==1){
		cout<<ans<<' '<<1;
		return 0;
	}
	if(m==1){
		cout<<1<<" "<<ans;
		return 0;
	}
	int s=ceil(1.0*ans/n);
	cout<<s<<' ';
	if(s%2==0) cout<<n-ans%n+1;
	else cout<<ans%(2*n);
	return 0;
}
