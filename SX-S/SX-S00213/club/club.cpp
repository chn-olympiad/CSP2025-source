#include <bits/stdc++.h>
#define fileIO(xx, yy) freopen(xx, "r", stdin), freopen(yy, "w", stdout)

using namespace std;

int n, a[100010][10];
int CNT[10];

bool valid(int i, int j, int k, int l) {
	memset(CNT, 0, sizeof CNT);
	CNT[i]++;
	CNT[j]++;
	CNT[k]++;
	CNT[l]++;
	return CNT[1] <= 2 && CNT[2] <= 2 && CNT[3] <= 2 && CNT[4] <= 2;
}

void sol() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
	// 第 i 个新成员对第 j 个部门的满意度为 a[i][j]

	if (n == 2) {
		// 两个新同学，各分配到一个部门
		// 输出 a[1, 2][1, 2, 3] 中两两组合最大值
		long long mx = -100;
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
				if (i != j)
					mx = max(mx, 1ll * a[1][i] + a[2][j]);
		printf("%lld\n", mx);
		return;

	} else if (n == 4) {
		long long mx = -100;
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
				for (int k = 1; k <= 3; k++)
					for (int l = 1; l <= 3; l++)
						if (valid(i, j, k, l))
							mx = max(mx, 1ll * a[1][i] + a[2][j] + a[3][k] + a[4][l]);
		printf("%lld\n", mx);
		return;
	}
}

int main() {
	fileIO("club.in", "club.out");

	int T;
	scanf("%d", &T);
	while (T--)
		sol();
}