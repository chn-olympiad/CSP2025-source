#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a, int b){
	return a > b;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i ++) {
		if(s[i] >= '0' && s[i] <= '9') {
			a[cnt] = (int)s[i] - 48;
			cnt ++;
		}
	}
	sort(a, a+cnt, cmp);
	for(int i = 0; i < cnt; i ++) {
		cout << a[i];
	}
	return 0;
}
