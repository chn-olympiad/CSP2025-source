#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int xx = 1e5+10,N=1e6+10;
struct node{
	int u,v,w;
}e[10*N];
int fa[xx];
int n,m;
ll ans;
bool cmp(node a,node b){
	return a.w < b.w;
}
int Find(int x){
	if(fa[x] == x)return x;
	else return fa[x] = Find(fa[x]);
}
int k;
void build(){
	int cnt = 0;
	for(int i=1;i<=m;i++){
		int fx = Find(e[i].u);
		int fy = Find(e[i].v);
		if(fx != fy){
			fa[fx] = fy;
			ans+=e[i].w;
			cnt++;
		}
		if(cnt == n+k-1){
			cout << ans ;
			exit(0);
		}
	}
}

int a[20];
int len;
struct pp{
	int u,v,w;
}p[xx*10];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;;
	for(int i=1;i<=m;i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for(int i=n+1;i<=n+k;i++){
		cin >> a[i];
		for(int x,j=1;j<=n;j++){
			cin >> x;
			e[++m].w = x+a[i];
			e[m].u = i;
			e[m].v = j;
		}
	}
	for(int i=1;i<=n+k;i++)fa[i] = i;
	sort(e+1,e+m+1,cmp);
	build();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
