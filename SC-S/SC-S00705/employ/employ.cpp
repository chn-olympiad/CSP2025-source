//0pts
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	string s;
	int n, m, num = 0;
	cin >> n >> m >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			num++;
		}
	}
	if (num < m) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
}
//rp++
//总分:24