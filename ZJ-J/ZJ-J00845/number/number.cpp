// 苦心人，天不负，加油！
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1010000;

int n;
char s[N];
int cnt[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	bool f = 1;
	for (int i = 1; i <= n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			cnt[s[i] - '0']++;
			if (s[i] - '0' > 0) f = 0;
		}
	}
	if (f) {
		printf("0\n");
		return 0;
	}
	for (int i = 9; i >= 0; i--) {
		while (cnt[i]) {
			printf("%d", i);
			cnt[i]--;
		}
	}
	printf("\n");
	return 0;
}
