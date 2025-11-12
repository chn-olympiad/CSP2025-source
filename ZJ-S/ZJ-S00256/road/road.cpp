#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
struct node{
	int u,v;
	ll w;
	friend bool operator < (const node &x,const node &y){
		return x.w<y.w;
	}
}p[N],P[N];
int n,m,k,fa[N],M;
ll ans,a[11][10005],c[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void solve1(){
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)p[++m]=node{n+i,j,a[i][j]};
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(p+1,p+m+1);
	for(int i=1,u,v;i<=m;i++){
		u=p[i].u,v=p[i].v;
		ll w=p[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		ans+=w;
		fa[fu]=fv;
	}
	cout<<ans<<'\n';
}
void solve2(){
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(p+1,p+m+1);
	for(int i=1,u,v;i<=m;i++){
		u=p[i].u,v=p[i].v;
		ll w=p[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		ans+=w;
		P[++M]=node{u,v,w};
		fa[fu]=fv;
	}
//	cout<<M<<'\n';
//	cout<<ans<<'\n';
	for(int S=1;S<(1<<k);S++){
		ll sum=0;
		M=n-1;
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=k;i++)
			if((S>>(i-1))&1){
				sum+=c[i];
				for(int j=1;j<=n;j++)P[++M]=node{n+i,j,a[i][j]};
			}
		sort(P+1,P+M+1);
		for(int i=1,u,v;i<=M;i++){
			u=P[i].u,v=P[i].v;
			ll w=P[i].w;
			int fu=find(u),fv=find(v);
			if(fu==fv)continue;
			sum+=w;
			fa[fu]=fv;
		}
		ans=min(ans,sum);
//		cout<<sum<<'\n';
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>p[i].u>>p[i].v>>p[i].w;
	bool flag=1;
	for(int i=1;i<=k;i++){
		cin>>c[k];
		if(c[k]!=0)flag=0;
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	if(flag){
		solve1();
	}
	else{
		solve2();
	}
	return 0;
}