#include <bits/stdc++.h>
using namespace std;

/*
T1
似乎是个贪心或背包，一种显然的做法是
先将所有人全部分配至三个所有部门，再每次减去最小的满意度
尝试举反例
以上做法一眼假
考虑DP
一种不难想到的是
DP[I][J][K]表示，1,2,3部门有I,J,K个成员情况下最大值
数据范围N=1E5，则复杂度N*N*N，TLE
考虑观察特殊性质
对于性质A
直接贪心即可，选取前N/2最大的即可
对于性质B
AI3=0
则考虑带悔贪心
遍历过程中算出反悔的代价，当该物品的代价比反悔代价小时，选该物品
考虑J=3
------------------------------
疑似正解：带悔贪心
我们只需要在遍历过程中维护三个优先队列，
记录之前反悔代价的最小值，遍历一个新值时，若不能添加，则选出最小代价，进行反悔
预计CODE时间：40MIN
*/
const int N = 1e5 + 5;
int n, num[5], ans, s[N], T;
struct node {
	int f, t, v, c;
	friend bool operator<(node a, node b) {
		return a.v > b.v;
	}
};
pair<int, int>in[5];
priority_queue<node>q[5];

void choose(int cnt) {
	node tmp;
	int cl = in[3].second;
	s[cnt] = cl;
	num[cl]++;
	ans += in[3].first;
	for (int j = 2; j >= 1; j--) {
		tmp.c = cnt;
		tmp.v = in[3].first - in[j].first;
		tmp.f = cl;
		tmp.t = in[j].second;
		q[cl].push(tmp);
	}
//	if (num[cl] < n / 2) {
//		for (int j = 2; j >= 1; j--) {
//			tmp.c = cnt;
//			tmp.v = in[3].first - in[j].first;
//			tmp.f = cl;
//			tmp.t = in[j].second;
//			q[cl].push(tmp);
//		}
//		num[cl]++;
//		ans += in[3].first;
//		s[cnt] = cl;
//		return;
//	} else {
//		tmp = q[cl].top();
//		while (s[tmp.c] != tmp.f && q[cl].size()) {
//			q[cl].pop();
//			tmp = q[cl].top();
//		}
//		int pay = tmp.v, now = in[3].first - in[2].first;
//		if (pay >= now) {
//			num[in[2].second]++;
//			ans += in[2].first;
//			s[cnt] = in[2].second;
//		} else {
//			s[cnt] = cl;
//			s[tmp.c] = tmp.t;
////			num[tmp.t]++;
//			ans += in[3].first - pay;
//		}
//	}
}

void work(int p) {
	node tmp;
	while (num[p] > n / 2) {
		tmp = q[p].top();
		while (s[tmp.c] != p && q[p].size()) {
			q[p].pop();
			tmp = q[p].top();
		}
		ans -= tmp.v;
		num[p]--;
		s[tmp.c] = tmp.t;
		q[p].pop();
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		ans = 0;
		memset(s, 0, sizeof(s));
		memset(num, 0, sizeof(num));
		scanf("%d", &n);
		for (int i = 1; i <= 3; i++)
			while (q[i].size())
				q[i].pop();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++)
				in[j].second = j;
			scanf("%d%d%d", &in[1].first, &in[2].first, &in[3].first);
			sort(in + 1, in + 4);
//			for (int j = 1; j <= 3; j++)
//				cout << "-" << in[j].first << " " << in[j].second << endl;
			choose(i);
		}
		for (int i = 1; i <= 3; i++)
			if (num[i] > n / 2) {
				work(i);
				break;
			}
		printf("%d\n", ans);
	}
	return 0;
}