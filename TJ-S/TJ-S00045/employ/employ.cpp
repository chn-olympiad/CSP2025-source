#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353

int n,m,ans;
int s;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	if(s==0){
		cout<<0;
		return 0;
	}
	int t=1;
	for(int i=1;i<=n;++i){
		t=(t*i)%mod;
	}
	int z=1;
	for(int i=1;i<=n-m;++i){
		z=(z*i)%mod;
	}
	ans=(t/z)%mod;
	cout<<ans;
	return 0;
}
