#include <bits/stdc++.h>
#define fup(i, l, r) for (int i = (l); i <= (r); i++)
#define fdw(i, l, r) for (int i = (l); i >= (r); i--)
const int N = 2e5 + 5, B = 5e6;
int n, Q, ans[N];
std::string S[N][2], T[2];
struct Node {
	int id, x, y;
};
std::vector<Node> buc[B * 2 + 55];
int bit[B + 5];
void mdf(int p, int x) {
	for (++p; p <= B + 1; p += p & -p) bit[p] += x;
}
int qry(int p) {
	int x = 0;
	for (++p; p; p &= p - 1) x += bit[p];
	return x;
}
bool check() {
	fup(i, 1, n) {
		fup(j, 0, 1) {
			int p = 0;
			while (p < S[i][j].length() && S[i][j][p] == 'a') p++;
			if (p >= S[i][j].length() || S[i][j][p] != 'b') return false;
			p++;
			// while (p < S[i][j].length() && S[i][j][p] == 'b') p++;
			while (p < S[i][j].length() && S[i][j][p] == 'a') p++;
			if (p != S[i][j].length()) return false;
		}
	}
	return true;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &Q);
	fup(i, 1, n) {
		std::cin >> S[i][0] >> S[i][1];
	}
	if (check()) {
		fup(i, 1, n) {
			int p = S[i][0].find('b');
			int q = S[i][1].find('b');
			int len = S[i][0].length();
			buc[p - q + B].push_back({ 0, std::min(p, q), len - std::max(p, q) - 1 });
		}
		fup(j, 1, Q) {
			std::cin >> T[0] >> T[1];
			int p = T[0].find('b');
			int q = T[1].find('b');
			int len = T[0].length();
			buc[p - q + B].push_back({ j, std::min(p, q), len - std::max(p, q) - 1 });
		}
		fup(p, 0, B * 2) {
			if (buc[p].empty()) continue;
			// printf("p = %d\n", p);
			std::sort(buc[p].begin(), buc[p].end(), [](const Node& a, const Node& b) { return a.x < b.x || (a.x == b.x && a.id < b.id); });
			for (Node d : buc[p]) {
				// printf("%d %d %d\n", d.id, d.x, d.y);
				if (!d.id) mdf(d.y, 1);
				else ans[d.id] += qry(d.y);
			}
			for (Node d : buc[p])
				if (!d.id) mdf(d.y, -1);
		}
		fup(j, 1, Q) printf("%d\n", ans[j]);
	} else {
		fup(j, 1, Q) {
			std::cin >> T[0] >> T[1];
			int lt = T[0].length();
			int res = 0;
			fup(i, 1, n) {
				int ls = S[i][0].length();
				int cnt = 0;
				fup(p, 0, lt - ls) {
					// std::cout << T[0].substr(p, ls) << ' ' << S[i][0] << " | " << T[1].substr(p, ls) << ' ' << S[i][1] << " | " << T[0].substr(0, p) << ' ' << T[1].substr(0, p) << " | " << T[0].substr(p + ls, lt) << ' ' << T[1].substr(p + ls, lt) << '\n';
					cnt += (
						T[0].substr(p, ls) == S[i][0] && T[1].substr(p, ls) == S[i][1] && 
						T[0].substr(0, p) == T[1].substr(0, p) && T[0].substr(p + ls, lt) == T[1].substr(p + ls, lt)
					);
				}
				// assert(cnt <= 1);
				res += cnt;
			}
			printf("%d\n", res);
		}
	}
	fclose(stdin), fclose(stdout);
	return 0;
}