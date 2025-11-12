#include<bits/stdc++.h>

using namespace std;

int n, m, k, a[200], b[20][20];

int main() {
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	k = n * m;
	for (int i = 1; i <= k; i++) {
		scanf("%d", &a[i]);
	}
	int r = a[1], v;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k - i; j++) {
			if (a[j] < a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
	for (int i = 1; i <= k; i++)
		if (a[i] == r)
			v = i;
	int l = v / n, l1 = v % n, h = v / m, h1 = v % m;
	if (l1 != 0) {
		l = l + 1; 
	}
	if (h1 != 0) {
		if (h % 2 == 1)
			h = n - h + 1;
		else
			h = h1;
		}
	else {
		if (h % 2 == 0)
			h = 1;
		else
			h = n;
		}
	printf("%d %d", l, h);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0; 
}
