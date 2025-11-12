//Flandre Scarlet
//I hate my trash codes
#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
struct member {
	int a[3];
	
	int max_val() {
		return max(a[0], max(a[1], a[2]));
	}
	
	int sum() {
		return a[0] + a[1] + a[2];
	}
}mb[MAXN];
int t, n;
bool aflag;
struct state {
	int v;
	int num[3];
	
	bool operator<(state s) const {
		return this -> v < s.v;
	}
	
	bool operator>(state s) const {
		return this -> v > s.v;
	}
	
	bool operator==(state s) const {
		return this -> v == s.v;
	}
}dp[MAXN][3];
bool cmp(member m1, member m2) {
	return m1.max_val() > m2.max_val() || 
		(m1.max_val() == m2.max_val() && m1.sum() > m2.sum());
}
bool acmp(member m1, member m2)  {
	return m1.a[0] > m2.a[0];
}
int solve() {
	dp[1][0].v = mb[1].a[0], dp[1][0].num[0] = 1;
	dp[1][1].v = mb[1].a[1], dp[1][1].num[1] = 1;
	dp[1][2].v = mb[1].a[2], dp[1][2].num[2] = 1;
	
	for(int i = 2; i <= n; i++) {
		for(int j = 0; j <= 2; j++) {
			state tmp;
			tmp.v = INT_MIN;
			for(int k = 0; k <= 2; k++) {
				if(dp[i-1][k].num[j] < n / 2) {
					tmp = max(tmp, dp[i-1][k]);
				}
			}
			dp[i][j] = tmp;
			dp[i][j].v += mb[i].a[j];
			dp[i][j].num[j]++;
		}
	}
	
	return max(dp[n][0].v, max(dp[n][1].v, dp[n][2].v));
}
struct numset {
	int num[3];
	
	int get(int index) {
		return num[index];
	}
	
	numset() {
		num[0] = num[1] = num[2] = 0;
	}
};
int dfs(int d, int lastv, numset &nums) {
	if(d > n) {
		return lastv;
	}
	
	int result = INT_MIN;
	
	for(int i = 0; i <= 2; i++) {
		if(nums.get(i) >= n / 2) {
			continue;
		}
		nums.num[i]++;
		result = max(result, dfs(d + 1, lastv + mb[d].a[i], nums));
		nums.num[i]--;
	}
	
	return result;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		aflag = true;
		for(int i = 1; i <= n; i++) {
			int a1, a2, a3;
			scanf("%d%d%d", &a1, &a2, &a3);
			mb[i].a[0] = a1;
			mb[i].a[1] = a2;
			mb[i].a[2] = a3;
			if(a2 != 0 || a3 != 0) {
				aflag = false;
			}
		}
		
		if(aflag) {
			int ans = 0;
			sort(mb+1, mb+n+1, acmp);
			for(int i = 1; i <= n / 2; i++) {
				ans += mb[i].a[0];
			}
			printf("%d\n", ans);
			continue;
		}
		
		if(n <= 10) {
			printf("%d\n", dfs(1, 0, *new numset()));
		} else {
			sort(mb + 1, mb + n + 1, cmp);
			printf("%d\n", solve());
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
