/*
T3 replace
给定 n 个字符串二元组，第 i 个(si,1, si,2)，满足|si,1| = |si,2|
定义 s 的替. 换. 如下：
? 对于 s 的某个子串 y，若存在 1 ≤ i ≤ n 满足 y = si,1，则将 y 替换为  si,2。
小 W 提出了 q 个问题，第 j (1 ≤ j ≤ m) 个问题会给定两个不同的字符串 tj,1, tj,2，
她想知道有多少种字符串 tj,1 的替换能够得到字符串 tj,2。两种 s 的替换不同当且仅当
子. 串.
y 的. 位. 置. 不. 同. 或. 用. 于. 替. 换. 的. 二. 元. 组.
(si,1, si,2) 不. 同. ，即 x, z 不同或 i 不同。你需要
回答小 W 提出的所有问题。

*/
#include <bits/stdc++.h>
using namespace std;
#define _for(i, a, b) for(int i = (a); i <= (b); ++i)
#define _rfo(i, a, b) for(int i = (a); i >= (b); --i)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFO(i, a, b) for(int i = (a); i > (b); --i)
using LL = long long;
using VI = vector<int>;
const int NN = 5E6 + 5;
const int NN1 = 2E5 + 5, HH = 100;
string S[NN1];
int H[NN1], P[NN], H1[NN], H2[NN];
struct Trie {
	int cnt;
	struct {
		int ch[26], fail;
		VI ed;
	} T[NN];
	void Insert(string &s, int id) {
		int nw = 0;
		for (char c : s) {
			if (!T[nw].ch[c - 'a'])
				T[nw].ch[c - 'a'] = ++cnt;
			nw = T[nw].ch[c - 'a'];
		}
		T[nw].ed.emplace_back(id);
	}
	void GetFail() {
		queue<int> Q;
		FOR(c, 0, 26) if (T[0].ch[c])
			Q.push(T[0].ch[c]);
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();
			FOR(c, 0, 26) {
				int son = T[u].ch[c];
				if (!son)
					T[u].ch[c] = T[T[u].fail].ch[c];
				else
					T[son].fail = T[T[u].fail].ch[c], Q.push(son);
			}
		}
	}
	int count(string &s, int *H1, int *H2) {
		int nw = 0, ans = 0, len = s.size();
		FOR(i, 0, len) {
			nw = T[nw].ch[s[i] - 'a'];
			int tmp = nw;
			while (nw) {
				if (!T[nw].ed.empty()) {
					for (int id : T[nw].ed) {
						string &si = S[id];
						int l = si.size();
						if (l == i + 1) {
							ans += (H[id] == H2[i] && H1[len - 1] + H2[i] == H2[len - 1] + H1[i]);
						} else {
							ans += (H1[i - l] == H2[i - l] && H[id] * P[i - l + 1] + H2[i - l] == H2[i]
							        && H1[len - 1] + H2[i] == H1[i] + H2[len - 1]);
						}
					}
				}
				nw = T[nw].fail;
			}
			nw = tmp;
		}
		return ans;
	}
} ACF;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	P[0] = 1;
	FOR(i, 1, NN) P[i] = P[i - 1] * HH;
	int n, q;
	cin >> n >> q;
	_for(i, 1, n) {
		string s;
		cin >> s >> S[i], ACF.Insert(s, i);
		FOR(j, 0, S[i].size())
		H[i] += (S[i][j] - 'a') * P[j];
	}
	ACF.GetFail();
	_for(i, 1, q) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1.size() != s2.size())
			cout << "0\n";
		else {
			FOR(j, 0, s1.size()) H1[j] = (j ? H1[j - 1] : 0) + (s1[j] - 'a') * P[j],
			                             H2[j] = (j ? H2[j - 1] : 0) + (s2[j] - 'a') * P[j];
			cout << ACF.count(s1, H1, H2) << "\n";
		}
	}
	return 0;
}