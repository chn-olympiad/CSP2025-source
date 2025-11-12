#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5, maxr = 485;

struct Member {
	int a, b, c;
} arr[maxn];

int t, n, upr, dp[maxr][maxr][maxr];
void DP() {
	for (int i = 1; i <= n; ++i) {
		for (int a = 0; a <= min(i, upr); ++a) {
			for (int b = 0; b <= min(i - a, upr); ++b) {
				int c = i - a - b;
				if (c > upr) {
					continue;
				}
				if (a != 0) {
					dp[a][b][c] = max(dp[a][b][c], dp[a - 1][b][c] + arr[i].a);
				}
				if (b != 0) {
					dp[a][b][c] = max(dp[a][b][c], dp[a][b - 1][c] + arr[i].b);
				}
				if (c != 0) {
					dp[a][b][c] = max(dp[a][b][c], dp[a][b][c - 1] + arr[i].c);
				}
			}
		}
	}
}

int ans;
void Print() {
	for (int i = 0; i <= upr; ++i) {
		for (int j = 0; j <= min(n - i, upr); ++j) {
			int k = n - i - j;
			if (k > upr) {
				continue;
			}
			ans = max(ans, dp[i][j][k]);
		}
	}
	printf("%d\n", ans);
}

void Init() {
	ans = 0;
	upr = n / 2;
	for (int a = 0; a <= upr; ++a) {
		for (int b = 0; b <= upr; ++b) {
			for (int c = 0; c <= upr; ++c) {
				dp[a][b][c] = 0;
			}
		}
	}
}

bool cmp(Member a, Member b) {
	return a.a > b.a;
}

void Tepan_12() {
	sort(arr + 1, arr + n + 1, cmp);
	int sum = 0;
	for (int i = 1; i <= upr; ++i) {
		sum += arr[i].a;
	}
	printf("%d\n", sum);
}

bool Is12;
void Input() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		Init();
		for (int i = 1; i <= n; ++i) {
			scanf("%d %d %d", &arr[i].a, &arr[i].b, &arr[i].c);
			if (arr[i].b != 0 || arr[i].c != 0) {
				Is12 = true;
			}
		}
		if (Is12 == false) {
			Tepan_12();
			continue;
		}
		DP();
		Print();
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	Input();
	return 0;
}