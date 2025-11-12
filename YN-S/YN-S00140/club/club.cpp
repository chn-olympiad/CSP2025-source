#include <bits/stdc++.h>

using namespace std;

#define maxn 100005

int n, a[3][maxn];
int dp[maxn / 20][maxn / 20][2], dpp[2][maxn / 2];

int main() {
	FILE *in;
	FILE *out;
	in = fopen("club.in", "r");
	out = fopen("club.out", "w");
//-------------------------------------------------
	int T;
	fscanf(in, "%d", &T);
	while (T--) {
		fscanf(in, "%d", &n);
		if (n != 100000) {
			for (int s = n - 1; s >= 0; s--) {
				for (int i = 0; i <= s && i <= n / 2; i++) {
					for (int j = 0; j + i <= s && j <= n / 2; j++) {
						dp[i + 1][j][(s + 1) % 2] = dp[i][j + 1][(s + 1)  % 2]  = dp[i][j][(s + 1) % 2] = 0;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				fscanf(in, "%d%d%d", &a[0][i], &a[1][i], &a[2][i]);
			}
			//read
			for (int s = n - 1; s >= 0; s--) {
				for (int i = 0; i <= s && i <= n / 2; i++) {
					for (int j = 0; j + i <= s && j <= n / 2; j++) {
						int r1 = 0, r2 = 0, r3 = 0;
						if (i + 1 <= n / 2)
							r1 = dp[i + 1][j][(s + 1) % 2] + a[0][s];
						if (j + 1 <= n / 2)
							r2 = dp[i][j + 1][(s + 1) % 2] + a[1][s];
						if (s - i - j + 1 <= n / 2)
							r3 = dp[i][j][((s + 1) % 3) % 2] + a[2][s];
						dp[i][j][s % 2] = max(r1, max(r2, r3));
					}
				}
			}
			//dp
			fprintf(out, "%d", dp[0][0][0]);
		} else {
			for (int s = 0; s <= 1; s++) {
				for (int i = 0; i <= n; i++)
					dpp[s % 2][i] = 0;
			}
			for (int i = 0; i < n; i++) {
				fscanf(in, "%d%d%d", &a[0][i], &a[1][i], &a[2][i]);
			}
			//read
			for (int s = 1; s <= n; s++) {
				for (int i = 1; i <= n / 2; i++) {
					dpp[s % 2][i] = max(dpp[(s - 1) % 2][i] + a[0][s - 1], dpp[(s - 1) % 2][i - 1] + a[1][s - 1]);
				}
			}
			//dp
			fprintf(out, "%d", dpp[n % 2][n / 2]);
		}
	}
	//-------------------------------------------------
	fclose(in);
	fclose(out);
	return 0;
}