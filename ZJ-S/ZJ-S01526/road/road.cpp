#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
int n,m,k;
int ans,res;
struct node{
	int u,v,w;
	bool operator <(const node& p) const{
		return this->w<p.w;
	}
}g[M];
set<node> t;
int tot;
int a[11][N],c[11];
int fa[N];
int find(int x){
	if(fa[x]==x)	return x;
	return fa[x]=find(fa[x]);
}
int TLT(int p){
	int nw=0,cnt=0;
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	for(set<node>::iterator it=t.begin();it!=t.end();it++){
		int x=find(it->u);
		int y=find(it->v);
		if(x==y)	continue;
		fa[x]=y;
		nw+=it->w;
		cnt++;
		if(cnt==p)	return nw;
	}
	return nw;
}
int cnt;
void dfs(int st,int f,int sum){
	if(st==k+1)
		return;
	if(f){
		int x=TLT(cnt+n-1)+sum;
		if(x>=res+sum)	return;
//		for(int i=1;i<=cnt;i++)
//			cout<<o[i]<<' ';
//		cout<<'\n'<<x<<'\n';
		ans=min(ans,x);
	}
	dfs(st+1,0,sum);
	for(int j=1;j<=n;j++)
		t.insert((node){n+j,st,a[st][j]});
	cnt++;
	dfs(st+1,1,sum+c[st]);
	for(int j=1;j<=n;j++)
		t.erase(t.lower_bound((node){n+j,st,a[st][j]}));
	cnt--;
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool F=1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>g[i].u>>g[i].v>>g[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]>0)	F=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]>0)	F=0;
		}
	}
	if(F){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m;i++)
		t.insert(g[i]);
	tot=m;
	ans=res=TLT(n-1);
	dfs(1,0,0);
	cout<<ans<<'\n';
	return 0;
}
