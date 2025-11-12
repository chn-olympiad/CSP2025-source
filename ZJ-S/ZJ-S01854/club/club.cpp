#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n;ll a[maxn][3];
priority_queue<pair<ll,pair<int,int>>>q;
priority_queue<pair<ll,pair<int,int>>>qq[3];
bool vis[maxn][3],is[maxn];int cnt[3],L[maxn];
inline void update(int i,int o){
	L[i]=o;ll now=-1e18,fl=-1;
	for(int j=0;j<=2;++j){
		if(vis[i][j]) continue;
		if(a[i][j]-a[i][o]>now){
			now=a[i][j]-a[i][o];
			fl=j;
		}
	}
	if(fl==-1) return;
	qq[o].push({now,{i,fl}});
}
inline void solve(){
	for(;!q.empty();) q.pop();
	for(int i=0;i<=2;++i){
		for(;!qq[i].empty();) qq[i].pop();
	}
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=0;j<=2;++j){
			vis[i][j]=0;
		}
		is[i]=0;
	}
	for(int i=0;i<=2;++i) cnt[i]=0;
	for(int i=1;i<=n;++i){
		scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
		q.push({a[i][0],{i,0}});q.push({a[i][1],{i,1}});q.push({a[i][2],{i,2}});
	}
//	for(int i=1;i<=n;++i){
//		for(int j=0;j<=2;++j){
//			for(int k=0;k<=2;++k){
//				if(a[i][j]-a[i][k]==1067){
//					printf("%d %d %d!!!\n",i,j,k);
//				}
//			}
//		}
//	}
	ll ans=0;int FFF=0;
	for(;!q.empty();){
		auto p=q.top();q.pop();
		int i=p.se.fi,o=p.se.se;ll v=p.fi;
		if(is[i]||vis[i][o]) continue;
		if(cnt[o]==n/2){
			FFF++;
			ll now=qq[o].top().fi;
			int fl=-1;
			for(int j=0;j<=2;++j){
				if(o==j||vis[i][j]) continue;
				if(now<=a[i][j]-v){
					fl=j;now=a[i][j]-v;
				}
			}
			if(fl==-1){
				ans+=now;
				auto x=qq[o].top();qq[o].pop();
				vis[x.se.fi][x.se.se]=1;
				++cnt[x.se.se];
				update(x.se.fi,x.se.se);
				vis[i][o]=1;is[i]=1;
				ans+=a[i][o];
				update(i,o);
			}
			else{
				vis[i][o]=1;vis[i][fl]=1;is[i]=1;
				++cnt[fl];ans+=a[i][fl];o=fl;
				update(i,fl);
			}
		}
		else{
			++cnt[o];ans+=v;
			is[i]=1;vis[i][o]=1;
			update(i,o);
		}
	}
	ll ans1=0;
//	for(int i=1;i<=n;++i){
//		if(vis[i][0]&&vis[i][1]&&vis[i][2]){
//			printf("..%d\n",i);
//		}
//	}
	for(int i=1;i<=n;++i){
//		printf("%d%c",L[i],"\0\n"[i==n]);
		ans1+=a[i][L[i]];
	}
//	for(int i=0;i<=2;++i) printf("%d%c",cnt[i]," \n"[i==2]);
	printf("%lld\n",ans1);//printf("     %d\n",FFF);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;for(scanf("%d",&T);T;--T) solve();
	return 0;
}
/*
I will AFO on 2025.11.29.
Goodbye,OI.
SuperCowHorse
*/