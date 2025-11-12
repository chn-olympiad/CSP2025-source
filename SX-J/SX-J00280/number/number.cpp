#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string c;
	vector<int> v = {};
	int t;
	cin >> c;
	for (int i = 0; i < c.length(); i++) {
		if (c[i] == '0' || c[i]  == '1' || c[i] == '2' || c[i]  == '3' || c[i]  == '4' || c[i]  == '5'
		        || c[i]  == '6' || c[i]  == '7' || c[i]  == '8' || c[i]  == '9') {
			v.push_back(c[i] - 48);
		}
	}
	for (int k = 1; k <= v.size() - 1; k++) {
		for (int j = 0; j < v.size() - 1; j++) {
			if (v[j + 1] > v[j]) {
				t = v[j];
				v[j] = v[j + 1];
				v[j + 1] = t;
			}
		}
	}
	for (int a = 0; a < v.size(); a++) {
		cout << v[a];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
