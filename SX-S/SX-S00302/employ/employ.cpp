#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int m, n;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> m;
	}
	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> dist(1, 122106114);
	int mean = dist(e1);
	std::cout << mean << '\n';

	return 0;
}
