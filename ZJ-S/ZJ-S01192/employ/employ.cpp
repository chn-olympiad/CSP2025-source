#include<bits/stdc++.h>
using namespace std;
int n, m, sum, p[520], ans;
bool flag, vis[520];
const int mod = 998244353;
struct st{
	char dif;
	int emp;
}a[520];
void dfs(int x) {
	if(x == n + 1) {
		int noegg = 0;
		for(int i = 1;i <= n;i++) {
			if(a[i].dif == '0' or a[p[i]].emp <= noegg) {
				noegg++;
			}
		}
		if(n - noegg >= m) {
			ans++;
			ans %= mod;
		}
		return ;
	}
	for(int i = 1;i <= n;i++) {
		if(!vis[i]) {
			vis[i] = true;
			p[x] = i;
			dfs(x + 1);
			vis[i] = false;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].dif;
		if(a[i].dif == '0') {
			sum++;
		}
	}
	for(int i = 1;i <= n;i++) {
		cin >> a[i].emp;
	}
	if(n - sum < m) {
		cout << 0;
		fclose(stdin);
		fclose(stdout);
		return 0;		
	}
	dfs(1);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}