//李心恒 SN-S00339 西安铁一中滨河高级中学
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+10;
const int M=1e6+10;
int n,m,k;
int lenw[20][N];
int c[20];
int fa[N+20];
void init(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int nlen;
pair<int ,pair<int ,int > >leng[M];
int nyuan;
pair<int ,pair<int ,int > >yuan[N+20*N];
ll ans;
int vis[N];
void solve(int chk){
	init();
	int num=0,cnt=0;
	ll ansss=0;
	for(int i=1;i<=k;i++){
		vis[i]=(chk>>(i-1))&1;
		if(vis[i]==1) ansss+=c[i],cnt++;
	}
	for(int i=1;i<=nyuan;i++){
		if(num==n+cnt-1) break;
		int w=yuan[i].first;
		int u=yuan[i].second.first;
		int v=yuan[i].second.second;
		if(u>n&&vis[u-n]==0) continue;
		int U=find(u);
		int V=find(v);
		if(U==V) continue;
		fa[U]=V;
		ansss+=w;
		num++;
	}
	ans=min(ansss,ans);
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		leng[++nlen]={w,{u,v}};
	}
	init();
	sort(leng+1,leng+nlen+1);
	for(int i=1;i<=nlen;i++){
		if(nyuan==n-1) break;
		int w=leng[i].first;
		int u=leng[i].second.first;
		int v=leng[i].second.second;
		int U=find(u);
		int V=find(v);
		if(U==V) continue;
		fa[U]=V;
		yuan[++nyuan]=leng[i];
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>lenw[i][j];
			yuan[++nyuan]={lenw[i][j],{n+i,j}};
		}
	}
	sort(yuan+1,yuan+nyuan+1);
	for(int i=1;i<(1<<k);i++){
		solve(i);
	}
	cout<<ans<<'\n';
	return 0;
}

