#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v,w;
	bool operator <(const Edge &x)const{
		return w<x.w;
	}
};
Edge e[1000010];
vector<Edge>op[2];
Edge eg[10][1111];
int f[1111],dg[1111],c[20];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int n,m,k;
long long ans=1e18;
void dfs(int x,int y,long long sum,int d){
	if(sum>=ans)return;
	if(x>k){
		int cnt=0;
		for(int i=1;i<=n+k;i++)f[i]=i;
		int len=op[d].size();
		for(int i=0;i<len;i++){
			if(!dg[op[d][i].u]||!dg[op[d][i].v])continue;
			int fu=find(op[d][i].u);
			int fv=find(op[d][i].v);
			if(fu!=fv){
				cnt++;
				f[fu]=fv;
				sum+=1ll*op[d][i].w;
				if(cnt>=n+y)break;
			}
		}
		ans=min(ans,sum);
		return;
	}
	dfs(x+1,y,sum,d);
	op[d^1]=op[d];
	for(int i=1;i<=n;i++){
		op[d^1].insert(lower_bound(op[d^1].begin(),op[d^1].end(),eg[x][i]),eg[x][i]);
	}
	d^=1;
	dg[x+n]=1;
	dfs(x+1,y+1,sum+1ll*c[x],d);
	dg[x+n]=0;
	d^=1;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=n;i++)dg[i]=1;
	for(int i=n+1;i<=n+k;i++){
		f[i]=i;
		scanf("%d",&c[i-n]);
		for(int j=1;j<=n;j++){
			Edge x;
			x.u=i,x.v=j;
			scanf("%d",&x.w);
			eg[i-n][j]=x;
		}
		sort(eg[i-n]+1,eg[i-n]+n+1);
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		op[0].push_back(e[i]);
	}
	dfs(1,0,0,0);
	printf("%lld",ans);
	return 0;
}
