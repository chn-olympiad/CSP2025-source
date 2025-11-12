#include <bits/stdc++.h>
#define int long long
#define N 10005
#define M 1000005
using namespace std;
struct edge{int a,b,w;};
edge e[M * 2];
int c[15];
int a[15][N];
int fa[N];
int n,m,k;
bool cmp(edge a,edge b){
	return a.w < b.w;
}
int find(int x){
	if (fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}
void solve_0(){
	sort(e + 1,e + m + 1,cmp);
	int cnt = 0,sum = 0;
	for (int i = 1;i <= n;i++) fa[i] = i;
	for (int i = 1;i <= m && cnt < n - 1;i++){
		int a = find(e[i].a);
		int b = find(e[i].b);
		if (a == b) continue;
		sum += e[i].w;
		fa[a] = b;
		cnt++;
	}
	printf("%lld",sum);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for (int i = 1;i <= m;i++){
		scanf("%lld%lld%lld",&e[i].a,&e[i].b,&e[i].w);
	}
	int github = 1;
	for (int i = 1;i <= k;i++){
		scanf("%lld",&c[i]);
		if (c[i] != 0) github = 0;
		int t = 1;
		for (int j = 1;j <= n;j++){
			scanf("%lld",&a[i][j]);
			if (a[i][j] == 0){
				t = 0;
			}
		}
		if (t == 1) github = 0;
	}
	if (k == 0) solve_0();
	if (github == 1){//处理：增加节点
		for (int i = 1;i <= k;i++){
			for (int j = 1;j <= n;j++){
				++m;
				e[m].a = i + n;
				e[m].b = j;
				e[m].w = a[i][j];
			}
		}
		n += k;
		solve_0();
	}
	
return 0;
}
