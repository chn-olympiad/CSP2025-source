#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N=1e4+5,K=15;

int n,m,k,c[K],a[K][N],fa[N],sum,ans=1e18;

struct edge{
	int u;
	int v;
	int w;	
	bool operator < (edge x)const{
		return w < x.w;
	}
};
vector<edge>Es[K],E,Ec,En;

int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		edge e;e.u=u;e.v=v;e.w=w;
		E.push_back(e);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;cin>>w;
			edge e;e.u=i+n;e.v=j;e.w=w;
			Es[i].push_back(e);
		}
	}
	sort(E.begin(),E.end());
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(edge x:E){
		int u=find(x.u);
		int v=find(x.v);
		int w=x.w;
		if(u==v)continue;
		fa[u]=v;
		sum+=w;
		Ec.push_back(x);
	}
	ans=sum;
	for(int i=0;i<(1<<k);i++){
		En.clear();
		for(edge x:Ec)En.push_back(x);
		int s=0;
		for(int j=1;j<=k;j++)
			if((i>>(j-1))&1){
				s+=c[j];
				for(edge x:Es[j])
					En.push_back(x);
			}	
		sort(En.begin(),En.end());
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(edge x:En){
			int u=find(x.u);
			int v=find(x.v);
			int w=x.w;
			if(u==v)continue;
			fa[u]=v;
			s+=w;
		}
		ans=min(ans,s);
	}
	cout<<ans<<"\n";
	return 0;
}
