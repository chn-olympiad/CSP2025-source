#include<bits/stdc++.h>
using namespace std;
#define re(i,n) for(int i=1;i<=n;i++)
#define pe(i,n) for(int i=n;i>=1;i--)
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
#define CIOO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define lowbit(x) (x & -x)
const int N=1e4+5,M=1e6+5;
int n,m,K;
struct Edge{
	int u,v,w,id;
};
Edge e[M];
Edge e2[N*10+N];
int a[11][N],c[11];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int lead[N+10];
int findld(int x){
	if(lead[x]==x)return x;
	return lead[x]=findld(lead[x]);
}
int tag[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	CIOO;
	cin>>n>>m>>K;
	re(i,m){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	re(i,K){
		cin>>c[i];
		re(j,n)cin>>a[i][j];
	}
	sort(e+1,e+m+1,cmp);
	re(i,n)lead[i]=i;
	ll now=0;
	int tot=0;
	re(i,m){
		int u=findld(e[i].u);
		int v=findld(e[i].v);
		if(u==v)continue;
		tag[i]=1;
		lead[u]=v;
		now+=e[i].w;
		tot++;
		if(tot==n-1)break;
	}
	int tp=0;
	re(i,m){
		if(tag[i]){
			e2[++tp]=e[i];
			e2[tp].id=0;
		}
	}
	re(i,K){
		re(j,n){
			e2[++tp]=(Edge){n+i,j,a[i][j],i};
		}
	}
	sort(e2+1,e2+tp+1,cmp);
	ll ans=now;
	re(S,(1<<K)-1){
		re(i,n+K)lead[i]=i;
		tot=0;
		ll res=0;
		int pc=0;
		re(i,K){
			if(S>>(i-1)&1)res+=c[i],pc++;
		}
		re(i,tp){
			if(e2[i].id!=0&&(!(S>>(e2[i].id-1)&1)))continue;
			int u=findld(e2[i].u);
			int v=findld(e2[i].v);
			if(u==v)continue;
			tot++;
			lead[u]=v;
			res+=e2[i].w;
			if(tot==n+pc-1)break;
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}
