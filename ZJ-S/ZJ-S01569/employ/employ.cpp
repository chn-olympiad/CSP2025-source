#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans=1,n;
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=2;i<=n;i++) {
		ans=(((ans*i)%998244353)+998244353)%998244353;
	}
	cout<<ans;
	return 0;
}