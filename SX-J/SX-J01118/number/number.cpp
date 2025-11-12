#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
string s;
vector<int> a;
int x[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a.push_back(s[i] - '0');
		}
	}
	for (int i = 0; i < a.size(); i++) {
		x[a[i]] += 1;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < x[i]; j++) {
			cout << i;
		}
	}
	return 0;
}