#include <bits/stdc++.h>
using namespace std;
int n, k;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;//QAQÍüÁËÒì»òÕ¦Ğ´
	cout << max(min(k, n - k), 1);
	return 0;
}