#include <cstdio>
#include <algorithm>
#include <vector>
constexpr int MAXN = 1e5;
int t, n;
struct Club {
	int t, v;
} seq[MAXN + 5][10];
bool cmp(Club a, Club b) { return a.v < b.v; }

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);

		int typecnt[5] {}, ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &seq[i][1].v, &seq[i][2].v, &seq[i][3].v);
			seq[i][1].t = 1, seq[i][2].t = 2, seq[i][3].t = 3;

			std::sort(seq[i] + 1, seq[i] + 4, cmp);
			typecnt[seq[i][3].t]++; ans += seq[i][3].v;
		}

		int bey = 0;
		if (typecnt[1] > (n >> 1)) bey = 1;
		if (typecnt[2] > (n >> 1)) bey = 2;
		if (typecnt[3] > (n >> 1)) bey = 3;
		if (bey) {
			int rest = typecnt[bey] - (n >> 1);
			std::vector<int> tmp;
			for (int i = 1; i <= n; i++) {
				if (seq[i][3].t == bey) { tmp.push_back(seq[i][3].v - seq[i][2].v); }
			}
			std::sort(tmp.begin(), tmp.end());
			for (int i = 0; i < rest; i++) ans -= tmp[i];
		}
	
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}