#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 2e4 + 100, M = 2e6 + 100;
struct edge{
	long long u, v, w;
	bool flag;
	bool operator < (const edge& x){
		if(w == x.w) return flag < x.flag;
		return w < x.w;
	}
} a[M];
long long n, m, k, f[N], c[50];

bool check(){
	bool flag = true;
	int x = f[1];//cout<<x<<" ";
	for(int i = 2; i <= n; i++){
		if(f[i] != x){
			flag = false;
			break;
		}
	}
	return !flag;
}

int main(){
	
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++){
		long long x, y, z;
		cin >> x >> y >> z;
		a[i] = {x, y, z, false};
	}
	
	long long tot = m;
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			long long x;
			cin >> x;
			a[++tot] = {i + n, j, x, true};
		}
	}
	
	sort(a + 1, a + 1 + tot);
	
	long long s = n, i = 1, ans = 0;
	while(s > 1){
		if(f[a[i].u] == f[a[i].v]){
			i++;
		}else{
			f[a[i].u] = f[a[i].v];
			if(f[a[i].u] <= n && f[a[i].v] <= n) s--; 
			ans += a[i].w;
			i++;
		}
	}
	cout << ans << "\n";
	
	return 0;
}
