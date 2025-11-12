#include <iostream>
#include <vector>
using namespace std;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	if (k == 0) cout << n / 2;
	return 0;
}
