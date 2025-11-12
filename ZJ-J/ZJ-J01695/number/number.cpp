#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(false); \
cin.tie(0); \
cout.tie(0);
string s;
ll number[1000005], tmp, tong[20];
void fr() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
}
int main() {
	fr();
	IOS
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			tong[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= tong[i]; j++) {
			cout << i;
		}
	}
	return 0;
}

