#include <bits/stdc++.h>
#define ll long long
#define N 3000005
using namespace std;
int n,m,k;
int V[N],W[N],fst[N],nxt[N],idx=1,c[11][10005],f[N],p[N];
inline int Find(int x){
	if(f[x]==x) return x;
	return f[x]=Find(f[x]);
}
struct edge{
	int u,v;
	ll w;
}e[N];
inline int rd(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
	return x;
}
inline bool cmp(edge a,edge b){return a.w<b.w;}
inline ll kruskal(int add){
	for(int i=1;i<=n+k;i++) f[i]=i;
	int tot=0;
	ll ans=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(p[u]&&p[v]){
			if(Find(u)==Find(v)) continue;
			f[Find(u)]=Find(v);
			tot++;
			ans+=w;
			if(tot==n+add-1) break;
		}
	}
	return ans;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int flag=1;
	n=rd(),m=rd(),k=rd();
	for(int i=1;i<=n+k;i++) f[i]=i,p[i]=1;
	for(int i=1;i<=m;i++){
		e[i].u=rd();
		e[i].v=rd();
		e[i].w=rd();
	}
	for(int i=1;i<=k;i++){
		c[i][0]=rd();
		if(c[i][0]) flag=0;
		int ff=0;
		for(int j=1;j<=n;j++){
			c[i][j]=rd();
			if(c[i][j]) ff=1;
		}
		if(!ff) flag=0;
	}
	if(k==0){
		sort(e+1,e+m+1,cmp);
		cout<<kruskal(0);
		return 0;
	}
	if(flag){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e[++m]={n+i,j,c[i][j]};
				e[++m]={j,n+i,c[i][j]};
			}
		}
		sort(e+1,e+m+1,cmp);
		cout<<kruskal(k);
		return 0;
	}
	if(n<=1000&&k<=5){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e[++m]={n+i,j,c[i][j]};
				e[++m]={j,n+i,c[i][j]};
			}
		}
		ll ans=0x3f3f3f3f3f3f3f3f;
		sort(e+1,e+m+1,cmp);
		for(int x=0;x<(1<<k);x++){
			int sum=0;
			for(int j=1;j<=k;j++){
				if((x>>(j-1))&1) p[j+n]=1,sum+=c[j][0];
				else p[j+n]=0;
			}
			ans=min(ans,kruskal(__builtin_popcount(x))+sum);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}//64
