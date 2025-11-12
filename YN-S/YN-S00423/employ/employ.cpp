#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int n, m;
int q[N];

//struct abc{//};
int ade[N], ans, maxans;
string a;

void ploy(int aug, int start) {
	if (aug > maxans || ade[m - 1] == 0)
		return ;

	for (int i = 1; i <= n; i++) {

		for (int j = start; j <= m; j++) {

			q[ans++] = max(i, j);
			ploy(maxans - i, i);
			ans++;
		}
	}
}

int main() {

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	//for (int i = 1; i <= n; i++) {


	//	cin >> ade[i];
	//}

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= m; ++j) {

			if (a.size() != 0)
				q[i] = int( a[i] + a[i + 1]) - 49;
			else {
				if (maxans < ade[i]) {
					maxans = ade[i];
				}
			}
		}
	}

	ploy(maxans, 0);
	return 0;
}