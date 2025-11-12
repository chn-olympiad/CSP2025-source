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

bool cmp(int a, int b) {
	return a > b;
}

int n, m;
int score[11000];
int R = 0, p = 0;
int c, r;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	n = read();
	m = read();
	int num = n * m;
	for (int i = 0; i < num; i++) {
		score[i] = read();
	}
	R = score[0];
	
	sort(score, score + num, cmp);
	
	for (int i = 0; i < num; i++) {
		if (score[i] == R) {
			p = i;
			break;
		}
	}
	
	c = p / n + 1;
	if (c % 2 == 0) {
		r = n - p % n;
	} else {
		r = p % n + 1;
	}
	
	printf("%d %d", c, r);
	return 0;
}


