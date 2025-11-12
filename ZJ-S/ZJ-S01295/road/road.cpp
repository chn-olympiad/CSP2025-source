#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const ll N = 1e4+10,INF = 1e18,M = 2e6+5;
int n,m,k;
ll ans;
int vis[N],fa[N],c[N],me[N];
map<pair<int,int>,int> mp;
struct edge{
	int u,v,w,cc;
	bool operator<(const edge& y){
		return w<y.w;
	}
}e[M];
int find(int x){
	if(fa[x]==x)	return fa[x];
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i ++)	fa[i]=i;
	for(int i = 1;i <= m;i ++){
		cin >> e[i].u >> e[i].v >> e[i].w;
		e[i].cc=0;
	}
	for(int i = 1;i <= k;i ++){
		int a;
		cin >> c[i];
		for(int j = 1;j <= n;j ++){
			cin >> a;
			if(i!=j){
				e[++m].u=i,e[m].v=j,e[m].w=a+c[i],e[m].cc=i;
			}else{
				me[i]=a;
			}
		}
	}
	sort(e+1,e+1+m);
	int cnt = 0;
	for(int i = 1;i <= m;i++){
		if(find(e[i].u) != find(e[i].v)){
			fa[find(e[i].u)]=find(e[i].v);
			cnt++;
			ans+=e[i].w;
			if(vis[e[i].cc])
				ans-=c[e[i].cc];
			vis[e[i].cc]=1;
		}
		if(cnt==n-1)	break;
	}
	for(int i = 1;i <= k;i ++){
		if(vis[i]){
			ans+=me[i];
		}
	}
	cout << ans << "\n";
	return 0;
}