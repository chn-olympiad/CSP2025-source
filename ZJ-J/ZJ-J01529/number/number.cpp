#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, cnt, c[N];
string s;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = s.size();
	for(int i = 0; i < n; i++)
		if(s[i] >= '0' && s[i] <= '9') c[cnt++] = s[i] - '0';
	sort(c + 0, c + cnt);
	for(int i = cnt - 1; i >= 0; i--)
		cout << c[i];
	return 0;
}
