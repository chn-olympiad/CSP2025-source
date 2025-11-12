#include <bits/stdc++.h>

using namespace std;

int n;
int a[5001];
int s[5001]; 

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	if (n < 3) {
		printf("0");
		return 0;
	}
	if (n == 3) {
		int ans = 0, ma = 0;
		ans = a[1] + a[2] + a[3];
		ma = max(a[1], max(a[2], a[3]));
		if (ans > ma * 2)
			printf("1");
		else
			printf("0");
		return 0;
	}
	s[0] = 0;
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int sum = 0; 
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j + 2 <= i; j++) {
			if (s[i] - s[j - 1] > a[i] * 2) {
				sum++;
			}
		}
	}
	printf("%d", sum);
	return 0;
} 
