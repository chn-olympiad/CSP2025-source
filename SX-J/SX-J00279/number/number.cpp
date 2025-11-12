#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10;
int a[N], n;
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
			a[s[i] - '0']++;
	}


	for (int i = 9; i >= 0; i--)
		for (int j = 1; j <= a[i]; j++)
			cout << i;


	return 0;

}
