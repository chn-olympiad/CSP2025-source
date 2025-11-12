#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10+10,M=1e6+1e5+10;
int n,m,k;long long sum;
struct node{
	long long u,v,w;
	friend bool operator<(const node &p,const node &q){
		return p.w<q.w;
	}friend bool operator>(const node &p,const node &q){
		return p.w>q.w;
	}
};
multiset<node>s;
int fa[N];
int coun[15][N],c[15];
void init(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
}int _find(int x){
	if(fa[x]==x)return x;
	return fa[x]=_find(fa[x]);
}void _merge(int x,int y){
	int fx=_find(x);
	int fy=_find(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
}long long kruskal(){
	long long ans=0,cnt=0;
	auto it=s.begin();
	for(int i=1;i<=m;i++){
		int fx=_find((*it).u);
		int fy=_find((*it).v);
		if(fx!=fy){
			_merge((*it).u,(*it).v);
			cnt++;
			ans+=(*it).w;
		}
		it++;
		if(cnt==m-1)break;
	}return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	init();
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		s.insert({u,v,w});
	}for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)scanf("%lld",&coun[i][j]);
	}auto kk=s.begin();
	
	sum=kruskal();
	int res=0;
	for(int i=1;i<=k;i++){
		init();
		res+=c[i];
		for(int j=1;j<=n;j++){
			s.insert({i+n,j,coun[i][j]});
			//a[m+j].u=i+n;
			//a[m+j].v=j;
			//a[m+j].w=coun[i][j];
		}
		m+=n;
		auto kk=s.begin();
		sum=min(sum,kruskal()+(long long)res);
	}cout<<sum;
	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
