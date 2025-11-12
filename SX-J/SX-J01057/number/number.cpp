#include <bits/stdc++.h>
using namespace std;

vector<int> num;

int main() {
	//priority_queue <pair<int, int>, vector<pair<int, int> >, greater<int>> pq
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s;
	cin >> s;
	for (char c : s) {
		if (c >= '0' && c <= '9') {
			num.push_back(c - '0');
		}
	}

	sort(num.begin(), num.end());
	for (int i = num.size() - 1; i >= 0; i --) {
		cout << num[i];
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
