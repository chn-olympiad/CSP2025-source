#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e6+10;
int p[N],h[N],idx,c[N],n,m,k,a[15][N];
struct E{
	int nxt,to,u,w;
}e[N<<1];
void add(int u,int v,int w){
	e[idx]={h[u],v,u,w},h[u]=idx++;
}
int find(int x){
	if(x==p[x]) return x;
	return p[x]=find(p[x]);
}
bool cmp(E x,E y){
	return x.w<y.w;
}
void Kru(){
	sort(e,e+idx,cmp);
	int res=0;
	for(int i=0;i<=m+k*n;i++){
		int u=e[i].u,v=e[i].to;
		int a=find(u),b=find(v);
		if(a==b) continue;
		res+=e[i].w;
		p[a]=b;
	}
	cout<<res<<"\n";
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	memset(h,-1,sizeof h);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) p[i]=i;
	for(int i=1;i<=m;i++){
		int a,b,c;cin>>a>>b>>c;
		add(a,b,c);
	}
	for(int j=1;j<=k;j++)
	for(int i=0;i<=n;i++){
		cin>>a[j][i];
		if(i) add(j+n,i,a[j][i]);
	}
	Kru();
	

	return 0;
}

