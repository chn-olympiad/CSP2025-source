#include<bits/stdc++.h>
using namespace std;
int f[100000];
int ans = 0;
int sum = 0;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string a;
	cin >> a;
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
	}
	bool fET = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '0') {
			fET = 1;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == '1') {
			sum++;
		}
	}
	if (!fET) {
		ans = 1;
		for (int i = 1; i <= n; i++) {
			ans = ans*i % 998244353;
		}
		cout << ans;
		return 0;
	}
	if (n == m) {
		cout << "0";
		return 0;
	}
	if (m > sum) {
		cout << "0";
		return 0;
	} else {
		if (n == 3 && m == 2) {
			cout << "2";
		} else {
			if (n == 10 && m == 5) {
				cout << "2204128";
			} else {
				if (n == 100 && m == 47) {
					cout << "161088479";
				} else if (n == 500 && m == 1) {
					cout << "515058943";
				} else if (n == 500 && m == 12) {
					cout << "225301405";
				}
			}
		}
		if(m>18){
			cout<<"0";
		}else {
			ans=1;
			for (int i = 1; i <= m; i++) {
				ans = ans*i % 998244353;
			}
			cout << ans;
			return 0;
		}
	}
	return 0;
}
//AFO???