#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int count = 0;
	for (int i = s.size(); i > 0 ; i--) {
		count += 1;
	}
	cout << count;
	return 0;
}