#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+50;
const int K=10+50;
const int M=1e6+50;
mt19937 rd(time(0));
inline int ran(int l,int r){
	return rd()%(r-l+1)+l;
}
int n,m,k;
int a[K][N],c[K];
struct edge{
	int x,y,w;
}E[M],sp[M];
inline bool cmp(edge a,edge b){
	return a.w<b.w;
}
int fa[N],tot;
inline int fin(int x){
	return fa[x]==x?fa[x]:fa[x]=fin(fa[x]);
}
inline void merge(int x,int y){
	fa[fin(x)]=fin(y);
}
inline bool same(int x,int y){
	return fin(x)==fin(y);
}
inline int solve(int V){
	int ans=0;
	int nod=n,cnt=0;
	for(int i=0;i<k;i++){
		if((V>>i)&1){
			nod++;
			for(int j=1;j<=n;j++){
				E[++cnt]={nod,j,a[i+1][j]};
			}
			ans+=c[i+1];
		}
	}
	for(int i=1;i<n;i++)E[++cnt]=sp[i];
	for(int i=1;i<=nod;i++)fa[i]=i;
	sort(E+1,E+cnt+1,cmp);
	int tot=0;
	for(int i=1,x,y,w;i<=cnt;i++){
		x=E[i].x,y=E[i].y,w=E[i].w;
		if(same(x,y))continue;
		merge(x,y);
		ans+=w;
		tot++;
		if(tot==nod-1)break;
	}
	return ans;
}
double be,ed;
int ans=0;
signed main (){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	be=clock();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;cin>>x>>y>>w;
		E[i]={x,y,w};
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(E+1,E+m+1,cmp);
	for(int i=1,x,y,w;i<=m;i++){
		x=E[i].x,y=E[i].y,w=E[i].w;
		if(same(x,y))continue;
		merge(x,y);
		ans+=w;
		sp[++tot]=E[i];
		if(tot==n-1)break;
	}
	if(!k){
		cout<<ans<<'\n';
		return 0;
	}
	int S=(1<<k)-1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	ans=min(ans,solve(S));
	for(int i=1;i<S;i++){
		if((i&(-i))==i)ans=min(ans,solve(i));
	}
	while(1){
		ed=clock();
		if((double)ed-be>=930)break;
		ans=min(ans,solve(ran(1,S-1)));
	}
	cout<<ans<<'\n';
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