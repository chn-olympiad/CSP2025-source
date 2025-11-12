#include <bits/stdc++.h>

using namespace std;

int a[10010], R;
int n, m, idx;

int getLIE(int id) {
	if (id % n)
		return id / n + 1;
	return id / n;
}

int getMOD_ODD(int id) {
	if (id % n)
		return id % n;
	else
		return n;
}

int getMOD_EVEN(int id) {
	int chk = getMOD_ODD(id);
	return n - chk + 1;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", a + i);
	}
	R = a[1];

	sort(a + 1, a + n *m + 1, greater<>());

//	for (int i = 1; i <= n * m; i++)
//		printf("%d%c", a[i], " \n"[i == n * m]);

	for (int i = 1; i <= n * m; i++)
		if (a[i] == R) {
			idx = i;
			break;
		}

//	printf("idx == %d\n", idx);

	int hang = 0, lie = getLIE(idx);
	if (lie % 2 == 0) {
		hang = getMOD_EVEN(idx);
	} else {
		hang = getMOD_ODD(idx);
	}

	printf("%d %d\n", lie, hang);
}
