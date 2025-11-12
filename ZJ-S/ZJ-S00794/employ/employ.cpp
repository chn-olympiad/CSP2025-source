#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
const int mod=998244353;
const int eps=1e-6;
void solve(){
	int n,m;
	cin>>n>>m;
	if(m!=1){
		cout<<"0\n";
		return ;
	}
	int ans=1;
	for(int i=1;i<=n;i++)ans=ans*i%mod;
	cout<<ans<<'\n';
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}

