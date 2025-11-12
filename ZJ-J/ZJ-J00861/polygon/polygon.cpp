#include <bits/stdc++.h>
using namespace std;
const int N = 5005, Mod = 998244353;
int n, m, cnt;
int a[N], c[N], v[N];
void dfs(int t){
	if (m == t + 1){
		int s = 0, mx = -1;
		for (int i = 1;i <= m;i++){
			s += c[i];
			mx = max(mx, c[i]);
		}if (s > mx * 2)cnt = (cnt + 1) % Mod;
		return;
	}for (int i = 1;i <= n;i++){
		if (!v[i]){
			c[i] = a[i];
			v[i] = true;
			dfs(m + 1);
			v[i] = false;	
		} 
	}
}
signed main(){
//	freopen("polygon.in", "r", stdin);
//	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)cin >> a[i];
	for (m = 3;m <= n;m++){
		dfs(m);
	}cout << cnt;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
