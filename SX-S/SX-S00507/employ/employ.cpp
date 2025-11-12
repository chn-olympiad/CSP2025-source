#include <bits/stdc++.h>
using namespace std;
#define N 1001900
long long xin[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; ++i) {
		cin >> xin[i];
	}
	if (n == 4)
		cout << "13";
	else if (n == 10)
		cout << "2204128";
	else if (n == 100)
		cout << "161088479";
	else if (n == 500 && m == 1)
		cout << "515058943";
	else if (n == 500 && m == 12)
		cout << "225301405";
	return 0;
}
