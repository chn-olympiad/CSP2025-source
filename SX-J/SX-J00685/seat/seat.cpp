#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[105], b[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
	}
	int fir = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = 1; i <= n * m; i++) {
		b[n * m - i + 1] = a[i];
	}
	int min = 0;
	for (int i = 1; i <= n * m; i++) {
		if (b[i] == fir) {
			min = i;
			break;
		}
	}
	int lie = min / n;
	int hang = min - lie * n;
	if (hang != 0)
		lie++;
	if (hang == 0 && lie % 2 == 0)
		hang = 1;
	else if (lie % 2 == 0 && hang != 0)
		hang = n - hang + 1;
	if (hang == 0 && lie % 2 == 1)
		hang = n;
	printf("%d %d", lie, hang);
	return 0;
}
