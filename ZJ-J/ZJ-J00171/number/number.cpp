#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n , m;
string s , t;
string a , b;

int main () {
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> s;
	n = s.size();
	for (int i = 0;i < n;i++) if (s[i] >= '0'&&s[i] <= '9') t += s[i];
	m = t.size();
	sort(t.begin() , t.end());
	reverse(t.begin() , t.end());
	if (t[0] == '0') cout << 0;
	else cout << t;
	return 0;
}