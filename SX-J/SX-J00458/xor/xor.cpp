#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 * 5 + 10;
ll n, k, arr[N], sum;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			if (arr[i] == 0 && arr[i + 1] == 0)
				i++, sum++;
			else if (arr[i] == 1)
				sum++;
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (arr[i] == 1 && arr[i + 1] == 1)
				i++, sum++;
			else if (arr[i] == 0)
				sum++;
		}
	}
	return 0;
}
