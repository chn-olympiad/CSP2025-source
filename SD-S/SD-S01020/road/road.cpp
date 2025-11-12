#include<algorithm>
#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
constexpr ll M=1e6+10,N=1e4+10,K=15,MAXN=3*1e6+5;
ll n,m,k,pl=0,ans=2e9,c[K],f[N],a[K][N];
struct edge{ll u,v,w;}p[M],all[MAXN];
inline ll reads(){
	char c=getchar();
	ll x=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}return x*f;
}inline void files(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
bool cmp(edge a,edge b){return a.w<b.w;}
ll finds(ll x){return f[x]==x?x:f[x]=finds(f[x]);}
signed main(){//file LL MLE WA
	files();
	n=reads(),m=reads(),k=reads();
	for(ll i=1;i<=m;i++) p[i].u=reads(),p[i].v=reads(),p[i].w=reads();
	for(ll i=1;i<=k;i++){
		c[i]=reads();
		for(ll j=1;j<=n;j++) a[i][j]=reads();
	}for(ll S=0;S<(1<<k);S++){
		ll t=S,cnt=0,res=0,nw=0,ok=0;pl=0;
		for(ll i=1;i<=m;i++) all[++pl]=p[i];
		for(ll i=1;i<=n+k;i++) f[i]=i;
		while(t){
			ll th=t&1;cnt++;
			if(th&1){
				res+=c[cnt];ok++;
				for(ll i=1;i<=n;i++) all[++pl]=edge{ok+n,i,a[cnt][i]};
			}t>>=1;
		}sort(all+1,all+pl+1,cmp);
		for(ll i=1;i<=pl;i++){
			if(nw==n+ok-1) break;
			ll u=all[i].u,v=all[i].v,x=finds(u),y=finds(v);
			if(x==y) continue;
			nw++;f[x]=y;
			res+=all[i].w;
		}ans=min(ans,res);
	}printf("%lld\n",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
