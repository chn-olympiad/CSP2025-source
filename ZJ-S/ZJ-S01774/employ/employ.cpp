#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
const ll N=1e4+100,p=998244353;
ll n,m,cnt,c[N],f[N],ans,vis[N];
string s;
void dfs(ll u,ll cnt){
	if(cnt==m){
		ans=(ans+f[n-u+1])%p;
		return ;
	}
	if(cnt+(n-u+1)<m){
//		if(cnt>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		ll z=1;
		if(s[u]=='0'||u-1-cnt>=c[i]) z=0;
		dfs(u+1,cnt+z);
		vis[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	bool flag=1;
	f[0]=1;
	for(int i=1;i<=n;i++){
		if(c[i]!=0) cnt++;
		if(s[i]=='0') flag=0;
		f[i]=f[i-1]*i%p;
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
