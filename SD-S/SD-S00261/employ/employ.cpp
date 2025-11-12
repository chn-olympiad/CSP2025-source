#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;

signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	long long ans=1;
	for(int i=1;i<=n;++i){
		ans=ans*i%mod;
	}
	cout<<ans<<endl;
	return 0;
}
