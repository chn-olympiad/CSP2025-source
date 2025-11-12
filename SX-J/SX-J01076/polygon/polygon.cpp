#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a;
ll s[5050];
ll summ;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> s[i];
	}


	for (int i = 0; i < a; i++) {
		ll maxx = 0;
		for (int j = i + 1; j < a; j++) {

			for (int c = j + 1; c < a; c++) {

				maxx = max(s[j], s[i]);
				maxx = max(maxx, s[c]);
				if (2 * maxx < s[i] + s[j] + s[c]) {
					summ++;
				}
			}
		}
	}

	cout << summ << endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}