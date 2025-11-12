#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string str;
long long a[N];

bool cmp(long long  a, long long  b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> str;
	long long  index = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			index++;
			a[index] = str[i] - '0';
		}
	}
	sort(a + 1, a + index + 1, cmp);
	for (int i = 1; i <= index; i++) {
		cout << a[i];
	}
	return 0;
}
