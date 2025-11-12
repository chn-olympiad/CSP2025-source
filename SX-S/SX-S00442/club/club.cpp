#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


struct manyidu {
	int num, val;
};

inline int cmp1(manyidu a, manyidu b) {
	return (a.val > b.val);
}

inline int cmp2(vector<manyidu> a, vector<manyidu> b) {
	return a[0].val > b[0].val;
}

void run() {
	int n, s;
	vector<vector<manyidu>> stu(100005, vector<manyidu>(3));
	vector<vector<int>> dp(100005, vector<int>(4, 0));
	scanf("%d", &n);
	s = n / 2;

	for (int i = 1; i <= n; i++) {
		stu[i][0].num = 0;
		stu[i][1].num = 1;
		stu[i][2].num = 2;
		scanf("%d %d %d", &stu[i][0].val, &stu[i][1].val, &stu[i][2].val);
		sort(stu[i].begin(), stu[i].begin() + 3, cmp1);
	}
	sort(stu.begin() + 1, stu.begin() + n + 1, cmp2);

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (dp[i][stu[i][0].num] < s) {
			dp[i][stu[i][0].num]++;
			dp[i][3] += stu[i][0].val;
		} else {
			dp[i][stu[i][1].num]++;
			dp[i][3] += stu[i][1].val;
			dp[i][3] = max(dp[i][3], dp[i - 1][3] - stu[i - 1][0].val + stu[i - 1][1].val + stu[i][0].val);
		}
	}
	printf("%d\n", dp[n][3]);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int _ = 0; _ < t; _++) {
		run();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
