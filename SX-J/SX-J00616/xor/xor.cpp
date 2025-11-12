#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int ai;
		scanf("%d", &ai);
		a.push_back(ai);
	}
	bool flag = true;
	for (int i = 1; i < a.size(); i++) {
		if (a[i] != a[i - 1])
			flag = false;
	}
	if (flag)
		printf("%d", n);
	return 0;
}
