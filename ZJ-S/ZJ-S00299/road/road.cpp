#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,ans,f[N],c[20],a[20][N];
struct Edge{int u,v,w;}e[M],_e[M],E[M];
int find(int x){
	return(x==f[x]?x:f[x]=find(f[x]));
}
bool cmp(Edge p,Edge q){
	return p.w<q.w;
}
int Kru(int _n,int _m){
	memcpy(_e+1,e+1,(_m+1)*24);
	sort(_e+1,_e+_m+1,cmp);
	int res=0;
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1,j=0;i<=_m&&j<_n-1;i++){
		int u=find(_e[i].u),v=find(_e[i].v);
		if(u!=v)f[u]=v,res+=_e[i].w,j++;
	}return res;
}
void dfs(int x,int y,int s,int tot){
	if(s>=ans)return;
	if(x==k){ans=min(ans,s+Kru(y,tot));return;}
	++x;
	dfs(x,y,s,tot);
	for(int i=1;i<=n;i++)
		if(a[x][i]<=e[n-1].w)
			e[++tot]={n+x,i,a[x][i]};
	dfs(x,y+1,s+c[x],tot);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
		cin>>E[i].u>>E[i].v>>E[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	sort(E+1,E+m+1,cmp);
	for(int i=1,j=0;i<=m&&j<n-1;i++){
		int u=find(E[i].u),v=find(E[i].v);
		if(u!=v)f[u]=v,e[++j]=E[i],ans+=E[i].w;
	}
	dfs(0,n,0,n-1);
	cout<<ans;
	return 0;
}
