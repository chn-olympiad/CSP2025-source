//刘泽辰 SN-S00070 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
const int N = 300;
int a[3*N], u[N], v[N], w[N], s[3*N];
bool vis[3*N], used[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n, m, cnt=0, numu=0, numv=0, numw=0, sum=0;
		bool flag = false;
		cin >> n;
		m = n/2;
		memset(u, 0, sizeof(u));
		memset(v, 0, sizeof(v));
		memset(w, 0, sizeof(w));
		memset(s, 0, sizeof(s));
		memset(vis, false, sizeof(vis));
		memset(used, false, sizeof(used));
		for (int i = 1; i <= n; i++) {
			cin >> u[i] >> v[i] >> w[i];
		}
		for (int i = 1; i <= n; i++) {
			s[i] = u[i];
			s[i+n] = v[i];
			s[i+n+n] = w[i];
		}
		sort(s+1, s+n+n+n+1);
		reverse(s+1, s+n+n+n+1);
		int pos = 1;
		for (int i = 1; i <= 3*n; i++) {
			if (!vis[s[i]]) {
				vis[s[i]] = 1;
				a[pos++] = s[i];
			}
		}
		for (int i = 1; i < pos; i++) {
			for (int j = 1; j <= n; j++) {
				if (sum == n) {
					flag = true;
					break;
				}
				if (u[j] == a[i] && numu < m && !used[j]) {
					numu++;
					cnt += u[j];
					used[j] = true;
				}
				if (v[j] == a[i] && numv < m && !used[j]) {
					numv++;
					cnt += v[j];
					used[j] = true;
				}
				if (w[j] == a[i] && numw < m && !used[j]) {
					numw++;
					cnt += w[j];
					used[j] = true;
				}
			}
			if (flag == true) break;
		}
		cout << cnt << "\n";
	}
	return 0;
}
