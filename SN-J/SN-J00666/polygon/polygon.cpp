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

int n;
int len[5010];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	n = read();
	if (n < 3){ 
		printf("%d", 0);
		return 0;
	}
	for (int i = 0; i < n; i++) {
		len[i] = read();
	}
	
	if (n == 3) {
		int mx = -1;
		int total = 0;
		for (int i = 0; i < n; i++) {
			mx = max(mx, len[i]);
			total += len[i];
		}
		if (total > mx * 2) {
			printf("%d", 1);
		} else {
			printf("%d", 0);
		}
		return 0;
	}
	
	printf("%d", 1);
	return 0;
}


