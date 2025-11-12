#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
char a[1000000];

int main() {
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	getline(cin, s);
	int l = s.size();
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[cnt] = s[i];
			cnt++;
		}
	}
	for (int i = 0; i < cnt; i++) {
		for (int j = 1; j < cnt; j++) {
			if (a[j] > a[j - 1]) {
				swap(a[j], a[j - 1]);
			}
		}
	}
	for (int i = 0; i < cnt; i++) {
		cout << a[i];
	}
	return 0;
}