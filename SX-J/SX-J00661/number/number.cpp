#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {

	return x > y;

}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s1, s2;
	long long i, l;
	cin >> s1;
	l = s1.size();
	for (i = 0; i < l; i++) {
		if (s1[i] >= '0' && s1[i] <= '9') {
			s2 = s1[i];
			cout << s2;
		}
	}

	return 0;
}
