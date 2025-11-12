#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int ctr[4][4] = {{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

int t, n;
int a[MAXN][5];

struct Node {
	int ki, a, b, c;
};

inline int dfs(int m, Node via) {
	if(max(via.a, max(via.b, via.c)) > n / 2) return 0;
	if(m > n) return via.ki;
	int ret = 0;
	for(int i = 1; i <= 3; i++)
		ret = max(ret, dfs(m + 1, (Node){via.ki + a[m][i], via.a + ctr[i][1], via.b + ctr[i][2], via.c + ctr[i][3]}));
	return ret;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &t);
	while(t--) {
		memset(a, 0, sizeof(a));
		
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) 
			for(int j = 1; j <= 3; j++)
				scanf("%d", &a[i][j]);
		
		printf("%d\n", dfs(1, (Node){0, 0, 0, 0}));
	}
	
return 0;
} 