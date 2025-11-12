#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
const int N = 1e5 + 5;
int n, m, k, ans, c[N], fa[N], siz[N], now[N];
inline int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int a,int b){
	if(siz[a]>siz[b])fa[b]=a,siz[a]+=siz[b];
	else fa[a]=b,siz[b]+=siz[a];
}
struct edge{
	int u,v,w;
	bool operator < (const edge x)const{
		return w>x.w;
	}
};
priority_queue < pair<edge,int> > q;
edge tmp;
vector <edge> v[N];
bool cmp(edge x, edge y){
	return x.w<y.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&tmp.u,&tmp.v,&tmp.w);
		v[0].push_back(tmp);
	}
	sort(v[0].begin(),v[0].end(),cmp);
	for(int i=1;i<=k;i++){
		scanf("%lld",c+i);
		for(int j=1,w;j<=n;j++){
			scanf("%lld",&w);
			tmp.u=n+i,tmp.v=j,tmp.w=w;
			v[i].push_back(tmp);
		}
		sort(v[i].begin(),v[i].end(),cmp);
	}
	ans=4e18;
	for(int S=0;S<(1<<k);S++){
		int res=0;
		for(int i=0;i<k;i++){
			if((S&(1<<i))!=0)res+=c[i+1];
		}
		for(int i=0;i<=k;i++){
			if(i!=0&&(S&(1<<i-1))==0)continue;
			now[i]=0;
			q.push({v[i][0],i});
		}
		int cnt=0;
		for(int i=1;i<=n+k;i++){
			fa[i]=i,siz[i]=1;
		}
		int tot=n+__builtin_popcount(S);
		while(cnt<tot-1){
			pair <edge,int> u=q.top();
			q.pop();
			
			now[u.S]++;
			if(now[u.S]<v[u.S].size())
			q.push({v[u.S][now[u.S]],u.S});
			
			int fu=find(u.F.u),fv=find(u.F.v);
			if(fu!=fv){
				merge(fu,fv);
				cnt++;
				res+=u.F.w;
			}
		}
		while(q.size())q.pop();
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}

