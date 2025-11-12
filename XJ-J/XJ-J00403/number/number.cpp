#include<bits/stdc++.h>

using namespace std;

int a[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	
	int len = s.size();
	for (int i = 0; i < len; i++) {
		int c = s[i] - '0';
		if (c >= 0 && c <= 9) a[c]++;
	}
	
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < a[i]; j++) {
			cout << i;
		}
	}
	
	cout << endl;
	
	return 0;
}
