#include<bits/stdc++.h>
#define inf 0x7ffffffffffffff
#define int long long
using namespace std;
int mp[10010][10010];
struct village{
	int c,p[10010];
}v[10010];
bool cmp(village a,village b){
	return a.c<b.c;
}
int fa[10010];
int n,m,k;
int find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
struct Edge{
	int u,v,d;
	bool operator<(const Edge&x)const{
		return d<x.d;
	}
}E[1000010];
int len=0;
int P[10010],tot=0;
//vector<Edge>E;
int kruscal(){
//	E.clear();
	len=0;
	for(int u=1;u<=n;u++){
		for(int d=u+1;d<=n;d++){
			int minn=mp[u][d];
			for(int i=1;i<=tot;i++){
				minn=min(minn,v[i].p[u]+v[i].p[d]);
			}
			if(minn!=inf){
				E[++len].u=u;
				E[len].v=d;
				E[len].d=minn;
			}
		}
	}
	sort(E+1,E+len+1);
	int cnt=0,ans=0;
	for(int i=1;i<=len;i++){
		int u=E[i].u,v=E[i].v,d=E[i].d;
//		cout<<u<<' '<<v<<' '<<d<<'\n';
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			ans+=d;
			cnt++;
			fa[fv]=fu;
		}
		if(cnt==n-1){
//			cout<<ans<<'\n';
			return ans;
		}
	}
	return inf;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		for(int j=1;j<=n;j++){
			mp[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,d;
		cin>>u>>v>>d;
		mp[u][v]=mp[v][u]=min(mp[u][v],d);
	}
	int ans=kruscal();
//	cout<<ans<<'\n';
	bool flag=true;
	for(int i=1;i<=k;i++){
		cin>>v[i].c;
		if(v[i].c)flag=false;
		for(int u=1;u<=n;u++){
			cin>>v[i].p[u];
		}
		if(ans<v[i].c)k--,i--;
	}
	if(flag){
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=k;i++)P[++tot]=i;
		cout<<kruscal()<<'\n';
		return 0;
	}
	sort(v+1,v+k+1,cmp);
	for(int i=1;i<(1<<k);i++){
		tot=0;
		int cost=0;
		for(int j=0;j<k;j++){
			if((1<<j)&i)cost+=v[j+1].c,P[++tot]=j+1;
		}
		if(cost>ans)continue;
		ans=min(ans,kruscal()+cost);
		if(i<(1<<k)-1)for(int i=1;i<=n;i++){
			fa[i]=i;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
