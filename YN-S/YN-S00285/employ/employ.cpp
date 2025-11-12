#include <bits/stdc++.h>
using namespace std;
int a[100];
int has[100];
int ord[100];
bool vis[100];
int n, m, ans = 0;
string tex;

void DFS(int x) {
	if (x > n) {
		int ou = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (tex[i - 1] == '1' && ou < a[ord[i]]) {
				cnt++;
			} else {
				ou++;
			}
		}
		if (cnt >= m) {
			ans++;
		}

	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == false) {
			ord[x] = i;
			vis[i] = true;
			DFS(x + 1);
			ord[x] = 0;
			vis[i] = false;
		}
	}
}


int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> tex;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	DFS(1);
	cout << ans;


	return 0;
}