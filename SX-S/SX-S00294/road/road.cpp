#include <bits/stdc++.h>
#define pii std::pair<int,int>
using namespace std;
typedef long long ll;
const int N = 2000050;
struct edge {
	ll u,v,w;
}input[N],e[N],rese[N],temp[N],t[11][100050];
ll cost[11];
bool operator < (const edge& a,const edge& b) {
	return a.w<b.w;
}
int n,m,s;
int fa[N];
int getroot(int x){return fa[x]==x?x:fa[x]=getroot(fa[x]);}
void merge(int x,int y) {
	int rx=getroot(x);
	int ry=getroot(y);
	if(rx!=ry) fa[rx]=ry;
}
ll buildcost;
ll buildcnt;
ll ans=1e18;
ll Kruscal(edge* edgearr,int nodecnt,int edgecnt) {
	std::sort(edgearr+1,edgearr+edgecnt+1,[](edge x,edge y){
		return x.w<y.w;
	});
	for(int i=1;i<=nodecnt+s;i++) fa[i]=i;
	ll res=0,pos=0;
	for(int i=1;i<=edgecnt;i++) {
		edge now=edgearr[i];
		if(getroot(now.u)==getroot(now.v)) continue;
		rese[++pos]=edgearr[i];
		res+=now.w;
		merge(now.u,now.v);
	}
	return res;
}

void dfs(int step,int nowcnt) {
	if(step==s+1) {
		for(int i=1;i<=nowcnt;i++) temp[i]=e[i];
		ans=min(ans,buildcost+Kruscal(temp,n+buildcnt,nowcnt));
		return;
	}
	dfs(step+1,nowcnt);
	++buildcnt;
	buildcost+=cost[step];
	for(int i=1;i<=n;i++) {
		e[nowcnt+i]=t[step][i];
	}
	dfs(step+1,nowcnt+n);
	--buildcnt;
	buildcost-=cost[step];
}

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		input[i]={u,v,w};
	}
	for(int i=1;i<=s;i++) {
		cin>>cost[i];
		for(int j=1;j<=n;j++) {
			int w;
			cin>>w;
			t[i][j]={n+i,j,w};
		}
	}
	int sfdgdsfgsdfg=Kruscal(input,n,m);
	for(int i=1;i<=n-1;i++) e[i]=rese[i];
	dfs(1,n-1);
	cout<<ans;
	return 0;
}
