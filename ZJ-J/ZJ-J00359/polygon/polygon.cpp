#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	long long n;
	
	cin >> n;
	
	if (n <= 2) {
		cout << 0 << endl;
		return 0;
	} else if (n == 3) {
		int a, b, c;
		cin >> a >> b >> c;
		int sum = a + b + c, mx = max(max(a, b), c);
		if (sum - mx > mx) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
		
		return 0;
	}
	bool flag = true;
	
	vector <int> v(n);
	
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		if (v[i] != 1) {
			flag = false;
		}
	}
	
	if (flag) {
		long long sum = 0;
		for (int i = 3; i <= n; ++i) {
			long long ji = 1, chu = 1;
			for (int j = 0; j < i; ++j) {
				ji *= n - j;
				chu *= j + 1;
			}
			sum += ji / chu;
		}
		cout << sum % 998244353 << endl;
		return 0;
	}
	int a;
	cin >> a;
	cout << n + a << endl;
	
	return 0;
}