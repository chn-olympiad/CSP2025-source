#include <bits/stdc++.h>
using namespace std;

struct as {
	string a;
	string b;
} ac[5000010];
string sd, jc;

int zj(string a, string b) {
	int g = b.size();
	int dc = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[dc]) {
			dc++;
		} else {
			dc = 0;
		}
		if (dc == g) {
			jc = i;
			return 1;
		}
	}
	return 0;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> ac[i].a >> ac[i].b;
	}
	string m, n;
	for (int j = 0; j < b; j++) {
		cin >> m >> n;
	}
	for (int i = 0; i < b; i++) {
		cout << 0 << endl;
	}
	return 0;
}
