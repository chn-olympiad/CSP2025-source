#include<bits/stdc++.h>
using namespace std;
int n, m, k, Bing[10015];
struct Edge{
	int u, v, val;
}e[1100005];
struct Vil{
	int a[10015], val;
}v[11];
int Find(int x) {
	if(Bing[x] == x) return x;
	else return Bing[x] = Find(Bing[x]);
}
bool cmp(Edge a, Edge b) {
	return a.val < b.val;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d",&e[i].u, &e[i].v, &e[i].val);
	}
	if(k==0) {
		for(int i = 1; i <= n; i++)
			Bing[i] = i;
		sort(e+1, e+1 + m, cmp);
		long long Sum = 0, ans = 0;
		for(int i = 1; ; i++) {
			if(Sum == n - 1)break;
			if(Find(e[i].u) != Find(e[i].v)) {
				Bing[Find(e[i].u)] = Bing[Find(e[i].v)];
				ans += e[i].val;
				Sum++;
			}
		}
		cout << ans;
	}
	else {		
		for(int i = 1; i <= k; i++) {
			cin >> v[i].val;
			for(int j = 1; j <= n; j++) {
				cin >> e[m+1+(i-1)*n+j].val;
				e[m+1+(i-1)*n+j].u = j;
				e[m+1+(i-1)*n+j].v = n + i;
			}
		}
		for(int i = 1; i <= n + k; i++)
			Bing[i] = i;
		sort(e+1, e+1 + m + n * k, cmp);
		long long Sum = 0, ans = 0;
		for(int i = 1; ; i++) {
			if(Sum == n + k - 1)break;
			if(Find(e[i].u) != Find(e[i].v)) {
				Bing[Find(e[i].u)] = Bing[Find(e[i].v)];
				ans += e[i].val;
				Sum++;
			}
		}
		cout << ans;
	}
	return 0;
} 
/*
4 5 2
1 2 3
1 3 2
2 3 1
2 4 1
3 4 2
0 0 2 2 5
0 1 3 0 5
*/
