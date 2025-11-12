#include <bits/stdc++.h>
using namespace std;
int sum = 0, maxs = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int ai;
		scanf("%d", &ai);
		a.push_back(ai);
		sum += ai;
		maxs = max(maxs, ai);
	}
	if (sum > maxs * 2)
		cout << 1;
	return 0;
}
