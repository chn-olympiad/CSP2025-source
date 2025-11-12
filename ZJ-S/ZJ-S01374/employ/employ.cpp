#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1005;
string str;
int n,m,flag,s[N],c[N],p[N],vis[N],ans = 0;
void dfs(int x){
	if(x == n+1){
		int cnt = 0;
		for(int i=1;i<=n;i++){
			if(cnt >= c[p[i]]){
				++ cnt;
				continue;
			}
			if(s[i] == 0) ++ cnt; 
		}
		if(n - cnt >= m) ++ ans;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue; vis[i] = 1;
		p[x] = i; dfs(x+1);
		vis[i] = 0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin >> str;
	for(int i=1;i<=n;i++) s[i] = str[i-1] - '0';
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	dfs(1); printf("%lld\n",ans);
	return 0;
}
