#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=10005;
const int M=1500005;
struct Node{
	int u,v;
	ll w;
	bool operator<(const Node &x)const{
		return w<x.w;
	}
}e[M],e2[N];
int n,m,k,fa[N],c[15],vis[15],a[15][N],cnt,f,flag;
ll ans;
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		f=1;
		cin>>c[i];
		if(c[i]!=0)f=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)f=0;
		}
		if(f==1)flag=1;
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy)continue;
		fa[fy]=fx;
		ans+=e[i].w;
		e2[++cnt]=e[i];
		if(cnt==n-1)break;
	}
	for(int i=1;i<=k;i++)vis[k]=1;
	for(int i=1;i<=cnt;i++){
		ll minn=1e18,pos=0,sum;
		for(int j=1;j<=k;j++){
			sum=a[j][e[i].u]+a[j][e[i].v];
			if(vis[j]==1)sum+=c[j];
			if(sum<minn)minn=sum,pos=j;
		}
		if(pos){
			if(minn<e[i].w)
				ans=ans-e[i].w+minn,vis[pos]=0;
		}
	}
	if(flag)cout<<"0\n";
	else cout<<ans<<'\n';
	return 0;
}