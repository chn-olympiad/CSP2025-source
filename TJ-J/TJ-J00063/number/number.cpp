#include <bits/stdc++.h>
using namespace std;

int box[300];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		box[s[i]]++;
	}
	for (char c = '9'; c >= '0'; c--) {
		for (int i = 1; i <= box[c]; i++)
			cout << c;
	}
	return 0;
}
