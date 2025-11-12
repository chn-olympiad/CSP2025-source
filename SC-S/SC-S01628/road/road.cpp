#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=20015;
const int M=2000005;
int n,m,k,ecnt,ecnt1;
ll ans=LLONG_MAX;
bool f[N];
ll c[N];
int fa[N];
ll a[15][N];
struct E{
	int f,t;
	ll w;
}e[2*M],e1[2*M];
bool cmp(E x,E y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]!=x)
		fa[x]=find(fa[x]);
	return fa[x];
}
void adde(int f,int t,ll w){
	e[++ecnt].t=t;
	e[ecnt].f=f;
	e[ecnt].w=w;
}
void adde1(int f,int t,ll w){
	e1[++ecnt1].t=t;
	e1[ecnt1].f=f;
	e1[ecnt1].w=w;
}
void Clear(){
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	ecnt1=ecnt;
	for(int i=1;i<=ecnt;i++)
		e1[i]=e[i];
}
ll check(){
	Clear();
	ll cnt=0;
	for(int i=1;i<=k;i++)
		cnt+=c[i]*f[i];
	for(int i=1;i<=k;i++){
		if(f[i]==0) continue;
		for(int j=1;j<=n;j++){
			e1[++ecnt1].t=i+n;
			e1[ecnt1].f=j;
			e1[ecnt1].w=a[i][j];
		}
	}
	sort(e1+1,e1+ecnt1+1,cmp);
	for(int i=1;i<=ecnt1;i++){
		int u=e1[i].f;
		int v=e1[i].t;
		int w=e1[i].w;
		if(find(u)!=find(v)){
			int fx=find(u);
			int fy=find(v);
			fa[fx]=fy;
			cnt+=w;
			if(cnt>=ans)
				return LLONG_MAX;
		}
	}
	return cnt;
}
void dfs(int x){
	if(x==k+1){
		ans=min(ans,check());
		return;
	}
	f[x]=1;
	dfs(x+1);
	f[x]=0;
	dfs(x+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adde(u,v,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	sort(e+1,e+ecnt+1,cmp);
	int t=ecnt;
	for(int i=1;i<=ecnt;i++){
		e1[i]=e[i];
		e[i]=(E){0,0,0ll};
	}
	ecnt=0;
	for(int i=1;i<=t;i++){
		int u=e1[i].f;
		int v=e1[i].t;
		if(find(u)!=find(v)){
			int fx=find(u);
			int fy=find(v);
			fa[fx]=fy;
			adde(u,v,e1[i].w);
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}