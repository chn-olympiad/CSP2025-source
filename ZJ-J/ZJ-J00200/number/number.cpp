#include<bits/stdc++.h>
using namespace std;
string s;
const int MAXN = 1e6 + 10;
int a[MAXN], cnt;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(isdigit(s[i])){
			a[++cnt] = (s[i] - 48);
		}
	}
	sort(a + 1, a + cnt + 1);
	for(int i = cnt; i >= 1; i--)cout << a[i];
	cout << '\n';
	return 0;
}
/*
RP++
The 4th input file(number4.in) and output file(number4.out) is too big to open it with notepad.
I'm a very vegetable OIer, with 74pts in CSP-J1.
*/