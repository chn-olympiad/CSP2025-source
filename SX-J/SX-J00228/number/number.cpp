#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
string s;
int a[N];
int cnt;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
	for (int i = 1; i <= l; i++) {
		s[i] = a[i];
	}

	sort(a + 1, a + l + 1, cmp);
	for (int i = 1; i <= l; i++) {
		cout << a[i];
	}
	return 0;
}