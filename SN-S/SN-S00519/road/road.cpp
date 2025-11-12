#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10,M=1e6+10,K=12,inf=1e18;
int n,m,k;
int u[N],v[N],w[N];
int fa[N],siz[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return ;
	if(siz[x]>siz[y]){
		fa[y]=x;siz[x]+=siz[y];
	}
	else{
		fa[x]=y;siz[y]+=siz[x];
	}
}
void clear(){
	for(int i=1;i<=n+k;i++)fa[i]=i,siz[i]=1;
}
bool check(pair<int,int>p){
	if(find(p.first)!=find(p.second)){merge(p.first,p.second);return 1;}
	return 0;
}
int a[K][N],c[N];
int b[N*(K+1)];
void init(){
	pair<int,pair<int,int> >e[M];
	int mm;cin>>n>>mm>>k;
	clear();
	for(int i=1;i<=mm;i++){
		cin>>e[i].second.first>>e[i].second.second>>e[i].first;
	}
	sort(e+1,e+mm+1);
	int cnt=0;
	for(int i=1;i<=mm;i++){
		int U=e[i].second.first,V=e[i].second.second,W=e[i].first;
		if(find(U)==find(V))continue;
		cnt++;
		u[cnt]=U;v[cnt]=V;w[cnt]=W;
		b[++m]=W;
		merge(U,V);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){cin>>a[i][j];b[++m]=a[i][j];}
	}
	sort(b+1,b+m+1);
	m=unique(b+1,b+m+1)-b-1;
	for(int i=1;i<n;i++)w[i]=lower_bound(b+1,b+m+1,w[i])-b;
	for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)a[i][j]=lower_bound(b+1,b+m+1,a[i][j])-b;
}
vector<pair<int,int> >e[N*(K+1)];
vector<pair<int,int> >R[N*(K+1)][K];
int ans=inf;
void solve(int s){
	clear();
	int num=0;
	for(int i=1;i<=k;i++)if((s>>i-1)&1)num+=c[i];
	for(int i=1;i<=m;i++){
		for(pair<int,int>p:e[i])if(check(p))num+=b[i];
		for(int j=1;j<=k;j++){
			if(!((s>>j-1)&1))continue;
			for(pair<int,int>p:R[i][j])if(check(p))num+=b[i];
		}
	}
	ans=min(ans,num);
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	for(int i=1;i<n;i++)e[w[i]].push_back({u[i],v[i]});
	for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)R[a[i][j]][i].push_back({i+n,j});
	for(int s=0;s<1<<k;s++)solve(s);
	cout<<ans<<"\n";
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
