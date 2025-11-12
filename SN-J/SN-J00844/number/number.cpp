#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> pii;

int n;
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = s.size();
	vector<int> v;
	for (int i = 0; i < n; i++)
		if (s[i] - '0' >= 0 && s[i] - '9' <= 9) v.push_back(s[i] - '0');
	sort(v.begin(), v.end(), greater<int>());
	while (v.front() == 0 && v.size() > 1) v.pop_back();
	for (auto i : v)
		printf("%d", i);
	puts("");
	return 0;
}
