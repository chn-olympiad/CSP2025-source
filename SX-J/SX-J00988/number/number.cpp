#include <bits/stdc++.h>
#define N 1000005
using namespace std;
char a[N];

int main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
//	cout << "Hi word\n";

	string s;
	cin >> s;


	sort(s.begin(), s.end());

	int n = s.size();
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] >= '0' && s[i] <= '9') {
			cout << s[i];
		}
	}


	return 0;
}














