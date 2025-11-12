#include <bits/stdc++.h>
using namespace std;
long long T,n,a[100010],b[100010],c[100010],dp[100010],ans,_aa,_bb,_cc,sum;//到目前这个人，能的多少分
void dfs(int x) {
	if(x == n+1) {
		ans = max(ans,sum);
		return;
	}
	if(_aa < n/2) {
		sum += a[x];
		_aa++;
		dfs(x+1);
		sum -= a[x];
		_aa--;
	}
	if(_bb < n/2) {
		sum += b[x];
		_bb++;
		dfs(x+1);
		sum -= b[x];
		_bb--;
	}
	if(_cc < n/2) {
		sum += c[x];
		_cc++;
		dfs(x+1);
		sum -= c[x];
		_cc--;
	}
	return;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(dp,0,sizeof(dp));
		for(int i = 1; i <= n; i++) {
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		}
		ans = sum = 0;
		_aa = _bb = _cc = 0;
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
