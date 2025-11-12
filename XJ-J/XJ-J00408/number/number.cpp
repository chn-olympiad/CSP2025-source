#include <bits/stdc++.h>

using namespace std;

string s;
int n;
vector<int> a;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	n = s.size();
	a.clear();
	for (int i = 0; i < n; i++)
		if (s[i] >= '0' && s[i] <= '9')
			a.push_back(s[i] - '0');
	sort(a.begin(), a.end());
	for (int i = a.size() - 1; i >= 0; i--)
		printf("%d", a[i]);
	cout << '\n';
	return 0;
}
