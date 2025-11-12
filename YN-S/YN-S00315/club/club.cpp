#include <iostream>
using namespace std;

int main() {
	int t, n, di;
	cin >> t >> n;
	1 <= di <= 3;
	for (int i; 1 <= i <= n; i++) {
		int ai;//ÂúÒâ¶È
		cin >> ai;
		if (ai < n) {
			main();
		}
	}
	int max = ai;
	cout << max << endl;
	return 0;
}
//2025-11-01 15:30 p.m.