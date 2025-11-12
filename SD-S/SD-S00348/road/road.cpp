#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int M = 1e6+3,N = 1e4+3,K = 10+3;
struct edge{
	int u,v,w;
}e[2*M];
int cnt;
int a[K][N],c[K];
void add(int u,int v,int w){
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].w = w;
}
int n,m,k;
ll ans;
ll kr[N],fa[N],tot;
int d[N];
bool cmp(edge x,edge y){
	return x.w < y.w;
}
int found(int x){
	if (fa[x] == x)  return x;
	return fa[x] = found(fa[x]);
}
ll kru(){
	ll ret = 0;
	for (int i = 1;i <= n;i++)  fa[i] = i;
	sort(e+1,e+2*m+1,cmp);
	for (int i = 1;tot < n-1;i++){
		int u = e[i].u,v = e[i].v,w = e[i].w;
		int fau = found(u),fav = found(v);
		if (fau == fav)  continue;
		fa[fau] = fav;
		ret += w;
		kr[++tot] = i;
	}
	return ret;
}
void dfs(int now,ll num,int dis[]){
	if (now > k){
		for (int i = 1;i < n;i++)  num += dis[i];
		ans = min(ans,num);
		return ;
	}
	dfs(now+1,num,dis);
	for (int i = 1;i < n;i++){
		int u = e[i].u,v = e[i].v;
		dis[i] = min(dis[i],a[now][u]+a[now][v]);
	}
	dfs(now+1,num+c[now],dis);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>k;
	for (int i = 1,u,v,w;i <= m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for (int i = 1;i <= k;i++){
		cin>>c[i];
		for (int j = 1;j <= n;j++){
			cin>>a[i][j];
		}
	}
	ans = kru();
//	for (int i = 1;i < n;i++)  d[i] = e[kr[i]].w;
//	dfs(1,0,d);
	cout<<ans;
	
	return 0;
}
