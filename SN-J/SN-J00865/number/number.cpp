//SN-J00865 程越萱 西安滨河学校 
#include <bits/stdc++.h>
using namespace std;
string s;
long long cnt;
char ch[1000005];
int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for (long long i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			cnt++;
			ch[cnt] = s[i];
		}
	}
	sort (ch+1, ch+1+cnt);
	for (long long i = cnt; i; i--) {
		cout << ch[i];
	}
	return 0;
}
