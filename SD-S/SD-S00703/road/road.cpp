#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
const int N=1e4+5;
const int M=1e6+5;
struct node{
	int u,v,w;
}a[M<<1],d[M<<1];
int n,m,k,b[15],c[15][N];
int fa[N<<1];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
void solve1(){
	int cnt=m;
	ll ans=0;
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			a[++cnt]={n+i,j,c[i][j]};
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		fa[fu]=fv;ans+=a[i].w*1LL;
	}cout<<ans;
}
ll ans=0;
void solve2(){
	ll mi=1e18;
	int cnt=0;
	for(int i=1;i<=m;i++)
		d[i]=a[i];
	for(int B=0;B<(1<<k);B++){
		for(int i=1;i<=n+k;i++)
			fa[i]=i;
		ans=0;cnt=0;
		int done=n-1;
		for(int i=1;i<=m;i++)
			a[++cnt]=d[i];
		for(int i=1;i<=k;i++){
			if(!((B>>(i-1))&1))
				continue;
			ans+=b[i]*1LL;
			for(int j=1;j<=n;j++)
				a[++cnt]={i+n,j,c[i][j]};
			done++;
		}sort(a+1,a+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			if(ans>=mi)break;
			int u=a[i].u,v=a[i].v,w=a[i].w;
			int fu=find(u),fv=find(v);
			if(fu==fv)continue;
			fa[fu]=fv;ans+=a[i].w*1LL;
			done++;if(done==0)break;
		}mi=min(mi,ans);
	}cout<<mi;
}
void solve(){
	bool flag=1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>b[i];
		flag&=(b[i]==0);
		for(int j=1;j<=n;j++)
			cin>>c[i][j];
	}if(k==0||flag){solve1();return;}
	else solve2();
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();return 0;
}
//yu shi zhen hao ke !!!

//Ren5Jie4Di4Ling5%
