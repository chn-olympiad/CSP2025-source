#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,ans,a[510],path[510];
char ch[510];
bool vis[510];

void dfs(int now){
	if(now == n + 1){
		int loser = 0;
		for(int i = 1;i <= n;i++){
			int x = path[i];
			if(loser >= a[x] || ch[i] == '0') loser++;
		}
		if(n - loser >= m) ans++;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		vis[i] = true;
		path[now] = i;
		dfs(now + 1);
		vis[i] = false;
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> (ch + 1);
	for(int i = 1;i <= n;i++) cin >> a[i];
	dfs(1);
	cout << ans;
	return 0;
}