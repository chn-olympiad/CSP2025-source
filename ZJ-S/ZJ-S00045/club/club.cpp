#include<bits/stdc++.h>
namespace sol {
	using namespace std;
	int t,n;
	constexpr int maxn=1e5+7;
	typedef long long ll;
	ll a[maxn][4];
	struct Del {
		int to;
		ll w;
		friend bool operator<(Del lhs,Del rhs) {
			return lhs.w<rhs.w;
		}
	} del[maxn];
	int ma[maxn],cnt[4];
	priority_queue<Del>q[4];
	int main() {
		for(scanf("%d",&t); t; --t) {
			memset(ma,0,sizeof(ma));
			memset(cnt,0,sizeof(cnt));
			scanf("%d",&n);
			for(int i=1,j; i<=n; ++i) {
				for(j=1; j<=3; ++j) {
					scanf("%lld",a[i]+j);
					if(a[i][j]>a[i][ma[i]])
						ma[i]=j;
				}
				del[i].to=0;
				del[i].w=-(0x3f3f3f3f);
				for(j=1; j<=3; ++j)
					if(j!=ma[i]&&a[i][j]-a[i][ma[i]]>del[i].w) {
						del[i].to=j;
						del[i].w=a[i][j]-a[i][ma[i]];
					}
			}
			const int mxcnt=n/2;
			long long ans=0;
			for(int i=1; i<=3; ++i)
				while(!q[i].empty())
					q[i].pop();
			for(int i=1; i<=n; ++i) {
				if(cnt[ma[i]]<mxcnt) {
					++cnt[ma[i]];
					ans+=a[i][ma[i]];
					q[ma[i]].push(del[i]);
				} else {
					if(del[i]<q[ma[i]].top()) {
						ans+=a[i][ma[i]]+q[ma[i]].top().w;
						q[ma[i]].pop();
						q[ma[i]].push(del[i]);
					} else ans+=a[i][ma[i]]+del[i].w;
				}
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	return sol::main();
}