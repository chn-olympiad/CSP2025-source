#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int a[20][10010];
struct node{
	int u,v,w;
};
vector<node>g;
int fa[10010];
inline int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
inline bool cmp(node a,node b){
	return a.w<b.w;
}
inline void print(){
	cout<<endl;
	for(auto i:g){
		cout<<i.u<<" "<<i.v<<" "<<i.w<<endl;
	}
	cout<<endl;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		g.push_back({u,v,w});
		//g.push_back({v,u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&a[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			int p1=a[i][0]+a[i][j];
			for(int x=j+1;x<=n;x++){
				int p=p1+a[i][x];
				g.push_back({j,x,p});
			}
		}
	}
	long long ans=0;
	sort(g.begin(),g.end(),cmp);
	//print();
	int sum=0;
	for(int i=0;i<g.size();i++){
		int fx=find(g[i].u);
		int fy=find(g[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			ans+=g[i].w;
			sum++;
			//cout<<g[i].u<<" "<<g[i].v<<" "<<g[i].w<<endl;
		}
		if(sum==n-1) break;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

