#include <bits/stdc++.h>
using namespace std;
int t, n, ff, sum, minn, maxx, zz[100005];
int num[4], nm[100005];

struct inf {
	int  al;
	int  bl;
	int  cl;
};
inf mem[100005];
bool f[4][100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &mem[i].al, &mem[i].bl, &mem[i].cl);
			if (mem[i].al >= mem[i].bl && mem[i].al >= mem[i].cl) {
				f[1][i] = 1;
				zz[i] = mem[i].al;
			} else if (mem[i].bl >= mem[i].al && mem[i].bl >= mem[i].cl) {
				f[2][i] = 1;
				zz[i] = mem[i].bl;
			} else if (mem[i].cl >= mem[i].al && mem[i].cl >= mem[i].bl) {
				f[3][i] = 1;
				zz[i] = mem[i].cl;
			}
		}
		for (int i = 1; i < 4; i++) {
			for (int j = 0; j < n; j++) {
				if (f[i][j] == 1)
					num[i]++;
			}
		}
		for (int i = 0; i < n; i++) {
			sum += zz[i];
		}
		cout << sum << endl;
		sum = 0;
		continue;


	}
	return 0;
}