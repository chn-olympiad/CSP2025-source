#include<bits/stdc++.h>
using namespace std;
const int N=10010,M=1000010;
int n,m,k;
int c[11],a[11][N],flag[11],minn[11][N];
int cnt,fa[N],ed[N];
long long res,ans;
struct edge{
	int u,v,w;
}e[M];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	res=0;
	cnt=0;
	for(int i=1;i<=m;i++){
		int fu=find(e[i].u);
		int fv=find(e[i].v);
		if(fu==fv) continue;
		ed[++cnt]=i;
		if(fu>fv) swap(fu,fv);
		fa[fv]=fu;
		res+=e[i].w;
		if(cnt==n-1) break;
	}
	ans=res;
	for(int x=1;x<(1<<k);x++){
		res=0;
		cnt=0;
		for(int i=1;i<=n;i++)
			fa[i]=i;
		for(int i=1;i<=k;i++){
			flag[i]=(x>>(i-1))&1;
			res+=c[i]*flag[i];
			for(int j=1;j<=n;j++){
				minn[i][j]=a[i][j];
			}
		}
		for(int i=1;i<=n-1;i++){
			int p=0;
			int fu=find(e[ed[i]].u);
			int fv=find(e[ed[i]].v);
			int cost=e[ed[i]].w;
			if(fu>fv) swap(fu,fv);
			fa[fv]=fu;
			for(int j=1;j<=k;j++){
				if(!flag[j]) continue;
				if(cost>=minn[j][fu]+minn[j][fv]){
					cost=minn[j][fu]+minn[j][fv];
					p=j;
				}
				minn[j][fu]=min(minn[j][fu],minn[j][fv]);
			}
			minn[p][fu]=0;
			res+=cost;
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
