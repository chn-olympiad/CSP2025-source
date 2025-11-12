#include <bits/stdc++.h>
using namespace std;

const int N = 500 + 5;

int n, m;
string s;
int a[N];
int b[N];
int c[N];

int now[N];
bool f[N];
int ans;

void dfs(int de) {
	if (de > n) {
		int res = 0;
		for (int i = 1; i <= n; i++) b[i] = a[i];
		for (int i = 1; i <= n; i++) {
			if (b[i] >= now[i]) {
				for (int j = i; j <= n; j++) b[j]++;
			}
			else if (s[i - 1] == '1') res++;
			else if (s[i - 1] == '0') for (int j = i; j <= n; j++) b[j]++;
		}
		if (res >= m) ans++;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (f[i]) continue;
		now[de] = c[i]; 
		f[i] = 1;
		dfs(de + 1);
		now[de] = 0;
		f[i] = 0;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) if (s[i - 1] == '0') a[i] = 1;
	for (int i = 1; i <= n; i++) a[i] += a[i - 1];
	for (int i = 1; i <= n; i++) cin >> c[i];
	
	dfs(1);
	
	cout << ans;
	
	return 0;
}
