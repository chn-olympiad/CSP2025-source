#include<bits/stdc++.h>
#define ll long long
#define N 1000001
using namespace std;
ll vis[N];
ll n,m,ans;
ll dfs(ll d,ll cnt) {
	if(cnt>=n) {
		ans++;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]){
			//dfs(d+1,);
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	cin>>n>>m;
	cin>>s;
		ans=1;
		for(ll i=n; i>=1; i--) {
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	return 0;
}

