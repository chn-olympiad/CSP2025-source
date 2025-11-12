#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k; 
struct EDGE{
	int u,v,w,nxt;
}edge[2000005],MST[15][20005];
int cnt[15]; 
int head[20005],tot;
void add(int u,int v,int w){
	edge[++tot]={u,v,w,head[u]};
	head[u]=tot;
}
int a[15][10005];
int c[15];
int fa[20005],siz[20005];
int Find(int x){
	if(x==fa[x])return x;
	return fa[x]=Find(fa[x]);
}
int ans=1e18,res,qwq;
bool cmp(EDGE x,EDGE y){
	return x.w<y.w;
}
bool solve(int x){
	int sjh=0;
	tot=0;cnt[x]=0;
	for(int i=1;i<=n+k;i++)head[i]=0;
	for(int i=1;i<=cnt[x-1];i++){
		edge[++tot]={MST[x-1][i].u,MST[x-1][i].v,MST[x-1][i].w,0};
	}
	for(int i=1;i<=n;i++){
		edge[++tot]={x+n,i,a[x][i],0};
	}
	sort(edge+1,edge+tot+1,cmp);
	for(int i=1;i<=n+k;i++)fa[i]=i,siz[i]=1;
	for(int i=1;i<=tot;i++){
		int u=edge[i].u,v=edge[i].v;
		if(u==x+n||v==x+n)sjh++;
		if(Find(u)!=Find(v)){
			if(siz[u]<siz[v])fa[Find(u)]=Find(v),siz[Find(v)]+=siz[Find(u)];
			else fa[Find(v)]=Find(u),siz[Find(u)]+=siz[Find(v)];
			MST[x][++cnt[x]]={u,v,edge[i].w};
		}
	}
	if(sjh>=2)return 1;
	if(sjh){
		for(int i=1;i<=cnt[x];i++){
			if(MST[x][i].u==x+n){
				swap(MST[x][i],MST[x][cnt[x]]);
				cnt[x]--;
			}
		}
	}
	return 0;
}
void dfs(int x){
	if(x==k+1){
		res=0;
		for(int i=1;i<=cnt[k];i++){
			res+=MST[k][i].w;
		}
		ans=min(ans,res+qwq);
		return ;
	}
	cnt[x]=cnt[x-1];
	for(int i=1;i<=cnt[x];i++){
		MST[x][i]=MST[x-1][i];
	}
	dfs(x+1);
	if(!solve(x))return ;
	qwq+=c[x];
	dfs(x+1);
	//if(res+qwq>=ans)return ;
	qwq-=c[x];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(edge+1,edge+tot+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	for(int i=1;i<=tot;i++){
		int u=edge[i].u,v=edge[i].v;
		if(Find(u)!=Find(v)){
			if(siz[u]<siz[v])fa[Find(u)]=Find(v),siz[Find(v)]+=siz[Find(u)];
			else fa[Find(v)]=Find(u),siz[Find(u)]+=siz[Find(v)];
			MST[0][++cnt[0]]={u,v,edge[i].w};
			res+=edge[i].w;
			//cout<<"MST[0] : "<<u<<' '<<v<<' '<<edge[i].w<<endl;
		}
	}
	ans=min(ans,res);
	dfs(1);
	cout<<ans<<endl;
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

3 2 1
1 2 2
2 3 2
0 1 100 100
*/
