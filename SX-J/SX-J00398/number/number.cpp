#include <bits/stdc++.h>
using namespace std;
vector<int> a;
char c[1001];
vector<int> l;

bool cmp(char a, char b) {
	return a > b;
}

int main() {
//	freopen("number.in", "r", stdin);
//	freopen("number.out", "w", stdout);


	for (long long i = 0; i < 1000; i++) {
		cin >> c[i];
		if (c[i] >= '0' && c[i] <= '9') {
			//cout << c[i];

			string s = c[i];
			cout << s;

		}
	}
	sort(s.begin(), s.end(), cmp);
	//sort(s.begin(), s.end(), cmp);
	//cout << s << endl;

	return 0;
}
