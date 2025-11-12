#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
const int maxn=5e3+10;
ll n,a[maxn],ans;
void dfs(int i,int g,ll s){
	if(i>=n){
		if(g+1>=3&&a[i]<s) ans=(ans+1)%mod;
		return;
	}
	if(g+1>=3)
		if(a[i]*2<s+a[i]) ans=(ans+1)%mod; 
	dfs(i+1,g+1,s+a[i]);
	dfs(i+1,g,s);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

