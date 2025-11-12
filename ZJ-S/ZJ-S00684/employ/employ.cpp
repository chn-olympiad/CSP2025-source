#include<bits/stdc++.h>
using namespace std;
int n,m,ans,p[105],c[105],dead_people,live_people;
bool vis[105],s[105];
void do_sth() {
	for(int i=1; i<=n; i++) {
		if(dead_people>=c[i]) {
			dead_people++;
			continue;
		}
		if(s[i]==0) live_people++;
		else dead_people++;
	}
	if(live_people>=m) ans=(ans+1)%998244353;;
}
void dfs(int pos) {
	if(pos>n) {
		do_sth();
		return;
	}
	for(int i=1; i<=n; i++) {
		if(vis[i]) continue;
		p[pos]=i;
		vis[i]=true;
		dfs(pos+1);
		vis[i]=false;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++) s[i]=getchar()-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;

	return 0;
}

