#include<bits/stdc++.h>
namespace sol {
	using namespace std;
	int n,m;
	typedef long long ll;
	constexpr ll mod=998244353;
	constexpr int maxn=5e2+7;
	char s[maxn];
	int c[maxn];
	ll ans;
	bool vis[maxn];
	void dfs(int k,int d,int cnt) {
		if(k>n) {
			if(cnt>=m)(++ans)%=mod;
		} else {
			for(int i=1; i<=n; ++i)
				if(!vis[i]) {
					vis[i]=true;
					int td=d;
					if(s[k]=='0'||d>=c[i])++td;
					int tcnt=cnt;
					if(d<c[i]&&s[k]=='1')++tcnt;
					dfs(k+1,td,tcnt);
					vis[i]=false;
				}
		}
	}
	int main() {
		scanf("%d%d%s",&n,&m,s+1);
		for(int i=1; i<=n; ++i)
			scanf("%d",c+i);
//		sort(c+1,c+n+1);
		dfs(1,0,0);
		printf("%lld",ans);
		return 0;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	return sol::main();
}