#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 100005; // 人数最大值
const int INF = 1145141919;  // 然而并无卵用 

int n = 0, ans = 0;
int a[MAX][3];

void dfs(int idx, int num1, int num2, int num3, int val) {
	if (idx > n) return ;
	if (num1 < n / 2) {
		ans = max(ans, val + a[idx][0]);
		dfs(idx + 1, num1 + 1, num2, num3, val + a[idx][0]);
	}
	if (num2 < n / 2) {
		ans = max(ans, val + a[idx][1]);
		dfs(idx + 1, num1, num2 + 1, num3, val + a[idx][1]);
	}
	if (num3 < n / 2) {
		ans = max(ans, val + a[idx][2]);
		dfs(idx + 1, num1, num2, num3 + 1,val + a[idx][2]);
	}

	return ;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		ans = 0;

		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}

		dfs(1, 0, 0, 0, 0);

		cout << ans << endl;
	}

	return 0;
}

/*

dp[i][j]
前面 i 个人里
第 i 个人给j部门的最大值

方程
dp[i][j] = max(dp[i - 1][0] + a[i][j],
	max(dp[i - 1][1] + a[i][j], dp[i - 1][2] + a[i][j]));

怎么处理部门满员的情况？
再开一个num[MAX][3]
num[i][j]为
当dp[i-1][j] 后 j 部门的人数
在dp后记录， 即
dp[i][0] = ...
num[i][0] = num[i - 1][0] + 1;?????

好像没法dp
带了限制条件
还是dfs吧；

dfs(idx, num1, num2, num3, val):
if (idx > n) return
if (num1 < n / 2)
	ans = max(ans, val + a[idx][0])
	dfs(idx+1, num1+1, num2, num3, val+a[idx][0])


---
14:30 - 15:10
40min 贪心失败
然后想起来 T1 应该是dp
花了两分钟推出来公式

30min dp失败
有限制条件，不会dp了
nnd暴力大法好
我爱暴力

10min 暴力结束
想不到正解
（大杯 
*/
