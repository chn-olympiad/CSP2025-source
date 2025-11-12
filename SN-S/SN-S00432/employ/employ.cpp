#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
coust int dy[4] = {0, -1, 0, 1};

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

bool st[10000]
vector<int> Es(int n) {
	vector<int> prime;
	for (int i = 2; i <= n; i++) {
		if (!st[i]) prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] <= n; j++) {
			st[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	return prime;
}

bool isPrime(int num) {
	if (num == 1) return 0;
	if (num == 2) return 1;

	int sqr = sqrt(num);
	for (int i = 2; i <= sqr; i++) {
		if(num % i == 0) return 0;
	}
	return 1;
}

struct ListNode {
	int val;
	ListNode *prev, *next;
};

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);

	return 0;
}

