#include<bits/stdc++.h>
#define cs const

using namespace std;

cs int MAXN = 30;

int n, m;
string s;
int c[MAXN];

int ans;
vector<int> order;

int main() {
#ifndef DEBUG
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#endif
	cin >> n >> m >> s, s = " " + s;
	for (int i = 1; i <= n; ++i)	cin >> c[i];
	order.resize(n), iota(order.begin(), order.end(), 1);
	do {
		int watleremle = 0, accepted = 0;
		for (int i = 1; i <= n; ++i) {
			if (watleremle >= c[order[i - 1]])	{
				watleremle++;
				continue;
			}
			watleremle += (s[i] == '0');
			accepted += (s[i] == '1');
		}
		if (accepted >= m)	ans++;
	} while (next_permutation(order.begin(), order.end()));
	cout << ans;
	return 0;
}
/*
还剩 18min 42s 结束，希望不要挂分。
T1 神秘贪心，不知道对不对，但是过了所有样例，并且自己口胡了证明，用了 1h 10min，有点慢；
T2 【模板】multiset，看似神秘的外表之下是 k = 10 的内心，复杂度 O(2^k \cdot n \log n)，不过也用了 1h 10min；
T3 幸好早上打了 KMP 板子，不然就真坠机了，但是还是只会 O(q \cdot L1) 的暴力，用了 1h，但心态很好；
T4 O(n! \cdot n) 小常数做法，只用了 4min 就写完了，绝对是单位时间拿分最多的时候；
期望得分：100 + 100 + 50 + 8 = 258 pts，显然是被薄纱了，不过场切两个题还是太舒服了。
CSP-S 不重要，CS:GO 最重要，所以明天直接开 GO 庆祝一下阶段性成果！

T3 想了一些优化，比如关于子串，但是并不能优化复杂度。
而且特殊性质 B 打不来。
感觉会是一个神秘的离线，把所有 t 放到自动机里面，然后让 s 去跑，
复杂度就是 O(L1 + L2)，可以通过。
*/