#include <bits/stdc++.h>
using namespace std;
string s, n;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			n += s[i];
	for (int i = 0; i < n.size(); i++)
		for (int j = 0; j < n.size(); j++)
			if (n[j] < n[j + 1])
				swap(n[j], n[j + 1]);
	for (int i = 0; i < n.size(); i++)
		cout << n[i];
	return 0;
}
