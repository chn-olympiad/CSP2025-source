#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
const ll N=1e4+100,M=3e6+10;
ll n,m,k,cnt,bianjie,c[N],a[11][N],mmax,f[N],ans=1e18,cntxuan;
struct node{
	ll u,v,w;
	bool operator <(const node &n2)const{
		return w<n2.w;
	}
}t[M],st[M],t1[M],t2[M];
ll find(ll x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
ll mintree(){
	for(int i=1;i<=n+k;i++) f[i]=i;
	ll cc=0;
	for(int i=1;i<=cnt;i++) t1[i]=st[i];
	sort(t1+1,t1+1+cnt);
	int i,j;
	for(i=1,j=1;i<=m&&j<=cnt;){
		if(t[i].w<t1[j].w){
			t2[++cc]=t[i],++i;
		}
		else{
			t2[++cc]=t1[j],++j;
		}
		if(cc==bianjie) continue;
	}
	if(cc<bianjie){
		for(;i<=m&&cc<bianjie;t2[++cc]=t[i++]){}
		for(;j<=cnt&&cc<bianjie;t2[++cc]=t1[j++]){}
	}
	ll uu,vv,res=0;
	for(i=1;i<=cc;i++){
		uu=find(t2[i].u),vv=find(t2[i].v);
		if(uu!=vv){
			f[uu]=vv,res+=t2[i].w;
		}
	}
	return res;
}
void dfs(ll u,ll sum){
	if(u==k+1){
		ans=min(ans,mintree()+sum);
		return ;
	}
	if(sum>=ans) return ;
	dfs(u+1,sum);
	cntxuan++;
	ll dfn=0;
	for(int i=1;i<=n;i++)
		if(a[u][i]<=mmax)
			st[++cnt]={u+n,i,a[u][i]},++dfn;
	dfs(u+1,sum+c[u]);
	cntxuan--;
	cnt-=dfn;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ll u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		t[i]={u,v,w};
	}
	bianjie=200000000/(1<<k);
	sort(t+1,t+1+m);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		ll uu=find(t[i].u),vv=find(t[i].v);
		if(uu!=vv){
			f[uu]=vv,mmax=max(mmax,t[i].w);
		}
	}
	bool flaga=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]) flaga=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]) flaga=1;
		}
	}
	if(flaga==0){
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
