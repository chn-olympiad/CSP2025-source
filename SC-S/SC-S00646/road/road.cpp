#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+505,M=1e6+505;
int n,m,k,len,ans,fa[N],val[N],pos[12],siz[12];
struct edge{
	int u,v,c;
}q[M],e[12][N];
inline bool operator < (edge a,edge b){
	return a.c<b.c;
}
inline int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
inline void solve(int s){
	int res=0,cnt=0,limit=n-1,len=1;
	pos[1]=0;
	siz[1]=1;
	for(int i=1;i<=k;++i){
	  if((s>>(i-1))&1){
		res+=val[i];
		++limit;
		pos[++len]=i;
		siz[len]=1;
	  }
	}
	for(int i=1;i<=n+k;++i)fa[i]=i;
	while(cnt!=limit){
	  int num=1e16,son=0,fu,fv;
	  for(int j=1;j<=len;++j){
	  	again:;
		if(siz[j]>n)continue;
		fu=find(e[pos[j]][siz[j]].u),fv=find(e[pos[j]][siz[j]].v);
		if(fu==fv){
		  ++siz[j];
		  goto again;
		}
		if(e[pos[j]][siz[j]].c<num){
		  num=e[pos[j]][siz[j]].c;
		  son=j;
		}
	  }
	  ++cnt;
	  res+=e[pos[son]][siz[son]].c;
	  fa[find(e[pos[son]][siz[son]].u)]=find(e[pos[son]][siz[son]].v);
	}
	ans=min(ans,res);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	  cin>>q[i].u>>q[i].v>>q[i].c;
	sort(q+1,q+1+m);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
	  int fu=find(q[i].u),fv=find(q[i].v);
	  if(fu==fv)continue;
	  fa[fu]=fv;
	  ans+=q[i].c;
	  e[0][++len]=q[i];
	}
	e[0][++len]={1,1,(int)1e16};
	for(int i=1;i<=k;++i){
	  cin>>val[i];
	  for(int j=1;j<=n;++j){
		e[i][j].v=j,e[i][j].u=n+i;
		cin>>e[i][j].c;
	  }
	  sort(e[i]+1,e[i]+1+n);
	}
	int limit=(1<<k);
	for(int s=1;s<limit;++s)solve(s);
	cout<<ans<<"\n";
//	cerr<<"Time :"<<clock()/1.0/CLOCKS_PER_SEC*1000.0<<" ms\n";
	return 0;
}
/*
首先是只保留原图最小生成树上的边

枚举重建了的乡村的子集

提前按权值从小到大排好，处理的时候把所有当前要用的点都扫一边看加哪个

复杂度 O(n k 2^k a(n))

最后几个点似乎会被卡常。 
*/