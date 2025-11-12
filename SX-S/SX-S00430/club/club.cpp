#include <bits/stdc++.h>
using namespace std;
int t, n, num, a1[100050], a2[100050], c1 = 0, c2 = 0;
bool d[100050];

int main() {
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a1[i] >> a2[i] >> num;
			if (a1[i] > a2[i]) {
				if (c1 < n / 2) {
					d[i] = 1, c1++;
				} else {
					int minn = INT_MAX, minn_j;
					for (int j = 1; j <= n / 2; j++)
						if (d[j] && ( minn < a1[j]))
							minn = a1[j], minn_j = j;
//					cout << minn << endl;
					if (a1[i] > minn)
						swap(d[minn_j], d[i]);
				}
			} else {
				if (c2 < n / 2) {
					d[i] = 0, c2++;
				} else {
					int minn = INT_MAX, minn_j;
					for (int j = 1; j <= n / 2; j++)
						if (!d[j] && (minn < a2[j]))
							minn = a2[j], minn_j = j;
//					cout << minn << endl;
					if (a2[i] > minn)
						swap(d[minn_j], d[i]);
				}
			}
		}
		if (a2[1] == 0) {
			sort(a1 + 1, a1 + n + 1);
			int sum = 0;
			for (int i = n / 2 + 1; i <= n; i++)
				sum += a1[i];
			cout << sum << endl;
		} else {
			int sum = 0;
			for (int i = 1; i <= n; i++) {
				if (d[i])
					sum += a1[i];
				else
					sum += a2[i];
//				cout << d[i] << " ";
			}
			cout << sum;
		}
	}
	return 0;
}