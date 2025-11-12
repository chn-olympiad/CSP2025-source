#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int n,m,k;
int f[N];
struct node {
	int u,v,w;
	bool operator<(const node &t) const {
		return w<t.w;
	}
} road[N];
int Find(int x) {
	if(f[x] == x) return x;
	return f[x] = Find(f[x]);
}
int a[15][10010];
int c[15];
int type = 0;

void solvea() {
	for(int i = 1; i<=k; i++) {
		for(int j = 1; j<=n; j++) {
			road[++m] = {i+n,j,a[i][j]};
		}
	}
	for(int i = 1; i<=n+k; i++) f[i] =i;
	sort(road+1,road+1+m);
	long long ans = 0;
//	cout<<road[1].w<<" here"<<endl;
	for(int i = 1; i<=m; i++) {
		int u = road[i].u;
		int v = road[i].v;
		int w = road[i].w;
		int fu = Find(u);
		int fv = Find(v);
		if(fu == fv) continue;
		f[fv] = fu;
		ans+=w;
	}

	printf("%lld",ans);
}

long long res;
void solve(int sta) {
	long long ans = 0;
	for(int i = 1; i<=k; i++) {
		if(sta&(1<<i-1)) {
			ans+=c[i];
			for(int j = 1; j<=n; j++) {
				road[++m] = {i+n,j,a[i][j]};
			}
		}
	}
	for(int i = 1; i<=n+k; i++) f[i] =i;
	sort(road+1,road+1+m);
	
//	cout<<road[1].w<<" here"<<endl;
	for(int i = 1; i<=m; i++) {
		int u = road[i].u;
		int v = road[i].v;
		int w = road[i].w;
		int fu = Find(u);
		int fv = Find(v);
		if(fu == fv) continue;
		f[fv] = fu;
		ans+=w;
	}

	res = min(res,ans);

}



int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i<=m; i++) {
		scanf("%d%d%d",&road[i].u,&road[i].v,&road[i].w);
	}
	for(int i = 1; i<=k; i++) {
		scanf("%d",&c[i]);
//		cout<<c[i]<<endl;
		if(c[i]!=0) type = 1;
		for(int j = 1; j<=n; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	if(!type) {
		solvea();
		return 0;
	}
	res = 1e18;
	for(int sta = 0; sta<(1<<k); sta++) {
		solve(sta);
	}
	printf("%lld",res);



	fclose(stdin);
	fclose(stdout);
	return 0;
}
