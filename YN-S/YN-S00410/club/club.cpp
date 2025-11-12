#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
typedef pair<int, int> pll;


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int n, t;
	cin >> t;
	int a, b, c;
	int sumn = 0;

	while (t--) {
		cin >> n;
		vector<int> fir(n / 2 + 1);
		vector<int> secon(n / 2 + 1);
		vector <int> thir(n / 2 + 1);
		vector<int> firt;
		vector<int> second;
		vector<int> third;

		int pan;
		bool flag = true;
		int sumn = 0;
		int maxx = -1;

		for (int i = 0; i < n; i++) {

			cin >> a >> b >> c;
			firt.push_back(a);
			second.push_back(b);
			third.push_back(c);

			if (flag && c == 0 && b == 0)
				pan = 1;
			else if (flag && b == 0)
				pan = 2;
			else {
				pan = 3;
				flag = false;
			}
		}

		if (pan == 1) {
			int j = fir.size() - 1;
			sort(fir.begin(), fir.end());

			while (j = 1 >= n / 2) {
				sumn += fir[j];
				j--;
			}

			cout << sumn << endl;
			continue;
		}

		else if (pan == 2) {
			for (int i = 0; i < n; i++) {

				sumn += max(firt[i], second[i]);

			}

			cout << sumn << endl;
			continue;
		} else {
			for (int i = 0; i < n; i++) {

				maxx = max(firt[i], second[i]);
				maxx = max(maxx, third[c]);
				sumn += maxx;

			}

			cout << sumn << endl;
			continue;
		}
	}

	return 0;
}