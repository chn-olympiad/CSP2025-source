#include<bits/stdc++.h>
using namespace std;
int n;
long long t;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=3;i<=n;i++){
		long long s=1,x=n;
		for(int j=2;j<=i;j++){
			s*=j%998244353;
		}
		for(int j=n-i+1;j<n;j++){
			x*=j%998244353;
		}
		t=(t+x/s)%998244353;
	}
	cout<<t;
	return 0;
}
