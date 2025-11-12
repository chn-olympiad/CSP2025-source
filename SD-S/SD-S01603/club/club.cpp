// SD-S01603

#include <bits/stdc++.h>

using namespace std;

inline int read () {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	
	return x * f;
}

const int N = 1e5 + 10;

struct S1 {
	int id, num, to;
	bool operator < (const S1 &ex) const {
		return num > ex.num;
	}
};

struct S2 {
	int tn, num;
} a[N][4];

inline bool cmp (S2 a, S2 b) {
	return a.num > b.num;
}

priority_queue <S1> q[4];

int T, n, cnt[4];

inline void work_Block2 () {
	n = read();
	long long ans = 0;
	
	cnt[1] = cnt[2] = cnt[3] = 0;
	int lim = n >> 1;
	while (!q[1].empty()) q[1].pop();
	while (!q[2].empty()) q[2].pop();
	while (!q[3].empty()) q[3].pop();
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j) {
			a[i][j].num = read();
			a[i][j].tn = j;
		}
		
		sort (a[i] + 1, a[i] + 3 + 1, cmp);
	}
	
	for (int i = 1; i <= n; ++i) {
		int tn1 = a[i][1].tn, vl1 = a[i][1].num,
			tn2 = a[i][2].tn, vl2 = a[i][2].num;
		
		int cost = vl1 - vl2;
		
		if (cnt[tn1] >= lim) {
			auto nya = q[tn1].top();
			if (nya.num < cost) {
				q[tn1].pop();
				q[nya.to].push(S1{nya.id, 114, 514});
				q[tn1].push(S1{i, cost, tn2});
				ans = ans - nya.num + vl1;
				cnt[nya.to] ++;
//				printf("Case1\n");
			} else {
				q[tn2].push(S1{i, 114, 514});
				ans = ans + vl2;
				cnt[tn2] ++;
//				printf("Case2\n");
 			}
		} else {
			q[tn1].push(S1{i, cost, tn2});
			ans = ans + vl1;
			cnt[tn1] ++;
//			printf("Neutral\n");
		}
	}
	
	printf("%lld\n", ans);
}

signed main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	T = read();
	while (T --) work_Block2();
	
	return 0;
}

// Block 1.
// 反悔贪心？
// 考虑每次将人添加到好感度最高的社团，如果人数超限就把好感度最低的踢出去
// 不会证。但是我猜T1不会放巨大容斥dp。 
// 2e9 不会爆 int
// 我觉得不太对。无法通过第三组样例。 

// Block 2.
// 注意到一个人最多只会被踢一次。 
// 这样一定有至少 n/2 的人可以选择好感度第一的社团 
// 开 dp[i] 记录有 i 个人被迫选择好感度第二的社团时的最大和 ..?
// 即有 i 个人选第二个，剩下 n-i 个人选第一个 
// 但是转移是n方的。考虑优化 i。
// 还是可以反悔贪心。每加一个人踢出当前移到第二个选择代价最小的。
// 我觉得证明显然。 

// 15:18 大样例全部通过。 
// 保险起见 ans 还是开 longlong 吧。 
