#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int fa[11000];
struct edge{
	int u,v,w;
	bool operator<(const edge k)const{
		return w<k.w;
	}
}e[1001000],e1[1001000];
int c[114];
int a[11][11000];
void init(){
	for(int i=1;i<=n+114;i++){
		fa[i]=i;
	}
}
int find(int u){
	if(u==fa[u]) return u;
	return fa[u]=find(fa[u]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e+1,e+1+m);
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	int ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<(1<<k);i++){
		init();
		int x=i;
		int cnt=0,res=0;
		int p=0;
		while(x){
			p++;
			if(x&1){
				res+=c[p];
				for(int j=1;j<=n;j++){
					e1[++cnt]={p+n,j,a[p][j]};
				}
			}
			x>>=1;
		}
		sort(e1+1,e1+1+cnt);
		int l1=1,l2=1;
		for(int j=1;j<=cnt+m;j++){
			edge E;
			if(l1>m){
				E=e1[l2++];
			}
			else if(l2>cnt){
				E=e[l1++];
			}
			else{
				if(e[l1]<e1[l2]){
					E=e[l1++];
				}
				else{
					E=e1[l2++];
				}
			}
			int u=find(E.u),v=find(E.v);
			if(u!=v){
				fa[u]=v;
				res+=E.w;
			}
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}

