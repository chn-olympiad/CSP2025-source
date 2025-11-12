#include <bits/stdc++.h>
using namespace std;
string s;
int h[15];//h[i]=k表示数字i出现了k次
int a;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a = s[i] - '0';
			h[a] ++;
		}
	}
	for (int i = 9; i >= 0; i --) {
		if (h[i] != 0) {
			while (h[i] --) {
				cout << i;
			}
		}
	}
	return 0;
}