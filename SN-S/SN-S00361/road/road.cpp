#include <bits/stdc++.h>
using namespace std;
const int A = 998244353;
struct S {
	int s , e , v;
}a[3000050];
int cnt;
int b[20][10050];
int c[20];
int root[3000050];
bool cmp(S x , S y) {
	if(x.v != y.v)return x.v < y.v;
	if(x.s != y.s)return x.s < y.s;
	return x.e <= y.e;
}
int main() {
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n , m , k;
	cin >> n >> m >> k;
	cnt = m;
	for(int i = 1; i <= n; i++)
		root[i] = i;
	for(int i = 1; i <= m; i++) {
		cin >> a[i].s >> a[i].e >> a[i].v;
	}
	for(int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		for(int j = 1; j <= n; j++) {
			cin >> b[i][j];
		}
	}
	for(int i = 1; i <= k; i++) {
		for(int j = 1; j <= n; j++) {
			if(b[i][j] == 0) {
				c[i] = j;
				break;
			}
		}
		for(int j = 1; j <= n; j++) {
			a[++cnt].s = c[i];
			a[cnt].e = j;
			a[cnt].v = b[i][j];
		}
	}
	long long ans = 0;
	sort(a + 1 , a + cnt + 1 , cmp);
	for(int i = 1; i <= cnt; i++) {
		while(root[root[a[i].s]] != root[a[i].s])root[a[i].s] = root[root[a[i].s]];
		while(root[root[a[i].e]] != root[a[i].e])root[a[i].e] = root[root[a[i].e]];
		if(root[a[i].s] == root[a[i].e])continue;
		ans += a[i].v;
		root[a[i].e]= root[a[i].s]; 
	}
	cout << ans;
	return 0;
}
