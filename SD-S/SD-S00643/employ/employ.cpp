#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,m,cnt;
int s[15],c[15],_rank[15];
bool vis[15];

bool cheak() {
	int fail = 0;
	for (int i = 1;i <= n;i ++) {
		if (s[i] == 0)
			fail ++;
		else if (fail >= c[_rank[i]]) 
			fail ++;
	}
	return (n-fail) >= m;
}

void dfs(int x) {
	for (int i = 1;i <= n;i ++) {
		if (!vis[i]) {
			_rank[x] = i;
			if (x == n) {
				if (cheak()) cnt = (cnt + 1) % mod;
			}
			else {
				vis[i] = true;
				dfs(x+1);
				vis[i] = false;
			}
		}
	}
	return ;
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i ++) {
		scanf("%1d",&s[i]);
	}
	for (int i = 1;i <= n;i ++) {
		scanf("%d",&c[i]);
	}
	dfs(1);
	printf("%d\n",cnt);
	return 0;
}

