#include <bits/stdc++.h>

using namespace std;
char a[100001];
int number[100001];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		a[i] = s[i];
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == '0' || a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6' || a[i] == '7' || a[i] == '8' || a[i] == '9') {
			++cnt;
			number[cnt] = a[i] - '0';
		}
	}
	sort(number + 1, number + cnt + 1);
	for(int i = cnt; i >= 1; i--) {
		cout << number[i];
	}
	return 0;
}




