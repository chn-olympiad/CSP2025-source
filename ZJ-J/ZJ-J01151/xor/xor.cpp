#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, mid, x, y, idx, a[N], b[N], d[N], v[N];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i], b[i] = b[i - 1] ^ a[i], v[i] = -1;
	if (n <= 1000){
		for (int i = 1; i <= n; i ++){
			for (int j = i; j <= n; j ++){
				if ((b[j] ^ b[i - 1]) == m) v[j] = i;
			}
		}
		for (int i = 1; i <= n; i ++){
			d[i] = d[i - 1];
			if (v[i] != -1) d[i] = max(d[i - 1], d[v[i] - 1] + 1); 
		}
		cout << d[n];
	}
	else {
		for (int i = 1; i <= n; i ++){
			int y = m ^ b[i];
			if (mp[y]) v[i] = mp[y] + 1;
			else v[i] = -1;
			mp[b[i]] = i;
		}
		for (int i = 1; i <= n; i ++){
			d[i] = d[i - 1];
			if (v[i] != -1) d[i] = max(d[i - 1], d[v[i] - 1] + 1); 
			//cout << v[i] << " ";
		}
		cout << d[n];
	}
	return 0;
}
