#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=10010,maxm=1e6+10;
int n,m,k,cnt=0,up;
ll ans=1e18;
struct edge{
	int u,v,w;
	friend operator<(edge x,edge y){
		return x.w>y.w;
	}
};
priority_queue<edge>g,gn;
int fa[maxn],a[15][maxn],c[15];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);	
}
bool unite(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return 0;
	fa[fx]=fy;
	return 1;
}
bool cmp(edge ta,edge tb){
	return ta.w<tb.w;
}
ll kru(){
	ll res=0;
	int tot=0;
	for(int i=1;i<=up;i++) fa[i]=i;
	for(int i=1;tot<up-1;i++){
		edge now=gn.top();
		if(unite(now.u,now.v)){
			res+=now.w;
			tot++;
		}
		gn.pop();
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g.push(edge{u,v,w});
	}
	int flag=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		flag=c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j]; 
	}
	if(!flag){ //special A
		gn=g;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				gn.push(edge{n+i,j,a[i][j]});
			}	
		}
		up=n+k;
		cout<<kru()<<"\n"; 
		return 0;
	}
	for(int i=0;i<(1<<k);i++){
		gn=g;
		ll cost=0;
		cnt=m,up=n;
		for(int j=1;(1<<(j-1))<=i;j++){
			if(i&j){
				up++;
				for(int u=1;u<=n;u++){
					gn.push(edge{up,u,a[j][u]});
				}
				cost+=c[j];
			}
		}
		ans=min(ans,cost+kru());
	}
	cout<<ans<<"\n";
	return 0;
} 
