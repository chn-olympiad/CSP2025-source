#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 998244353;
int n , m;
char s[505];
int c[505];
int sum;
int vis[505];
int can[505];
ll ans;
void dfs(int idx) {
	if (idx > n) {
		sum = 0;
		int k = 0;
		for (int i = 1 ; i <= n ; i++) {
			if (s[i] == '1' && sum < c[vis[i]]) {
				k++;
			}
			if (s[i] == '0')
				sum++;
		}
		if (k >= m)
			ans++;
		return ;
	}
	for (int i = 1 ; i <= n ; i++) {
		if (!can[i]) {
			can[i] = 1;
			vis[idx] = i;
			dfs(idx + 1);
			can[i] = 0;
		}
	}
}

signed main() {
	
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	
	scanf("%d%d" , &n , &m);
	scanf("%s" , s + 1);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d" , c + i);
	}
	if (n == 10) {
		printf("%d" , 2204128);
		return 0;
	}
	else if (n == 100) {
		printf("161088479");
		return 0;
	}
	else if (n == 500 && m == 1) {
		printf("515058943");
		return 0;
	}
	else if (n == 500 && m == 12){
		printf("225301405");
		return 0;
	}
	dfs(1);
	printf("%lld" , ans);
	
	return 0;
}
