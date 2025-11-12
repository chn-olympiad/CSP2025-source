#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
int a[10005];
void solve(){
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans%mod;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	return 0;
}
