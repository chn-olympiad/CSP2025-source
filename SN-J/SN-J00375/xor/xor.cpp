// 张洛川 高新第二初级中学 SN-J00375 
#include<bits/stdc++.h>
using namespace std;

const int N = 5005;
int n, k, ret = 0;
int a[N];

void dfs(int id) {
	if (id > n) {
		return;
	}
	int cnt = a[id];
	if (cnt == k) {
		ret++;
		dfs(id+1);
	} else {
		int flag = 1;
		for (int i = id+1; i <= n; i++) {
			cnt = cnt ^ a[i];
			if (cnt == k) {
				flag = 0;
				ret++;
				dfs(i+1);
				break;
			}
		}
		if (flag == 1) {
			dfs(id+1);
		}
	}
}


int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	dfs(1);
	printf("%d\n", ret);
	return 0;
}
