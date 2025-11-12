#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],a[505],ans;
string s;
bool vis[505];
void dfs(int dep){
	if(dep==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[a[i]]) cnt++;
			else if(s[i-1]=='0') cnt++;
		}
		if(n-cnt>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		a[dep]=i;
		dfs(dep+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
