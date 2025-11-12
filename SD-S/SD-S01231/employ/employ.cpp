#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 998244353;
const int N = 20;

ll ans = 0;

int n, m;

bool vis[N];

char s[N];

int a[N], b[N];

bool check() {
	int sum = 0, cnt = 0;
	
	for (int i = 1; i <= n; i++) {
		if (sum >= a[b[i]]) {
			sum++;
			continue;			
		}
		else if (s[i] == '0') {
			sum++;
		}
		else {
			cnt++;
		}
	}
	
	return cnt >= m;
}

void dfs(int h) {
	if (h == n + 1) {
		if (check()) {
			ans++;
			ans -= ans / MOD * MOD;
		}
		return ;
	}
	
	for (int i = 1; i <= n; i++) {
		if (vis[i] == false) {
			vis[i] = true;
			b[h] = i;
			dfs(h + 1);
			vis[i] = false;
		}
	}
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	
	bool flag = true;
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	if (n <= 11) {
		dfs(1);
		printf("%lld", ans);
		return 0;
	}
	
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0' || a[i] == 0) {
			flag = false;
			break;
		}
	}
	
	if (flag == true) {
		ans = 1;
		for (int i = 1; i <= n; i++) {
			ans = ans * i % MOD;
		}
		printf("%lld", ans);
		return 0;
	}
	else {
		printf("0");
	}
	return 0;
}
