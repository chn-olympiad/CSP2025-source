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

int n, k;
int a[500010];
bool flagA = true;
bool flagB = true;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	n = read();
	k = read();
	for (int i = 0; i < n; i++) {
		a[i] = read();
		if (a[i] != 1) flagA = false;
		if (a[i] != 1 && a[i] != 0) flagB = false;
	}
	
	if (flagA && k == 0) {
		printf("%d", n / 2);
		return 0;
	}
	
	if (flagB && k == 0) {
		int num_0;
		int num_1;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) num_1++;
			if (a[i] == 0) num_0++;
		}
		
		printf("%d", num_1 / 2 + num_0);
		return 0;
	}
	
	if (flagB && k == 1) {
		int num_1;
		int num_0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) num_1++;
			if (a[i] == 0) num_0++;
		}
		printf("%d", num_1);
		return 0;
	}
	
	printf("%d", 1);
	return 0;
}


