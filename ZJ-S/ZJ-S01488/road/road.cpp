#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define R register
#define LL long long
using namespace std;
const int N=1e4+20,M=2e6+10;
int n,m,k,f[N],u[N],v[N];
LL ans,w[N];
struct Min{
	int u,v;
	LL w;
}p[M];
inline int find(int k){
	if(f[k]!=k) f[k]=find(f[k]);
	return f[k];
}
bool cmp(Min a,Min b){
	return a.w<b.w;
}
inline void init(){
	for(R int i=1;i<=n+k;i++) f[i]=i;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	init();
	for(R int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		p[i]={u[i],v[i],w[i]};
	}
	sort(p+1,p+1+m,cmp);
	int tot=0;
	for(R int i=1;i<=m;i++){
		int u=p[i].u,v=p[i].v;
		int x=find(u),y=find(v);
		if(x!=y){
			f[y]=x;
			tot++;
			ans+=p[i].w;
			if(tot==n-1) continue;
		}
	}
	for(R int i=1;i<=k;i++){
		LL C,W;
		cin>>C;
		for(R int j=1;j<=m;j++) p[j]={u[j],v[j],w[j]};
		for(R int j=1;j<=n;j++) cin>>W,p[j+m]={i+n,j,W};
		sort(p+1,p+1+n+m,cmp);
		int tl=0;
		LL res=0;
		init();
		for(R int j=1;j<=n+m;j++){
			int u=p[j].u,v=p[j].v;
			int x=find(u),y=find(v);
			if(x!=y){
				tl++;
				res+=p[j].w;
				f[y]=x;
				if(tl==n) break;
			}
		}
		ans=min(ans,res+C);
	}
	cout<<ans<<'\n';
	return 0;
}
