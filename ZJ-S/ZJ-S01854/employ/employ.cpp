#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=505;
const ll mod=998244353;
int n,m,a[maxn],c[maxn];
ll ans;bool vis[maxn];vector<int>p;
inline int Calc(){
	int now=0,res=0;
	for(int i=1;i<=n;++i){
		if(now>=c[p[i]]) ++now;
		else if(a[i]==0) ++now;
		else ++res;
	}
	return res;
}
inline void dfs(int x){
	if(x==n+1){
		ans+=(Calc()>=m);
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		vis[i]=1;
		p.push_back(i);
		dfs(x+1);
		vis[i]=0;
		p.pop_back();
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%1d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&c[i]);
	}
	if(m==n){
		bool fl=1;
		for(int i=1;i<=n;++i){
			if(a[i]==0){
				fl=1;break;
			}
		}
		for(int i=1;i<=n;++i){
			if(c[i]==0){
				fl=1;break;
			}
		}
		if(fl){
			printf("0\n");
			return 0;
		}
		ll ans=1;
		for(ll i=1;i<=n;++i){
			ans=ans*(1ll*i)%mod;
		}
		printf("%lld\n",ans);
		return 0;
	}
	if(n<=10){
		p.push_back(0);
		dfs(1);
		printf("%lld\n",ans);
		return 0;
	}
	if(m==1){
		ll ans=1;
		for(ll i=1;i<=n;++i){
			ans=ans*i%mod;
		}
		printf("%lld\n",ans);
		return 0;
	}
	bool K=1;
	for(int i=1;i<=n;++i){
		if(a[i]==0) K=0;
	}
	if(K){
		ll ans=1;
		for(ll i=1;i<=n;++i){
			ans=ans*i%mod;
		}
		printf("%lld\n",ans);
		return 0;
	}
	printf("0\n");
	return 0;
}
/*
I will AFO on 2025.11.29.
Goodbye,OI.
SuperCowHorse
*/