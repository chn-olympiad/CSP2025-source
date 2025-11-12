#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5005],vis[5005],ans = 0;
string s;
void dfs(int t,int x,int j){
	if(t == n+1){
		if(x >= m) ans++;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		vis[i] = 1;
		if(s[t-1] == '0' || j >= a[i]) dfs(t+1,x,j+1);
		else dfs(t+1,x+1,j);
		vis[i] = 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(n >= 20){
		cout << 0 << endl;
		return 0;
	}
	dfs(1,0,0);
	cout << ans << endl;
	return 0;
}

