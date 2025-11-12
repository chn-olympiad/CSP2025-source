#include<bits/stdc++.h>
using namespace std;
int c[510];
int n,m;
int v[510];
bool vis[510];
string s;
int ans=0;
long long TT=998244353;
void dfs(int l){
	if(l>n){
		int bg=0;
		int gl=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0') bg++;
			else if(bg>=c[v[i]]) bg++;
			else gl++;
		}
		if(gl>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		v[l]=i;
		vis[i]=1;
		dfs(l+1);
		v[l]=0;
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++) cin >> c[i];
	dfs(1);
	cout << ans%TT;
	return 0;
}
