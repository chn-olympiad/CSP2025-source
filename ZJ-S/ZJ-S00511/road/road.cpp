#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k;
pair<int, pair<int,int> >g[M];
bool f[20];
long long c[20];
long long a[20][N];
int fa[N];
int minn[20][N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	int u,v,w,fu,fv;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[i]={w,{u,v}};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j],minn[i][j]=a[i][j];
		f[i]=true;
	}
	sort(g+1,g+m+1);
	long long ans=0;
	long long cost,pos;
	for(int i=1;i<=m;i++){
		w=g[i].first,u=g[i].second.first,v=g[i].second.second;
		fu=find(u),fv=find(v);
		if(fu==fv)continue;
		cost=w,pos=0;
		for(int j=1;j<=k;j++){
			if((long long)minn[j][fu]+minn[j][fv]+f[j]*c[j]<cost){
				cost=(long long)minn[j][fu]+minn[j][fv]+f[j]*c[j];
				pos=j;
			}
		}
		ans+=cost;
		f[pos]=false;
		fa[fu]=fv;
		for(int i=1;i<=k;i++)
		minn[i][fv]=min(minn[i][fu],minn[i][fv]);
	}
	cout<<ans;
	return 0;
}
