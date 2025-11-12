#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

namespace PTqwq {
	
int readqwq() {
	int x = 0;
	bool f = false;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) f |= (c == '-');
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c - '0');
	if (f) {
		x = -x;
	}
	return x;
}

ll readllqwq() {
	ll x = 0;
	bool f = false;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) f |= (c == '-');
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c - '0');
	if (f) {
		x = -x;
	}
	return x;
}

const int N = 4e5 + 50;
const int M = 6e6 + 50;
const ll infoB[2] = {41, 233};
const ll infoP[2] = {1610612741, 998244353};

int n, q, mp[N], ord[N], ans[N];
pair<ll, ll> info[N];
vector<int> st[N];
char s[M], t[M];

namespace ACAM {
	int trie[M][27], posFa[M], cntFa[M], totU, curQ[M];
	void initNode(int x) {
		for (int i = 0; i < 27; ++ i) {
			trie[x][i] = 0;
		}
		posFa[x] = 0;
		cntFa[x] = 0;
	}
	void initT() {
		totU = 0;
		initNode(0);
	}
	void updateS(int x) {
		int u = 0;
		for (auto ch : st[x]) {
			if (trie[u][ch] == 0) {
				trie[u][ch] = ++ totU;
				initNode(totU);
			}
			u = trie[u][ch];
		}
		cntFa[u] ++;
	}
	void initAC() {
		int pL = 1, pR = 0;
		for (int i = 0; i < 27; ++ i) {
			if (trie[0][i] != 0) {
				curQ[++ pR] = trie[0][i]; 
			}
		}
		while (pL <= pR) {
			int u = curQ[pL];
			pL ++;
			cntFa[u] += cntFa[posFa[u]];
			for (int i = 0; i < 27; ++ i) {
				if (trie[u][i] != 0) {
					posFa[trie[u][i]] = trie[posFa[u]][i];
					curQ[++ pR] = trie[u][i];
				} else {
					trie[u][i] = trie[posFa[u]][i];
				}
			}
		}
	}
}

bool cmpF(int u, int v) {
	if (info[u].first != info[v].first) {
		return info[u].first < info[v].first;
	} else {
		return info[u].second < info[v].second;
	}
}

void solveQ(int pL, int pR) {
	vector<int> stL, stR;
	for (int i = pL; i <= pR; ++ i) {
		if (mp[ord[i]] == 1) {
			if (ord[i] <= n) {
				stL.push_back(ord[i]);
			} else {
				stR.push_back(ord[i]);
			}
		}
	}
	ACAM::initT();
	for (auto u : stL) {
		ACAM::updateS(u);
	}
	ACAM::initAC();
	for (auto u : stR) {
		int x = 0;
		for (auto ch : st[u]) {
			x = ACAM::trie[x][ch];
			ans[u] += ACAM::cntFa[x];
		}
	}
}

void Solve() {
	n = readqwq();
	q = readqwq();
	for (int i = 1; i <= n + q; ++ i) {
		scanf("%s", s + 1);
		scanf("%s", t + 1);
		int lenS = strlen(s + 1);
		int lenT = strlen(t + 1);
		mp[i] = 1;
		ll curU = 0, curV = 0;
		ll curA = 0, curB = 0;
		if (lenS != lenT) {
			mp[i] = 0;
		} else {
			int curO = 1, qL = 0, qR = 0;
			for (int j = 1; j <= lenS; ++ j) {
				if (s[j] != t[j]) {
					curO = 0;
					if (qL == 0) {
						qL = j;
					}
					qR = j;
				}
			}
			if (curO == 1) {
				mp[i] = 0;
			} else {
				for (int j = qL; j <= qR; ++ j) {
					curU = (curU * infoB[0] + s[j]) % infoP[0];
					curV = (curV * infoB[0] + t[j]) % infoP[0];
					curA = (curA * infoB[1] + s[j]) % infoP[1];
					curB = (curB * infoB[1] + t[j]) % infoP[1];
				}
				for (int j = 1; j < qL; ++ j) {
					st[i].push_back(s[j] - 'a');
				}
				st[i].push_back(26);
				for (int j = qR + 1; j <= lenS; ++ j) {
					st[i].push_back(s[j] - 'a');
				}
			}
		}
		curA = curA * infoP[0] + curU;
		curB = curB * infoP[0] + curV;
		info[i] = make_pair(curA, curB);
		ord[i] = i;
		ans[i] = 0;
	}
	sort(ord + 1, ord + 1 + n + q, cmpF);
	int curP = 1;
	for (int i = 2; i <= n + q; ++ i) {
		if (info[ord[i]].first != info[ord[i - 1]].first || info[ord[i]].second != info[ord[i - 1]].second) {
			if (curP <= i - 1) {
				solveQ(curP, i - 1);
			}
			curP = i;
		}
	}
	solveQ(curP, n + q);
	for (int i = n + 1; i <= n + q; ++ i) {
		printf("%d\n", ans[i]);
	}
}

}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	PTqwq::Solve();
	
	return 0;
}
