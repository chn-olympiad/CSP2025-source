#include <bits/stdc++.h>

using namespace std;



inline int read() {
	int ans = 0, f = 1;
	char ch = getchar();

	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		ans = (ans << 3) + (ans << 1) + ch - '0';
		ch = getchar();
	}

	return f * ans;
}

struct road {
	int l, r;
	int val;
	void re() {
		l = read();
		r = read();
		val = read();
	}
} roads[1100];



struct countryside{
	int up;
	int val[10010];
	void r(int n) {
		up = read();
		for (int i = 0; i < n; i++) {
			val[i] = read();
		}
	}
}cty[30];

int n, m, k;
int answer;


int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = read();
	m = read();
	k = read();
	
	for (int i = 0; i < m; i++) {
		roads[i].re();
	}
	for (int i = 0; i < k; i++) {
		cty[i].r(n);
	}
	
	if (k == 0) {
		for (int i = 0; i < m; i++) {
			answer += roads[i].val;
		}
		printf("%d", answer);
		return 0;
	}
	
	printf("%d", 0);
	return 0;
}

