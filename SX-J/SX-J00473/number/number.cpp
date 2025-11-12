#include <bits/stdc++.h>
using namespace std;
string s, s1;
int le, a[1000010], k = 1;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	le = s.size();
	for (int i = 0; i < le; i++) {
		if (isdigit(s[i]) != 0) {
			s1 = s[i];
			a[k] = stoi(s1);
			k++;
		}
	}
	sort(a + 1, a + k, greater<int>());
	for (int i = 1; i < k; i++) {
		printf("%d", a[i]);
	}
	return 0;
}
