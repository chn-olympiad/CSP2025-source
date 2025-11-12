#include <bits/stdc++.h>
using namespace std;

int val[100005][3];
int n;

//void solve() {
//	memset(val, 0, sizeof(val));
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < 3; j++) {
//			int tmp;
//			scanf("%d", &tmp);
//			val[i][j] = tmp;
//		}
//	}
//	int dp[n+1][3];
//	memset(dp,0,sizeof(dp));
//	int cnt[3]={0,0,0};
//	for(int i = 1,i<n+1;i++){
//		for(int j = 0;j<3;j++){
//			if(cnt[j]>(n/2))
//				continue;
//			if()
//		}
//	}
//
//	return ;
//}

//string err("get\n");


int MAX = -1;

void dfs(int i = 0, int cntA = 0, int cntB = 0, int cntC = 0, int AAA = 0) {
//	cout << i ;
	if (i >= n) {
		MAX = max(MAX, AAA);
//		cout << "get\n";
		return ;
	}
//	int cur = 0;
	if (cntA <= (n / 2)) {
//		cur = max(dfs(i + 1, cntA + 1, cntB, cntC) + val[i][0], cur);
		dfs(i + 1, cntA + 1, cntB, cntC, AAA + val[i][0]);
//		cout << AAA + val[i][0];
	}
	if (cntB <= (n / 2)) {
//		cur = max(dfs(i + 1, cntA, cntB + 1, cntC) + val[i][1], cur);
		dfs(i + 1, cntA, cntB + 1, cntC, AAA + val[i][1]);
//		cout << AAA + val[i][1];
	}
	if (cntC <= (n / 2)) {
//		cur = max(dfs(i + 1, cntA, cntB, cntC + 1) + val[i][2], cur);
		dfs(i + 1, cntA, cntB, cntC + 1, AAA + val[i][2]);
//		cout << AAA + val[i][2];
	}
	return ;
}


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int T;
	scanf("%d", &T);
	while (T--) {
		memset(val, 0, sizeof(val));
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				int tmp;
				scanf("%d", &tmp);
				val[i][j] = tmp;
			}
		}
//		memset(cnt, 0, sizeof(cnt));
//		int MAX = 0;
//		MAX = max(dfs(0, 0, 0, 0,0), MAX);
//		MAX = max(dfs(0, 0, 0, 0,0), MAX);
//		MAX = max(dfs(0, 0, 0, 0,0), MAX);
		MAX = -1;
		dfs(0, 0, 0, 0, 0);
		cout << MAX;

	}


	return 0;
}