/*
T4 employ
 n 人应聘，录用至少 m 人。
每天面试一个人,选择一个 1 ～ n 的排列 p，
第 i (1 ≤ i ≤ n) 天通知编号为 pi前来面试。
n 套难度不一的面试题
对于同一套题，所有人的作答结果是一致的。
具体地，第 i (1 ≤ i ≤ n) 天的面试题的难度为 si ∈ {0, 1}，
其中 si = 0 表示这套题的难度较高，没有人能够做出
si = 1 表示所有人均能做出。
小 H 会根据面试者的作答结果决定是否录用，即如
果面试者没有做出面试题，则会拒绝，否则会录用。
具体地，编号为 i (1 ≤ i ≤ n) 的人的耐心上限可以用非负整数 ci
描述，若在他之前>=ci 人被拒绝或放弃参加面试，则他也将放弃参加面试。
小 Z 想知道一共有多少种面试的顺序 p 能够让他们录用至少 m 人。你需要帮助小
Z 求出，能够录用至少 m 人的排列 p 的数量。由于答案可能较大，你只需要求出答案
对 998, 244, 353 取模后的结果。

*/
#include <bits/stdc++.h>
using namespace std;
#define _for(i, a, b) for(int i = (a); i <= (b); ++i)
#define _rfo(i, a, b) for(int i = (a); i >= (b); --i)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFO(i, a, b) for(int i = (a); i > (b); --i)
using LL = long long;
using VI = vector<int>;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, ans = 0;
	string s;
	cin >> n >> m >> s;
	VI C(n), P(n), T(n);
	for (int &c : C)
		cin >> c;
	iota(begin(P), end(P), 0);
	do {
		FOR(i, 0, n) T[i] = C[P[i]];
		int res = 0;
		FOR(i, 0, n) if (s[i] == '0' || res >= T[i])
			++res;
		ans += (res <= n - m);

	} while (next_permutation(begin(P), end(P)));
	cout << ans;
	return 0;
}